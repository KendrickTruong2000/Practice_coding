def reverses_string(s):
	return s[::-1]

user_input = input("Enter a string: ")
reversed_str = reverses_string(user_input)
print(reversed_str)