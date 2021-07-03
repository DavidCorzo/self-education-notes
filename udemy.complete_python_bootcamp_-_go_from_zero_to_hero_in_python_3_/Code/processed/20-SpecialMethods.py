# class Book():
#     def __init__(self,title,author,pages):
#         self.title = title
#         self.author = author 
#         self.pages = pages 
    
# b = Book("Python","David",200)
# print(b)
# # output: <__main__.Book object at 0x000001B7E92102B0>
# # I want to be able to print this in a string form so...

# class Book():
#     def __init__(self,title,author,pages):
#         self.title = title
#         self.author = author 
#         self.pages = pages 
    
#     def __str__(self):
#         return f"{self.title} by {self.author}"
    
#     def __len__(self):
#         return self.pages

#     def __del__(self):
#         print(f"The book object '{self.__str__()}'' has been deleted")

# b = Book("Python","David",200)
# print(b)
# # output: Python by David
# print(len(b))
# # output: 200
# del b 
# # output: The book object 'Python by David' has been deleted
