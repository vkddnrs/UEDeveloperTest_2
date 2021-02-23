// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Turtle.h"
#include "Turtle_1.generated.h"

/**
 * 
 */
UCLASS()
class TEST_2_API ATurtle_1 : public ATurtle
{
	GENERATED_BODY()

	public:
		UFUNCTION(BlueprintCallable, Category = "Move")
		void MoveToAimPoint() override;
	
};
