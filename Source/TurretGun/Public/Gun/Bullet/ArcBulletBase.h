// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gun/Bullet/BulletBase.h"
#include "ArcBulletBase.generated.h"

/**
 * Bullet that moves in a cosine wave
 */
UCLASS()
class TURRETGUN_API AArcBulletBase : public ABulletBase
{
	GENERATED_BODY()
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime);
};
