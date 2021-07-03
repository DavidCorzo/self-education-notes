index = 0
word = 'abcde'
for item in word: 
    print(index,item)
    index += 1
# (0,'a')
# (1,'b')
# (2,'c')
# (3,'d')
# (4,'e')
# The same can be achived with enumerate 
for item in enumerate(word):
    print(item)
# (0,'a')
# (1,'b')
# (2,'c')
# (3,'d')
# (4,'e')

mylist1 = [1,2,3]
mylist2 = ['a','b','c']
mylist3 = [100,200,300]
for item in zip(mylist1,mylist2,mylist3): 
    print(item)
# output: (1,'a',100)
# output: (2,'b',200)
# output: (3,'c',300)

'x' in ['x','y']
# output: True 
'mykey' in {'mykey':345} # works for the keys 
# output: True

mylist = [1,2,3]
min(mylist)
# output: 1
max(mylist)
# output: 3
mylist = "abcd"
min(mylist)
# output: a
max(mylist)
# output: d

from random import shuffle 
mylist = [1,2,3,4,5,6,7,8,9,10]
shuffle(mylist)
# output: [3, 9, 5, 1, 2, 10, 8, 6, 7, 4] -> it shuffles it

from random import randint 
mynum = randint(0,10)
# output: 3 -> random number in range 0 to 9

result = input("Enter a number: ")
# output: Enter a number: -> you will be required to enter input.

mylist = [letter for letter in 'string']
# output: ['s', 't', 'r', 'i', 'n', 'g']

mylist = [num for num in range(0,11)]
# grab the square of every number in that list.
mylist = [num**2 for num in range(0,11)]
# output: [0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100]

mylist = [x for x in range(0,11) if x % 2 == 0]
# output: [0, 2, 4, 6, 8, 10]

fahrenheit = []
celcius = [0,10,20,34.5]
for temp in celcius: 
    fahrenheit.append(((9/5)*temp + 32))
# output: [32.0, 50.0, 68.0, 94.1]

# Alternatively on a one liner
fahrenheit = [((9/5)*temp + 32) for temp in celcius]
# output: [32.0, 50.0, 68.0, 94.1]

results = [x if x % 2 == 0 else 'ODD' for x in range(0,11)]
# output: [0, 'ODD', 2, 'ODD', 4, 'ODD', 6, 'ODD', 8, 'ODD', 10]

mylist = []
for x in [2,4,6]:
    for y in [1,10,1_000]:
        mylist.append(x*y)
# output: [2, 20, 2000, 4, 40, 4000, 6, 60, 6000]

# Alternative one liner
myresult = [x*y for x in [2,4,6] for y in [1,10,1_000]]
# output: [2, 20, 2000, 4, 40, 4000, 6, 60, 6000]
