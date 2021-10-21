// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * �÷�, �ο� ���̺� ���·� ����Ǵ� ���� �����͸� ����/�ҷ����� �����ϴ� Ŭ����
 * �ܼ� �����͸� \t�� �������� ���ٿ� �ؽ�Ʈ�� ����/�ҷ����⸦ �����ϴ� Ŭ����
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
