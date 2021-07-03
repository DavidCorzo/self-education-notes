# def create_cubes(n):
#     """ 
#     This function will create an entire list in memory before doing anything else. 
#     """
#     result = []
#     for x in range(n):
#         result.append(x**3)
#     return result 

# for x in create_cubes(10):
#     print(x)
# # output: 0
# # output: 1
# # output: 8
# # output: 27
# # output: 64
# # output: 125
# # output: 216
# # output: 343
# # output: 512
# # output: 729

# def create_cubes(n):
#     """
#     This function will produce the cubes according to when they are needed. 
#     """
#     for x in range(n):
#         yield x**3
# for i in create_cubes(10):
#     print(x)
# # output: 0
# # output: 1
# # output: 8
# # output: 27
# # output: 64
# # output: 125
# # output: 216
# # output: 343
# # output: 512
# # output: 729

# def gen_fibon(n):
#     """ Memory ineficient fib sequence """
#     a,b = 1,1
#     output = []
#     for i in range(n):
#         output.append(a) 
#         a,b = b,a+b 
#     return output
# for num in gen_fibon(10):
#     print(num)
# # output: 1
# # output: 1
# # output: 2
# # output: 3
# # output: 5
# # output: 8
# # output: 13
# # output: 21
# # output: 34
# # output: 55

# def gen_fibon(n):
#     """ Memory eficient fib sequence """
#     a,b = 1,1
#     for i in range(n):
#         yield a 
#         a,b = b,a+b 
# for num in gen_fibon(10):
#     print(num)
# # output: 1
# # output: 1
# # output: 2
# # output: 3
# # output: 5
# # output: 8
# # output: 13
# # output: 21
# # output: 34
# # output: 55

# def simple_gen():
#     for x in range(3):
#         yield x 
# for num in simple_gen():
#     print(num)
# # output: 0
# # output: 1
# # output: 2

# g = simple_gen()
# g
# # output: <generator object simple_gen at 0x000001BB5D22D840>

# print(next(g))
# # output: 0
# print(next(g))
# # output: 1
# print(next(g))
# # output: 2
# print(next(g))
# # Traceback (most recent call last):
# #   File "<stdin>", line 1, in <module>
# # StopIteration

# s = "hello"
# for letter in s: 
#     print(letter)
# next(s)
# # Traceback (most recent call last):
# #   File "<stdin>", line 1, in <module>
# # TypeError: 'str' object is not an iterator

# s_iter = iter(s) 
# next(s_iter)
# # output: 'h'
# next(s_iter)
# # output: 'e'
# next(s_iter)
# # output: 'l'

# square = (i**2 for i in range(1,11))
# print(square)
# # output: <generator object <genexpr> at 0x0000014A1427D840>
# for x in square:
#     print(x)
# # output: 1
# # output: 4
# # output: 9
# # output: 16
# # output: 25
# # output: 36
# # output: 49
# # output: 64
# # output: 81
# # output: 100

