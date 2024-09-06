#include <stdio.h>
#include <inttypes.h>

void printAsBinary(double val) {
    typedef union {
        double decimal;
        uint64_t binary;
    } IEEE_double;

    IEEE_double ieee_val;
    ieee_val.decimal = val;
    
    // little endian (x86 e arm são little endian)
    for (int i = 63; i >= 0; i--) {
        printf("%ld", (ieee_val.binary >> i) & 1); // shift + mascara para o bit na posição i
        if (i == 63 || i == 52) { // i == 63 (espaco entre sinal e expoente) || i == 52 (espaço entre expoente e mantissa) 
            printf(" ");
        }
    }
}

int main() {
    double aux = 1.0;
    int i = 0;

    // while (1 + aux > 1) {
    //     printf("%2d ", ++i);
    //     printf("%.20lf\n", aux);
    //     aux = aux / 2;
    // }

    do
    {
        printf("%2d ", ++i);
        printf("%.20lf", (1 + aux));
        printAsBinary((1 + aux));
        printf("\n");
        aux = aux / 2;
    } while (1 + aux > 1);
    

    return 0;
}