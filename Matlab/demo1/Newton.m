function [x,minf]=Newton(f,x0,eps)
%{
Newton      牛顿法
    f       函数
    x0      初始点
    eps     误差
   
    x       目标x
    minf    目标函数值
%}
xmax = x0+2;
xmin = x0-2;
F0 = matlabFunction(f);             %原函数函数句柄
F1 = matlabFunction(diff(f));       %一阶导函数函数句柄
F2 = matlabFunction(diff(f,2));     %二阶导函数函数句柄

while abs(F1(x0)) >= eps            %迭代
    x0 = x0 - F1(x0) / F2(x0);
end

x = x0;
minf = F0(x);

%%%%%%%% 绘图
figure('Name', 'MinHJ')
xx = xmin:0.01:xmax;
yy = F0(xx);
plot(xx, yy, 'LineWidth', 2)
hold on
plot(x,minf,'p', 'LineWidth', 2)
end


while abs(F1(x0)) >= eps            %迭代
    x0 = x0 - F1(x0) / F2(x0);
end

x = x0;
minf = F0(x);

%%%%%%%% 绘图
figure('Name', 'MinHJ')
xx = xmin:0.01:xmax;
yy = F0(xx);
plot(xx, yy, 'LineWidth', 2)
hold on
plot(x,minf,'p', 'LineWidth', 2)
end
