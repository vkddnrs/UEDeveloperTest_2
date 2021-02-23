// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "VectorField/VectorField.h"

#include "Turtle.generated.h"

UCLASS()
class TEST_2_API ATurtle : public APawn
// ������������ �� �����, � �� �� ������ ��� ������������� - ����� �����������  ��� � ����� �����
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

	FVector direction;

public:
	// ��� ���������� � ��������� �� ������� ���� ������� ���������� � ���������� ������������������ ����� �� ������
	// ���� �� �������, ������. �������� ����� �������� ����� � ��������� �� �� ��������� ������� � ��������.
	UPROPERTY(EditAnywhere, Category = "Building")
	AActor* SpawnPointActor;

	UPROPERTY(EditAnywhere, Category = "Building")
	AActor* AimPointActor;
	
};
