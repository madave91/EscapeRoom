// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UGrabber : public UActorComponent
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
	//How far can we reach things in cm
	float Reach = 100.0f;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;
	
	//Raycast and Grab what we need
	void Grab();
	
	//Grab release
	void Release();

	//find attached pyshics handle
	void FindPhysicsHandleComponent();

	//find input component
	void SetupInputComponent();

	//returen hit from the first pyhsics body
	const FHitResult GetFirstPhysicsBodyInReach();

	//returns current end od reach line
	FVector GetReachLineStart();

	//returns current end od reach line
	FVector GetReachLineEnd();
};
