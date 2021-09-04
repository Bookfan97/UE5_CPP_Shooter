// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
	public:
		AShooterPlayerController();
	protected:
		virtual void BeginPlay() override;
	private:
		/*Reference to the HUD overlay blueprint class*/
		UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
			TSubclassOf<class UUserWidget> HUDOverlayClass;

		/*Variable to hold the overlay widget after creation*/
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widgets", meta = (AllowPrivateAccess = "true"))
			UUserWidget* HUDOverlay;
};
