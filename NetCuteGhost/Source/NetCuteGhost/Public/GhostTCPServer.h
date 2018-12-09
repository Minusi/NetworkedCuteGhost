// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NetCuteGhost.h"
#include "GameFramework/Actor.h"
#include "Networking/Public/Networking.h"
#include "GhostTCPServer.generated.h"

UCLASS()
class NETCUTEGHOST_API AGhostTCPServer : public AActor
{
#define BUFSIZE 256

	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGhostTCPServer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 액터의 역할이 끝날 때 사용되는 함수입니다.
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;



	// 네트워크 통신 프로세스를 시작합니다. 서버의 통신 프로세스는
	// 다음과 같은 순서로 호출되며 수행합니다:
	// 1. InitNetwork
	// 2. InitListenerSocket
	// 3. CreateListenerSocket
	// 3-1. ActivateListenerSocket
	// 4. ActivateConnectionSocket
	void InitNetwork();

	// ListenerSocket을 초기화하고 초기화된 리스너 소켓을 활성화합니다.
	bool InitListenerSocket(const FString& ListenerSocketName);

	// ListenerSocket을 생성합니다.
	FSocket* CreateListenerSocket
	(
		const FString& ListenerSocketName, 
		const int32 RecvedBufferSize = BUFSIZE
	);

	// ListenerSocket을 활성화하고 클라이언트와의 연결 정보를
	// ConnectionSocket에 저장합니다.
	void ActivateListenerSocket();

	// ConnectionSocket을 활성화합니다.
	void ActivateConnectionSocket();



	// iPv4 문자열 포맷을 숫자 포맷으로 변환합니다.
	bool FormatIPv4ToNumber(const FString& IP, uint8(&Out)[4]);

	// 바이너리 데이터를 FString 데이터로 변환합니다.
	FString StringFromBinaryArray(TArray<uint8>& BinaryArray);
	

private:
	// 이 머신의 IP입니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Network", meta = (AllowPrivateAccess = "true"))
	FString ServerIP;

	// 이 머신의 포트입니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Network", meta = (AllowPrivateAccess = "true"))
	int32 ServerPort;

	// 서버에서 클라이언트의 접속을 기다리는 소켓입니다.
	FSocket* ListenerSocket;

	// 서버와 연결중인 클라이언트 소켓입니다.
	FSocket* ConnectionSocket;
	
	// 원격 주소에 대한 클래스 스코프 캐시입니다.
	FIPv4Endpoint RemoteAddressForConnection;
};
