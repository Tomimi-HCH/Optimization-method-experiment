#include <stdio.h>
#include <math.h>

// �����Ŀ�꺯��������ʹ��ʾ������
double f(double x) {
    return log(1 + x + x*x + exp(x + x*x))/(1 + x*x) + log(1 + 2*exp(x - 7));
}

void Brackeing(double (*func)(double), double x0, double h, double *xmin, double *xmax) {
    const double a = 2.0; // �ӱ�ϵ��
    int k = 1; // ������
    double lambda = 0.0; // ��¼��
    int flag = 0; // ���
    double x[11]; // �����Ա����ռ�
    double f_val[11]; // ���뺯��ֵ�ռ�

    x[1] = x0; // �Ա�����ֵ
    f_val[1] = func(x[1]); // ������ֵ

    while (!flag) {
        // ��̽&����
        x[k + 1] = x[k] + h;
        f_val[k + 1] = func(x[k + 1]);

        // �Ƚ�
        if (f_val[k + 1] >= f_val[k]) {
            if (k == 1) { // ���
                h = -h; // �ı䷽����ǰ��
                lambda = x[k + 1];
                x[k + 1] = x[k] + h;
                f_val[k + 1] = func(x[k + 1]);
            } else {
                flag = 1; // ��������
            }
        }

        // �Ӳ�
        if (!flag) {
            h = a * h;
            lambda = x[k];
            x[k] = x[k + 1];
            f_val[k] = f_val[k + 1];
            k++;
        }
    }

    // ���ұ߽�
    *xmin = fmin(lambda, x[k + 1]);
    *xmax = fmax(lambda, x[k + 1]);
}

int main() {
    double xmin, xmax, x0 = 0.0, h = 0.1; // ��ʼ��Ͳ���
    Brackeing(f, x0, h, &xmin, &xmax);
    printf("xmin: %f\n", xmin);
    printf("xmax: %f\n", xmax);
    return 0;
}
