#NOTE: Program can only propagate error for functions of 3 variables or less.
#EXAMPLE SHOWN: Error in kinetic energy (J) with mass = (1 ± 0.001) kg and speed = (5 ± 0.01) m/s.

from numpy import *

#Values of each variable
valX = 1
valY = 5
valZ = 0

#Values of each uncertainty/error in each variable
deltaX = 0.001
deltaY = 0.01
deltaZ = 0

#Function (Do not include variable if unused)
def f(x,y,z):
    return 0.5*(x)*(y**2)



# g: function
# x: value of x
# y: value of y
# z: value of z
# d: respect to one of the specified variables above

def partDer(g,x,y,z,d):
    h=0.00001 
    match d:
        case 'x':
            return (g(x+h,y,z)-g(x,y,z))/h
        case 'y':
            return (g(x,y+h,z)-g(x,y,z))/h
        case 'z':
            return (g(x,y,z+h)-g(x,y,z))/h

F = f(valX,valY,valZ,)
deltaF = ((partDer(f,valX,valY,valZ,'x')*deltaX)**2 + (partDer(f,valX,valY,valZ,'y')*deltaY)**2 + (partDer(f,valX,valY,valZ,'z')*deltaZ)**2)**0.5
print(f"F: {F} \u00B1 {deltaF}")