import meniuri as menus
import teste as tests

def start():
    """
    functia principala de start
    """

    tests.all_tests()
    participant_dictionary={}
    menus.choose_option_main_menu(participant_dictionary)


start()