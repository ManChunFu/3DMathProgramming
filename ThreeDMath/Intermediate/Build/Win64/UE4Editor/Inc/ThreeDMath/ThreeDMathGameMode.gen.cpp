// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ThreeDMath/ThreeDMathGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeThreeDMathGameMode() {}
// Cross Module References
	THREEDMATH_API UClass* Z_Construct_UClass_AThreeDMathGameMode_NoRegister();
	THREEDMATH_API UClass* Z_Construct_UClass_AThreeDMathGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ThreeDMath();
// End Cross Module References
	void AThreeDMathGameMode::StaticRegisterNativesAThreeDMathGameMode()
	{
	}
	UClass* Z_Construct_UClass_AThreeDMathGameMode_NoRegister()
	{
		return AThreeDMathGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AThreeDMathGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AThreeDMathGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ThreeDMath,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AThreeDMathGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "ThreeDMathGameMode.h" },
		{ "ModuleRelativePath", "ThreeDMathGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AThreeDMathGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AThreeDMathGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AThreeDMathGameMode_Statics::ClassParams = {
		&AThreeDMathGameMode::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AThreeDMathGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AThreeDMathGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AThreeDMathGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AThreeDMathGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AThreeDMathGameMode, 1323688879);
	template<> THREEDMATH_API UClass* StaticClass<AThreeDMathGameMode>()
	{
		return AThreeDMathGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AThreeDMathGameMode(Z_Construct_UClass_AThreeDMathGameMode, &AThreeDMathGameMode::StaticClass, TEXT("/Script/ThreeDMath"), TEXT("AThreeDMathGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AThreeDMathGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
