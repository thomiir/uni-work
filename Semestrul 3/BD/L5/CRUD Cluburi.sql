USE CluburiTenis
GO
CREATE OR ALTER PROCEDURE CRUD_Cluburi
	@Nume VARCHAR(50),
	@Adresa VARCHAR(50),
	@NrClienti INT
AS
BEGIN
	SET NOCOUNT ON
	IF (dbo.isClientNumberValid(@NrClienti) = 1)
	BEGIN
		INSERT INTO Cluburi VALUES(@Nume, @Adresa, @NrClienti)
		
		SELECT * FROM Cluburi

		UPDATE Cluburi SET Cluburi.Nume = @Nume + '_CRUD' WHERE Cluburi.Nume = @Nume

		SELECT * FROM Cluburi

		DELETE FROM Cluburi WHERE Cluburi.Nume LIKE @Nume + '_CRUD'

		SELECT * FROM Cluburi

		PRINT 'S-au realizat cu succes operatiile CRUD pentru tabela Cluburi'
	END

	ELSE
	BEGIN
		RAISERROR('Eroare la validare', 16, 1)
	END
END

EXEC CRUD_Cluburi 'NumeClub', 'AdresaClub', 5; -- eroare la validare, nr clienti prea mic
EXEC CRUD_Cluburi 'NumeClub', 'AdresaClub', 20;