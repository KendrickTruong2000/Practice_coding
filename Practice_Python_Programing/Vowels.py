def count_vowels(s):
    vowel = ('a', 'e', 'i', 'o','u')
    count = 0

    for c in s:
        if c in vowel:
            count += 1
    
    print("Number of vowels: ", count)      
    return count

user_input = input("Please enter a string: ")
count_vowels(user_input.lower())