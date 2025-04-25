


## **THE SELECT STATEMENT**
* The select statement is the most common statement in SQL, it retrieves information from a given source, typically a table.
```
SELECT column_name_1, column_name_2 FROM table_name;
```
* Steps taken by SQL:
	1. Figures out which database you are operating in.
	2. Figures out which table you are referencing.
	3. Figures out which column you want to retrieve.
* The "\*"  for the column name will retrieve all the columns as they appear in the table.
```
select * from actor;
SELECT last_name, first_name FROM actor;
```
* The SQL keywords are not case sensitive, you can write it in lower or upper case, or any mix of the two.
```
sElEcT * fRoM table; -- the column and table names are case sensitive
```


### **THE SELECT DISTINCT KEYWORD**
- The distinct  keyword allows the query to return unique values on a column, if there are 1 million rows of the field "numbers" and we run a distinct, instead of returning 1 million rows, it returns just the numbers unique to that column. Example: 1,2,3,4,4,4,4,4,5,6,7,8,9 -> 1,2,3,4,5,6,7,8
```
SELECT DISTINCT <column> FROM <table>;  
SELECT DISTINCT(<column>) FROM <table>;
```
- You can also use parenthesis to specify and apply distinct just to that column and not to other columns that might be involved in the select statement.
- Basically only used to figure out or isolate the unique values on a column.


### **THE COUNT FUNCTION**
- The count function allows us to count the number of rows that are returned in a query.
- It does need a parenthesis because it is a function that acts on something.
```
SELECT COUNT(<col>) from table; -- returns the number of rows in the column <col>
```
- It can be mixed with the DISTINCT keyword:
```
	SELECT COUNT(DISTINCT <col>) from <table>; 
	SELECT COUNT( DISTINCT(<col>) ) from <table>;
```



### **THE SELECT WHERE STATEMENT**
```
SELECT <column(s)> FROM <table> WHERE <condition(s)>;
```
- the condition is a filter applied to the rows of the select statement.
- The condition can be any of the following:
	- comparisons: greater than, equal to, etc. <, >, <=, >=, =, <>, !=
	- logical operators: AND, OR, NOT


### **ORDER BY STATEMENT**
- SQL queries are not ordered, the result of one query will not be maintained across computers or even if you repeat the same query the order might change. 
- use "order by" to order the query explicitly. ```
```
SELECT <column(s)> FROM <table> ORDER BY <column(s)> ASC/DESC;
```
* ASC means ascending, desc means descending.


### **LIMIT KEYWORD**
- The LIMIT command will allow us to limit the amount of rows a query returns, append it as the last thing int the query. 
```
SELECT <column(s)> FROM <table> ORDER BY <column(s)> ASC/DESC LIMIT <num_of_rows>;
```
- the LIMIT will allow us to return n number of rows from the query.
- Use it in conjunction with order by to return valuable information such as top or lower n rows based on a certain criteria.
```
SELECT * FROM payment 
ORDER BY payment_date DESC 
LIMIT 5;
-- returns 5 most recent payments.
```



### **BETWEEN KEYWORDS OPERATOR**
- The between keyword is used to filter in values only based on the conditions if the are "between" one lower and upper limit inclusive, it includes the limits.
- Can be used with the NOT operator to specify you want all values not matching the between conditions.
- The between operator works with numerical data types, and with dates as long as they follow the YYYY-MM-DD format (ISO 8601). 
	- Keep in mind that the 0:00 hour of dates are included in the result if you use the between operator, these include hours and the 0:00 is included.
```
SELECT * FROM payment
WHERE amount BETWEEN 8 AND 9;
```
- Checkout the date example:
```
SELECT * FROM payment
WHERE payment_date BETWEEN 
'2007-02-01' AND '2007-02-15';
-- includes the dates and times including the 0:00 hours
-- means from the 2 of february until the 15 of february at 0:00 hours, meaning the 15th is not included after the 0:00 hour.
```


### **THE "IN" OPERATOR**
- This syntax is basically only used to avoid having to write a bunch of OR statments.
```
SELECT color FROM table
WHERE color IN ('red', 'blue', 'yellow');
```
- You can combine it with other operators such as the NOT operator to exclude the list.
```
SELECT color FROM table
WHERE color IN NOT ('red', 'blue', 'yellow');
```


### **THE "LIKE" OPERATOR**
- Enables the use of wildcards. 
- The "%" sign, means any character from that point forward until we hit another character specified in the query. In regular expressions is equivalent to  ".\*" .
- The "\_" means any character but just a single character, equivalent to "." in regex.
- LIKE is case sensitive, ILIKE is case insensitive.
- SQL supports regular expression capabilities, here is the documentation https://www.postgresql.org/docs/current/functions-matching.html
```
SELECT * FROM customer
WHERE first_name LIKE 'J%';
-- all fields starting with the letter J.
```
- ILIKE case insensitive.
```
SELECT * FROM customer
WHERE first_name ILIKE 'J%';
-- all fields starting with the letter J or j.
```




