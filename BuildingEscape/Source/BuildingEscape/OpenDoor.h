// Copyright Kristian Mandaric 2018

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
		float OpenAngle = -90.0f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 0.55f;

		float LastDoorOpenTime; 

		// The owning door
		AActor* Owner = nullptr; 

		//returns total mass in kgs
		float GetTotalMassOfActorsOnPlate();

};

