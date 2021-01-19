// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ThreeDMath/IKSolver.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIKSolver() {}
// Cross Module References
	THREEDMATH_API UClass* Z_Construct_UClass_AIKSolver_NoRegister();
	THREEDMATH_API UClass* Z_Construct_UClass_AIKSolver();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ThreeDMath();
	ENGINE_API UClass* Z_Construct_UClass_UArrowComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	void AIKSolver::StaticRegisterNativesAIKSolver()
	{
	}
	UClass* Z_Construct_UClass_AIKSolver_NoRegister()
	{
		return AIKSolver::StaticClass();
	}
	struct Z_Construct_UClass_AIKSolver_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LinearArrow_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LinearArrow;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Joint_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Joint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UpperSegment_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_UpperSegment;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LowerSegment_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LowerSegment;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VerticalMarker_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_VerticalMarker;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EndPoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EndPoint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UpperArm_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_UpperArm;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LowerArm_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LowerArm;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TargetLocation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IKOrigin_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_IKOrigin;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AIKSolver_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ThreeDMath,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AIKSolver_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "IKSolver.h" },
		{ "ModuleRelativePath", "IKSolver.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AIKSolver_Statics::NewProp_LinearArrow_MetaData[] = {
		{ "Category", "IKSolver" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "IKSolver.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AIKSolver_Statics::NewProp_LinearArrow = { "LinearArrow", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AIKSolver, LinearArrow), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AIKSolver_Statics::NewProp_LinearArrow_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AIKSolver_Statics::NewProp_LinearArrow_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AIKSolver_Statics::NewProp_Joint_MetaData[] = {
		{ "Category", "IKSolver" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "IKSolver.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AIKSolver_Statics::NewProp_Joint = { "Joint", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AIKSolver, Joint), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AIKSolver_Statics::NewProp_Joint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AIKSolver_Statics::NewProp_Joint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AIKSolver_Statics::NewProp_UpperSegment_MetaData[] = {
		{ "Category", "IKSolver" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "IKSolver.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AIKSolver_Statics::NewProp_UpperSegment = { "UpperSegment", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AIKSolver, UpperSegment), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AIKSolver_Statics::NewProp_UpperSegment_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AIKSolver_Statics::NewProp_UpperSegment_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AIKSolver_Statics::NewProp_LowerSegment_MetaData[] = {
		{ "Category", "IKSolver" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "IKSolver.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AIKSolver_Statics::NewProp_LowerSegment = { "LowerSegment", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AIKSolver, LowerSegment), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AIKSolver_Statics::NewProp_LowerSegment_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AIKSolver_Statics::NewProp_LowerSegment_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AIKSolver_Statics::NewProp_VerticalMarker_MetaData[] = {
		{ "Category", "IKSolver" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "IKSolver.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AIKSolver_Statics::NewProp_VerticalMarker = { "VerticalMarker", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AIKSolver, VerticalMarker), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AIKSolver_Statics::NewProp_VerticalMarker_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AIKSolver_Statics::NewProp_VerticalMarker_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AIKSolver_Statics::NewProp_EndPoint_MetaData[] = {
		{ "Category", "IKSolver" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "IKSolver.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AIKSolver_Statics::NewProp_EndPoint = { "EndPoint", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AIKSolver, EndPoint), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AIKSolver_Statics::NewProp_EndPoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AIKSolver_Statics::NewProp_EndPoint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AIKSolver_Statics::NewProp_UpperArm_MetaData[] = {
		{ "Category", "IKSolver" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "IKSolver.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AIKSolver_Statics::NewProp_UpperArm = { "UpperArm", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AIKSolver, UpperArm), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AIKSolver_Statics::NewProp_UpperArm_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AIKSolver_Statics::NewProp_UpperArm_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AIKSolver_Statics::NewProp_LowerArm_MetaData[] = {
		{ "Category", "IKSolver" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "IKSolver.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AIKSolver_Statics::NewProp_LowerArm = { "LowerArm", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AIKSolver, LowerArm), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AIKSolver_Statics::NewProp_LowerArm_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AIKSolver_Statics::NewProp_LowerArm_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AIKSolver_Statics::NewProp_TargetLocation_MetaData[] = {
		{ "Category", "IKSolver" },
		{ "MakeEditWidget", "TRUE" },
		{ "ModuleRelativePath", "IKSolver.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AIKSolver_Statics::NewProp_TargetLocation = { "TargetLocation", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AIKSolver, TargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AIKSolver_Statics::NewProp_TargetLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AIKSolver_Statics::NewProp_TargetLocation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AIKSolver_Statics::NewProp_IKOrigin_MetaData[] = {
		{ "Category", "IKSolver" },
		{ "MakeEditWidget", "TRUE" },
		{ "ModuleRelativePath", "IKSolver.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AIKSolver_Statics::NewProp_IKOrigin = { "IKOrigin", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AIKSolver, IKOrigin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AIKSolver_Statics::NewProp_IKOrigin_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AIKSolver_Statics::NewProp_IKOrigin_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AIKSolver_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIKSolver_Statics::NewProp_LinearArrow,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIKSolver_Statics::NewProp_Joint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIKSolver_Statics::NewProp_UpperSegment,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIKSolver_Statics::NewProp_LowerSegment,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIKSolver_Statics::NewProp_VerticalMarker,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIKSolver_Statics::NewProp_EndPoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIKSolver_Statics::NewProp_UpperArm,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIKSolver_Statics::NewProp_LowerArm,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIKSolver_Statics::NewProp_TargetLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AIKSolver_Statics::NewProp_IKOrigin,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AIKSolver_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AIKSolver>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AIKSolver_Statics::ClassParams = {
		&AIKSolver::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AIKSolver_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AIKSolver_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AIKSolver_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AIKSolver_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AIKSolver()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AIKSolver_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AIKSolver, 2978898074);
	template<> THREEDMATH_API UClass* StaticClass<AIKSolver>()
	{
		return AIKSolver::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AIKSolver(Z_Construct_UClass_AIKSolver, &AIKSolver::StaticClass, TEXT("/Script/ThreeDMath"), TEXT("AIKSolver"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AIKSolver);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
