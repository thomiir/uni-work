USE CluburiTenis
GO

INSERT INTO Cluburi(Nume, Adresa, NrClienti)
VALUES ('Club Tenis ProSport', 'blvd. Primaverii nr. 25 Timisoara', 100)

INSERT INTO Competitii(Nume, Punctaj, Premiu, NumeClub)
VALUES ('Concurs primavara', 250, 30000, 'Club Tenis ProSport'),
       ('Concurs vara', 250, 30000, 'Club Tenis ProSport'),
	   ('Concurs toamna', 250, 30000, 'Club Tenis ProSport'),
	   ('Concurs iarna', 250, 30000, 'Club Tenis ProSport'),
	   ('Turneul Campionilor', 1000, 500000, 'Club Tenis ProSport') 

INSERT INTO Angajati(Nume, Cnp, Functie, NumeClub)
VALUES ('Ion Popescu', 196502148, 'Antrenor', 'Club Tenis ProSport'),
	   ('Maria Ionescu', 198703219, 'Manager', 'Club Tenis ProSport'),
	   ('Andrei Georgescu', 200110257, 'Antrenor', 'Club Tenis ProSport'),
	   ('Elena Vasilescu', 199201186, 'Fizioterapeut', 'Club Tenis ProSport'),
	   ('Radu Mihailescu', 197905035, 'Asistent', 'Club Tenis ProSport'),
	   ('Mihai Nistor', 199811215, 'Antrenor', 'Club Tenis ProSport'),
	   ('Oana Radu', 199303208, 'Antrenor', 'Club Tenis ProSport')


INSERT INTO Echipe(Nume, Nivel, Tip, NumeClub)
VALUES ('Rachetele de aur', 'incepator', 'mixt', 'Club Tenis ProSport'),
	   ('Academia de tenis Galati', 'mediu', 'feminin', 'Club Tenis ProSport'),
	   ('Sportivii clujeni', 'avansat', 'masculin', 'Club Tenis ProSport'),
	   ('Tenis club Bucuresti', 'incepator', 'feminin', 'Club Tenis ProSport')

INSERT INTO Antrenori(Cnp, Nume, Strategie, NumeEchipa)
VALUES (196502148, 'Ion Popescu', 'tare si pe centru', 'Rachetele de aur'),
	   (200110257, 'Andrei Georgescu', 'tare si pe centru', 'Rachetele de aur'),
	   (199811215, 'Mihai Nistor', 'tare si pe colt', 'Sportivii clujeni'),
	   (199303208, 'Oana Radu', 'cu efect si langa fileu', 'Tenis club Bucuresti')

INSERT INTO Jucatori(Cnp, Nume, Experienta, NumeEchipa)
VALUES (135792468, 'Vlad Stanescu', 10, 'Rachetele de aur'),
	   (246813579, 'Laura Marin', 1, 'Rachetele de aur'),
	   (369258147, 'Cristian Dobre', 2, 'Academia de tenis Galati'),
	   (741852963, 'Bianca Radulescu', 5, 'Sportivii clujeni'),
	   (159753468, 'Sorin Petrescu', 2, 'Tenis club Bucuresti'),
	   (852963741, 'Oana Munteanu', 3, 'Academia de tenis Galati')

INSERT INTO Terenuri(Locatie, NrMingi, NumeClub)
VALUES ('NE', 200, 'Club Tenis ProSport'),
	   ('SV', 300, 'Club Tenis ProSport'),
	   ('NV', 50, 'Club Tenis ProSport'),
	   ('E', 20, 'Club Tenis ProSport')

INSERT INTO ManageriTerenuri(TerenId, Nume)
VALUES (1, 'Larisa Pop'),
	   (2, 'Adelina Conu'),
	   (3, 'Vlad Radulescu'),
	   (4, 'Laura Munteanu')

INSERT INTO Rezervari(Nume, Pret)
VALUES ('Mihai Andreev', 200),
	   ('Daniela Costin', 300),
	   ('Raluca Neagu', 100),
	   ('Gabriel Toma', 50),
	   ('Simona Paun', 100),
	   ('Florin Ionescu', 50)

INSERT INTO RezervariTerenuri(RezervariId, TerenuriId)
VALUES (1, 1),
	   (1, 2),
	   (1, 3),
	   (2, 4),
	   (3, 1),
	   (4, 2),
	   (5, 4),
	   (6, 1),
	   (6, 2)

INSERT INTO Cluburi (Nume, Adresa, NrClienti)
VALUES ('Club Tenis Elite', 'str. Sporturilor nr. 10, Cluj-Napoca', 75);

INSERT INTO Angajati (Cnp, Nume, Functie, NumeClub)
VALUES (198712345, 'Alex Buzatu', 'Antrenor', 'Club Tenis Elite'),
       (197623451, 'Irina Dumitrescu', 'Manager', 'Club Tenis Elite'),
       (199803567, 'Sergiu Marcu', 'Asistent', 'Club Tenis Elite');

INSERT INTO Competitii (Nume, Punctaj, Premiu, NumeClub)
VALUES ('Turneu Cluj Open', 300, 150000, 'Club Tenis Elite'),
       ('Campionatul de vara', 500, 100000, 'Club Tenis Elite');

INSERT INTO Terenuri (Locatie, NrMingi, NumeClub)
VALUES ('SE', 150, 'Club Tenis Elite'),
       ('N', 100, 'Club Tenis Elite');

INSERT INTO ManageriTerenuri (TerenId, Nume)
VALUES (5, 'Maria Pop'),
       (6, 'George Rotaru');

INSERT INTO Echipe (Nume, Nivel, Tip, NumeClub)
VALUES ('Tenis Masters', 'incepator', 'mixt', 'Club Tenis Elite'),
       ('Cluj Champions', 'mediu', 'masculin', 'Club Tenis Elite');

INSERT INTO Antrenori (Cnp, Nume, Strategie, NumeEchipa)
VALUES (198712345, 'Alex Buzatu', 'serviciu tare', 'Tenis Masters'),
       (197623451, 'Irina Dumitrescu', 'tactica defensiva', 'Cluj Champions');

INSERT INTO Jucatori (Cnp, Nume, Experienta, NumeEchipa)
VALUES (123456789, 'Andrei Cojocaru', 3, 'Tenis Masters'),
       (987654321, 'Emil Popa', 4, 'Cluj Champions'),
       (123123123, 'Ana Marin', 5, 'Tenis Masters'),
       (321321321, 'Cosmin Ionescu', 6, 'Cluj Champions');

INSERT INTO Rezervari (Nume, Pret)
VALUES ('Adriana Muresan', 150),
       ('Dorin Lungu', 200);

INSERT INTO RezervariTerenuri (RezervariId, TerenuriId)
VALUES (7, 5),
       (7, 6),
       (8, 5),
       (8, 6);


-- 1) selectam echipele de la club tenis prosport
-- WHERE(1)
-- DISTINCT(1)
SELECT DISTINCT e.Nivel, e.Tip, e.Nume
FROM Echipe e
WHERE e.NumeClub = 'Club Tenis ProSport'

-- 2) afisam ce suma a generat fiecare teren
-- GROUP BY(1)
-- tabele aflate in relatie m-n(1)
SELECT t.Locatie AS LocatieTeren, 
       SUM(r.Pret) AS Castig
FROM Terenuri t
JOIN RezervariTerenuri rz ON t.Id = rz.TerenuriId
JOIN Rezervari r ON rz.RezervariId = r.Id
GROUP BY t.Locatie
ORDER BY Castig DESC;

-- 3) afisam cate terenuri a rezervat fiecare client
-- DISTINCT(2)
-- tabele aflate in relatie m-n(2)
SELECT r.Id AS RezervareID, 
       r.Nume AS Client, 
	   COUNT(DISTINCT t.Id) AS NrTerenuri
FROM Rezervari r
JOIN RezervariTerenuri rt ON r.Id = rt.RezervariId
JOIN Terenuri t ON rt.TerenuriId = t.Id
GROUP BY r.Id, r.Nume;

-- 4) pentru fiecare nivel, scriem nr jucatori din club tenis prosport
-- WHERE(2)
-- GROUP BY(2)
-- extrage din >2 tabele(1)
SELECT e.Nivel AS NivelEchipa, 
	   COUNT(j.Cnp) AS NrJucatori, 
	   c.Nume AS Club
FROM Jucatori j
JOIN Echipe e ON j.NumeEchipa = e.Nume
JOIN Cluburi c ON e.NumeClub = c.Nume
WHERE c.Nume = 'Club Tenis ProSport'
GROUP BY e.Nivel, c.Nume;

-- 5) afisam strategiile si cati antrenori o folosesc 
--    din club tenis prosport
-- WHERE(3)
-- GROUP BY(3)
-- HAVING(1)
-- extrage din >2 tabele(2)
SELECT a.Strategie, 
	   COUNT(a.Cnp) AS NrAntrenori, 
	   c.Nume AS Club
FROM Antrenori a
JOIN Echipe e ON a.NumeEchipa = e.Nume
JOIN Cluburi c ON e.NumeClub = c.Nume
WHERE c.Nume = 'Club Tenis ProSport'
GROUP BY a.Strategie, c.Nume
HAVING COUNT(a.Cnp) >= 1;

-- 6) afisam cati jucatori din fiecare echipa au
--    experienta mai mare de 3 ani
-- WHERE(4)
-- HAVING(2)
-- extrage din >2 tabele(3)
SELECT e.Nume AS Echipa, 
	   COUNT(j.Cnp) AS NrJucatori, 
	   c.Nume AS Club
FROM Jucatori j
JOIN Echipe e ON j.NumeEchipa = e.Nume
JOIN Cluburi c ON e.NumeClub = c.Nume
WHERE  j.Experienta > 3
GROUP BY e.Nume, c.Nume
HAVING COUNT(j.Cnp) > 0;

-- 7) afisam punctajul total pt competitiile cu premiul >50k
-- WHERE(5)
-- extrage din >2 tabele(4)
SELECT c.Nume AS Club, 
	   COUNT(comp.Id) AS NrCompetitii, 
	   SUM(comp.Punctaj) AS TotalPunctaj
FROM Competitii comp
JOIN Cluburi c ON comp.NumeClub = c.Nume
WHERE comp.Premiu > 50000
GROUP BY c.Nume
HAVING COUNT(comp.Id) > 0
ORDER BY TotalPunctaj DESC;

-- 8) cate echipe au strategia tare si pe centru
-- extrage din >2 tabele(5)
SELECT c.Nume AS Club, 
	   COUNT(DISTINCT e.Nume) AS NrEchipe, 
	   a.Strategie as Strategie
FROM Antrenori a
JOIN Echipe e ON a.NumeEchipa = e.Nume
JOIN Cluburi c ON e.NumeClub = c.Nume
WHERE Strategie = 'tare si pe centru'
GROUP BY c.Nume, a.Strategie
HAVING COUNT(DISTINCT e.Nume) > 0;

-- 9) afisam numarul de jucatori si antrenorul pentru toate echipele
-- extrage din >2 tabele(6)
SELECT a.Nume, 
       e.Nume, 
       COUNT(j.Cnp) as NrJucatori
FROM Antrenori a
JOIN Echipe e ON a.NumeEchipa = e.Nume
JOIN Jucatori j ON e.Nume = j.NumeEchipa
GROUP BY a.Nume, e.Nume
HAVING COUNT(j.Cnp) >= 2;

-- 10) afisam echipele cu mai mult de un antrenor
-- extrage din >2 tabele(7)
SELECT c.Nume AS Club, 
       COUNT(DISTINCT a.Cnp) AS NrAntrenori, 
       e.Tip AS TipEchipa
FROM Cluburi c
JOIN Echipe e ON c.Nume = e.NumeClub
JOIN Antrenori a ON e.Nume = a.NumeEchipa
GROUP BY c.Nume, e.Tip
HAVING COUNT(DISTINCT a.Cnp) > 1;



