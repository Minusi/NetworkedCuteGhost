// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"	

#include "MNSGhostPawnBase.generated.h"

UCLASS()
class NETCUTEGHOST_API AMNSGhostPawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMNSGhostPawnBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



private:
	// 고스트의 체력입니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ghost|Character", meta=(AllowPrivateAccess = "true"))
	int GhostHP = 0;
	

	// CuteGhost에 대한 스태틱 메시 컴포넌트입니다.
	class UStaticMeshComponent* SMComponent;

	// CuteGhost에 대한 게임플레이 콜리전입니다. 정교한 콜리전 설정을 원한다면 
	// 스태틱 메시 에디터에서 알맞은 콜리전을 설정하시길 바랍니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ghost|Collision", meta=(AllowPrivateAccess = "true"))
	class USphereComponent* SphereComponent;



	// CuteGhost의 중심에서 일어날 수 있는 다양한 VFX를 위한 파티클 컴포넌트입니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ghost|Effect", meta=(AllowPrivateAccess = "true"))
	class UParticleSystemComponent* PtcCompoment;
	

};
