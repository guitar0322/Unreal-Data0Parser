// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 컬럼, 로우 테이블 형태로 저장되는 문자 데이터를 저장/불러오기 수행하는 클래스
 * 단순 데이터를 \t로 구분지어 한줄에 텍스트로 저장/불러오기를 수행하는 클래스
 */
class TXTDATA_PARSER_API MyDataParser
{
public:
	MyDataParser();
	~MyDataParser();

	void SaveTextData(const FString& FilePath, const TArray<FString>& InData);
	void SaveTextData(const FString& FilePath, const TArray<FString>& InCol, const TArray<FString>& InRow, const TArray<TArray<FString>>& InData);
	void LoadTextData(const FString& FilePath, TArray<FString>& Result);
	void LoadTextData(const FString& FilePath, TArray<TArray<FString>>& Result);
	FString CombineData(const TArray<FString>& InData);
	FString CombineData(const FString& Elem, int Num);
	FString GetNullString(int ColNum);
	void SeparateString(const FString& String, TArray<FString>& Result);
};
