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
	SwitchToLeftCamera->OnClicked.AddUniqueDynamic(this, UCameraSwitchUI::OnSwitchToLeftCam);
	
	
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
