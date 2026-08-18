#include <stdio.h>
#include <string.h>
int bubbleSort(char str[], int n) {
    int temp = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (str[j] > str[j+1]) {
                temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
    return 0;
}

int main(){
    char nums[][10] = {{"ZERO"},{"ONE"},{"TWO"},{"THREE"},{"FOUR"},{"FIVE"},{"SIX"},{"SEVEN"},{"EIGHT"},{"NINE"},{"TEN"},{"ELEVEN"},{"TWELVE"}};
    int num = 0;
    char letters[100] = "";
    while(num!=999){
        scanf("%d",&num);
        if(num>=0 && num<=12){
            strcat(letters,nums[num]);
        }
    printf("%d ",num);
    }
    printf(". ");
    bubbleSort(letters,strlen(letters));
    for(int i=0;i<strlen(letters);i++){
        printf("%c ",letters[i]);
    }
}