// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NetCuteGhost/Public/GhostElements/MNSGhostPawnBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMNSGhostPawnBase() {}
// Cross Module References
	NETCUTEGHOST_API UClass* Z_Construct_UClass_AMNSGhostPawnBase_NoRegister();
	NETCUTEGHOST_API UClass* Z_Construct_UClass_AMNSGhostPawnBase();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_NetCuteGhost();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
// End Cross Module References
	void AMNSGhostPawnBase::StaticRegisterNativesAMNSGhostPawnBase()
	{
	}
	UClass* Z_Construct_UClass_AMNSGhostPawnBase_NoRegister()
	{
		return AMNSGhostPawnBase::StaticClass();
	}
	struct Z_Construct_UClass_AMNSGhostPawnBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PtcCompoment_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PtcCompoment;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SphereComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SphereComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GhostHP_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_GhostHP;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMNSGhostPawnBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_NetCuteGhost,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMNSGhostPawnBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "GhostElements/MNSGhostPawnBase.h" },
		{ "ModuleRelativePath", "Public/GhostElements/MNSGhostPawnBase.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMNSGhostPawnBase_Statics::NewProp_PtcCompoment_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Ghost|Effect" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GhostElements/MNSGhostPawnBase.h" },
		{ "ToolTip", "CuteGhost\xec\x9d\x98 \xec\xa4\x91\xec\x8b\xac\xec\x97\x90\xec\x84\x9c \xec\x9d\xbc\xec\x96\xb4\xeb\x82\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8a\x94 \xeb\x8b\xa4\xec\x96\x91\xed\x95\x9c VFX\xeb\xa5\xbc \xec\x9c\x84\xed\x95\x9c \xed\x8c\x8c\xed\x8b\xb0\xed\x81\xb4 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMNSGhostPawnBase_Statics::NewProp_PtcCompoment = { UE4CodeGen_Private::EPropertyClass::Object, "PtcCompoment", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x004000000008000d, 1, nullptr, STRUCT_OFFSET(AMNSGhostPawnBase, PtcCompoment), Z_Construct_UClass_UParticleSystemComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMNSGhostPawnBase_Statics::NewProp_PtcCompoment_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMNSGhostPawnBase_Statics::NewProp_PtcCompoment_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMNSGhostPawnBase_Statics::NewProp_SphereComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Ghost|Collision" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GhostElements/MNSGhostPawnBase.h" },
		{ "ToolTip", "CuteGhost\xec\x97\x90 \xeb\x8c\x80\xed\x95\x9c \xea\xb2\x8c\xec\x9e\x84\xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4 \xec\xbd\x9c\xeb\xa6\xac\xec\xa0\x84\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4. \xec\xa0\x95\xea\xb5\x90\xed\x95\x9c \xec\xbd\x9c\xeb\xa6\xac\xec\xa0\x84 \xec\x84\xa4\xec\xa0\x95\xec\x9d\x84 \xec\x9b\x90\xed\x95\x9c\xeb\x8b\xa4\xeb\xa9\xb4\n\xec\x8a\xa4\xed\x83\x9c\xed\x8b\xb1 \xeb\xa9\x94\xec\x8b\x9c \xec\x97\x90\xeb\x94\x94\xed\x84\xb0\xec\x97\x90\xec\x84\x9c \xec\x95\x8c\xeb\xa7\x9e\xec\x9d\x80 \xec\xbd\x9c\xeb\xa6\xac\xec\xa0\x84\xec\x9d\x84 \xec\x84\xa4\xec\xa0\x95\xed\x95\x98\xec\x8b\x9c\xea\xb8\xb8 \xeb\xb0\x94\xeb\x9e\x8d\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMNSGhostPawnBase_Statics::NewProp_SphereComponent = { UE4CodeGen_Private::EPropertyClass::Object, "SphereComponent", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x004000000008000d, 1, nullptr, STRUCT_OFFSET(AMNSGhostPawnBase, SphereComponent), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMNSGhostPawnBase_Statics::NewProp_SphereComponent_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMNSGhostPawnBase_Statics::NewProp_SphereComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMNSGhostPawnBase_Statics::NewProp_GhostHP_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Ghost|Character" },
		{ "ModuleRelativePath", "Public/GhostElements/MNSGhostPawnBase.h" },
		{ "ToolTip", "\xea\xb3\xa0\xec\x8a\xa4\xed\x8a\xb8\xec\x9d\x98 \xec\xb2\xb4\xeb\xa0\xa5\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AMNSGhostPawnBase_Statics::NewProp_GhostHP = { UE4CodeGen_Private::EPropertyClass::Int, "GhostHP", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000005, 1, nullptr, STRUCT_OFFSET(AMNSGhostPawnBase, GhostHP), METADATA_PARAMS(Z_Construct_UClass_AMNSGhostPawnBase_Statics::NewProp_GhostHP_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMNSGhostPawnBase_Statics::NewProp_GhostHP_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMNSGhostPawnBase_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMNSGhostPawnBase_Statics::NewProp_PtcCompoment,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMNSGhostPawnBase_Statics::NewProp_SphereComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMNSGhostPawnBase_Statics::NewProp_GhostHP,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMNSGhostPawnBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMNSGhostPawnBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMNSGhostPawnBase_Statics::ClassParams = {
		&AMNSGhostPawnBase::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_AMNSGhostPawnBase_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AMNSGhostPawnBase_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AMNSGhostPawnBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMNSGhostPawnBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMNSGhostPawnBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMNSGhostPawnBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMNSGhostPawnBase, 1641045652);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMNSGhostPawnBase(Z_Construct_UClass_AMNSGhostPawnBase, &AMNSGhostPawnBase::StaticClass, TEXT("/Script/NetCuteGhost"), TEXT("AMNSGhostPawnBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMNSGhostPawnBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
