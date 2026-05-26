// Fill out your copyright notice in the Description page of Project Settings.


#include "Cameras/CameraSwitchUI.h"
#include "Cameras/CameraManager.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UCameraSwitchUI::NativeConstruct()
{
	Super::NativeConstruct();
	
	CameraManagerClass = Cast<ACameraManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ACameraManager::StaticClass()));
	
	//Binding all buttons to their OnClicked functions
	if (!SwitchToLeftCamera) return;
	if (!SwitchToRightCamera) return;
	
	SwitchToLeftCamera->OnClicked.AddDynamic(this, &UCameraSwitchUI::OnSwitchToLeftCam);
	SwitchToRightCamera->OnClicked.AddDynamic(this, &UCameraSwitchUI::OnSwitchToRightCam);
	
}

void UCameraSwitchUI::OnSwitchToLeftCam()
{
	if (!CameraManagerClass) return;
	
	CameraManagerClass->SetPlayerCamera("Left");
	
	GetOwningPlayer()->SetViewTargetWithBlend(CameraManagerClass);
}

void UCameraSwitchUI::OnSwitchToRightCam()
{
	if (!CameraManagerClass) return;
	
	CameraManagerClass->SetPlayerCamera("Right");
	
	GetOwningPlayer()->SetViewTargetWithBlend(CameraManagerClass);
}
