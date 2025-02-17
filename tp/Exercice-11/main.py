(a, b) = (int(input('a :')), int(input('b :')))

if b != 0:
    if a % b:
        print("la division de a par b donne un reste non nul")
    else:
        print("a est divisible par b")
else:
    print("La division de a par b ten vers plus ou moins infinie")
