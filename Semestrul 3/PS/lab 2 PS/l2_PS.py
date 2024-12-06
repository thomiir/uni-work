from random import randint, random
from matplotlib.pyplot import plot, grid, show, subplot, axis
from math import dist


def cerinta_1a(n):
    nrDuplicate = 0
    for i in range(10000):
        zile_nastere = [randint(1, 365) for j in range(n)]
        if len(zile_nastere) != len(set(zile_nastere)):
            nrDuplicate += 1
    
    return nrDuplicate / 10000.0

def cerinta_1b(n):
    if n > 365:
        return 1
    prob = 1.0
    for i in range(n):
        prob *= (365 - i) / 365
    return 1 - prob

def cerinta_1c():
    xs = range(50)
    ys1 = [cerinta_1a(x) for x in xs]
    ys2 = [cerinta_1b(x) for x in xs]
    subplot(1, 2, 1)
    plot(xs, ys1, 'r*')
    grid()
    subplot(1, 2, 2)
    plot(xs, ys2, 'r*')
    grid()
    show()

def cerinta_2aI(nr_pct):
    E = [0.5, 0.5]
    count = 0
    for i in range(nr_pct):
        F = [random(), random()]
        if dist(F,E) < 0.5:
            count += 1
            plot(F[0], F[1], 'r*')
        else:
            plot(F[0], F[1], 'b*')
    show()
    return count / nr_pct

def cerinta_2aII(nr_pct):
    count = 0
    A,B,C,D = [0,0],[1,0],[0,1],[1,1]
    E = [0.5,0.5]
    for i in range(nr_pct):
        F = [random(),random()]
        if dist(F,E) < min(dist(F,A),dist(F,B),dist(F,C),dist(F,D)):
            count += 1
            plot(F[0],F[1],"r*")
        else:
            plot(F[0],F[1],'b*')
    show()
    return count / nr_pct
            
def cerinta_2aIII(nr_pct):
    count = 0
    A,B,C,D = [0,0],[1,0],[0,1],[1,1]
    for i in range(nr_pct):
        F = [random(), random()]

def main():
    print(cerinta_1a(20))
    print(cerinta_1b(20))
    cerinta_1c()
    print(cerinta_2aI(2000))
    print(cerinta_2aII(2000))

main()