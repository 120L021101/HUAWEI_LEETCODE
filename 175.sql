# Write your MySQL query statement below
select LastName, FirstName, City, State
from Person left join Address
on Person.PersonId = Address.PersonId