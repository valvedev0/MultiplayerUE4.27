// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PUZZLEMP_PuzzleMPCharacter_generated_h
#error "PuzzleMPCharacter.generated.h already included, missing '#pragma once' in PuzzleMPCharacter.h"
#endif
#define PUZZLEMP_PuzzleMPCharacter_generated_h

#define PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_SPARSE_DATA
#define PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_RPC_WRAPPERS
#define PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPuzzleMPCharacter(); \
	friend struct Z_Construct_UClass_APuzzleMPCharacter_Statics; \
public: \
	DECLARE_CLASS(APuzzleMPCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PuzzleMP"), NO_API) \
	DECLARE_SERIALIZER(APuzzleMPCharacter)


#define PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAPuzzleMPCharacter(); \
	friend struct Z_Construct_UClass_APuzzleMPCharacter_Statics; \
public: \
	DECLARE_CLASS(APuzzleMPCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PuzzleMP"), NO_API) \
	DECLARE_SERIALIZER(APuzzleMPCharacter)


#define PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APuzzleMPCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APuzzleMPCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APuzzleMPCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APuzzleMPCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APuzzleMPCharacter(APuzzleMPCharacter&&); \
	NO_API APuzzleMPCharacter(const APuzzleMPCharacter&); \
public:


#define PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APuzzleMPCharacter(APuzzleMPCharacter&&); \
	NO_API APuzzleMPCharacter(const APuzzleMPCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APuzzleMPCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APuzzleMPCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APuzzleMPCharacter)


#define PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(APuzzleMPCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(APuzzleMPCharacter, FollowCamera); }


#define PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_9_PROLOG
#define PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_SPARSE_DATA \
	PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_RPC_WRAPPERS \
	PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_INCLASS \
	PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_SPARSE_DATA \
	PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_INCLASS_NO_PURE_DECLS \
	PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PUZZLEMP_API UClass* StaticClass<class APuzzleMPCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PuzzleMP_Source_PuzzleMP_PuzzleMPCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
