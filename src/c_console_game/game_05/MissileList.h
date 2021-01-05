#pragma once
#include <time.h>

typedef struct tagMissileItem
{
    int velocity;   // ����: ms,  1ĭ�� �����̴µ� �ɸ��� �ð� (��: 200)
    int x, y;       // ���� ��ġ
    clock_t move_time; // �ֱٿ� ������ �ð�

    struct tagMissileItem* next;
} MissileItem;

// typedef MissileItem* MissileList; // �Ʒ��� ������ ���

typedef struct tagMissileList
{
    MissileItem* head;
} MissileList;

void MissileListInsert(MissileList* list, int x, int y, int velocity);
/*
Missile MissileCreate(int x, int y, int velocity);
void MissileDestroy(Missile* m);
int MissileExist(Missile* m);
*/

