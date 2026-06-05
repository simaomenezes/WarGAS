// War GAS - SIMAO
#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "CC_BaseCharacter.generated.h"

struct FOnAttributeChangeData;
class UAttributeSet;
class UGameplayEffect;
class UGameplayAbility;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FASCInitialized, UAbilitySystemComponent*, ASC, UAttributeSet*, AS);

UCLASS(Abstract)
class WARGAS_API ACC_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACC_BaseCharacter();
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	UPROPERTY(BlueprintAssignable)
	FASCInitialized OnASCInitialized;
	
	virtual UAttributeSet* GetAttributeSet() const { return nullptr; }
	
	bool IsAlive() const { return bAlive;}
	void SetAlive(bool bAliveStatus) { bAlive = bAliveStatus;}
	
	UFUNCTION(BlueprintCallable, Category= "Crash|Death")
	virtual void HandleRespawn();
	
protected:
	void GiveStartUpAbilities();
	void InitializeAttributes() const;
	
	void OnHealthChanged(const FOnAttributeChangeData& AttributeChangeData);
	
	virtual void HandleDeath();

private:
	
	UPROPERTY(EditDefaultsOnly, Category= "Crash|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartUpAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category = "Crash|Effects")
	TSubclassOf<UGameplayEffect> InitializeAttributesEffect;
	
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Replicated)
	bool bAlive = true;
};
