// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class TXTDATA_PARSER_API MyDataParser
{
public:
	MyDataParser();
	~MyDataParser();

	void SaveTextData(const FString& FilePath, const TArray<FString>& Data);
	void LoadTextData(const FString& FilePath, TArray<FString>& Result);
	FString CombineData(const TArray<FString>& Data);
	void SeparateString(const FString& String, TArray<FString>& Result);
};
