//    _   _      _       ____     ____   __   __      _   _   U _____ u                   __   __U _____ u    _       ____     
//   |'| |'| U  /"\  u U|  _"\ uU|  _"\ u\ \ / /     | \ |"|  \| ___"|/__        __       \ \ / /\| ___"|/U  /"\  uU |  _"\ u  
//  /| |_| |\ \/ _ \/  \| |_) |/\| |_) |/ \ V /     <|  \| |>  |  _|"  \"\      /"/        \ V /  |  _|"   \/ _ \/  \| |_) |/  
//  U|  _  |u / ___ \   |  __/   |  __/  U_|"|_u    U| |\  |u  | |___  /\ \ /\ / /\       U_|"|_u | |___   / ___ \   |  _ <    
//   |_| |_| /_/   \_\  |_|      |_|       |_|       |_| \_|   |_____|U  \ V  V /  U        |_|   |_____| /_/   \_\  |_| \_\   
//   //   \\  \\    >>  ||>>_    ||>>_ .-,//|(_      ||   \\,-.<<   >>.-,_\ /\ /_,-.    .-,//|(_  <<   >>  \\    >>  //   \\_  
//  (_") ("_)(__)  (__)(__)__)  (__)__) \_) (__)     (_")  (_/(__) (__)\_)-'  '-(_/      \_) (__)(__) (__)(__)  (__)(__)  (__) 
//                                                                                                                             
//                                                                                                                             
//                                                                                                                             
//                                                                                                                             
//                                                                                                                             
//                                                                                                                             
//Text to ASCII art Generator: http://patorjk.com/software/taag/                                                                                                                

#include <Windows.h>
#include "Size.h"
#include <iostream>
int main()
{
	HANDLE sb0 = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	if (sb0 == INVALID_HANDLE_VALUE) {
		exit(0);
	}

	HANDLE sb1 = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	if (sb0 == INVALID_HANDLE_VALUE) {
		exit(0);
	}

	CONSOLE_SCREEN_BUFFER_INFO infoSb0;

	bool s0 = GetConsoleScreenBufferInfo(sb0, &infoSb0);

	wchar_t * buffer0 = new wchar_t[SSS];
	wchar_t* buffer1 = new wchar_t[SSS];

	for (int i = 0; i < SSS; i++) {
		buffer0[i] = buffer1[i] = L'0';
	}
	for (int i = 500; i < 600; i++) {
		buffer1[i] = L'o';
	}
	unsigned long writtenChar = 0;
	WriteConsole(sb0, buffer0, SSS, &writtenChar, NULL);
	WriteConsole(sb1, buffer1, SSS, &writtenChar, NULL);

	SetConsoleActiveScreenBuffer(sb0);
	HANDLE t = sb0;
	while (1) {
		Sleep(1000);
		t = t == sb0 ? sb1 : sb0;
		SetConsoleActiveScreenBuffer(t);
	}
}

