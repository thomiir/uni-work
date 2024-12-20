import infrastructura as inf

def test_add_score_for_new_participant():
    """
    test pentru add_score_for_new_participant
    """ 

    participant_dictionary = {}
    score_list = [1,2,3,4,5,6,7,8,9,10]
    inf.add_score_for_new_participant(participant_dictionary,score_list)
    assert participant_dictionary == {1:[1,2,3,4,5,6,7,8,9,10]}


def test_insert_score_for_new_participant():
    """
    test pentru insert_score_for_new_participant
    """

    participant_dictionary = {1:[1,2,3,4,5,6,7,8,9,10]}
    inf.insert_score_for_participant(1,0,10,participant_dictionary)
    assert participant_dictionary == {1:[10,2,3,4,5,6,7,8,9,10]}


def test_delete_score_for_given_participant():
    """
    test pentru delete_score_for_given_participant
    """

    participant_dictionary = {1:[1,2,3,4,5,6,7,8,9,10]}
    inf.delete_score_for_given_participant(1,participant_dictionary)
    assert participant_dictionary == {1:[0,0,0,0,0,0,0,0,0,0]}


def test_delete_score_for_interval_of_participants():
    """
    test pentru delete_score_for_interval_of_participants
    """

    participant_dictionary = {1:[1,2,3,4,5,6,7,8,9,10],2:[1,2,3,4,5,6,7,8,9,10],3:[1,2,3,4,5,6,7,8,9,10]}
    inf.delete_score_for_interval_of_participants(1,2,participant_dictionary)
    assert participant_dictionary == {1:[0,0,0,0,0,0,0,0,0,0],2:[0,0,0,0,0,0,0,0,0,0],3:[1,2,3,4,5,6,7,8,9,10]}


def test_replace_score_for_given_participant():
    """
    test pentru replace_score_for_given_participant
    """

    participant_dictionary = {1:[0,0,0,0,0,0,0,0,0,0]}
    score_list = [1,2,3,4,5,6,7,8,9,10]
    inf.replace_score_for_given_participant(1,score_list,participant_dictionary)
    assert participant_dictionary == {1:[1,2,3,4,5,6,7,8,9,10]}


def test_get_participants_with_lower_score():
    """
    test pentru get_participants_with_lower_score
    """

    participant_dictionary = {1:[1,2,3,4,5,6,7,8,9,10],2:[3,3,3,3,3,3,3,3,3,3],3:[4,4,4,4,4,4,4,4,4,4]}
    assert inf.get_participants_with_lower_score(50,participant_dictionary) == [[2,30],[3,40]]


def test_calculate_average():
    """
    test pentru calculate_average
    """

    score_list = [[1,55],[2,30]]
    assert inf.calculate_average(1,2,score_list) == 42.5
    assert inf.calculate_average(1,1,score_list) == 55.0


def test_calculate_min():
    """
    test pentru calculate_min
    """

    score_list = [[1,55],[2,30]]
    assert inf.calculate_min(1,2,score_list) == 30


def test_multiple_of_10_list():
    """
    test pentru multiple_of_10_list
    """
    
    score_list = [[1,55],[2,30],[3,10]]
    assert inf.multiple_of_10_list(1,3,score_list) == [[2,30],[3,10]]


def test_filter_by_score_multiple():
    """
    test pentru filter_by_score_multiple
    """

    participant_dictionary = {1:[1,2,3,4,5,6,7,8,9,10]}
    inf.filter_by_score_multiple(10,participant_dictionary)
    assert participant_dictionary == {1:[0,0,0,0,0,0,0,0,0,0]}


def test_filter_lesser_than_score():
    """
    test pentru filter_lesser_than_score
    """

    dictionary = {1:[1,2,3,4,5,6,7,8,9,10],2:[3,3,3,3,3,3,3,3,3,3],3:[4,4,4,4,4,4,4,4,4,4]}
    inf.filter_lesser_than_score(50,dictionary)
    assert dictionary == {1:[0,0,0,0,0,0,0,0,0,0],2:[3,3,3,3,3,3,3,3,3,3],3:[4,4,4,4,4,4,4,4,4,4]}


def all_tests():
    test_add_score_for_new_participant()
    test_calculate_average()
    test_calculate_min()
    test_delete_score_for_given_participant()
    test_delete_score_for_interval_of_participants()
    test_filter_by_score_multiple()
    test_filter_lesser_than_score()
    test_get_participants_with_lower_score()
    test_insert_score_for_new_participant()
    test_multiple_of_10_list()
    test_replace_score_for_given_participant()