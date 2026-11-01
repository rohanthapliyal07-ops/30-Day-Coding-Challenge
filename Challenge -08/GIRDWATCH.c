
#include <stdio.h>

int a[6][6], n, t;
int count = 0, hotspots = 0;

void input();
void display();
void rows();
void columns();
void fullGrid();
void diagonals();
void boundary();
void hotspot();
void decision();

void input()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter value [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);

            while (a[i][j] < 0 || a[i][j] > 100)
            {
                printf("Invalid! Enter 0 to 100: ");
                scanf("%d", &a[i][j]);
            }
        }
    }
}

void display()
{
    int i, j;
    printf("\nRisk Grid:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%4d", a[i][j]);

        printf("\n");
    }
}

void rows()
{
    int i, j, sum, max = 0;

    printf("\nROW ANALYSIS\n");

    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
            sum = sum + a[i][j];

        printf("Row %d = %d\n", i + 1, sum);

        if (sum > max)
            max = sum;
    }

    printf("Highest row total = %d\n", max);
    printf("Highest row(s): ");

    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
            sum = sum + a[i][j];

        if (sum == max)
            printf("%d ", i + 1);
    }
    printf("\n");
}

void columns()
{
    int i, j, sum, max = 0;

    printf("\nCOLUMN ANALYSIS\n");

    for (j = 0; j < n; j++)
    {
        sum = 0;
        for (i = 0; i < n; i++)
            sum = sum + a[i][j];

        printf("Column %d = %d\n", j + 1, sum);

        if (sum > max)
            max = sum;
    }

    printf("Highest column total = %d\n", max);
    printf("Highest column(s): ");

    for (j = 0; j < n; j++)
    {
        sum = 0;
        for (i = 0; i < n; i++)
            sum = sum + a[i][j];

        if (sum == max)
            printf("%d ", j + 1);
    }
    printf("\n");
}

void fullGrid()
{
    int i, j, max = a[0][0];
    count = 0;

    printf("\nFULL GRID ANALYSIS\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] > max)
                max = a[i][j];

            if (a[i][j] >= t)
                count++;
        }
    }

    printf("Highest risk = %d\n", max);
    printf("Highest risk positions:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == max)
                printf("Row %d Column %d\n", i + 1, j + 1);
        }
    }

    printf("Cells meeting threshold = %d\n", count);
}

void diagonals()
{
    int i, d1 = 0, d2 = 0;

    printf("\nDIAGONAL ANALYSIS\n");

    for (i = 0; i < n; i++)
    {
        d1 = d1 + a[i][i];
        d2 = d2 + a[i][n - 1 - i];
    }

    printf("Main diagonal = %d\n", d1);
    printf("Secondary diagonal = %d\n", d2);

    if (d1 == d2)
        printf("Diagonals are balanced.\n");
    else
        printf("Diagonals are not balanced.\n");
}

void boundary()
{
    int i, j, sum = 0;

    printf("\nBOUNDARY ANALYSIS\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 ||
                j == 0 || j == n - 1)
                sum = sum + a[i][j];
        }
    }

    printf("Boundary total = %d\n", sum);
}

void hotspot()
{
    int i, j;
    hotspots = 0;

    printf("HOTSPOT ANALYSIS\n");

    for (i = 1; i < n - 1; i++)
    {
        for (j = 1; j < n - 1; j++)
        {
            if (a[i][j] >= t &&
                a[i][j] > a[i-1][j] &&
                a[i][j] > a[i+1][j] &&
                a[i][j] > a[i][j-1] &&
                a[i][j] > a[i][j+1])
            {
                printf("Hotspot at Row %d Column %d, Score = %d\n",
                       i + 1, j + 1, a[i][j]);
                hotspots++;
            }
        }
    }

    if (hotspots == 0)
        printf("No local hotspots found.\n");
    else
        printf("Total hotspots = %d\n", hotspots);
}

void decision()
{
    printf("SECURITY RESPONSE\n");

    if (hotspots > 0)
        printf("CRITICAL\n");
    else if (count >= n)
        printf("WARNING\n");
    else
        printf("NORMAL\n");
}

int main()
{
    printf("========== GRIDWATCH ==========\n");

    printf("Enter grid size (3 to 6): ");
    scanf("%d", &n);

    while (n < 3 || n > 6)
    {
        printf("Invalid size! Enter again: ");
        scanf("%d", &n);
    }

    input();

    printf("Enter warning threshold (1 to 100): ");
    scanf("%d", &t);

    while (t < 1 || t > 100)
    {
        printf("Invalid threshold! Enter again: ");
        scanf("%d", &t);
    }

    display();
    rows();
    columns();
    fullGrid();
    diagonals();
    boundary();
    hotspot();
    decision();
    return 0;
}
