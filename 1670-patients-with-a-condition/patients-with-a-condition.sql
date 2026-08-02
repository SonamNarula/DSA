# Write your MySQL query statement below
-- 1527. Patients With a Condition

SELECT *
FROM Patients
WHERE conditions LIKE 'DIAB1%'
   OR conditions LIKE '% DIAB1%';