#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include "Console.h"

HANDLE  hConsole;
char cs_BackBuffer[dfSCREEN_HEIGHT][dfSCREEN_WIDTH];

//-------------------------------------------------------------
// 콘솔 제어를 위한 준비 작업.
// 적군 위치에 대해 초기화 작업이 필요함.
//-------------------------------------------------------------
void cs_Initial(void)
{
	CONSOLE_CURSOR_INFO stConsoleCursor;

	//-------------------------------------------------------------
	// 화면의 커서를 안보이게끔 설정한다.
	//-------------------------------------------------------------
	stConsoleCursor.bVisible = FALSE;
	stConsoleCursor.dwSize = 1;			// 커서 크기.
										// 이상하게도 0 이면 나온다. 1로하면 안나온다.

										//-------------------------------------------------------------
										// 콘솔화면 (스텐다드 아웃풋) 핸들을 구한다.
										//-------------------------------------------------------------
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hConsole, &stConsoleCursor);

}

//-------------------------------------------------------------
// 콘솔 화면의 커서를 X, Y 좌표로 이동시킨다.
//
//-------------------------------------------------------------
void cs_MoveCursor(int iPosX, int iPosY)
{
	COORD stCoord;
	stCoord.X = iPosX;
	stCoord.Y = iPosY;
	//-------------------------------------------------------------
	// 원하는 위치로 커서를 이동시킨다.
	//-------------------------------------------------------------
	SetConsoleCursorPosition(hConsole, stCoord);
}

//-------------------------------------------------------------
// 콘솔 화면을 조기화 한다.
//
//-------------------------------------------------------------
void cs_ClearScreen(void)
{
	int iCountX, iCountY;

	//-------------------------------------------------------------
	// 화면 크기만큼 세로, 가로 이중 for 문을 사용하여
	// 각각의 좌표마다 printf(" ");  공백을 전부 출력 해준다.
	//-------------------------------------------------------------
	for (iCountY = 0; iCountY < dfSCREEN_HEIGHT; iCountY++)
	{
		for (iCountX = 0; iCountX < dfSCREEN_WIDTH; iCountX++)
		{
			cs_MoveCursor(iCountX, iCountY);
			printf(" ");
		}
	}
}
//-------------------------------------------------------------
// 버퍼을 조기화 한다.
//
//-------------------------------------------------------------
void cs_BufferClear(void)
{
	for (int i = 0; i < dfSCREEN_HEIGHT; i++)
	{
		memset(cs_BackBuffer[i], ' ', dfSCREEN_WIDTH);
		cs_BackBuffer[i][dfSCREEN_WIDTH - 1] = 0x20;
	}
}
//-------------------------------------------------------------
// 버퍼에 데이터 입력 한다.
//
//-------------------------------------------------------------
void Sprite_Draw(int x, int y, char Sprite)
{
	if (x >= 0 && x < dfSCREEN_WIDTH && y >= 0 && y < dfSCREEN_WIDTH)
	{
		cs_BackBuffer[y][x] = Sprite;
	}
}
//-------------------------------------------------------------
// 출력하는 함수
//
//-------------------------------------------------------------
void Flip(void)
{
	for (int i = 0; i < dfSCREEN_HEIGHT; i++)
	{
		cs_MoveCursor(0, i);
		printf(cs_BackBuffer[i]);
	}
	cs_MoveCursor(0, dfSCREEN_HEIGHT - 1);
}


void Hp_Draw(int x, int y, int hp)
{
	char *index = (cs_BackBuffer[y] + x);
	sprintf_s(index, 40, "Player HP : %d ", hp);
}

void Message_Draw(int x, int y, char * message)
{
	char *index = (cs_BackBuffer[y] + x);

	memcpy(index, message, strlen(message) - 1);
}