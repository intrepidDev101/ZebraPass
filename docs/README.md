
# ZebraPass

[![Screenshot-From-2024-12-02-18-18-21.png](https://i.postimg.cc/CMsp9sbL/Screenshot-From-2024-12-02-18-18-21.png)](https://postimg.cc/BtbzKDhd)

**A powerful, fun, and interactive CLI-based password generator that crafts unique, secure passwords tailored to your needs. ZebraPass makes password creation enjoyable while ensuring top-notch security for your digital life.**

## Features
**🎨 User-Friendly Design**
- Clear terminal interface with vibrant and colorful ASCII art.
- Concise, interactive menus for ease of use.

**🔑 Password Generation Options**
- Generate random or memorable passwords.
- Choose between auto-generated or user-specified content.
- Specify the number of passwords to generate (single or batch).

**🛠️ Customization**
- Include specific character sets (uppercase, lowercase, digits, special characters).
- Exclude ambiguous characters like I, l, O, 0.
- Set minimum and maximum password length.
- Ensure no character repetition if desired.

**🧠 Password Strength Checker**
- Evaluates password strength based on length, diversity, and common vulnerabilities.
- Provides instant feedback with suggestions for improvement.

**🕵️‍♂️ Advanced Security Options**
- Avoid common patterns and dictionary words.
- Cryptographically secure random number generation.

**💾 Output Options**
- Display passwords in the terminal.
- Save passwords securely to a file.
- Copy passwords directly to the clipboard.

**🔐 Security Best Practices**
- Utilizes secure random number generation methods.
- Avoids storing sensitive data in plain text.
- Regularly updated for adherence to security standards.

## Installation
There are two methods to get **ZebraPass** running on your system: **Manual Compilation** or Using **Makefile**.

**Option 1: Manual Compilation**

To manually compile **ZebraPass**, follow these steps:

1.Clone the repository:

```bash
git clone https://github.com/intrepidDev101/ZebraPass.git
cd ZebraPass
```

2.Compile the source code:

```bash
gcc -o zebrapass zebrapass.c
```

3.Run ZebraPass:

```bash
./zebrapass
```

**Option 2: Using Makefile**

The **Makefile** automates the build process and provides additional features like cleaning up object files and installing the binary.

1.Clone the repository:

```bash
git clone https://github.com/intrepidDev101/ZebraPass.git
cd ZebraPass
```

2.Use the Makefile to compile ZebraPass:

```bash
make
```

This will create the `zebrapass` executable.

3.To clean up object files and the compiled executable, use the `clean` target:

```bash
make clean
```

4,Optionally, you can install **ZebraPass** to your system by running:

```bash
make install
```

This will copy the `zebrapass` executable to `/usr/local/bin/`, making it accessible from anywhere in your terminal.

## Usage
### Menu Options:
1.**Generate Password**
- Choose password type (random or memorable).
- Customize character sets, length, and security features.
2.**Help**
- Access detailed documentation for all program features.
3.**Quit**
- Exit the program safely.


## Example: Generating Passwords
### Steps:
1.Launch ZebraPass and select Generate Password.
2.Choose random or memorable passwords.
3.Define character sets, exclude ambiguous characters, and set password length.
4.Generate single or multiple passwords with your specifications.
5.Save the passwords to a file or copy them to the clipboard.


## Contributing
Contributions are welcome! Please follow these steps:

1.Fork the repository.
2.Create a new branch for your feature/bugfix.
3.Submit a pull request with detailed explanations.

## License
This project is licensed under the [MIT License](#MITLICENSE).

