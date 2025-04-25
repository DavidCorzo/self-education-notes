

### **AGGREGATE FUNCTION**
- An aggregate function takes multiple inputs and returns a single output, such as average, sum, count, etc.
	- AVG(), COUNT(), MAX(), MIN(), SUM()
- Only allowed in the SELECT clause or the HAVING clause.
```
SELECT MIN(replacement_cost) FROM FILM; -- returns the minimum replacement cost
SELECT MAX(replacement_cost) FROM FILM; -- returns the maximum replacement cost
```
- Can only return 1 row columns matrices from 1 x n.
```
SELECT MIN(replacement_cost), MAX(replacement_cost) FROM FILM;
-- returns the minimum and max.
```


### **"GROUP BY"**
- First choose a _categorical column_, needs to be non-continuous, in other words different.
- Second we choose the _data column_, this will be the second column returned, we can then transform the data column and group by the categorical column. Its better if you just see it.
- Example:
![[Pasted image 20250406160911.png]]
- First it will split the categorical column into its unique values, basically a distinct procedure, then it will group all the data column values that are accompanied with the each unique value, creating a set of sub tables. 
- After we can operate or transform each of the data columns of each individual sub table such as with the count aggregate function, we can also leave it as is and return the sub tables, however in the examples we operate each sub table with the count, counting how many rows each sub table has and returning it.
- The general syntax is as follows.
```
SELECT <category_col>, AGG(<data_col>)
FROM <table>
GROUP BY <category_col>;
```
- This is a procedure that can work with any filtering prier to returning the data you can use the where statement for example.
--- 
- In the SELECT statement columns must have an aggregate function or be in the GROUP BY call.
```
SELECT company, division, SUM(sales)
FROM finance_table
GROUP BY company, division;
```
- In other words, the select and group by statement must list the same columns except when in the select statement some column is being aggregated, in this case SUM(sales) does NOT need to be in the GROUP BY clause because it is being aggregated.
- The WHERE statement should not refer to the aggregation result, in this case we cannot touch with the WHERE statement the aggregation result of sales. We use HAVING for this.
```
SELECT company, division, SUM(sales)
FROM finance_table
WHERE sum(sales) > 10000
GROUP BY company, division;
-- INCORRECT, where statement cannot manipulate aggregate function results. Use having.
```
- Here is another example query:
```
SELECT company, sum(sales)
from finance_table
group by company
order by sum(sales) -- refer to the results
limit 5;
-- This query is correct, you can reference results of aggregate functions using the order by statement, not the where statement.
```


- Lets find out the amount per customer id and order it from highest to lowest.
```
--  list of customers id according to sum of purchases.
select customer_id, sum(amount) from payment
group by customer_id
order by sum(amount) desc;
```
![[Pasted image 20250412210224.png]]
- Now lets find out the total sum of transactions per client, from highest to lowest.
```
-- list of customers id according to sum of total transactions.
select customer_id, count(amount) from payment
group by customer_id
order by count(amount) desc;
```
![[Pasted image 20250412210330.png]]
- Now lets find the total amount spent per customer id and which staff id attended each amount, from hightest to lowest.
```
-- group by and staff id, the amount of purchases per customer.
select customer_id, staff_id, sum(amount) from payment
group by staff_id, customer_id -- will give us the amount purchased per staff id.
order by customer_id desc;
```
![[Pasted image 20250412213113.png]]

- Using the DATE() function. When using group by with dates it is important to use the DATE() function.
```
select date(payment_date), sum(amount) from payment
group by date(payment_date)
order by sum(amount) desc;
```
![[Pasted image 20250412213329.png]]


### CHALLENGE GROUP BY
We have 2 staff members, with staff id's 1, 2. We want to give a bonus to the staff member that handled the most payments. (Most in terms of number of payments processed, not total dollar amount).
How many payments did each staff member handle and who gets the bonus?
```
select staff_id, count(amount) -- grab the staff id, and the count of amounts
from payment
group by staff_id -- group by staff id
order by count(amount) desc; -- order desc
```
![[Pasted image 20250412214527.png]]



### **THE "HAVING" CLAUSE**
- We can filter out values using the WHERE statement before arriving to the GROUP BY statement, sometimes you need to do some further filtering after the group by. An example:
```
select company, sum(sales) 
from finance_table
where company != 'Google'
group by company;
```
- What if we want to filter based on the "sum(sales)" part? That aggregation  will be performed after the group by statement, and we cannot filter it in the WHERE statement since it is an aggregation function.
- This is where HAVING comes in, it goes after the GROUP BY and allows us to filter values of aggregation functions.
```
select company, sum(sales)
from finance_table
where company != 'Google'
group by company
having sum(sales) > 1000; -- now we can filter the aggregate.
```


 ### **SECTION CHALLENGE**

1. Return the customer IDs of customers who have spent at least $110 with the staff member who has an ID of 2. The answer should be customers 187 and 148.
```
select customer_id, staff_id, sum(amount) from payment
where staff_id = 2
group by customer_id, staff_id
having sum(amount) >= 110;
```
2. How many films begin with the letter J? The answer should be 20.
```
select count(title) from film
where title like 'J%';
```
3. What customer has the highest customer ID number whose name starts **with** an 'E' **and** has an address ID lower than 500? The answer is Eddie Tomlin
```
select first_name, last_name from customer
where first_name like 'E%' and address_id < 500
order by customer_id desc
limit 1;
```


