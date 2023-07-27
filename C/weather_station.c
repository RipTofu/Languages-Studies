//Brief study on data type double

#include <stdio.h>

int main() {
    double celsius, fahrenheit;
    printf("Enter celsius degrees: ");
    scanf("%lf", &celsius);
    double converted = celsius * 1.8 + 32.0;
    printf("\nThe fahrenheit degrees is %lf", converted);

    printf("Enter fahrenheit degrees: ");
    scanf("%lf", &fahrenheit);
    converted = (fahrenheit-32.0)/1.8;
    printf("The celsius degrees is %lf", converted);
}
