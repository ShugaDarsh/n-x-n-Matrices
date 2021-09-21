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

void transpose(matrix A) {
//textcolor(14);
	printf("\n\r The Transpose of the Matrix \n\r");
	fprintf(Fx, "\n\r The Transpose of the Matrix \n\r");
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++) {
			tran[j][i] = A[i][j];
			tran[i][j] = A[j][i];
		}
	SHOW(tran);
	}
