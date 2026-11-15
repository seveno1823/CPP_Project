// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	FVector MovingDirction = BallVelocity.GetSafeNormal();
	FVector EndLocation = StartLocation + MovingDirction * MoveDistance;
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bWaiting)
	{
		WaitTimer += DeltaTime;
		if (WaitTimer >= WaitTime)
		{
			bWaiting = false;
			WaitTimer = 0.0f;
		}
		return; 
	}

	FVector CurrentLoacation = GetActorLocation();

	DistanceMoved = FVector::Dist(StartLocation, CurrentLoacation);
	float Progress = FMath::Clamp(DistanceMoved / MoveDistance, 0.0f, 1.0f);  //计算走了百分多少，便于速度控制

	SpeedFactor = 1.0f - SlowFactor * FMath::Sin(Progress * PI);  //用1-a*sinx这个函数控制速度变化（两头快中间慢）

	FVector NewLocation = CurrentLoacation + BallVelocity * SpeedFactor * DeltaTime;
	if (FVector::Dist(StartLocation, NewLocation) >= MoveDistance)
	{
		FVector MovingDirction = BallVelocity.GetSafeNormal();
		FVector NewStartLocation = StartLocation + MovingDirction * MoveDistance;
		SetActorLocation(NewStartLocation);
		StartLocation = NewStartLocation;
		bWaiting = true;
		WaitTimer = 0.0f;
		BallVelocity = -BallVelocity;
	}

	else
	{
		SetActorLocation(NewLocation);
	}
}

