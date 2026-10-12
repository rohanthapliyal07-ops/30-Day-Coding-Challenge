#include <stdio.h>

int main() {
    float amount;
    
    // Counters and Totals
    int valid_count = 0;
    int small_count = 0;
    int medium_count = 0;
    int large_count = 0;
    
    float total_amount = 0.0;
    float small_total = 0.0;
    float medium_total = 0.0;
    float large_total = 0.0;

    printf("=== SMARTLOOP: Daily Expense Analyzer ===\n");
    printf("Enter expense amounts. Enter 0 to stop.\n");

    // Using a simple while loop
    while (1) {
        printf("Enter expense amount: ");
        scanf("%f", &amount);

        // Stop signal: if amount is 0, exit the loop
        if (amount == 0) {
            break;
        }

        // Negative amount check
        if (amount < 0) {
            printf("Error: Negative amount! Invalid expense.\n");
            continue; // Skip the rest and ask for the next input
        }

        // If it is a valid positive expense
        valid_count = valid_count + 1;
        total_amount = total_amount + amount;

        // Classify into Small, Medium, or Large
        if (amount < 100) {
            small_count = small_count + 1;
            small_total = small_total + amount;
        } 
        else if (amount >= 100 && amount < 500) {
            medium_count = medium_count + 1;
            medium_total = medium_total + amount;
        } 
        else {
            large_count = large_count + 1;
            large_total = large_total + amount;
        }
    }

    // Displaying the Summary
    printf("\n--- EXPENSE SUMMARY REPORT ---\n");

    if (valid_count == 0) {
        printf("No valid expenses were entered.\n");
    } else {
        printf("Number of valid expenses: %d\n", valid_count);
        printf("Total of valid expenses: %.2f\n", total_amount);
        printf("Average valid expense: %.2f\n\n", total_amount / valid_count);

        printf("Category Breakdown:\n");
        printf("Small (Below 100):    Count = %d, Total = %.2f\n", small_count, small_total);
        printf("Medium (100 to <500): Count = %d, Total = %.2f\n", medium_count, medium_total);
        printf("Large (500 or more):  Count = %d, Total = %.2f\n", large_count, large_total);
    }

    return 0;
}
