# Write your MySQL query statement below
select p.email as Email  
from (
    select email , count(*) as email_count
    from person
    group by email
) as p
where p.email_count > 1;



