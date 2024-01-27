SELECT car_name, COUNT(*) AS TotalRentalDays
FROM cars
WHERE car_id IN (
    SELECT car_id
    FROM rentals
    WHERE MONTH(pickup_date) = 5
    GROUP BY car_id
    HAVING COUNT(*) = (
        SELECT COUNT(*)
        FROM rentals
        WHERE MONTH(pickup_date) = 5
        GROUP BY car_id
        ORDER BY COUNT(*) DESC
        LIMIT 1
    )
)
GROUP BY car_name;
