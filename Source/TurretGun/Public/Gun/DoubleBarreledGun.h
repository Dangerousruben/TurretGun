// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gun/GunBase.h"
#include "DoubleBarreledGun.generated.h"

/**
 * Turret gun with two barrels
 */
UCLASS()
class TURRETGUN_API ADoubleBarreledGun : public AGunBase
{
	GENERATED_BODY()
	
protected:

	//Fires the gun once
	UFUNCTION(BlueprintNativeEvent)
		void StartShooting(APawn* Shooter);
		void StartShooting_Implementation(APawn* Shooter) override;

	
	//Muzzle socket name for the left barrel
	UPROPERTY(EditDefaultsOnly, Category = Shooting)
		FName LeftMuzzleSocket = "LeftMuzzle";

	//Muzzle socket name for the right barrel
	UPROPERTY(EditDefaultsOnly, Category = Shooting)
		FName RightMuzzleSocket = "RightMuzzle";
};
