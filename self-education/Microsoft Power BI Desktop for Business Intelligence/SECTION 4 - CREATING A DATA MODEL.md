

# WHAT IS A DATA MODEL
- A data model is born from the relationships between tables, an example of something that is not a data model:
- ![[Pasted image 20250424133532.png]]
- A data model looks like this because they have relationships:
- ![[Pasted image 20250424133552.png]]



# DATABASE NORMALIZATION
- Normalization: the process of organizing the tables and columns in a relational database to reduce redundancy and preserve data integrity. It's commonly used to: 
	- Eliminate redundant data to decrease table size and improve processing speed and efficiency.
	- Minimize errors and anomalies from data modifications (inserting, updating or deleting records).
	- Simplify queries and structure the database for meaningful analysis.
- In a normalized database each table should serve only one distinct purpose, example, table that only contains information about products, another that only contains customer information.
- Example of non normalized table:
![[Pasted image 20250424134300.png]]


# PRIMARY AND FOREIGN KEYS
![[Pasted image 20250424134630.png]]


# MANAGING AND EDITING RELATIONSHIPS
![[Pasted image 20250424153638.png]]

# STAR AND SNOWFLAKE SCHEMA
- STAR: fact table and dimensions.
![[Pasted image 20250424154256.png]]
- SNOWFLAKE: related tables, no fact table, is an extension of a star schema but creates a chain of dimensions in the table.
![[Pasted image 20250424154345.png]]


# PRO TIP: ACTIVE AND INACTIVE RELATIONSHIPS
- There can only be one active relationship when matching primary and foreign keys, deactivate one to use the other vice versa.
- YOU CAN ONLY HAVE ONE ACTIVE RELATIONSHIP TO A PRIMARY KEY.
![[Pasted image 20250424155344.png]]



# RELATIONSHIP CARDINALITY
- ONE TO MANY
![[Pasted image 20250424163634.png]]
![[Pasted image 20250424163713.png]]
- Example of more complex relationships:
![[Pasted image 20250424164233.png]]




# FILTER CONTEXT AND FILTER FLOW
- Filters are applied through the direction of the relationship.
![[Pasted image 20250424164619.png]]
![[Pasted image 20250424164724.png]]



# BI-DIRECTIONAL FILTERS AND AMBIGUITY
- By allowing bidirectional filters, both sides of the relationship can apply the filters.
![[Pasted image 20250424165034.png]]
![[Pasted image 20250424165121.png]]
![[Pasted image 20250424165206.png]]
![[Pasted image 20250424165326.png]]
- The tip is to always use one way filters, and 1 to many cardinality unless more complex relationships are absolutely necessary.


# HIDING FIELDS FROM REPORT VIEW
- It does not delete it it just hides it.
![[Pasted image 20250424165645.png]]



# PRO TIP: MODEL LAYOUT
![[Pasted image 20250424172927.png]]



# DATA FORMATS AND CATEGORIES
![[Pasted image 20250424173149.png]]
- Changing a date format does not change how they are stored, they only change how they are displayed.


# CREATING HIEARCHIES
![[Pasted image 20250424173754.png]]


# DATA MODEL BEST PRACTICES
