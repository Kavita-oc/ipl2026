#include<stdio.h>

void printBits(int n){
    int bits=sizeof(int)*8;
    for(int i=bits-1; i>=0; i--){
        printf("%d", n >> i & 1);
        
        if(i%8==0){
            printf(" ");
        }
    }

}

int countBits(int n){
    int count =0;

    while(n){
        count += n & 1;
        n=n>>1;
    }
    return count;
}

int main(){
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("\nBits of the integer: ");
    printBits(n);

    int count=countBits(n);
    printf("\nNo. of 1s: %d\n", count);

    return 0;
}