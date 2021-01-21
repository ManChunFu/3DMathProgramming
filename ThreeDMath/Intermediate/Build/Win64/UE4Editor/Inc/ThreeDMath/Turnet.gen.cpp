// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ThreeDMath/Turnet.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTurnet() {}
// Cross Module References
	THREEDMATH_API UEnum* Z_Construct_UEnum_ThreeDMath_EAimPoint();
	UPackage* Z_Construct_UPackage__Script_ThreeDMath();
	THREEDMATH_API UClass* Z_Construct_UClass_ATurnet_NoRegister();
	THREEDMATH_API UClass* Z_Construct_UClass_ATurnet();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UArrowComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	THREEDMATH_API UClass* Z_Construct_UClass_ABullet_NoRegister();
// End Cross Module References
	static UEnum* EAimPoint_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ThreeDMath_EAimPoint, Z_Construct_UPackage__Script_ThreeDMath(), TEXT("EAimPoint"));
		}
		return Singleton;
	}
	template<> THREEDMATH_API UEnum* StaticEnum<EAimPoint>()
	{
		return EAimPoint_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EAimPoint(EAimPoint_StaticEnum, TEXT("/Script/ThreeDMath"), TEXT("EAimPoint"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ThreeDMath_EAimPoint_Hash() { return 1545365718U; }
	UEnum* Z_Construct_UEnum_ThreeDMath_EAimPoint()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ThreeDMath();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EAimPoint"), 0, Get_Z_Construct_UEnum_ThreeDMath_EAimPoint_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EAimPoint::EAP_Head", (int64)EAimPoint::EAP_Head },
				{ "EAimPoint::EAP_LeftArm", (int64)EAimPoint::EAP_LeftArm },
				{ "EAimPoint::EAP_RightArm", (int64)EAimPoint::EAP_RightArm },
				{ "EAimPoint::EAP_LeftLeg", (int64)EAimPoint::EAP_LeftLeg },
				{ "EAimPoint::EAP_RightLeg", (int64)EAimPoint::EAP_RightLeg },
				{ "EAimPoint::EAP_Body", (int64)EAimPoint::EAP_Body },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "EAP_Body.DisplayName", "Body" },
				{ "EAP_Body.Name", "EAimPoint::EAP_Body" },
				{ "EAP_Head.DisplayName", "Head" },
				{ "EAP_Head.Name", "EAimPoint::EAP_Head" },
				{ "EAP_LeftArm.DisplayName", "LeftArm" },
				{ "EAP_LeftArm.Name", "EAimPoint::EAP_LeftArm" },
				{ "EAP_LeftLeg.DisplayName", "LeftLeg" },
				{ "EAP_LeftLeg.Name", "EAimPoint::EAP_LeftLeg" },
				{ "EAP_RightArm.DisplayName", "RightArm" },
				{ "EAP_RightArm.Name", "EAimPoint::EAP_RightArm" },
				{ "EAP_RightLeg.DisplayName", "RightLeg" },
				{ "EAP_RightLeg.Name", "EAimPoint::EAP_RightLeg" },
				{ "ModuleRelativePath", "Turnet.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ThreeDMath,
				nullptr,
				"EAimPoint",
				"EAimPoint",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static FName NAME_ATurnet_Shoot = FName(TEXT("Shoot"));
	void ATurnet::Shoot(FVector Velocity, float Speed)
	{
		Turnet_eventShoot_Parms Parms;
		Parms.Velocity=Velocity;
		Parms.Speed=Speed;
		ProcessEvent(FindFunctionChecked(NAME_ATurnet_Shoot),&Parms);
	}
	void ATurnet::StaticRegisterNativesATurnet()
	{
	}
	struct Z_Construct_UFunction_ATurnet_Shoot_Statics
	{
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Velocity;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Speed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATurnet_Shoot_Statics::NewProp_Velocity = { "Velocity", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Turnet_eventShoot_Parms, Velocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ATurnet_Shoot_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Turnet_eventShoot_Parms, Speed), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATurnet_Shoot_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnet_Shoot_Statics::NewProp_Velocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnet_Shoot_Statics::NewProp_Speed,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATurnet_Shoot_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Turnet.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnet_Shoot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnet, nullptr, "Shoot", nullptr, nullptr, sizeof(Turnet_eventShoot_Parms), Z_Construct_UFunction_ATurnet_Shoot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnet_Shoot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATurnet_Shoot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnet_Shoot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATurnet_Shoot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATurnet_Shoot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ATurnet_NoRegister()
	{
		return ATurnet::StaticClass();
	}
	struct Z_Construct_UClass_ATurnet_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Body_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Body;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Parent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Parent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Base_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Base;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Barrel_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Barrel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Target;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InterpSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InterpSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BulletSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BulletSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TurnetHorizontalLimit_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TurnetHorizontalLimit;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_AimPoint_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AimPoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_AimPoint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Bullet_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Bullet;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsShooting_MetaData[];
#endif
		static void NewProp_bIsShooting_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsShooting;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATurnet_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ThreeDMath,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATurnet_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATurnet_Shoot, "Shoot" }, // 2807944856
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATurnet_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Turnet.h" },
		{ "ModuleRelativePath", "Turnet.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATurnet_Statics::NewProp_Body_MetaData[] = {
		{ "Category", "Turnet" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Turnet.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATurnet_Statics::NewProp_Body = { "Body", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATurnet, Body), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATurnet_Statics::NewProp_Body_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATurnet_Statics::NewProp_Body_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATurnet_Statics::NewProp_Parent_MetaData[] = {
		{ "Category", "Turnet" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Turnet.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATurnet_Statics::NewProp_Parent = { "Parent", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATurnet, Parent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATurnet_Statics::NewProp_Parent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATurnet_Statics::NewProp_Parent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATurnet_Statics::NewProp_Base_MetaData[] = {
		{ "Category", "Turnet" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Turnet.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATurnet_Statics::NewProp_Base = { "Base", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATurnet, Base), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATurnet_Statics::NewProp_Base_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATurnet_Statics::NewProp_Base_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATurnet_Statics::NewProp_Barrel_MetaData[] = {
		{ "Category", "Turnet" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Turnet.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATurnet_Statics::NewProp_Barrel = { "Barrel", nullptr, (EPropertyFlags)0x001000000009000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATurnet, Barrel), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATurnet_Statics::NewProp_Barrel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATurnet_Statics::NewProp_Barrel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATurnet_Statics::NewProp_Target_MetaData[] = {
		{ "Category", "Turnet" },
		{ "ModuleRelativePath", "Turnet.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATurnet_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATurnet, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATurnet_Statics::NewProp_Target_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATurnet_Statics::NewProp_Target_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATurnet_Statics::NewProp_InterpSpeed_MetaData[] = {
		{ "Category", "Turnet" },
		{ "ModuleRelativePath", "Turnet.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATurnet_Statics::NewProp_InterpSpeed = { "InterpSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATurnet, InterpSpeed), METADATA_PARAMS(Z_Construct_UClass_ATurnet_Statics::NewProp_InterpSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATurnet_Statics::NewProp_InterpSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATurnet_Statics::NewProp_BulletSpeed_MetaData[] = {
		{ "Category", "Turnet" },
		{ "ModuleRelativePath", "Turnet.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATurnet_Statics::NewProp_BulletSpeed = { "BulletSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATurnet, BulletSpeed), METADATA_PARAMS(Z_Construct_UClass_ATurnet_Statics::NewProp_BulletSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATurnet_Statics::NewProp_BulletSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATurnet_Statics::NewProp_TurnetHorizontalLimit_MetaData[] = {
		{ "Category", "Turnet" },
		{ "ModuleRelativePath", "Turnet.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATurnet_Statics::NewProp_TurnetHorizontalLimit = { "TurnetHorizontalLimit", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATurnet, TurnetHorizontalLimit), METADATA_PARAMS(Z_Construct_UClass_ATurnet_Statics::NewProp_TurnetHorizontalLimit_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATurnet_Statics::NewProp_TurnetHorizontalLimit_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_ATurnet_Statics::NewProp_AimPoint_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATurnet_Statics::NewProp_AimPoint_MetaData[] = {
		{ "Category", "Turnet" },
		{ "ModuleRelativePath", "Turnet.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ATurnet_Statics::NewProp_AimPoint = { "AimPoint", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATurnet, AimPoint), Z_Construct_UEnum_ThreeDMath_EAimPoint, METADATA_PARAMS(Z_Construct_UClass_ATurnet_Statics::NewProp_AimPoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATurnet_Statics::NewProp_AimPoint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATurnet_Statics::NewProp_Bullet_MetaData[] = {
		{ "Category", "Bullet" },
		{ "ModuleRelativePath", "Turnet.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATurnet_Statics::NewProp_Bullet = { "Bullet", nullptr, (EPropertyFlags)0x0014000000010005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATurnet, Bullet), Z_Construct_UClass_ABullet_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ATurnet_Statics::NewProp_Bullet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATurnet_Statics::NewProp_Bullet_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATurnet_Statics::NewProp_bIsShooting_MetaData[] = {
		{ "Category", "Turnet" },
		{ "ModuleRelativePath", "Turnet.h" },
	};
#endif
	void Z_Construct_UClass_ATurnet_Statics::NewProp_bIsShooting_SetBit(void* Obj)
	{
		((ATurnet*)Obj)->bIsShooting = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATurnet_Statics::NewProp_bIsShooting = { "bIsShooting", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ATurnet), &Z_Construct_UClass_ATurnet_Statics::NewProp_bIsShooting_SetBit, METADATA_PARAMS(Z_Construct_UClass_ATurnet_Statics::NewProp_bIsShooting_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATurnet_Statics::NewProp_bIsShooting_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATurnet_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnet_Statics::NewProp_Body,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnet_Statics::NewProp_Parent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnet_Statics::NewProp_Base,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnet_Statics::NewProp_Barrel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnet_Statics::NewProp_Target,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnet_Statics::NewProp_InterpSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnet_Statics::NewProp_BulletSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnet_Statics::NewProp_TurnetHorizontalLimit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnet_Statics::NewProp_AimPoint_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnet_Statics::NewProp_AimPoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnet_Statics::NewProp_Bullet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnet_Statics::NewProp_bIsShooting,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATurnet_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATurnet>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATurnet_Statics::ClassParams = {
		&ATurnet::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATurnet_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ATurnet_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ATurnet_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATurnet_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATurnet()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATurnet_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATurnet, 557850706);
	template<> THREEDMATH_API UClass* StaticClass<ATurnet>()
	{
		return ATurnet::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATurnet(Z_Construct_UClass_ATurnet, &ATurnet::StaticClass, TEXT("/Script/ThreeDMath"), TEXT("ATurnet"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATurnet);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
