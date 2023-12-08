# Write your MySQL query statement below
select name from Customer
where not(referee_id=2) or referee_id is null;
/*you had to handle null cases explicitly*/