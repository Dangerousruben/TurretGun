// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gun/GunBase.h"
#include "StandardGun.generated.h"

/**
 * Standard turret gun with 1 barrel
 */
UCLASS()
class TURRETGUN_API AStandardGun : public AGunBase
{
	GENERATED_BODY()

protected:
	//Fires the gun once
	UFUNCTION(BlueprintNativeEvent)
		void StartShooting(APawn* Shooter);
		void StartShooting_Implementation(APawn* Shooter) override;

	//Muzzle socket name for the barrel
	UPROPERTY(EditDefaultsOnly, Category = Shooting)
		FName MuzzleSocket = "Muzzle";
};
