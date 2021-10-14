/* PROGRAM MATRICES (n x n)
{   MATRIX INVERSES - MATRIX COFACTORS - MATRIX DETERMINANTS - TRANSPOSES - FACTORIZATION   }
{ AUTHOR : ISHRAGA MUSTAFA AWAD ALLAM }     {  IshragaAllam@Gmail.com }   {  00 249 912 652300 }
{  ON = 31 : 10 : 2019   }       {   Khartoum, Sudan  }   */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

#define z 5

typedef float matrix[z][z];
matrix Mat, cofact, tran, inv, co[z][z], prod, Mat1, Mat2;
FILE *Fx;
int i, j, k, n;

double det(int , matrix );
void cof(matrix );
void add(matrix , matrix );
void sub(matrix , matrix );
void mult(matrix , matrix );
void transpose(matrix );
void inverse(matrix );
void factors(matrix );
void SHOW(matrix );

void SHOW(matrix S) {
      int x, y;
        printf("\n\r");           fprintf(Fx, "\n\r");
        for(x = 1; x <= n; x++) {
          for(y = 1; y <= n; y++) {
            textcolor(y + 10);     cprintf("   %16.3f", S[y][x]);
            fprintf(Fx,  "   %16.3f", S[y][x]);
          }
          printf("\n\r");           fprintf(Fx, "\n\r");
          }
      printf("\n\r");           fprintf(Fx, "\n\r");
      }

void add(matrix A, matrix B)  {
   textcolor(15);
   cprintf("\n\r Adding the TWO Matrices \n\r");
   fprintf(Fx, "\n\r Adding the TWO Matrices \n\r");
      for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
           prod[i][j] = A[i][j] + B[i][j];
        }
      } 
	SHOW(prod);   
}

void sub(matrix A, matrix B) {
   textcolor(14);
   cprintf("\n\r Subtracting the TWO Matrices \n\r");
   fprintf(Fx, "\n\r Subtracting the TWO Matrices \n\r");
     for(i = 1; i <= n; i++) {
      for(j = 1; j <= n; j++) {
        prod[i][j] = A[i][j] - B[i][j];
      }
    }
    SHOW(prod);
  }

void mult(matrix A, matrix B) {
  float res;
    textcolor(15);
    cprintf("\n\r Multiplying the TWO Matrices \n\r");
    fprintf(Fx, "\n\r Multiplying the TWO Matrices \n\r");
    for(i = 1; i <= n; i++) {
      for(j = 1; j <= n; j++) {
        res = 0;
        for(k = 1; k <= n; k++) {
          res = res + (A[j][k] * B[k][i]);
        }
      prod[j][i] = res;
      }
    }
    SHOW(prod);
  }

void transpose(matrix A) {
  textcolor(14);
  cprintf("\n\r The Transpose of the Matrix \n\r");
  fprintf(Fx, "\n\r The Transpose of the Matrix \n\r");
  for(i = 1; i <= n; i++)
      for(j = 1; j <= n; j++) {
         tran[j][i] = A[i][j];
         tran[i][j]  = A[j][i];
         }
     SHOW(tran);    
   }

double det(int b, matrix M)  {
  matrix C[z][z];
  double determinant, d, M1, M2, M3;
  int c = 0, p, q, x, y;

  if(b == 2) determinant = (M[1][1] * M[2][2]) - (M[1][2] * M[2][1]);
  if(b == 3) {
      M1 = (M[1][1] * (M[2][2] * M[3][3] - M[3][2] * M[2][3]));
      M2 = (M[2][1] * (M[1][2] * M[3][3] - M[3][2] * M[1][3]));
      M3 = (M[3][1] * (M[1][2] * M[2][3] - M[2][2] * M[1][3]));   
      determinant = M1 - M2 + M3;
      }
   if(b >= 4) {
      textcolor(13);
      for(x = 1; x <= b; x++)
        for(y = 1; y <= b; y++) {
          p = 1;
          for(i = 1; i <= b, i != x; i++) {
            q = 1;
            for(j = 1; j <= b, j != y; j++) {
               C[x][y][p][q] = M[i][j];
               cprintf("\n\r COEFFICIENTS of cofactoring : [%d] [%d] [%d] [%d] : %16.8lf", x, y, p, q, C[x][y][p][q]);
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
          for(i = 1; i <= n, i != x; i++) {
          	q = 1;
            for(j = 1; j <= n, j != y; j++) {
               co[x][y][p][q] = A[i][j];
               cprintf("\n\r COEFFICIENTS of cofactoring : %d by %d : %16.8lf", p, q, co[x][y][p][q]);
               q = q + 1;
               }
             p = p + 1;
             }
          cofact[x][y] = det(n - 1, co[x][y]);
         }
    }
    //free(co);
  }

void inverse(matrix A) {
   cof(A);
   textcolor(14);
   cprintf("\n\r The Inverse of the Matrix \n\r");
   fprintf(Fx, "\n\r The Inverse of  the Matrix \n\r");
   for(i = 1; i <= n; i++) {
      for(j = 1; j <= n; j++) {
         inv[i][j] = (1 / det(n, A)) *  cofact[i][j];
         //cprintf("\n\r The Inverse of the matrix is %d %d %16.8lf", i, j, inv[i][j]);
         }
       printf("\n\r");
      }
    SHOW(inv);  
  }

void factors(matrix M) {
  float res;
  int f;
    textcolor(12);
    cprintf("\n\r The Factors Matrix of the Matrix \n\r");
    fprintf(Fx, "\n\r The Factors Matrix of the Matrix \n\r");
    for(i = 1; i <= n; i++)
      for(j = 1; j <= n; j++)
        prod[i][j] = 0;
    for(i = 1; i <= n; i++) {
      res = 1;
      for(k = 10000; k >= 2; k--) {
        f = 0;
        for(j = 1; j <= n, fmod(M[i][j], k) == 0; j++)
          f = f + 1;
        if(f == n) {
          M[j][i] = M[j][i] / k;
          res = res * k;
          prod[i][i] = k;
          }
         }
      }
      SHOW(prod);
   }

int main() {
  double dd;
  double det(int , matrix );
  void cof(matrix );
  void add(matrix , matrix );
  void sub(matrix , matrix );
  void mult(matrix , matrix );
  void transpose(matrix );
  void inverse(matrix );
  void factors(matrix );

    textbackground(9);
    clrscr();
    textcolor(15);
    cprintf("Enter your matrix damiansions : ");
    textcolor(14);
    cscanf("%d", &n);
    printf("\n\r");
    Fx = fopen("matrices.txt", "w");
    fprintf(Fx, "Enter your matrix damiansions : %d\n\r", n);
    fprintf(Fx, "\n\r");
    for(i = 1; i <= n; i++)
      for(j = 1; j <= n; j++) {
      textcolor(15);
      cprintf(" COEFFICIENTS : %d by %d : ", i, j);
      textcolor(15);
      cscanf("%f", &Mat[i][j]);
      printf("\n\r");
      }
    SHOW(Mat);  
    dd = det(n, Mat);
    cof(Mat);
    textcolor(14);
    cprintf("\n\r The determinant is %24.16lf\n\r", dd);
    fprintf(Fx, "\n\r The determinant is %24.16lf\n\r", dd);
    inverse(Mat);
      for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
          cprintf("\n\r The Inverse coefficients of the matrix is %d %d %16.8lf", i, j, inv[i][j]);
       printf("\n\r");
       }
    dd = (1 / det(n, Mat)) * det(n, cofact);
    cprintf("\n\r The Inverse is %24.16lf\n\r", dd);
    fprintf(Fx, "\n\r The Inverse is %24.16lf\n\r", dd);
    transpose(Mat);
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
          cprintf("\n\r The Transpost coefficients of the matrix is %d %d %16.8lf", i, j, tran[i][j]);
       printf("\n\r");
       }

    textcolor(15);
    cprintf("Enter your matrix damiansions : ");
    textcolor(14);
    cscanf("%d", &n);
    fprintf(Fx, "\n\rEnter your FIRST matrix damiansions of diminsions %d: \n\r", n);
    printf("\n\r");
    for(i = 1; i <= n; i++)
      for(j = 1; j <= n; j++) {
      textcolor(15);
      cprintf(" COEFFICIENTS of First Matrix is : %d by %d : ", i, j);
      textcolor(15);
      cscanf("%f", &Mat1[i][j]);
      printf("\n\r");
    }
    SHOW(Mat1);
    fprintf(Fx, " Second Matrix is : \n\r");
    for(i = 1; i <= n; i++)
      for(j = 1; j <= n; j++) {
        textcolor(15);
        cprintf(" COEFFICIENTS of Second Matrix is : %d by %d : ", i, j);
        textcolor(15);
        cscanf("%f", &Mat2[i][j]);
        printf("\n\r");
    }
    SHOW(Mat2);
    mult(Mat1, Mat2);
    add(Mat1, Mat2);
    sub(Mat1, Mat2);
    factors(Mat);
    textcolor(14);
    cprintf("\n\r The Resultant Matrix is : \n\r");
    for(i = 1; i <= n; i++) {
      for(j = 1; j <= n; j++) {
         cprintf("\n\r The Coefficients of the Resultant matrix is %d %d %16.8lf", i, j, prod[i][j]);
         }
       printf("\n\r");
      } 
	fclose(Fx);   
    getche();
    return 0;
    }


