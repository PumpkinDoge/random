from numpy import *


def f(x):
    # Only edit the function after the "return" keyword (e.g. return ...)
    return e**x

def derivative(a):
    h= 0.00000001
    return (f(a + h) - f(a))/h
 
def main():
    # Only edit the value folllowing the "x" varible (e.g. x = ...)
    x = pi
    print(derivative(x))

if __name__ == '__main__':
    main()