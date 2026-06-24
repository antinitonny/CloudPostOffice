// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LittleCloud.generated.h"

UCLASS()
class WIND_API ALittleCloud : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALittleCloud();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 云朵的网格体（外观）
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* CloudMesh;

	// 云朵的暖光
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UPointLightComponent* CloudLight;

	// 云朵的漂浮动画
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class URotatingMovementComponent* FloatingMovement;
};