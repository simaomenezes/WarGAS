// War GAS - SIMAO


#include "CC_WidgetComponent.h"

#include "WarGAS/CrashCourse/AbilitySystem/CC_AbilitySystemComponent.h"
#include "WarGAS/CrashCourse/AbilitySystem/CC_AttributeSet.h"
#include "WarGAS/CrashCourse/Characters/CC_BaseCharacter.h"


UCC_WidgetComponent::UCC_WidgetComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UCC_WidgetComponent::BeginPlay()
{
	Super::BeginPlay();
	
	InitAbilitySystemData();
	
	if (!IsASCInitialized())
	{
		CrashCharacter->OnASCInitialized.AddDynamic(this, &ThisClass::OnASCInitialized);
	}
}

void UCC_WidgetComponent::InitAbilitySystemData()
{
	CrashCharacter = Cast<ACC_BaseCharacter>(GetOwner());
	AttributeSet = Cast<UCC_AttributeSet>(CrashCharacter->GetAttributeSet());
	AbilitySystemComponent = Cast<UCC_AbilitySystemComponent>(CrashCharacter->GetAbilitySystemComponent());
}

bool UCC_WidgetComponent::IsASCInitialized() const
{
	return AbilitySystemComponent.IsValid() && AttributeSet.IsValid();
}

void UCC_WidgetComponent::OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AbilitySystemComponent = Cast<UCC_AbilitySystemComponent>(ASC);
	AttributeSet = Cast<UCC_AttributeSet>(AS);

	// TODO: Check if the Attribute Set has been initialized with the first GE
	// If not, bind to some delegate that will be broadcast when it is initialized.
}
