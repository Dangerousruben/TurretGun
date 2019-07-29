// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface.h"
#include "GunInterface.generated.h"

/**
 * The interface for the turret to interact with the gun
 */
UINTERFACE()
class TURRETGUN_API UGunInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()

};

class TURRETGUN_API IGunInterface
{
	GENERATED_IINTERFACE_BODY()

public:

	//Will shoot or start repeated shooting depending on the gun
	UFUNCTION(BlueprintNativeEvent)
		void StartShooting(APawn* Shooter);

	//Will stop shooting
	UFUNCTION(BlueprintNativeEvent)
		void StopShooting();

};