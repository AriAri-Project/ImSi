// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuackToHell/QuackToHellGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuackToHellGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
QUACKTOHELL_API UClass* Z_Construct_UClass_AQuackToHellGameMode();
QUACKTOHELL_API UClass* Z_Construct_UClass_AQuackToHellGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_QuackToHell();
// End Cross Module References

// Begin Class AQuackToHellGameMode Function CallChat
struct Z_Construct_UFunction_AQuackToHellGameMode_CallChat_Statics
{
	struct QuackToHellGameMode_eventCallChat_Parms
	{
		FString SendTo;
		FString SendMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Command" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xeb\x94\x94\xeb\xb2\x84\xea\xb9\x85 - \xed\x95\xa8\xec\x88\x98\xed\x98\xb8\xec\xb6\x9c\n" },
#endif
		{ "ModuleRelativePath", "QuackToHellGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x94\x94\xeb\xb2\x84\xea\xb9\x85 - \xed\x95\xa8\xec\x88\x98\xed\x98\xb8\xec\xb6\x9c" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_SendTo;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SendMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AQuackToHellGameMode_CallChat_Statics::NewProp_SendTo = { "SendTo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(QuackToHellGameMode_eventCallChat_Parms, SendTo), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AQuackToHellGameMode_CallChat_Statics::NewProp_SendMessage = { "SendMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(QuackToHellGameMode_eventCallChat_Parms, SendMessage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AQuackToHellGameMode_CallChat_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AQuackToHellGameMode_CallChat_Statics::NewProp_SendTo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AQuackToHellGameMode_CallChat_Statics::NewProp_SendMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AQuackToHellGameMode_CallChat_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AQuackToHellGameMode_CallChat_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AQuackToHellGameMode, nullptr, "CallChat", nullptr, nullptr, Z_Construct_UFunction_AQuackToHellGameMode_CallChat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AQuackToHellGameMode_CallChat_Statics::PropPointers), sizeof(Z_Construct_UFunction_AQuackToHellGameMode_CallChat_Statics::QuackToHellGameMode_eventCallChat_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020601, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AQuackToHellGameMode_CallChat_Statics::Function_MetaDataParams), Z_Construct_UFunction_AQuackToHellGameMode_CallChat_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AQuackToHellGameMode_CallChat_Statics::QuackToHellGameMode_eventCallChat_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AQuackToHellGameMode_CallChat()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AQuackToHellGameMode_CallChat_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AQuackToHellGameMode::execCallChat)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_SendTo);
	P_GET_PROPERTY(FStrProperty,Z_Param_SendMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CallChat(Z_Param_SendTo,Z_Param_SendMessage);
	P_NATIVE_END;
}
// End Class AQuackToHellGameMode Function CallChat

// Begin Class AQuackToHellGameMode Function PrintChatHistory
struct Z_Construct_UFunction_AQuackToHellGameMode_PrintChatHistory_Statics
{
	struct QuackToHellGameMode_eventPrintChatHistory_Parms
	{
		FString Name;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Command" },
		{ "ModuleRelativePath", "QuackToHellGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AQuackToHellGameMode_PrintChatHistory_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(QuackToHellGameMode_eventPrintChatHistory_Parms, Name), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AQuackToHellGameMode_PrintChatHistory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AQuackToHellGameMode_PrintChatHistory_Statics::NewProp_Name,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AQuackToHellGameMode_PrintChatHistory_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AQuackToHellGameMode_PrintChatHistory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AQuackToHellGameMode, nullptr, "PrintChatHistory", nullptr, nullptr, Z_Construct_UFunction_AQuackToHellGameMode_PrintChatHistory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AQuackToHellGameMode_PrintChatHistory_Statics::PropPointers), sizeof(Z_Construct_UFunction_AQuackToHellGameMode_PrintChatHistory_Statics::QuackToHellGameMode_eventPrintChatHistory_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020601, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AQuackToHellGameMode_PrintChatHistory_Statics::Function_MetaDataParams), Z_Construct_UFunction_AQuackToHellGameMode_PrintChatHistory_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AQuackToHellGameMode_PrintChatHistory_Statics::QuackToHellGameMode_eventPrintChatHistory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AQuackToHellGameMode_PrintChatHistory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AQuackToHellGameMode_PrintChatHistory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AQuackToHellGameMode::execPrintChatHistory)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PrintChatHistory(Z_Param_Name);
	P_NATIVE_END;
}
// End Class AQuackToHellGameMode Function PrintChatHistory

// Begin Class AQuackToHellGameMode
void AQuackToHellGameMode::StaticRegisterNativesAQuackToHellGameMode()
{
	UClass* Class = AQuackToHellGameMode::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CallChat", &AQuackToHellGameMode::execCallChat },
		{ "PrintChatHistory", &AQuackToHellGameMode::execPrintChatHistory },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AQuackToHellGameMode);
UClass* Z_Construct_UClass_AQuackToHellGameMode_NoRegister()
{
	return AQuackToHellGameMode::StaticClass();
}
struct Z_Construct_UClass_AQuackToHellGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "QuackToHellGameMode.h" },
		{ "ModuleRelativePath", "QuackToHellGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AQuackToHellGameMode_CallChat, "CallChat" }, // 3336854677
		{ &Z_Construct_UFunction_AQuackToHellGameMode_PrintChatHistory, "PrintChatHistory" }, // 709806301
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AQuackToHellGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AQuackToHellGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_QuackToHell,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AQuackToHellGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AQuackToHellGameMode_Statics::ClassParams = {
	&AQuackToHellGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AQuackToHellGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AQuackToHellGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AQuackToHellGameMode()
{
	if (!Z_Registration_Info_UClass_AQuackToHellGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AQuackToHellGameMode.OuterSingleton, Z_Construct_UClass_AQuackToHellGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AQuackToHellGameMode.OuterSingleton;
}
template<> QUACKTOHELL_API UClass* StaticClass<AQuackToHellGameMode>()
{
	return AQuackToHellGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AQuackToHellGameMode);
AQuackToHellGameMode::~AQuackToHellGameMode() {}
// End Class AQuackToHellGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_swu_Documents_Unreal_Projects_QuackToHell_OriginalRepo_QuackToHell_QuackToHell_Source_QuackToHell_QuackToHellGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AQuackToHellGameMode, AQuackToHellGameMode::StaticClass, TEXT("AQuackToHellGameMode"), &Z_Registration_Info_UClass_AQuackToHellGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AQuackToHellGameMode), 2283095479U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_swu_Documents_Unreal_Projects_QuackToHell_OriginalRepo_QuackToHell_QuackToHell_Source_QuackToHell_QuackToHellGameMode_h_2763999007(TEXT("/Script/QuackToHell"),
	Z_CompiledInDeferFile_FID_Users_swu_Documents_Unreal_Projects_QuackToHell_OriginalRepo_QuackToHell_QuackToHell_Source_QuackToHell_QuackToHellGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_swu_Documents_Unreal_Projects_QuackToHell_OriginalRepo_QuackToHell_QuackToHell_Source_QuackToHell_QuackToHellGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
