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

void cof(matrix A) {
	double det(int , matrix );
	int p, q, x, y;
		if(n == 2) {
			cofact[1][1] = A[2][2];
			cofact[1][2] = -A[1][2];
			cofact[2][1] = -A[2][1];
			cofact[2][2] = A[1][1];
		}
		 else {
			for(x = 1; x <= n; x++)
				for(y = 1; y <= n; y++) {
					p = 1;
					for(i == 1; i <= n, i != x; i++) {
						q = 1;
						for(j == 1; j <= n, j != y; j++) {
							co[x][y][p][q] = A[i][j];
							printf("\n\r COEFFICIENTS of cofactoring : %d by %d : %16.8f", p, q, co[x][y][p][q]);
							q = q + 1;
						}
						p = p + 1;
					}
			cofact[x][y] = det(n - 1, co[x][y]);
			}
		}
		//free(co);
	}
