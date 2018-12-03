// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void Grab();
	void Release();
	void FindPhysicsComponent();

	void BindInputComponent();
	FVector LineTraceEnd();

	const FHitResult ReturnFirstPhysicsBodyinReach();

	FVector PVLocation;
	FRotator PVRotation;
	float CastScalar = 100.0f;
	UPhysicsHandleComponent* PhysicsHandle{ nullptr };
	UInputComponent* InputComponent{ nullptr };
};
