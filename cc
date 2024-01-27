SELECT car_name, SUM(DATEDIFF(return_date, pickup_date)) AS TotalRentalDays
FROM cars
WHERE car_id IN (
    SELECT car_id
    FROM rentals
    WHERE MONTH(pickup_date) = 5
    GROUP BY car_id
    HAVING SUM(DATEDIFF(return_date, pickup_date)) = (
        SELECT SUM(DATEDIFF(return_date, pickup_date))
        FROM rentals
        WHERE MONTH(pickup_date) = 5
        GROUP BY car_id
        ORDER BY SUM(DATEDIFF(return_date, pickup_date)) DESC
        LIMIT 1
    )
)
GROUP BY car_name;
