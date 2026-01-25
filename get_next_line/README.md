# 📄 get_next_line — Reading Files Line by Line in C

> *This project has been created as part of the 42 curriculum by malsabah*
![Demo GIF](https://preview.redd.it/n46h9ay1rd291.gif?width=400&format=mp4&s=0b3d20a21c0c69fdcceb461f27e70128f83646cd)

---

## 📌 Description

`get_next_line` is a core project in the 42 curriculum.
The objective is to **read a file descriptor line by line**, returning one line
each time the function is called.

This project focuses on:
- File descriptors
- Static variables
- Memory management
- Buffered reading
- Handling partial reads

---

## 🧠 The Problem

In C, reading a file line by line is not trivial:
- `read()` does NOT know what a line is
- Reads may stop in the middle of a line
- Lines can be longer than the buffer size

So we must **store leftover data** and reuse it later.

---

## 🔢 Function Prototype

```c
char *get_next_line(int fd);
```

---

## 🧠 Core Idea — Static Buffer

A **static variable** is used to remember data between calls.

Flow:
1. Read from `fd` into a buffer
2. Append buffer to static storage
3. Check if a newline exists
4. Extract the line
5. Save leftover data for next call

---

## 🧵 BUFFER_SIZE

`BUFFER_SIZE` defines how many bytes are read at once and must work for any value.

---

## ⚙️ Memory Management

- No leaks allowed
- Returned line must be heap-allocated
- Static storage cleaned on EOF

---

## ⚙️ Compilation

first remove the comment notation (/* */) in the get_next_line.c then
```bash
cc -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c \
-o gnl
```

---

## ▶️ Usage

```bash
$ ./gnl example.txt
Hello world
This is get_next_line
42 Network
```

---

## 🎯 Learning Outcomes

- Buffered I/O
- Static variables
- Defensive memory handling

---

## 🏁 Final Notes

`get_next_line` teaches you how real programs read data incrementally.
