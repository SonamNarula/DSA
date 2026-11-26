# Write your MySQL query statement below
-- 596. Classes With at Least 5 Students
SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(student) >= 5;