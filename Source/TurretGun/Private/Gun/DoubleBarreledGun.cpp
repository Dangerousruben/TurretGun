// Fill out your copyright notice in the Description page of Project Settings.


#include "DoubleBarreledGun.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

	//Fires the gun once
void ADoubleBarreledGun::StartShooting_Implementation(APawn * Shooter)
{
	if (BulletType && (GunMesh->DoesSocketExist(LeftMuzzleSocket) && GunMesh->DoesSocketExist(RightMuzzleSocket)))
	{
		//Left Bullet
		ABulletBase* tempptr = GetWorld()->SpawnActor<ABulletBase>(BulletType, FTransform(GetActorRotation(), GunMesh->GetSocketLocation(LeftMuzzleSocket), FVector(1.0f, 1.0f, 1.0f)));
		tempptr->BulletMesh->IgnoreActorWhenMoving(this, true);
		if (Shooter)
			tempptr->Instigator = Shooter;

		//Right Bullet
		tempptr = GetWorld()->SpawnActor<ABulletBase>(BulletType, FTransform(GetActorRotation(), GunMesh->GetSocketLocation(RightMuzzleSocket), FVector(1.0f, 1.0f, 1.0f)));
		tempptr->BulletMesh->IgnoreActorWhenMoving(this, true);
		if (Shooter)
			tempptr->Instigator = Shooter;
	}
}
