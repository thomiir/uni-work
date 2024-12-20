from domain.client import Client
from domain.validator import ClientValidator
from repository.client_repository import ClientInMemoryRepository
import random
import string

class ClientController:
    def __init__(self, repository: ClientInMemoryRepository, client_validator: ClientValidator):
        """
        initializeaza controller-ul de clienti
        :param repository: repository-ul de clienti
        :param client_validator: validatorul de clienti
        """

        self.__client_validator = client_validator
        self.__repository = repository

    def add_client(self, id, name, cnp, no_rentals):
        """
        adauga un client in repository
        :param id: id-ul clientului
        :param name: numele clientului
        :param cnp: cnp-ul clientului
        :param no_rentals: numarul de inchirieri al clientului
        :raises ValueError: daca clientul nu este valid
        """

        client = Client(id, name, cnp, no_rentals)
        self.__client_validator.validate_client(client)
        self.__repository.store(client)

    def delete_client(self, id):
        """
        sterge un client
        :param id: id-ul clientului de sters
        :raises ValueError: daca nu exista un client cu id-ul dat
        """

        return self.__repository.delete(id)

    def delete_all_clients(self):
        """
        sterge toti clientii
        """

        for i in range(0, self.__repository.size()):
            self.__repository.delete(i)

    def update_client(self, id, name, cnp, no_rentals):
        """
        modifica un client
        :param id: id-ul clientului de modificat
        :param name: noul nume al clientului
        :param cnp: noul cnp al clientului
        :param no_rentals: noul numar de inchirieri al clientului
        :raises ValueError: daca clientul nu este valid
        """

        new_client = Client(id, name, cnp, no_rentals)
        self.__client_validator.validate_client(new_client)
        self.__repository.update(id,new_client)

    def get_all_clients(self):
        """
        getter pentru lista de clienti
        :return: lista de clienti
        """

        return self.__repository.get_current_list()

    def filter_by_id(self, id):
        """
        filtreaza clientii dupa id
        :param id: id-ul dupa care se filtreaza
        :return: lista de clienti filtrata dupa id
        """

        return [client for client in self.__repository.get_current_list() if client.get_id() == id]

    def filter_by_name(self, name):
        """
        filtreaza clientii dupa nume
        :param name: numele dupa care se filtreaza
        :return: lista de clienti filtrata dupa nume
        """

        return [client for client in self.__repository.get_current_list() if client.get_name() == name]

    def find_client_by_id(self, id):
        """
        cauta un client dupa id
        :param id: id-ul clientului cautat
        :return: clientul cu id-ul dat sau None daca nu exista
        """

        for client in self.get_all_clients():
            if client.get_id() == id:
                return client
        return None

    def sort_by_number_of_books(self, report_list):
        """
        sorteaza raportul dupa numarul de carti inchiriate
        :param report_list: raportul generat
        :return: raportul sortat
        """

        report_list = self.insertSort(report_list, key=lambda x: x[0], reversed=True)
        return report_list

    @staticmethod
    def insertSort(list, key=None, reversed=False):
        """
        ANALIZA COMPLEXITATE:
        cazul mediu: O(n^2)
        worst case: numarul maxim de iteratii - atunci cand lista este ordonata invers
        best case: lista este sortata
        functie care sorteaza raportul folosind sortarea prin insertie
        :param list:
        :param key: functia dupa care se sorteaza
        :param reversed: ordinea dupa care se sorteaza
        :return: lista sortata
        """

        if not reversed:  # sortare in ordine crescatoare
            for i in range(1, len(list)):
                ind = i - 1
                a = list[i]
                while ind >= 0 and key(a) < key(list[ind]):
                    list[ind + 1] = list[ind]
                    ind = ind - 1
                list[ind + 1] = a
            return list

        else:  # sortare in ordine descrescatoare
            for i in range(1, len(list)):
                ind = i - 1
                a = list[i]
                while ind >= 0 and key(a) > key(list[ind]):
                    list[ind + 1] = list[ind]
                    ind = ind - 1
                list[ind + 1] = a
            return list

    def sort_by_name(self, report_list):
        """
        sorteaza raportul dupa nume
        :param report_list: raportul generat
        :return: raportul sortat
        """

        report_list = self.insertSort(report_list, key=lambda x: x[1].get_name(), reversed=False)
        return report_list

    def generate_random_clients(self, number):
        """
        genereaza number random clienti
        :param number: numarul de clienti de generat
        """

        for i in range(0, number):
            client_id = i
            client_name = ''.join(random.choices(string.ascii_lowercase, k=5))
            client_cnp = random.randint(5000000000000, 6000000000000)
            client_cnp = str(client_cnp)
            client_no_rentals = random.randint(0, number)
            client = Client(client_id, client_name, client_cnp, client_no_rentals)
            self.__repository.store(client)
