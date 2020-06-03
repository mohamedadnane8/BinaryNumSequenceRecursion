#include<stdio.h>

void generateNumber(int binary[], int start,int max,int * cnt_number,int target){
    if (*cnt_number == target) return;
    if(max == start){
        for(int row = 0;row<max;row++)
            printf("%d",binary[row]);
        printf("\n");
        (*cnt_number)++;
        return;
    }
    for(int row = 0; row < 2 && start < max; row++){
        binary[start] = row; 
        generateNumber(binary,start+1,max,cnt_number,target);
    }
}
void printBinaryNumbers(int n, int row, int* cnt_number){
    int binary[row];

    binary[0] = 1;
    if( *cnt_number == n)  return;
    generateNumber(binary,1,row,cnt_number,n);
    printBinaryNumbers(n,row+1,cnt_number);
}
int main(){
    int cnt = 0;
    int num;
    printf("please imput a number:");
    scanf("%d",&num);
    printBinaryNumbers(num,0,&cnt);
    return 0;
}
