def fibonacci(n):
    num1 = 0
    num2 = 1
    temp = 0

    print(temp)
    for i in range(n-1):
       temp = num1
       num1 = num1 + num2
       num2 = temp
       print(num1)

    return

user_input = int(input("Please length of the sequence: "))
fibonacci(user_input)