// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PuzzleMP/PuzzleMPGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePuzzleMPGameMode() {}
// Cross Module References
	PUZZLEMP_API UClass* Z_Construct_UClass_APuzzleMPGameMode_NoRegister();
	PUZZLEMP_API UClass* Z_Construct_UClass_APuzzleMPGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_PuzzleMP();
// End Cross Module References
	void APuzzleMPGameMode::StaticRegisterNativesAPuzzleMPGameMode()
	{
	}
	UClass* Z_Construct_UClass_APuzzleMPGameMode_NoRegister()
	{
		return APuzzleMPGameMode::StaticClass();
	}
	struct Z_Construct_UClass_APuzzleMPGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APuzzleMPGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_PuzzleMP,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APuzzleMPGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "PuzzleMPGameMode.h" },
		{ "ModuleRelativePath", "PuzzleMPGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APuzzleMPGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APuzzleMPGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APuzzleMPGameMode_Statics::ClassParams = {
		&APuzzleMPGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_APuzzleMPGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APuzzleMPGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APuzzleMPGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APuzzleMPGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APuzzleMPGameMode, 679336283);
	template<> PUZZLEMP_API UClass* StaticClass<APuzzleMPGameMode>()
	{
		return APuzzleMPGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APuzzleMPGameMode(Z_Construct_UClass_APuzzleMPGameMode, &APuzzleMPGameMode::StaticClass, TEXT("/Script/PuzzleMP"), TEXT("APuzzleMPGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APuzzleMPGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
