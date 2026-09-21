
     CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    RETURN (
        WITH RankedEmployees AS (
            SELECT salary,
                   DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
            FROM Employee
        )
        SELECT MAX(salary)
        FROM RankedEmployees
        WHERE rnk = N
    );
END

