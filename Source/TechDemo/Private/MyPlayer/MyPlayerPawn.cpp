// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer/MyPlayerPawn.h"
#include "Cameras/CameraManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyPlayerPawn::AMyPlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>("PlayerCamera");
	RootComponent = PlayerCamera;

}

// Called when the game starts or when spawned
void AMyPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
	CameraManagerClass = Cast<ACameraManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ACameraManager::StaticClass()));

	if (!CameraManagerClass) return;
	
	AMyPlayerController* PC = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
	
	if (!PC) return;
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("IT WORKED"));
	
	//Setting the player's camera is the first camera in the CameraManager
	CameraManagerClass->SetDefaultCam();
	PC->SetViewTargetWithBlend(CameraManagerClass);
}

// Called every frame
void AMyPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

