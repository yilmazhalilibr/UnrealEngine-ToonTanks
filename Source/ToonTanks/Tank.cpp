// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Controller.h"



ATank::ATank()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);

}
void ATank::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("MoveForward"),this, &ATank::Move);
    PlayerInputComponent->BindAxis(TEXT("Turn"),this,&ATank::Turn);

    PlayerInputComponent->BindAction(TEXT("Fire"),IE_Pressed,this,&ATank::Fire);
}
void ATank::BeginPlay()
{
    Super::BeginPlay();
    PlayerControllerRef = Cast<APlayerController>(GetController());
    
        DrawDebugSphere(GetWorld(),
        GetActorLocation() + FVector(0.f,0.f,200.f),
        100.f,
        12,
        FColor::Red,
        true,
        30.f
        );
}
void ATank::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if(PlayerControllerRef)
    {
        FHitResult HitResult;
        PlayerControllerRef->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility,false,HitResult);

        RotateTurret(HitResult.ImpactPoint);
    }
}

void ATank::Move(float Value)
{
    UE_LOG(LogTemp, Display, TEXT("Value %f"),Value);
    FVector DeltaLocation = FVector::ZeroVector;

    DeltaLocation.X = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);

    AddActorLocalOffset(DeltaLocation,true);

}
void ATank::Turn(float Value)
{
    FRotator DeltaRotation = FRotator::ZeroRotator;

    DeltaRotation.Yaw = Value * TurnRate * UGameplayStatics::GetWorldDeltaSeconds(this);
    AddActorLocalRotation(DeltaRotation,true);
}