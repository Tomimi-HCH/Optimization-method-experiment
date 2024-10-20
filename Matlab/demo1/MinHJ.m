function [x,miny]=MinHJ(f,a,b,eps)
%{
    MinHJ   0.618法
    f       函数
    a       左区间
    b       右区间
    eps     精度

    x       自变量
    miny    局部极小值
%}
xmax = b;
xmin = a;
F = matlabFunction(f);  %函数句柄
tau = 0.618;            %缩短率
lambda = a + (1 - tau)*(b - a);     %计算lambda
mu = a + tau * (b - a);             %计算mu

lambda_val = F(lambda);             %lambda函数值
mu_val = F(mu);                     %mu函数值

while b - a >= eps                  %误差区间之外
    %fprintf('a=%d,b=%d,a_val=%d,b_val=%d\n',a,b,lambda_val,mu_val);
    if lambda_val < mu_val
        b = mu;
        mu = lambda;
        mu_val = lambda_val;
        lambda = a + (1 - tau)*(b - a);
        lambda_val = F(lambda);
    else
        a = lambda;
        lambda = mu;
        lambda_val = mu_val;
        mu = a + tau * (b - a);
        mu_val = F(mu);
    end
end

%计算结果
x = (lambda + mu) / 2;
miny = F(x);

%%%%%%%% 绘图
figure('Name', 'MinHJ')
xx = xmin:0.01:xmax;
yy = F(xx);
plot(xx, yy, 'LineWidth', 2)
hold on
plot(x,miny,'p', 'LineWidth', 2)
end
