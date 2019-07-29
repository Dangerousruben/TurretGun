// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include "GunBase.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "Components/ChildActorComponent.h"
#include "Components/InputComponent.h"
#include "TurretController.h"

// Sets default values
ATurret::ATurret()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TurretStandMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Stand Mesh"));
	RootComponent = TurretStandMesh;

	TurretRotatorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rotator Mesh"));
	TurretRotatorMesh->AttachToComponent(TurretStandMesh, FAttachmentTransformRules::KeepRelativeTransform);

	TurretGun = CreateDefaultSubobject<UChildActorComponent>(TEXT("Gun"));
	TurretGun->AttachToComponent(TurretRotatorMesh, FAttachmentTransformRules::KeepRelativeTransform);
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->AttachToComponent(TurretStandMesh, FAttachmentTransformRules::KeepRelativeTransform);
	SpringArm->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 1500.0f;
	SpringArm->bDoCollisionTest = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->AttachToComponent(SpringArm, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATurret::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Shoot", IE_Pressed, this, &ATurret::PressShoot);
	InputComponent->BindAction("Shoot", IE_Released, this, &ATurret::ReleaseShoot);
}

//Called when shoot action is pressed
//Calls IGunInterface::StartShooting
void ATurret::PressShoot()
{
	IGunInterface* gunInterface = Cast<IGunInterface>(TurretGun->GetChildActor());
	if (gunInterface)
	{
		gunInterface->Execute_StartShooting(TurretGun->GetChildActor(), this);
	}
}

//Called when shoot action is released
//Calls IGunInterface::StopShooting
void ATurret::ReleaseShoot()
{
	IGunInterface* gunInterface = Cast<IGunInterface>(TurretGun->GetChildActor());
	if (gunInterface)
	{
		gunInterface->Execute_StopShooting(TurretGun->GetChildActor());
	}
}

//Rotates the rotator mesh to a location
void ATurret::RotateGun(FVector a_RotateTo, float a_DeltaTime)
{
	FRotator currentRotation = TurretRotatorMesh->GetComponentRotation();
	FVector direction = a_RotateTo - TurretRotatorMesh->GetComponentLocation();
	direction.Normalize();
	FRotator newRotation = FRotator(currentRotation.Pitch, FRotationMatrix::MakeFromX(direction).Rotator().Yaw, currentRotation.Roll);
	TurretRotatorMesh->SetWorldRotation(FMath::RInterpTo(currentRotation, newRotation, a_DeltaTime, 3.0f));
}

