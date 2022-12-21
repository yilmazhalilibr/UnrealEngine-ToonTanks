// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	int32 VisibleAnywhereInt = 12;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 EdiyAnywhereInt=22;

	UPROPERTY(VisibleInstanceOnly)
	int32 VisibleInstanceOnly = 32;

	UPROPERTY(VisibleDefaultsOnly)
	int VisibleDefaultsOnlyInt = 5;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "Super Variables", meta = (AllowPrivateAccess = "true"))
	int32 EditDefaultsOnlyInt = 9;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite,Category = "Super Variables", meta = (AllowPrivateAccess = "true"))
	int32 EditInstanceOnlyInt = 14;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Speed = 400;
private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly , Category = "Components" , meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly , Category = "Components" , meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly , Category = "Components" , meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly , Category = "Components" , meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectTileSpawnPoint;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
