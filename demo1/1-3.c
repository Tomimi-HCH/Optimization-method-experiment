#include <stdio.h>
#include <math.h>

// 假设的目标函数，这里使用示例函数
double f(double x) {
    // 替换为目标函数的实现
    return 2*exp(sin(M_PI/6* pow(x, 5) )) + 3* pow(x, 2) + 2*x;
}

void MinHJ(double (*func)(double), double a, double b, double eps, double *x, double *miny) {
    double tau = 0.618; // 缩短率
    double lambda, mu, lambda_val, mu_val;

    lambda = a + (1 - tau) * (b - a); // 计算lambda
    mu = a + tau * (b - a);           // 计算mu

    lambda_val = func(lambda);        // lambda函数值
    mu_val = func(mu);                // mu函数值

    while (b - a >= eps) {            // 误差区间之外
        if (lambda_val < mu_val) {
            b = mu;
            mu = lambda;
            mu_val = lambda_val;
            lambda = a + (1 - tau) * (b - a);
            lambda_val = func(lambda);
        } else {
            a = lambda;
            lambda = mu;
            lambda_val = mu_val;
            mu = a + tau * (b - a);
            mu_val = func(mu);
        }
    }

    // 计算结果
    *x = (lambda + mu) / 2;
    *miny = func(*x);
}

int main() {
    double a = -1.85, b = -1.57, eps = 1e-6; // 定义区间和精度
    double x, miny;

    MinHJ(f, a, b, eps, &x, &miny);
    printf("x: %f\n", x);
    printf("miny: %f\n", miny);

    return 0;
}
