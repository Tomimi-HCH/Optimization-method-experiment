#include <stdio.h>
#include <math.h>
#define EPS 1e-6 // ���徫��
double f(double x) {
    return log(1 + x + x*x + exp(x + x*x))/(1 + x*x) + log(1 + 2*exp(x - 7));
}
int main() {
    double a, b, c;
    printf("�������ʼ����[a,b]: ");
    scanf("%lf %lf", &a, &b);
    if (f(a)*f(b) > 0) {
        printf("������������û�����\n");
        return 0;
    }
    double h = (b-a)/2;
    double fa = f(a), fb = f(b), fc = f(c);
    while (h > EPS) {
        if (fa*fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
        h /= 2;
        c = a + h;
        fc = f(c);
    }
    printf("������һ����������Ϊ[%lf, %lf]\n", a, b);
    return 0;
}
