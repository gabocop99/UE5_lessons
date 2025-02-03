// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameModeBase.h"

#include "CustomTPCharacter.h"

ACustomGameModeBase::ACustomGameModeBase()
{
	if (MyDefaultPawnClass != nullptr)
	{
		DefaultPawnClass = MyDefaultPawnClass;
		return;
	}
	
	DefaultPawnClass = ACustomTPCharacter::StaticClass();
}
