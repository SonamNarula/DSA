# Write your MySQL query statement below
-- 570. Managers with at Least 5 Direct Reports

SELECT e1.name
FROM Employee e1
INNER JOIN Employee e2
ON e1.id = e2.managerId 
GROUP BY e2.managerId
HAVING COUNT(e2.managerId) >= 5