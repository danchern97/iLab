#include <stdio.h>
#include <math.h>

int main(){
    double a, b, c;
    printf("Enter the coefficients of the equation : \n");
	if(scanf("%lg %lg %lg", &a, &b, &c) == 3){
    solving(a, b, c);
	} else {
	printf("Wrong input");
	}
    return 0;
}

void solving(double a, double b, double c){
	if (a == 0){
        if (b == 0){
            if(c == 0){
                printf("Oops! The equation has an infinite number of solutions.");
            } else {
            printf("Oops! No solutions in this case.");
            }
        } else {
        double x;
        x = -c/b;
        printf("Here's a solution: %lg", x);
        }
	} else {
        if((b*b - 4*a*c) < 0){
            printf("Oops! No solutions in this case.");
        } else if((b*b - 4*a*c) == 0){
        double x;
        x = -b/(2*a);
        printf("Here's a solution: %lg", x);
        } else {
        double x1, x2, D;
        D = pow((b*b - 4*a*c), 0.5);
        x1 = (-b + D)/4;
        x2 = (-b-D)/4;
        printf("Here's 2 solutions: %lg and %lg", x1, x2);
        }
	}
}
