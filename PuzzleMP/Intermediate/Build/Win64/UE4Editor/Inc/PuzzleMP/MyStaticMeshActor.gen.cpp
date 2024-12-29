// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PuzzleMP/MyStaticMeshActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyStaticMeshActor() {}
// Cross Module References
	PUZZLEMP_API UClass* Z_Construct_UClass_AMyStaticMeshActor_NoRegister();
	PUZZLEMP_API UClass* Z_Construct_UClass_AMyStaticMeshActor();
	ENGINE_API UClass* Z_Construct_UClass_AStaticMeshActor();
	UPackage* Z_Construct_UPackage__Script_PuzzleMP();
// End Cross Module References
	void AMyStaticMeshActor::StaticRegisterNativesAMyStaticMeshActor()
	{
	}
	UClass* Z_Construct_UClass_AMyStaticMeshActor_NoRegister()
	{
		return AMyStaticMeshActor::StaticClass();
	}
	struct Z_Construct_UClass_AMyStaticMeshActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Speed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Speed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyStaticMeshActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AStaticMeshActor,
		(UObject* (*)())Z_Construct_UPackage__Script_PuzzleMP,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyStaticMeshActor_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Input" },
		{ "IncludePath", "MyStaticMeshActor.h" },
		{ "ModuleRelativePath", "MyStaticMeshActor.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyStaticMeshActor_Statics::NewProp_Speed_MetaData[] = {
		{ "Category", "Speed" },
		{ "Comment", "//create a variable to store the speed of the actor\n" },
		{ "ModuleRelativePath", "MyStaticMeshActor.h" },
		{ "ToolTip", "create a variable to store the speed of the actor" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyStaticMeshActor_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyStaticMeshActor, Speed), METADATA_PARAMS(Z_Construct_UClass_AMyStaticMeshActor_Statics::NewProp_Speed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyStaticMeshActor_Statics::NewProp_Speed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyStaticMeshActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyStaticMeshActor_Statics::NewProp_Speed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyStaticMeshActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyStaticMeshActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMyStaticMeshActor_Statics::ClassParams = {
		&AMyStaticMeshActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMyStaticMeshActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AMyStaticMeshActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyStaticMeshActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyStaticMeshActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyStaticMeshActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMyStaticMeshActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMyStaticMeshActor, 3606982095);
	template<> PUZZLEMP_API UClass* StaticClass<AMyStaticMeshActor>()
	{
		return AMyStaticMeshActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyStaticMeshActor(Z_Construct_UClass_AMyStaticMeshActor, &AMyStaticMeshActor::StaticClass, TEXT("/Script/PuzzleMP"), TEXT("AMyStaticMeshActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyStaticMeshActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
