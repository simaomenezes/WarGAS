// War GAS - SIMAO


#include "CC_AttributeWidget.h"

#include "WarGAS/CrashCourse/AbilitySystem/CC_AttributeSet.h"

void UCC_AttributeWidget::OnAttributeChange(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair,
                                            UCC_AttributeSet* AttributeSet)
{
	const float AttributeValue = Pair.Key.GetNumericValue(AttributeSet);
	const float MaxAttributeValue = Pair.Value.GetNumericValue(AttributeSet);

	BP_OnAttributeChange(AttributeValue, MaxAttributeValue);
}

bool UCC_AttributeWidget::MatchesAttributes(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const
{
	return Attribute == Pair.Key && MaxAttribute == Pair.Value;
}
