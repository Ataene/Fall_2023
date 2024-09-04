-- Create the database
CREATE DATABASE IF NOT EXISTS CIRQUE_DU_SOLEIL;

-- Use the database
USE CIRQUE_DU_SOLEIL;

-- Create the PERFORMER table
CREATE TABLE PERFORMER (
    PerformerID INT PRIMARY KEY,
    FirstName VARCHAR(255),
    LastName VARCHAR(255),
    Citizenship VARCHAR(255),
    Birthdate DATE,
    SpecialDiet VARCHAR(255),
	Role VARCHAR(50) COLLATE utf8mb4_general_ci CHECK (Role IN ('Musician', 'Aerialist', 'Entertainer')), -- 'Musician', 'Aerialist', 'Entertainer'
	Sport VARCHAR(255),
    Equipment VARCHAR(255),
    MainAct VARCHAR(255),
    UnderstudyForID INT,
	FOREIGN KEY (UnderstudyForID) REFERENCES PERFORMER(PerformerID), -- Reference to the same table for understudy relationship
    UNIQUE (PerformerID), -- Ensure a one-to-one relationship
	CHECK ((Role = 'Aerialist' AND Sport IS NOT NULL AND Equipment IS NOT NULL) OR Role != 'Aerialist'),-- Aerialist-specific check
	#CHECK ((Role = 'Musician' AND EXISTS (SELECT 1 FROM INSTRUMENT WHERE INSTRUMENT.MusicianID = PERFORMER.PerformerID)) OR Role != 'Musician'),-- Musician-specific check
	CHECK ((Role = 'Entertainer' AND MainAct IS NOT NULL) OR Role != 'Entertainer') -- Entertainer-specific check
	#FOREIGN KEY (PerformerID) REFERENCES EMERGENCYCONTACT(PerformerID) -- Reference to EMERGENCYCONTACT table
);

-- Create the SHOW table
CREATE TABLE SHOWTAB (
    ShowName VARCHAR(255),
    PerformanceYear INT,
    Sponsor VARCHAR(255),
    Producer VARCHAR(255),
    PerformerID INT NOT NULL,
    PRIMARY KEY (ShowName, PerformanceYear),
    FOREIGN KEY (PerformerID) REFERENCES PERFORMER(PerformerID)  -- Reference to PERFORMER table
);

-- Create the VENUE table
CREATE TABLE VENUE (
    VenueID INT,
    VenueName VARCHAR(255),
    Capacity INT,
    StreetAddress VARCHAR(255),
    City VARCHAR(255),
    Province VARCHAR(255),
    AccessibleByTransit BOOLEAN,
    PRIMARY KEY (VenueID)
);

-- Create the HOSTING table
CREATE TABLE HOSTING (
    VenueID INT,
    ShowName VARCHAR(255),
    PerformanceYear INT,
    Date DATE,
    Location VARCHAR(255),
    PRIMARY KEY (ShowName, PerformanceYear, VenueID),
    FOREIGN KEY (ShowName, PerformanceYear) REFERENCES SHOWTAB(ShowName, PerformanceYear), -- Reference to SHOWTAB table
    FOREIGN KEY (VenueID) REFERENCES VENUE(VenueID) -- Reference to VENUE table
);


-- Create the MEDICATION table
CREATE TABLE MEDICATION (
    MedicationID INT, 
	MedicationName VARCHAR(255) COLLATE utf8mb4_general_ci NOT NULL,
    PRIMARY KEY (MedicationID)
    
);

-- Create Table PERFORMER_MEDICATION
CREATE TABLE PERFORMER_MEDICATION (
    PerformerID INT,
    MedicationID INT,
	PRIMARY KEY (PerformerID, MedicationID),
    FOREIGN KEY (PerformerID) REFERENCES PERFORMER(PerformerID),
    FOREIGN KEY (MedicationID) REFERENCES MEDICATION(MedicationID),
    UNIQUE (PerformerID, MedicationID) -- Ensure unique combinations (Assumption: Each performer has a unique combination of medication)
);


-- Create the INSTRUMENT table
CREATE TABLE INSTRUMENT (
    InstrumentID INT,
	MusicianID INT,
    InstrumentName VARCHAR(255),
    PRIMARY KEY (InstrumentID),
    FOREIGN KEY (MusicianID) REFERENCES PERFORMER(PerformerID)
   
);


-- Create the EMERGENCYCONTACT table
CREATE TABLE EMERGENCYCONTACT (
    ContactID INT PRIMARY KEY,
    ContactFirstName VARCHAR(255) NOT NULL,
    ContactLastName VARCHAR(255) NOT NULL,
    PhoneNumber VARCHAR(255) NOT NULL,
    Relationship VARCHAR(255) NOT NULL,
    UNIQUE (ContactID),
    FOREIGN KEY (ContactID) REFERENCES PERFORMER(PerformerID)
);

INSERT INTO PERFORMER (PerformerID, FirstName, LastName, Citizenship, Birthdate, SpecialDiet, Role, Sport, Equipment, MainAct, UnderstudyForID)
VALUES
  (1, 'John', 'Doe', 'USA', '1990-01-15', 'None', 'Musician', NULL, NULL, NULL, NULL),
  (2, 'Alice', 'Smith', 'Canada', '1988-05-20', 'Vegan', 'Aerialist', 'Aerial Silks', 'Safety Net', NULL, NULL),
  (3, 'Bob', 'Johnson', 'UK', '1992-09-08', 'Vegetarian', 'Entertainer', NULL, NULL, 'Magic Show', NULL),
  (4, 'Emma', 'Williams', 'Australia', '1985-03-12', 'Gluten-Free', 'Musician', NULL, NULL, NULL, NULL),
  (5, 'Charlie', 'Brown', 'USA', '1995-07-30', 'None', 'Aerialist', 'Trapeze', 'Safety Net', NULL, NULL);


-- Generate random data for SHOWTAB table
INSERT INTO SHOWTAB (ShowName, PerformanceYear, Sponsor, Producer, PerformerID)
VALUES
  ('Kooza', 2023, 'Sponsor1', 'Producer1', 1),
  ('Corteo', 2023, 'Sponsor2', 'Producer2', 2),
  ('Alegria', 2023, 'Sponsor3', 'Producer3', 3),
  ('Alegria', 2024, 'Sponsor4', 'Producer4', 4),
  ('Kooza', 2024, 'Sponsor5', 'Producer5', 5);
 

-- Generate random data for VENUE table
INSERT INTO VENUE (VenueID, VenueName, Capacity, StreetAddress, City, Province, AccessibleByTransit)
VALUES
  (1, 'Venue1', 1000, '123 Main St', 'City1', 'Province1', 1),
  (2, 'Venue2', 1500, '456 Oak St', 'City2', 'Province2', 0),
  (3, 'Venue3', 1200, '789 Maple St', 'City3', 'Province3', 1);
 

-- Generate random data for HOSTING table
INSERT INTO HOSTING (VenueID, ShowName, PerformanceYear, Date, Location)
VALUES
  (1, 'Kooza', 2023, '2023-05-01', 'Location1'),
  (2, 'Corteo', 2023, '2023-06-15', 'Location2'),
  (3, 'Alegria', 2023, '2023-07-20', 'Location3');


-- Generate random data for MEDICATION table
INSERT INTO MEDICATION (MedicationID, MedicationName)
VALUES
  (1, 'Medication1'),
  (2, 'Medication2'),
  (3, 'Medication3');
  

-- Generate random data for PERFORMER_MEDICATION table
INSERT INTO PERFORMER_MEDICATION (PerformerID, MedicationID)
VALUES
  (1, 1),
  (2, 2),
  (3, 3);


-- Generate random data for INSTRUMENT table
INSERT INTO INSTRUMENT (InstrumentID, MusicianID, InstrumentName)
VALUES
  (1, 1, 'Guitar'),
  (2, 1, 'Piano'),
  (3, 4, 'Flute');
 

-- Generate random data for EMERGENCYCONTACT table
INSERT INTO EMERGENCYCONTACT (ContactID, ContactFirstName, ContactLastName, PhoneNumber, Relationship)
VALUES
  (1, 'Emergency1', 'Contact1', '123-456-7890', 'Parent'),
  (2, 'Emergency2', 'Contact2', '987-654-3210', 'Sibling'),
  (3, 'Emergency3', 'Contact3', '555-123-4567', 'Spouse');
 