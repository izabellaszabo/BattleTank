// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
class UTankAimingComponent;

/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimingCompRef);

private:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

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
