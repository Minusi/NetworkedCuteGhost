// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NetCuteGhost/Public/CuteGhostPawnBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCuteGhostPawnBase() {}
// Cross Module References
	NETCUTEGHOST_API UClass* Z_Construct_UClass_ACuteGhostPawnBase_NoRegister();
	NETCUTEGHOST_API UClass* Z_Construct_UClass_ACuteGhostPawnBase();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_NetCuteGhost();
// End Cross Module References
	void ACuteGhostPawnBase::StaticRegisterNativesACuteGhostPawnBase()
	{
	}
	UClass* Z_Construct_UClass_ACuteGhostPawnBase_NoRegister()
	{
		return ACuteGhostPawnBase::StaticClass();
	}
	struct Z_Construct_UClass_ACuteGhostPawnBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACuteGhostPawnBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_NetCuteGhost,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACuteGhostPawnBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "CuteGhostPawnBase.h" },
		{ "ModuleRelativePath", "Public/CuteGhostPawnBase.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACuteGhostPawnBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACuteGhostPawnBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACuteGhostPawnBase_Statics::ClassParams = {
		&ACuteGhostPawnBase::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ACuteGhostPawnBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ACuteGhostPawnBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACuteGhostPawnBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACuteGhostPawnBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACuteGhostPawnBase, 3266459697);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACuteGhostPawnBase(Z_Construct_UClass_ACuteGhostPawnBase, &ACuteGhostPawnBase::StaticClass, TEXT("/Script/NetCuteGhost"), TEXT("ACuteGhostPawnBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACuteGhostPawnBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
