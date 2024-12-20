-- tabelele pe care vom lucra: Cluburi, Terenuri, ManageriTerenuri, RezervariTerenuri, Rezervari
-- validari:
-- pentru Cluburi : validam nr clienti sa fie > 10
-- pentru Terenuri : validam sa existe cheia straina in Cluburi
-- pentru ManageriTerenuri : validam sa existe cheia straina in Terenuri
-- pentru RezervariTerenuri : validam sa existe ambele chei straine
-- pentru Rezervari : validam pretul sa fie > 50


-- functie de validare pentru Cluburi
USE CluburiTenis

GO
CREATE OR ALTER FUNCTION isClientNumberValid(@ClientNumber INT) RETURNS INT
AS 
BEGIN
	IF (@ClientNumber > 10)
	BEGIN
		RETURN 1
	END

	RETURN 0
END


-- functie de validare pentru Terenuri
GO
CREATE OR ALTER FUNCTION isTerenForeignKeyValid(@ForeignKey VARCHAR(50)) RETURNS INT
AS
BEGIN
	IF EXISTS (SELECT * FROM Cluburi WHERE @ForeignKey = Cluburi.Nume)
	BEGIN
		RETURN 1
	END
	
	RETURN 0
END



-- functie de validare pentru ManageriTerenuri
GO
CREATE OR ALTER FUNCTION isManageriForeignKeyValid(@ForeignKey INT) RETURNS INT
AS
BEGIN
	IF EXISTS (SELECT * FROM Terenuri WHERE @ForeignKey = Terenuri.Id)
	BEGIN
		RETURN 1
	END

	RETURN 0
END


-- functie de validare pentru RezervariTerenuri
GO
CREATE OR ALTER FUNCTION isRezervariTerenuriForeignKeyValid(@TerenuriKey INT, @RezervariKey INT) RETURNS INT
AS
BEGIN
	IF EXISTS (SELECT * FROM Terenuri WHERE Terenuri.Id = @TerenuriKey) AND
	   EXISTS (SELECT * FROM Rezervari WHERE Rezervari.Id = @RezervariKey)
	   BEGIN
		RETURN 1
	END

	RETURN 0
END


-- functii de validare pentru Rezervari
GO
CREATE OR ALTER FUNCTION isRezervariPriceValid(@Price FLOAT) RETURNS INT
AS
BEGIN
	IF (@Price > 50)
	BEGIN
		RETURN 1
	END

	RETURN 0
END