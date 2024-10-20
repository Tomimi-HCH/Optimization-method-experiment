function f = fun(x)
    f = log(1 + x + x^2 + exp(x + x^2)) / (1 + x^2) + log(1 + 2*exp(x - 7));
end