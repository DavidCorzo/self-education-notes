# def new_decorator(original_func):
#     def wraper_func():
#         print("Some code actions before your original function")
#         original_func()
#         print("Some code actions after your original function")
#     return wraper_func
# def func_deco():
#     print("This is the code intended to be decorated")
# decorated_func = new_decorator(func_deco)
# decorated_func()
# # output: Some code actions before your original function
# # output: This is the code intended to be decorated
# # output: Some code actions after your original function
# 
# # Using a decorator syntax
# @new_decorator
# def func_deco():
#     print("This is the code intended to be decorated")
# func_deco()
# # output: Some code actions before your original function
# # output: This is the code intended to be decorated
# # output: Some code actions after your original function
