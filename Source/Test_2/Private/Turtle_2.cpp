// Fill out your copyright notice in the Description page of Project Settings.


#include "Turtle_2.h"

void ATurtle_2::BeginPlay()
{
	Super::BeginPlay();
}


void ATurtle_2::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);
	if (IsFinish)
		return;
	
	if (!is_pause)	
		MoveToAimPoint();	

	time += DeltaTime;
	
	if (!is_pause && time >= TimeMove)
	{
		is_pause = true;
		if(SoundMovingPtr)
			AudioPlayerMoving->Activate(false);
		time = 0.0;
	}
	
	if (is_pause && time >= TimePass)
	{
		is_pause = false;
		if(SoundMovingPtr)
			AudioPlayerMoving->Activate(true);
		time = 0.0;
	}
}

void ATurtle_2::MoveToAimPoint()
{
	Super::MoveToAimPoint();
}