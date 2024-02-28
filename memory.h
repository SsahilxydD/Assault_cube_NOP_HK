#pragma once
#include <Windows.h>

struct Hook
{
	BYTE* hookPosition{ nullptr };
	BYTE stolenBytes[20]{ 0 };
	int lengthOfHook;
	bool bActive = false;

	BYTE* desiredFunction{ nullptr };
	DWORD hookToTrampJump;
	DWORD trampToFuncCall;
	DWORD returnJump;

	BYTE* trampoline{ nullptr };

	BYTE preserveStack[2]{ 0x60, 0x9C };
	BYTE releaseStack[2]{ 0x9D, 0x61 };
	bool bTrampBuilt = false;

	DWORD hookToDetourJump;
	DWORD returnJumpDetour;

	void ToggleTrampSBF();
	void ToggleTrampSBL();
	void ToggleDetour();

	Hook(BYTE* hookPosition, BYTE* desiredFunction, int lengthOfHook);
	Hook();
};

struct Nop
{
	BYTE* nopPosition{ nullptr };
	int length{ 0 };
	BYTE stolenBytes[30]{ 0 };
	bool bActive = false;
	void ToggleNop();
	Nop(BYTE* nopPosition, int length);
	Nop();
};




