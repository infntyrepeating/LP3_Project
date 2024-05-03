#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SecondDoorInterface.h"
#include "DoorSecondDoor.generated.h"

UCLASS()
class ADoorSecondDoor : public AActor, public ISecondDoorInterface
{
	GENERATED_BODY()

public:
	ADoorSecondDoor();

public:
	virtual void OnInteractCPP_Implementation() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	UStaticMeshComponent* MainMeshComponent; // This will be your main mesh component

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	UStaticMeshComponent* RotatingMeshComponent; // This will be the mesh component you want to rotate

	// Called when the game starts or when spawned
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool AnimationOnGoing;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool isDoorOpen;

};
