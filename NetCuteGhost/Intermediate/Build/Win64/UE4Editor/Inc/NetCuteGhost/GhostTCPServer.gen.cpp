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
	NETCUTEGHOST_API UFunction* Z_Construct_UFunction_AGhostTCPServer_InitNetwork();
// End Cross Module References
	void AGhostTCPServer::StaticRegisterNativesAGhostTCPServer()
	{
		UClass* Class = AGhostTCPServer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "InitNetwork", &AGhostTCPServer::execInitNetwork },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AGhostTCPServer_InitNetwork_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGhostTCPServer_InitNetwork_Statics::Function_MetaDataParams[] = {
		{ "Category", "Network" },
		{ "ModuleRelativePath", "Public/GhostTCPServer.h" },
		{ "ToolTip", "\xeb\x84\xa4\xed\x8a\xb8\xec\x9b\x8c\xed\x81\xac \xed\x86\xb5\xec\x8b\xa0 \xed\x94\x84\xeb\xa1\x9c\xec\x84\xb8\xec\x8a\xa4\xeb\xa5\xbc \xec\x8b\x9c\xec\x9e\x91\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4. \xec\x84\x9c\xeb\xb2\x84\xec\x9d\x98 \xed\x86\xb5\xec\x8b\xa0 \xed\x94\x84\xeb\xa1\x9c\xec\x84\xb8\xec\x8a\xa4\xeb\x8a\x94\n\xeb\x8b\xa4\xec\x9d\x8c\xea\xb3\xbc \xea\xb0\x99\xec\x9d\x80 \xec\x88\x9c\xec\x84\x9c\xeb\xa1\x9c \xed\x98\xb8\xec\xb6\x9c\xeb\x90\x98\xeb\xa9\xb0 \xec\x88\x98\xed\x96\x89\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4:\n1. InitNetwork\n2. InitListenerSocket\n3. CreateListenerSocket\n3-1. ActivateListenerSocket\n4. ActivateConnectionSocket" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGhostTCPServer_InitNetwork_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGhostTCPServer, "InitNetwork", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGhostTCPServer_InitNetwork_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AGhostTCPServer_InitNetwork_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGhostTCPServer_InitNetwork()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGhostTCPServer_InitNetwork_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AGhostTCPServer_NoRegister()
	{
		return AGhostTCPServer::StaticClass();
	}
	struct Z_Construct_UClass_AGhostTCPServer_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PacketContainer_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_PacketContainer;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PacketContainer_Key_KeyProp;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PacketContainer_ValueProp;
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
	const FClassFunctionLinkInfo Z_Construct_UClass_AGhostTCPServer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AGhostTCPServer_InitNetwork, "InitNetwork" }, // 144620410
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGhostTCPServer_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GhostTCPServer.h" },
		{ "ModuleRelativePath", "Public/GhostTCPServer.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_PacketContainer_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Network" },
		{ "ModuleRelativePath", "Public/GhostTCPServer.h" },
		{ "ToolTip", "\xec\x88\x98\xec\x8b\xa0\xeb\x90\x9c \xed\x8c\xa8\xed\x82\xb7\xec\x9d\x84 \xec\xa0\x80\xec\x9e\xa5\xed\x95\x98\xeb\x8a\x94 \xec\xbb\xa8\xed\x85\x8c\xec\x9d\xb4\xeb\x84\x88\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_PacketContainer = { UE4CodeGen_Private::EPropertyClass::Map, "PacketContainer", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000010005, 1, nullptr, STRUCT_OFFSET(AGhostTCPServer, PacketContainer), METADATA_PARAMS(Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_PacketContainer_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_PacketContainer_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_PacketContainer_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Str, "PacketContainer_Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000001, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_PacketContainer_ValueProp = { UE4CodeGen_Private::EPropertyClass::Str, "PacketContainer", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000001, 1, nullptr, 1, METADATA_PARAMS(nullptr, 0) };
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
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_PacketContainer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_PacketContainer_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGhostTCPServer_Statics::NewProp_PacketContainer_ValueProp,
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
		FuncInfo, ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(AGhostTCPServer, 753720409);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGhostTCPServer(Z_Construct_UClass_AGhostTCPServer, &AGhostTCPServer::StaticClass, TEXT("/Script/NetCuteGhost"), TEXT("AGhostTCPServer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGhostTCPServer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
