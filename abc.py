from itertools import product
import string

u_pwd = input("Enter a password: ")
chars = string.ascii_lowercase + string.digits
for attempt in product(chars, repeat=len(u_pwd)):
    guess = ''.join(attempt)
    print(f"Trying: {guess}")
    if guess == u_pwd:
        print("Password cracked:", guess)
        break
