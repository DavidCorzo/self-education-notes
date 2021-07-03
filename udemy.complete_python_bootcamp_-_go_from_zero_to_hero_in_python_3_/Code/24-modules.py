# from collections import Counter 
# l = [1,1,1,1,12,2,2,2,2,3,3,3,3,3,4,5,5,5,6]
# Counter(l)
# # output: Counter({3: 5, 1: 4, 2: 4, 5: 3, 12: 1, 4: 1, 6: 1})
# s = "aaaassssssvvvvsssaasassjjjdjjd"
# Counter(s)
# # output: Counter({'s': 12, 'a': 7, 'j': 5, 'v': 4, 'd': 2})
# s = "Hello this is a sentence containing lots of hellos and hello statments hello hello hello"
# Counter(s.split())
# # output: Counter({'hello': 4, 'Hello': 1, 'this': 1, 'is': 1, 'a': 1, 'sentence': 1, 'containing': 1, 'lots': 1, 'of': 1, 'hellos': 1, 'and': 1, 'statments': 1})
# c = Counter(s.split())
# c.most_common(2) # Two most common
# # output: [('hello', 4), ('Hello', 1)]

# from collections import defaultdict
# d = defaultdict(object)
# d['one'] 
# # output: <object object at 0x0000019728D8E1B0>
# d = defaultdict(lambda: 0) # lambda that returns 0
# d['one'] 
# # output: 0
# d['two'] = 2
# d 
# # output: defaultdict(<function <lambda> at 0x0000019728DDC1E0>, {'one': 0, 'two': 2})

# d = {}
# d['a'] = 1
# d['b'] = 2
# d['c'] = 3
# d['d'] = 4
# d['e'] = 5
# d 
# # output: {'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5}

# for k,v in d.items():
#     print(k,v)
# # output: a 1
# # output: c 3
# # output: e 5
# # output: b 2
# # output: d 4

# from collections import OrderedDict
# d = OrderedDict()
# d['a'] = 1
# d['b'] = 2
# d['c'] = 3
# d['d'] = 4
# d['e'] = 5
# d 
# # output: a 1
# # output: b 2
# # output: c 3
# # output: d 4
# # output: e 5

# d1 = {}
# d1['a'] = 1
# d1['b'] = 2

# d2 = {}
# d2['a'] = 2
# d2['b'] = 1

# print(d1 == d2)
# # output: True

# d1 = OrderedDict()
# d1['a'] = 1
# d1['b'] = 2

# d2 = OrderedDict()
# d2['b'] = 2
# d2['a'] = 1

# print(d1 == d2)
# # output: False 

# from collections import namedtuple
# Dog = namedtuple('Dog','age breed name')
# sam = Dog(age=2,breed='Lab',name='Sammy')
# sam.age
# # output: 2
# sam[0]
# # output: 2

# Cat = namedtuple('Cat','fur claws name')
# c = Cat(fur='Fuzzy',claws=False,name='Kitty')
# c.name
# # output: 'Kitty'
# c[2]
# # output: 'Kitty'

# import datetime 
# t = datetime.time(5,25,1)
# print(t)
# t.hour
# # output: 5
# t.minute
# # output: 25
# t.second
# # output: 1
# print(datetime.time.min)
# # output: 00:00:00
# print(datetime.time.max)
# # output: 23:59:59.999999
# print(datetime.time.resolution)
# # output: 0:00:00.000001

# today = datetime.date.today() 
# print(today)
# # output: 2020-05-25
# today.timetuple() 
# # output: time.struct_time(tm_year=2020, tm_mon=5, tm_mday=25, tm_hour=0, tm_min=0, tm_sec=0, tm_wday=0, tm_yday=146, tm_isdst=-1)
# today.year
# # output: 2020
# today.month
# # output: 4
# today.day
# # output: 25
# print(datetime.date.min)
# # output: 0001-01-01
# print(datetime.date.max)
# # output: 9999-12-31
# print(datetime.date.resolution)
# # output: 1 day, 0:00:00

# d1 = datetime.date(2015,3,11)
# print(d1)
# # output: 2015-03-11
# d2 = d1.replace(year=1900)
# print(d2) 
# # output: datetime.date(1900, 3, 11)
# d1-d2 
# # output: datetime.timedelta(days=42003)

# import pdb 
# x = [1,3,4]
# y = 2 
# z = 3 
# result = y + z 
# print(result)

# pdb.set_trace()

# result2 = y + x 
# print(result2)
# # output: import pdb 
# x = [1,3,4]
# y = 2 
# z = 3 
# result = y + z 
# print(result)

# pdb.set_trace()

# result2 = y + x 
# print(result2)
# # output: -> result2 = y + x
# # output: (Pdb) y
# # output: 2     
# # output: (Pdb) x
# # output: [1, 3, 4]
# # output: (Pdb) y+x
# # output: *** TypeError: unsupported operand type(s) for +: 'int' # output: and 'list'
# # output: (Pdb) x+z
# # output: *** TypeError: can only concatenate list (not "int") to # output: list
# # output: (Pdb) y+x
# # output: *** TypeError: unsupported operand type(s) for +: 'int' # output: and 'list'
# # output: (Pdb) y+z
# # output: 5
# # output: (Pdb) q

# import timeit 
# timeit.timeit('"-".join(str(n) for n in range(100))',number=1_000)
# # output: 0.018360799999999955
# timeit.timeit('"-".join([str(n) for n in range(100)])',number=10_000)
# # output: 0.16509299999999993
# timeit.timeit("-".join(map(str,range(100))),number=10_000)
# # output: 0.00012020000000001474

# import re 
# patterns = ["term1","term2"]
# text = 'This is a string with term1, but not the other term'
# re.search('hello','hello world!')
# # output: <re.Match object; span=(0, 5), match='hello'>
# match = re.search(patterns[0],text)
# type(match)
# # output: <class 're.Match'>
# match.start()
# # output: 22
# match.end()
# # output: 27
# split_term = '@'
# phrase = 'What is your email, is it hello@gmail.com'
# re.split(split_term,phrase)
# # output: ['What is your email, is it hello', 'gmail.com']
# 'hello world'.split()
# # output: ['hello', 'world']
# re.findall(pattern="match",string="Here is one match, here is another match")
# # output: ['match', 'match']

# def multi_re_find(patterns,phrase):
#     for pattern in patterns: 
#         print(f"Searching the phrase using the re check: {pattern}")
#         print(re.findall(pattern,phrase))

# test_phrase = 'sdsd..sssddd...sdddsddd...dsds...dsssss...sdddd'
# test_patterns = [
#     'sd*', # s followed by zero or more d's
#     'sd+', # s followed by one or more d's
#     'sd?', # s followed by zero or one d's
#     'sd{3}', # s followed by three d's 
#     'sd{2,3}' # s followed by two to three d's
# ]
# multi_re_find(test_patterns,test_phrase)

# # output: Searching the phrase using the re check: sd*
# # output: ['sd', 'sd', 's', 's', 'sddd', 'sddd', 'sddd', 'sd', 's',  's', 's', 's', 's', 's', 'sdddd']
# # output: Searching the phrase using the re check: sd+
# # output: ['sd', 'sd', 'sddd', 'sddd', 'sddd', 'sd', 'sdddd']
# # output: Searching the phrase using the re check: sd?
# # output: ['sd', 'sd', 's', 's', 'sd', 'sd', 'sd', 'sd', 's', 's',  's', 's', 's', 's', 'sd']
# # output: Searching the phrase using the re check: sd{3}
# # output: ['sddd', 'sddd', 'sddd', 'sddd']
# # output: Searching the phrase using the re check: sd{2,3}
# # output: ['sddd', 'sddd', 'sddd', 'sddd']

# test_phrase = 'sdsd..sssddd...sdddsddd...dsds...dsssss...sdddd'
# test_patterns = [
#     '[sd]', # either s or d
#     's[sd]+' # s followed by one or more s or d
# ]
# multi_re_find(test_patterns,test_phrase)
# # output: Searching the phrase using the re check: [sd]
# # output: ['s', 'd', 's', 'd', 's', 's', 's', 'd', 'd', 'd', 's', 'd', 'd', 'd', 's', 'd', 'd', 'd', 'd', 's', 'd', 's', 'd', 's', 's', 's', 's', 's', 's', 'd', 'd', 'd', 'd']
# # output: Searching the phrase using the re check: s[sd]+
# # output: ['sdsd', 'sssddd', 'sdddsddd', 'sds', 'sssss', 'sdddd']

# test_phrase = 'This is a string! But it has punctuation. How can we remove it?'
# re.findall('[^!.? ]+',test_phrase)
# # output: ['This', 'is', 'a', 'string', 'But', 'it', 'has', 'punctuation', 'How', 'can', 'we', 'remove', 'it']

# test_phrase = 'This is an example sentence. Lets see if we can find some letters.'
# test_patterns = [
#     '[a-z]+', # sequences of lower case letters
#     '[A-Z]+', # sequences of upper case letters
#     '[a-zA-Z]+', # sequences of lower or upper case letters 
#     '[A-Z][a-z]+' # one upper case letter followed by lower case letters.
# ]
# multi_re_find(test_patterns,test_phrase)
# # output: Searching the phrase using the re check: [a-z]+
# # output: ['his', 'is', 'an', 'example', 'sentence', 'ets', 'see', 'if', 'we', 'can', 'find', 'some', 'letters']
# # output: Searching the phrase using the re check: [A-Z]+
# # output: ['T', 'L']
# # output: Searching the phrase using the re check: [a-zA-Z]+
# # output: ['This', 'is', 'an', 'example', 'sentence', 'Lets', 'see', 'if', 'we', 'can', 'find', 'some', 'letters']
# # output: Searching the phrase using the re check: [A-Z][a-z]+
# # output: ['This', 'Lets']

# test_phrase = 'This is a string with some numbers 1233 and a symbol #hashtag'
# test_patterns = [
#     r'\d+', # sequense of digits
#     r'\D+', # sequense of non-digits
#     r'\s+', # sequense of whitespace
#     r'\S+', # sequense of characters
#     r'\w+', # alphanumeric characters
#     r'\W+' # non-alphanumeric
# ]
# multi_re_find(test_patterns,test_phrase)
# # output: Searching the phrase using the re check: \d+
# # output: ['1233']
# # output: Searching the phrase using the re check: \D+
# # output: ['This is a string with some numbers ', ' and a symbol #hashtag']
# # output: Searching the phrase using the re check: \s+
# # output: [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ']
# # output: Searching the phrase using the re check: \S+
# # output: ['This', 'is', 'a', 'string', 'with', 'some', 'numbers', '1233', 'and', 'a', 'symbol', '#hashtag']
# # output: Searching the phrase using the re check: \w+
# # output: ['This', 'is', 'a', 'string', 'with', 'some', 'numbers', '1233', 'and', 'a', 'symbol', 'hashtag']
# # output: Searching the phrase using the re check: \W+
# # output: [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' #']

# import StringIO
# message = 'This is just a normal string'
# f = StringIO.StringIO(message)
# f.read()
# f.write(' Second')
# f.seek(0)
