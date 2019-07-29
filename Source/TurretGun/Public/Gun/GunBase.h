// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunInterface.h"
#include "BulletBase.h"
#include "GunBase.generated.h"

/**
* Basic Turret Gun
* This gun is placed on the turret
*/

UCLASS(BlueprintType)
class TURRETGUN_API AGunBase : public AActor, public IGunInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Mesh for the gun
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
		UStaticMeshComponent* GunMesh;

	//Class reference for the bullets this gun shoots
	UPROPERTY(EditAnywhere, Category = Bullets)
		TSubclassOf<class ABulletBase> BulletType = ABulletBase::StaticClass();

};
