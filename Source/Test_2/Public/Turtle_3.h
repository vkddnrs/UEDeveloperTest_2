// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Turtle.h"
#include "Turtle_3.generated.h"

/**
 * 
 */
UCLASS()
class TEST_2_API ATurtle_3 : public ATurtle
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Move")
		void MoveToAimPoint() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Time")
		float TimeMove = 1.0;

	UPROPERTY(EditAnywhere, Category = "Time")
		float TimeInvesionMove = 0.5;

	bool is_inversion = false;

private:
	float time = 0.0;
};
