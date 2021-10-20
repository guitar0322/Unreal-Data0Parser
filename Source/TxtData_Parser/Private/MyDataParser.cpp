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

void MyDataParser::SaveTextData(const FString& FilePath, const TArray<FString>& Col, const TArray<FString>& Row, const TArray<TArray<FString>>& Data)
{
	TArray<FString> WholeStringData;
	FString ColStr = TEXT("\t");
	ColStr += CombineData(Col);
	WholeStringData.Add(ColStr);
	for (int i = 0; i < Row.Num(); ++i)
	{
		FString RowStr = Row[i];
		RowStr += "\t";
		if (i >= Data.Num())
		{
			RowStr += GetNullString(Col.Num());
		}
		else
		{
			RowStr += CombineData(Data[i]);
		}
		WholeStringData.Add(RowStr);
	}
	FFileHelper::SaveStringArrayToFile(WholeStringData, *FilePath);
}

FString MyDataParser::CombineData(const TArray<FString>& Data)
{
	FString combineText = TEXT("");
	for (int i = 0; i < Data.Num(); ++i)
	{
		combineText += Data[i];
		if (i + 1 < Data.Num())
		{
			combineText += "\t";
		}
	}
	return combineText;
}

FString MyDataParser::CombineData(const FString& Elem, int Num)
{
	FString Result;
	for (int i = 0; i < Num; ++i)
	{
		Result += Elem;
		if (i + 1 != Num)
		{
			Result += "\t";
		}
	}
	return Result;
}

FString MyDataParser::GetNullString(int ColNum)
{
	return CombineData(TEXT("NULL"), ColNum);
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
