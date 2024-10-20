function g = grid(x)
    term1 = (2*exp(x - 7))/(1 + 2*exp(x - 7));

    term2 = (2*x*log(1 + x + x^2+ exp(x + x^2)))/((1 + x^2)^2);

    term3 = (1 + 2*x+(2*x + 1)*exp(x + x^2))/((1 + x^2)*(1 + x + x^2+ exp(x + x^2)));
    
    g = term1 - term2 + term3;
end