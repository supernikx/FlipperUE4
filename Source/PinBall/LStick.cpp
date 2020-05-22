// Fill out your copyright notice in the Description page of Project Settings.


#include "LStick.h"
#include "Components/InputComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ALStick::ALStick()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));

	LMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LMeshComp"));

	LBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("LBoxComp"));
	LBoxComp->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	LBoxComp->SetupAttachment(LMeshComp);

	RMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RMeshComp"));

	RBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("RBoxComp"));
	RBoxComp->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	RBoxComp->SetupAttachment(RMeshComp);

	RootComponent = RootComp;
}

// Called when the game starts or when spawned
void ALStick::BeginPlay()
{
	Super::BeginPlay();

	LStickDefaultRotation = LMeshComp->GetComponentRotation();
	LStickPressedRotation = LMeshComp->GetComponentRotation().Add(0, -30, 0);
	UE_LOG(LogTemp, Log, TEXT("Left Stick %s %s"), *LStickDefaultRotation.Euler().ToString(), *LStickPressedRotation.Euler().ToString());

	RStickDefaultRotation = RMeshComp->GetComponentRotation();
	RStickPressedRotation = RMeshComp->GetComponentRotation().Add(0, 30, 0);
	UE_LOG(LogTemp, Log, TEXT("Right Stick %s %s"), *RStickDefaultRotation.Euler().ToString(), *RStickPressedRotation.Euler().ToString());

	LStickTimer = 0;
	RStickTimer = 0;
	stickSpeed = 30;
}

// Called every frame
void ALStick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (RStickIsDown && !RMeshComp->GetComponentRotation().Equals(RStickPressedRotation, 5))
	{
		RStickTimer += DeltaTime * stickSpeed;
		FRotator deltaRotation = FMath::Lerp(RStickDefaultRotation, RStickPressedRotation, RStickTimer);
		RMeshComp->SetRelativeRotation(deltaRotation);
	}
	else 
	{
		RStickTimer = 0;
	}

	if (LStickIsDown && !LMeshComp->GetComponentRotation().Equals(LStickPressedRotation, 5))
	{
		LStickTimer += DeltaTime * stickSpeed;
		FRotator deltaRotation = FMath::Lerp(LStickDefaultRotation, LStickPressedRotation, LStickTimer);
		LMeshComp->SetRelativeRotation(deltaRotation);
	}
	else
	{
		LStickTimer = 0;
	}
}

// Called to bind functionality to input
void ALStick::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("LStick", IE_Pressed, this, &ALStick::LSitckPressed);
	PlayerInputComponent->BindAction("RStick", IE_Pressed, this, &ALStick::RSitckPressed);
	PlayerInputComponent->BindAction("LStick", IE_Released, this, &ALStick::LSitckReleased);
	PlayerInputComponent->BindAction("RStick", IE_Released, this, &ALStick::RSitckReleased);
}

void ALStick::LSitckPressed()
{
	UE_LOG(LogTemp, Log, TEXT("Left Stick pressed"));
	LStickIsDown = 1;
}

void ALStick::RSitckPressed()
{
	UE_LOG(LogTemp, Log, TEXT("Right Stick pressed"));
	RStickIsDown = 1;
}

void ALStick::LSitckReleased()
{
	UE_LOG(LogTemp, Log, TEXT("Left Stick released"));
	LStickIsDown = 0;
	LMeshComp->SetRelativeRotation(LStickDefaultRotation);
}

void ALStick::RSitckReleased()
{
	UE_LOG(LogTemp, Log, TEXT("Right Stick released"));
	RStickIsDown = 0;
	RMeshComp->SetRelativeRotation(RStickDefaultRotation);
}

