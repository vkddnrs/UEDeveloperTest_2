// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "VectorField/VectorField.h"

#include "Turtle.generated.h"

UCLASS()
class TEST_2_API ATurtle : public APawn
// наследовался от Павна, а не от Актора для перестраховки - вдруг понадобятся  еще и фишки Павна
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATurtle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// sound
	USoundCue* SoundMovingStep_1;
	USoundCue* SoundMovingStep_2;
	USoundCue* SoundCueFX;
	USoundCue* SoundCueAmbience; // replace to GameMode

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	virtual void MoveToAimPoint();

	UFUNCTION(BlueprintCallable, Category = "SetUp")
	void SetUp(AActor* spawn_point, AActor* aim_point);
	

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

	UPROPERTY(EditAnywhere, Category = "Sound")
	float VolumeFX;

	UPROPERTY(EditAnywhere, Category = "Sound")
	float VolumeAmbience; // replace to GameMode

	FVector direction;

	UAudioComponent* AudioPlayerMovingStep_1;
	UAudioComponent* AudioPlayerMovingStep_2;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Sound/Building")
	TAssetPtr<USoundCue> SoundMovingPtr_1;
	
	UPROPERTY(EditDefaultsOnly, Category = "Sound/Building")
	TAssetPtr<USoundCue> SoundMovingPtr_2;

	

public:
	// Эти переменные к сожалению не удалось пока сделать способными в блюпринтах инициализироваться прямо из уровня
	// пока не понимаю, почему. Пришлось пойти обходным путем и назначать их из блюпринта виджета с кнопками.
	UPROPERTY(EditAnywhere, Category = "Building")
	AActor* SpawnPointActor;

	UPROPERTY(EditAnywhere, Category = "Building")
	AActor* AimPointActor;
	
};
