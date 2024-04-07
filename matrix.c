#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// 행렬 출력 함수
void print_matrix(int **A, int row_a, int col_a,int **B, int row_b, int col_b){
    
    printf("Matrix A\n"); // 행렬 A 출력
    for(int i=0; i<row_a; i++){
        for(int j=0; j<col_a; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("Matrix B\n"); // 행렬 B 출력
    for(int i=0; i<row_b; i++){ 
        for(int j=0; j<col_b; j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}
// 행렬 덧셈 함수
void addition_matrix(int **A, int row_a, int col_a,int **B, int row_b, int col_b){
    if(row_a != row_b || col_a != col_b){
        printf("Matrix addition is not possible\n");
    }
    else{
        
        printf("Matrix A + Matrix B\n"); // 행렬 A와 B의 각 요소를 더한 결과 출력
        for(int i=0; i<row_a; i++){
            for(int j=0; j<col_a; j++){
                printf("%d ", A[i][j] + B[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
// 행렬 뺄셈 함수
void subtraction_matrix(int **A, int row_a, int col_a,int **B, int row_b, int col_b){
    if(row_a != row_b || col_a != col_b){
        printf("Matrix subtraction is not possible\n");
    }
    else{
        
        printf("Matrix A - Matrix B\n"); // 행렬 A와 B의 각 요소를 뺀 결과 출력
        for(int i=0; i<row_a; i++){
            for(int j=0; j<col_a; j++){
                printf("%d ", A[i][j] - B[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
// 행렬 전치시키는 함수
void transpose_matrix(int **A, int row_a, int col_a,int **B, int row_b, int col_b){
    
    printf("Matrix A Transpose\n"); // 행렬 A의 전치행렬 출력
    for(int i=0; i<col_a; i++){
        for(int j=0; j<row_a; j++){
            printf("%d ", A[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}
// 행렬 곱셈 함수
void multiply_matrix(int **A, int row_a, int col_a,int **B, int row_b, int col_b){
    if(col_a != row_b){
        printf("Matrix multiplication is not possible\n");
    }
    else{ 
        printf("Matrix A * Matrix B\n"); // 행렬 A와 B의 곱셈 결과 출력
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

    int rowa, cola, rowb, colb,random; // 행렬 A와 B의 행과 열을 저장할 변수 선언
    srand(time(NULL)); // 난수 생성을 위한 srand 함수 호출
    scanf("%d %d %d %d", &rowa, &cola, &rowb, &colb);

    // 행렬 A와 B 동적 할당
    int **A = (int**)malloc(rowa*sizeof(int*));
    int **B = (int**)malloc(rowb*sizeof(int*));

    random = time(NULL); // 난수 생성을 위한 seed 값 설정

    for(int i=0; i<cola; i++){
        A[i] = (int*)malloc(cola*sizeof(int)); // 행렬 A의 열만큼 동적 할당
    }

    for(int i=0; i<colb; i++){
        B[i] = (int*)malloc(colb*sizeof(int)); // 행렬 B의 열만큼 동적 할당
    }

    for(int i=0; i<rowa; i++){
        for(int j=0; j<cola; j++){
            random = rand()% 100+1;
            A[i][j] = (unsigned int)random;  // 행렬 A의 각 요소에 난수 저장
        }
    }

    for(int i=0; i<rowb; i++){
        for(int j=0; j<colb; j++){
            random = rand() % 100+1;
            B[i][j] = (unsigned int)random; // 행렬 B의 각 요소에 난수 저장
        }
    }
    print_matrix(A,rowa,cola,B,rowb, colb); // 행렬 A와 B 출력

    // 동적 할당된 메모리 해제
    for(int i = 0; i < rowa; i++) {
    free(A[i]); 
    }
    free(A); 

    for(int i = 0; i < rowb; i++) {
    free(B[i]); 
    }
    free(B); 

    printf("[----- [leetaejung] [2023041062] -----]");
    
    return 0;
}
