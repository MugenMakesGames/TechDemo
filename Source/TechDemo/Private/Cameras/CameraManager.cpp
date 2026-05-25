// Fill out your copyright notice in the Description page of Project Settings.


#include "Cameras/CameraManager.h"

// Sets default values
ACameraManager::ACameraManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Camera1 = CreateDefaultSubobject<UCameraComponent>("Camera_1");
	Camera1->SetupAttachment(RootComponent);
	
	Camera2 = CreateDefaultSubobject<UCameraComponent>("Camera_2");
	Camera2->SetupAttachment(RootComponent);
	
	Camera3 = CreateDefaultSubobject<UCameraComponent>("Camera_3");
	Camera3->SetupAttachment(RootComponent);
	
	Camera4 = CreateDefaultSubobject<UCameraComponent>("Camera_4");
	Camera4->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACameraManager::BeginPlay()
{
	Super::BeginPlay();
	
	//Adding all the camera to a camera array
	AllCameras.Add(Camera1);
	AllCameras.Add(Camera2);
	AllCameras.Add(Camera3);
	AllCameras.Add(Camera4);
}

// Called every frame
void ACameraManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACameraManager::SetAllCameraInactive()
{
	//Setting all camera inactive
	for (UCameraComponent* Cameras : AllCameras)
	{
		Cameras->SetActive(false);
	}
}

void ACameraManager::SetPlayerCamera(int CamID)
{
	SetAllCameraInactive();
	
	//Activating cameras based on their ID
	switch (CamID)
	{
	case 1:
		Camera1->SetActive(true);
		break;
	case 2:
		Camera2->SetActive(true);
		break;
	case 3:
		Camera3->SetActive(true);
		break;
	case 4:
		Camera4->SetActive(true);
		break;
	default:
		break;
	}
}
