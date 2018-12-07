// Fill out your copyright notice in the Description page of Project Settings.

#include "GhostElements/MNSGhostPawnBase.h"


// Sets default values
AMNSGhostPawnBase::AMNSGhostPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("GhostCollision"));
	RootComponent = SphereComponent;

	
}

// Called when the game starts or when spawned
void AMNSGhostPawnBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMNSGhostPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMNSGhostPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

