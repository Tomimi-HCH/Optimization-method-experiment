#include <stdio.h>
#include <math.h>

// 目标函数 f(x)，这里使用了一个示例函数，你可以根据需要替换为其他函数
double function(double x) {
    // 示例函数: -x * sin(10 * x)
    return -x * sin(10 * x);
}

// 0.618法（黄金分割搜索法）
void golden_section_search(double a, double b, double epsilon) {
    double phi = (sqrt(5) + 1) / 2; // 黄金比例
    double r = phi - 1; // 黄金分割比

    double x1, x2; // 区间内的两个点
    double f1, f2; // 这两个点的函数值

    // 循环直到区间长度小于误差阈值
    while (b - a > epsilon) {
        // 计算两个内部点
        x1 = a + r * (b - a);
        x2 = b - r * (b - a);

        // 计算这两个点的函数值
        f1 = function(x1);
        f2 = function(x2);

        // 根据函数值更新区间
        if (f1 < f2) {
            b = x2; // 更新区间的上界
        } else {
            a = x1; // 更新区间的下界
        }
    }

    // 输出近似极小点的位置
    printf("0.618法（黄金分割搜索法）: 近似极小点在 x = %.6f\n", (a + b) / 2);
}

// 抛物线法
void parabolic_interpolation(double a, double b, double epsilon) {
    double fa = function(a); // a点的函数值
    double fb = function(b); // b点的函数值
    double fc = function((a + b) / 2); // 中点的函数值

    double x_min, f_min; // 最小值点及其函数值
    double x_new; // 新的点

    // 循环直到区间长度小于误差阈值
    while (b - a > epsilon) {
        // 使用二次插值法计算新的x_min
        x_min = (fa * (b - a) * (b - a) - fb * (a - a) * (a - a) - fc * (a - b) * (a - b)) /
                (2 * (fb - fa - fc));

        // 确保x_min在区间内
        if (x_min <= a || x_min >= b) {
            x_min = (a + b) / 2;
        }

        f_min = function(x_min); // 计算新点的函数值

        // 更新区间
        if (f_min < fb) {
            if (x_min < b) {
                a = b; // 更新区间的下界
                b = x_min; // 更新区间的上界
            } else {
                b = a; // 更新区间的上界
                a = x_min; // 更新区间的下界
            }
        } else {
            if (x_min < b) {
                a = x_min; // 更新区间的下界
            } else {
                b = x_min; // 更新区间的上界
            }
        }

        // 重新计算中点的函数值
        fc = function((a + b) / 2);
    }

    // 输出近似极小点的位置
    printf("抛物线法: 近似极小点在 x = %.6f\n", (a + b) / 2);
}

int main() {
    double a = 1.0; // 区间下界
    double b = 2.0; // 区间上界
    double epsilon = 1e-6; // 误差阈值

    // 使用0.618法寻找近似极小点
    golden_section_search(a, b, epsilon);

    // 使用抛物线法寻找近似极小点
    parabolic_interpolation(a, b, epsilon);

    return 0;
}
