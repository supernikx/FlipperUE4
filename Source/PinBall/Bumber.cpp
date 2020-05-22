// Fill out your copyright notice in the Description page of Project Settings.


#include "Bumber.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Ball.h"

// Sets default values
ABumber::ABumber()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SphereComp->SetupAttachment(MeshComp);
}

// Called when the game starts or when spawned
void ABumber::BeginPlay()
{
	Super::BeginPlay();
}

void ABumber::NotifyActorBeginOverlap(AActor* OtherActor)
{
	UE_LOG(LogTemp, Log, TEXT("Item NotifyActorBeginOverlap"));

	ABall* ball = Cast<ABall>(OtherActor);
	if (ball)
	{
		UE_LOG(LogTemp, Log, TEXT("Ball Collision"));
	}
}

// Called every frame
void ABumber::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

