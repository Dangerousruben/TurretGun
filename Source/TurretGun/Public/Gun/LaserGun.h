// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gun/GunBase.h"
#include "LaserGun.generated.h"

/**
 * This gun shoots a laser if StartShooting is called and stops when StopShooting is called
 */
UCLASS()
class TURRETGUN_API ALaserGun : public AGunBase
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

protected:
	//Sets boolean to true so firing starts
	UFUNCTION(BlueprintNativeEvent)
		void StartShooting(APawn* Shooter);
		void StartShooting_Implementation(APawn* Shooter) override;

	//Sets boolean to false so firing starts
	UFUNCTION(BlueprintNativeEvent)
		void StopShooting();
		void StopShooting_Implementation() override;

	//Muzzle socket name for the barrel
	UPROPERTY(EditDefaultsOnly, Category = Shooting)
		FName MuzzleSocket = "Muzzle";

	//Range of the laser
	UPROPERTY(EditDefaultsOnly, Category = Shooting)
		float Range = 2000.0f;

	//Damage dealt when hitting another object
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float Damage = 1.0f;

private:

	//Boolean that if set to true starts firing
	bool IsFiring = false;
};
