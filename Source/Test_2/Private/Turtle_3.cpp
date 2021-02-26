// Fill out your copyright notice in the Description page of Project Settings.


#include "Turtle_3.h"

void ATurtle_3::BeginPlay()
{
	Super::BeginPlay();
}

void ATurtle_3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!IsFinish)
		MoveToAimPoint();

	time += DeltaTime;

	if (!is_inversion && time >= TimeMove)
	{
		is_inversion = true;
		time = 0.0;
		Speed = -Speed;
	}

	if (is_inversion && time >= TimeInvesionMove)
	{
		is_inversion = false;
		time = 0.0;
		Speed = -Speed;
	}
}


void ATurtle_3::MoveToAimPoint()
{
	Super::MoveToAimPoint();
}