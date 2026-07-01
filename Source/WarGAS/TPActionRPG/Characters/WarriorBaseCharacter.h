// War GAS - SIMAO

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "WarriorBaseCharacter.generated.h"

class UWarrior_DataAsset_StartUpDataBase;
class UWarriorAttributeSet;
class UWarriorAbilitySystemComponent;

UCLASS()
class WARGAS_API AWarriorBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AWarriorBaseCharacter();
	
	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	//~ End IAbilitySystemInterface Interface
	
protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Warrior|AbilitySystem")
	UWarriorAbilitySystemComponent* WarriorAbilitySystemComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Warrior|AbilitySystem")
	UWarriorAttributeSet* WarriorAttributeSet;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Warrior|CharacterData")
	TSoftObjectPtr<UWarrior_DataAsset_StartUpDataBase> CharacterStartUpData;
	
public:
	FORCEINLINE UWarriorAbilitySystemComponent* GetWarriorAbilitySystemComponent() const { return WarriorAbilitySystemComponent; }
	
	FORCEINLINE UWarriorAttributeSet* GetWarriorAttributeSet() const { return WarriorAttributeSet; }

};
