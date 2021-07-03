mylist = [(1,2),(3,4),(5,6),(7,8)]
for (a,b) in mylist: # output: This is variable unpacking, this can be done without the parenthesis. 
    print(a)
    print(b) 
mylist = [(1,2,3),(4,5,6),(7,8,9)]
for a,b,c in mylist: # output: tuple unpacking of three variables. 
    print(a,b,c)
