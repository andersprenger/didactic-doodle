#include <stdio.h>
#include <math.h>

double f(double x, double p) {
    return pow(x, 2) - p;
}

double df(double x) {
    return 2 * x - 1;
}



// double bisec(double a, double b) {
//     double meio = (a+b)/2;

//     while (fabs(f(meio)) > 1e-6) {
//         if (f(meio) > 0) {
//             b = meio;
//         } else {
//             a = meio;
//         }

//         meio = (a+b)/2;
//     }

//     return meio;
// }

double newton(double x, double p) {
    while (fabs(f(x, p)) > 1e-8) {
        x = x - f(x, p)/df(x);
        printf("%20lf\n", x);
    }

    return x;
}

int main() {
    printf("%.20lf\n", newton(1, 6));
    
    return 0;
}
