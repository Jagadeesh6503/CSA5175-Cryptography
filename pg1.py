# Input text and the parameters a (multiplier) and b (increment)
text = input("Enter text: ")
a = int(input("Enter a (multiplier): "))
b = int(input("Enter b (increment): "))

# Encrypt the text
encrypted_text = ""
for char in text:
    if 'a' <= char <= 'z':  # Encrypt lowercase letters
        encrypted_text += chr(((a * (ord(char) - ord('a')) + b) % 26) + ord('a'))
    elif 'A' <= char <= 'Z':  # Encrypt uppercase letters
        encrypted_text += chr(((a * (ord(char) - ord('A')) + b) % 26) + ord('A'))
    else:
        encrypted_text += char  # Non-alphabetic characters remain the same

print("Encrypted text:", encrypted_text)

# Find the modular inverse of 'a'
a_inv = -1
for i in range(26):
    if (a * i) % 26 == 1:
        a_inv = i
        break

if a_inv == -1:
    print("Inverse not found, decryption impossible.")
else:
    # Decrypt the text
    decrypted_text = ""
    for char in encrypted_text:
        if 'a' <= char <= 'z':  # Decrypt lowercase letters
            decrypted_text += chr(((a_inv * (ord(char) - ord('a') - b + 26)) % 26) + ord('a'))
        elif 'A' <= char <= 'Z':  # Decrypt uppercase letters
            decrypted_text += chr(((a_inv * (ord(char) - ord('A') - b + 26)) % 26) + ord('A'))
        else:
            decrypted_text += char  # Non-alphabetic characters remain the same

    print("Decrypted text:", decrypted_text)
