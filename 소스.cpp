#pragma warning (disable : 4996)
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define up 72
#define down 80
#define left 75
#define right 77
int ck, ckGameEnd, score;
char trash;
int map[25][12] = {
	1,1,1,1,1,1,1,1,1,1,1,1,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	1,1,1,1,1,1,1,1,1,1,1,1
};
int copymap[25][12] = {
	1,1,1,1,1,1,1,1,1,1,1,1,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	2,0,0,0,0,0,0,0,0,0,0,3,
	1,1,1,1,1,1,1,1,1,1,1,1
};
void setmap() {
	int i, j;
	for (i = 0; i < 25; i++)
		for (j = 0; j < 12; j++)
			map[i][j] = copymap[i][j];
}
int nextblockmap[6][7] = {
	1,0,0,0,0,0,1,
	1,0,0,0,0,0,1,
	1,0,0,0,0,0,1,
	1,0,0,0,0,0,1,
	1,0,0,0,0,0,1,
	1,1,1,1,1,1,1,
};
void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void cursor(int n) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
void textcolor(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
struct pos {
	int x;
	int y;
};
pos blockpos[7][4][4];
pos prexy[4];
void setblockpos() {
	// ¡á ¡á ¡á ¡á   textcolor(11);
	blockpos[0][0][0].x = -2; blockpos[0][0][0].y = 2; blockpos[0][0][1].x = 0; blockpos[0][0][1].y = 2; blockpos[0][0][2].x = 2; blockpos[0][0][2].y = 2; blockpos[0][0][3].x = 4; blockpos[0][0][3].y = 2;
	blockpos[0][1][0].x = 0; blockpos[0][1][0].y = 1; blockpos[0][1][1].x = 0; blockpos[0][1][1].y = 2; blockpos[0][1][2].x = 0; blockpos[0][1][2].y = 3; blockpos[0][1][3].x = 0; blockpos[0][1][3].y = 4;
	blockpos[0][2][0].x = -2; blockpos[0][2][0].y = 2; blockpos[0][2][1].x = 0; blockpos[0][2][1].y = 2; blockpos[0][2][2].x = 2; blockpos[0][2][2].y = 2; blockpos[0][2][3].x = 4; blockpos[0][2][3].y = 2;
	blockpos[0][3][0].x = 0; blockpos[0][3][0].y = 1; blockpos[0][3][1].x = 0; blockpos[0][3][1].y = 2; blockpos[0][3][2].x = 0; blockpos[0][3][2].y = 3; blockpos[0][3][3].x = 0; blockpos[0][3][3].y = 4;
	//   ¡á ¡á
	// ¡á ¡á       textcolor(10);
	blockpos[1][0][0].x = -2; blockpos[1][0][0].y = 3; blockpos[1][0][1].x = 0; blockpos[1][0][1].y = 3; blockpos[1][0][2].x = 0; blockpos[1][0][2].y = 2; blockpos[1][0][3].x = 2; blockpos[1][0][3].y = 2;
	blockpos[1][1][0].x = -2; blockpos[1][1][0].y = 1; blockpos[1][1][1].x = -2; blockpos[1][1][1].y = 2; blockpos[1][1][2].x = 0; blockpos[1][1][2].y = 2; blockpos[1][1][3].x = 0; blockpos[1][1][3].y = 3;
	blockpos[1][2][0].x = -2; blockpos[1][2][0].y = 3; blockpos[1][2][1].x = 0; blockpos[1][2][1].y = 3; blockpos[1][2][2].x = 0; blockpos[1][2][2].y = 2; blockpos[1][2][3].x = 2; blockpos[1][2][3].y = 2;
	blockpos[1][3][0].x = -2; blockpos[1][3][0].y = 1; blockpos[1][3][1].x = -2; blockpos[1][3][1].y = 2; blockpos[1][3][2].x = 0; blockpos[1][3][2].y = 2; blockpos[1][3][3].x = 0; blockpos[1][3][3].y = 3;
	// ¡á ¡á
	//   ¡á ¡á     textcolor(12);
	blockpos[2][0][0].x = -2; blockpos[2][0][0].y = 2; blockpos[2][0][1].x = 0; blockpos[2][0][1].y = 2; blockpos[2][0][2].x = 0; blockpos[2][0][2].y = 3; blockpos[2][0][3].x = 2; blockpos[2][0][3].y = 3;
	blockpos[2][1][0].x = 0; blockpos[2][1][0].y = 3; blockpos[2][1][1].x = 0; blockpos[2][1][1].y = 2; blockpos[2][1][2].x = 2; blockpos[2][1][2].y = 2; blockpos[2][1][3].x = 2; blockpos[2][1][3].y = 1;
	blockpos[2][2][0].x = -2; blockpos[2][2][0].y = 2; blockpos[2][2][1].x = 0; blockpos[2][2][1].y = 2; blockpos[2][2][2].x = 0; blockpos[2][2][2].y = 3; blockpos[2][2][3].x = 2; blockpos[2][2][3].y = 3;
	blockpos[2][3][0].x = 0; blockpos[2][3][0].y = 3; blockpos[2][3][1].x = 0; blockpos[2][3][1].y = 2; blockpos[2][3][2].x = 2; blockpos[2][3][2].y = 2; blockpos[2][3][3].x = 2; blockpos[2][3][3].y = 1;
	// ¡á ¡á
	// ¡á ¡á       textcolor(14);
	blockpos[3][0][0].x = 0; blockpos[3][0][0].y = 2; blockpos[3][0][1].x = -2; blockpos[3][0][1].y = 2; blockpos[3][0][2].x = 0; blockpos[3][0][2].y = 3; blockpos[3][0][3].x = -2; blockpos[3][0][3].y = 3;
	blockpos[3][1][0].x = 0; blockpos[3][1][0].y = 2; blockpos[3][1][1].x = -2; blockpos[3][1][1].y = 2; blockpos[3][1][2].x = 0; blockpos[3][1][2].y = 3; blockpos[3][1][3].x = -2; blockpos[3][1][3].y = 3;
	blockpos[3][2][0].x = 0; blockpos[3][2][0].y = 2; blockpos[3][2][1].x = -2; blockpos[3][2][1].y = 2; blockpos[3][2][2].x = 0; blockpos[3][2][2].y = 3; blockpos[3][2][3].x = -2; blockpos[3][2][3].y = 3;
	blockpos[3][3][0].x = 0; blockpos[3][3][0].y = 2; blockpos[3][3][1].x = -2; blockpos[3][3][1].y = 2; blockpos[3][3][2].x = 0; blockpos[3][3][2].y = 3; blockpos[3][3][3].x = -2; blockpos[3][3][3].y = 3;
	//     ¡á
	// ¡á ¡á ¡á     texrtcolor(6);
	blockpos[4][0][0].x = -2; blockpos[4][0][0].y = 3; blockpos[4][0][1].x = 0; blockpos[4][0][1].y = 3; blockpos[4][0][2].x = 2; blockpos[4][0][2].y = 3; blockpos[4][0][3].x = 2; blockpos[4][0][3].y = 2;
	blockpos[4][1][0].x = 0; blockpos[4][1][0].y = 1; blockpos[4][1][1].x = 0; blockpos[4][1][1].y = 2; blockpos[4][1][2].x = 0; blockpos[4][1][2].y = 3; blockpos[4][1][3].x = 2; blockpos[4][1][3].y = 3;
	blockpos[4][2][0].x = -2; blockpos[4][2][0].y = 3; blockpos[4][2][1].x = -2; blockpos[4][2][1].y = 2; blockpos[4][2][2].x = 0; blockpos[4][2][2].y = 2; blockpos[4][2][3].x = 2; blockpos[4][2][3].y = 2;
	blockpos[4][3][0].x = -2; blockpos[4][3][0].y = 1; blockpos[4][3][1].x = 0; blockpos[4][3][1].y = 1; blockpos[4][3][2].x = 0; blockpos[4][3][2].y = 2; blockpos[4][3][3].x = 0; blockpos[4][3][3].y = 3;
	// ¡á ¡á ¡á
	//     ¡á     textcolor(9);
	blockpos[5][0][0].x = -2; blockpos[5][0][0].y = 2; blockpos[5][0][1].x = -2; blockpos[5][0][1].y = 3; blockpos[5][0][2].x = 0; blockpos[5][0][2].y = 3; blockpos[5][0][3].x = 2; blockpos[5][0][3].y = 3;
	blockpos[5][1][0].x = 0; blockpos[5][1][0].y = 3; blockpos[5][1][1].x = 0; blockpos[5][1][1].y = 2; blockpos[5][1][2].x = 0; blockpos[5][1][2].y = 1; blockpos[5][1][3].x = 2; blockpos[5][1][3].y = 1;
	blockpos[5][2][0].x = -2; blockpos[5][2][0].y = 2; blockpos[5][2][1].x = 0; blockpos[5][2][1].y = 2; blockpos[5][2][2].x = 2; blockpos[5][2][2].y = 2; blockpos[5][2][3].x = 2; blockpos[5][2][3].y = 3;
	blockpos[5][3][0].x = -2; blockpos[5][3][0].y = 3; blockpos[5][3][1].x = 0; blockpos[5][3][1].y = 3; blockpos[5][3][2].x = 0; blockpos[5][3][2].y = 2; blockpos[5][3][3].x = 0; blockpos[5][3][3].y = 1;
	//  ¡á
	//¡á ¡á ¡á      textcolor(13);
	blockpos[6][0][0].x = -2; blockpos[6][0][0].y = 3; blockpos[6][0][1].x = 0; blockpos[6][0][1].y = 3; blockpos[6][0][2].x = 2; blockpos[6][0][2].y = 3; blockpos[6][0][3].x = 0; blockpos[6][0][3].y = 2;
	blockpos[6][1][0].x = 0; blockpos[6][1][0].y = 2; blockpos[6][1][1].x = 0; blockpos[6][1][1].y = 3; blockpos[6][1][2].x = 0; blockpos[6][1][2].y = 4; blockpos[6][1][3].x = 2; blockpos[6][1][3].y = 3;
	blockpos[6][2][0].x = -2; blockpos[6][2][0].y = 3; blockpos[6][2][1].x = 0; blockpos[6][2][1].y = 3; blockpos[6][2][2].x = 2; blockpos[6][2][2].y = 3; blockpos[6][2][3].x = 0; blockpos[6][2][3].y = 4;
	blockpos[6][3][0].x = 0; blockpos[6][3][0].y = 2; blockpos[6][3][1].x = 0; blockpos[6][3][1].y = 3; blockpos[6][3][2].x = 0; blockpos[6][3][2].y = 4; blockpos[6][3][3].x = -2; blockpos[6][3][3].y = 3;
};
void output() {
	int i, j;
	for (i = 0; i < 25; i++) {
		gotoxy(29, i + 1);
		for (j = 0; j < 12; j++) {
			if (i == 6 && map[i][j] != 0) {
				textcolor(14);
				printf("¡Ú");
				textcolor(7);
			}
			else if (map[i][j] == 0)
				printf(" .");
			else if (map[i][j] == 4)
				printf("¡á");
			else
				printf("¡à");
		}
		printf("\n");
	}
	return;
}
void printnextblock(int nextblock) {
	int i, j, x = 62, y = 3;
	gotoxy(56, 2);
	printf("  Next Block");
	for (i = 3; i < 9; i++) {
		gotoxy(56, i);
		for (j = 0; j < 7; j++) {
			if (nextblockmap[i - 3][j] == 1)
				printf("¡à");
			else
				printf("  ");
		}
	}
	switch (nextblock) {
	case 0: textcolor(11); break;
	case 1: textcolor(10); break;
	case 2: textcolor(12); break;
	case 3: textcolor(14); break;
	case 4: textcolor(6); break;
	case 5: textcolor(9); break;
	case 6: textcolor(13); break;
	}
	for (i = 0; i < 4; i++) {
		gotoxy(x + blockpos[nextblock][0][i].x, y + blockpos[nextblock][0][i].y);
		printf("¡á");
	}
	textcolor(7);
}
void printhelp(int level, int dueto, int* bestscore) {
	gotoxy(56, 10);
	printf("    Level     : %d", level);
	gotoxy(56, 11);
	printf("To Next Level :       ");
	gotoxy(56, 11);
	printf("To Next Level : %d", dueto);
	gotoxy(56, 13);
	printf("  YOUR SCORE  :");
	gotoxy(56, 14);
	printf("%17d", score);
	gotoxy(56, 15);
	printf("  BEST SCORE  :");
	gotoxy(56, 16);
	if (score > *bestscore)
		*bestscore = score;
	printf("%17d", *bestscore);
	gotoxy(56, 18);
	printf("  ¡â   : Rotate");
	gotoxy(56, 19);
	printf("¢·  ¢¹ : Left / Right");
	gotoxy(56, 20);
	printf("  ¡ä   : Soft Drop");
	gotoxy(56, 22);
	printf("SPACE  : Hard Drop");
	gotoxy(56, 23);
	printf("  P    : Pause");
	gotoxy(56, 24);
	printf(" ESC   : Quit");

}
void setlevel_line(int level_line[10]) {
	level_line[0] = 2;
	level_line[1] = 3;
	level_line[2] = 5;
	level_line[3] = 8;
	level_line[4] = 12;
	level_line[5] = 17;
	level_line[6] = 23;
	level_line[7] = 29;
	level_line[8] = 35;
	level_line[9] = 25;
}
int rotatecheck(int nx, int ny) {
	nx -= 28;
	nx = (nx - 1) / 2;	ny -= 1;
	if (map[ny][nx] == 4)
		return 1;
	else
		return 0;
}
void eraseblock() {
	int i;
	for (i = 0; i < 4; i++) {
		gotoxy(prexy[i].x, prexy[i].y);
		printf(" .");
	}
}
int detectbottomwall(int nx, int ny) {
	nx -= 28;
	nx = (nx - 1) / 2;	ny -= 1;
	if (map[ny][nx] == 1 || map[ny][nx] == 4) {
		return 0;
	}
	if (map[ny][nx] == 0) {
		return 1;
	}
}
void detectsidewall(int nx, int ny) {
	if (nx < 31) {
		ck = 2;
		return;
	}
	if (nx > 50) {
		ck = 3;
		return;
	}
}
void printblock(int n, int* idxx, int idxy, int direction) {
	int p = 41, q = 1, i, check = 0;
	p += *idxx; q += idxy;
	for (i = 0; i < 4; i++) {
		check += detectbottomwall(p + blockpos[n][direction][i].x, q + blockpos[n][direction][i].y);
	}
	if (check < 4) {
		ck = 1;
		return;
	}
	for (i = 0; i < 4; i++) {
		while (p + blockpos[n][direction][i].x < 31 || p + blockpos[n][direction][i].x > 50) {
			detectsidewall(p + blockpos[n][direction][i].x, q + blockpos[n][direction][i].y);
			if (ck == 2) {
				*idxx += 2;
				p += 2;
			}
			if (ck == 3) {
				*idxx -= 2;
				p -= 2;
			}
		}
	}
	eraseblock();
	switch (n) {
	case 0: textcolor(11); break;
	case 1: textcolor(10); break;
	case 2: textcolor(12); break;
	case 3: textcolor(14); break;
	case 4: textcolor(6); break;
	case 5: textcolor(9); break;
	case 6: textcolor(13); break;
	}
	for (i = 0; i < 4; i++) {
		gotoxy(p + blockpos[n][direction][i].x, q + blockpos[n][direction][i].y);
		prexy[i].x = p + blockpos[n][direction][i].x;
		prexy[i].y = q + blockpos[n][direction][i].y;
		printf("¡á");
	}
	textcolor(7);
}
void rotateblock(int* idxx, int idxy, int* turncnt, int curblock) {
	int p = 41, q = 1, i, check = 0;
	p += *idxx; q += idxy;
	if (*turncnt >= 4)
		*turncnt %= 4;
	for (i = 0; i < 4; i++) {
		check += rotatecheck(p + blockpos[curblock][*turncnt][i].x, q + blockpos[curblock][*turncnt][i].y);
	}
	if (check > 0) {
		if (*turncnt == 0)
			*turncnt = 4;
		*turncnt -= 1;
	}
	printblock(curblock, idxx, idxy, *turncnt);
	return;
}
void putdata() {
	int i;
	for (i = 0; i < 4; i++) {
		prexy[i].x = (prexy[i].x - 29) / 2;
		prexy[i].y -= 1;
		map[prexy[i].y][prexy[i].x] = 4;
		prexy[i].x = 50;
		prexy[i].y = 30;
	}
}
int checkline(int* level, int* combo, int level_line[10]) {
	int i, j, k, l, ck = 0, cnt = 0, TheEnd = 0;
	for (j = 1; j < 11; j++) {
		if (map[6][j] == 4)
			ckGameEnd++;
	}
	if (ckGameEnd > 0) {
		system("cls");
		return 0;
	}
	for (i = 23; i >= 5; i--) {
		for (j = 1; j < 11; j++) {
			if (map[i][j] == 4)
				ck++;
		}
		if (ck == 10) {
			for (k = i; k >= 5; k--) {
				for (j = 1; j < 11; j++) {
					map[k][j] = 0;
					map[k][j] = map[k - 1][j];
				}
			}
			cnt++; i++; *combo += 1;
		}
		ck = 0;
	}
	if (cnt == 0)
		*combo = 1;
	if (cnt == 1)
		score += *level * 100 * *combo;
	if (cnt == 2)
		score += *level * 250 * *combo;
	if (cnt == 3)
		score += *level * 500 * *combo;
	if (cnt == 4)
		score += *level * 1000 * *combo;
	for (i = 0; i < cnt; i++) {
		level_line[*level] -= 1;
		if (level_line[*level] == 0) {
			*level += 1;
			if (*level == 11) {
				TheEnd = 1;
				break;
			}
			gotoxy(34, 4);
			printf("!!LEVEL UP!!");
			gotoxy(34, 5);
			printf("!!LEVEL UP!!");
			Sleep(800);
			gotoxy(34, 4);
			printf(" . . . . . .");
			gotoxy(34, 5);
			printf(" . . . . . .");
			Sleep(500);
			gotoxy(34, 4);
			printf("!!LEVEL UP!!");
			gotoxy(34, 5);
			printf("!!LEVEL UP!!");
			Sleep(800);
			gotoxy(34, 4);
			printf(" . . . . . .");
			gotoxy(34, 5);
			printf(" . . . . . .");
			while (kbhit())
				trash = getch();
		}
		else {
			if (i == cnt - 1) {
				Sleep(350);
				while (kbhit())
					trash = getch();
			}
		}
	}
	return TheEnd;
}
void title(int bestscore) {
	gotoxy(1, 29);
	printf(" ver 2.0");
	gotoxy(65, 29);
	printf("made by ParkShinBeen");
	gotoxy(21, 9);
	textcolor(2);
	printf("¢Ã¢Ã¢Ã  ¢Ã¢Ã¢Ã  ¢Ã¢Ã¢Ã  ¢Ã¢Ã     ¢Ã   ¢Ã¢Ã¢Ã");
	gotoxy(21, 10);
	printf("  ¢Ã    ¢Ã        ¢Ã    ¢Ã  ¢Ã   ¢Ã   ¢Ã");
	gotoxy(21, 11);
	printf("  ¢Ã    ¢Ã¢Ã¢Ã    ¢Ã    ¢Ã¢Ã     ¢Ã   ¢Ã¢Ã¢Ã");
	gotoxy(21, 12);
	printf("  ¢Ã    ¢Ã        ¢Ã    ¢Ã  ¢Ã   ¢Ã       ¢Ã");
	gotoxy(21, 13);
	printf("  ¢Ã    ¢Ã¢Ã¢Ã    ¢Ã    ¢Ã  ¢Ã   ¢Ã   ¢Ã¢Ã¢Ã");
	textcolor(7);
	gotoxy(39, 17);
	printf("Best Score");
	gotoxy(39, 19);
	printf("%10d", bestscore);
	gotoxy(33, 21);
	textcolor(3);
	printf("PRESS ANY KEY TO START");
	textcolor(7);
	while (1) {
		if (kbhit()) {
			getch();
			return;
		}
	}
}
int harddrop(int idxx, int idxy, int turncnt, int curblock) {
	int p = 41, q = 1, i, check = 0;
	p += idxx; q += idxy;
	while (1) {
		for (i = 0; i < 4; i++)
			check += detectbottomwall(p + blockpos[curblock][turncnt][i].x, q + blockpos[curblock][turncnt][i].y);
		if (check < 4) {
			ck = 1;
			return idxy - 1;
		}
		else
			check = 0; q++; idxy += 1;
	}
}
int again() {
	int key;
	gotoxy(38, 13);
	printf("Try Again?");
	gotoxy(35, 16);
	printf("Yes : Y / No : N");
	while (1) {
		if (kbhit()) {
			key = getch();
			if (key == 'Y' || key == 'y')
				return 1;
			else if (key == 'N' || key == 'n')
				return 0;
		}
	}
}
void savescore(int* bestscore, int score) {
	int tempbestscore;
	FILE* fp;
	if (*bestscore < score)
		*bestscore = score;
	fp = fopen("score.txt", "r");
	if (fp == NULL) {
		fp = fopen("score.txt", "w");
		fclose(fp);
		fp = fopen("score.txt", "r");
	}
	fscanf(fp, "%d", &tempbestscore);
	fclose(fp);
	if (tempbestscore > *bestscore)
		*bestscore = tempbestscore;
	else {
		fp = fopen("score.txt", "w");
		fprintf(fp, "%d", *bestscore);
		fclose(fp);
	}
	return;
}
void printEnd(int bestscore) {
	system("cls");
	savescore(&bestscore, score);
	printf("Congratulations!!");
	Sleep(650);
	printf("Thanks for Playing Tetris");
	Sleep(650);
	printf("~~BYE BYE~~");
}


int main() {
	system("mode con cols=85 lines=30");
	cursor(0);
	setblockpos();
	srand(time(NULL));
	int curblock, nextblock = rand() % 7, idxx = 0, idxy = 0, key, turncnt = 0, p = 41, q = 1, i, check = 0, ckharddrop = 0, quit = 0, n, j;
	int level = 0, level_speed[] = { 0, 100, 175, 250, 300, 360, 410, 460, 500, 550 };
	int level_line[] = { 2, 3, 5, 8, 12, 17, 23, 29, 35, 25 }, bestscore = 0, ckagain = 0, TheEnd = 0, combo = 1, tempbestscore;
	int startTickCount, printTickCount;
	while (1) {
		savescore(&bestscore, score);
		title(bestscore);
		quit = 0; ckharddrop = 0; ck = 0;
		ckGameEnd = 0; idxx = 0; idxy = 0; turncnt = 0;
		level = 0; n = 0;
		setlevel_line(level_line);
		setmap();
		system("cls");
		while (1) {
			gotoxy(2, 28);
			printf("Made By\n Park Shin Been");
			output();
			curblock = nextblock;
			nextblock = rand() % 7;
			printnextblock(nextblock);
			printhelp(level + 1, level_line[level], &bestscore);
			printblock(curblock, &idxx, idxy, turncnt);
			startTickCount = printTickCount = GetTickCount();
			while (1) {
				if (GetTickCount() - startTickCount >= 650 - level_speed[level]) {
					startTickCount = GetTickCount();
					printblock(curblock, &idxx, ++idxy, turncnt);
				}
				else {
					if (GetTickCount() - printTickCount >= 20) {
						printTickCount = GetTickCount();
						if (kbhit()) {
							key = getch();
							if (key == 'P' || key == 'p') {
								system("pause>null");
							}
							else if (key == 27) {
								quit = 1;
								break;
							}
							else if (key == 32) {
								ckharddrop = 1;
								ck = 1;
								idxy = harddrop(idxx, idxy, turncnt, curblock);
								eraseblock();
								p += idxx; q += idxy;
								switch (curblock) {
								case 0: textcolor(11); break;
								case 1: textcolor(10); break;
								case 2: textcolor(12); break;
								case 3: textcolor(14); break;
								case 4: textcolor(6); break;
								case 5: textcolor(9); break;
								case 6: textcolor(13); break;
								}
								for (i = 0; i < 4; i++) {
									gotoxy(p + blockpos[curblock][turncnt][i].x, q + blockpos[curblock][turncnt][i].y);
									prexy[i].x = p + blockpos[curblock][turncnt][i].x;
									prexy[i].y = q + blockpos[curblock][turncnt][i].y;
									printf("¡á");
								}
								textcolor(7);
								p = 41; q = 1;
							}
							else if (key == 224) {
								key = getch();
								if (key == left) {
									idxx -= 2;
									p += idxx; q += idxy;
									for (i = 0; i < 4; i++) {
										if (map[q + blockpos[curblock][turncnt][i].y - 1][(p + blockpos[curblock][turncnt][i].x - 29) / 2] != 0)
											check++;
									}
									if (check > 0)
										idxx += 2;
									check = 0; p = 41; q = 1;
								}
								else if (key == right) {
									idxx += 2;
									p += idxx; q += idxy;
									for (i = 0; i < 4; i++) {
										if (map[q + blockpos[curblock][turncnt][i].y - 1][(p + blockpos[curblock][turncnt][i].x - 29) / 2] != 0)
											check++;
									}
									if (check > 0)
										idxx -= 2;
									check = 0; p = 41; q = 1;
								}
								else if (key == down) {
									idxy += 1;
								}
								else if (key == up) {
									turncnt++;
									rotateblock(&idxx, idxy, &turncnt, curblock);
								}
							}
						}
						if (ckharddrop == 0)
							printblock(curblock, &idxx, idxy, turncnt);
					}

				}
				if (ck == 1) {
					putdata();
					score += (level + 1) * 10;
					break;
				}
				ck = 0;
			}
			if (quit == 1) {
				system("cls");
				gotoxy(39, 14);
				printf("~Bye Bye~");
				gotoxy(29, 20);
				system("pause>null");
				return 0;
			}
			TheEnd = checkline(&level, &combo, level_line);
			if (TheEnd == 1)
				break;
			if (ckGameEnd > 0) {
				ckGameEnd = 0;
				if (bestscore < score)
					bestscore = score;
				score = 0;
				ckagain = again();
				system("cls");
				if (ckagain == 1) {
					ckagain = 0;
					break;
				}
				else {
					savescore(&bestscore, score);
					gotoxy(39, 14);
					printf("~Bye Bye~");
					gotoxy(29, 20);
					system("pause>null");
					return 0;
				}
			}
			ck = 0;
			idxx = 0;
			idxy = 0;
			turncnt = 0;
			ckharddrop = 0;
		}
		if (TheEnd == 1)
			break;
	}
	printEnd(bestscore);
	return 0;
}
