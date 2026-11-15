// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class CPP_PROJECT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FVector BallVelocity = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere)
	float MoveDistance = 100.0f;

	UPROPERTY(EditAnywhere)
	float WaitTime = 0.0f;

	UPROPERTY(EditAnywhere)
	float SlowFactor = 0.0f;  //中间慢的程度

	UPROPERTY(VisibleAnywhere)
	float DistanceMoved = 0.0f;

	UPROPERTY(VisibleAnywhere)
	float WaitTimer = 0.0f;

	UPROPERTY(VisibleAnywhere)
	float SpeedFactor = 0.0f;

	FVector StartLocation;
	bool bWaiting = false;

};
