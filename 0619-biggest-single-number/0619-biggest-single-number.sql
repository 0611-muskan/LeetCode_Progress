# Write your MySQL query statement below
select max(num) as num from(
SELECT num
from MyNumbers
group by num
having count(*)=1)
as single_num

