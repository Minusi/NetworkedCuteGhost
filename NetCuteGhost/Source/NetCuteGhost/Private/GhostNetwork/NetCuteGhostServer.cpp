// Fill out your copyright notice in the Description page of Project Settings.

#include "GhostNetwork/NetCuteGhostServer.h"
#include "Engine\Engine.h"
#include "TimerManager.h"



// TCP 리시버를 시작시킵니다.
bool UNetCuteGhostServer::StartTCPReceiver
(
	const FString& ServerSocketName,
	const FString& ServerIP,
	const int32 ServerPort
)
{
	// CreateTCPConnectinoListener를 호출합니다.
	ListenerSocket = CreateTCPConnectionListener(ServerSocketName, ServerIP, ServerPort);

	// 소켓 생성 실패시 에러 메시지를 발생시키고 false를 반환합니다.
	if (ListenerSocket == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,
			FString::Printf(TEXT("StartTCPReceiver>> ListenSocket could not be created! -> %s %d"), ServerIP, ServerPort);

		return false;
	}

	// TODO : 설정할 것
	GetWorld()

	return true;
}



// TCP 커넥션 리스너를 생성합니다.
FSocket * UNetCuteGhostServer::CreateTCPConnectionListener
(
	const FString & SocketName, 
	const FString & IP, 
	const int32 Port, 
	const int32 ReceiveBufferSize
)
{
	uint8 IP4Nums[4];
	if (FormatIP4ToNumber(IP, IP4Nums) == false)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,
			TEXT("Invalid IP! Expecting 4 parts separated by."));
;	}

	// 소켓을 생성합니다.
	FIPv4Endpoint Endpoint(FIPv4Address(IP4Nums[0], IP4Nums[1], IP4Nums[2], IP4Nums[3]), Port);
	FSocket* TempListenSocket = FTcpSocketBuilder(*SocketName)
		.AsReusable()
		.BoundToEndpoint(Endpoint)
		.Listening(8);

	// 버퍼 사이즈를 설정합니다.
	int32 NewSize = 0;
	TempListenSocket->SetReceiveBufferSize(ReceiveBufferSize, NewSize);

	return TempListenSocket;
}



// IP 문자열 포맷을 숫자 파트로 변환합니다.
bool UNetCuteGhostServer::FormatIP4ToNumber(const FString & IP, uint8(&Out)[4])
{
	// IP를 포맷팅합니다.
	IP.Replace(TEXT(" "), TEXT(""));


	//////////////////////////////////////////////////////////////////////////
	// IP 4 Part입니다.
	
	// 문자열 파트
	// TODO : ParseIntoArray의 1번째 인자에 &를 붙이면 에러가 나서 떼긴 했지만,
	// 동작에 의심스러운 부분이 있음.
	TArray<FString> Parts;
	IP.ParseIntoArray( Parts, TEXT("."), true);
	if (Parts.Num() != 4)
	{
		return false;
	}

	// Parts의 문자열을 숫자화합니다.
	for (int32 i = 0; i < 4; ++i)
	{
		Out[i] = FCString::Atoi(*Parts[i]);
	}

	return true;
}



// TCP 커넥션 리스너 함수입니다.
void UNetCuteGhostServer::TCPConnectionListener()
{
	if (ListenerSocket == nullptr)
	{
		return;
	}

	// 원격 주소입니다.
	TSharedRef<FInternetAddr> RemoteAddress =
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	bool Pending;

	// 들어오는 연결을 제어합니다.
	if (ListenerSocket->HasPendingConnection(Pending) && Pending)
	{
		// 이미 연결을 가지고 있으면 이전 연결을 파괴합니다.
		if (ConnectionSocket)
		{
			ConnectionSocket->Close();
			ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ConnectionSocket);
		}

		// 새로운 커넥션 소켓을 생성합니다.
		ConnectionSocket = ListenerSocket->Accept(*RemoteAddress,
			TEXT("TCP Received Socket Connection"));

		if (ConnectionSocket != nullptr)
		{
			// 현재 원격 주소의 글로벌 캐시입니다.
			RemoteAddressForConnection = FIPv4Endpoint(RemoteAddress);

			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,
				TEXT("Accpected Connection"));

			// TODO : GETWORLDTIMGER() AGAIN;
		}
	}
}