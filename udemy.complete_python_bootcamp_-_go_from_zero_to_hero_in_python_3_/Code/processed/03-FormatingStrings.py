print("this is a string {}".format("inserted"))
# output: This is a string inserted

print("The {} {} {}".format("fox","brown","quick"))
# output:  The fox brown quick 

print("The {2} {1} {0}".format("fox","brown","quick"))
# output: The quick brown fox

print("The {a} {b} {c}".format(a="fox",b="brown",c="quick"))
# output: The quick brown fox

result = 100/777
print(result) 
# output: 0.1287001287001287
# Float formatting formula "{value:width.precision f}"
print("The result was {r:1.3f}".format(r=result))
# output: The result was 0.129 

# F-STRING FORMATING
var = "World"
print(f"Hello {var}")
# output: Hello World
