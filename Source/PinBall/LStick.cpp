// Fill out your copyright notice in the Description page of Project Settings.


#include "LStick.h"
#include "Components/InputComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
ALStick::ALStick()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));

	LBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("LBoxComp"));
	LBoxComp->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	
	LMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LMeshComp"));
	LMeshComp->SetupAttachment(LBoxComp);

	RBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("RBoxComp"));
	RBoxComp->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);

	RMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RMeshComp"));
	RMeshComp->SetupAttachment(RBoxComp);
	
	RootComponent = RootComp;
}

// Called when the game starts or when spawned
void ALStick::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALStick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
	FRotator rotation = FRotator(0, 0, 30);
	LBoxComp->AddLocalRotation(rotation);
}

void ALStick::RSitckPressed()
{
	UE_LOG(LogTemp, Log, TEXT("Right Stick pressed"));
	FRotator rotation = FRotator(0, 0, -30);
	RBoxComp->AddLocalRotation(rotation);
}

void ALStick::LSitckReleased()
{
	UE_LOG(LogTemp, Log, TEXT("Left Stick released"));
	FRotator rotation = FRotator(0, 0, -30);
	LBoxComp->AddLocalRotation(rotation);
}

void ALStick::RSitckReleased()
{
	UE_LOG(LogTemp, Log, TEXT("Right Stick released"));
	FRotator rotation = FRotator(0, 0, 30);
	RBoxComp->AddLocalRotation(rotation);
}

