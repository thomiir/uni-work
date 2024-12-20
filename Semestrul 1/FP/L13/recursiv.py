def consistent(x):
    """
    verificam daca solutia este consistenta
    deoarece generam permutari, elementele trebuie sa fie diferite
    :param x: lista de indici
    :return: True daca este o permutare valida, False altfel
    """

    for i in range(0, len(x) - 1):
        if x[i] == x[len(x) - 1] or x[i] > x[len(x) - 1]:
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
    if s == SUM:
        return True
    else:
        return False


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


def backRec(SUM, DIM, coins, x):
    x.append(0)
    found_solution = False
    for i in range(0, DIM):
        x[-1] = i
        if consistent(x):
            if valid_solution(SUM, coins, x):
                solutionFound(x, coins)
                found_solution = True
            if backRec(SUM, DIM, coins, x):
                found_solution = True
    x.pop()
    return found_solution


def test_backRec():
    assert backRec(10, 5, [1, 2, 3, 4, 5], []) is True
    assert backRec(15, 4, [4, 3, 10, 1], []) is True


test_backRec()
