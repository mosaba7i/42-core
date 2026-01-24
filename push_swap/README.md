 *This project has been created as part of the 42 curriculum by malsabah*
---
<p align="center">
  <img src="https://miro.medium.com/v2/resize:fit:600/format:webp/1*1MiLjMYgr2r2fDORCJn89w.gif" width="500"/>
  <img src="https://miro.medium.com/v2/resize:fit:640/format:webp/1*ZLKF3qJ75poRylB9g8wM5w.gif" width="500"/>
  
</p>

# push_swap

## Description

`push_swap` is a sorting algorithm project from 42 curriculum
The goal is to sort a list of integers using two stacks a and b and a limited
set of allowed operations sa pb ra rra etc producing the smallest possible number of ops

The program validate input only integers no duplicates within INT_MIN INT_MAX
and output the sequence of operations needed to sort the numbers in ascending order

Small lists 5 or less numbers use a dedicated small-sort algoritm while larger lists
use normalized indexs with a binary radix sort

---

## Instructions

### Compilation

To compile the project run

make

This will generate the push_swap executable in the project dir

### Execution

Run the program by passing a list of integers as arguments

./push_swap 3 2 1

The program prints the operations needed to sort the input one per line
Only integers within INT_MIN and INT_MAX are accept
Duplicate numbers or invalid input will result in Error printed to stderr

### Example Usage

./push_swap 5 2 3 1 4
### Sample output
pb
pb
sa
pa
pa
ra

./push_swap 2 1
### Output
sa

---

## Resources

### References

42 Push_swap Guide
https://42-cursus.gitbook.io/guide/2-rank-02/push_swap

Push Swap Explaind Medium
https://medium.com/@ayogun/push-swap-c1f5d2d41e97

These referances were used to understand the project requirements allowed operations and common algoritms like indexing and radix sort

### AI Usage Disclosure

AI tools was not used to write the project code

AI assistance was used only for conceptual explanation such as
Understanding stack operations
Clarifing how radix sort work
Explaining small-sort stratgies

All implementaion logic and final code were writen by the goat malsabah hehe :)
