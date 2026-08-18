#include <stdio.h>
int bubbleSort(int arr[], int n) {
    int temp = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return 0;
}

int swapAdjacent(int arr[],int n){
    int temp = 0;
    for(int i = 0;i<n-1;i=i+2){
        temp = arr[i];
        arr[i]=arr[i+1];
        arr[i+1]= temp;
    }
    return 0;
}

int main(){
    int n = 0;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    if(bubbleSort(arr,n)!=0) return 1;
    if(swapAdjacent(arr,n)) return 1;

    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}