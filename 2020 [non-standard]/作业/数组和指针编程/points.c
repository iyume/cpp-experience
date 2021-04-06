#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,j,n;
    double s = 0;
    double a[15][2];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<2;j++)
            scanf("%lf",&a[i][j]);
    for(i=1;i<n;i++)
        for(j=0;j<2;j++)
            a[i][j] = a[i][j] - a[0][j];
    for(i=1;i<n-1;i++){
        s = s + 0.5* ( a[i][0] * a[i+1][1] - a[i+1][0] * a[i][1]);
    }
    s = abs(s);
    printf("%.2f", s);
} // 显然这是抄的