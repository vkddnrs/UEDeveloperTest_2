// Fill out your copyright notice in the Description page of Project Settings.


#include "Turtle_1.h"

void ATurtle_1::BeginPlay()
{
	Super::BeginPlay();
	//// set sound system 
	//SoundMovingStep_1 = SoundMovingPtr_1.Get();
	//if(!SoundMovingStep_1)
	//{
	//	const FSoftObjectPath& AssetRef = SoundMovingPtr_1.ToStringReference();
	//	SoundMovingStep_1 = LoadObject<USoundCue>(nullptr, *AssetRef.GetAssetPathString());		
	//}
	//SoundMovingStep_2 = SoundMovingPtr_2.Get();
	//if (!SoundMovingStep_2)
	//{
	//	const FSoftObjectPath& AssetRef = SoundMovingPtr_2.ToStringReference();
	//	SoundMovingStep_2 = LoadObject<USoundCue>(nullptr, *AssetRef.GetAssetPathString());
	//}
	//if (SoundMovingStep_1 && SoundMovingStep_2)
	//{
	//	AudioPlayerMovingStep_1 = UGameplayStatics::SpawnSound2D(this, SoundMovingStep_1);
	//	AudioPlayerMovingStep_2 = UGameplayStatics::SpawnSound2D(this, SoundMovingStep_2);
	//	AudioPlayerMovingStep_1->VolumeMultiplier = VolumeMoving;
	//	AudioPlayerMovingStep_2->VolumeMultiplier = VolumeMoving;
	//	AudioPlayerMovingStep_1->OnAudioFinished.AddDynamic(this, &ATurtle_1::SoundStepFinished_1);
	//	AudioPlayerMovingStep_2->OnAudioFinished.AddDynamic(this, &ATurtle_1::SoundStepFinished_2);

	//	AudioPlayerMovingStep_1->Activate(true);
	//}
}


void ATurtle_1::MoveToAimPoint()
{
	Super::MoveToAimPoint();
	//Mesh->AddWorldOffset(direction * Speed);
}

