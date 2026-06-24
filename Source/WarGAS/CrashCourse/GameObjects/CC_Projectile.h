// War GAS - SIMAO

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CC_Projectile.generated.h"

class UGameplayEffect;
class UProjectileMovementComponent;

UCLASS()
class WARGAS_API ACC_Projectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACC_Projectile();
	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crash|Damage", meta=(ExposeOnSpawn, ClampMin="0.0"))
	float Damage{10.f};
	
	UFUNCTION(BlueprintImplementableEvent, Category="Crash|Projectile")
	void SpawnImpactEffect();
private:
	
	UPROPERTY(VisibleAnywhere, Category= "Crash|Projectile")
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;
	
	UPROPERTY(EditDefaultsOnly, Category= "Crash|Damage")
	TSubclassOf<UGameplayEffect> DamageEffect;
};
