// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "LStick.generated.h"

UCLASS()
class PINBALL_API ALStick : public APawn
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	ALStick();

protected:
	UPROPERTY(EditAnywhere, Category = "Components")
		class UStaticMeshComponent* LMeshComp;

	UPROPERTY(EditAnywhere, Category = "Components")
		class UBoxComponent* LBoxComp;

	UPROPERTY(EditAnywhere, Category = "Components")
		class UStaticMeshComponent* RMeshComp;

	UPROPERTY(EditAnywhere, Category = "Components")
		class UBoxComponent* RBoxComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* RootComp;

	float stickSpeed;

	int32 LStickIsDown : 1;
	int32 RStickIsDown : 1;
	float LStickTimer;
	float RStickTimer;
	FRotator LStickPressedRotation;
	FRotator LStickDefaultRotation;
	FRotator RStickPressedRotation;
	FRotator RStickDefaultRotation;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void LSitckPressed();

	void RSitckPressed();

	void LSitckReleased();

	void RSitckReleased();
};
