// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Engine/World.h"
#include "Components/BoxComponent.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root;

	spawnArea = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawn Area"));
	spawnArea->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
	if (randomizeSeed)
	{
		randomStream.GenerateNewSeed();
	}
	else
	{
		randomStream = FRandomStream(seed);
	}
}

void AEnemySpawner::SpawnEnemy()
{
	float forwardExtent = randomStream.FRandRange(spawnArea->GetUnscaledBoxExtent().X*-1, spawnArea->GetUnscaledBoxExtent().X);
	float rightExtent = randomStream.FRandRange(spawnArea->GetUnscaledBoxExtent().Y*-1, spawnArea->GetUnscaledBoxExtent().Y);

	AEnemy* tempptr = GetWorld()->SpawnActor<AEnemy>(standardEnemy, FTransform(GetActorRotation(), 
		FVector(GetActorLocation().X + forwardExtent, GetActorLocation().Y + rightExtent, GetActorLocation().Z), FVector(1.0f, 1.0f, 1.0f)));
	tempptr->SpawnDefaultController();
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	{
		currentSpawnTimer -= DeltaTime;

		if (currentSpawnTimer <= 0.0f)
		{
			SpawnEnemy();
			currentSpawnTimer = 3.0f;
		}
	}
}

