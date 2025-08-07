def check_prime(n):
    isPrime = True

    for i in range(2, n - 1):
        if n % i == 0:
            isPrime = False
            break

    return isPrime

num = int(input("Please enter a number to check prime number: "))
print(check_prime(num))