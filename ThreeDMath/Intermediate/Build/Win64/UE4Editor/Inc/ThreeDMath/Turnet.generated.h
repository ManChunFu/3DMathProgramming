// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef THREEDMATH_Turnet_generated_h
#error "Turnet.generated.h already included, missing '#pragma once' in Turnet.h"
#endif
#define THREEDMATH_Turnet_generated_h

#define ThreeDMath_Source_ThreeDMath_Turnet_h_23_SPARSE_DATA
#define ThreeDMath_Source_ThreeDMath_Turnet_h_23_RPC_WRAPPERS
#define ThreeDMath_Source_ThreeDMath_Turnet_h_23_RPC_WRAPPERS_NO_PURE_DECLS
#define ThreeDMath_Source_ThreeDMath_Turnet_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATurnet(); \
	friend struct Z_Construct_UClass_ATurnet_Statics; \
public: \
	DECLARE_CLASS(ATurnet, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ThreeDMath"), NO_API) \
	DECLARE_SERIALIZER(ATurnet)


#define ThreeDMath_Source_ThreeDMath_Turnet_h_23_INCLASS \
private: \
	static void StaticRegisterNativesATurnet(); \
	friend struct Z_Construct_UClass_ATurnet_Statics; \
public: \
	DECLARE_CLASS(ATurnet, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ThreeDMath"), NO_API) \
	DECLARE_SERIALIZER(ATurnet)


#define ThreeDMath_Source_ThreeDMath_Turnet_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATurnet(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATurnet) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATurnet); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATurnet); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATurnet(ATurnet&&); \
	NO_API ATurnet(const ATurnet&); \
public:


#define ThreeDMath_Source_ThreeDMath_Turnet_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATurnet(ATurnet&&); \
	NO_API ATurnet(const ATurnet&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATurnet); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATurnet); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATurnet)


#define ThreeDMath_Source_ThreeDMath_Turnet_h_23_PRIVATE_PROPERTY_OFFSET
#define ThreeDMath_Source_ThreeDMath_Turnet_h_20_PROLOG
#define ThreeDMath_Source_ThreeDMath_Turnet_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ThreeDMath_Source_ThreeDMath_Turnet_h_23_PRIVATE_PROPERTY_OFFSET \
	ThreeDMath_Source_ThreeDMath_Turnet_h_23_SPARSE_DATA \
	ThreeDMath_Source_ThreeDMath_Turnet_h_23_RPC_WRAPPERS \
	ThreeDMath_Source_ThreeDMath_Turnet_h_23_INCLASS \
	ThreeDMath_Source_ThreeDMath_Turnet_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ThreeDMath_Source_ThreeDMath_Turnet_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ThreeDMath_Source_ThreeDMath_Turnet_h_23_PRIVATE_PROPERTY_OFFSET \
	ThreeDMath_Source_ThreeDMath_Turnet_h_23_SPARSE_DATA \
	ThreeDMath_Source_ThreeDMath_Turnet_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	ThreeDMath_Source_ThreeDMath_Turnet_h_23_INCLASS_NO_PURE_DECLS \
	ThreeDMath_Source_ThreeDMath_Turnet_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> THREEDMATH_API UClass* StaticClass<class ATurnet>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ThreeDMath_Source_ThreeDMath_Turnet_h


#define FOREACH_ENUM_EAIMPOINT(op) \
	op(EAimPoint::EAP_Head) \
	op(EAimPoint::EAP_LeftArm) \
	op(EAimPoint::EAP_RightArm) \
	op(EAimPoint::EAP_LeftLeg) \
	op(EAimPoint::EAP_RightLeg) \
	op(EAimPoint::EAP_Body) 

enum class EAimPoint : uint8;
template<> THREEDMATH_API UEnum* StaticEnum<EAimPoint>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
