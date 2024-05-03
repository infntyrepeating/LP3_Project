#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SD_PlayerController.generated.h"

UCLASS()
class ASD_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void SetupInputComponent() override;

	void MoveForward(float AxisValue);
	void MoveSideways(float AxisValue);
	void Interact();
};
