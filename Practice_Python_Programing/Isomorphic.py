def check_isomorphic(s1, s2):

    if len(s1) != len(s2):
        return False
    
    map_s1 = {}
    map_s2 = {}

    for c1, c2 in zip(s1, s2):
        if (c1 in map_s1 and map_s1[c1] != c2) or (c2 in map_s2 and map_s2[c2] != c1):
            return False
        
        map_s1[c1] = c2
        map_s2[c2] = c1

    return True

str1 = input("Please enter 1st string: ")
str2 = input("Please enter 2nd string: ")
print(check_isomorphic(str1, str2))