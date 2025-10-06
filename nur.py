# Improved passwordCracker.py
import itertools
import string
import time

# Full character set: lowercase, uppercase, digits, punctuation
charset = string.ascii_letters + string.digits + string.punctuation

# Get user password
u_pwd = input("Enter a password: ")

start_time = time.time()
attempts = 0

print("Cracking Password... Please Wait")

# Brute-force attempt: try all combinations of the correct length
for guess_tuple in itertools.product(charset, repeat=len(u_pwd)):
    guess = ''.join(guess_tuple)
    attempts += 1

    # Optional: show progress every 100000 attempts
    if attempts % 100000 == 0:
        print(f"Attempts: {attempts} | Current guess: {guess}")

    if guess == u_pwd:
        elapsed = time.time() - start_time
        print(f"\n✅ Password cracked: {guess}")
        print(f"🔢 Total attempts: {attempts}")
        print(f"⏱️ Time taken: {elapsed:.2f} seconds")
        break
