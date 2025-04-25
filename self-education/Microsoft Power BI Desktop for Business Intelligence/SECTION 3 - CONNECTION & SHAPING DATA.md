
# POWER BI FRONT END AND BACKEND
* The frontend of PWBI includes the Data, Model & Report views, where most of the modeling, analysis and visualization takes place.
* The backend includes the Power Query Editor, where raw data is extracted, transformed, and loaded to the front-end (ETL).


# TYPES OF DATA CONNECTORS
- Using the Get Data option, you can connect perhaps to any data source, from excel worksheets to SQL databases, etc.


# PRO TIP: STORAGE AND CONNECTION MODES
- **Import**: tables are stored in memory within PWBI and queries are fulfilled by cached data (default).
	- Dataset must be less than 1GB after compression.
	- Source data does not change frequently.
	- No restrictions on Power Query data modeling, and DAX functions.
- **DirectQuery**: tables are connected directly to the source and queries are executed on demand at the data source.
	- Dataset is too large to be stored in-memory.
	- Source data changes frequently and reports must reflect changes.
	- Source data changes frequently and reports must reflect changes.
	- Company policy states that data can only be accessed from the original source.
- **Composite model (dual)**: table come from a mix of import and directquery modes, or integrate multiple directquery tables.
	- Boosts performance by setting appropriate storage for each table.
	- Combine a directquery model with additional imported data.
	- Create a single model from two or more directquery models.
- **Live connection**: connect to pre-published power bi datasets in power bi service or azure analysis services.
	- Create one dataset that serves as a central source of truth.
	- Analyst teams can create different reports from the same source.
	- Multi-developer teams where one user builds the model and another works on visualization.



# DATA PROFILING QA AND PROFILING TOOLS
- Profiling tools like column quality, column distribution, and column profile allow you to explore quality, composition, and distribution of out data before loading it into the power bi frontend. 
- Column distribution: tool used to show the distribution of data within a column.
- Column profile: provides a more holistic view of the data in a column, including a sample distribution and profiling statistics. Provides more detail than column distribution.


# TEXT TOOLS
- Text columns permit manipulating text and fixing mistakes in the data, such as trimming spaces, cleaning spaces, lower and upper case, use delimiters to return, lots of flexibility.
- Difference between transform and add column: the transform overwrites or replaces the current column, the add column adds a brand new column.


# NUMERICAL TOOLS
- Statistics functions allow you to profile columns further:
![[Pasted image 20250423191053.png]]
- You will always need to delete the last applied step.


# DATE AND TIME TOOLS
- ![[Pasted image 20250423193357.png]]
- Almost always you will want to perform these operations from the "add column" menu to build out new fields rather than transforming an individual date/time.
- PRO TIP: load up a table containing a single date column and use date tools to build out an entire calendar table.

# CHANGE TYPE WITH LOCALE
- some countries have the format of date DD/MM/YYYY or MM/DD/YYYY.
- Lets fix this.
- ![[Pasted image 20250423195707.png]]


# ROLLING CALENDAR
- We are going to use M code to create a rolling calendar. 
- ![[Pasted image 20250423200312.png]]


# CONDITIONAL COLUMNS
- ![[Pasted image 20250423202256.png]]


# CALCULATED COLUMN BEST PRACTICES
![[Pasted image 20250423221829.png]]
- The idea is that the table transformations should be manipulated as least as possible to maximize performance, first consider using the data source as is, if it is not possible then PowerQuery, followed by the power bi front end (DAX), and finally the published report.


# GROUPING AND AGGREGATION
- Same as the group by in SQL:
![[Pasted image 20250423222341.png]]


# PIVOTING AND UNPIVOTING
- Pivoting: the process of turning distinct row values into columns
- Unpivoting: the process of turning distinct columns into rows.
- Basically transposing DISTINCT rows and columns.
![[Pasted image 20250423224038.png]]


# MERGING QUERIES
- This basically works like VLOOKUP in excel.
![[Pasted image 20250423224602.png]]
- Generally better to add a relationship in power bi and not to merge.


# APPENDING QUERIES
- Basically adding rows to a table, the new rows need to be identical to the rows that already exist within the table.
![[Pasted image 20250423225024.png]]
- Better to use the folder option in the Get Data menu.


# DATA SOURCE SETTINGS
- The file paths, if they change power bi will not know where the data sources are because they are hardcoded into a file path. The data sources settings is to solve this issue.
![[Pasted image 20250423230020.png]]
- Every time you update the name or location of the files you are importing into power bi you must update the power bi paths, do this using the data source settings. 



# REFRESHING QUERIES
![[Pasted image 20250424131313.png]]
- consider which queries you want to refresh when you hit refresh.


# PRO TIP: IMPORTING EXCEL MODELS
- You can build a data model in excel, and then import it into power bi.
![[Pasted image 20250424131707.png]]


