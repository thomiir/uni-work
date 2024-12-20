import interfata_utilizator as ui
import validator as val
import infrastructura as inf

def menu1(participant_dictionary,stack):
    """
    alegerea unei optiuni pentru meniul sub-cerintei 1
    @param dictionary of lists [int] participant_dictionary: dictionarul participantilor si scorurilor acestora
    """

    while True:
        ui.print_menu1()
        sub_option = ui.read_option()
        sub_option = val.validate_option_menu1(sub_option)
        if sub_option == 'a':
            participant_dictionary_copy = inf.create_deep_copy(participant_dictionary)
            stack.append(participant_dictionary_copy)
            print("Introduceti lista de scoruri obtinute de noul participant.")
            score_list = ui.read_score_list()
            inf.add_score_for_new_participant(participant_dictionary,score_list)
            print(participant_dictionary)

        elif sub_option == 'b':
            participant_dictionary_copy = inf.create_deep_copy(participant_dictionary)
            stack.append(participant_dictionary_copy)
            print("Introduceti numarul participantului caruia doriti sa ii inserati scorul.")
            participant_number = ui.read_participant_number()
            participant_number = val.validate_participant_number(participant_number,participant_dictionary)
            participant_number= int(participant_number)
            print("Introduceti numarul probei asupra careia doriti sa faceti modificari.")
            test_number = ui.read_test_number()
            test_number = val.validate_test_number(test_number)
            test_number = int(test_number)
            print("Introduceti scorul obtinut la acea proba.")
            score = ui.read_score()
            score = val.validate_score(score)
            score = int(score)
            inf.insert_score_for_participant(participant_number,test_number,score,participant_dictionary)

        else:
            break


def menu2(participant_dictionary,stack):
    """
    alegerea unei optiuni din meniul pentru sub-cerinta 2
    @param dictionary of lists [int] participant_dictionary: dictionarul participantilor si scorurilor acestora
    """

    while True:
        ui.print_menu2()
        sub_option = ui.read_option()
        sub_option = val.validate_option_menu2(sub_option)
        if sub_option == 'a':
            participant_dictionary_copy = inf.create_deep_copy(participant_dictionary)
            stack.append(participant_dictionary_copy)
            print("Introduceti numarul de concurs al participantului caruia doriti sa ii stergeti scorul.")
            participant_number = ui.read_participant_number()
            participant_number = val.validate_participant_number(participant_number,participant_dictionary)
            participant_number = int(participant_number)
            inf.delete_score_for_given_participant(participant_number,participant_dictionary)
            print(participant_dictionary)

        elif sub_option == 'b':
            participant_dictionary_copy = inf.create_deep_copy(participant_dictionary)
            stack.append(participant_dictionary_copy)
            print("Introduceti limita inferioara a intervalului.")
            lower_bound = ui.read_lower_bound()
            print("Introduceti limita superioara a intervalului.")
            upper_bound = ui.read_upper_bound()
            lower_bound, upper_bound = val.validate_bounds(lower_bound,upper_bound,participant_dictionary)
            lower_bound = int(lower_bound)
            upper_bound = int(upper_bound)
            inf.delete_score_for_interval_of_participants(lower_bound,upper_bound,participant_dictionary)

        elif sub_option == 'c':
            participant_dictionary_copy = inf.create_deep_copy(participant_dictionary)
            stack.append(participant_dictionary_copy)
            print("Introduceti numarul participantului caruia doriti sa ii inlocuiti scorul.")
            participant_number = ui.read_participant_number()
            participant_number = val.validate_participant_number(participant_number,participant_dictionary)
            participant_number = int(participant_number)
            print("Introduceti lista noua de scoruri a participantului.")
            score_list = ui.read_score_list()
            inf.replace_score_for_given_participant(participant_number,score_list,participant_dictionary)

        else:
            break

    
def menu3(participant_dictionary):
    """
    alegerea unei optiuni din meniul pentru sub-cerinta 3
    @param dictionary of lists [int] participant_dictionary: dictionarul participantilor si scorurilor acestora
    """

    while True:
        ui.print_menu3()
        sub_option = ui.read_option()
        sub_option = val.validate_option_menu3(sub_option)
        if sub_option == 'a':
            print("Introduceti scorul dorit.")
            score = ui.read_score()
            score = val.validate_score_sum(score)
            score = int(score)
            participant_list = inf.get_participants_with_lower_score(score,participant_dictionary)
            print(participant_list)

        elif sub_option == 'b':
            new_list = inf.get_sum_list(participant_dictionary)
            inf.sort_list(new_list)
            print(new_list)

        elif sub_option == 'c':
            print("Introduceti scorul dorit.")
            score = ui.read_score()
            score = val.validate_score_sum(score)
            score = int(score)
            new_list = inf.get_sum_list(participant_dictionary)
            inf.sort_list(new_list)
            sorted_list = inf.get_sorted_list_with_greater_score(score,new_list)
            print(sorted_list)

        else:
            break


def menu4(participant_dictionary):
    """
    alegerea unei optiuni din meniul pentru sub-cerinta 4
    """
    
    while True:
        ui.print_menu4()
        sub_option = ui.read_option()
        sub_option = val.validate_option_menu4(sub_option)
        if sub_option == 'a':
            print("Introduceti limita inferioara a intervalului.")
            lower_bound = ui.read_lower_bound()
            print("Introduceti limita superioara a intervalului.")
            upper_bound = ui.read_upper_bound()
            lower_bound, upper_bound = val.validate_bounds(lower_bound,upper_bound,participant_dictionary)
            lower_bound = int(lower_bound)
            upper_bound = int(upper_bound)
            new_list = inf.get_sum_list(participant_dictionary)
            average_score = inf.calculate_average(lower_bound,upper_bound,new_list)
            print(average_score)

        elif sub_option == 'b':
            print("Introduceti limita inferioara a intervalului.")
            lower_bound = ui.read_lower_bound()
            print("Introduceti limita superioara a intervalului.")
            upper_bound = ui.read_upper_bound()
            lower_bound, upper_bound = val.validate_bounds(lower_bound,upper_bound,participant_dictionary)
            lower_bound = int(lower_bound)
            upper_bound = int(upper_bound)
            new_list = inf.get_sum_list(participant_dictionary)
            min_score = inf.calculate_min(lower_bound,upper_bound,new_list)
            print(min_score)

        elif sub_option == 'c':
            print("Introduceti limita inferioara a intervalului.")
            lower_bound = ui.read_lower_bound()
            print("Introduceti limita superioara a intervalului.")
            upper_bound = ui.read_upper_bound()
            lower_bound, upper_bound = val.validate_bounds(lower_bound,upper_bound,participant_dictionary)
            lower_bound = int(lower_bound)
            upper_bound = int(upper_bound)
            old_list = inf.get_sum_list(participant_dictionary)
            new_list = inf.multiple_of_10_list(lower_bound,upper_bound,old_list)
            print(new_list)

        else:
            break


def menu5(participant_dictionary,stack):
    """
    alegerea unei optiuni din meniul pentru sub-cerinta 5
    """
    
    while True:
        ui.print_menu5()
        sub_option = ui.read_option()
        sub_option = val.validate_option_menu5(sub_option)
        if sub_option == 'a':
            participant_dictionary_copy = inf.create_deep_copy(participant_dictionary)
            stack.append(participant_dictionary_copy)
            print("Introduceti scorul dorit.")
            score = ui.read_score()
            score = val.validate_score_sum(score)
            score = int(score)
            inf.filter_by_score_multiple(score,participant_dictionary)
            print(participant_dictionary)

        elif sub_option == 'b':
            participant_dictionary_copy = inf.create_deep_copy(participant_dictionary)
            stack.append(participant_dictionary_copy)
            print("Introduceti scorul dorit.")
            score = ui.read_score()
            score = val.validate_score_sum(score)
            score = int(score)
            inf.filter_lesser_than_score(score,participant_dictionary)
            print(participant_dictionary)
            

        else:
            break


def choose_option_main_menu(participant_dictionary):
    """
    alegerea unei optiuni pentru meniul principal
    @param dictionary of lists [int] participant_dictionary: dictionarul participantilor si scorurilor acestora
    """

    stack = []
    while True:
        print("Dictionarul curent de participanti, alaturi de scorurile lor este:")
        print(participant_dictionary)
        ui.print_main_menu()
        option = ui.read_option()
        option = val.validate_option_main_menu(option)
        if option == '1':
            menu1(participant_dictionary,stack)

        elif option == '2':
            menu2(participant_dictionary,stack) 

        elif option == '3':
            menu3(participant_dictionary)

        elif option == '4':
            menu4(participant_dictionary)

        elif option == '5':
            menu5(participant_dictionary,stack)

        elif option == '6':
            participant_dictionary = inf.undo_last_operation(participant_dictionary,stack)

        elif option == '7':
            batch_participant_dictionary = {}
            command_list = ui.read_batch_mode()
            command_list = inf.split_list(command_list)
            command_list = inf.batch_menu(command_list)
            
            for i in range(0,len(command_list)):
                if command_list[i][0] == 'add':
                    stack.append(inf.create_deep_copy(batch_participant_dictionary))
                    score_list = inf.create_score_list(command_list[i][1])
                    score_list = inf.convert_to_int_score_list(score_list)
                    inf.add_score_for_new_participant(batch_participant_dictionary,score_list)
                    print(batch_participant_dictionary)

                elif command_list[i][0] == 'delete':
                    stack.append(inf.create_deep_copy(batch_participant_dictionary))
                    inf.delete_score_for_given_participant(int(command_list[i][1]),batch_participant_dictionary)
                    print(batch_participant_dictionary)

                elif command_list[i][0] == 'filter':
                    stack.append(inf.create_deep_copy(batch_participant_dictionary))
                    inf.filter_lesser_than_score(int(command_list[i][1]),batch_participant_dictionary)
                    print(batch_participant_dictionary)

                elif command_list[i][0] == 'undo':
                    batch_participant_dictionary = inf.undo_last_operation(batch_participant_dictionary,stack)
        
        else:
            break
