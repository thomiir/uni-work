GO
USE CluburiTenis
GO

GO
CREATE OR ALTER PROCEDURE deleteTableRows
	@tableName VARCHAR(50),
	@noOfRows INT
AS
BEGIN
	DECLARE @contor INT
	SET @contor = 1

	WHILE @contor <= @noOfRows
	BEGIN
 		IF @tableName = 'Rezervari'
			DELETE FROM RezervariTest WHERE RezervariTest.Id = @contor

		ELSE IF @tableName = 'RezervariTerenuri'
			DELETE FROM RezervariTerenuriTest WHERE RezervariTerenuriTest.RezervariId = @contor AND
													RezervariTerenuriTest.TerenuriId = @contor

		ELSE IF @tableName = 'Terenuri'
			DELETE FROM TerenuriTest WHERE TerenuriTest.Id = @contor

		SET @contor = @contor + 1
	END
END;


SELECT * FROM RezervariTest;
SELECT * FROM TerenuriTest;
SELECT * FROM RezervariTerenuriTest;

EXEC deleteTableRows RezervariTerenuri, 10000;
EXEC deleteTableRows Terenuri, 10000;
EXEC deleteTableRows Rezervari, 10000;