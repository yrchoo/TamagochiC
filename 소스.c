//1991336 추예린
//다마고치 게임
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h> 
#include <ctype.h>

#define ROWS 25
#define COLS 50
// text color define
// 색상 정의
#define BLACK   0
#define BLUE1   1
#define GREEN1   2
#define CYAN1   3
#define RED1   4
#define MAGENTA1 5
#define YELLOW1   6
#define GRAY1   7
#define GRAY2   8
#define BLUE2   9
#define GREEN2   10
#define CYAN2   11
#define RED2   12
#define MAGENTA2 13
#define YELLOW2   14
#define WHITE   15

#define SPECIAL1 0xe0 // 특수키는 0xe0 + key 값으로 구성된다.
#define SPECIAL2 0x00 // keypad 경우 0x00 + key 로 구성된다.

#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d

int Delay = 500;
int ani = 0;
int FOOD = 10, ENERGY = 10, LOVE = 1, GOLD = 0, DEATH = 0;
int be_lv1 = 0, be_lv2 = 0;

void removeCursor(void) { // 커서를 안보이게 한다

	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void gotoxy(int x, int y){
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
// 문자의 color 설정, foreground | background
void textcolor(int color, int bgcolor){
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}
// 화면 clear
// 화면 지우기고 원하는 배경색으로 설정한다.
void cls(int text_color, int bg_color){
	char cmd[100];
	system("cls");
	sprintf(cmd, "COLOR %x%x", bg_color, text_color);
	system(cmd);
}
void draw_box(int x1, int y1, int x2, int y2, char *ch)
{
	int x, y;
	for (y = y1; y <= y2; y++) {
		if (y == y1 || y == y2)
			for (int x = x1; x <= x2; x += 2) {
				gotoxy(x, y);
				printf("%s", ch);
			}
		else {
			gotoxy(x1, y);
			printf("%s", ch);
			gotoxy(x2, y);
			printf("%s", ch);
		}
	}
}
void clear_box() {
	for (int i = 0; i < ROWS; i++) {
		gotoxy(26, 1 + i);
		printf("                                                 ");
	}
}
void clear(int x1, int y1, int x2, int y2) {
	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			gotoxy(j, i);
			printf(" ");
		}
	}
}
void get_name(char name[]) {
	cls(BLACK, GRAY1);
	draw_box(24, 0, 76, 26, "▒");
	gotoxy(38, 8);
	printf("이름을 입력해주세요.(Enter입력)");
	gotoxy(38, 19);
	printf("(한글 5자, 영어 10자)");
	gotoxy(38, 12);
	printf("_________________");
	gotoxy(38, 12);
	scanf("%s", name);
}
int start_screen(char name[]) {
	draw_box(0, 0, 102, 26, "▒");
	gotoxy(38, 8);
	textcolor(GRAY1, BLACK);
	printf("  ★추억의 다마고치 게임★  ");
	textcolor(BLACK, GRAY1);
	gotoxy(46, 16); 
	printf("  시작하기  ");
	gotoxy(46, 18);
	printf("   나가기    ");
	gotoxy(3, 24);
	printf("←→ 이동\n");
	gotoxy(3, 25);
	printf("↓ 선택");
	int ch;
	int i = 0;
	int x = 46, y = 16;
	while (1) {
		if (kbhit() == 1) {
			ch = getch();
			gotoxy(x, y);
			printf("  ");
			gotoxy(x + 10, y);
			printf("  ");
			if (ch == SPECIAL1 || SPECIAL2) {
				ch = getch();
				switch (ch) {
				case DOWN:
					if (y = 16) {
						get_name(name);
						return 1;
					}
					else {
						return 0;
					}
				case RIGHT:
					if (y == 16)
						y = 18;
					else y = 16;
					break;
				case LEFT:
					if (y == 16)
						y = 18;
					else y = 16;
					break;
				}
			}
		}
		if (i % 2 == 0) {
			gotoxy(x, y);
			printf("▶");
			gotoxy(x + 10, y);
			printf("◀");
		}
		else {
			gotoxy(x, y);
			printf("▷");
			gotoxy(x + 10, y);
			printf("◁");
		}
		i++;
		Sleep(Delay);
	}
}

void level0() {
	char lv00[ROWS - 8][COLS] = {
		"                    ■■■■■",
		"                  ■          ■",
		"                ■              ■",
		"              ■                  ■",
		"              ■                  ■",
		"            ■                      ■",
		"            ■      ■■■■        ■",
		"          ■        ■      ■        ■",
		"          ■        ■      ■        ■",
		"          ■        ■■■■          ■",
		"          ■        ■    ■          ■",
		"          ■        ■      ■        ■",
		"          ■        ■      ■        ■",
		"          ■                          ■",
		"            ■                      ■",
		"              ■                  ■",
		"                ■■■■■■■■■"
	};
	char lv00_2[ROWS - 7][COLS] = {
		"                    ■■■■■",
		"                  ■          ■",
		"                ■              ■",
		"              ■                  ■",
		"              ■                  ■",
		"            ■                      ■",
		"            ■      ■■■■        ■",
		"          ■        ■      ■        ■",
		"          ■        ■      ■        ■",
		"          ■        ■■■■          ■",
		"          ■        ■    ■          ■",
		"          ■        ■      ■        ■",
		"          ■        ■      ■        ■",
		"          ■                          ■",
		"          ■                          ■",
		"            ■                      ■",
		"              ■                  ■",
		"                ■■■■■■■■■"
	};
	clear_box();
	if (ani % 4 == 0 || ani % 4 == 1)
		for (int i = 0; i < ROWS - 8; i++) {
			gotoxy(26, 9 + i);
			printf("%s", lv00[i]);
		}
	else
		for (int i = 0; i < ROWS - 7; i++) {
			gotoxy(26, 8 + i);
			printf("%s", lv00_2[i]);
		}
}
void level1() {
	char lv01[ROWS - 10][COLS] = {
		"                  ■■■■■■■                 ",
		"                ■              ■               ",
		"              ■                  ■             ",
		"            ■                      ■           ",
		"          ■                          ■         ",
		"          ■                          ■         ",
		"        ■                              ■       ",
		"        ■                              ■       ",
		"        ■                              ■       ",
		"      ■                                  ■     ",
		"      ■                                  ■     ",
		"      ■                                  ■     ",
		"      ■                                  ■     ",
		"        ■                              ■       ",
		"          ■■■■■■■■■■■■■■■         "
	};
	char lv01_2[ROWS - 9][COLS] = {
		"                  ■■■■■■■                 ",
		"                ■              ■               ",
		"              ■                  ■             ",
		"            ■                      ■           ",
		"          ■                          ■         ",
		"          ■                          ■         ",
		"        ■                              ■       ",
		"        ■                              ■       ",
		"        ■                              ■       ",
		"      ■                                  ■     ",
		"      ■                                  ■     ",
		"      ■                                  ■     ",
		"      ■                                  ■     ",
		"      ■                                  ■     ",
		"        ■                              ■       ",
		"          ■■■■■■■■■■■■■■■         "
	};
	clear_box();
	if (ani % 4 == 0 || ani % 4 == 1)
		for (int i = 0; i < ROWS - 10; i++) {
			gotoxy(26, 11 + i);
			printf("%s", lv01[i]);
		}
	else
		for (int i = 0; i < ROWS - 9; i++) {
			gotoxy(26, 10+ i);
			printf("%s", lv01_2[i]);
		}
}
void level2() {
	char lv02[ROWS - 6][COLS] = {
		"          ■■                      ■■",
		"          ■  ■                  ■  ■",
		"          ■    ■              ■    ■",
		"          ■      ■          ■      ■",
		"          ■      ■■■■■■■      ■         ",
		"          ■    ■              ■    ■         ",
		"  ■      ■  ■                  ■  ■         ",
		"    ■    ■■                      ■■         ",
		"      ■  ■                          ■         ",
		"      ■  ■                          ■         ",
		"    ■  ■                              ■       ",
		"  ■    ■    ■■              ■■    ■       ",
		"  ■    ■        ■          ■        ■       ",
		"    ■■          ■          ■          ■     ",
		"      ■                                  ■     ",
		"      ■                                  ■     ",
		"      ■                                  ■     ",
		"        ■                              ■       ",
		"          ■■■■■■■■■■■■■■■         "
	};
	char lv02_2[ROWS - 5][COLS] = {
		"          ■■                      ■■",
		"          ■  ■                  ■  ■",
		"          ■    ■              ■    ■",
		"          ■      ■          ■      ■",
		"          ■      ■■■■■■■      ■         ",
		"          ■    ■              ■    ■         ",
		"      ■  ■  ■                  ■  ■         ",
		"    ■    ■■                      ■■         ",
		"  ■      ■                          ■         ",
		"  ■      ■                          ■         ",
		"    ■  ■                              ■       ",
		"      ■■    ■■              ■■    ■       ",
		"      ■■        ■          ■        ■       ",
		"    ■■          ■          ■          ■     ",
		"      ■                                  ■     ",
		"      ■                                  ■     ",
		"      ■                                  ■     ",
		"      ■                                  ■     ",
		"        ■                              ■       ",
		"          ■■■■■■■■■■■■■■■         "
	};
	clear_box();
	if (ani % 4 == 0 || ani % 4 == 1)
		for (int i = 0; i < ROWS - 6; i++) {
			gotoxy(26, 7 + i);
			printf("%s", lv02[i]);
		}
	else
		for (int i = 0; i < ROWS - 5; i++) {
			gotoxy(26, 6 + i);
			printf("%s", lv02_2[i]);
		}
}
void face1() {
	char happy[3][20] = {
		"  ■      ■",
		"■          ■",
		"  ■■■■■"
	};
	char sad[3][20] = {
		"  ■      ■",
		"          ",
		"  ■■■■■"
	};
	if (ani % 4 == 0 || ani % 4 == 1)
		if (FOOD < 4 || ENERGY < 4) {
			for (int i = 0; i < 3; i++) {
				gotoxy(49, 15 + i);
				printf("%s", sad[i]);
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				gotoxy(44, 15 + i);
				printf("%s", happy[i]);
			}
		}
	else {
		if (FOOD < 4 || ENERGY < 4) {
			for (int i = 0; i < 3; i++) {
				gotoxy(49, 14 + i);
				printf("%s", sad[i]);
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				gotoxy(44, 14 + i);
				printf("%s", happy[i]);
			}
		}
	}
}
void face2() {
	char happy[3][20] = {
		"  ■      ■",
		"■    ■    ■",
		"  ■■  ■■"
	};
	char sad[3][20] = {
		"  ■      ■",
		"      ■    ",
		"  ■■  ■■"
	};
	if (ani % 4 == 0 || ani % 4 == 1)
		if (FOOD < 4 || ENERGY < 4) {
			for (int i = 0; i < 3; i++) {
				gotoxy(49, 15 + i);
				printf("%s", sad[i]);
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				gotoxy(44, 15 + i);
				printf("%s", happy[i]);
			}
		}
	else {
		if (LOVE < 4 || FOOD < 4 || ENERGY < 4) {
			for (int i = 0; i < 3; i++) {
				gotoxy(49, 14 + i);
				printf("%s", sad[i]);
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				gotoxy(44, 14 + i);
				printf("%s", happy[i]);
			}
		}
	}
}
void BAD_ENDING(char name[]) {
	clear_box();
	char bad[22][100] = {
		"          ■■■■",
		"        ■        ■",
		"          ■■■■",
		" ",
		"          ■■■■",
		"      ■■        ■",
		"    ■              ■",
		"    ■    ■    ■  ■",
		"  ■    ■        ■  ■",
		"  ■      ■■■■    ■",
		"  ■                  ■",
		"  ■                  ■",
		"  ■                  ■",
		"  ■                  ■",
		"  ■                  ■",
		"    ■                ■",
		"      ■            ■",
		"      ■            ■",
		"        ■        ■",
		"          ■    ■",
		"          ■  ■",
		"            ■"
	};
	for (int i = 0; i < 22; i++) {
		gotoxy(38, 2+i);
		printf("%s", bad[i]);
	}
	gotoxy(26, 24);
	if (FOOD == 0) {
		printf("%s는 허기를 이기지 못하고", name);
		gotoxy(26, 25);
		printf("세상을 떴습니다...");
	}
	else if (ENERGY == 0) {
		printf("%s는 피로에 잠겨", name);
		gotoxy(26, 25);
		printf("눈을 다시 뜨지 못하게 되었습니다...");
	}
	else if (LOVE == 0) {
		printf("%s는 당신의 애정을 갈망하다", name);
		gotoxy(26, 25);
		printf("외로이 죽게 되었습니다...");
	}
	gotoxy(0, 27);
	exit(1);
}
void ENDING(char name[]) {
	char end[ROWS - 6][COLS] = {
		"          ■■                      ■■",
		"          ■  ■                  ■  ■",
		"          ■    ■              ■    ■",
		"          ■      ■          ■      ■",
		"          ■      ■■■■■■■      ■",
		"          ■    ■              ■    ■",
		"  ■      ■  ■                  ■  ■  ■■",
		"    ■    ■■      ■      ■      ■■■    ■",
		"      ■  ■      ■    ■    ■      ■      ■",
		"      ■  ■        ■■  ■■                ■",
		"    ■  ■                                  ■",
		"  ■    ■    ■■                        ■",
		"  ■    ■        ■                      ■",
		"    ■■          ■                      ■",
		"      ■                                  ■",
		"      ■                                  ■",
		"      ■                                  ■",
		"        ■                              ■",
		"          ■■■■■■■■■■■■■■■"
	};
	char end2[ROWS - 6][COLS] = {
		"          ■■                      ■■",
		"          ■  ■                  ■  ■",
		"          ■    ■              ■    ■",
		"          ■      ■          ■      ■",
		"          ■      ■■■■■■■      ■",
		"          ■    ■              ■    ■",
		"  ■      ■  ■                  ■  ■  ",
		"    ■    ■■      ■      ■      ■■ ",
		"      ■  ■      ■    ■    ■      ■■■■",
		"      ■  ■        ■■  ■■                ■",
		"    ■  ■                                    ■",
		"  ■    ■    ■■                          ■",
		"  ■    ■        ■                      ■",
		"    ■■          ■                      ■",
		"      ■                                  ■",
		"      ■                                  ■",
		"      ■                                  ■",
		"        ■                              ■",
		"          ■■■■■■■■■■■■■■■"
	};
	while (1) {
		clear_box();
		gotoxy(28, 2);
		printf("%s는 자라서 멋진 고양이가 되었습니다!", name);
		gotoxy(28, 3);
		printf("%s는 이제 독립합니다.", name);
		gotoxy(28, 4);
		printf("언젠간 다시 만나요 안녕!");
		if (ani % 2 == 0) {
			for (int i = 0; i < ROWS - 6; i++) {
				gotoxy(26, 7 + i);
				printf("%s", end[i]);
			}
		}
		else {
			for (int i = 0; i < ROWS - 6; i++) {
				gotoxy(26, 7 + i);
				printf("%s", end2[i]);
			}
		}
		ani++;
		Sleep(Delay);
	}
}
void PrintInfo(char name[]) {
	if (ENERGY > 10)
		ENERGY = 10;
	if (FOOD > 10)
		FOOD = 10;
	if (ENERGY <= 0) {
		DEATH++;
		ENERGY = 0;
	}
	if (FOOD <= 0) {
		DEATH++;
		FOOD = 0;
	}
	if (LOVE <= 0) {
		DEATH++;
		LOVE = 0;
	}
	if (LOVE > 0 && ENERGY > 0 && FOOD > 0)
		DEATH = 0;
	gotoxy(78, 2);
	printf("{%s}", name);
	gotoxy(78, 4);
	printf("<체력>");
	gotoxy(78, 5);
	for (int i = 0; i < ENERGY / 2; i++)
		printf("♥");
	for (int i = 0; i < 5 - ENERGY / 2; i++)
		printf("♡");
	gotoxy(78, 7);
	printf("<포만감>");
	gotoxy(78, 8);
	for (int i = 0; i < FOOD / 2; i++)
		printf("★");
	for (int i = 0; i < 5 - FOOD / 2; i++)
		printf("☆");
	gotoxy(78, 10);
	printf("<소지금> %4d GOLD", GOLD);
}

void EAT() {
	if (FOOD == 10) {
		gotoxy(30, 4);
		printf("배가 안고파요..ㅜㅜ");
		return;
	}
	if (GOLD - 50 < 0) {
		gotoxy(30, 4);
		printf("돈이 없어요..ㅜㅜ");
		return;
	}
	char eat00[ROWS - 8][COLS] = {
		"                      ■",
		"                  ■    ■      ■",
		"                    ■    ■  ■",
		"                  ■    ■      ■",
		"                    ■        ■",
		"                      ■■■",
		"                  ■■■■■■■",
		"                ■  ■■■■■  ■",
		"              ■■              ■■",
		"            ■    ■      ■■■    ■",
		"            ■      ■■■          ■",
		"          ■                          ■",
		"      ■■■                          ■■■",
		"    ■  ■                              ■  ■",
		"  ■    ■■■■■■■■■■■■■■■■■    ■",
		"    ■                                      ■",
		"      ■■■■■■■■■■■■■■■■■■■"
	};
	char eat01[ROWS - 8][COLS] = {
		"                   ■  ■      ■",
		"                  ■      ■  ■",
		"                    ■  ■      ■",
		"                        ■    ■",
		" ",
		"                      ■■■",
		"                  ■■■■■■■",
		"                ■  ■■■■■  ■",
		"              ■■              ■■",
		"            ■    ■      ■■■    ■",
		"            ■      ■■■          ■",
		"          ■                          ■",
		"      ■■■                          ■■■",
		"    ■  ■                              ■  ■",
		"  ■    ■■■■■■■■■■■■■■■■■    ■",
		"    ■                                      ■",
		"      ■■■■■■■■■■■■■■■■■■■"
	};
	int num = rand() % 5;
	for (int i = 0; i < 4; i++) {
		clear_box();
		gotoxy(30, 4);
		switch (num) {
		case 0:
			printf("너무 맛있어요!");
			break;
		case 1:
			printf("웩.. 이게 뭐죠?");
			break;
		case 2:
		case 3:
		case 4:
			printf("냠냠...");
			break;
		}
		if (i % 2 == 0)
			for (int i = 0; i < ROWS - 8; i++) {
				gotoxy(26, 6 + i);
				printf("%s", eat00[i]);
			}
		else
			for (int i = 0; i < ROWS - 8; i++) {
				gotoxy(26, 6 + i);
				printf("%s", eat01[i]);
			}
		Sleep(Delay * 2);
	}
	switch (num) {
	case 0:
		FOOD += 4; LOVE += 3; break;
	case 1:
		FOOD--; break;
	case 2:
	case 3:
	case 4:
		FOOD+=2; LOVE++; break;
	}
	GOLD -= 50;
}

void SLEEP() {
	if (FOOD == 0) {
		gotoxy(30, 4);
		printf("배고파서 잠이 안와요..ㅜㅜ");
		return;
	}
	if (ENERGY == 10) {
		gotoxy(30, 4);
		printf("안 피곤해요!");
		return;
	}
	char sleep00[ROWS - 4][COLS] = {
		"                      ■■■■■■",
		"                    ■            ■■",
		"          ■      ■                  ■",
		"                ■                      ■",
		"                ■  ■■■■■            ■",
		"    ■            ■          ■            ■",
		"  ■■■                        ■  ■      ■",
		"    ■                          ■  ■      ■",
		"          ■      ■            ■      ■  ■",
		"                ■  ■          ■■■■    ■",
		"                ■    ■      ■            ■",
		"                ■      ■■■              ■",
		"      ■        ■                          ■",
		"                ■                        ■",
		"                  ■                    ■",
		"                    ■              ■■    ■",
		"            ■        ■■■■■■■      ■■■",
		"                                            ■"
	};
	char sleep00_2[ROWS - 4][COLS] = {
		"                      ■■■■■■          ■",
		"                    ■            ■■    ■■■",
		"          ■      ■                  ■    ■",
		"                ■                      ■",
		"                ■  ■■■■■            ■",
		"                  ■          ■            ■",
		"    ■                          ■  ■      ■",
		"          ■                    ■  ■      ■",
		"        ■■■    ■            ■      ■  ■",
		"          ■    ■  ■          ■■■■    ■",
		"                ■    ■      ■            ■",
		"                ■      ■■■              ■",
		"      ■        ■                          ■",
		"                ■                        ■",
		"                  ■                    ■",
		"                    ■              ■■    ",
		"            ■        ■■■■■■■        ■",
		"                                            "
	};
	int num = rand() % 5;
	for (int i = 0; i < 4; i++) {
		clear_box();
		gotoxy(30, 4);
		switch (num) {
		case 0:
			printf("으으..(악몽 꾸는 중)");
			break;
		case 1:
		case 2:
		case 3:
		case 4:
			printf("Zzz...");
			break;
		}
		if (i % 2 == 0)
			for (int i = 0; i < ROWS - 4; i++) {
				gotoxy(26, 6 + i);
				printf("%s", sleep00[i]);
			}
		else
			for (int i = 0; i < ROWS - 4; i++) {
				gotoxy(26, 6 + i);
				printf("%s", sleep00_2[i]);
			}
		Sleep(Delay * 2);
	}
	switch (num) {
	case 0:
		ENERGY++;
		LOVE++;
		FOOD -= 3;
		break;
	case 1:
	case 2:
	case 3:
	case 4:
		ENERGY+=5;
		FOOD -= 3;
		LOVE++;
		break;
	}
	
}

void JUMP(int f) {
	char jump0[6][13] = {
		"            ",
		"    ■■",
		"  ■    ■",
		"■    ■  ■",
		"■        ■",
		"  ■■■■  ",
	};
	char jump1[6][13] = {
		"            ",
		"  ■■■■  ",
		"■        ■",
		"■    ■  ■",
		"■        ■",
		"  ■■■■",
	};
	char jump2[6][13] = {
		"    ■■    ",
		"  ■    ■",
		"■    ■  ■",
		"■        ■",
		"  ■    ■",
		"    ■■"
	};
	clear(28, 15, 41, 25);
	switch (f % 15) {
	case 0:
		for (int i = 0; i < 6; i++) {
			gotoxy(28, 20 + i);
			printf("%s", jump0[i]);
		}
		break;
	case 1: case 2: case 3: case 4:  case 10: case 11: case 12:
		for (int i = 0; i < 6; i++) {
			gotoxy(28, 17 + i);
			printf("%s", jump1[i]);
		}
		break;
	 case 5: case 6: case 7: case 8: case 9:
		for (int i = 0; i < 6; i++) {
			gotoxy(28, 15 + i);
			printf("%s", jump2[i]);
		}
		break;
	}
}
int OBS(int r) {
	int last = 0;
	char obs[3][100] = {
		"  ■",
		"■■■",
		"  ■"
	};
	char obs2[3][100] = {
		"■",
		"■■",
		"■"
	};
	char obs3[3][100] = {
		" ",
		"■",
		" "
	};

	if ((r == 0) || (r == 44) || (r == 46)) {
		clear(68 - 42 + 2, 23, 68 - 42 + 3, 23);
		clear(68 - 42, 24, 68 - 42 + 5, 24);
		clear(68 - 42 + 2, 25, 68 - 42 + 4, 25);
	}
	else clear(68 - r + 2, 23, 68 - r + 8, 25);
	if (r == 44) {
		for (int i = 0; i < 3; i++) {
			gotoxy(68 - 42, 23 + i);
			printf("%s", obs2[i]);
		}
		return 28;
	}
	else if (r == 46) {
		for (int i = 0; i < 3; i++) {
			gotoxy(68 - 42, 23 + i);
			printf("%s", obs3[i]);
		}
		return 26;
	}
	else {
		for (int i = 0; i < 3; i++) {
			gotoxy(68 - r, 23 + i);
			printf("%s", obs[i]);
		}
		return 70 - r;
	}
	
}
void MINI_GAME() {
	ani = 0;
	clear_box();
	clock_t start = 0, now = 0;
	int ch;
	int r = 0;
	int run = 0, speed = 100;
	int score;
	int jumping = 0, up = 1, down = 0;
	start = clock();
	while (1) {
		now = clock();
		score = 10 * ((now - start) / CLOCKS_PER_SEC);
		gotoxy(60, 2);
		printf("SCORE : %5d", score);
		if ((kbhit() == 1) && (jumping == 0)) {
			ch = getch();
			if (ch == SPECIAL1 || SPECIAL2) {
				ch = getch();
				if (ch == DOWN) {
					jumping = 1;
				}
			}
		}
		if (jumping == 1) {
			ani++;
			if (ani == 12) {
				ani = 0;
				jumping = 0;
			}
		}
		JUMP(ani);
		int range = OBS(r);
		if (range >= 28 && range <= 40) {
			if (jumping == 0)
				break;
		}
		r+=2;
		if (r > 46) r = 0;
		Sleep(speed);
		run += 1;
		if (run > 46) {
			run = 0;
			speed = 100;
			speed /= (rand() % 5 + 1);
		}
	}
	clear_box();
	GOLD += score;
	ENERGY -= 2;
	FOOD -= 2;
	LOVE += score / 50;
	ENERGY-= score / 100;
	FOOD -= score / 100;
	gotoxy(42, 8);
	printf("  ★GAME OVER★  ");
	gotoxy(42, 15);
	printf("획득한 GOLD :%4d", score);
	gotoxy(42, 16);
	printf("↓키를 눌러주세요. . .");
	getch(); getch();
	getch(); getch();
}
void OH(name) {
	int i = 0;
	while (i<4) {
		clear_box();
		gotoxy(28, 11);
		if (ani % 2 == 0)
			printf("☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆");
		else
			printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★");
		gotoxy(28, 13);
		printf("  우와");
		gotoxy(28, 14);
		printf("  %s가 성장했다...!", name);
		gotoxy(28, 16);
		if (ani % 2 == 0)
			printf("☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆");
		else
			printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★");
		i++;
		ani++;
		Sleep(Delay);
	}
	clear_box();
}

void main_game(char name[]) {
	cls(BLACK, GRAY1);
	draw_box(24, 0, 76, 26, "▒");//메인화면
	draw_box(3, 0, 19, 10, "▒");
	gotoxy(5, 2);
	printf("    밥주기");
	gotoxy(5, 4);
	printf("    잠자기");
	gotoxy(5, 6);
	printf("   미니게임");
	gotoxy(5, 8);
	printf("   종료하기");

	int ch;
	int i = 0;
	int x = 5, y = 2;
	while (1) {
		PrintInfo(name);
		if (LOVE > 80) {
			ENDING(name);
		}
		if (DEATH >= 10) {
			BAD_ENDING(name);
		}
		if (LOVE > 50) {
			if (be_lv2 == 0) {
				OH(name);
				be_lv2 = 1;
			}
			level2();
			face2();
		}
		else if (LOVE > 20) {
			if (be_lv1 == 0) {
				OH(name);
				be_lv1 = 1;
			}
			level1();
			face1();
		} 
		else
			level0();
		if (kbhit() == 1) {
			ch = getch();
			gotoxy(x, y);
			printf("  ");
			gotoxy(x + 12, y);
			printf("  ");
			if (ch == SPECIAL1 || SPECIAL2) {
				ch = getch();
				switch (ch) {
				case DOWN:
					switch (y) {
					case 2:
						EAT(); break;
					case 4:
						SLEEP(); break;
					case 6:
						MINI_GAME(); break;
					case 8:
						gotoxy(0, 27);
						exit(1);
					}
					break;
				case RIGHT:
					if (y == 8)
						y = 2;
					else y += 2;
					break;
				case LEFT:
					if (y == 2)
						y = 8;
					else y -= 2;
					break;
				}
			}
			else {
				switch (ch) {
				case 'e':
					ENERGY-=2; break;
				case 'f':
					FOOD-=2; break;
				case 'l':
					LOVE += 10; break;
				}
			}
		}
		if (i % 2 == 0) {
			gotoxy(x, y);
			printf("▶");
			gotoxy(x + 12, y);
			printf("◀");
		}
		else {
			gotoxy(x, y);
			printf("▷");
			gotoxy(x + 12, y);
			printf("◁");
		}
		ani++;
		i++;
		Sleep(Delay);
	}
}

int main() {
	srand(time(NULL));
	removeCursor();
	char name[16];
	system("title Damagochi");
	system("mode con: cols=104 lines=32");
	cls(BLACK, GRAY1);
	if (!start_screen(name)) {
		gotoxy(0, 27);
		exit(1);
	}
	main_game(name);
}