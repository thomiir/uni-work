import interfata_utilizator as ui

def validate_option_main_menu(option):
    """
    validarea datelor de intrare pentru meniul principal
    @param int option: optiunea aleasa de utilizator
    """

    while True:
        try:
            if option < '1' or option > '8' or len(option)>1: raise ValueError

        except ValueError:
            print("Optiune invalida. Introduceti din nou.")
            option = ui.read_option()

        else: break
    return option


def validate_option_menu1(option):
    """
    validarea datelor de intrare pentru meniul sub-cerintei 1
    @param int option: optiunea aleasa de utilizator
    """

    while True:
        try:
            if option < 'a' or option > 'c': raise ValueError

        except ValueError:
            print("Optiune invalida. Introduceti din nou.")
            option = ui.read_option()

        else: break
    return option


def validate_option_menu2(option):
    """
    validarea datelor de intrare pentru meniul sub-cerintei 2
    @param int option: optiunea aleasa de utilizator
    """

    while True:
        try:
            if option < 'a' or option > 'd': raise ValueError

        except ValueError:
            print("Optiune invalida. Introduceti din nou.")
            option = ui.read_option()

        else: break
    return option


def validate_option_menu3(option):
    """
    validarea datelor de intrare pentru meniul sub-cerintei 3
    @param int option: optiunea aleasa de utilizator
    """

    while True:
        try:
            if option < 'a' or option > 'd': raise ValueError

        except ValueError:
            print("Optiune invalida. Introduceti din nou.")
            option = ui.read_option()

        else: break
    return option


def validate_option_menu4(option):
    """
    validarea datelor de intrare pentru meniul sub-cerintei 4
    @param int option: optiunea aleasa de utilizator
    """

    while True:
        try:
            if option < 'a' or option > 'd': raise ValueError

        except ValueError:
            print("Optiune invalida. Introduceti din nou.")
            option = ui.read_option()

        else: break
    return option


def validate_option_menu5(option):
    """
    validarea datelor de intrare pentru meniul sub-cerintei 5
    @param int option: optiunea aleasa de utilizator
    """

    while True:
        try:
            if option < 'a' or option>'c': raise ValueError

        except ValueError:
            print("Optiune invalida. Introduceti din nou.")
            option = ui.read_option()

        else: break
    return option


def validate_score_sum(score):
    """
    validarea scorului citit
    @param int score: scorul introdus de utilizator
    """

    while True:
        try:
            if score < '0':  raise ValueError

        except ValueError:
            print("Optiune invalida. Introduceti din nou.")
            score = ui.read_score()

        else: break
    return score


def validate_bounds(lower_bound,upper_bound,participant_dictionary):
    """
    validarea limitelor intervalului
    @param int lower_bound: limita inferioara a intervalului
    """

    while True:
        try:
            if lower_bound<'1' or lower_bound>str(len(participant_dictionary)) or upper_bound<'1' or upper_bound>str(len(participant_dictionary)) or lower_bound>upper_bound: raise ValueError

        except ValueError:
            print(f"Limitele intervalului trebuie sa fie intre 1 si {len(participant_dictionary)}, iar limita inferioara trebuie sa fie mai mica sau egala decat cea superioara. Introduceti din nou limita inferioara, apoi cea superioara.")
            lower_bound = ui.read_lower_bound()
            upper_bound = ui.read_upper_bound()

        else: break
    return lower_bound, upper_bound


def validate_score(score):
    """
    validarea scorului citit
    @param string score: scorul obtinut de un participant la o anumita proba
    """

    while True:
        try:
            if score<'1' or len(score)==2 and score!='10': raise ValueError

        except ValueError:
            print("Scorul participantului trebuie sa fie un numar intreg, in intervalul [1,10]. Introduceti din nou valoarea.")
            score = ui.read_score()

        else: break
    return score


def validate_participant_number(participant_number,participant_dictionary):
    """
    validarea numarului de concurs al unui participant
    @param string participant_number: numarul de concurs al unui participant
    @param dictionary of lists [int] participant_dictionary: dictionarul participantilor si scorurilor acestora
    """

    while True:
        try:
            if participant_number<'1' or participant_number>str(len(participant_dictionary)): raise ValueError

        except ValueError:
            print(f"Numar de concurs invalid. Numarul de concurs trebuie sa fie in intervalul [1,{len(participant_dictionary)}]. Introduceti din nou valoarea.")
            participant_number = ui.read_participant_number()

        else: break
    return participant_number

def validate_test_number(test_number):
    """
    validarea numarului probei
    @param string test_number: numarul probei
    """

    while True:
        try:
            if test_number<'1' or len(test_number)>1: raise ValueError

        except ValueError:
            print("Numarul probei este invalid. Numarul trebuie sa fie in intervalul [0,9]. Introduceti din nou valoarea.")
            test_number = ui.read_test_number()

        else: break
    return test_number