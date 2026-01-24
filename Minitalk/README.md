# 📡 minitalk — Inter-Process Communication in C

> *This project has been created as part of the 42 curriculum by malsabah*
<p align="center">
  <img src="https://37.media.tumblr.com/beb4213459e17195558741b1e4c1aef9/tumblr_n4fnwsiMb81s2wio8o1_500.gif" height="200" width="320"/>
  <img src="https://64.media.tumblr.com/tumblr_ljyb42mmCN1qi5j6xo1_500.gifv" height="200" width="320"/>
</p>

## 📌 Description

`minitalk` is a system programming project from the 42 curriculum.
The goal is to **build a small communication protocol** between two processes
using **only UNIX signals**.

You must create:
- A **server** that receives messages
- A **client** that sends messages

Only:
- `SIGUSR1`
- `SIGUSR2`

---

## 🧠 What Is Inter-Process Communication (IPC)?

**IPC** allows processes to exchange data.

In this project:
- Each **bit** of data is transmitted using a signal
- Signals are sent **one by one**
- The receiver reconstructs the original message

This mimics how low-level communication protocols work.

---

## 🔢 Core Idea — Sending Bits with Signals

Each character is made of **8 bits**.

Example:
```
'A' = 65 = 01000001
```

Transmission logic:
- `0` → send `SIGUSR1`
- `1` → send `SIGUSR2`

The client sends **8 signals per character**.
The server rebuilds the character **bit by bit**.

---

## 🧠 Bit Reconstruction Logic (Server Side)

1. Receive a signal
2. Shift current byte left
3. Add `0` or `1` depending on the signal
4. Repeat until 8 bits are received
5. Print the resulting character
6. Reset and wait for the next character

This is pure **bitwise manipulation**.

---

## ⚙️ Signals Used

### SIGUSR1
- Represents binary `0`

### SIGUSR2
- Represents binary `1`

These signals are user-defined and safe to repurpose.

---

## 🧵 Synchronization (IMPORTANT)

Signals are **asynchronous**.
If the client sends signals too fast:
❌ Bits may be lost.

To prevent this:
- The server **acknowledges** each received bit
- The client waits before sending the next bit
- or you can use usleep() as i did which is an effective simple solution to the probblem
This ensures **reliable communication**.

---

## 🖥️ Program Structure

### 🖥️ Server
- Displays its **PID**
- Waits indefinitely for signals
- Decodes incoming bits
- Prints received message to STDOUT

### 💻 Client
- Takes:
  - Server PID
  - Message string
- Encodes characters into bits
- Sends bits using signals
- Waits for acknowledgment

---

## ▶️ Usage

### 1️⃣ Compile
```bash
make
```

### 2️⃣ Start Server
```bash
./server
```

Output example:
```
Server PID: 4242
```

### 3️⃣ Send Message
```bash
./client 4242 "Batman Was Here!"
```

---

## 🧠 Implementation Overview

### Client Side
1. Convert each character to binary
2. Send bits MSB → LSB
3. Send signal for each bit
4. Wait for server acknowledgment

### Server Side
1. Catch signals using `signal`
2. Store bits using shifts and OR
3. Print character after 8 bits
4. Send acknowledgment back

---

## 🧩 Bitwise Operations Used

- `<<` left shift
- `|` bitwise OR
- `&` bit masking

These operations allow precise control over individual bits.

---

## ⚠️ Edge Cases Handled

- Empty strings
- Multiple consecutive messages
- Fast signal bursts
- Server restart safety
- End-of-string detection (`\0`)

---

## 🎯 Learning Outcomes

Through this project I learned:
- UNIX signal handling
- Bitwise operations
- Process synchronization
- Low-level IPC concepts
- Writing reliable communication logic in C

---

## 📚 Resources

### 📖 UNIX & Signals
- Signals Overview  
  https://man7.org/linux/man-pages/man7/signal.7.html

- kill  
  https://man7.org/linux/man-pages/man2/kill.2.html

### 📘 C & Bitwise Logic
- Bitwise Operators in C  
  https://www.geeksforgeeks.org/bitwise-operators-in-c/

- ASCII Table  
  https://www.asciitable.com/

### 🎥 Videos
- UNIX Signals Explained  
  https://www.youtube.com/watch?v=83M5-NPDeWs

- Bitwise Operations Visualized  
  https://www.youtube.com/watch?v=jlQmeyce65Q

---

## 🏁 Final Notes

`minitalk` is a deceptively simple project that teaches **how computers actually talk** under the hood.
It forces you to think in bits, timing, and signals — just like real operating systems do.
