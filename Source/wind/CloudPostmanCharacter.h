// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CloudPostmanCharacter.generated.h"

UCLASS()
class WIND_API ACloudPostmanCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACloudPostmanCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// ---------- 二段跳相关变量 ----------

	/** 最大跳跃次数（在编辑器中可修改） */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	int32 MaxJumpCount = 2;

	/** 当前已跳跃次数（只读） */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Movement")
	int32 CurrentJumpCount = 0;

	// 重写父类的跳跃相关函数
	virtual void Landed(const FHitResult& Hit) override;
	virtual void Jump() override;
	virtual void StopJumping() override;
};