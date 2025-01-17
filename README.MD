# Vigenère Cipher in C++

This project implements the Vigenère Cipher in C++. The Vigenère Cipher is a method of encrypting alphabetic text using a simple form of polyalphabetic substitution. It uses a keyword to shift each letter of the plaintext to create the ciphertext.

## Features

- **Encrypt messages**: Convert plaintext to ciphertext using a keyword.
- **Decrypt messages**: Convert ciphertext back to plaintext using the same keyword.
- **Error handling**: Handles invalid inputs gracefully.
- **Fun typing effect**: Adds a typing animation to enhance the user experience.

## Sample Output

```
*******************************************
************** Vigenère Cipher ************
*******************************************

Enter 1 for encryption, 2 for decryption (0 to exit): 1
Enter a message to encrypt: test
Enter the Key (same length as your message!): abcd

Original message: test
Encrypted message: TFUW
Decrypted message: TEST
Your key: abcd

Enter 1 for encryption, 2 for decryption (0 to exit): 2

Enter the Key (same length as your message!): abcd
Enter the decrypted message: tfuw
Encrypted message: tfuw
Decrypted message: TEST
Your key: abcd
```

## Usage Instructions

1. Clone this repository to your local machine.
   ```bash
   git clone https://github.com/B7SJuba/VigenereCipher.git
   ```

2. Open the project folder and compile the code using a C++ compiler such as g++.
   ```bash
   g++ vigenereCipher.cpp -o vigenereCipher
   ```

3. Run the compiled executable.
   ```bash
   ./vigenereCipher
   ```

4. Follow the on-screen prompts to encrypt or decrypt messages.

## How It Works

### Encryption
Each letter in the plaintext is shifted by a value determined by the corresponding letter in the keyword. If the keyword is shorter than the plaintext, it is repeated cyclically.

### Decryption
The reverse of the encryption process, using the same keyword, shifts the ciphertext back to the original plaintext.

### Key Features in the Code
- **Key normalization**: Converts the key to uppercase for consistency.
- **Case handling**: Converts plaintext to uppercase for encryption and decryption.
- **ASCII manipulation**: Ensures all operations stay within the range of alphabetic ASCII values.

## Example
### Input
- Message: `test`
- Key: `abcd`

### Output
- Encrypted message: `TFUW`
- Decrypted message: `TEST`

## Prerequisites
- A C++ compiler (e.g., g++, Visual Studio, or any IDE with C++ support).
- Windows OS for the `Sleep` function used in the typing animation (or replace `Sleep` with an equivalent cross-platform function).

## Customization
- Modify the typing speed by adjusting the `Sleep(20)` value in the `type` function.
- Add additional error checks or enhance the interface as needed.

## License
This project is licensed under the MIT License. Feel free to use and modify it.

