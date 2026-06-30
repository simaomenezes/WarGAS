// War GAS - SIMAO

#pragma once

#include "CoreMinimal.h"
#include "WarGAS/TPActionRPG/AnimInstances/WarriorCharacterAnimInstance.h"
#include "WarriorHeroAnimInstance.generated.h"

class AWarriorHeroCharacter;
/**
 * 
 */
UCLASS()
class WARGAS_API UWarriorHeroAnimInstance : public UWarriorCharacterAnimInstance
{
	GENERATED_BODY()
	
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds);

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Warrior|AnimData|Refrences")
	AWarriorHeroCharacter* OwningHeroCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Warrior|AnimData|LocomotionData")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Warrior|AnimData|LocomotionData")
	float EnterRelaxtStateThreshold = 5.f;

	float IdleElpasedTime;
};
