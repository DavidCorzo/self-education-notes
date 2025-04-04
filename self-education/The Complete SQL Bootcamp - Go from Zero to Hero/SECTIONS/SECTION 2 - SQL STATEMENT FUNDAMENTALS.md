


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
