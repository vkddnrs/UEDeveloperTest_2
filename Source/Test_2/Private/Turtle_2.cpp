// Fill out your copyright notice in the Description page of Project Settings.


#include "Turtle_2.h"

void ATurtle_2::MoveToAimPoint()
{
	Super::MoveToAimPoint();	
}

void ATurtle_2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!IsFinish && !is_pause)
		MoveToAimPoint();

	time += DeltaTime;
	
	if (!is_pause && time >= TimeMove)
	{
		is_pause = true;
		time = 0.0;
	}
	
	if (is_pause && time >= TimePass)
	{
		is_pause = false;
		time = 0.0;
	}
}