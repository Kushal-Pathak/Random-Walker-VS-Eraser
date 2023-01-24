// Random Walker vs Eraser By Kushal Pathak
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#define h 25
#define w 25
#define path 'X'
#define no_path ' '
char left = '<', right = '>', up = '^', down = 'v';
char walker = '>', eraser = 'O';
int wx = 12, wy = 12, ex = 13, ey = 12, edir = 3, wdir = 1, matrix[h][w];

void maximizeWindow();
void init();		// To fill matrix with empty spaces
void display();		// To display contents of matrix
void walk(float);	// To walk and erase in a random direction by one unit
void delay(float);	// To create delay
void random(float); // To generate a random direction

void main()
{
	// maximizeWindow();
	init();
	int i, n;
	float speed;
	printf("Random Walker vs Eraser By Kushal Pathak\nEnter steps (eg 1000): ");
	scanf("%d", &n);
	printf("Enter speed (eg 0.01): ");
	scanf("%f", &speed);
	for (i = 0; i <= n; i++)
	{
		display();
		printf("\n--------------------(Step %d)--------------------", i);
		walk(speed);
	}
	getch();
}
void init()
{
	srand(time(0));
	int i, j;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
			matrix[i][j] = ' ';
	}
	matrix[12][12] = path;
}
void walk(float speed)
{
	random(speed);
	switch (wdir)
	{
	case 0:
		wy = (wy + h - 1) % h;
		walker = up;
		break;
	case 1:
		wx = (wx + 1) % w;
		walker = right;
		break;
	case 2:
		wy = (wy + 1) % h;
		walker = down;
		break;
	case 3:
		wx = (wx + w - 1) % w;
		walker = left;
		break;
	}
	switch (edir)
	{
	case 0:
		ey = (ey + h - 1) % h;
		break;
	case 1:
		ex = (ex + 1) % w;
		break;
	case 2:
		ey = (ey + 1) % h;
		break;
	case 3:
		ex = (ex + w - 1) % w;
		break;
	}
	matrix[wy][wx] = path;
	matrix[ey][ex] = no_path;
}
void display()
{
	system("cls");
	int i, j;
	for (i = 0; i < h; i++)
	{
		printf("\n");
		for (j = 0; j < w; j++)
		{
			if (j == wx && i == wy || j == ex && i == ey)
			{
				if (ex == wx && ey == wy)
					printf("# ");
				else
				{
					if (j == wx && i == wy)
						printf("%c ", walker);
					if (j == ex && i == ey)
						printf("%c ", eraser);
				}
			}
			else
			{
				printf("%c ", matrix[i][j]);
			}
		}
	}
}
void delay(float n)
{
	int i, j, k;
	for (i = 0; i < 10000; i++)
	{
		for (j = 0; j < 500; j++)
		{
			for (k = 0; k < n * 100; k++)
				;
		}
	}
}
void random(float speed)
{
	wdir = rand() % 4;
	delay(speed);
	edir = rand() % 4;
}

void maximizeWindow()
{
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}
