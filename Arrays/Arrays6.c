#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
 
int minPrice(int price[], int n){
    int min = price[0];
    int index = 0;
    for(int i = 0;i<n;i++){
        if(price[i]<min){
            min = price[i];
            index = i;
        }
    }
    return index;
}

int main(){
    int n = 0;
    int total = 0;
    scanf("%d",&total);
    scanf("%d",&n);
    int temp = total;
    char item[n][100];
    int price[n];
    for(int i = 0; i<n; i++){
        scanf("%s",item[i]);
        scanf("%d",&price[i]);
    }
    bool afford[n];
    while(true){
        int index = minPrice(price,n);
        if(total>=price[index]){
            afford[index] = true;
            total -= price[index];
            price[index] = INT_MAX;
        }else{
            afford[index] = false;
            break;
        }
    }
    for(int i = 0; i<n; i++){
        if(afford[i]){
            printf("I can afford %s\n",item[i]);
        }else{
            printf("I can't afford %s\n",item[i]);
        }
    }
    if(total==temp){
        printf("I need more Dollar\n");
    }
    else{
        printf("%d\n",total);
    }
    return 0;
}