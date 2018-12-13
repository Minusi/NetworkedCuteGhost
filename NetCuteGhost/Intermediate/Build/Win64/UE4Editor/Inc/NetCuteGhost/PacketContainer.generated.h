// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NETCUTEGHOST_PacketContainer_generated_h
#error "PacketContainer.generated.h already included, missing '#pragma once' in PacketContainer.h"
#endif
#define NETCUTEGHOST_PacketContainer_generated_h

#define NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_12_RPC_WRAPPERS
#define NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPacketContainer(); \
	friend struct Z_Construct_UClass_APacketContainer_Statics; \
public: \
	DECLARE_CLASS(APacketContainer, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/NetCuteGhost"), NO_API) \
	DECLARE_SERIALIZER(APacketContainer)


#define NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAPacketContainer(); \
	friend struct Z_Construct_UClass_APacketContainer_Statics; \
public: \
	DECLARE_CLASS(APacketContainer, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/NetCuteGhost"), NO_API) \
	DECLARE_SERIALIZER(APacketContainer)


#define NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APacketContainer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APacketContainer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APacketContainer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APacketContainer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APacketContainer(APacketContainer&&); \
	NO_API APacketContainer(const APacketContainer&); \
public:


#define NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APacketContainer(APacketContainer&&); \
	NO_API APacketContainer(const APacketContainer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APacketContainer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APacketContainer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APacketContainer)


#define NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PacketMap() { return STRUCT_OFFSET(APacketContainer, PacketMap); }


#define NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_9_PROLOG
#define NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_12_PRIVATE_PROPERTY_OFFSET \
	NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_12_RPC_WRAPPERS \
	NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_12_INCLASS \
	NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_12_PRIVATE_PROPERTY_OFFSET \
	NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_12_INCLASS_NO_PURE_DECLS \
	NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID NetCuteGhost_Source_NetCuteGhost_Public_PacketContainer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
