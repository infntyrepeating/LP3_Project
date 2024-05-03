#include "DoorSecondDoor.h"
#include "SecondDoorInterface.h"
#include "GameFramework/PlayerInput.h"
#include "Components/TimelineComponent.h"

ADoorSecondDoor::ADoorSecondDoor()
{
	AnimationOnGoing = false;
	isDoorOpen = false;

	MainMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainMeshComponent"));
	RootComponent = MainMeshComponent;

	RotatingMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RotatingMeshComponent"));
	RotatingMeshComponent->SetupAttachment(MainMeshComponent);

}

void ADoorSecondDoor::OnInteractCPP_Implementation() {
	UE_LOG(LogTemp, Warning, TEXT("InteractCPP has been done!"));
	if (!AnimationOnGoing) {
		AnimationOnGoing = true;
        
		//EU IA FAZER UMA ANIMAÇÃO PQ A SABRINA DISSE Q SE EU FIZESSE IA TER UM 20, EU DESISTI, TENTEI TANTAS MANEIRAS E FAZE-LA EM C++ FOI HORRIVEL, NENHUMA FUNCIONOU, A PORTA CHEGOU ATÉ A APRENDER A VOAR, ENT DESISTI.

		FRotator Target = FRotator(0, 90, 0);
		if (isDoorOpen) {
			Target = FRotator(0, 0, 0);
		}

		RotatingMeshComponent->SetRelativeRotation(Target);
		AnimationOnGoing = false;
		isDoorOpen = !isDoorOpen;

	}
}
