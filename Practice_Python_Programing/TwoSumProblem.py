def two_sum_cal(list, target):
    output = []

    for i in range(len(list)):
        complement = target - list[i]
        for j in range(len(list)):
            if complement == list[j]:
                output.append(i)
                output.append(j)

    return output

nums = []
output = []
n = int(input("Enter the number of elements: "))

for i in range(n):
    element = int(input(f"Enter element {i+1}: "))
    nums.append(element)

print("List: ", nums)
target = int(input("Enter target number: "))
output = two_sum_cal(nums, target=target)
print(output)