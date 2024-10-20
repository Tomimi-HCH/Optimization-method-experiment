#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x);
double f_prime(double x);
void Armjio(double *alpha, double *xk, double *f_val, int *k, double x0, double dk);

double f(double x) {
    return (log(1 + x + x * x + exp(x + x * x)) / (1 + x * x)) + log(1 + 2 * exp(x - 7));
}

double f_prime(double x) {
    double term1 = (2 * exp(x - 7)) / (1 + 2 * exp(x - 7));
    double term2 = (2 * x * log(1 + x + x * x + exp(x + x * x))) / ((1 + x * x) * (1 + x * x));
    double term3 = (1 + 2 * x + (2 * x + 1) * exp(x + x * x)) / ((1 + x * x) * (1 + x + x * x + exp(x + x * x)));
    return term1 - term2 + term3;
}

void Armjio(double *alpha, double *xk, double *f_val, int *k, double x0, double dk) {
    double beta = 0.333;
    double c = 1e-3;
    *alpha = 1;
    *k = 0;
    double gk = f_prime(x0);
    double fd = f(x0 + (*alpha) * dk);
    double fk = f(x0)+ (*alpha) * c * gk * dk;
    while (fd > fk) {
        *alpha *= beta;
        fd = f(x0 + (*alpha) * dk);
        fk = f(x0)+ (*alpha) * c * gk * dk;
        (*k)++;
    }
    *xk = x0 + (*alpha) * dk;
    *f_val = f(*xk);
}

int main() {
    double alpha, xk, f_val;
    int k;
    double x0 = 0;
    double dk = -1;
    Armjio(&alpha, &xk, &f_val, &k, x0, dk);
    printf("alpha: %lf\nxk: %lf\nf_val: %lf\nk: %d\n", alpha, xk, f_val, k);
    return 0;
}