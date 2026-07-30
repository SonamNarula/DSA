# Write your MySQL query statement below
-- 620. Not Boring Movies
SELECT id, movie, description, rating
FROM Cinema
WHERE MOD(id, 2) = 1 AND description != 'boring'
GROUP BY id
ORDER BY rating DESC