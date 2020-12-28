#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>
#include "Screen.h"
#include "Fps.h"

FPSData* fpsData;
int hero_x, hero_y;

void Init()
{
    InitFPSData(&fpsData);
    hero_x = 10;
    hero_y = 10;
}

void Update()
{
}

void Render()
{
    ScreenClear();
    DrawFPS(&fpsData);

    ScreenPrint(hero_x, hero_y, "A");

    ScreenFlipping();
}

void Release()
{
    DestoyFPSData(&fpsData);
}

void WaitRender(clock_t OldTime)
{
    int CurTime;
    
    while (1)
    {
        CurTime = clock();
        if (CurTime - OldTime > 1)
        {
            break;
        }
    }
}

int GetKeyEvent()
{
    if (_kbhit())
    {
        return _getch();
    }
    return 0;
}

int KeyProcess(int key)
{
    if (key == 'q')
        return 1;
    switch (key)
    {
    case 'j':
        hero_x -= 1;
        break;
    case 'l':
        hero_x += 1;
        break;
    case 'k':
        hero_y += 1;
        break;
    case 'i':
        hero_y -= 1;
        break;
    }
    return 0;
}

int main()
{
    int nKey;
    clock_t CurTime, OldTime;
    ScreenInit();
    Init();//�ʱ�ȭ

    while (1)
    {
        OldTime = clock();

        nKey = GetKeyEvent();
        if (KeyProcess(nKey) == 1)
        {
            break;
        }
               
        Update();//������ ����
        Render();//ȭ�� ���

        WaitRender(OldTime);
        
    }
    Release();//����
    ScreenRelease();
    return 0;
}


// ��ó: https://huiyu.tistory.com/entry/C����-���Ӹ����-3-������-���-����?category=463903 [huiyu's blog]