-- Assingment 3
-- ENSF608 
-- Emmanuel Alafonye
-- Due Date 20 November 2023.

-- Question 1. List all student names (first and last) the music studio 
SELECT C.FName, C.LName, T.StudioName -- Select Fname and Lname and StudioName
FROM COMPETITOR C JOIN TEACHER T ON C.TeacherID = T.TeacherID; -- Retrieve Data from COMPETITOR and JOIN Teacher T.

-- Question 2. This count how many students in each music studio group.
SELECT T.StudioName, COUNT(C.CompetitorID) AS StudentCount -- Counting Students in each studio
FROM TEACHER T LEFT JOIN COMPETITOR C ON T.TeacherID = C.TeacherID GROUP BY T.StudioName;

-- Question 3. This count how many teachers in each music studio group.
SELECT StudioName, COUNT(*) AS TeacherCount FROM TEACHER GROUP BY StudioName; -- Count teachers in each studio

-- Question 4. Here list the last name of all teachers wiht more than one student registered.
SELECT T.LName FROM TEACHER T -- Select the last names of Teachers
WHERE (SELECT COUNT(*) FROM COMPETITOR C WHERE C.TeacherID = T.TeacherID) > 1; -- Filter more than one student

-- Question 5. List of all student names (first and last) performing in Romantic genre category and the title of their composition.
SELECT C.FName, C.LName, CM.Title FROM COMPETITOR C -- Select student names and title in competition
JOIN PERFORMANCE P ON C.CompetitorID = P.CompetitorID
JOIN CATEGORY CAT ON P.CategoryID = CAT.CategoryID
JOIN COMPOSITION CM ON P.MusicID = CM.MusicID WHERE CAT.Genre = 'Romantic'; -- Filter Romatic Genre

-- Question 6. All possible compositions and categories they performed in.
SELECT CM.Title, CAT.Genre FROM COMPOSITION CM LEFT JOIN PERFORMANCE P ON CM.MusicID = P.MusicID -- Select composition genres
LEFT JOIN CATEGORY CAT ON P.CategoryID = CAT.CategoryID;

-- Question 7. Created a view called SCORE_ANALYSIS listing ages of each competitor and performance score.
CREATE VIEW SCORE_ANALYSIS AS 
SELECT C.Age, P.Score FROM COMPETITOR C -- Create a view with competitor ages scores
JOIN PERFORMANCE P ON C.CompetitorID = P.CompetitorID;

-- Question 8. Display the rows of SCORE_ANALYSIS from the highest score to the lowest score.
SELECT * FROM SCORE_ANALYSIS ORDER BY Score DESC; -- Shows competitors ages and score descending order.

-- Question 9. The highest score, lowest score, and average score from SCORE_ANALYSIS.
SELECT MAX(Score) AS Highest_Score, MIN(Score) AS Lowest_Score, AVG(Score) AS Average_Score
FROM SCORE_ANALYSIS; -- Calculate the hightest and lowest and averages.

-- Question 10. Alter COMPOSITION table and add new column, Copyright with a default value ‘SOCAN’.
ALTER TABLE COMPOSITION ADD Copyright VARCHAR(20) DEFAULT 'SOCAN'; -- Add Copyright defautl value
SELECT * FROM COMPOSITION; -- Copyright in Composition.

-- Question 11. Competitors who do not meet the age restrictions for their chosen performance category.
SELECT C.FName, C.LName, CAT.Genre, CAT.AgeMin, CAT.AgeMax FROM COMPETITOR C 
JOIN PERFORMANCE P ON C.CompetitorID = P.CompetitorID JOIN CATEGORY CAT ON P.CategoryID = CAT.CategoryID
WHERE C.Age < CAT.AgeMin OR C.Age > CAT.AgeMax; -- Fins competitor not meeting age requirements

-- Question 12. This alter the COMPETITOR table to add a CHECK constraint for age restrictions.
ALTER TABLE COMPETITOR ADD CHECK (Age >= 5 AND Age <= 18); -- Add age restrictions.

-- Question 13. Changing Harmony Inc.'s name to Harmony Studio to update applicable tables.
UPDATE STUDIO SET Name = 'Harmony Studio' WHERE Name = 'Harmony Inc';
UPDATE TEACHER SET StudioName = 'Harmony Studio' WHERE StudioName = 'Harmony Inc';
## The update is done using the foreign key relationship to the studio table.
## This ensures consistency across the database and reflects the name change in all relevant records.

## Question 14. The deletion statement 'DELETE FROM COMPOSITION WHERE Composer = 'Beethoven';'
-- Will result in an error because there are foreign key constraints on the 
-- COMPOSITION table that reference the MUSICID column.

## Question 15. Addressing the issue of teacher certification with a trigger.
-- From the tables trigger checks if a teacher is being updated and if their certification is empty.
-- If it's empty, and error is raised, indicating that proof of certification must be provided.

DELIMITER ## Used to check update in the TEACHER table.
CREATE TRIGGER Certification
BEFORE UPDATE ON TEACHER FOR EACH ROW
BEGIN
  IF NEW.Certification IS NULL OR NEW.Certification = '' THEN
    SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Proof of certification must be provided to the main office.';
  END IF;
END;
//
DELIMITER ;

