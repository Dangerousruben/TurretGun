// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.h"
#include "Math/RandomStream.h"
#include "EnemySpawner.generated.h"

UCLASS()
class TURRETGUN_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

private:

	float currentSpawnTimer = 0.0f;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class USceneComponent* root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UBoxComponent* spawnArea;

	UPROPERTY(EditAnywhere, Category = "Enemy")
		TSubclassOf<AEnemy> standardEnemy;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SpawnEnemy();

	UPROPERTY(EditAnywhere, Category = "RNG")
		bool randomizeSeed = true;

	UPROPERTY(EditAnywhere, Category = "RNG")
		int32 seed = 0;

	FRandomStream randomStream;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
