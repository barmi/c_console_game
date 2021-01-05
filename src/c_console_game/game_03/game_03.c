
#include<stdio.h>
#if !defined(__APPLE__)
#include <conio.h>
#endif
#include "cursor.h"

#define putsxy(x, y, s) {gotoxy(x, y);puts(s);}
#define KEY_ESC 27

char tetris[21][11] = {
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"#        #",
	"##########",
};

// �� ����, ȸ�� Ƚ��, ����, ����
char tetris_block[7][4][5][5] =
{
	{
		{ // I��
			"@",
			"@",
			"@",
			"@"
		},
		{
			"@@@@"
		}
	},
	{
		{ // ����
			"@@",
			"@@"
		},
	},
	{
		{ // L��
			"@",
			"@",
			"@@"
		},
		{
			"@@@",
			"@"
		},
		{
			"@@",
			" @",
			" @"
		},
		{
			"  @",
			"@@@"
		}
	},
	{
		{ // ����
		" @",
		"@@@"
		},
		{
		"@",
		"@@",
		"@"
		},
		{
		"@@@",
		" @ "
		},
		{
		" @",
		"@@",
		" @"
		}
	},
	{
		{ // ����
			"@@",
			" @",
			" @"
		},
		{
			"  @",
			"@@@"
		},
		{
			"@",
			"@",
			"@@"
		},
		{
			"@@@",
			"@  "
		}
	},
	{
		{ // Z��
		"@@",
		" @@"
		},
		{
		" @",
		"@@",
		"@"
		}
	},
	{
		{ // S��
			" @@",
			"@@"
		},
		{
			"@",
			"@@",
			" @"
		}
	}
};

struct game
{
	int cur_x;
	int cur_y;

	int cur_block;
	int cur_block_rot;
	int cur_block_width;
	int cur_block_height;

	int dx;
	int dr;
};

void game_init(struct game * g)
{
	g->cur_x = 0;
	g->cur_y = 0;
	g->cur_block = 0;
	g->cur_block_rot = 0;
	g->dr = 0;
	g->dx = 0;

	g->cur_block_width = 0;
	g->cur_block_height = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (tetris_block[g->cur_block][g->cur_block_rot][i][j] == '@')
			{
				if (g->cur_block_width <= j + 1)
				{
					g->cur_block_width = j + 1;
				}
				g->cur_block_height = i + 1;
			}
		}
	}
}

void process_internal(struct game* g)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (tetris_block[g->cur_block][g->cur_block_rot][i][j] == '@')
			{
				//next_position_check(&g);
			}
		}
	}
}

void next_position_check(struct game* g)
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (tetris[i][j])
			{
				
			}
		}
	}
}

void process_display(struct game* g)
{
	// ��Ʈ���� Ʋ ���̰� �ϱ�
	gotoxy(0, 0);
	for (int i = 0; i < 20; i++)
	{
		printf("%s\n", tetris[i]);
	}
}

int main()
{
	struct game g;

	game_init(&g);

	while (1) {
		//process_input(&g);
		process_internal(&g);
		process_display(&g);
	}


	return 0;
}


