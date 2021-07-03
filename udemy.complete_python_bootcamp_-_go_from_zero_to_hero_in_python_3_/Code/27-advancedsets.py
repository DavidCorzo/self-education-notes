# s = set()
# s.add(1)
# s.add(2)
# s
# # output: {1,2}
# s.add(2)
# s 
# # output: {1,2}
# s.clear()
# s = {1,2,3}
# sc = s.copy()
# sc
# s.add(4)
# # output: {1,2,3}
# s.difference(sc)
# # output: {4}
# s1 = {1,2,3}
# s2 = {1,4,5}
# s1.difference_update(s2) # does the same as diference() just that the return from the diference() is applied to s1
# s1 
# # output: {2,3}
# s
# # output: {1,2,3,4}
# s.discard(2)
# # output: {1,3,4}
# s1 = {1,2,3}
# s2 = {1,2,4}
# s1.intersection(s2) # elements that are common to both of the sets
# # output: {1, 2}
# s1 = {1,2}
# s2 = {1,2,4}
# s3 = {5}
# s1.isdisjoint(s2) # returns True if they don't have anything in common. 
# # output: False
# s1.issubset(s2) # {1,2} is a subset of {1,2,4} returns true
# # output: True
# s2.issuperset(s1) # is the inverse of the issubset()
# # output: True
# s1.symmetric_difference(s2) # the elements that are only in one of the sets.
# # output: {4}
# s1.union(s2) # elements that are in either set. 
# # output: {1,2,4}
# s1.update(s2) # it's the same as the union, only that the result is stored in s1. 


