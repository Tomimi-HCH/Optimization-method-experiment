function [xmin,xmax]=Brackeing(f,x0,h)
%{
Brackeing 进退法
   f       函数
   x0      初始点
   h0      步长
   
   xmin    左区间
   xmax    右区间
%}
F = matlabFunction(f);  %建立函数句柄
a = 2;                  %加倍系数
k = 1;                  %迭代数
lambda = 0;             %记录答案
flag = false;           %标记

x = zeros(1,10);        %申请自变量空间
f_val = zeros(1,10);    %申请函数值空间
x(1) = x0;              %自变量赋值
f_val(1) = F(x(1));     %函数赋值


while true
%%%%%%%%%%%%% 试探&计算
    x(k+1) = x(k) + h;      
    f_val(k+1) = F(x(k+1));
%%%%%%%%%%%%%
    if f_val(k+1) >= f_val(k) %  比较
        if k == 1       %检查
            h = -h;     %改变方向反向前进
            lambda = x(k+1);
            x(k+1) = x(k) + h;      
            f_val(k+1) = F(x(k+1));
        else 
            flag = true;
        end
    end
    
    if flag         %结束计算
        break
    end
        
%%%%%%%%%%%%% 加步
    h = a * h;
    lambda = x(k);
    x(k) = x(k+1);
    f_val(k) = f_val(k+1);
    k = k + 1;
%%%%%%%%%%%%%
end

xmin = min(lambda, x(k+1));     %左边界
xmax = max(lambda, x(k+1));     %右边界
disp(xmin)
disp(xmax)
%%%%%%%%%%%%% 绘图查看
figure('Name', 'Brackeing')
xx = xmin-0.5:0.01:xmax+0.5;
yy = F(xx);
plot(xx, yy, 'LineWidth', 2)
hold on
plot([xmin,xmax], [min(yy), min(yy)],':r', 'LineWidth', 1.5)
end
