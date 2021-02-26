// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Turtle.h"
#include "Turtle_2.generated.h"

/**
 * 
 */
UCLASS()
class TEST_2_API ATurtle_2 : public ATurtle
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable, Category = "Move")
	void MoveToAimPoint() override;

protected:
	void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category="Time")
	float TimeMove = 1.0;

	UPROPERTY(EditAnywhere, Category = "Time")
	float TimePass = 0.5;

	bool is_pause = false;

private:
	float time = 0.0;
};
