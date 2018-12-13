// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NETCUTEGHOST_GhostTCPServer_generated_h
#error "GhostTCPServer.generated.h already included, missing '#pragma once' in GhostTCPServer.h"
#endif
#define NETCUTEGHOST_GhostTCPServer_generated_h

#define NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_20_RPC_WRAPPERS
#define NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGhostTCPServer(); \
	friend struct Z_Construct_UClass_AGhostTCPServer_Statics; \
public: \
	DECLARE_CLASS(AGhostTCPServer, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/NetCuteGhost"), NO_API) \
	DECLARE_SERIALIZER(AGhostTCPServer)


#define NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_20_INCLASS \
private: \
	static void StaticRegisterNativesAGhostTCPServer(); \
	friend struct Z_Construct_UClass_AGhostTCPServer_Statics; \
public: \
	DECLARE_CLASS(AGhostTCPServer, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/NetCuteGhost"), NO_API) \
	DECLARE_SERIALIZER(AGhostTCPServer)


#define NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGhostTCPServer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGhostTCPServer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGhostTCPServer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGhostTCPServer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGhostTCPServer(AGhostTCPServer&&); \
	NO_API AGhostTCPServer(const AGhostTCPServer&); \
public:


#define NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGhostTCPServer(AGhostTCPServer&&); \
	NO_API AGhostTCPServer(const AGhostTCPServer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGhostTCPServer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGhostTCPServer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGhostTCPServer)


#define NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ServerIP() { return STRUCT_OFFSET(AGhostTCPServer, ServerIP); } \
	FORCEINLINE static uint32 __PPO__ServerPort() { return STRUCT_OFFSET(AGhostTCPServer, ServerPort); } \
	FORCEINLINE static uint32 __PPO__PacketContainer() { return STRUCT_OFFSET(AGhostTCPServer, PacketContainer); }


#define NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_15_PROLOG
#define NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_20_PRIVATE_PROPERTY_OFFSET \
	NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_20_RPC_WRAPPERS \
	NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_20_INCLASS \
	NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_20_PRIVATE_PROPERTY_OFFSET \
	NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_20_INCLASS_NO_PURE_DECLS \
	NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID NetCuteGhost_Source_NetCuteGhost_Public_GhostTCPServer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
