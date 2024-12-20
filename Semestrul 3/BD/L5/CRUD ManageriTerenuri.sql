USE CluburiTenis
GO
CREATE OR ALTER PROCEDURE CRUD_ManageriTerenuri
	@Id INT, 
	@Nume varchar(50)
AS
BEGIN
	SET NOCOUNT ON
	IF (dbo.isManageriForeignKeyValid(@Id) = 1)
	BEGIN
		INSERT INTO ManageriTerenuri VALUES(@Id, @Nume)
		
		SELECT * FROM ManageriTerenuri

		UPDATE ManageriTerenuri SET ManageriTerenuri.Nume = @Nume + '_CRUD' WHERE ManageriTerenuri.Nume = @Nume

		SELECT * FROM ManageriTerenuri

		DELETE FROM ManageriTerenuri WHERE ManageriTerenuri.Nume LIKE @Nume + '_CRUD'

		SELECT * FROM ManageriTerenuri

		PRINT 'S-au realizat cu succes operatiile CRUD pentru tabela Cluburi'
	END

	ELSE
	BEGIN
		RAISERROR('Eroare la validare', 16, 1)
	END
END

EXEC CRUD_ManageriTerenuri 1, 'NumeManager'; -- eroare la validare, nu exista un teren cu id-ul 1
EXEC CRUD_ManageriTerenuri 10179, 'NumeManager';

select * from terenuri