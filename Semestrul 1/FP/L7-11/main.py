from domain.validator import BookValidator
from domain.validator import ClientValidator
#from repository.book_repository import BookInMemoryRepository
from repository.file_repository import BookInFileRepository, ClientInFileRepository
#from repository.client_repository import ClientInMemoryRepository
from repository.rentals_repository import RentalInMemoryRepository
from service.book_service import BookController
from service.client_service import ClientController
from service.rentals_service import RentalController
from ui.console import Console
from tests.repository_tests import run_repository_tests
from tests.service_tests import run_service_tests
from tests.domain_tests import run_domain_tests
from tests.console_tests import run_console_tests

#book_repository = BookInMemoryRepository()
book_repository = BookInFileRepository("fisier_carti.txt")
#client_repository = ClientInMemoryRepository()
client_repository = ClientInFileRepository("fisier_clienti.txt")
rental_repository = RentalInMemoryRepository()
book_validator = BookValidator()
client_validator = ClientValidator()
book_controller = BookController(book_repository, book_validator)
client_controller = ClientController(client_repository, client_validator)
rental_controller = RentalController(rental_repository)
console = Console(book_controller, client_controller, rental_controller)
run_repository_tests()
run_service_tests()
run_domain_tests()
run_console_tests()
console.run()
