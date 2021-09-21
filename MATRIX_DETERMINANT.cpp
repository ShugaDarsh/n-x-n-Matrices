//By: Ishraga Mustafa Awad Allam. On: 31 - 10 - 2019.
/* PROGRAM MATRICES (n x n)
{ MATRIX INVERSES - MATRIX COFACTORS - MATRIX DETERMINANTS - TRANSPOSES - FACTORIZATION }
{ AUTHOR : ISHRAGA MUSTAFA AWAD ALLAM } { IshragaAllam@Gmail.com } { 00 249 912 652300 }
{ ON = 31 : 10 : 2019 } { Khartoum, Sudan } */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define z 5 // Because of cofactors 4-Dimensions, the size is limited to 5. If RAM of computer is bigger, this number can be increased.
typedef float matrix[z][z];
matrix Mat, cofact, tran, inv, co[z][z], prod, Mat1, Mat2;
FILE *Fx; // To print all results also on a text file, called matrices.txt.
int i, j, k, n;

double det(int b, matrix M) {
	matrix C[z][z];
	double determinant, d, M1, M2, M3;
	int c = 0, p, q, x, y;
		if(b == 2) determinant = (M[1][1] * M[2][2]) - (M[1][2] * M[2][1]);
		 else if(b == 3) {
			M1 = (M[1][1] * (M[2][2] * M[3][3] - M[3][2] * M[2][3]));
			M2 = (M[2][1] * (M[1][2] * M[3][3] - M[3][2] * M[1][3]));
			M3 = (M[3][1] * (M[1][2] * M[2][3] - M[2][2] * M[1][3]));
			determinant = M1 - M2 + M3;
		}
		 else if(b >= 4) {
			for(x = 1; x <= b; x++)
				for(y = 1; y <= b; y++) {
					p = 1;
					for(i = 1; i <= b, i != x; i++) {
						q = 1;
						for(j = 1; j <= b, j != y; j++) {
							C[x][y][p][q] = M[i][j];
//cprintf("\n\r COEFFICIENTS of cofactoring : [%d] [%d] [%d] [%d] : %16.8lf", x, y, p, q, C[x][y][p][q]);
							q = q + 1;
						}
						p = p + 1;
					}
				}
		determinant = 0;
		for(i = 1; i <= b; i++) {
			c = c + 1;
			d = det(b - 1, C[i][1]);
			if(fmod(c, 2) == 0) d = -d;
			determinant = determinant + (M[i][1] * d);
		}
	}
//free(C);
	return determinant;
	}
