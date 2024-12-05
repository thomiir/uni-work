USE CluburiTenis
GO

/*
Terenuri - 1 PK, 1 FK
Rezervari - 1 PK
RezervariTerenuri - 2 PK
*/

GO
CREATE OR ALTER PROCEDURE insertTableRows 
	@tableName VARCHAR(50),
	@noOfRows INT
AS
BEGIN

	DECLARE @contor INT
	SET @contor = 1

	WHILE @contor <= @noOfRows
	BEGIN		
		IF @tableName = 'Terenuri'
		BEGIN
			DECLARE @Locatie VARCHAR(50)
			DECLARE @NrMingi INT
			DECLARE @NumeClub VARCHAR(50)

			SET @Locatie = 'Locatie' + CONVERT(VARCHAR(7), @contor)
			SET @NrMingi = floor(RAND() * 50)
			SELECT TOP 1 @NumeClub = Nume FROM CluburiTest ORDER BY NEWID()

			INSERT INTO TerenuriTest(Id, Locatie, NrMingi, NumeClub) 
			VALUES (@contor, @Locatie, @NrMingi, @NumeClub)
	   END
		
		ELSE IF @tableName = 'Rezervari'
		BEGIN
			DECLARE @Nume VARCHAR(50)
			DECLARE @Pret FLOAT

			SET @Nume = 'Rezervare' + CONVERT(VARCHAR(7), @contor)
			SET @Pret = floor(RAND() * 100)
			
			INSERT INTO RezervariTest(Id, Nume, Pret)
			VALUES (@contor, @Nume, @Pret)
		END

		ELSE IF @tableName = 'RezervariTerenuri'
		BEGIN
			DECLARE @idRezervare INT
			DECLARE cursorRezervari CURSOR FAST_FORWARD FOR

			SELECT Id FROM RezervariTest;
			OPEN cursorRezervari
			FETCH NEXT FROM cursorRezervari INTO @idRezervare;
			WHILE @@FETCH_STATUS=0	
			BEGIN
				INSERT INTO RezervariTerenuriTest(RezervariId, TerenuriId)
			    VALUES (@idRezervare, @idRezervare)
				SET @contor = @contor + 1
				FETCH NEXT FROM cursorRezervari INTO @idRezervare;
			END

			CLOSE cursorRezervari;
			DEALLOCATE cursorRezervari
			
		END
		SET @contor = @contor + 1
	END
	
END

GO
USE CluburiTenis
EXEC insertTableRows Rezervari, 10000;
EXEC insertTableRows Terenuri, 10000;
EXEC insertTableRows RezervariTerenuri, 10000;

SELECT * FROM RezervariTest;
SELECT * FROM TerenuriTest;
SELECT * FROM RezervariTerenuriTest;

DELETE FROM RezervariTerenuriTest
DELETE FROM RezervariTest
DELETE FROM TerenuriTest
