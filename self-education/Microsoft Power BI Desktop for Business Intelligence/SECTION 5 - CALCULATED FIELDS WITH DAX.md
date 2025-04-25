
# Section introduction
- Data Analysis Expression (DAX), this is used to add calculated columns and measures to out model, and introduce topics like row & filter context, iterators and more.


# Data Analysis Expressions 101
- DAX is the formula language that drives the PWBI front end.
- You can use powerful functions that are designed to work with relational databases.
- Add **calculated columns for filtering**, and **measures for aggregation** to enhance data models.


# DAX vs M Language
- What is the difference? They are 2 distinct and functional languages used within PWBI:
	- M is used in the **Power Query editor** and is designed specifically for extracting, transforming and loading data.
	- DAX is used in the **PWBI front end** and is designed specifically for analyzing relational data models.
![[Pasted image 20250425001248.png]]

# Intro to DAX and calculated columns
- Calculated columns allow you to add new formula based columns to tables in a model.
- Some points to consider:
	- Calculated columns refer to entire tables or columns (no A1 style cell references like Excel)
	- Calculated columns generate values for each row, which are visible within tables in the Data View.
	- Calculated columns understand row context, they are great for defining properties based on information in each row, but generally useless for aggregation (sum, count, etc.)
	- You want to use a calculated column to add another column transforming information contained in other columns, you DO NOT want to use calculated columns to perform aggregation: sum, sumx, etc. That is what measures are for. If you use an aggregation function in a calculated column the result of the calculation will be returned in a column of the amount of rows that the data set has, and this cannot be filtered or manipulated.
![[Pasted image 20250425001414.png]]
- Examples:
![[Pasted image 20250425001547.png]]
- DO NOT USE AGGREGATION FUNCTIONS IN CALCULATED COLUMNS.


# INTRO TO DAX MEASURES
![[Pasted image 20250425002357.png]]
- Same as calculated fields, but they generate calculated values that are live.
- You are going to use MEASURES to aggregate, or when you cannot calculate a column based on what is just in the same row.


# IMPLICIT VS EXPLICIT MEASURES
![[Pasted image 20250425002527.png]]


# QUICK MEASURES
![[Pasted image 20250425002940.png]]
- Recommended to validate the result of a quick measure because sometimes they do not get it right.


# RECAP CALCULATED COLUMNS AND MEASURES
![[Pasted image 20250425003057.png]]




# PRO TIP: DEDICATED MEASURE TABLES
- Suggested to keep all measures in a separate table.
- You can create it using DAX or the table builder.
![[Pasted image 20250425003151.png]]

By adding a table and typing the DAX code:
```
Measure Table (DAX) = {""}
```
![[Pasted image 20250425003442.png]]
The issue is that this DAX created table does not appear on the power bi backend, and is not recommended. Instead, use the Enter Data option and create a new table that way:
![[Pasted image 20250425003419.png]]

Once created you can opt to create folders and group your measures like this:
![[Pasted image 20250425003800.png]]

