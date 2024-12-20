from iterativ import backIter
from recursiv import backRec


def read_input():
    S = input("Introduceti suma de platit: ")
    n = input("Introduceti numarul de monede: ")
    try:
        S = int(S)
        n = int(n)
        if S <= 0 or n <= 0:
            raise ValueError("n si S trebuie sa fie intregi nenule!")

    except ValueError:
        raise ValueError("n si S trebuie sa fie intregi nenule!")
    print("Introduceti cele n monede: ")

    coins_list = []
    for i in range(0, n):
        x = input("Introduceti valoarea monedei: ")
        try:
            x = int(x)

        except ValueError:
            raise ValueError("Monedele trebuie sa fie intregi!")
        coins_list.append(x)

    return S, n, coins_list


def print_main_menu():
    print("Pentru o lista de monede cu valorile a1, ..., an si o valoare S. TIpariti toate modalitatile de a plati suma S cu monedele disponibile. Tipariti un mesaj daca suma nu se poate plati.")
    print("1. Varianta iterativa.")
    print("2. Varianta recursiva.")
    print("3. Iesire.")


def choose_option():
    while True:
        print_main_menu()
        option = int(input("Alegeti o optiune: "))
        try:

            if option == 1:
                S, n, coins_list = read_input()
                found = backIter(n, coins_list, S)
                if not found:
                    print("Suma nu se poate plati.")

            elif option == 2:
                S, n, coins_list = read_input()
                found = backRec(S, n, coins_list, [])
                if not found:
                    print("Suma nu se poate plati.")

            else:
                break

        except ValueError as ve:
            print(ve)

choose_option()