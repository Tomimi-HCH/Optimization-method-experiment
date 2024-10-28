%% 2-1-1
clc;clear
f = @(x1,x2) 0.5*(21*x1^2 + 8*x1*x2+15*x2^2)+2*x1+3*x2
x0{1}=[-30;100];
x ='[x1,x2]';      % 函数变量字符串
eps = 10^-6;     % ε为误差精度

[x0,i] = steepest_descent(f,x,x0,eps);
%% 2-1-1画图
x1=0:0.01:2;
x2=x1;
GIFname = 'f1.gif';
GDplot(f,x0,i,x1,x2,GIFname)

%% 2-1-2
clc;clear
f = @(x1,x2) 0.5*(21*x1^2 + 8*x1*x2+x2^2)+2*x1+3*x2
x0{1}=[-30;100];
x ='[x1,x2]';      % 函数变量字符串
eps = 10^-6;     % ε为误差精度

[x0,i] = steepest_descent(f,x,x0,eps);

%% 2-1-2画图
x1=0:0.01:2;
x2=x1;
GIFname = 'f1.gif';
GDplot(f,x0,i,x1,x2,GIFname)


%% 2-1-3
clc;clear
f = @(x1,x2) log(1+(x1+3)^2 + x2^2/2 + exp((x1+3)^2 + x2^2/2)) / (1+(x1+3)^2 + x2^2/2);
x0{1}=[-30;100];
x ='[x1,x2]';      % 函数变量字符串
eps = 10^-6;     % ε为误差精度

[x0,i] = steepest_descent(f,x,x0,eps);

%% 2-1-3画图
x1=0:0.01:2;
x2=x1;
GIFname = 'f1.gif';
GDplot(f,x0,i,x1,x2,GIFname)

%% 2-2-1











