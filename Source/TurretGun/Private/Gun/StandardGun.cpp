// Fill out your copyright notice in the Description page of Project Settings.


#include "StandardGun.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

//Fires the gun once
void AStandardGun::StartShooting_Implementation(APawn * Shooter)
{
	if (BulletType && GunMesh->DoesSocketExist(MuzzleSocket))
	{
		ABulletBase* tempptr = GetWorld()->SpawnActor<ABulletBase>(BulletType, FTransform(GetActorRotation(), GunMesh->GetSocketLocation(MuzzleSocket), FVector(1.0f, 1.0f, 1.0f)));
		tempptr->BulletMesh->IgnoreActorWhenMoving(this, true);
		if (Shooter)
		{
			tempptr->SetInstigator(Shooter);
		}
	}
}
