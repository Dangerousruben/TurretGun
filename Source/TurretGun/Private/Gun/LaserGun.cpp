// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserGun.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "DrawDebugHelpers.h"

//Sets boolean to true so firing starts
void ALaserGun::StartShooting_Implementation(APawn * Shooter)
{
	IsFiring = true;
}

//Sets boolean to false so firing stops
void ALaserGun::StopShooting_Implementation()
{
	IsFiring = false;
}


void ALaserGun::Tick(float DeltaTime)
{
	if (IsFiring)
	{
		FVector startLocation = GunMesh->GetSocketLocation(MuzzleSocket);
		FVector endLocation = startLocation + (GetActorForwardVector() * Range);
		FHitResult hitResult;
		if (GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, endLocation, ECollisionChannel::ECC_Visibility))
		{
			DrawDebugLine(GetWorld(), startLocation, hitResult.Location, FColor::Red, false, 0.01667f, 1, 10.0f);
			if (Cast<APawn>(GetAttachParentActor()))
			hitResult.Actor->TakeDamage(Damage * DeltaTime, FDamageEvent(), Cast<APawn>(GetAttachParentActor())->GetController(), this);
		}
		else
		{
			DrawDebugLine(GetWorld(), startLocation, endLocation, FColor::Red, false, 0.01667f, 1, 10.0f);
		}
	}
}