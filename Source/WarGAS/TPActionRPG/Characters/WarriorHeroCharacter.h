// War GAS - SIMAO

#pragma once

#include "CoreMinimal.h"
#include "WarriorBaseCharacter.h"
#include "WarriorHeroCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class WARGAS_API AWarriorHeroCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

public:
	AWarriorHeroCharacter();
	
protected:
	virtual void BeginPlay() override;
	
private:
	
#pragma region Components
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Warrior|Camera",  meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom; 
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Warrior|Camera",  meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
#pragma endregion Components

};
