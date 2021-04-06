#include <stdio.h> 

void timeplus(float a_h, float a_m, float a_s, float b_h, float b_m, float b_s){
    float c_m = a_m + b_m, c_s = a_s + b_s;
    if(c_s >= 60){
        c_s -= 60;
        c_m += 1;
    }
    if(c_m >= 60){
        c_m -= 60;
        a_h += 1;
    }
    printf("%.0f %.0f %.0f\n", a_h + b_h, c_m, c_s);
}

int main(){
    float a_h, a_m, a_s, b_h, b_m, b_s;
    while(scanf("%f %f %f %f %f %f", &a_h, &a_m, &a_s, &b_h, &b_m, &b_s) != EOF){
        timeplus(a_h, a_m, a_s, b_h, b_m, b_s);
    }
    return 0;
}