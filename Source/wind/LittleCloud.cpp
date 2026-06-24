// Fill out your copyright notice in the Description page of Project Settings.

#include "LittleCloud.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "GameFramework/RotatingMovementComponent.h"

// Sets default values
ALittleCloud::ALittleCloud()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 创建根组件
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	// 创建云朵网格体
	CloudMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CloudMesh"));
	CloudMesh->SetupAttachment(RootComponent);

	// 创建点光源（暖光）
	CloudLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("CloudLight"));
	CloudLight->SetupAttachment(CloudMesh);
	CloudLight->SetLightColor(FLinearColor(1.0f, 0.8f, 0.5f)); // 暖黄色
	CloudLight->SetIntensity(800.0f);
	CloudLight->SetAttenuationRadius(200.0f);

	// 创建漂浮动画组件
	FloatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("FloatingMovement"));
	FloatingMovement->RotationRate = FRotator(0.0f, 30.0f, 10.0f); // 轻微旋转
}

// Called when the game starts or when spawned
void ALittleCloud::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ALittleCloud::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 在这里添加漂浮动画（上下浮动）
	FVector NewLocation = GetActorLocation();
	NewLocation.Z += FMath::Sin(GetGameTimeSinceCreation() * 2.0f) * 0.5f;
	SetActorLocation(NewLocation);
}