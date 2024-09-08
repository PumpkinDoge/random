from numpy import *

# Edit function of integral
def f(x):
    return x**2

def main():
    
# Edit boundaries
    xMin = 0
    xMax = 10

#Edit number of subintervals; higher number means greater accuracy, but also greater runtime.
    numSubintervals = 10000
    
    
    xDelta = (xMax - xMin) / numSubintervals
    valueSum = 0
    cof = 4
    point = xMin

    for i in range(0, numSubintervals):
        if i == 0:
            valueSum += f(point)
            point += xDelta
        elif i == numSubintervals:
            valueSum += f(point)
            point += xDelta
        elif cof == 4:
            valueSum += cof * f(point)
            point += xDelta
            cof -= 2 
        else:
            valueSum += cof * f(point)
            point += xDelta
            cof += 2
          
    valueSum = (xDelta/3) * valueSum  
    print(valueSum)
    
if __name__ == '__main__':
    main()
