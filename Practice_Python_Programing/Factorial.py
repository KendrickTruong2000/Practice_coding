def cal_factorial(n):
    result = 1
    for i in range(1, n + 1):
        result = result * i

    return result

user_input = int(input("Please enter a number to find factorial: "))
result = cal_factorial(user_input)
print(result)