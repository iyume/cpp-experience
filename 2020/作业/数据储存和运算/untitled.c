#include <stdio.h>

int main(){
    float x, y, z;
    while(scanf("%f %f %f", &x, &y, &z) != EOF){
        printf("%.0f\n", x + y + z);
        printf("%.2f\n", (x + y + z) / 3);
    }
    return 0;
}