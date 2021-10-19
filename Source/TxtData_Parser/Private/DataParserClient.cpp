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
	MyDataParser dataParser;
	FString TestFilePath;
	TArray<FString> TestData;
	TArray<FString> LoadedData;
	TestData.Add(TEXT("1"));
	TestData.Add(TEXT("4"));
	TestData.Add(TEXT("5"));

	TestFilePath = FPaths::ProjectDir();
	TestFilePath += "/test_data.txt";
	dataParser.SaveTextData(TestFilePath, TestData);
	dataParser.LoadTextData(TestFilePath, LoadedData);
	for (FString Data : LoadedData)
	{
		UE_LOG(LogTemp, Log, TEXT("%s"), *Data);
	}
}

//// Called every frame
//void UDataParserClient::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//	// ...
//}

