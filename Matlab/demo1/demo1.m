%% 1-1
clc;clear;

syms x y;
y = (x^2 - 1)^2 - (x - 1)^2 + 3;
f = log(1 + x + x^2 + exp(x + x^2)) / (1 + x^2) + log(1 + 2*exp(x - 7));
x0 = 0;
h0 = 0.1

[a, b] = Brackeing(f,x0,h0)

%% 1-2

[x,miny]=MinHJ(y,a,b,10^-6)

%% 1-3
clc;clear;

syms x y;

y = 2*exp(sin(pi/6*x^5)) + 3*x^2 + 2*x;

% [−1.85, −1.57] 、[−1.55, 1.25] 、[1.29, 1.72] 中
a = -1.85;
b = -1.57;
eps = 10^-6;

[x,miny]=MinHJ(y,a,b,eps)

