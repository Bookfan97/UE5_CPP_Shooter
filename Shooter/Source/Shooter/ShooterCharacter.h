// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"

#include "ShooterCharacter.generated.h"

UCLASS()
class SHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*Forwards/Backwards Input*/
	void MoveForward(float value);

	/*Left/Right Input*/
	void MoveRight(float value);

	/* Called via input to turn at a given rate
	 * @param Rate normalize rate
	 */
	void TurnAtRate(float rate);

	/* Called via input to look up/down at a given rate
	 * @param Rate normalize rate
	 */
	void LookUpAtRate(float rate);

	/* Rotate controller based on mouse X movement
	 * @param Value Input value for mouse movement
	 */
	void Turn(float value);

	/* Rotate controller based on mouse Y movement
	* @param Value Input value for mouse movement
	*/
	void LookUp(float value);
	
	/*Called when fire button is pressed*/
	void FireWeapon();

	/**/
	bool GetBeamEndLocation(const FVector& MuzzleSocketLocation, FVector& OutBeamLocation);

	/*Set bAiming to true or false*/
	void AimingButtonPressed();
	void AimingButtonReleased();
	void CameraInterpZoom(float DeltaTime);
	void SetLookRate();

	/**/
	void CalculateCrosshairSpread(float DeltaTime);

	/**/
	void StartCrosshairBulletFire();
	
	/**/
	UFUNCTION()
	void FinishCrosshairBulletFire();

	/**/
	void FireButtonPressed();

	/**/
	void FireButtonReleased();

	/**/
	void StartFireTimer();

	/**/
	UFUNCTION()
	void AutoFireReset();

	/*Line trace for items under the crosshairs*/
	bool TraceUnderCrosshairs(FHitResult& OutHitResult);
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	/*Camera boom positions camera behind the character*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* CameraBoom;

	/*Camera that follows the character*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* FollowCamera;

	/*Base turn rate in degrees/second */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		float BaseTurnRate;

	/*Base look up/down rate in degrees/second */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		float BaseLookUpRate;

	/*Base turn rate in degrees/second while not aiming*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		float HipTurnRate;

	/*Base look up/down rate in degrees/second while not aiming*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		float HipLookUpRate;

	/*Base turn rate in degrees/second while aiming*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		float AimTurnRate;

	/*Base look up/down rate in degrees/second while aiming*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		float AimLookUpRate;

	/*Base turn rate in degrees/second while not aiming*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"), meta = (ClampMin = "0.0"), meta = (ClampMax = "1.0"), meta = (UIMin = "0.0"), meta = (UIMax = "1.0"))
		float MouseHipTurnRate;

	/*Base look up/down rate in degrees/second while not aiming*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"), meta = (ClampMin = "0.0"), meta = (ClampMax = "1.0"), meta = (UIMin = "0.0"), meta = (UIMax = "1.0"))
		float MouseHipLookUpRate;

	/*Base turn rate in degrees/second while aiming*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"), meta = (ClampMin = "0.0"), meta = (ClampMax = "1.0"), meta = (UIMin = "0.0"), meta = (UIMax = "1.0"))
		float MouseAimTurnRate;

	/*Base look up/down rate in degrees/second while aiming*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"), meta = (ClampMin = "0.0"), meta = (ClampMax = "1.0"), meta = (UIMin = "0.0"), meta = (UIMax = "1.0"))
		float MouseAimLookUpRate;

	/*Gun fire sound cue*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	class USoundCue* FireSound;

	/*Flash spawned at BarrelSocket*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	class UParticleSystem* MuzzleFlash;

	/*Montage for firing weapon*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	class UAnimMontage* HipFireMontage;

	/*Particles spawned on impact*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	UParticleSystem* ImpactParticles;

	/*Particles for Smoke Trail*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	UParticleSystem* BeamParticles;
	
	/*True when aiming*/
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess = "true"))
	bool bAiming;

	/*Default camera field of view value*/
	float CameraDefaultFOV;

	/*Zoomed camera field of view value*/
	float CameraZoomedFOV;
	
	/*Current Field of View for frame*/
	float CameraCurrentFOV;

	/*Interp speed for zooming and aiming*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	float ZoomInterpSpeed;

	/*Determines the spread of the crosshairs*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Crosshairs, meta = (AllowPrivateAccess = "true"))
	float CrosshairSpreadMultiplier;

	/*Velocity component for crosshair spread*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Crosshairs, meta = (AllowPrivateAccess = "true"))
	float CrosshairVelocityFactor;

	/*in air component for crosshair spread*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Crosshairs, meta = (AllowPrivateAccess = "true"))
	float CrosshairInAirFactor;

	/*Aim component for crosshair spread*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Crosshairs, meta = (AllowPrivateAccess = "true"))
	float CrosshairAimFactor;

	/*Shooting component for crosshair spread*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Crosshairs, meta = (AllowPrivateAccess = "true"))
	float CrosshairShootingFactor;

	float ShootTimeDuration;

	bool bFiringBullet;

	FTimerHandle CrosshairShootTimer;

	/*LMB or Right Console Trigger pressed*/
	bool bFireButtonPressed;

	/*True when player can fire, false when waiting for the timer*/
	bool bShouldFire;

	/*Rate of automatic fire*/
	float AutomaticFireRate;

	/*Sets a timer between gunshots*/
	FTimerHandle AutoFireTimer;

public:
	/*Returns camera boom subobject*/
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/*Returns follow camera subobject*/
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	/*Returns bAiming to be used in the anim instance*/
	FORCEINLINE bool GetAiming() const {return bAiming;}

	/*Returns bAiming to be used in the anim instance*/
	UFUNCTION(BlueprintCallable)
	float GetCrosshairSpreadMultiplier();
};