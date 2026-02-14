#Shriyans Singh 114807762
HW3/
├── Makefile
├── HW3_main.c
├── MyBitManipulation.h
├── MyBitManipulation.c
├── Myfloat.h
├── Myfloat.c
├── MyIntegers.h
├── MyIntegers.c
└── README.txt  


1- write your name and SBU ID in each of the file.

Part 1:
Q1: In ToggleBit(num, pos) I put the edge case of less than 0, or greater than 31 since we are assuming 32 bits for integer

Q2: made bit_check an unsigned integer because i got worried about -0 error (I tested in a vm, and local. VM had error, local didn't).

Q3. Wrote the constraints requested of start<0, end>31, start>end return num. Additionally made one an unsigned integer to prevent -0 error that happened on vm.

Q4. Constraint to prevent d from being greater than 31 (number could be put, but it would be less than 32). Created a checker to see if most significant bit is one.