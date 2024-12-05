CREATE DATABASE CluburiTenis
GO
USE CluburiTenis
GO

CREATE TABLE Cluburi
(Nume VARCHAR(50) PRIMARY KEY,
Adresa VARCHAR(50),
NrClienti INT
)

CREATE TABLE Angajati
(Cnp INT PRIMARY KEY,
Nume VARCHAR(50),
Functie VARCHAR(50),
NumeClub VARCHAR(50) FOREIGN KEY REFERENCES Cluburi(Nume)
)

CREATE TABLE Competitii
(Id INT PRIMARY KEY IDENTITY,
Nume VARCHAR(50),
Punctaj INT,
Premiu FLOAT,
NumeClub VARCHAR(50) FOREIGN KEY REFERENCES Cluburi(Nume)
)

CREATE TABLE Terenuri
(Id INT PRIMARY KEY IDENTITY,
Locatie VARCHAR(50),
NrMingi INT,
NumeClub VARCHAR(50) FOREIGN KEY REFERENCES Cluburi(Nume)
)

CREATE TABLE ManageriTerenuri
(TerenId INT FOREIGN KEY REFERENCES Terenuri(Id),
Nume VARCHAR(50) NOT NULL,
CONSTRAINT pk_ManageriTerenuri PRIMARY KEY(TerenId)
)

CREATE TABLE Rezervari
(Id INT PRIMARY KEY IDENTITY,
Nume VARCHAR(50) NOT NULL,
Pret FLOAT NOT NULL
)

CREATE TABLE RezervariTerenuri
(RezervariId INT FOREIGN KEY REFERENCES Rezervari(Id),
TerenuriId INT FOREIGN KEY REFERENCES Terenuri(Id),
CONSTRAINT pk_RezervariTerenuri PRIMARY KEY (RezervariId, TerenuriId)
)

CREATE TABLE Echipe
(Nume VARCHAR(50) PRIMARY KEY,
Nivel VARCHAR(50) CHECK (Nivel='incepator' OR Nivel='mediu' OR Nivel='avansat'),
Tip VARCHAR(50) CHECK (Tip='masculin' OR Tip='feminin' OR Tip='mixt'),
NumeClub VARCHAR(50) FOREIGN KEY REFERENCES Cluburi(Nume) 
)

CREATE TABLE Antrenori
(Cnp INT PRIMARY KEY,
Nume VARCHAR(50) NOT NULL,
Strategie VARCHAR(50) NOT NULL,
NumeEchipa VARCHAR(50) FOREIGN KEY REFERENCES Echipe(Nume)
)

CREATE TABLE Jucatori
(Cnp INT PRIMARY KEY,
Nume VARCHAR(50) NOT NULL,
Experienta INT,
NumeEchipa VARCHAR(50) FOREIGN KEY REFERENCES Echipe(Nume)
)