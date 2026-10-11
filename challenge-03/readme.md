# CODE2THINK | 30 DAYS CHALLENGE

## CHALLENGE 03: SMARTCART

*"Calculate. Check. Decide."*

## 1. Problem Statement

An online store requires an automated billing and delivery fee calculator based on user inputs. The program reads the **purchase amount**, **customer type** (`1` = Student, `2` = Regular Customer), and **delivery distance** (in kilometers) to determine discounts and delivery charges using conditional statements. Finally, it displays the purchase amount, discount amount, amount after discount, delivery charge, and final payable amount.

### Discount Rules
* **Student + Purchase $\ge$ ₹2000:** $15\%$ Discount
* **Student + Purchase $<$ ₹2000:** $10\%$ Discount
* **Regular + Purchase $\ge$ ₹3000:** $8\%$ Discount
* **Regular + Purchase $<$ ₹3000:** $0\%$ Discount

### Delivery Rules
* **Distance $\le$ 5 km:** ₹40
* **Distance $>$ 5 km and $\le$ 15 km:** ₹70
* **Distance $>$ 15 km:** ₹100

---

## 2. Objective
Apply `if`, `else if`, `else`, relational/logical operators, and arithmetic expressions to solve a multi-condition decision-making problem.

---

## 3. Algorithm
1. **Start** the program.
2. **Read** `purchase_amount`, `customer_type`, and `distance`.
3. **Determine Discount Percentage** using nested `if-else` statements based on customer type and purchase thresholds.
4. **Determine Delivery Charge** using `if-else if-else` statements based on distance tiers.
5. **Calculate Billing Details**:
   - $\text{Discount Amount} = (\text{purchase\_amount} \times \text{discount\_percent}) / 100$
   - $\text{Amount After Discount} = \text{purchase\_amount} - \text{discount\_amount}$
   - $\text{Final Payable Amount} = \text{amount\_after\_discount} + \text{delivery\_charge}$
6. **Display** all calculated summary values clearly.
7. **End** the program.

---

## 4. Test Cases & Results

| TC | Purchase | Customer | Distance | Discount | Delivery | Final Amount | Result |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **TC01** | ₹2000 | 1 (Student) | 5 km | ₹300 | ₹40 | ₹1740 | Pass |
| **TC02** | ₹1500 | 1 (Student) | 10 km | ₹150 | ₹70 | ₹1420 | Pass |
| **TC03** | ₹3000 | 2 (Regular) | 15 km | ₹240 | ₹70 | ₹2830 | Pass |
| **TC04** | ₹2500 | 2 (Regular) | 18 km | ₹0 | ₹100 | ₹2600 | Pass |
| **TC05** | ₹5000 | 1 (Student) | 3 km | ₹750 | ₹40 | ₹4290 | Pass |
| **TC06** | ₹4000 | 2 (Regular) | 6 km | ₹320 | ₹70 | ₹3750 | Pass |

---

## 5. How to Compile and Run (C Program)

1. Save the source code into a file named `smartcart.c`.
2. Open your terminal or command prompt.
3. Compile the program using a C compiler (like GCC):
   ```bash
   gcc smartcart.c -o smartcart
   ```
4. Run the executable:
   * **Linux/macOS:** `./smartcart`