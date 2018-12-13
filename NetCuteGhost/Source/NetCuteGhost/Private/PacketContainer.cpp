// Fill out your copyright notice in the Description page of Project Settings.

#include "PacketContainer.h"


// Sets default values
APacketContainer::APacketContainer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APacketContainer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APacketContainer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

const TMap<FString, FString>& APacketContainer::GetPacketMap()
{
	return PacketMap;
}

