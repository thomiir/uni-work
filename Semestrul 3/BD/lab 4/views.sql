USE CluburiTenis;

GO
CREATE OR ALTER VIEW View_Terenuri AS
SELECT Id, Locatie, NrMingi
FROM Terenuri;

GO
CREATE OR ALTER VIEW View_RezervariTerenuri AS
SELECT r.Id AS RezervareID, r.Nume AS Client, r.Pret, t.Locatie AS TerenLocatie
FROM Rezervari r
INNER JOIN RezervariTerenuri rt ON r.Id = rt.RezervariId
INNER JOIN Terenuri t ON rt.TerenuriId = t.Id; -- afisam toate rezervarile, clientii, pretul si locatia

GO
CREATE OR ALTER VIEW View_Rezervari AS
SELECT t.Locatie AS TerenLocatie, COUNT(r.Id) AS TotalRezervari, SUM(r.Pret) AS TotalIncasari
FROM Rezervari r
INNER JOIN RezervariTerenuri rt ON r.Id = rt.RezervariId
INNER JOIN Terenuri t ON rt.TerenuriId = t.Id
GROUP BY t.Locatie; -- nr de rezervari si totalul de incasari pentru fiecare locatie

GO
CREATE OR ALTER PROCEDURE viewTableRows
	@tableName VARCHAR(50)
AS
BEGIN
	IF @tableName = 'Terenuri'
	BEGIN
		SELECT * FROM View_Terenuri
	END

	ELSE IF @tableName = 'Rezervari'
	BEGIN
		SELECT * FROM View_Rezervari
	END

	ELSE IF @tableName = 'RezervariTerenuri'
	BEGIN
		SELECT * FROM View_RezervariTerenuri
	END
END

		
	
GO
SELECT * FROM View_Terenuri
SELECT * FROM View_RezervariTerenuri
SELECT * FROM View_Rezervari

GO
DROP VIEW View_Terenuri;
DROP VIEW View_RezervariTerenuri;
DROP VIEW View_Rezervari;