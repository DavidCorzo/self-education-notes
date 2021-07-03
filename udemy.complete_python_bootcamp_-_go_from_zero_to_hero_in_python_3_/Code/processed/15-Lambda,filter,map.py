# def square(num):
#     return num**2

# my_nums = [1,2,3,4,5]

# for item in map(square,my_nums):
#     print(item)
# # output: 1
# # output: 4
# # output: 9
# # output: 16
# # output: 25

# list(map(square,my_nums))
# # output: [1, 4, 9, 16, 25]


# def check_even(num):
#     return num%2 == 0

# mynums = [1,2,3,4,5,6]

# list(filter(check_even,mynums))
# # output: [2, 4, 6]

# for n in filter(check_even,mynums):
#     print(n)
# # output: 2
# # output: 4
# # output: 6

# square = lambda num: num ** 2
# square(5)
# # output: 25

# list(map(lambda num: num**2,mynums))
# # output: [1, 4, 9, 16, 25, 36]

# list(map(lambda num: num%2 == 0,mynums))
# # output: [2, 4, 6]

# names = ['Hello','World','!']
# list(map(lambda string:string[0],names))
# # output: ['H', 'W', '!']
