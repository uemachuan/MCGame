// Fill out your copyright notice in the Description page of Project Settings.

#include "MCGame.h"
#include "Public/Tools/JsonConfig.h"

#include "Json.h"

// Sets default values
UJsonConfig::UJsonConfig()
{
}

//��ȡJSON�ļ�
TSharedPtr<class FJsonObject> UJsonConfig::ReadJSONFile(const FString& Filename)
{
	//������Ϸ�Ļ���/����Ŀ¼
	FString GameDir = FPaths::GameDir();

	//read in file as string
	FString FileContents;
	if (!FFileHelper::LoadFileToString(FileContents, *Filename))
	{
		//UE_LOG(LogObj, Error, TEXT("Failed to load file %s."), *Filename);
		return nullptr;
	}
	if (FileContents.IsEmpty())
	{
		return nullptr;
	}
	//parse as JSON
	TSharedPtr<FJsonObject> JSONObject;
	TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(FileContents);
	if (!FJsonSerializer::Deserialize(Reader, JSONObject) || !JSONObject.IsValid())
	{
		//UE_LOG(LogObj, Warning, TEXT("Invalid JSON in file %s."), *Filename);
		return nullptr;
	}

	return JSONObject;
}


