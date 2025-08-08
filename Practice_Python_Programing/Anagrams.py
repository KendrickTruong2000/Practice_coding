def group_anagrams(lst):
    group_dict = {}
    
    for item in lst:
        key = tuple(sorted(item))
        if key in group_dict:
            group_dict[key].append(item)
        else:
            group_dict[key] = [item]

    groups = list(group_dict.values())
    print("Grouped anagrams: ", groups)

    return groups

strs = []
num = int(input("Enter number of element: "))

for i in range(num):
    element = input(f"Enter a string for element number {i}: ")
    strs.append(element)

print("List ", strs)
group_anagrams(strs)