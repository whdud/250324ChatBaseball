// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyTestCPPLib.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLECHAT_API UMyTestCPPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
    // 랜덤 정답 생성 함수
    UFUNCTION(BlueprintCallable, Category = "Baseball")
    static FString GenerateRandomAnswer();

    // 스트라이크(S), 볼(B) 계산 함수
    UFUNCTION(BlueprintCallable, Category = "Baseball")
    static FString CalculateSB(const FString& Input, const FString& Answer);
	
};
