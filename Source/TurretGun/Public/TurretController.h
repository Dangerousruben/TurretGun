// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TurretController.generated.h"

/**
 * TurretController used to rotate the turret
 */
UCLASS()
class TURRETGUN_API ATurretController : public APlayerController
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
