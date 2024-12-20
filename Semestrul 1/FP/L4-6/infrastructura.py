def add_score_for_new_participant(participant_dictionary,score_list):
    """
    adaugarea listei de scoruri a unui nou participant in dictionar
    @param dictionary of lists [int] participant_dictionary: dictionarul participantilor si scorurilor acestora
    @param list[int] score_list: lista de scoruri a unui participant
    """

    participant_dictionary[len(participant_dictionary)+1]=[0,0,0,0,0,0,0,0,0,0]
    for i in range(0,10):
        participant_dictionary[len(participant_dictionary)][i]=score_list[i]


def insert_score_for_participant(participant_number,test_number,score,participant_dictionary):
    """
    inserarea listei de scoruri pentru un participant anume
    @param int participant_number: numarul de concurs al unui participant
    @param int test_number: numarul probei
    @param int score: scorul obtinut la acea proba
    @param dictionary of lists [int] participant_dictionary: dictionarul participantilor si scorurilor acestora
    """
    
    participant_dictionary[participant_number][test_number] = score


def create_deep_copy(participant_dictionary):
    """
    crearea unei copii a dictionarului participant_dictionary
    """

    participant_dictionary_copy = {}
    for key in participant_dictionary.keys():
        participant_dictionary_copy[key] = participant_dictionary[key][:]
    return participant_dictionary_copy


def delete_score_for_given_participant(participant_number,participant_dictionary):
    """
    stergerea scorului pentru un anumit participant
    @param int participant_number: numarul de concurs al participantului caruia dorim sa ii stergem scorul
    @param dictionary of lists [int] participant_dictionary: dictionarul participantilor si scorurilor acestora
    """

    for i in range(0,10):
        participant_dictionary[participant_number][i]=0


def delete_score_for_interval_of_participants(lower_bound,upper_bound,participant_dictionary):
    """
    stergerea scorului pentru un interval dat de participanti
    @param int lower_bound: limita inferioara a intervalului
    @param int upper_bound: limita superioara a intervalului
    @param dictinary of lists [int] participant_dictionary: dictionarul participantilor si scorurilor acestora
    """

    for i in range(lower_bound,upper_bound+1):
        delete_score_for_given_participant(i,participant_dictionary)


def replace_score_for_given_participant(participant_number,score_list,participant_dictionary):
    """
    inlocuirea scorului pentru un participant anume
    @param int participant_number: numarul de concurs al unui participant
    @param list[int] score_list: lista de scoruri a participantului participant_number
    @param dictionary of lists [int] participant_dictionary: dictionarul participantilor si scorurilor acestora
    """

    for i in range(0,10):
        participant_dictionary[participant_number][i]=score_list[i]



def get_participants_with_lower_score(score,participant_dictionary):
    """
    crearea unui nou dictionar, care contine participantii care au scor mai mic decat un scor dat
    @param int score: scorul 
    @param dictionary of lists [int] participant_dictionary: dictionarul participantilor si scorurilor acestora
    @return list of lists [[int,int]] participant_list: lista de liste, contine pe pozitia i numarul de concurs al participantului i, precum si scorul acestuia
    """

    participant_list=[]
    for i in range(1,len(participant_dictionary)+1):
        score_sum = 0
        for j in range(0,10):
            score_sum = score_sum + participant_dictionary[i][j]
        if score_sum < score:
            participant_list.append([i,score_sum])
    return participant_list


def get_sum_list(participant_dictionary):
    """
    crearea unei noi liste care sa contina doar numarul de concurs al participantului si scorul acestuia
    @param dictionary of lists [int] participant_dictionary: dictionarul participantilor si scorurilor acestora
    @return list[list[int,int]] new_list: lista de liste, contine pe pozitia i doar numarul de concurs al participantului i si scorul acestuia
    """

    new_list=[]
    for i in range(1,len(participant_dictionary)+1):
        score_sum = 0
        for j in range(0,10):
            score_sum = score_sum + participant_dictionary[i][j]
        new_list.append([i,score_sum])
    return new_list


def sort_list(new_list):
    """
    sortarea listei in functie de scor
    @param list[list[int,int]] new_list: lista de liste, contine pe pozitia i doar numarul de concurs al participantului i si scorul acestuia
    """

    aux_list=[]
    b=0
    e=1
    while b==0:
        b=1
        for i in range(0,len(new_list)-e):
            if new_list[i][1]>new_list[i+1][1]:
                aux_list=new_list[i]
                new_list[i]=new_list[i+1]
                new_list[i+1]=aux_list
                b=0
        e=e+1


def get_sorted_list_with_greater_score(score,new_list):
    """
    crearea unei liste care sa contina numarul de concurs al participantilor, cu scorul mai mare decat un scor anume (sortata crescator)
    @param int score: scorul citit de la tastatura
    @param list[list[int,int]] new_list: lista de liste, contine pe pozitia i doar numarul de concurs al participantului i si scorul acestuia
    """

    sorted_list=[]
    for i in range(0,len(new_list)):
        if new_list[i][1]>score:
            sorted_list.append([new_list[i][0],new_list[i][1]])
    return sorted_list


def calculate_average(lower_bound,upper_bound,new_list):
    """
    calcularea mediei aritmetice a scorurilor participantilor dintr-un interval dat
    @param int lower_bound: limita inferioara a intervalului
    @param int upper_bound: limita superioara a intervalului
    @param list[list[int,int]]: lista de liste, contine numarul de concurs al participantului si scorul acestora
    @return float average
    """
    
    sum=0
    for i in range(lower_bound-1,upper_bound):
        sum = sum + new_list[i][1]
    return sum/(upper_bound-lower_bound+1)


def calculate_min(lower_bound,upper_bound,new_list):
    """
    calcularea mediei aritmetice a scorurilor participantilor dintr-un interval dat
    @param int lower_bound: limita inferioara a intervalului
    @param int upper_bound: limita superioara a intervalului
    @param list[list[int,int]]: lista de liste, contine numarul de concurs al participantului si scorul acestora
    @return float average
    """
    
    min_score = new_list[lower_bound-1][1]
    for i in range(lower_bound,upper_bound):
        if new_list[i][1] < min_score:
            min_score = new_list[i][1]
    return min_score


def multiple_of_10_list(lower_bound,upper_bound,old_list):
    """
    crearea unei noi liste care sa contina doar participantii dintr-un interval dat cu scorul multiplu de 10
    @param int lower_bound: limita inferioara a intervalului
    @param int upper_bound: limita superioara a intervalului
    @param list[list[int,int]] old_list: lista de liste, contine numarul de concurs al participantului si scorul acestora
    @return list[list[int,int]] new_list: lista de liste, contine numarul de concurs al participantului si scorul acestora
    """

    new_list = []
    for i in range(lower_bound-1,upper_bound):
        if old_list[i][1] % 10 ==0:
            new_list.append([old_list[i][0],old_list[i][1]])
    return new_list


def filter_by_score_multiple(score,participant_dictionary):
    """
    filtrarea participantilor din dictionar care au scorul multiplu variabilei score
    @param int score: scorul
    @param dictionary of lists [int] participant_dictionary: dictionarul participantilor si scorurilor acestora
    """

    for i in range(1,len(participant_dictionary)+1):
        sum = 0
        for j in range(0,10):
            sum = sum + participant_dictionary[i][j]
        if sum % score != 0:
            delete_score_for_given_participant(i,participant_dictionary)


def filter_lesser_than_score(score,participant_dictionary):
    """
    filtrarea participantilor din dictionar care au scorul mai mic decat un scor dat
    @param int score: scorul
    @param dictionary of lists [int] participant_dictionary: dictionarul participantilor si scorurilor acestora
    """

    for i in range(1,len(participant_dictionary)+1):
        sum = 0
        for j in range(0,10):
            sum = sum + participant_dictionary[i][j]
        if sum > score:
            delete_score_for_given_participant(i,participant_dictionary)

    
def undo_last_operation(participant_dictionary,stack):
    """
    undoes the last operation on the participant_dictionary with the help of a stack
    """

    if len(stack) == 0:
        print("Nu mai exista operatii de refacut.")
        return []
    else:
        participant_dictionary = stack.pop()
        print("Ultima operatie a fost refacuta cu succes.")
        print(participant_dictionary)
    return participant_dictionary


def split_list(command_list):
    """
    impartirea listei pe comenzi
    """

    return command_list.split(";")


def batch_menu(command_list):
    """
    
    """

    for i in range(0,len(command_list)):
        command_list[i] = command_list[i].split(" ")
    return command_list


def create_score_list(command_list):
    """

    """
    new_list = command_list.split(",")
    return new_list

def convert_to_int_score_list(score_list):
    for i in range(0,len(score_list)):
        score_list [i] = int(score_list[i])
    return score_list
