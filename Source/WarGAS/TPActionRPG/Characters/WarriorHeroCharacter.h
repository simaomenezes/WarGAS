// War GAS - SIMAO

#pragma once

#include "CoreMinimal.h"
#include "WarriorBaseCharacter.h"
#include "WarriorHeroCharacter.generated.h"

struct FInputActionValue;
class UWarrior_DataAsset_InputConfig;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class WARGAS_API AWarriorHeroCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

public:
	AWarriorHeroCharacter();
	
protected:
	
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	virtual void BeginPlay() override;
	
private:
	
#pragma region Components
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Warrior|Camera",  meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom; 
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Warrior|Camera",  meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
#pragma endregion Components
	
#pragma region Inputs

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Warrior|CharacterData", meta = (AllowPrivateAccess = "true"))
	UWarrior_DataAsset_InputConfig* InputConfigDataAsset;

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);

#pragma endregion

};
