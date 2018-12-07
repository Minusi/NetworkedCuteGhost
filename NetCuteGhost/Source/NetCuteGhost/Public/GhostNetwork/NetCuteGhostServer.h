// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Networking\Public\Networking.h"
#include "NetCuteGhostServer.generated.h"

/**
 * 
 */
UCLASS()
class NETCUTEGHOST_API UNetCuteGhostServer : public UObject
{
	GENERATED_BODY()
	
public:
	// TCP 리시버를 개시합니다.
	bool StartTCPReceiver
	(
		const FString& SocketName,
		const FString& ClientIP,
		const int32 ClientPort
	);
	
	FSocket* CreateTCPConnectionListener
	(
		const FString& SocketName,
		const FString& IP,
		const int32 Port,
		const int32  ReceiveBufferSize = 2 * 1024 * 1024
	);

	void TCPConnectionListener();
	void TCPSocketListner();

	bool FormatIP4ToNumber(const FString& IP, uint8 (&Out)[4]);

	FString StringFromBinaryArray(const TArray<uint8>& BinaryArray);

public:
	FSocket * ListenerSocket;
	FSocket* ConnectionSocket;
	FIPv4Endpoint RemoteAddressForConnection;
	
};
