USE CluburiTenis
GO
CREATE OR ALTER PROCEDURE CRUD_RezervariTerenuri
	@RezervareId INT,
	@TerenId INT
AS
BEGIN
	SET NOCOUNT ON
	IF (dbo.isRezervariTerenuriForeignKeyValid(@TerenId, @RezervareId) = 1)
	BEGIN
		INSERT INTO RezervariTerenuri VALUES(@RezervareId, @TerenId)
		
		SELECT * FROM RezervariTerenuri

		PRINT ('update')

		DELETE FROM RezervariTerenuri WHERE RezervariTerenuri.RezervariId = @RezervareId AND RezervariTerenuri.TerenuriId = @TerenId

		SELECT * FROM RezervariTerenuri

		PRINT 'S-au realizat cu succes operatiile CRUD pentru tabela RezervariTerenuri'
	END

	ELSE
	BEGIN
		RAISERROR('Eroare la validare', 16, 1)
	END
END

EXEC CRUD_RezervariTerenuri 1, 1 -- eroare la validare, cheile nu exista
EXEC CRUD_RezervariTerenuri 10014, 1 -- eroare la validare, cheia nu exista in tabela Terenuri
EXEC CRUD_RezervariTerenuri 1, 10179 -- eroare la validare, cheia nu exista in tabela Rezervari
EXEC CRUD_RezervariTerenuri 10014, 10179