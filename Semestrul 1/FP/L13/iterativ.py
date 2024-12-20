def consistent(x):
    """
    verificam daca solutia este consistenta
    deoarece generam permutari, elementele trebuie sa fie diferite
    :param x: lista de indici
    :return: True daca este o permutare valida, False altfel
    """

    for i in range(0, len(x) - 1):
        if x[i] == x[len(x) - 1]:
            return False
    return True


def valid_solution(SUM, coins, x):
    """
    verificam daca solutia este valida
    :param SUM: suma de cheltuit
    :param coins: lista de monede
    :param x: lista de indici
    :return: True daca se poate plati suma, False altfel
    """

    s = 0
    for i in range(0, len(x)):
        s = s + coins[x[i]]

    return s == SUM


def solutionFound(x, coins):
    """
    afisarea unei solutii
    :param x: lista de indici
    :param coins: lista de monede
    :return: True, inseamna ca am afisat o solutie si suma se poate plati
    """

    for i in range(0, len(x)):
        print(coins[x[i]], end=" ")
    print("\n")

    return True


def backIter(DIM, coins, SUM):
    """
    algoritmul de backtracking care genereaza permutari
    :param DIM: dimensiunea listei de monede
    :param coins: lista de monede
    :param SUM: suma care trebuie platita
    :return found: daca am gasit solutie sau nu
    """

    found = False
    x = [-1]
    while len(x) > 0:
        chosen = False
        while not chosen and x[-1] < DIM - 1:
            x[-1] = x[-1] + 1
            chosen = consistent(x)

        if chosen:
            if valid_solution(SUM, coins, x):
                solutionFound(x, coins)
                found = True
            x.append(x[-1])

        else:
            x = x[:-1]

    return found


def test_backIter():
    assert backIter(5, [1, 2, 3, 4, 5], 10) is True
    assert backIter(4, [3, 2, 6, 4], 13) is True


test_backIter()
