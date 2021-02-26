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

	// set sound system 
	SoundMoving = SoundMovingPtr.Get();
	if (!SoundMoving)
	{
		const FSoftObjectPath& AssetRef = SoundMovingPtr.ToSoftObjectPath();
		SoundMoving = LoadObject<USoundCue>(nullptr, *AssetRef.GetAssetPathString());
	}

	if (SoundMoving)
	{
		AudioPlayerMoving = UGameplayStatics::SpawnSound2D(this, SoundMoving);
		AudioPlayerMoving->VolumeMultiplier = VolumeMoving;
		AudioPlayerMoving->Activate(true);		
	}
	else
		UE_LOG(LogAudio, Error, TEXT("SoundCue is don`t loaded"));
	

	// Spawn/Aim Points
	AActor* SpawnPointActor = SpawnPointActorPtr.Get();
	if (!SpawnPointActor)
	{
		const FSoftObjectPath& AssetRef = SpawnPointActorPtr.ToSoftObjectPath();
		SpawnPointActor = LoadObject<AActor>(nullptr, *AssetRef.GetAssetPathString());
		SpawnPoint = SpawnPointActor->GetActorLocation();
	}

	AActor* AimPointActor = AimPointActorPtr.Get();
	if (!AimPointActor)
	{
		const FSoftObjectPath& AssetRef = AimPointActorPtr.ToSoftObjectPath();
		AimPointActor = LoadObject<AActor>(nullptr, *AssetRef.GetAssetPathString());
		AimPoint = AimPointActor->GetActorLocation();
	}

	if(AimPointActor && SpawnPointActor)
		SetUp(nullptr, nullptr);	
}



// Called every frame
void ATurtle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!IsFinish)
		MoveToAimPoint();
}


void ATurtle::MoveToAimPoint()
{
	AddActorWorldOffset(direction * Speed);
}

void ATurtle::SetUp(AActor* spawn_point = nullptr, AActor* aim_point = nullptr)
{
	if (spawn_point)
		AimPoint = aim_point->GetActorLocation();

	if (aim_point)
		SpawnPoint = spawn_point->GetActorLocation();
	
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

void ATurtle::EndPlay(const EEndPlayReason::Type EndPlayReason)
{	
	Super::EndPlay(EndPlayReason);

	if(AudioPlayerMoving)
		AudioPlayerMoving->Stop();	
}
