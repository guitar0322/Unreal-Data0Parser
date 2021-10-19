// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDataParser.h"

MyDataParser::MyDataParser()
{
}

MyDataParser::~MyDataParser()
{
}

void MyDataParser::SaveTextData(const FString& FilePath, const TArray<FString>& Data)
{
	FFileHelper::SaveStringToFile(CombineData(Data), *FilePath);
}

FString MyDataParser::CombineData(const TArray<FString>& Data)
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

void MyDataParser::LoadTextData(const FString& FilePath, TArray<FString>& Result)
{
	FString LoadedData;
	FFileHelper::LoadFileToString(LoadedData, *FilePath);
	SeparateString(LoadedData, Result);
}

void MyDataParser::SeparateString(const FString& String, TArray<FString>& Result)
{
	String.ParseIntoArray(Result, TEXT(","));
}
