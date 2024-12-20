# -*- encoding: utf-8 -*-
from scipy.stats import bernoulli, binom, hypergeom, geom
from matplotlib.pyplot import bar, show, hist, grid, legend, xticks
import random
from math import comb
from numpy import arange

def ex1a(nr_pasi, p):
    pozitii = [0]
    for _ in range(nr_pasi):
        x = bernoulli.rvs(p)
        pas = 2*x-1
        pozitii.append(pozitii[-1] + pas)
    return pozitii

def ex1b(nr_pasi, p, nr_sim):
    pozitii_finale = [ex1a(nr_pasi, p)[-1] for _ in range(nr_sim)]
    bin_edges = [i + 0.5 for i in range(-nr_pasi - 1, nr_pasi + 1)]
    hist(pozitii_finale, bin_edges, density=True, rwidth=0.9, align='mid', edgecolor='black', color='green', alpha=0.3, label="frecvente relative")
    distribution = dict([(k - (nr_pasi - k), binom.pmf(k, nr_pasi, p)) for k in range(nr_pasi+1)])
    bar(distribution.keys(), distribution.values(), width = 0.6, align='center', color = 'red', edgecolor = 'black',alpha= 0.6, label = 'probabilitati')
    xticks(range(-nr_pasi, nr_pasi + 1))
    legend(loc = 'upper left')
    grid()
    show()
 

def mers_aleator_cerc(nr_pasi, p, n):
    pozitii = [0]
    for _ in range(nr_pasi):
        x = bernoulli.rvs(p)
        if x == 1:
            pas = 1
        else:
            pas = -1
        next_position = (pozitii[-1] + pas) % n
        pozitii.append(next_position)
    return pozitii

def ex1c(nr_pasi, p, nr_sim, n):
    pozitii_finale = [mers_aleator_cerc(nr_pasi, p, n)[-1] for _ in range(nr_sim)]
    bin_edges = arange(-0.5, n + 0.5, 1) 
    hist(pozitii_finale, bins=bin_edges, density=True, rwidth=0.9, align='mid', edgecolor='black', color='green', alpha=0.3, label="frecvente relative")
    xticks(range(n))  
    legend(loc='upper left')
    grid()
    show()

def ex2a(nr_sim):
    p = sum([hypergeom.pmf(k,49,6,6) for k in range(3,7)])
    nr_bile_necastigatoare = geom.rvs(p, size=nr_sim)
    return nr_bile_necastigatoare

def ex2b(n_sim):
    win = sum(comb(6, k) * comb(43, 6 - k) / comb(49, 6) for k in range(3, 7))
    loss = 1 - win
    teoretic = loss ** 10
    cnt = 0
    for _ in range(n_sim):
        winning_numbers = set(random.sample(range(1, 50), 6))
        losses = 0
        while True:
            bilet = set(random.sample(range(1, 50), 6))
            matches = len(bilet & winning_numbers)
            if matches >= 3:
                if losses >= 10:
                    cnt += 1
                break
            losses += 1
    estimat = cnt / n_sim
    return [estimat, teoretic]

print("ex 1a)")
print(ex1a(100, 0.1))
print("ex 1b)")
ex1b(10, 0.5, 1000)
print("ex 1c)")
ex1c(100, 0.5, 1000, 7)
print("ex 2a)")
print(ex2a(1000))
print("ex 2b)")
print(ex2b(1000))
