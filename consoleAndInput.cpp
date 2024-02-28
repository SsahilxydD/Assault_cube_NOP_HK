#include "pch.h"
#include <iostream>
#include "consoleAndInput.h"
#include "setupHooksAndNops.h"

bool bBreakHackThreadWhileLoop = false;

void GetInput()
{
	if (GetAsyncKeyState(VK_END) & 1)
	{
		BreakHackLoop();
	}


	if (GetAsyncKeyState(VK_NUMPAD0) & 1)
	{
		infAmmoNop.ToggleNop();
		PrintConsole();
	}


}
void PrintConsole()
{
    system("CLS");
    std::cout << "Press NUMPAD0 for infAmmoNop" << std::endl;
    std::cout << "Press END to unload" << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << "Inf Ammo: " << (infAmmoNop.bActive) <<std::endl;

}
void BreakHackLoop()
{
    if (infAmmoNop.bActive)infAmmoNop.ToggleNop();

	mainHackLoopTramp.ToggleTrampSBF();
	bBreakHackThreadWhileLoop = true;
}
void ToggleConsole();
