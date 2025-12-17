//Spinu Rares
#ifndef akari_headers_h
#define akari_headers_h
#define NMAX 51

void afisare(char grid[][NMAX], unsigned short n, unsigned short m);
void gridL(char grid[][NMAX], unsigned short i, unsigned short j);
void grid0(char grid[][NMAX], unsigned short i, unsigned short j);
void grid1(char grid[][NMAX], unsigned short i, unsigned short j);
void grid2(char grid[][NMAX], unsigned short i, unsigned short j);
void grid3(char grid[][NMAX], unsigned short i, unsigned short j);

unsigned short gridl(char grid[][NMAX], unsigned short i, unsigned short j);
unsigned short grid02(char grid[][NMAX], unsigned short i, unsigned short j);
unsigned short grid12(char grid[][NMAX], unsigned short i, unsigned short j);
unsigned short grid22(char grid[][NMAX], unsigned short i, unsigned short j);
unsigned short grid32(char grid[][NMAX], unsigned short i, unsigned short j);

#endif
