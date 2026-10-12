# Challenge 04: LOOPLAB - Daily Expense Analyzer

A C program designed to process and analyze daily expenses dynamically using core C programming constructs such as infinite loops, conditional statements, arithmetic operations, and formatted input/output.

---

## 1. Problem Statement

Create a C program named **LOOPLAB** to analyze daily expense entries. The program repeatedly reads expense amounts from the user until `0` is entered. For every positive expense, it classifies the amount into a category, updates the respective counts and totals, and prints a final summary report. 

*Constraint Checklist:*
- [x] Uses loops (`while`)
- [x] Uses conditional logic (`if`, `else if`, `else`)
- [x] Uses arithmetic operators (`+`, `/`)

---

## 2. Expense Classification Rules

The program processes input according to the following criteria:

| Expense Amount | Category | Required Action |
| :--- | :--- | :--- |
| **Below ₹100** | Small | Count and add to `small_total` |
| **₹100 to below ₹500** | Medium | Count and add to `medium_total` |
| **₹500 or more** | Large | Count and add to `large_total` |
| **Exactly ₹0** | Stop Signal | Stop execution (do not count or add) |
| **Negative Amount** | Invalid | Display error message (do not count or add) |

---

## 3. Required Output Summary

Upon termination via the `0` stop signal, the program outputs:

| Output Item | Description | Logic / Formula |
| :--- | :--- | :--- |
| **Valid Expenses Count** | Total number of positive entries | Increment by `1` per valid input |
| **Total Valid Expenses** | Sum of all valid expenses | `total_amount = total_amount + amount` |
| **Average Valid Expense** | Mean cost per valid entry | `total_amount / valid_count` |
| **Category Breakdown** | Count & total per category | Individual trackers for Small, Medium, Large |

*Note: If no valid expenses are entered (`valid_count == 0`), the program displays a message indicating no valid entries were made to avoid a division-by-zero error.*

---


## 4. How to Compile and Run

1. Open your terminal in Linux / Unix (e.g., Kali Linux).
2. Navigate to your source file folder:
   ```bash
   cd 
   ```
3. Compile the code using `gcc`:
   ```bash
   gcc Smartloop.c -o SMARTLOOP
   ```
4. Execute the compiled program:
   ```bash
   ./SMARTLOOP
   ```

---

## 5. Sample Input/Output Walkthrough

```text
=== LOOPLAB: Daily Expense Analyzer ===
Enter expense amounts. Enter 0 to stop.

Enter expense amount: 50
Enter expense amount: 300
Enter expense amount: 750
Enter expense amount: -20
Error: Negative amount! Invalid expense.
Enter expense amount: 0

--- EXPENSE SUMMARY REPORT ---
Number of valid expenses: 3
Total of valid expenses: 1100.00
Average valid expense: 366.67

Category Breakdown:
Small (Below 100):    Count = 1, Total = 50.00
Medium (100 to <500): Count = 1, Total = 300.00
Large (500 or more):  Count = 1, Total = 750.00
```
