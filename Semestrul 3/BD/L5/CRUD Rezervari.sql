USE CluburiTenis
GO
CREATE OR ALTER PROCEDURE CRUD_Rezervari
	@Nume VARCHAR(50),
	@Pret FLOAT
AS
BEGIN
	SET NOCOUNT ON
	IF (dbo.isRezervariPriceValid(@Pret) = 1)
	BEGIN
		INSERT INTO Rezervari VALUES(@Nume, @Pret)
		
		SELECT * FROM Rezervari

		UPDATE Rezervari SET Rezervari.Nume = @Nume + '_CRUD' WHERE Rezervari.Nume = @Nume

		SELECT * FROM Rezervari

		DELETE FROM Rezervari WHERE Rezervari.Nume LIKE @Nume + '_CRUD'

		SELECT * FROM Rezervari

		PRINT 'S-au realizat cu succes operatiile CRUD pentru tabela Rezervari'
	END

	ELSE
	BEGIN
		RAISERROR('Eroare la validare', 16, 1)
	END
END

EXEC CRUD_Rezervari 'Nume', 50; -- eroare la validare, pretul este prea mic
EXEC CRUD_Rezervari 'Nume', 500;