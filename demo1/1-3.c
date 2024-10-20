#include <stdio.h>
#include <math.h>

// 定义函数phi(x)
double phi(double x) {
    return 2 * exp(sin(M_PI / 6 * pow(x, 5))) + 3 * x * x + 2 * x;
}

// 使用0.618法求极小值点
void golden_section_search(double a, double b, double epsilon) {
    double lambda = (sqrt(5) - 1) / 2; // 黄金比例系数
    double c = b - lambda * (b - a);
    double d = a + lambda * (b - a);

    while (fabs(b - a) > epsilon) {
        if (phi(c) < phi(d)) {
            b = d;
        } else {
            a = c;
        }
        c = b - lambda * (b - a);
        d = a + lambda * (b - a);
    }

    printf("Golden Section Search: 最小值点近似为x = %.10f\n", (a + b) / 2);
}

// 使用抛物线法求极小值点
void parabola_method(double a, double b, double c, double epsilon) {
    double fa = phi(a), fb = phi(b), fc = phi(c);

    while (fabs(b - a) > epsilon && fabs(c - b) > epsilon) {
        double fmin = fmin(fa, fmin(fb, fc));
        if (fa == fmin) {
            double t = b - ((fb - fa) * (b - c) / (fb - fc) + (b - a));
            if (t <= a || t >= c) break;
            a = b;
            fa = fb;
            b = t;
            fb = phi(t);
        } else if (fc == fmin) {
            double t = a - ((fb - fa) * (b - c) / (fb - fc) + (b - a));
            if (t <= a || t >= c) break;
            c = b;
            fc = fb;
            b = t;
            fb = phi(t);
        } else {
            double t1 = a - ((fb - fa) * (b - c) / (fb - fc) + (b - a));
            double t2 = c - ((fb - fc) * (b - a) / (fb - fa) + (c - b));
            if (fabs(t1 - a) < fabs(t2 - c)) {
                if (t1 <= a || t1 >= c) break;
                a = b;
                fa = fb;
                b = t1;
                fb = phi(t1);
            } else {
                if (t2 <= a || t2 >= c) break;
                c = b;
                fc = fb;
                b = t2;
                fb = phi(t2);
            }
        }
    }

    printf("Parabola Method: 最小值点近似为x = %.10f\n", b);
}

int main() {
    double a, b, c;

    // 选择任意一个单峰区间进行计算
    a = -1.85;
    b = -1.57;

    // 使用0.618法求解
    golden_section_search(a, b, 1e-6);

    // 使用抛物线法求解
    c = -1.55;
    parabola_method(a, b, c, 1e-6);

    return 0;
}
