// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PacketContainer.generated.h"

UCLASS()
class NETCUTEGHOST_API APacketContainer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APacketContainer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	const TMap<FString, FString>& GetPacketMap();

private:
	// 인덱스와 입력 커맨드를 저장하는 컨테이너입니다.
	// TCP 서버에 의해 참조됩니다.
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Packet", meta = (AllowPrivateAccess = "true"))
	TMap<FString, FString> PacketMap;
	
};
