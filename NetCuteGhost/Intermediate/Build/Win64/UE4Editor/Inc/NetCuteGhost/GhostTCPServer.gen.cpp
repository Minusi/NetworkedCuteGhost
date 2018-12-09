// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NetCuteGhost/Public/GhostTCPServer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGhostTCPServer() {}
// Cross Module References
	NETCUTEGHOST_API UClass* Z_Construct_UClass_AGhostTCPServer_NoRegister();
	NETCUTEGHOST_API UClass* Z_Construct_UClass_AGhostTCPServer();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_NetCuteGhost();
// End Cross Module References
	void AGhostTCPServer::StaticRegisterNativesAGhostTCPServer()
	{
	}
	UClass* Z_Construct_UClass_AGhostTCPServer_NoRegister()
	{
		return AGhostTCPServer::StaticClass();
	}
	struct Z_Construct_UClass_AGhostTCPServer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ServerPort_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ServerPort;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ServerIP_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ServerIP;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGhostTCPServer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_NetCuteGhost,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGhostTCPServer_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GhostTCPServer.h" },
		{ "ModuleRelativePath", "Public/GhostTCPServer.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_ServerPort_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Network" },
		{ "ModuleRelativePath", "Public/GhostTCPServer.h" },
		{ "ToolTip", "\xec\x9d\xb4 \xeb\xa8\xb8\xec\x8b\xa0\xec\x9d\x98 \xed\x8f\xac\xed\x8a\xb8\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_ServerPort = { UE4CodeGen_Private::EPropertyClass::Int, "ServerPort", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000005, 1, nullptr, STRUCT_OFFSET(AGhostTCPServer, ServerPort), METADATA_PARAMS(Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_ServerPort_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_ServerPort_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_ServerIP_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Network" },
		{ "ModuleRelativePath", "Public/GhostTCPServer.h" },
		{ "ToolTip", "\xec\x9d\xb4 \xeb\xa8\xb8\xec\x8b\xa0\xec\x9d\x98 IP\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_ServerIP = { UE4CodeGen_Private::EPropertyClass::Str, "ServerIP", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000005, 1, nullptr, STRUCT_OFFSET(AGhostTCPServer, ServerIP), METADATA_PARAMS(Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_ServerIP_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_ServerIP_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGhostTCPServer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_ServerPort,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_ServerIP,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGhostTCPServer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGhostTCPServer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGhostTCPServer_Statics::ClassParams = {
		&AGhostTCPServer::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_AGhostTCPServer_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AGhostTCPServer_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AGhostTCPServer_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AGhostTCPServer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGhostTCPServer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGhostTCPServer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGhostTCPServer, 396040491);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGhostTCPServer(Z_Construct_UClass_AGhostTCPServer, &AGhostTCPServer::StaticClass, TEXT("/Script/NetCuteGhost"), TEXT("AGhostTCPServer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGhostTCPServer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
