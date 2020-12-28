#pragma once
#include <time.h>

typedef struct Missile
{
    int velocity;   // ����: ms,  1ĭ�� �����̴µ� �ɸ��� �ð� (��: 200)
    int x, y;       // ���� ��ġ
    clock_t move_time; // �ֱٿ� ������ �ð�

} Missile;

Missile MissileCreate(int x, int y, int velocity);
void MissileDestroy(Missile * m);
