// Fill out your copyright notice in the Description page of Project Settings.


#include "Turtle.h"

#include "Kismet/GameplayStatics.h"


// Sets default values
ATurtle::ATurtle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

}

// Called when the game starts or when spawned
void ATurtle::BeginPlay()
{
	Super::BeginPlay();

	static;
	SoundMovingStep_1 = SoundMovingPtr_1.Get();
	SoundMovingStep_2 = SoundMovingPtr_2.Get();
	AudioPlayerMovingStep_1 = UGameplayStatics::SpawnSound2D(this, SoundMovingStep_1);
	AudioPlayerMovingStep_2 = UGameplayStatics::SpawnSound2D(this, SoundMovingStep_2);
	AudioPlayerMovingStep_1->Activate(true);

	
	
}

// Called every frame
void ATurtle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!IsFinish)
		MoveToAimPoint();

}

// Called to bind functionality to input
void ATurtle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATurtle::MoveToAimPoint()
{
	Mesh->AddWorldOffset(direction * Speed);
}

void ATurtle::SetUp(AActor* spawn_point, AActor* aim_point)
{
	if (AimPointActor == nullptr)
		AimPointActor = aim_point;

	if (SpawnPointActor == nullptr)
		SpawnPointActor = spawn_point;
	
	if (AimPointActor != nullptr)
		AimPoint = AimPointActor->GetActorLocation();

	if (SpawnPointActor != nullptr)
		SpawnPoint = SpawnPointActor->GetActorLocation();
	
	direction = AimPoint - SpawnPoint;
	direction = direction.GetSafeNormal2D();
	FVector forward_vector = Mesh->GetForwardVector();
	FQuat bq = FQuat::FindBetweenVectors(forward_vector, direction);
	float angle;
	FVector axis;
	bq.ToAxisAndAngle(axis, angle);
	angle = FMath::RadiansToDegrees(angle);
	FRotator rotator = forward_vector.RotateAngleAxis(angle, axis).Rotation();
	Mesh->SetWorldLocationAndRotation(SpawnPoint, rotator);

}
