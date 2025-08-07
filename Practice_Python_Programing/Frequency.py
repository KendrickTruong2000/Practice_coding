def count_frequency(list):
    count = 0
    num = []
    freq_dict = {}

    for i in list:
        temp = i
        if i not in num:
            num.append(temp)
            for item in list:
                if temp == item:
                    count += 1
    
            print(f"{temp}:{count}")
            count = 0

    # for i in list:
    #     temp = i
    #     if temp not in freq_dict:
    #         freq_dict[i] = 1
    #     else:
    #         freq_dict[i] += 1

    # return freq_dict

a = []
freq_dict = {}
n = int(input("Enter the number of elements: "))

for i in range(n):
    element = input(f"Enter element {i+1}: ")
    a.append(element)

print("List: ", a)

count_frequency(a)
# freq_dict = count_frequency(a)

# for value, count in freq_dict.items():
#     print(f"{value}:{count}")
