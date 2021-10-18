// Fill out your copyright notice in the Description page of Project Settings.


#include "TextDataParser.h"
#include <vector>

using namespace std;
void UTextDataParser::SaveTextData(const FString& FilePath, const TArray<FString>& Data)
{
	
}

FString UTextDataParser::CombineData(const TArray<FString>& Data)
{
	FString combineText = TEXT("");
	for (int i = 0; i < Data.Num(); ++i)
	{
		combineText += Data[i];
		if (i + 1 < Data.Num())
		{
			combineText += ",";
		}
	}
	return combineText;
}