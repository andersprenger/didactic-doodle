#include <stdio.h>
#include <math.h>

double f(double x) {
    return (x - 2) * (x - 3) * (x - 4) *(x-5);
}

double bisec(double a, double b) {
    double meio = (a+b)/2;

    while (fabs(f(meio)) > 1e-6) {
        if (f(meio) > 0) {
            b = meio;
        } else {
            a = meio;
        }

        meio = (a+b)/2;
    }

    return meio;
}

int main(int argc, char const *argv[]) {
    printf("%20lf\n", bisec(1, 6));
    
    return 0;
}
