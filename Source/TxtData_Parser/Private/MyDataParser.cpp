// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDataParser.h"

MyDataParser::MyDataParser()
{
}

MyDataParser::~MyDataParser()
{
}
/*
* ���ڿ� �迭�� ��� �����͸� ������ \t�� �������� �ϳ��� ���ڿ��� ������ �ؽ�Ʈ���Ͽ� �����մϴ�
* @param FilePath - ���ڿ� �����͸� ������ ������ ���
* @param InData - �� �����͵��� ����ִ� �б����� �迭 ���۷���
*/
void MyDataParser::SaveTextData(const FString& FilePath, const TArray<FString>& InData)
{
	FFileHelper::SaveStringToFile(CombineData(InData), *FilePath);
}

/*
* Col, Row�� ������ ���̺� �������� �����͸� ���ڿ��� �����մϴ�.
* �� Col �� �����͵��� \t�� �������� �����մϴ�
* @param FilePath - ���ڿ� �����͸� ������ ������ ���
* @param InCol - ������ ���̺� ����� Col ����� ����ִ� �б����� �迭
* @param InRow - ������ ���̺� ����� Row ����� ����ִ� �б����� �迭
* @param InData - ���̺� ����� �����͸� ����ִ� �б����� 2���� �迭
*/
void MyDataParser::SaveTextData(const FString& FilePath, const TArray<FString>& InCol, const TArray<FString>& InRow, const TArray<TArray<FString>>& InData)
{
	//�ؽ�Ʈ ���Ͽ� ����� ��ü ���ڿ��� ���� �迭
	//Elem�� �ؽ�Ʈ ���Ͽ� ����� ���� 1���� ����
	TArray<FString> WholeStringData;
	WholeStringData.SetNum(InRow.Num() + 1);	//Col�� ������ �ٰ� Row������ŭ �뷮�� �Ҵ�
	WholeStringData[0] = TEXT("\t");
	WholeStringData[0] += CombineData(InCol);	//Col�� ������ ���ڿ� ������ ����
	for (int i = 0; i < InRow.Num(); ++i)
	{
		WholeStringData[i + 1] = InRow[i];		//Row�̸����� ����
		WholeStringData[i + 1] += "\t";			//������ �߰�
		//Row�� �̸����� Data�� �������� ���� ��� ��� �����͸� "NULL" ���ڿ��� ä��
		if (i >= InData.Num())
		{
			WholeStringData[i + 1] += GetNullString(InCol.Num());
		}
		else
		{
			WholeStringData[i + 1] += CombineData(InData[i]);
		}
	}
	FFileHelper::SaveStringArrayToFile(WholeStringData, *FilePath);	//Elem�� ���پ� �ؽ�Ʈ���Ͽ� ����
}

/*
* �迭�� ��� �� ���ڿ����� \t�� �����ϴ� �ϳ��� ���ڿ��� �����Ͽ� ��ȯ�մϴ�
* @param InDataArr - ���� ����� �Ǵ� �����͵��� ����ִ� �б����� �迭
* @return Result - �����͵��� ���յ� �ϳ��� ���ڿ�
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
* �ϳ��� ���ڿ� �����͸� Num�� ��ŭ �̾�ٿ� �ϳ��� ���ڿ��� �����մϴ�.
* @param Elem - ������ ����̵� ���ڿ� ������
* @param Num - ������ ����
* @return Result - Elem�� Num�� �ݺ��Ǿ� ���յ� ���ڿ� ���
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
* Ư�� ������ "NULL" ���ڿ��� ���յ� �ϳ��� ���ڿ��� ��ȯ�մϴ�
* @param ColNum - "NULL"�� �ݺ��� Ƚ��
* @return - "NULL"�� ColNum�� ��ŭ �ݺ��Ǿ� ���յ� ���ڿ� ���
*/
FString MyDataParser::GetNullString(int ColNum)
{
	return CombineData(TEXT("NULL"), ColNum);
}

/*
* �Ϸķ� ����� �ܼ� �����͸� �о�鿩 �����ڸ� �����ϴ� �۾��� ���� �迭�� ����ϴ�.
* @param FilePath - �����Ͱ� ����ִ� ���� ���
* @param Result - ����� ��ȯ�޴� ���ڿ� �迭
*/
void MyDataParser::LoadTextData(const FString& FilePath, TArray<FString>& Result)
{
	FString LoadedData;
	FFileHelper::LoadFileToString(LoadedData, *FilePath);
	SeparateString(LoadedData, Result);
}

/*
* ���̺� �������� ����� �����͸� �о�鿩 2���� �迭�� ����ϴ�.
* @param FilePath - ���̺� �����Ͱ� ����ִ� ���� ���
* @param Result - ����� ��ȯ�޴� 2���� ���ڿ� �迭
*/
void MyDataParser::LoadTextData(const FString& FilePath, TArray<TArray<FString>>& Result)
{
	TArray<FString> LineArray;	//������ �� ���� �����ϱ� ���� �ӽ� ���ڿ� �迭
	FFileHelper::LoadFileToStringArray(LineArray, *FilePath);	//������ ���� ���پ� LineArray�� ����
	Result.SetNum(LineArray.Num() - 1);//��ȯ �޴� �迭�� ũ�⸦ ����
	for (int i = 0; i < LineArray.Num() - 1; ++i)
	{
		SeparateString(LineArray[i+1], Result[i]);
	}
}

/*
* ���ڿ����� �����ڸ� �����ϴ� �۾��� ���� ���ڿ� �迭�� ��ȯ�մϴ�.
* @param String - ���յǾ� �ִ� �ϳ��� ���ڿ�
* @param Result - �����ڸ� ������ ����� ��ȯ�޴� ���ڿ� �迭
*/
void MyDataParser::SeparateString(const FString& String, TArray<FString>& Result)
{
	String.ParseIntoArray(Result, TEXT("\t"));
}
