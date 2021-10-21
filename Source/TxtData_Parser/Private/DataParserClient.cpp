// Fill out your copyright notice in the Description page of Project Settings.


#include "DataParserClient.h"
#include "MyDataParser.h"
// Sets default values for this component's properties
UDataParserClient::UDataParserClient()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UDataParserClient::BeginPlay()
{
	Super::BeginPlay();
	MyDataParser DataParser;
	FString TestFilePath;
	TArray<FString> TestCol;
	TArray<FString> TestRow;
	TArray<TArray<FString>> TestData;
	TArray<TArray<FString>> TestLoadedData;
	TestFilePath = FPaths::ProjectDir();
	TestFilePath += "/test_data.txt";

	TestCol.Add(TEXT("ATK"));
	TestCol.Add(TEXT("DFN"));

	TestRow.Add(TEXT("archor"));
	TestRow.Add(TEXT("sword"));
	
	TestData.Add(TArray<FString>({ "1", "2" }));

	//DataParser.SaveTextData(TestFilePath, TestCol, TestRow, TestData);
	DataParser.LoadTextData(TestFilePath, TestLoadedData);
	for (int i = 0; i < TestLoadedData.Num(); ++i)
	{
		for (FString data : TestLoadedData[i])
		{
			UE_LOG(LogTemp, Log, TEXT("%s"), *data);
		}
	}
}

//// Called every frame
//void UDataParserClient::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//	// ...
//}

