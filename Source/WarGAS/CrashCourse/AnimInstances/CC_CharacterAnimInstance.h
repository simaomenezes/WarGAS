// War GAS - SIMAO

#pragma once

#include "CoreMinimal.h"
#include "CC_BaseAnimInstance.h"
#include "WarGAS/CrashCourse/Characters/CC_BaseCharacter.h"
#include "CC_CharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class WARGAS_API UCC_CharacterAnimInstance : public UCC_BaseAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	UPROPERTY()
	ACC_BaseCharacter* OwningCharacter;
	
	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float GroundSpeed;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAcceleration;
};
