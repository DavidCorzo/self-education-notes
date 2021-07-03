# lambda num: num**2 # num is local

# name = "Global string"
# def greet():
#     name = 'Sammy'
#     def hello():
#         print('Hello ' + name)
#     hello()
# greet()
# # output: Hello Sammy

# # GLOBAL
# name = "Global string"
# def greet():
#     # ENCLOSING 
#     name = 'Sammy'
#     def hello():
#         # LOCAL
#         name = 'Im a local'
#         print('Hello ' + name)
#     hello()
# greet()
# # output: Hello Im a local

# x = 50 
# def func():
#     global x # go to the global space and grab the variable x
#     # Anything that happens with x will be equivalent as it happening on a global scope.
#     print(f"x is {x}")
#     #LOCAL REASSIGNMENT ON A GLOBAL VARIABLE
#     x = 'new value'
#     print(f"I JUST LOCALLY CHANGED X TO {x}")
# print(x)
# # output: 50
# func() 
# # output: x is 50
# # output: I JUST LOCALLY CHANGED X TO new value
# print(x)
# # output: new value

# # EQUIVALENT OF ALTERNATIVE
# x = 50 
# def func(x):
#     print(f"x is {x}")
#     #LOCAL REASSIGNMENT ON A GLOBAL VARIABLE
#     x = 'new value'
#     print(f"I JUST LOCALLY CHANGED X TO {x}")
#     return x
# x = func(x)
# # output: x is 50 
# # output: I JUST LOCALLY CHANGED X TO new value
# print(x)
# # output: new value
