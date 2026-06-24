// Fill out your copyright notice in the Description page of Project Settings.

#include "CloudPostmanCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ACloudPostmanCharacter::ACloudPostmanCharacter()
{
	// Set this character to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 设置角色移动属性（这些数值你可以自己调整）
	GetCharacterMovement()->JumpZVelocity = 600.f;  // 跳跃高度
	GetCharacterMovement()->AirControl = 0.8f;      // 空中控制力（0=完全不能控制，1=和地面一样灵活）
}

// Called when the game starts or when spawned
void ACloudPostmanCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACloudPostmanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACloudPostmanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// ---------- 二段跳逻辑 ----------

void ACloudPostmanCharacter::Landed(const FHitResult& Hit)
{
	// 先调用父类的Landed函数（处理落地动画等）
	Super::Landed(Hit);

	// 落地后重置跳跃次数
	CurrentJumpCount = 0;
}

void ACloudPostmanCharacter::Jump()
{
	// 判断是否可以跳跃（当前次数 < 最大次数）
	if (CurrentJumpCount < MaxJumpCount)
	{
		// 调用父类的Jump函数（执行真正的跳跃）
		Super::Jump();

		// 跳跃次数+1
		CurrentJumpCount++;
	}
	// 如果已经跳了够多次，就不执行跳跃
}

void ACloudPostmanCharacter::StopJumping()
{
	// 注意：不需要在这里重置CurrentJumpCount
	// 因为玩家可能在空中停止跳跃，但还没落地
	// 应该只在Landed里重置
	Super::StopJumping();
}