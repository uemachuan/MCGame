// Fill out your copyright notice in the Description page of Project Settings.

#include "MCGame.h"
#include "Public/Tools/JsonConfig.h"

#include "Json.h"

DEFINE_LOG_CATEGORY_STATIC(LogJsonConfig, Warning, All);

// Sets default values
UJsonConfig::UJsonConfig()
{
}

// 读取JSON文件
TSharedPtr<class FJsonObject> UJsonConfig::ReadJSONFile(const FString& Filename)
{
	// 返回游戏的基本/基础目录
	//FString GameDir = FPaths::GameDir();
	// 获取资源路径（E:/Unreal Projects/Demo/Filename）
	FString SourceFullPath = FString::Printf(TEXT("%s%s"), *(FPaths::GameDir()), *Filename);
	
	UE_LOG(LogJsonConfig, Warning, TEXT("SourceFullPath = %s"), *SourceFullPath);

	//read in file as string
	FString FileContents;
	if (!FFileHelper::LoadFileToString(FileContents, *SourceFullPath))
	{
		UE_LOG(LogJsonConfig, Warning, TEXT("Failed to load file %s."), *Filename);
		return nullptr;
	}
	if (FileContents.IsEmpty())
	{
		return nullptr;
	}
	
	//parse as JSON
	TSharedPtr<FJsonObject> JsonObj;
	TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(FileContents);
	if (!FJsonSerializer::Deserialize(Reader, JsonObj) || !JsonObj.IsValid())
	{
		UE_LOG(LogJsonConfig, Warning, TEXT("Invalid JSON in file %s."), *Filename);
		return nullptr;
	}

	return JsonObj;
}

bool UJsonConfig::GetTestConfig(TArray<FTestConfig>& TestConfig)
{
	TSharedPtr<FJsonObject> Root;
	Root = ReadJSONFile(TEXT("GameSource/Test.json"));
	if (!Root.IsValid())
	{
		return false;
	}
	const TArray<TSharedPtr<FJsonValue> > * JsonItems = nullptr;
	if (Root->TryGetArrayField(TEXT("Test"), JsonItems))
	{
		for (TSharedPtr<FJsonValue> JsonItem : *JsonItems)
		{
			const TSharedPtr<FJsonObject> & ItemObject = JsonItem->AsObject();
			FTestConfig TestConfigTemp;
			TestConfigTemp.ID		= ItemObject->GetIntegerField("ID");
			TestConfigTemp.Desc		= ItemObject->GetStringField("Desc");
			TestConfig.Add(TestConfigTemp);
			UE_LOG(LogJsonConfig, Warning, TEXT("Desc%i = %s"), TestConfigTemp.ID, *TestConfigTemp.Desc);
		}
		return true;
	}
	return false;
}
