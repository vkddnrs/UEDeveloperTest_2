// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "VectorField/VectorField.h"

#include "Turtle.generated.h"

UCLASS()
class TEST_2_API ATurtle : public AActor

{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATurtle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	virtual void MoveToAimPoint();

	UFUNCTION(BlueprintCallable, Category = "SetUp")
	void SetUp(AActor* spawn_point, AActor* aim_point);

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:	
	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(EditAnywhere, Category = "Points")
	FVector SpawnPoint;

	UPROPERTY(EditAnywhere, Category = "Points")
	FVector AimPoint;

	UPROPERTY(EditAnywhere, Category = "Move")
	float Speed = 0.5;

	UPROPERTY(BlueprintReadWrite, Category = "Move")
	bool IsFinish = false;

	UPROPERTY(EditAnywhere, Category = "Sound")
	float VolumeMoving;

	FVector direction;

	USoundCue* SoundMoving;
	UAudioComponent* AudioPlayerMoving;

	AActor* FXSpawn;
	AActor* FXDisappearance;
	

public:
	UPROPERTY(EditDefaultsOnly, Category = "Sound/Building")
	TAssetPtr<USoundCue> SoundMovingPtr;

	UPROPERTY(EditDefaultsOnly, Category = "Building")
	TAssetPtr<AActor> SpawnPointActorPtr;

	UPROPERTY(EditDefaultsOnly, Category = "Building")
	TAssetPtr<AActor> AimPointActorPtr;	
	
};
