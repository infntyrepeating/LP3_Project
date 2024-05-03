#include "SD_PlayerController.h"
#include "Char_SecondDoor.h"
#include "Components/InputComponent.h"

void ASD_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("ForwardAxis", this, &ASD_PlayerController::MoveForward);
	InputComponent->BindAxis("SidewaysAxis", this, &ASD_PlayerController::MoveSideways);
	InputComponent->BindAction("InteractionKey", IE_Pressed, this, &ASD_PlayerController::Interact);
}

void ASD_PlayerController::MoveForward(float AxisValue)
{
	APawn* ControlledPawn = GetPawn();

	if (ControlledPawn) {
		FVector ForwardVector = FVector::ForwardVector;
		FVector MovementInput = ForwardVector * AxisValue;

		ControlledPawn->AddMovementInput(MovementInput, 1.0f);
	}
}

void ASD_PlayerController::MoveSideways(float AxisValue) {
	APawn* ControlledPawn = GetPawn();

	if (ControlledPawn) {
		FVector ForwardVector = FVector::ForwardVector;
		FVector SidewaysVector = ForwardVector.RotateAngleAxis(90.0f, FVector::UpVector);
		FVector MovementInput = SidewaysVector * AxisValue;

		ControlledPawn->AddMovementInput(MovementInput, 1.0f);
	}
}

void ASD_PlayerController::Interact() {
	APawn* ControlledPawn = GetPawn();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController accepted Input."));

	if (ControlledPawn) {
		AChar_SecondDoor* charPlayer = Cast<AChar_SecondDoor>(ControlledPawn);

		if (charPlayer) {
			charPlayer->Interaction();
		}
	}
}