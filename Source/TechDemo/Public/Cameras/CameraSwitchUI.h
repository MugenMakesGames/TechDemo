// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "CameraSwitchUI.generated.h"

class ACameraManager;

/**
 * 
 */
UCLASS()
class TECHDEMO_API UCameraSwitchUI : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	
	virtual void NativeConstruct() override;
	
	UPROPERTY()
	ACameraManager* CameraManagerClass;

public:
	
	UPROPERTY(meta = (Bindwidget), BlueprintReadWrite)
	UButton* SwitchToLeftCamera;
	
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UButton* SwitchToRightCamera;
	
	UFUNCTION()
	void OnSwitchToLeftCam();
	
	UFUNCTION()
	void OnSwitchToRightCam();
};
