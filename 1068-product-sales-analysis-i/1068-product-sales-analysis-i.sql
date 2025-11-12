# Write your MySQL query statement below
SELECT p.product_name, year,price
FROM Sales s, Product p
WHERE s.product_id = p.product_id