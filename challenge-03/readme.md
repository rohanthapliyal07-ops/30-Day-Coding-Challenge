# CODE2THINK | 30 DAYS CHALLENGE
## CHALLENGE 03: SMARTCART
*"Calculate. Check. Decide."*[cite: 1]

---

## 1. Problem Statement
A student is purchasing items from an online store. Read the purchase amount, customer type (1 = Student, 2 = Regular Customer), and delivery distance in kilometres. Determine the discount and delivery charge using conditional statements. Display the purchase amount, discount amount, amount after discount, delivery charge, and final payable amount[cite: 1].

### Discount Rules
* **Student + Purchase >= ₹2000:** 15% Discount[cite: 1, 2]
* **Student + Purchase < ₹2000:** 10% Discount[cite: 1]
* **Regular + Purchase >= ₹3000:** 8% Discount[cite: 1, 2]
* **Regular + Purchase < ₹3000:** 0% Discount[cite: 1]

### Delivery Rules
* **Distance <= 5 km:** ₹40[cite: 1, 2]
* **Distance > 5 km and <= 15 km:** ₹70[cite: 1, 2]
* **Distance > 15 km:** ₹100[cite: 1]

---

## 2. Objective
Apply `if`, `else if`, `else`, relational/logical operators, and arithmetic expressions to solve a multi-condition decision-making problem[cite: 1].

---

## 3. Algorithm
1. **Start** the program.
2. **Read** `purchase_amount`, `customer_type`, and `distance`.
3. **Determine Discount Percentage** using nested `if-else` statements based on customer type and purchase thresholds.
4. **Determine Delivery Charge** using `if-else if-else` statements based on distance tiers.
5. **Calculate Billing Details**:
   - `Discount Amount` = `(purchase_amount * discount_percent) / 100`[cite: 1]
   - `Amount After Discount` = `purchase_amount - discount_amount`[cite: 1]
   - `Final Payable Amount` = `amount_after_discount + delivery_charge`[cite: 1]
6. **Display** all calculated summary values clearly[cite: 1].
7. **End** the program.

---

## 4. Test Cases & Results

| TC | Purchase | Customer | Distance | Discount | Delivery | Final Amount | Result |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **TC01** | ₹2000[cite: 2] | 1 (Student)[cite: 1] | 5 km[cite: 2] | ₹300[cite: 1] | ₹40[cite: 1] | ₹1740 | Pass |
| **TC02** | ₹1500 | 1 (Student)[cite: 1] | 10 km | ₹150[cite: 1] | ₹70[cite: 1] | ₹1420 | Pass |
| **TC03** | ₹3000[cite: 2] | 2 (Regular)[cite: 1] | 15 km[cite: 2] | ₹240[cite: 1] | ₹70[cite: 1] | ₹2830 | Pass |
| **TC04** | ₹2500 | 2 (Regular)[cite: 1] | 18 km | ₹0[cite: 1] | ₹100[cite: 1] | ₹2600 | Pass |
| **TC05** | ₹5000 | 1 (Student)[cite: 1] | 3 km | ₹750[cite: 1] | ₹40[cite: 1] | ₹4290 | Pass |
| **TC06** | ₹4000 | 2 (Regular)[cite: 1] | 6 km | ₹320[cite: 1] | ₹70[cite: 1] | ₹3750 | Pass |

---

## 5. How to Compile and Run (C Program)

1. Save the source code into a file named `smartcart.c`.
2. Open your terminal or command prompt.
3. Compile the program using a C compiler (like GCC):
   ```bash
   gcc smartcart.c -o smartcart
