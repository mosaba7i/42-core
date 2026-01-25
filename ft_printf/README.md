# 🖨️ ft_printf — Recreating printf in C

> This project has been created as part of the 42 curriculum by malsabah
<p align ="center">
  <img src="https://media.giphy.com/media/Ta1R0vSRfVLmDrvhHf/giphy.gif" />
</p>
---

## 📌 Description

`ft_printf` is a core project in the 42 curriculum.
The goal is to **recreate the behavior of the standard C `printf` function**
as a static library, following strict rules and using only allowed system calls.

This project focuses on:
- Variadic functions
- Format string parsing
- Low-level output handling
- Static library creation (`.a`)
- Precise control over memory and logic

---

## 🧠 What Is printf?

`printf` is a standard C function used to print formatted output to the terminal.

Example:
printf("Hello %s, you scored %d/100", name, score);

It works by:
1. Reading a format string
2. Detecting conversion specifiers (like %d, %s)
3. Replacing them with the corresponding values
4. Writing the final result to standard output

---

## 🔎 Project Objective

The objective of `ft_printf` is to:
- Parse the format string manually
- Detect and handle conversion specifiers
- Retrieve arguments using `va_list`
- Print the correct output
- Return the exact number of printed characters
- Compile everything into a static library: `libftprintf.a`

---

## 🔤 Supported Conversion Specifiers

The mandatory part supports:

- %c → character
- %s → string
- %p → pointer address (hexadecimal)
- %d → signed decimal integer
- %i → signed integer
- %u → unsigned integer
- %x → hexadecimal (lowercase)
- %X → hexadecimal (uppercase)
- %% → literal percent sign

---

## 🧬 Variadic Functions Explained

Because `printf` accepts a variable number of arguments,
`ft_printf` uses `<stdarg.h>`.

Key macros:
- va_start → initialize argument reading
- va_arg → retrieve next argument
- va_end → clean up

Each conversion specifier determines the type retrieved from `va_arg`.

---

## 🔁 Parsing Logic

The format string is scanned character by character.

Workflow:
1. If the current character is NOT `%` → print it directly
2. If `%` is found → read the next character
3. Match it with a supported specifier
4. Call the corresponding handler function
5. Increase the printed character count

---

## 🔢 Number & Base Conversion Logic

Numbers are printed without using the real `printf`.

Implementation ideas:
- Handle negative numbers explicitly
- Print digits recursively or iteratively
- Convert numbers using different bases:
  - Base 10 for decimal
  - Base 16 for hexadecimal
- Convert digits to characters manually

---

## 🧵 Output Handling

All output is written using:
write(1, &c, 1);

This ensures:
- Full control over output
- No forbidden functions
- Compliance with project rules

---

## ⚙️ Compilation

This project compiles into a **static library**.

```bash
make
```

This will generate:
```
libftprintf.a
```

---

## ▶️ Usage

Since `ft_printf` is a library, it must be **linked** to your program.

### Example `main.c`

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, number = %d\n", "world", 42);
    return (0);
}
```

### Compile your program with the library

```bash
cc main.c libftprintf.a
```

Or, if used inside another project (like `libft`):

```bash
cc main.c -L. -lftprintf
```

### Return Value

`ft_printf` returns:
- The total number of characters printed
- Same behavior as the original `printf`

---

## 🧠 Implementation Overview

1. Initialize `va_list`
2. Parse the format string
3. Detect conversion specifiers
4. Fetch the corresponding argument
5. Print formatted output
6. Count and return printed characters

---

## 🎯 Learning Outcomes

Through this project I learned:
- Variadic function internals
- Format string parsing
- Base conversion and number formatting
- Static library creation with `ar`
- Writing modular and norm-compliant C code

---

## 📚 Resources

### 📖 Documentation
- man 3 printf
- man 3 stdarg
- man 1 ar

### 📘 Helpful References
- https://en.cppreference.com/w/c/variadic
- https://man7.org/linux/man-pages/man3/printf.3.html

---

## ✅ Notes

- Mandatory part only (no bonus)
- Output matches required behavior
- Compiles into `libftprintf.a`
- Designed to be simple, clean, and readable
