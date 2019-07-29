// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcBulletBase.h"

// Called every frame
void AArcBulletBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalOffset(FVector(200.0f, FMath::Cos(GetGameTimeSinceCreation() * 3) * 1000, 0.0f) * DeltaTime);
}