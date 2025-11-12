# Write your MySQL query statement below
SELECT s.stock_name, (t2.price-t1.price) as capital_gain_loss 
FROM Stocks s, (
    SELECT stock_name, operation, SUM(price) as price
    FROM Stocks
    WHERE operation = 'Buy'
    GROUP BY stock_name
) AS t1,
(
    SELECT stock_name, operation, SUM(price) as price
    FROM Stocks
    WHERE operation = 'Sell'
    GROUP BY stock_name
) AS t2
WHERE t1.stock_name = t2.stock_name AND t1.stock_name = s.stock_name
GROUP BY s.stock_name

