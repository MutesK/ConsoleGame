#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include "Console.h"

HANDLE  hConsole;
char cs_BackBuffer[dfSCREEN_HEIGHT][dfSCREEN_WIDTH];

//-------------------------------------------------------------
// �ܼ� ��� ���� �غ� �۾�.
// ���� ��ġ�� ���� �ʱ�ȭ �۾��� �ʿ���.
//-------------------------------------------------------------
void cs_Initial(void)
{
	CONSOLE_CURSOR_INFO stConsoleCursor;

	//-------------------------------------------------------------
	// ȭ���� Ŀ���� �Ⱥ��̰Բ� �����Ѵ�.
	//-------------------------------------------------------------
	stConsoleCursor.bVisible = FALSE;
	stConsoleCursor.dwSize = 1;			// Ŀ�� ũ��.
										// �̻��ϰԵ� 0 �̸� ���´�. 1���ϸ� �ȳ��´�.

										//-------------------------------------------------------------
										// �ܼ�ȭ�� (���ٴٵ� �ƿ�ǲ) �ڵ��� ���Ѵ�.
										//-------------------------------------------------------------
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hConsole, &stConsoleCursor);

}

//-------------------------------------------------------------
// �ܼ� ȭ���� Ŀ���� X, Y ��ǥ�� �̵���Ų��.
//
//-------------------------------------------------------------
void cs_MoveCursor(int iPosX, int iPosY)
{
	COORD stCoord;
	stCoord.X = iPosX;
	stCoord.Y = iPosY;
	//-------------------------------------------------------------
	// ���ϴ� ��ġ�� Ŀ���� �̵���Ų��.
	//-------------------------------------------------------------
	SetConsoleCursorPosition(hConsole, stCoord);
}

//-------------------------------------------------------------
// �ܼ� ȭ���� ����ȭ �Ѵ�.
//
//-------------------------------------------------------------
void cs_ClearScreen(void)
{
	int iCountX, iCountY;

	//-------------------------------------------------------------
	// ȭ�� ũ�⸸ŭ ����, ���� ���� for ���� ����Ͽ�
	// ������ ��ǥ���� printf(" ");  ������ ���� ��� ���ش�.
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
// ������ ����ȭ �Ѵ�.
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
// ���ۿ� ������ �Է� �Ѵ�.
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
// ����ϴ� �Լ�
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