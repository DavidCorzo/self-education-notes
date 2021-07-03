# # BASE CLASS
# class Animal():
#     def __init(self):
#         print("Animal created")
    
#     def who_im_i(self):
#         print("I'm an animal")
    
#     def eat(self):
#         print("I'm eating")

# # INHERITANCE OF DOG FROM THE ANIMAL CLASS
# class Dog(Animal):
#     def __init__(self): 
#         Animal.__init__(self) # Copy Animal class constructor
#         print("Dog created")
#     def who_im_i(self):
#         print("I'm a dog!")
#     def bark(self):
#         print("I'm a dog eating")

# mydog = Dog()
# # output: Animal created
# # output: Dog created
# mydog.who_im_i()
# # output: I'm a dog!
# mydog.bark()
# # output: I'm a dog eating

# class Dog():
#     def __init__(self,name):
#         self.name = name 
#     def speak(self):
#         print(self.name + " says woof!")

# class Cat():
#     def __init__(self,name):
#         self.name = name 
#     def speak(self):
#         print(self.name + " says meow!")

# niko = Dog("niko")
# felix = Cat("felix")
# print(niko.speak())
# # output: niko says woof!
# print(felix.speak())
# # output: felix says meow!

# for pet in [niko,felix]:
#     print(type(pet))
#     print(pet.speak())
# # output: <class '__main__.Dog'>
# # output: niko says woof!
# # output: <class '__main__.Dog'>
# # output: felix says meow!

# # ABSTRACT CLASSES
# class Animal():
#     def __init__(self,name):
#         self.name = name 
#     def speak(self):
#         raise NotImplementedError("Subclass must implement this abstract method.")
# class Dog(Animal):
#     def __init__(self,name):
#         self.name = name 
#     def speak(self):
#         print(self.name + " says woof!")

# class Cat(Animal):
#     def __init__(self,name):
#         self.name = name 
#     def speak(self):
#         print(self.name + " says meow!")

# fido = Dog("Fido")
# isis = Cat("Isis")
# print(fido.speak())
# print(isis.speak())
