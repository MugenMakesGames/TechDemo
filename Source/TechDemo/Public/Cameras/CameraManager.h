// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "CameraManager.generated.h"

UCLASS()
class TECHDEMO_API ACameraManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera1;
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera2;
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera3;
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera4;
	
	UPROPERTY()	
	TArray<UCameraComponent*> AllCameras;
	
	UFUNCTION()
	void SetPlayerCamera(int CamID);
	
	UFUNCTION()
	void SetAllCameraInactive();
};
