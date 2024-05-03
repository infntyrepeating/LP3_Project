#include "Char_SecondDoor.h"
#include "DoorSecondDoor.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

AChar_SecondDoor::AChar_SecondDoor()
{
	// Set this character to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;
}

void AChar_SecondDoor::BeginPlay()
{
	Super::BeginPlay();
}

void AChar_SecondDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AChar_SecondDoor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AChar_SecondDoor::Interaction() {
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADoorSecondDoor::StaticClass(), FoundActors);

	UE_LOG(LogTemp, Warning, TEXT("Interaction pressed!"));
	if (FoundActors.Num() > 0) {
		ADoorSecondDoor* Door = Cast<ADoorSecondDoor>(FoundActors[0]);
		if (Door)
		{
			FVector CharacterLocation = GetActorLocation();
			FVector DoorLocation = Door->GetActorLocation();
			float Distance = FVector::Dist(CharacterLocation, DoorLocation);

			if (Distance <= 350.0f) {
				if (Door->GetClass()->ImplementsInterface(USecondDoorInterface::StaticClass())) {
					ISecondDoorInterface* DoorInterface = Cast<ISecondDoorInterface>(Door);
					if (DoorInterface) {
						ISecondDoorInterface::Execute_OnInteractCPP(Door);
					}
				}
			}
			else {
				UE_LOG(LogTemp, Warning, TEXT("Distancia: %f"), Distance);
			}
		}
	}
}

