USE CluburiTenis
GO

-- modificam tipul coloanei Nume din tabela Angajati
-- astfel incat sa aiba maxim 40 de caractere
CREATE PROCEDURE MicsorareLgNumeAngajati 
AS 
BEGIN
	ALTER TABLE Angajati
	ALTER COLUMN Nume VARCHAR(40);
END
GO

-- modificam tipul coloanei Nume din tabela Angajati
-- astfel incat sa aiba maxim 50 de caractere
CREATE PROCEDURE MarireLgNumeAngajati
AS
BEGIN
	ALTER TABLE Angajati
	ALTER COLUMN Nume VARCHAR(50);
END
GO

-- adaugam o constrangere de tip default pentru numarul
-- de mingi dintr-un teren, NrMingi din tabela Terenuri
CREATE PROCEDURE CreareDefaultNrMingi
AS
BEGIN
	ALTER TABLE Terenuri
	ADD CONSTRAINT df_NrMingi DEFAULT 50 FOR NrMingi
END
GO

-- stergem constrangerea de tip default creata mai sus
CREATE PROCEDURE StergereDefaultNrMingi
AS
BEGIN
	ALTER TABLE Terenuri
	DROP CONSTRAINT df_NrMingi
END
GO

-- cream o tabela noua care sa retina planificarea
-- interviurilor pentru angajare
CREATE PROCEDURE CreeazaTabelaPlanificari
AS
BEGIN
	CREATE TABLE Planificari (
		NumeCandidat VARCHAR(50),
		CNPAngajator INT PRIMARY KEY
		)
END
GO

-- stergem tabela creata mai sus
CREATE PROCEDURE StergeTabelaPlanificari
AS
BEGIN
	DROP TABLE Planificari
END
GO

-- adaugam campul Ora in tabela planificari
CREATE PROCEDURE AdaugaOraPlanificari
AS
BEGIN
	ALTER TABLE Planificari
	ADD OraInterviu DATETIME;
END
GO

-- stergem campul Ora din tabela planificari
CREATE PROCEDURE StergeOraPlanificari
AS
BEGIN
	ALTER TABLE Planificari
	DROP COLUMN OraInterviu;
END
GO

-- adaugam constrangerea de cheie straina pentru cnp-ul
-- angajatorului 
CREATE PROCEDURE AdaugareFKPlanificari
AS
BEGIN
	ALTER TABLE Planificari
	ADD CONSTRAINT fk_CNPAngajator FOREIGN KEY (CNPAngajator) REFERENCES Angajati(Cnp);
END
GO

-- stergem constrangerea de cheie straina pentru cnp-ul
-- angajatorului
CREATE PROCEDURE StergereFKPlanificari
AS
BEGIN
	ALTER TABLE Planificari
	DROP CONSTRAINT fk_CNPAngajator
END
GO


CREATE TABLE Versiune (V INT NOT NULL);
INSERT INTO Versiune(V) VALUES (0);

CREATE TABLE VersiuneSteps 
(
	V INT NOT NULL,
	U VARCHAR(50),  -- upgrade
	D VARCHAR(50),  -- downgrade
);

INSERT INTO VersiuneSteps(V, U, D) VALUES
	(0, 'MicsorareLgNumeAngajati', ''),
	(1, 'CreareDefaultNrMingi', 'MarireLgNumeAngajati'),
	(2, 'CreeazaTabelaPlanificari', 'StergereDefaultNrMingi'),
	(3, 'AdaugaOraPlanificari', 'StergeTabelaPlanificari'),
	(4, 'AdaugareFKPlanificari', 'StergeOraPlanificari'),
	(5, '', 'StergereFKPlanificari');

	

CREATE PROCEDURE ChangeVersion @version INT
AS
BEGIN
	-- verificam daca este valida versiunea
	IF @version < 0 OR @version > 5 
	BEGIN
		RAISERROR('Versiunea nu exista', 10, 1)	
		RETURN
	END
	-- getter pentru versiunea curenta
	DECLARE @currentVersion INT
	SELECT TOP 1 @currentVersion = V FROM Versiune
	PRINT 'Versiunea curenta este ' + CAST(@currentVersion AS VARCHAR);
	-- verificam daca nu suntem deja in versiunea ceruta
	IF @version = @currentVersion
	BEGIN
		PRINT 'Versiunea exista deja.'
		RETURN
	END
	-- setam directia corespunzatoare
	DECLARE @step INT
	IF @version > @currentVersion 
		SET @step = 1 -- facem upgrade
	ELSE 
		SET @step = -1 -- facem downgrade
	-- executam procedurile corespunzatoare cat timp nu suntem in versiunea corecta
	WHILE @currentVersion <> @version
	BEGIN				
		DECLARE @procedureName VARCHAR(50)
		IF @step = 1  
			SELECT @procedureName = U FROM VersiuneSteps WHERE V = @currentVersion
		ELSE
			SELECT @procedureName = D FROM VersiuneSteps WHERE V = @currentVersion
		PRINT 'Am iesit din versiunea ' + CAST(@currentVersion AS VARCHAR)
		DECLARE @query NVARCHAR(200)
		SET @query = 'EXEC ' + @procedureName
		EXECUTE sp_executesql @query
		-- actualizam versiunea curenta
		SET @currentVersion = @currentVersion + @step
		DELETE FROM Versiune
		INSERT INTO Versiune(V) VALUES (@currentVersion);
	END
END
GO

DELETE FROM Versiune
INSERT INTO Versiune(V) VALUES (0);
EXEC ChangeVersion 10