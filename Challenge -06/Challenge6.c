#include <stdio.h>
int main()
{
    int a[12];
    int n, i, j, temp;
    int sum = 0, min, max;
    int second, found = 0;
    int peaks = 0;
    int currentRun = 1, longestRun = 1;
    int k, shift;
    int r, d, divisible = 0;
    float average;

    // Read and validate N
    do
    {
        printf("Enter number of readings (5 to 12): ");
        scanf("%d", &n);

        if (n < 5 || n > 12)
            printf("Invalid N. Please enter a value from 5 to 12.\n");

    } while (n < 5 || n > 12);

    // Read and validate array elements
    for (i = 0; i < n; i++)
    {
        do
        {
            printf("Enter reading %d (0 to 1000): ", i + 1);
            scanf("%d", &a[i]);

            if (a[i] < 0 || a[i] > 1000)
                printf("Invalid reading. Try again.\n");

        } while (a[i] < 0 || a[i] > 1000);
    }

    // Display original readings
    printf("\nOriginal readings: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    //Calculate sum, minimum and maximum
    min = max = a[0];

    for (i = 0; i < n; i++)
    {
        sum += a[i];

        if (a[i] < min)
            min = a[i];

        if (a[i] > max)
            max = a[i];
    }

    average = (float)sum / n;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);
    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    // Find second-largest distinct value
    for (i = 0; i < n; i++)
    {
        if (a[i] < max)
        {
            if (!found || a[i] > second)
            {
                second = a[i];
                found = 1;
            }
        }
    }

    if (found)
        printf("Second-largest distinct value = %d\n", second);
    else
        printf("No second-largest distinct value exists.\n");

    //Count local peaks
    for (i = 1; i < n - 1; i++)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
            peaks++;
    }

    printf("Number of local peaks = %d\n", peaks);

    // Find longest strictly increasing contiguous run
    for (i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            currentRun++;

            if (currentRun > longestRun)
                longestRun = currentRun;
        }
        else
        {
            currentRun = 1;
        }
    }

    printf("Longest increasing run length = %d\n", longestRun);

    // Read rotation value
printf("\nEnter K for rotation: ");
scanf("%d", &k);

shift = k % n;

if (shift < 0)
    shift += n;

// Rotate array to the right
for (i = 0; i < shift; i++)
{
    temp = a[n - 1];

    for (j = n - 1; j > 0; j--)
        a[j] = a[j - 1];

    a[0] = temp;
}

printf("Rotated readings: ");
for (i = 0; i < n; i++)
    printf("%d ", a[i]);

printf("\n");

    //Registration number calculation
    printf("\nEnter the last two numeric digits of your registration number: ");
    scanf("%d", &r);

    d = (r % 9) + 1;

    for (i = 0; i < n; i++)
    {
        if (a[i] % d == 0)
            divisible++;
    }

    printf("D = %d\n", d);
    printf("Values divisible by D = %d\n", divisible);

    return 0;
}
