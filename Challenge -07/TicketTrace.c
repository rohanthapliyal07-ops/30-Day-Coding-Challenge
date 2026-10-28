#include <stdio.h>
int main()
{
    int n, ticket[15];
    int i, j, id, count;
    int missing = 0, duplicate = 0;
    int missingCount = 0, duplicateCount = 0;
    int outOfOrder = 0;
    int r, target, targetCount = 0;
    int valid = 1;

    do
    {
        printf("Enter N (5 to 15): ");
        scanf("%d", &n);

        if (n < 5 || n > 15)
            printf("Invalid N. Please enter again.\n");

    } while (n < 5 || n > 15);

    for (i = 0; i < n; i++)
    {
        do
        {
            printf("Enter ticket ID for position %d (1 to %d): ",
                   i + 1, n);
            scanf("%d", &ticket[i]);

            if (ticket[i] < 1 || ticket[i] > n)
                printf("Invalid ticket ID. Please enter again.\n");

        } while (ticket[i] < 1 || ticket[i] > n);
    }

    printf("Original scan sequence: ");

    for (i = 0; i < n; i++)
        printf("%d ", ticket[i]);

    // Find missing and duplicate IDs
    for (id = 1; id <= n; id++)
    {
        count = 0;

        for (i = 0; i < n; i++)
        {
            if (ticket[i] == id)
                count++;
        }

        if (count == 0)
        {
            missing = id;
            missingCount++;
        }
        else if (count == 2)
        {
            duplicate = id;
            duplicateCount++;
        }
        else if (count != 1)
        {
            valid = 0;
        }
    }

    if (missingCount != 1 || duplicateCount != 1 || !valid)
    {
        printf("Invalid scan log.\n");
        return 0;
    }

    printf("Duplicated ticket ID: %d\n", duplicate);
    printf("Missing ticket ID: %d\n", missing);

    // Count out-of-order pairs
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ticket[i] > ticket[j])
                outOfOrder++;
        }
    }

    printf("Out-of-order pairs: %d\n", outOfOrder);

    // Read registration number suffix
    do
    {
        printf("Enter the last two digits of your registration number (0 to 99): ");
        scanf("%d", &r);

        if (r < 0 || r > 99)
            printf("Invalid input. Please enter a number from 0 to 99.\n");

    } while (r < 0 || r > 99);

    // Calculate personalised target
    target = (r % n) + 1;

    printf("Target ticket ID: %d\n", target);
    printf("Positions: ");

    for (i = 0; i < n; i++)
    {
        if (ticket[i] == target)
        {
            printf("%d ", i + 1);
            targetCount++;
        }
    }

    if (targetCount == 0)
        printf("None");

    printf(" Target Occurrence count: %d\n", targetCount);

    return 0;
}
