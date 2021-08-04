// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ShooterCharacter.h"
#include "Animation/AnimInstance.h"
#include "ShooterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UShooterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	public:
	
	UFUNCTION(BlueprintCallable)
	void UpdateAnimationProperties(float DeltaTime);

	virtual void NativeInitializeAnimation() override;

	private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Movement, meta=(AllowPrivateAccess="true"))
	class AShooterCharacter* ShooterCharacter;

	/*The speed of the character*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Movement, meta=(AllowPrivateAccess="true"))
	float Speed;

	/*Check whether or not the character is in the air*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Movement, meta=(AllowPrivateAccess="true"))
	bool bIsInAir;

	/*Check whether the character is accelerating*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Movement, meta=(AllowPrivateAccess="true"))
	bool bIsAccelerating;
};
