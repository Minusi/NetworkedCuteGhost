// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NetCuteGhost/Public/GhostNetwork/NetCuteGhostServer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNetCuteGhostServer() {}
// Cross Module References
	NETCUTEGHOST_API UClass* Z_Construct_UClass_UNetCuteGhostServer_NoRegister();
	NETCUTEGHOST_API UClass* Z_Construct_UClass_UNetCuteGhostServer();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_NetCuteGhost();
// End Cross Module References
	void UNetCuteGhostServer::StaticRegisterNativesUNetCuteGhostServer()
	{
	}
	UClass* Z_Construct_UClass_UNetCuteGhostServer_NoRegister()
	{
		return UNetCuteGhostServer::StaticClass();
	}
	struct Z_Construct_UClass_UNetCuteGhostServer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNetCuteGhostServer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_NetCuteGhost,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNetCuteGhostServer_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GhostNetwork/NetCuteGhostServer.h" },
		{ "ModuleRelativePath", "Public/GhostNetwork/NetCuteGhostServer.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNetCuteGhostServer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNetCuteGhostServer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UNetCuteGhostServer_Statics::ClassParams = {
		&UNetCuteGhostServer::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UNetCuteGhostServer_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UNetCuteGhostServer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UNetCuteGhostServer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UNetCuteGhostServer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UNetCuteGhostServer, 605840257);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNetCuteGhostServer(Z_Construct_UClass_UNetCuteGhostServer, &UNetCuteGhostServer::StaticClass, TEXT("/Script/NetCuteGhost"), TEXT("UNetCuteGhostServer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNetCuteGhostServer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
