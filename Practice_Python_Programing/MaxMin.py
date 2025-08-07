def find_max(list):
    temp = list[0]

    for i in range(len(list)):
        if temp < list[i]:
            temp = list[i]

    return temp

def find_min(list):
    temp = list[0]

    for i in range(len(list)):
        if temp > list[i]:
            temp = list[i]
    
    return temp

a = []
n = int(input("Enter the number of elements: "))

for i in range(n):
    element = input(f"Enter element {i+1}: ")
    a.append(element)

print("List: ", a)

max = find_max(a)
min = find_min(a)

print("Max: ", max)
print("Min: ", min)