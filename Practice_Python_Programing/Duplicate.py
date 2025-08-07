def find_duplicate(list):
    freq_dict = {}
    duplicate = []

    for item in list:
        if item in freq_dict:
            freq_dict[item] += 1
            if freq_dict[item] == 2:
                duplicate.append(item)
        else:
            freq_dict[item] = 1

    return duplicate

a = []
d = []
n = int(input("Enter the amount of elements: "))

for i in range(n):
    element = input(f"enter element {i + 1}: ")
    a.append(element)

print("List: ", a)
d = find_duplicate(a)

print(d)
# for i in d:
#     print(i)