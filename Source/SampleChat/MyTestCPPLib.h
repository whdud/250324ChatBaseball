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
    // ���� ���� ���� �Լ�
    UFUNCTION(BlueprintCallable, Category = "Baseball")
    static FString GenerateRandomAnswer();

    // ��Ʈ����ũ(S), ��(B) ��� �Լ�
    UFUNCTION(BlueprintCallable, Category = "Baseball")
    static FString CalculateSB(const FString& Input, const FString& Answer);
	
};
