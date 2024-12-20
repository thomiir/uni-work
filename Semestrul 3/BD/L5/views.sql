GO
CREATE OR ALTER VIEW View_Manageri AS
SELECT M.Nume, T.Locatie 
FROM ManageriTerenuri M
INNER JOIN Terenuri T ON T.Id = M.TerenId;

GO
SELECT * FROM View_Manageri

GO
CREATE NONCLUSTERED INDEX index_id ON ManageriTerenuri (TerenId)
CREATE NONCLUSTERED INDEX index_nume ON ManageriTerenuri (Nume)
CREATE NONCLUSTERED INDEX index_tid ON Terenuri (Id)
CREATE NONCLUSTERED INDEX index_locatie ON Terenuri (Locatie)


GO
CREATE OR ALTER VIEW View_Rezervari AS
SELECT t.Locatie AS TerenLocatie, COUNT(r.Id) AS TotalRezervari, SUM(r.Pret) AS TotalIncasari
FROM Rezervari r
INNER JOIN RezervariTerenuri rt ON r.Id = rt.RezervariId
INNER JOIN Terenuri t ON rt.TerenuriId = t.Id
GROUP BY t.Locatie;

GO
SELECT * FROM View_Rezervari

GO
CREATE NONCLUSTERED INDEX index_rid ON RezervariTerenuri (RezervariId)
CREATE NONCLUSTERED INDEX index_tid ON RezervariTerenuri (TerenuriId)
CREATE NONCLUSTERED INDEX index_id ON Rezervari (Id)
CREATE NONCLUSTERED INDEX index_pret ON Rezervari (Pret)



