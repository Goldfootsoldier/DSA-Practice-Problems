#include <stdio.h>

int main(){
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        int n, m = 0;
        scanf("%d %d",&n,&m);
        int mat[n][m];
        for(int j = 0;j<n;j++){
            for(int k = 0;k<m;k++){
                scanf("%d", &mat[j][k]);
            } 
        }
        int x1,x2,y1,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        int sum = 0;
        for(int j = x1-1;j<=x2-1;j++){
            for(int k = y1-1;k<=y2-1;k++){
                sum += mat[j][k];
            }
        }
        printf("%d",sum);
    }
    return 0;
}