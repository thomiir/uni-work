def print_main_menu():
    """
    printarea meniului principal
    """

    print("Alegeti o optiune:")
    print("1. Adauga un scor la un participant.")
    print("2. Modificare scor.")
    print("3. Tipareste lista de participanti.")
    print("4. Operatii pe un subset de participanti.")
    print("5. Filtrare.")
    print("6. Undo (reface ultima operatie, lista de scoruri revine la numerele ce existau inainte de ultima operatie care a modificat lista).")
    print("7. batch mode")
    print("8. Iesire.")


def print_menu1():
    """
    printarea meniului pentru sub-cerinta 1
    """

    print("Alegeti o optiune:")
    print("a. Adauga scor pentru un nou participant (ultimul participant).")
    print("b. Inserare scor pentru un participant.")
    print("c. Iesire")


def print_menu2():
    """
    printarea meniului pentru sub-cerinta 2
    """

    print("Alegeti o optiune:")
    print("a. Sterge scorul pentru un participant dat.")
    print("b. Sterge scorul pentru un interval de participanti.")
    print("c. Inlocuieste scorul de la un participant.")
    print("d. Iesire")


def print_menu3():
    """
    printarea meniului pentru sub-cerinta 3
    """

    print("Alegeti o optiune:")
    print("a. Tipareste participantii care au scor mai mic decat un scor dat.")
    print("b. Tipareste participantii ordonat dupa scor")
    print("c. Tipareste participantii cu scor mai mare decat un scor dat, ordonat dupa scor.")
    print("d. Iesire")


def print_menu4():
    """
    printarea meniului pentru sub-cerinta 4
    """

    print("Alegeti o optiune:")
    print("a. Calculeaza media scorurilor pentru un interval dat.")
    print("b. Calculeaza scorul minim pentru un interval de participanti dat.")
    print("c. Tipareste participantii dintr-un interval dat care au scorul multiplu de 10.")
    print("d. Iesire.")


def print_menu5():
    """
    printarea meniului pentru sub-cerinta 5
    """

    print("Alegeti o optiune:")
    print("a. Filtrare participanti care au scorul multiplu unui numar dat.")
    print("b. Filtrare participanti care au scorul mai mic decat un scor dat.")
    print("c. Iesire.")


def print_menu6():
    """
    printarea meniului pentru sub-cerinta 6
    """

    print("Alegeti o optiune:")
    print("a. Reface ultima operatie (lista de scoruri revine la numerele ce existau inainte de ultima operatie care a modificat lista).")
    print("b. Iesire.")


def read_option():
    """
    citirea optiunii utilizatorului
    @return string option: optiunea introdusa de utilizator
    """

    option = input()
    return option


def read_test_number():
    """
    citirea numarului probei
    @param string test_number: numarul probei
    """

    test_number = input()
    return test_number


def read_participant_number():
    """
    citirea numarului de concurs al unui participant
    @return string participant: numarul de concurs al unui participant
    """

    participant_number = input()
    return participant_number


def read_score_list():
    """
    citirea listei de scoruri a unui participant
    @return list[int] score_list: lista de scoruri a unui participant
    """

    score_list=[]
    i=1
    while i<=10:
        score = input()
        try:
            if score<'1' or len(score)==2 and score!='10': raise ValueError
        except ValueError:
            print("Scorul participantului trebuie sa fie un numar intreg, in intervalul [1,10]. Introduceti din nou valoarea.")
            i=i-1
        else:
            score_list.append(int(score))
        i=i+1
    return score_list


def read_score():
    """
    citirea scorului
    @return string score: scorul obtinut de un participant la o anumita proba
    """

    score = input()
    return score


def read_lower_bound():
    """
    citirea limitei inferioare a intervalului
    """

    lower_bound = input()
    return lower_bound


def read_upper_bound():
    """
    citirea limitei superioare a intervalului
    """

    upper_bound = input()
    return upper_bound


def read_batch_mode():
    """
    citirea listei de comenzi in mod batch
    """

    string = input()
    return string