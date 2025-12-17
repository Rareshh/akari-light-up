//Spinu Rares
#include <stdio.h>
#include "akari_headers.h"
#define NMAX 51

//Afisez matricea
void afisare(char grid[][NMAX], unsigned short n, unsigned short m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c ", grid[i][j]);
		}
		printf("\n");
	}
}

//Inlocuieste cu X fiecare element liber din calea luminii
void gridL(char grid[][NMAX], unsigned short i, unsigned short j)
{
	short k;
	k = i;
	while (grid[k + 1][j] == '-' || grid[k + 1][j] == 'x') {
		grid[k + 1][j] = 'x';
		k++;
	}

	k = i;
	while (grid[k - 1][j] == '-' || grid[k - 1][j] == 'x') {
		grid[k - 1][j] = 'x';
		k--;
	}

	k = j;
	while (grid[i][k + 1] == '-' || grid[i][k + 1] == 'x') {
		grid[i][k + 1] = 'x';
		k++;
	}

	k = j;
	while (grid[i][k - 1] == '-' || grid[i][k - 1] == 'x') {
		grid[i][k - 1] = 'x';
		k--;
	}
}

//Inlocuieste cu X fiecare element liber de langa un 0
void grid0(char grid[][NMAX], unsigned short i, unsigned short j)
{
	short dx[] = {-1, 1, 0, 0};
	short dy[] = {0, 0, -1, 1};

	for (int d = 0; d < 4; d++) {
		if (grid[i + dx[d]][j + dy[d]] == '-') {
			grid[i + dx[d]][j + dy[d]] = 'x';
		}
	}
}

//Inlocuieste cu X fiecare element liber de langa un 1, mai putin lumina
void grid1(char grid[][NMAX], unsigned short i, unsigned short j)
{
	short dx[] = {-1, 1, 0, 0};
	short dy[] = {0, 0, -1, 1};

	unsigned short count = 0;
	for (int d = 0; d < 4; d++) {
		if (grid[i + dx[d]][j + dy[d]] == 'L') {
			count++;
		}
	}
	if (count == 1) {
		for (int q = 0; q < 4; q++) {
			if (grid[i + dx[q]][j + dy[q]] != 'L') {
				if (grid[i + dx[q]][j + dy[q]] == '-') {
					grid[i + dx[q]][j + dy[q]] = 'x';
				}
			}
		}
	}
}

//Inlocuieste cu X fiecare element liber de langa un 2, mai putin lumina
void grid2(char grid[][NMAX], unsigned short i, unsigned short j)
{
	short dx[] = {-1, 1, 0, 0};
	short dy[] = {0, 0, -1, 1};

	unsigned short count = 0;
	for (int d = 0; d < 4; d++) {
		if (grid[i + dx[d]][j + dy[d]] == 'L') {
			count++;
		}
	}
	if (count == 2) {
		for (int q = 0; q < 4; q++) {
			if (grid[i + dx[q]][j + dy[q]] != 'L') {
				if (grid[i + dx[q]][j + dy[q]] == '-') {
					grid[i + dx[q]][j + dy[q]] = 'x';
				}
			}
		}
	}
}

//Inlocuieste cu X fiecare element liber de langa un 3, mai putin lumina
void grid3(char grid[][NMAX], unsigned short i, unsigned short j)
{
	short dx[] = {-1, 1, 0, 0};
	short dy[] = {0, 0, -1, 1};

	unsigned short count = 0;
	for (int d = 0; d < 4; d++) {
		if (grid[i + dx[d]][j + dy[d]] == 'L') {
			count++;
		}
	}
	if (count == 3) {
		for (int q = 0; q < 4; q++) {
			if (grid[i + dx[q]][j + dy[q]] != 'L') {
				if (grid[i + dx[q]][j + dy[q]] == '-') {
					grid[i + dx[q]][j + dy[q]] = 'x';
				}
			}
		}
	}
}

//Verific daca intalnesc alta lumina in calea unei lumini. Daca da,
//inseamna ca jocul nu este valid si returnez 0
unsigned short gridl(char grid[][NMAX], unsigned short i, unsigned short j)
{
	short k;
	k = i;

	while (grid[k + 1][j] == '-' || grid[k + 1][j] == 'x') {
		k++;
	}
	if (grid[k + 1][j] == 'L') {
		return 0;
	}

	k = i;
	while (grid[k - 1][j] == '-' || grid[k - 1][j] == 'x') {
		k--;
	}
	if (grid[k - 1][j] == 'L') {
		return 0;
	}

	k = j;
	while (grid[i][k + 1] == '-' || grid[i][k + 1] == 'x') {
		k++;
	}
	if (grid[i][k + 1] == 'L') {
		return 0;
	}

	k = j;
	while (grid[i][k - 1] == '-' || grid[i][k - 1] == 'x') {
		k--;
	}
	if (grid[i][k - 1] == 'L') {
		return 0;
	}
	return 1;
}

//Testez daca in jurul unui 0 gasesc o lumina, daca da, jocul nu este valid
unsigned short grid02(char grid[][NMAX], unsigned short i, unsigned short j)
{
	short dx[] = {-1, 1, 0, 0};
	short dy[] = {0, 0, -1, 1};

	for (int d = 0; d < 4; d++) {
		if (grid[i + dx[d]][j + dy[d]] == 'L') {
			return 0;
		}
	}
	return 1;
}

//Testez daca in jurul unui 1 gasesc mai mult de o lumina,
//daca da jocul nu este valid
unsigned short grid12(char grid[][NMAX], unsigned short i, unsigned short j)
{
	short dx[] = {-1, 1, 0, 0};
	short dy[] = {0, 0, -1, 1};

	unsigned short count1 = 0, count2 = 0;
	for (int d = 0; d < 4; d++) {
		if (grid[i + dx[d]][j + dy[d]] == 'L') {
			count1++;
		}
		if (grid[i + dx[d]][j + dy[d]] == '-') {
			count2++;
		}
	}
	if (count1 > 1) {
		return 0;
	}

	if (count1 < 1 && count2 < 1 - count1) {
		return 0;
	}
	return 1;
}

//Testez daca in jurul unui 2 gasesc mai mult de doua lumini,
//daca da jocul nu este valid
unsigned short grid22(char grid[][NMAX], unsigned short i, unsigned short j)
{
	short dx[] = {-1, 1, 0, 0};
	short dy[] = {0, 0, -1, 1};

	unsigned short count1 = 0, count2 = 0;
	for (int d = 0; d < 4; d++) {
		if (grid[i + dx[d]][j + dy[d]] == 'L') {
			count1++;
		}
		if (grid[i + dx[d]][j + dy[d]] == '-') {
			count2++;
		}
	}
	if (count1 > 2) {
		return 0;
	}

	if (count1 < 2 && count2 < 2 - count1) {
		return 0;
	}
	return 1;
}

//Testez daca in jurul unui 3 gasesc mai mult de trei lumini,
//daca da jocul nu este valid
unsigned short grid32(char grid[][NMAX], unsigned short i, unsigned short j)
{
	short dx[] = {-1, 1, 0, 0};
	short dy[] = {0, 0, -1, 1};

	unsigned short count1 = 0, count2 = 0;
	for (int d = 0; d < 4; d++) {
		if (grid[i + dx[d]][j + dy[d]] == 'L') {
			count1++;
		}
		if (grid[i + dx[d]][j + dy[d]] == '-') {
			count2++;
		}
	}
	if (count1 > 3) {
		return 0;
	}

	if (count1 < 3 && count2 < 3 - count1) {
		return 0;
	}
	return 1;
}
