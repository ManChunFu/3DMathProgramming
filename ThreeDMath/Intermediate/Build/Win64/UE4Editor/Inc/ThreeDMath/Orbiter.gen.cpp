// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ThreeDMath/Orbiter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOrbiter() {}
// Cross Module References
	THREEDMATH_API UClass* Z_Construct_UClass_AOrbiter_NoRegister();
	THREEDMATH_API UClass* Z_Construct_UClass_AOrbiter();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ThreeDMath();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
// End Cross Module References
	void AOrbiter::StaticRegisterNativesAOrbiter()
	{
	}
	UClass* Z_Construct_UClass_AOrbiter_NoRegister()
	{
		return AOrbiter::StaticClass();
	}
	struct Z_Construct_UClass_AOrbiter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Planet_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Planet;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RootSceneComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RootSceneComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Radius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Offset_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Offset;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOrbiter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ThreeDMath,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOrbiter_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Orbiter.h" },
		{ "ModuleRelativePath", "Orbiter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOrbiter_Statics::NewProp_Planet_MetaData[] = {
		{ "Category", "Sphere" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Orbiter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOrbiter_Statics::NewProp_Planet = { "Planet", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOrbiter, Planet), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AOrbiter_Statics::NewProp_Planet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOrbiter_Statics::NewProp_Planet_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOrbiter_Statics::NewProp_RootSceneComponent_MetaData[] = {
		{ "Category", "Sphere" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Orbiter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOrbiter_Statics::NewProp_RootSceneComponent = { "RootSceneComponent", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOrbiter, RootSceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AOrbiter_Statics::NewProp_RootSceneComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOrbiter_Statics::NewProp_RootSceneComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOrbiter_Statics::NewProp_Radius_MetaData[] = {
		{ "Category", "Orbit" },
		{ "ModuleRelativePath", "Orbiter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AOrbiter_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOrbiter, Radius), METADATA_PARAMS(Z_Construct_UClass_AOrbiter_Statics::NewProp_Radius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOrbiter_Statics::NewProp_Radius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOrbiter_Statics::NewProp_Offset_MetaData[] = {
		{ "Category", "Orbit" },
		{ "ModuleRelativePath", "Orbiter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AOrbiter_Statics::NewProp_Offset = { "Offset", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AOrbiter, Offset), METADATA_PARAMS(Z_Construct_UClass_AOrbiter_Statics::NewProp_Offset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AOrbiter_Statics::NewProp_Offset_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOrbiter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbiter_Statics::NewProp_Planet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbiter_Statics::NewProp_RootSceneComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbiter_Statics::NewProp_Radius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbiter_Statics::NewProp_Offset,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOrbiter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOrbiter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AOrbiter_Statics::ClassParams = {
		&AOrbiter::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AOrbiter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AOrbiter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AOrbiter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AOrbiter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AOrbiter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AOrbiter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AOrbiter, 49285904);
	template<> THREEDMATH_API UClass* StaticClass<AOrbiter>()
	{
		return AOrbiter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AOrbiter(Z_Construct_UClass_AOrbiter, &AOrbiter::StaticClass, TEXT("/Script/ThreeDMath"), TEXT("AOrbiter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOrbiter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
