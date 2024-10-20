#include <stdio.h>
#include <math.h>

// 假设的目标函数，这里使用示例函数
double f(double x) {
    return log(1 + x + x*x + exp(x + x*x))/(1 + x*x) + log(1 + 2*exp(x - 7));
}

void Brackeing(double (*func)(double), double x0, double h, double *xmin, double *xmax) {
    const double a = 2.0; // 加倍系数
    int k = 1; // 迭代数
    double lambda = 0.0; // 记录答案
    int flag = 0; // 标记
    double x[11]; // 申请自变量空间
    double f_val[11]; // 申请函数值空间

    x[1] = x0; // 自变量赋值
    f_val[1] = func(x[1]); // 函数赋值

    while (!flag) {
        // 试探&计算
        x[k + 1] = x[k] + h;
        f_val[k + 1] = func(x[k + 1]);

        // 比较
        if (f_val[k + 1] >= f_val[k]) {
            if (k == 1) { // 检查
                h = -h; // 改变方向反向前进
                lambda = x[k + 1];
                x[k + 1] = x[k] + h;
                f_val[k + 1] = func(x[k + 1]);
            } else {
                flag = 1; // 结束计算
            }
        }

        // 加步
        if (!flag) {
            h = a * h;
            lambda = x[k];
            x[k] = x[k + 1];
            f_val[k] = f_val[k + 1];
            k++;
        }
    }

    // 左右边界
    *xmin = fmin(lambda, x[k + 1]);
    *xmax = fmax(lambda, x[k + 1]);
}

int main() {
    double xmin, xmax, x0 = 0.0, h = 0.1; // 初始点和步长
    Brackeing(f, x0, h, &xmin, &xmax);
    printf("xmin: %f\n", xmin);
    printf("xmax: %f\n", xmax);
    return 0;
}
