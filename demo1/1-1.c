#include <stdio.h>
#include <math.h>

// 定义函数 f(x)
double f(double x) {
    return log(1 + x + x*x + exp(x + x*x)) / (1 + x*x) + log(1 + 2 * exp(x - 7));
}

int main() {
    double x, h, phi1, phi2;
    int success = 0; // 搜索是否成功的标志

    // 步骤1: 选择初始点、步长和精度
    printf("Enter initial point x: ");
    scanf("%lf", &x);

    printf("Enter initial step size h: ");
    scanf("%lf", &h);

    const double epsilon = 1e-5; // 精度

    // 计算初始点的函数值
    phi1 = f(x);

    // 步骤2: 计算 φ2 = f(x + h)
    phi2 = f(x + h);

    // 步骤3: 判断搜索是否成功或失败
    if (phi2 < phi1) {
        // 搜索成功，进入步骤4
        success = 1;
    } else {
        // 搜索失败，进入步骤5
        success = 0;
    }

    while (!success && fabs(h) > epsilon) {
        // 步骤4: 更新 x 和 h 的值
        if (success) {
            x += h;
            phi1 = phi2;
            h *= 2.0;

            // 再次计算新的 φ2 值
            phi2 = f(x + h);
        } else {
            // 步骤5: 调整步长并改变符号
            h /= -4.0;

            // 再次计算新的 φ2 值
            phi2 = f(x + h);

            // 如果 φ2 小于 φ1，则更新状态为成功
            if (phi2 < phi1) {
                success = 1;
            }
        }

        // 判断 |h| 是否小于等于 ε
        if (fabs(h) <= epsilon) {
            break;
        }
    }

    // 输出结果
    if (success) {
        printf("A single peak interval is found around x = %lf\n", x);
    } else {
        printf("No single peak interval found within the given precision.\n");
    }

    return 0;
}
