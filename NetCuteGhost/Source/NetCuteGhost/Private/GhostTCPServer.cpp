// Fill out your copyright notice in the Description page of Project Settings.

#include "GhostTCPServer.h"
#include "TimerManager.h"
#include "UnrealString.h"
#include "Engine/Engine.h"
#include "HAL/UnrealMemory.h"
#include "Misc/CString.h"

// Sets default values
AGhostTCPServer::AGhostTCPServer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ServerIP = "192.168.43.170";
	ServerPort = 12357;
}

// Called when the game starts or when spawned
void AGhostTCPServer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGhostTCPServer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// 액터의 역할이 끝날 때 사용되는 함수입니다.
void AGhostTCPServer::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UE_LOG(NetCuteGhost, Log, TEXT("%s"), *CALLINFO);
	if (ListenerSocket != nullptr)
	{
		ListenerSocket->Close();
	}

	if (ConnectionSocket != nullptr)
	{
		ConnectionSocket->Close();
	}
}





void AGhostTCPServer::InitNetwork()
{
	UE_LOG(NetCuteGhost, Log, TEXT("%s : Start Initiate Network System, %s, %d"), 
		*CALLINFO, *ServerIP, ServerPort);

	// 리스너 소켓 초기화에 실패하면 로그를 남기고 작동을 중지합니다.
	if (InitListenerSocket("GhostTcpListener") == false)
	{
		UE_LOG(NetCuteGhost , Warning, TEXT("InitListenerSocket returns false"));
		return;
	}

	
	UE_LOG(NetCuteGhost, Log, TEXT("%s : Network System successfully init! "), *CALLINFO);
}

bool AGhostTCPServer::InitListenerSocket(const FString & ListenerSocketName)
{
	UE_LOG(NetCuteGhost, Log, TEXT("%s"), *CALLINFO);

	// 리스너 소켓을 생성합니다.
	ListenerSocket = CreateListenerSocket(ListenerSocketName, BUFSIZE);
	if (ListenerSocket == nullptr)
	{
		UE_LOG(NetCuteGhost, Warning, TEXT("CreateListenerSocket cannot create Listener Socket : %s %d"), *ServerIP, ServerPort);

		return false;
	}

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AGhostTCPServer::ActivateListenerSocket, 0.1f, true);

	return true;
}

FSocket * AGhostTCPServer::CreateListenerSocket
(
	const FString & ListenerSocketName, 
	const int32 RecvedBufferSize
)
{
	UE_LOG(NetCuteGhost, Log, TEXT("%s"), *CALLINFO);
	UE_LOG(NetCuteGhost, Log,
		TEXT("%s : ReceivedBufferSize is %s"),
		*CALLINFO, *FString::FromInt(RecvedBufferSize));


	// IP 문자열로부터 IP클래스별로 담을 uint 배열입니다.
	uint8 IPv4Nums[4];
	if (FormatIPv4ToNumber(ServerIP, IPv4Nums) == false)
	{
		UE_LOG(NetCuteGhost, Warning,
			TEXT("%s %s"), *CALLINFO, TEXT(" : Invalid IPv4 Input"));
		
		return nullptr;
	}

	// 서버 리스너 소켓을 생성합니다.
	FIPv4Endpoint EndPoint(FIPv4Address(IPv4Nums[0], IPv4Nums[1], IPv4Nums[2], IPv4Nums[3]), ServerPort);
	UE_LOG(NetCuteGhost, Log, TEXT("%s : %s"), *CALLINFO, *(EndPoint.ToText().ToString()));

	FSocket* TempListenerSocket = FTcpSocketBuilder(*ListenerSocketName)
		.AsReusable()
		.BoundToEndpoint(EndPoint)
		.Listening(8);

	if (TempListenerSocket == nullptr)
	{
		UE_LOG(NetCuteGhost, Warning,
			TEXT("%s %s"), *CALLINFO, TEXT(" : Failed To Create Listener Socket"));

		return nullptr;
	}

	int NewSize = 0;
	TempListenerSocket->SetReceiveBufferSize(RecvedBufferSize, NewSize);
	UE_LOG(NetCuteGhost, Log,
		TEXT("%s : ReceivedBufferSize is %s, and NewSize is %s"),
		*CALLINFO, *FString::FromInt(RecvedBufferSize), *FString::FromInt(NewSize));

	return TempListenerSocket;
}

void AGhostTCPServer::ActivateListenerSocket()
{
	if (ListenerSocket == nullptr)
	{
		UE_LOG(NetCuteGhost, Warning, TEXT("%s : ListenerSocket is invalid"), *CALLINFO);
		return;
	}

	// 원격 주소를 생성합니다.
	TSharedRef<FInternetAddr> RemoteAddress =
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();

	
	bool Pending;
	if (ListenerSocket->HasPendingConnection(Pending) && Pending)
	{
		UE_LOG(NetCuteGhost, Log, TEXT("%s : HasPendingConnection is true"), *CALLINFO);

		// 이미 연결을 가지고 있으면 이전 연결을 파괴합니다
		if (ConnectionSocket != nullptr)
		{
			ConnectionSocket->Close();
			ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ConnectionSocket);
		}

		// 새로운 커넥션 소켓을 생성합니다.
		ConnectionSocket = ListenerSocket->Accept(*RemoteAddress, 
			TEXT("ConnectionSocket is created by Accept"));

		// 서버와 클라이언트의 연결이 성공했을 때 아래 프로세스를 실행합니다.
		if (ConnectionSocket != nullptr)
		{
			RemoteAddressForConnection = FIPv4Endpoint(RemoteAddress);

			UE_LOG(NetCuteGhost, Warning, TEXT("%s : Accept Success"), *CALLINFO);

			GetWorldTimerManager().SetTimer(TimerHandle, this, &AGhostTCPServer::ActivateConnectionSocket, 0.1f, true);
		}
	}
}

void AGhostTCPServer::ActivateConnectionSocket()
{
	// 클라이언트 소켓이 유효하지 않으면 종료합니다.
	if (ConnectionSocket == nullptr)
	{
		UE_LOG(NetCuteGhost, Warning, TEXT("%s : ConnectionSocekt is not valid"), *CALLINFO);
		return;
	}

	// 네트워크를 통해 수신받을 바이너리 데이터를 선언합니다.
	
	char RecvedData[BUFSIZE];
	FMemory::Memset(RecvedData, 0, sizeof(RecvedData));


	uint32 DataSize;
	while (ConnectionSocket->HasPendingData(DataSize) == true)
	{
		GetWorldTimerManager().PauseTimer(TimerHandle);
		int32 ReadNum = 0;

		// Recv를 통해 수신합니다.
		ConnectionSocket->Recv(reinterpret_cast<uint8*>(RecvedData), sizeof(RecvedData), ReadNum);
	}
	GetWorldTimerManager().UnPauseTimer(TimerHandle);

	// TODO : NON UNIVERSAL CODE
	if ( strlen(RecvedData) <= 0 )
	{
		return;
	}

	

	FString PacketString(RecvedData);
	ParsePacket(PacketString);
}





bool AGhostTCPServer::FormatIPv4ToNumber(const FString & IP, uint8(&Out)[4])
{
	// IP를 포맷팅합니다.
	IP.Replace(TEXT(" "), TEXT(""));


	// 문자열 파트
	TArray<FString> Parts;
	IP.ParseIntoArray(Parts, TEXT("."), true);

	// 문자열이 4 클래스 파트로 나눠지지 않으면 false를 반환합니다.
	if (Parts.Num() != 4)
	{
		UE_LOG(NetCuteGhost, Warning, 
			TEXT("%s : Invalid IP contains, must be A.B.C.D format"), *CALLINFO)
		
		return false;
	}

	// Parts의 문자열을 숫자화하여 출력합니다.
	for (int32 i = 0; i < 4; ++i)
	{
		Out[i] = FCString::Atoi(*Parts[i]);
	}

	return true;
}

// 바이너리 데이터를 FString 데이터로 변환합니다.
FString AGhostTCPServer::StringFromBinaryArray(TArray<uint8>& BinaryArray)
{
	// 널 문자를 삽입합니다.
	BinaryArray.Add(0);

	// ANSI에서 TCHAR 형식으로 문자열을 변경하여 반환합니다.
	return FString(ANSI_TO_TCHAR(reinterpret_cast<const char*>(BinaryArray.GetData())));
}



void AGhostTCPServer::ParsePacket(FString InString)
{
	TArray<FString> ParsedArray;
	InString.ParseIntoArray(ParsedArray, TEXT(","), true);

	FString IndexString = ParsedArray[0];
	FString InputString = ParsedArray[1];

	//int32 WeightValue = 0;
	//while (PacketContainer.Find(*ParsedArray[0]) == nullptr)
	//{
	//	WeightValue += 10;
	//}
	//if (WeightValue == 0)
	//{
	PacketContainer.Add(IndexString, InputString);
	//}
	//else
	//{
	//	int32 StringToInt = FCString::Atoi(*ParsedArray[0]);
	//	StringToInt += WeightValue;
	//	FString IntToString(FString::FromInt(StringToInt));

	//	PacketContainer.Add(IntToString, ParsedArray[1]);
	//}
}


const FString FNetMessage::GAME::UP = "%up";
const FString FNetMessage::GAME::DOWN = "%down";
const FString FNetMessage::GAME::LEFT = "%left";
const FString FNetMessage::GAME::RIGHT = "%right";

const FString FNetMessage::GAME::SLOWUP = "%slowup";
const FString FNetMessage::GAME::SLOWDOWN = "%slowdown";
const FString FNetMessage::GAME::SLOWLEFT = "%slowleft";
const FString FNetMessage::GAME::SLOWRIGHT = "%slowright";

const FString FNetMessage::GAME::STOP = "%stop";
const FString FNetMessage::GAME::DASH = "%dash";