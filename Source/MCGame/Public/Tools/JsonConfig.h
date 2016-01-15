// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Object.h"
#include "JsonConfig.generated.h"

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
	//¶ÁÈ¡JSONÎÄ¼þ
	static TSharedPtr<class FJsonObject> ReadJSONFile(const FString& FileName);
	
};
