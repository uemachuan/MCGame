// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Object.h"
#include "JsonConfig.generated.h"

struct MCGAME_API FTestConfig
{
	int ID;
	FString Desc;

	FTestConfig()
		: ID(0), Desc(TEXT(""))
	{}
};

/**
 * 
 */
UCLASS()
class MCGAME_API UJsonConfig : public UObject
{
	GENERATED_BODY()
	
public:
	// Sets default values for this object's properties
	UJsonConfig();
	// 读取Json文件
	static TSharedPtr<class FJsonObject> ReadJSONFile(const FString& FileName);

public:
	// 获取测试配置
	static bool GetTestConfig(TArray<FTestConfig>& TestConfig);
};
