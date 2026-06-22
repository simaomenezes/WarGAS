// War GAS - SIMAO

#pragma once

#include "CoreMinimal.h"
#include "CC_BaseCharacter.h"
#include "CC_EnemyCharacter.generated.h"

class UAttributeSet;

UCLASS()
class WARGAS_API ACC_EnemyCharacter : public ACC_BaseCharacter
{
	GENERATED_BODY()

public:
	ACC_EnemyCharacter();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	virtual UAttributeSet* GetAttributeSet() const override;
	
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crash|AI")
	float AcceptanceRadius{500.f};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crash|AI")
	float MinAttackDelay{.1f};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crash|AI")
	float MaxAttackDelay{.5f};
	
	virtual void BeginPlay() override;
	
	virtual void HandleDeath() override;
	
private:
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
