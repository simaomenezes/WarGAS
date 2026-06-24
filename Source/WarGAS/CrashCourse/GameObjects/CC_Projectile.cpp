// War GAS - SIMAO


#include "CC_Projectile.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "WarGAS/CrashCourse/Characters/CC_PlayerCharacter.h"

// Sets default values
ACC_Projectile::ACC_Projectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");

	bReplicates = true;
}

void ACC_Projectile::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	ACC_PlayerCharacter* PlayerCharacter = Cast<ACC_PlayerCharacter>(OtherActor);
	if (!IsValid(PlayerCharacter)) return;
	if (!PlayerCharacter->IsAlive()) return;
	
	UAbilitySystemComponent* AbilitySystemComponent = PlayerCharacter->GetAbilitySystemComponent();
	if (!IsValid(AbilitySystemComponent) || !HasAuthority()) return;
	
	FGameplayEffectContextHandle ContextHandle = AbilitySystemComponent->MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DamageEffect, 1.f, ContextHandle);
	
	//TODO Use the Damage variable for this amount of damage to couse
	
	AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	
	SpawnImpactEffect();
	Destroy();
}
