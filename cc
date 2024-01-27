SELECT c.car_name, COUNT(r.pickup_date) AS TotalRentalDays
FROM cars c
JOIN rentals r ON c.car_id = r.car_id
WHERE MONTH(r.pickup_date) = 5
GROUP BY c.car_name
HAVING DATEDIFF(MAX(r.return_date), MIN(r.pickup_date)) = (
    SELECT DATEDIFF(MAX(return_date), MIN(pickup_date))
    FROM rentals
    WHERE MONTH(pickup_date) = 5
    GROUP BY car_id
    ORDER BY DATEDIFF(MAX(return_date), MIN(pickup_date)) DESC
    LIMIT 1
);
