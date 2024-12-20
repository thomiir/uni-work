USE CluburiTenis
GO

CREATE TABLE CluburiTest
(Nume VARCHAR(50) PRIMARY KEY,
Adresa VARCHAR(50),
NrClienti INT
)

CREATE TABLE TerenuriTest
(Id INT PRIMARY KEY,
Locatie VARCHAR(50),
NrMingi INT,
NumeClub VARCHAR(50) FOREIGN KEY REFERENCES CluburiTest(Nume)
)

CREATE TABLE RezervariTest
(Id INT PRIMARY KEY,
Nume VARCHAR(50) NOT NULL,
Pret FLOAT NOT NULL
)

CREATE TABLE RezervariTerenuriTest
(RezervariId INT FOREIGN KEY REFERENCES RezervariTest(Id),
TerenuriId INT FOREIGN KEY REFERENCES TerenuriTest(Id),
CONSTRAINT pk_RezervariTerenuriTest PRIMARY KEY (RezervariId, TerenuriId)
)

INSERT INTO CluburiTest(Nume, Adresa, NrClienti) VALUES ('Club Tenis ProSport', 'blvd. Primaverii nr. 25 Timisoara', 100)
SELECT * FROM CluburiTest
SELECT * FROM RezervariTest
SELECT * FROM RezervariTerenuriTest

DROP TABLE CluburiTest
DROP TABLE TerenuriTest
DROP TABLE RezervariTest
DROP TABLE RezervariTerenuriTest