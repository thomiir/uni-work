USE CluburiTenis
GO
CREATE OR ALTER PROCEDURE CRUD_Terenuri
	@Locatie VARCHAR(50),
	@NrMingi INT,
	@NumeClub VARCHAR(50)
AS
BEGIN
	SET NOCOUNT ON
	IF (dbo.isTerenForeignKeyValid(@NumeClub) = 1)
	BEGIN
		INSERT INTO Terenuri VALUES(@Locatie, @NrMingi, @NumeClub)
		
		SELECT * FROM Terenuri

		UPDATE Terenuri SET Terenuri.Locatie = @Locatie + '_CRUD' WHERE Terenuri.Locatie = @Locatie

		SELECT * FROM Terenuri

		DELETE FROM Terenuri WHERE Terenuri.Locatie LIKE @Locatie + '_CRUD'

		SELECT * FROM Terenuri

		PRINT 'S-au realizat cu succes operatiile CRUD pentru tabela Terenuri'
	END

	ELSE
	BEGIN
		RAISERROR('Eroare la validare', 16, 1)
	END
END

EXEC CRUD_Terenuri 'Locatie', 50, 'NumeClub'; -- eroare la validare, numele clubului nu exista in tabela
EXEC CRUD_Terenuri 'Locatie', 50, 'Club Tenis ProSport';