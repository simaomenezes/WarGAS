// War GAS - SIMAO

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "Warrior_DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARGAS_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UWarrior_DataAsset_InputConfig* InInputConfig, 
		const FGameplayTag& InInputTag, 
		ETriggerEvent TriggerEvent, 
		UserObject* ContextObject, 
		CallbackFunc Func);
};

template <class UserObject, typename CallbackFunc>
inline void UWarriorInputComponent::BindNativeInputAction(
	const UWarrior_DataAsset_InputConfig* InInputConfig, 
	const FGameplayTag& InInputTag, 
	ETriggerEvent TriggerEvent, 
	UserObject* ContextObject, 
	CallbackFunc Func)
{
		checkf(InInputConfig,TEXT("Input config data asset is null,can not proceed with binding"));

		if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
		{
			BindAction(FoundAction,TriggerEvent,ContextObject,Func);
		}
}

