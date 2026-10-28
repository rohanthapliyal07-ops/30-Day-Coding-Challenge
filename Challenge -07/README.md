# Campus Ticket Audit System

## About the Project
This project is a C program that checks a campus event's ticket scan sequence. It finds the duplicated ticket ID and the missing ticket ID, checks how many pairs are out of order, and displays a personalised audit ticket based on the last two digits of the registration number.

## Features
- Takes the number of tickets and their IDs as input.
- Checks that all inputs are within the allowed range.
- Finds the missing and duplicated ticket IDs.
- Counts out-of-order pairs in the original sequence.
- Calculates a personalised target ticket.
- Displays all positions and the occurrence count of the target ID.
- Reports an invalid scan log if the sequence does not follow the required pattern.

## Concepts Used
- One-dimensional arrays
- `for` loops and nested loops
- `if-else` conditions
- Input validation
- Basic counting and comparison

## Input Rules
- The number of tickets (`N`) must be between 5 and 15.
- Each ticket ID must be between 1 and `N`.
- A valid scan log contains one missing ID and one different ID appearing twice.
- The last two digits of the registration number are used to calculate the personalised target.

## How to Compile and Run

Compile the program using GCC:

```bash
gcc tickettrace.c -o tickettrace
```

Run it using:

```bash
./tickettrace
```

## Example

**Input:**
```text
N = 6
Ticket IDs: 1 3 2 3 5 6
Registration suffix: 26
```

**Output:**
```text
Original scan sequence: 1 3 2 3 5 6
Duplicated ticket ID: 3
Missing ticket ID: 4
Out-of-order pairs: 1
Target ticket ID: 3
Positions: 2 4
Occurrence count: 2
```

## What I Learned
Through this challenge, I practised using arrays and nested loops in C. I learned how to find missing and repeated values, count out-of-order pairs, validate input, and use a registration number to calculate a personalised result.

## Testing
The program was tested with standard inputs, duplicates near the beginning and end, out-of-order sequences, personalised targets, invalid scan logs, and out-of-range inputs.
