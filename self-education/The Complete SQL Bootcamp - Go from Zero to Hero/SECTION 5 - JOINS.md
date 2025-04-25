

# AS STATEMENT
- Basically it is used to rename aggregate functions or some other field with the purpose of better readability.
```
select sum(amount) as net_revenue FROM payment;
```
- The AS operator gets executed at the very end of a query, meaning that we cannot use the alias inside a WHERE statement or a HAVING clause.
- We can only use this basically in the SELECT statement.


# INNER JOIN
- Joins allow us to combine multiple tables together.
- The reason for the different JOIN types, is to decide how to deal with information only present in one of the joined tables.
- The INNER JOIN will result with the set of records that match in both tables.
![[Pasted image 20250424010900.png]]
- Called inner join because only the inner portion of the Venn Diagram is the result.
```
select * from <table A> 
inner join <table B>
on <table A>.<col match> = <table B>.<col match>;
```
- Basically this join will return the set of records that are in both table A and in table B.
- Since they return the records that are present in both tables, they are symmetrical, meaning that it is the same reverse the tables in the query:
```
select * from <table B> 
inner join <table A>
on <table B>.<col match> = <table A>.<col match>;
```

![[Pasted image 20250424011226.png]]
- When you just see the word JOIN, SQL defaults it to an INNER join.


# FULL OUTER JOINS
- A full outer join will grab all the information within the 2 tables.
![[Pasted image 20250424012900.png]]
```
select * from <table A>
full outer join <table B>
on <table A>.<col match> = <table B>.<col match>
```
- Grab everything even if it is not present in both tables, this is also symmetrical and the table order in the query can be changed the same way as an inner join.
- The values that do not match ON the other table will be filled in with null values.
![[Pasted image 20250424013210.png]]

### FULL OUTER JOINS with a WHERE
- The complete opposite to an INNER JOIN.
```
select * from <table A>
full outer join <table B>
on <table A>.<col match> = <table B>.<col match>
where <table A>.<id> is null or 
	<table B>.<id> is null;
```
- Basically remove the nulls.
![[Pasted image 20250424013445.png]]
- This is also symmetrical.
![[Pasted image 20250424013530.png]]
- And goes from this: 
![[Pasted image 20250424013623.png]]
- To this: 
![[Pasted image 20250424013645.png]]
- Usually used to check if there are no anomalies and best practice compliance.



# LEFT OUTER JOIN / LEFT JOIN
- A LEFT OUTER JOIN results in the set of records that are in the left table, if there are no match with the right table, the results are null.
- This is NOT SYMMETRICAL, the table order matters:
![[Pasted image 20250424020357.png]]
- Essentially we are grabbing all information in table A, plus any information that matches in table B, if information is only present in table B, it is not included.
- LEFT OUTER JOIN is the same as LEFT JOIN.
- ![[Pasted image 20250424020556.png]]
- ![[Pasted image 20250424020606.png]]


### LEFT OUTER JOIN WITH WHERE STATEMENT
- Here we are looking to grab all info that is in table A but NOT in table B.
```
select * from <table A>
left outer join <table B>
on <table A>.<col match> = <table B>.<col match>
where <table B>.<id> is null;
```
- ![[Pasted image 20250424020730.png]]

![[Pasted image 20250424020911.png]]

![[Pasted image 20250424020920.png]]


# RIGHT JOINS
- The same thing as LEFT JOIN except tables are switched.
![[Pasted image 20250424021438.png]]
- The same thing can be done with the WHERE STATEMENT.
![[Pasted image 20250424021551.png]]
- RIGHT OUTER JOIN is the same as RIGHT JOIN.


# UNIONS
- Unions are used to combine the result set of two or more select statements.
- It directly concatenates two results together.
- They should be logical, contain the same columns and be able to stack up on top of another.
![[Pasted image 20250424022624.png]]




# CHALLENGE

1. 
![[Pasted image 20250424024037.png]]
```
select distinct c.email, a.district
from customer c
join address a
on c.address_id = c.address_id
where a.district = 'California'
order by c.email asc;
```
![[Pasted image 20250424024028.png]]

2. 
![[Pasted image 20250424024129.png]]

```
SELECT f.title, concat(a.first_name, ' ', a.last_name) from film f
join film_actor fa
on f.film_id = fa.film_id
join actor a
on fa.actor_id = a.actor_id
where a.first_name = 'Nick' AND a.last_name = 'Wahlberg';
```

![[Pasted image 20250424024540.png]]