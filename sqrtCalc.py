#Function requests number that is to be square rooted and the number of loops
#Number of loops dicatate accurracy
def rootFunc(number, loops, guess):
  a = guess
  for i in range(loops):
    a = 0.5 * (a + (number / a))
  return a

#Function requests number that is to be square rooted, the factor of accuracy (number of loops), and closest guess
print(rootFunc( int(input("Number? ")), int(input("Factor of accurracy? ")), int(input("Closest guess? "))))