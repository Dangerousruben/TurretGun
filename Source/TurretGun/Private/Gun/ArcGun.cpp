// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcGun.h"
#include "ArcBulletBase.h"

AArcGun::AArcGun()
{
	BulletType = AArcBulletBase::StaticClass();
}
