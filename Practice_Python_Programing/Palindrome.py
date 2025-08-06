def check_palindrom(str, len):
    for i in range(len):
        head = str[i]
        end = str[len - 1 - i]
        
        if head != end:
            return False
        
    return True

user_input = input("Please enter a string: ")
length = len(user_input)
is_palindrom = check_palindrom(user_input, length)
print(is_palindrom)