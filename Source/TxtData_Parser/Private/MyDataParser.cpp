// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDataParser.h"

MyDataParser::MyDataParser()
{
}

MyDataParser::~MyDataParser()
{
}
/*
* 문자열 배열에 담긴 데이터를 구분자 \t로 구분지어 하나의 문자열로 조합해 텍스트파일에 저장합니다
* @param FilePath - 문자열 데이터를 저장할 파일의 경로
* @param InData - 각 데이터들을 담고있는 읽기전용 배열 레퍼런스
*/
void MyDataParser::SaveTextData(const FString& FilePath, const TArray<FString>& InData)
{
	FFileHelper::SaveStringToFile(CombineData(InData), *FilePath);
}

/*
* Col, Row를 가지는 테이블 형식으로 데이터를 문자열로 저장합니다.
* 각 Col 및 데이터들을 \t로 구분지어 저장합니다
* @param FilePath - 문자열 데이터를 저장할 파일의 경로
* @param InCol - 데이터 테이블에 저장될 Col 목록을 담고있는 읽기전용 배열
* @param InRow - 데이터 테이블에 저장될 Row 목록을 담고있는 읽기전용 배열
* @param InData - 테이블에 저장될 데이터를 담고있는 읽기전용 2차원 배열
*/
void MyDataParser::SaveTextData(const FString& FilePath, const TArray<FString>& InCol, const TArray<FString>& InRow, const TArray<TArray<FString>>& InData)
{
	//텍스트 파일에 저장될 전체 문자열을 담을 배열
	//Elem당 텍스트 파일에 저장될 라인 1줄을 저장
	TArray<FString> WholeStringData;
	WholeStringData.SetNum(InRow.Num() + 1);	//Col을 저장할 줄과 Row개수만큼 용량을 할당
	WholeStringData[0] = TEXT("\t");
	WholeStringData[0] += CombineData(InCol);	//Col을 저장할 문자열 라인을 구성
	for (int i = 0; i < InRow.Num(); ++i)
	{
		WholeStringData[i + 1] = InRow[i];		//Row이름으로 시작
		WholeStringData[i + 1] += "\t";			//구분자 추가
		//Row의 이름수가 Data의 개수보다 많을 경우 모든 데이터를 "NULL" 문자열로 채움
		if (i >= InData.Num())
		{
			WholeStringData[i + 1] += GetNullString(InCol.Num());
		}
		else
		{
			WholeStringData[i + 1] += CombineData(InData[i]);
		}
	}
	FFileHelper::SaveStringArrayToFile(WholeStringData, *FilePath);	//Elem당 한줄씩 텍스트파일에 저장
}

/*
* 배열에 담긴 각 문자열들을 \t로 구분하는 하나의 문자열로 조합하여 반환합니다
* @param InDataArr - 조합 대상이 되는 데이터들을 담고있는 읽기전용 배열
* @return Result - 데이터들이 조합된 하나의 문자열
*/
FString MyDataParser::CombineData(const TArray<FString>& InDataArr)
{
	FString Result = TEXT("");
	for (int i = 0; i < InDataArr.Num(); ++i)
	{
		Result += InDataArr[i];
		if (i + 1 < InDataArr.Num())
		{
			Result += "\t";
		}
	}
	return Result;
}

/*
* 하나의 문자열 데이터를 Num개 만큼 이어붙여 하나의 문자열로 조합합니다.
* @param Elem - 조합할 대상이될 문자열 데이터
* @param Num - 조합할 개수
* @return Result - Elem이 Num개 반복되어 조합된 문자열 결과
*/
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

/*
* 특정 개수의 "NULL" 문자열이 조합된 하나의 문자열을 반환합니다
* @param ColNum - "NULL"이 반복될 횟수
* @return - "NULL"이 ColNum번 만큼 반복되어 조합된 문자열 결과
*/
FString MyDataParser::GetNullString(int ColNum)
{
	return CombineData(TEXT("NULL"), ColNum);
}

/*
* 일렬로 저장된 단순 데이터를 읽어들여 구분자를 제거하는 작업을 거쳐 배열에 담습니다.
* @param FilePath - 데이터가 담겨있는 파일 경로
* @param Result - 결과를 반환받는 문자열 배열
*/
void MyDataParser::LoadTextData(const FString& FilePath, TArray<FString>& Result)
{
	FString LoadedData;
	FFileHelper::LoadFileToString(LoadedData, *FilePath);
	SeparateString(LoadedData, Result);
}

/*
* 테이블 형식으로 저장된 데이터를 읽어들여 2차원 배열에 담습니다.
* @param FilePath - 테이블 데이터가 담겨있는 파일 경로
* @param Result - 결과를 반환받는 2차원 문자열 배열
*/
void MyDataParser::LoadTextData(const FString& FilePath, TArray<TArray<FString>>& Result)
{
	TArray<FString> LineArray;	//파일의 각 줄을 저장하기 위한 임시 문자열 배열
	FFileHelper::LoadFileToStringArray(LineArray, *FilePath);	//파일의 내용 한줄씩 LineArray에 저장
	Result.SetNum(LineArray.Num() - 1);//반환 받는 배열의 크기를 설정
	for (int i = 0; i < LineArray.Num() - 1; ++i)
	{
		SeparateString(LineArray[i+1], Result[i]);
	}
}

/*
* 문자열에서 구분자를 제거하는 작업을 거쳐 문자열 배열로 반환합니다.
* @param String - 조합되어 있는 하나의 문자열
* @param Result - 구분자를 제거한 결과를 반환받는 문자열 배열
*/
void MyDataParser::SeparateString(const FString& String, TArray<FString>& Result)
{
	String.ParseIntoArray(Result, TEXT("\t"));
}
