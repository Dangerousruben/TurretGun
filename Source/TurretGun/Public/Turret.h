// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Turret.generated.h"

/**
* Turret that consists of a turret stand mesh, a rotator mesh that can rotate and attached to that a Gun actor
* Also has a camera and is possessed by the player
*/

UCLASS()
class TURRETGUN_API ATurret : public APawn
{
	GENERATED_BODY()

	friend class ATurretController;

public:
	// Sets default values for this pawn's properties
	ATurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	//Base of the turret
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
		UStaticMeshComponent* TurretStandMesh;

	//Attached to base, used for rotating
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
		UStaticMeshComponent* TurretRotatorMesh;

	//Gun actor attached to RotatorMesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
		UChildActorComponent* TurretGun;

	//Spring arm for camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
		class USpringArmComponent* SpringArm;

	//Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
		class UCameraComponent* Camera;


private:

	//Called when shoot action is pressed
	//Calls IGunInterface::StartShooting
	void PressShoot();

	//Called when shoot action is released
	//Calls IGunInterface::StopShooting
	void ReleaseShoot();

	//Rotates the rotator mesh to a location
	void RotateGun(FVector a_RotateTo, float a_DeltaTime);
};
