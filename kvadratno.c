#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int main(){

    double a, b, c, d;
    printf("Enter the value of a: ");
    scanf("%lf", &a);
    printf("Enter the value of b: ");
    scanf("%lf", &b);
    printf("Enter the value of c: ");
    scanf("%lf", &c);

    //printf("a: %lf\tb: %lf\t, c:%lf \t", a, b, c);

    d = b*b - 4*(a*c);
    printf("D is: %lf\n", d);

    if(d > 0){
        double x1 = (-b - sqrt(d))/2*a;
        double x2 = (-b + sqrt(d))/2*a;
        printf("x1 is: %lf\nx2 is: %lf", x1, x2);
    } else if(d == 0){
        double x = -b / 2*a;
        printf("x is: %lf", x);
    } else{
        printf("No real roots");
    }

    return 0;
}