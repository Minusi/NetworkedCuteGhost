// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"



DECLARE_LOG_CATEGORY_EXTERN(NetCuteGhost, Log, All);

#define CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))