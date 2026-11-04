#include <stdio.h>
#define ROWS 5
#define COLS 8
// Function declarations
void initializeSeats(int seats[ROWS][COLS]);
void displaySeats(int seats[ROWS][COLS]);
int bookSeat(int seats[ROWS][COLS], int row, int col);
int cancelSeat(int seats[ROWS][COLS], int row, int col);
int reserveGroup(int seats[ROWS][COLS], int groupSize);
void displayReport(int seats[ROWS][COLS]);
int main()
{
    int seats[ROWS][COLS];
    int choice, row, col, groupSize;
    initializeSeats(seats);
    do
    {
        printf("\n===== SEATSMART =====\n");
        printf("1. Display Seats\n");
        printf("2. Book One Seat\n");
        printf("3. Cancel Booking\n");
        printf("4. Group Reservation\n");
        printf("5. Occupancy Report\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                displaySeats(seats);
                break;

            case 2:
                printf("Enter row (1-5): ");
                scanf("%d", &row);

                printf("Enter seat (1-8): ");
                scanf("%d", &col);

                if (bookSeat(seats, row, col) == 1)
                {
                    printf("Seat booked successfully!\n");
                    displaySeats(seats);
                }
                else
                {
                    printf("Booking failed!\n");
                }
                break;

            case 3:
                printf("Enter row (1-5): ");
                scanf("%d", &row);

                printf("Enter seat (1-8): ");
                scanf("%d", &col);

                if (cancelSeat(seats, row, col) == 1)
                {
                    printf("Booking cancelled!\n");
                    displaySeats(seats);
                }
                else
                {
                    printf("Cancellation failed!\n");
                }
                break;

            case 4:
                printf("Enter group size (2-8): ");
                scanf("%d", &groupSize);

                if (reserveGroup(seats, groupSize) == 1)
                {
                    printf("Group booked successfully!\n");
                    displaySeats(seats);
                }
                else
                {
                    printf("No suitable seats available!\n");
                }
                break;

            case 5:
                displayReport(seats);
                break;

            case 6:
                printf("Thank you for using SEATSMART!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
// Set all seats to 0
void initializeSeats(int seats[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            seats[i][j] = 0;
        }
    }
}
// Display all seats
void displaySeats(int seats[ROWS][COLS])
{
    int i, j;

    printf("\nSeating Arrangement:\n");

    for (i = 0; i < ROWS; i++)
    {
        printf("Row %d: ", i + 1);

        for (j = 0; j < COLS; j++)
        {
            printf("%d ", seats[i][j]);
        }

        printf("\n");
    }

    printf("0 = Available, 1 = Booked\n");
}
// Book one seat
int bookSeat(int seats[ROWS][COLS], int row, int col)
{
    if (row < 1 || row > 5 || col < 1 || col > 8)
    {
        return 0;
    }

    row = row - 1;
    col = col - 1;

    if (seats[row][col] == 0)
    {
        seats[row][col] = 1;
        return 1;
    }

    return 0;
}
// Cancel one seat
int cancelSeat(int seats[ROWS][COLS], int row, int col)
{
    if (row < 1 || row > 5 || col < 1 || col > 8)
    {
        return 0;
    }

    row = row - 1;
    col = col - 1;

    if (seats[row][col] == 1)
    {
        seats[row][col] = 0;
        return 1;
    }

    return 0;
}
// Book consecutive seats for a group
int reserveGroup(int seats[ROWS][COLS], int groupSize)
{
    int i, j, k;
    int count;

    if (groupSize < 2 || groupSize > 8)
    {
        return 0;
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j <= COLS - groupSize; j++)
        {
            count = 0;

            for (k = 0; k < groupSize; k++)
            {
                if (seats[i][j + k] == 0)
                {
                    count++;
                }
            }
            if (count == groupSize)
            {
                for (k = 0; k < groupSize; k++)
                {
                    seats[i][j + k] = 1;
                }
                printf("Group allocated in Row %d\n", i + 1);
                printf("Starting seat: %d\n", j + 1);

                return 1;
            }
        }
    }

    return 0;
}
// Display occupancy report
void displayReport(int seats[ROWS][COLS])
{
    int i, j;
    int booked = 0, available;
    int rowCount[ROWS] = {0};
    int max = 0;
    float percentage;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (seats[i][j] == 1)
            {
                booked++;
                rowCount[i]++;
            }
        }
    }
    available = 40 - booked;
    percentage = (booked * 100.0) / 40;

    for (i = 0; i < ROWS; i++)
    {
        if (rowCount[i] > max)
        {
            max = rowCount[i];
        }
    }
    printf("\n===== OCCUPANCY REPORT =====\n");
    printf("Booked Seats: %d\n", booked);
    printf("Available Seats: %d\n", available);
    printf("Occupancy Percentage: %.2f%\n", percentage);
    printf("Busiest Row(s): ");
    
    for (i = 0; i < ROWS; i++)
    {
        if (rowCount[i] == max)
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}
