// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretController.h"
#include "Turret.h"

	// Called every frame
void ATurretController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Rotating the Turrets Gun
	{
		FHitResult hitResult;
		if (GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), true, hitResult))
		{
			if (Cast<ATurret>(GetPawn()))
			Cast<ATurret>(GetPawn())->RotateGun(hitResult.Location, DeltaTime);
		}
	}
}