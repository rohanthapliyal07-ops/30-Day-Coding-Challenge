GRIDWATCH – Grid-Based Risk Analysis System

Challenge 8 – C Programming

Problem Statement

Campus security has divided a high-traffic area into an N × N grid. Each cell stores a risk score collected from a sensor:

- "0" represents no risk.
- "100" represents the highest risk.

The objective is to develop a C program called GRIDWATCH that traverses the grid in different ways to identify risky zones and recommend an appropriate security response.

The program must analyse rows, columns, diagonals, boundaries and neighbouring cells. It must also identify local hotspots and determine the overall security status.

---

Input Requirements

1. Read the grid size "N", where:
   
   "3 ≤ N ≤ 6"

2. Read "N × N" integer risk scores, where each value must be between "0" and "100".

3. Read a warning threshold "T", where:
   
   "1 ≤ T ≤ 100"

4. If any input value is outside its permitted range, the program must ask the user to enter that value again.

---

Required Grid Traversals

1. Row Traversal

- Calculate the total risk score of each row.
- Identify and display all row numbers having the highest total.
- Report all ties.

2. Column Traversal

- Calculate the total risk score of each column.
- Identify and display all column numbers having the highest total.
- Report all ties.

3. Full-Grid Traversal

- Find the highest risk score in the entire grid.
- Display every position where the highest score occurs.
- Count the number of cells having a score greater than or equal to the warning threshold "T".

4. Diagonal Traversal

- Calculate the main diagonal sum (top-left to bottom-right).
- Calculate the secondary diagonal sum (top-right to bottom-left).
- If both sums are equal, report that the diagonal totals are balanced.

5. Boundary Traversal

- Calculate the total risk score of all boundary cells.
- Count each boundary cell exactly once, including the four corners.

A cell is considered a boundary cell if it belongs to the first row, last row, first column or last column.

6. Neighbour Traversal – Local Hotspot Detection

Identify every local hotspot in the grid.

A cell is considered a local hotspot if:

- It is an interior cell.
- Its value is strictly greater than its top neighbour.
- Its value is strictly greater than its bottom neighbour.
- Its value is strictly greater than its left neighbour.
- Its value is strictly greater than its right neighbour.
- Its value is greater than or equal to the threshold "T".

Diagonal neighbours must not be considered.

If no local hotspots are found, display a clear message.

---

Final Security Decision

The program must determine the security response using the following conditions in order:

Condition| Security Status
At least one local hotspot exists| CRITICAL
No hotspot exists, but at least N cells meet or exceed T| WARNING
Neither condition is satisfied| NORMAL

Priority: CRITICAL takes precedence over WARNING, and WARNING takes precedence over NORMAL.

---

Rules and Restrictions

1. Use a single square two-dimensional array.
2. Use nested loops for grid traversal.
3. Use "if-else" conditions for decision-making.
4. Do not use a second matrix.
5. Do not use sorting functions.
6. Do not use hard-coded answers.
7. Display positions using row and column numbers starting from 1.
8. Remember that C array indices start from 0.
9. All ties must be reported.
10. Input validation must be implemented for all restricted input values.

---

Expected Concepts

The project involves the following C programming concepts:

- Two-dimensional arrays
- Nested "for" loops
- "while" loops
- Conditional statements ("if-else")
- User-defined functions
- Matrix traversal
- Input validation
- Logical operators
- Basic problem-solving and algorithm development

---

Objective

The main objective of GRIDWATCH is to strengthen programming fundamentals by applying different matrix traversal techniques to a practical risk-analysis scenario.

The project demonstrates how basic C programming concepts can be combined to analyse grid-based data and make decisions based on predefined conditions.

---

Project: GRIDWATCH
Challenge: 8
Language: C
Category: Matrix Traversal and Risk Analysis
