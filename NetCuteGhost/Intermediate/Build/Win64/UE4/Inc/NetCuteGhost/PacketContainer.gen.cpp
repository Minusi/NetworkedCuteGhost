// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NetCuteGhost/Public/PacketContainer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePacketContainer() {}
// Cross Module References
	NETCUTEGHOST_API UClass* Z_Construct_UClass_APacketContainer_NoRegister();
	NETCUTEGHOST_API UClass* Z_Construct_UClass_APacketContainer();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_NetCuteGhost();
// End Cross Module References
	void APacketContainer::StaticRegisterNativesAPacketContainer()
	{
	}
	UClass* Z_Construct_UClass_APacketContainer_NoRegister()
	{
		return APacketContainer::StaticClass();
	}
	struct Z_Construct_UClass_APacketContainer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PacketMap_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_PacketMap;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PacketMap_Key_KeyProp;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PacketMap_ValueProp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APacketContainer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_NetCuteGhost,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APacketContainer_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PacketContainer.h" },
		{ "ModuleRelativePath", "Public/PacketContainer.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APacketContainer_Statics::NewProp_PacketMap_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Packet" },
		{ "ModuleRelativePath", "Public/PacketContainer.h" },
		{ "ToolTip", "\xec\x9d\xb8\xeb\x8d\xb1\xec\x8a\xa4\xec\x99\x80 \xec\x9e\x85\xeb\xa0\xa5 \xec\xbb\xa4\xeb\xa7\xa8\xeb\x93\x9c\xeb\xa5\xbc \xec\xa0\x80\xec\x9e\xa5\xed\x95\x98\xeb\x8a\x94 \xec\xbb\xa8\xed\x85\x8c\xec\x9d\xb4\xeb\x84\x88\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4.\nTCP \xec\x84\x9c\xeb\xb2\x84\xec\x97\x90 \xec\x9d\x98\xed\x95\xb4 \xec\xb0\xb8\xec\xa1\xb0\xeb\x90\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_APacketContainer_Statics::NewProp_PacketMap = { UE4CodeGen_Private::EPropertyClass::Map, "PacketMap", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000010005, 1, nullptr, STRUCT_OFFSET(APacketContainer, PacketMap), METADATA_PARAMS(Z_Construct_UClass_APacketContainer_Statics::NewProp_PacketMap_MetaData, ARRAY_COUNT(Z_Construct_UClass_APacketContainer_Statics::NewProp_PacketMap_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_APacketContainer_Statics::NewProp_PacketMap_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Str, "PacketMap_Key", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000001, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_APacketContainer_Statics::NewProp_PacketMap_ValueProp = { UE4CodeGen_Private::EPropertyClass::Str, "PacketMap", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000001, 1, nullptr, 1, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APacketContainer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APacketContainer_Statics::NewProp_PacketMap,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APacketContainer_Statics::NewProp_PacketMap_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APacketContainer_Statics::NewProp_PacketMap_ValueProp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APacketContainer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APacketContainer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APacketContainer_Statics::ClassParams = {
		&APacketContainer::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_APacketContainer_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_APacketContainer_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_APacketContainer_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_APacketContainer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APacketContainer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APacketContainer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APacketContainer, 2087637349);
	static FCompiledInDefer Z_CompiledInDefer_UClass_APacketContainer(Z_Construct_UClass_APacketContainer, &APacketContainer::StaticClass, TEXT("/Script/NetCuteGhost"), TEXT("APacketContainer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APacketContainer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
