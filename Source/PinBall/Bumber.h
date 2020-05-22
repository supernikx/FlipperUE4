// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bumber.generated.h"

UCLASS()
class PINBALL_API ABumber : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABumber();

protected:
	UPROPERTY(EditAnywhere, Category = "Components")
		class UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category = "Components")
		class USphereComponent* SphereComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
