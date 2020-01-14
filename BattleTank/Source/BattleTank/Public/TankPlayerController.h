// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(OUT FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, OUT FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, OUT FVector& OutHitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairLocationX = 0.5f;
	UPROPERTY(EditDefaultsOnly)
	float CrosshairLocationY = 0.33333f;
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000; // 10km
};
