//Spinu Rares
#include <stdio.h>
#include "akari_headers.h"
#define NMAX 51

int main(void)
{
	unsigned short n, m, o;
	char grid[NMAX][NMAX];
	scanf("%hu", &o);
	scanf("%hu%hu", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &grid[i][j]);
		}
	}
	//Optiunea 1
	if (o == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 'L') {
					gridL(grid, i, j);
				}
				if (grid[i][j] == '0') {
					grid0(grid, i, j);
				}
				if (grid[i][j] == '1') {
					grid1(grid, i, j);
				}
				if (grid[i][j] == '2') {
					grid2(grid, i, j);
				}
				if (grid[i][j] == '3') {
					grid3(grid, i, j);
				}
			}
		}
		afisare(grid, n, m);
	//Optiunea 2
	} else if (o == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 'L') {
					gridL(grid, i, j);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 'L') {
					if (gridl(grid, i, j) == 0) {
						printf("zero\n");
						return 0;
					}
				}
				if (grid[i][j] == '0') {
					if (grid02(grid, i, j) == 0) {
						printf("zero\n");
						return 0;
					}
				}
				if (grid[i][j] == '1') {
					if (grid12(grid, i, j) == 0) {
						printf("zero\n");
						return 0;
					}
				}
				if (grid[i][j] == '2') {
					if (grid22(grid, i, j) == 0) {
						printf("zero\n");
						return 0;
					}
				}
				if (grid[i][j] == '3') {
					if (grid32(grid, i, j) == 0) {
						printf("zero\n");
						return 0;
					}
				}
			}
		}
		printf("ichi\n");
	}
	return 0;
}
