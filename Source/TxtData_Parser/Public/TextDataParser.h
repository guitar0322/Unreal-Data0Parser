// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TextDataParser.generated.h"

/**
 * 
 */
UCLASS()
class TXTDATA_PARSER_API UTextDataParser : public UGameInstance
{
	GENERATED_BODY()
public:
	void SaveTextData(const FString& FilePath, const TArray<FString>& Data);
	FString CombineData(const TArray<FString>& Data);
};
