#include<stdio.h>

int Hoare_partition(int n, int A[n]);

int main(){
    int arr[]={6,2,7,9,6,3,7,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int index=Hoare_partition(n, arr);
    printf("%d\n", index);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

int Hoare_partition(int n, int A[n]){
    int pivot=A[0];
    int i=-1;
    int j=n;
    int temp;

    while(i<j){
        do{
            i++;
        }while(A[i]<pivot);

        do{
            j--;
        }while(A[j]>pivot);

        if(i>=j){
            return j;
        }

        temp=A[i];
        A[i]=A[j];
        A[j]=temp;

    }
}
