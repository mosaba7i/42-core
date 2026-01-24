
# 📚 libft — Custom C Standard Library

> *This project has been created as part of the 42 curriculum by malsabah* 🐐  
> A foundational C library built completely from scratch.

<p align="center">
  <img src="https://media.giphy.com/media/uUIFcDYRbvJTtxaFNa/giphy.gif"
       width="320" height="200" style="object-fit: cover;"/>
  <img src="https://media.giphy.com/media/3oKIPnAiaMCws8nOsE/giphy.gif"
       width="320" height="200" style="object-fit: cover;"/>
</p>



---

## 📌 Description

`libft` is the first major project in the 42 curriculum.  
The objective is to reimplement essential functions from the C standard library
and build a **reusable personal library** that will be used in future projects.

This project focuses on:
- 🧠 Understanding memory allocation
- 🧵 Mastering string manipulation
- ⚙️ Low-level C behavior and safety

⚠️ **No bonus part was implemented in this version.**  
Only mandatory functions are included, as required by the subject.

---

## 🧩 Implemented Functions

### 🔹 Memory Functions
- `ft_memset`
- `ft_bzero`
- `ft_memcpy`
- `ft_memmove`
- `ft_memchr`
- `ft_memcmp`
- `ft_calloc`

### 🔹 String Functions
- `ft_strlen`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_strchr`
- `ft_strrchr`
- `ft_strnstr`
- `ft_strdup`

### 🔹 Character Checks
- `ft_isalpha`
- `ft_isdigit`
- `ft_isalnum`
- `ft_isascii`
- `ft_isprint`

### 🔹 Conversions
- `ft_atoi`

### 🔹 Output
- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

---

## ⚙️ Compilation

```bash
make
```

This will generate:

```bash
libft.a
```

Clean object files:

```bash
make clean
```

Remove everything:

```bash
make fclean
```

---

## 🧪 How To Use

Include in your project:

```c
#include "libft.h"
```

Compile with:

```bash
cc main.c -L. -lft
```

---

## 🎯 Learning Outcomes

- Proper memory allocation and freeing
- Pointer safety
- Reusable modular coding
- Debugging segmentation faults 

---

## 📚 Resources

### 📖 Documentation
- Linux man pages: `man strlen`, `man memcpy`
- GNU C Library Manual  
  https://www.gnu.org/software/libc/manual/

### 📘 Tutorials
- C Memory Management  
  https://www.learn-c.org/en/Memory_management
- C String Functions  
  https://www.programiz.com/c-programming/c-strings

### 🎥 Videos
- Pointers in C (freeCodeCamp)  
  https://www.youtube.com/watch?v=zuegQmMdy8M

---
