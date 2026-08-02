# Write your MySQL query statement below
-- 1321. Restaurant Growth
SELECT a.visited_on as visited_on,
SUM(b.day_sum) AS amount,
ROUND(SUM(b.day_sum)/7,2) AS average_amount

FROM (SELECT visited_on, SUM(amount) as day_sum FROM Customer GROUP BY visited_on) as a,
(SELECT visited_on, SUM(amount) as day_sum FROM Customer GROUP BY visited_on) as b

WHERE DATEDIFF(a.visited_on , b.visited_on) BETWEEN 0 AND 6
GROUP BY a.visited_on
HAVING a.visited_on >= (SELECT MIN(visited_on) FROM Customer) + 6
ORDER BY a.visited_on