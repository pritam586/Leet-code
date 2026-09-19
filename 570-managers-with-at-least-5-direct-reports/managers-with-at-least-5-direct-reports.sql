# Write your MySQL query statement below
select name 
from Employee
where id IN (
SELECT managerId
FROM Employee
WHERE managerId IS NOT NULL
GROUP BY managerId
HAVING COUNT(*) >= 5)