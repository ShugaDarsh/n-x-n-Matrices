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

void factors(matrix M) {
	float res;
	int f;
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				prod[i][j] = 0;
				for(i = 1; i <= n; i++) {
					res = 1;
					for(k = 100; k >= 2; k--) {
						f = 0;
						for(j = 1; j<= n, fmod(M[j][i], k) == 0; j++)
							f = f + 1;
						if(f == n) {
							M[j][i] = M[j][i] / k;
							res = res * k;
							prod[i][i] = res;
						}
				}
			}
		SHOW(prod);
	}
