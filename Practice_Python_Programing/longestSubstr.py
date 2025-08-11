def find_longest_substring(s):
    char = []
    count = 0

    for item in s:
        key = tuple(sorted(item))
        if key not in char:
            char.append(key)
            count += 1
    
    print(char)
    
    return count

str = input("Please enter a string: ")
result = find_longest_substring(str)
print(result)