# Write your MySQL query statement below
# Write your MySQL query statement below
-- # Write your MySQL query statement below
-- SELECT p.product_name, s.year, s.price
-- FROM Product p
-- INNER JOIN Sales s
-- ON s.product_id = p.product_id;

SELECT 
    p.product_name, s.year, s.price
FROM 
    Sales s
JOIN 
    Product p
ON
    s.product_id = p.product_id