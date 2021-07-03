while True: 
    pass 
else: # output: combine the else with the while. 
    pass

for item in x: 
    pass 

mystring = "Sammy"
for letter in mystring: 
    if letter == "a":  # this letter will be ommited. 
        continue 
    print(letter)
# output: S
# output: m
# output: m
# output: y

x = 5 
while x < 5: 
    if x == 2: # whenever x = 2 the loop will stop. 
        break 
    print(x)
    x += 1 
