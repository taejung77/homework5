#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void print_matrix(int **A, int row_a, int col_a,int **B, int row_b, int col_b){
    printf("Matrix A\n");
    for(int i=0; i<row_a; i++){
        for(int j=0; j<col_a; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Matrix B\n");
    for(int i=0; i<row_b; i++){
        for(int j=0; j<col_b; j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}
void addition_matrix(int **A, int row_a, int col_a,int **B, int row_b, int col_b){
    if(row_a != row_b || col_a != col_b){
        printf("Matrix addition is not possible\n");
    }
    else{
        printf("Matrix A + Matrix B\n");
        for(int i=0; i<row_a; i++){
            for(int j=0; j<col_a; j++){
                printf("%d ", A[i][j] + B[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
void subtraction_matrix(int **A, int row_a, int col_a,int **B, int row_b, int col_b){
    if(row_a != row_b || col_a != col_b){
        printf("Matrix subtraction is not possible\n");
    }
    else{
        printf("Matrix A - Matrix B\n");
        for(int i=0; i<row_a; i++){
            for(int j=0; j<col_a; j++){
                printf("%d ", A[i][j] - B[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
void transpose_matrix(int **A, int row_a, int col_a,int **B, int row_b, int col_b){
    printf("Matrix A Transpose\n");
    for(int i=0; i<col_a; i++){
        for(int j=0; j<row_a; j++){
            printf("%d ", A[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}
void multiply_matrix(int **A, int row_a, int col_a,int **B, int row_b, int col_b){
    if(col_a != row_b){
        printf("Matrix multiplication is not possible\n");
    }
    else{
        printf("Matrix A * Matrix B\n");
        for(int i=0; i<row_a; i++){
            for(int j=0; j<col_b; j++){
                int sum = 0;
                for(int k=0; k<col_a; k++){
                    sum += A[i][k] * B[k][j];
                }
                printf("%d ", sum);
            }
            printf("\n");
        }
        printf("\n");
    }

}



int main(){

    int rowa, cola, rowb, colb,random;
    srand(time(NULL));
    scanf("%d %d %d %d", &rowa, &cola, &rowb, &colb);

    int **A = (int**)malloc(rowa*sizeof(int*));
    int **B = (int**)malloc(rowb*sizeof(int*));

    random = time(NULL);

    for(int i=0; i<cola; i++){
        A[i] = (int*)malloc(cola*sizeof(int));
    }

    for(int i=0; i<colb; i++){
        B[i] = (int*)malloc(colb*sizeof(int));
    }

    for(int i=0; i<rowa; i++){
        for(int j=0; j<cola; j++){
            random = rand()% 100+1;
            A[i][j] = (unsigned int)random;
        }
    }

    for(int i=0; i<rowb; i++){
        for(int j=0; j<colb; j++){
            random = rand() % 100+1;
            B[i][j] = (unsigned int)random;
        }
    }
    print_matrix(A,rowa,cola,B,rowb, colb);

    for(int i = 0; i < rowa; i++) {
    free(A[i]);
    }
    free(A);

    for(int i = 0; i < rowb; i++) {
    free(B[i]);
    }
    free(B);
    printf("[----- [ÀÌÅÂÁ¤] [2023041062] -----]");
    return 0;
}
