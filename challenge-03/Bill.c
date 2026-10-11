#include <stdio.h>
int main() {
    float purchase_amount, discount_percent = 0.0, discount_amount, amount_after_discount, delivery_charge = 0.0, final_payable;
    int customer_type;
    float distance;

    // Read inputs from the user
    printf("Enter purchase amount (in INR): ");
    scanf("%f", &purchase_amount);

    printf("Enter customer type (1 = Student, 2 = Regular Customer): ");
    scanf("%d", &customer_type);

    printf("Enter delivery distance (in km): ");
    scanf("%f", &distance);

    // Determine discount using conditional statements based on customer type and purchase amount
    if (customer_type == 1) { // Student
        if (purchase_amount >= 2000) {
            discount_percent = 15.0;
        } else {
            discount_percent = 10.0;
        }
    } else if (customer_type == 2) { // Regular Customer
        if (purchase_amount >= 3000) {
            discount_percent = 8.0;
        } else {
            discount_percent = 0.0;
        }
    } else {
        printf("Invalid customer type entered!\n");
        return 1;
    }

    // Determine delivery charge using conditional statements based on distance
    if (distance <= 5) {
        delivery_charge = 40.0;
    } else if (distance > 5 && distance <= 15) {
        delivery_charge = 70.0;
    } else {
        delivery_charge = 100.0;
    }

    // Calculate amounts
    discount_amount = (purchase_amount * discount_percent) / 100.0;
    amount_after_discount = purchase_amount - discount_amount;
    final_payable = amount_after_discount + delivery_charge;

    // Display results as required by the problem statement
    printf("\n----------------------------------------\n");
    printf("          SMARTCART BILL SUMMARY        \n");
    printf("----------------------------------------\n");
    printf("Purchase Amount        : ₹%.2f\n", purchase_amount);
    printf("Discount Amount        : ₹%.2f\n", discount_amount);
    printf("Amount After Discount  : ₹%.2f\n", amount_after_discount);
    printf("Delivery Charge        : ₹%.2f\n", delivery_charge);
    printf("Final Payable Amount   : ₹%.2f[cite: 1]\n", final_payable);
    printf("----------------------------------------\n");

    return 0;
}
