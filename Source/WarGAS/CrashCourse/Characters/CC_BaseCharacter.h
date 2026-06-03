// War GAS - SIMAO
#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "CC_BaseCharacter.generated.h"

class UGameplayAbility;

UCLASS()
class WARGAS_API ACC_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACC_BaseCharacter();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
protected:
	void GiveStartUpAbilities();
	
private:
	
	UPROPERTY(EditDefaultsOnly, Category= "Crash|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartUpAbilities;

};
