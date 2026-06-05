// War GAS - SIMAO

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Blueprint/UserWidget.h"
#include "CC_AttributeWidget.generated.h"

class UCC_AttributeSet;
/**
 * 
 */
UCLASS()
class WARGAS_API UCC_AttributeWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crash|Attributes")
	FGameplayAttribute Attribute;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crash|Attributes")
	FGameplayAttribute MaxAttribute;

	void OnAttributeChange(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair, UCC_AttributeSet* AttributeSet);
	bool MatchesAttributes(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Attribute Change"))
	void BP_OnAttributeChange(float NewValue, float NewMaxValue);
};
