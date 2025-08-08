import itertools

def find_permutations(s):
    perms = itertools.permutations(s)
    result = [''.join(p) for p in perms]
    print("All possible permuations: ")
    for perm in result:
        print(perm)

    return result

user_input = input("Please enter a string to find all possible permutations: ")
find_permutations(user_input)