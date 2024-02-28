#include "pch.h"
#include "setupHooksAndNops.h"
#include "mainHackLoop.h"
#include "memory.h"




Hook mainHackLoopTramp;
Nop infAmmoNop;

void SetupHooksAndNops()
{
	BYTE* modueBaseAssaultCube = (BYTE*)GetModuleHandle(L"ac_client.exe");
	BYTE* moduleBaseOpenGl = (BYTE*)GetModuleHandle(L"opengl32.dll");

	BYTE* mainHackLoopHookDst = moduleBaseOpenGl + 0x47ADE;
	Hook mainHackLoopTrampTemp(mainHackLoopHookDst, (BYTE*)MainHackLoop, 5);
	mainHackLoopTramp = mainHackLoopTrampTemp;


	BYTE* infAmmoNopDst = modueBaseAssaultCube + 0x637E9;
	Nop infAmmoNopTemp(infAmmoNopDst, 2);
	infAmmoNop = infAmmoNopTemp;

}