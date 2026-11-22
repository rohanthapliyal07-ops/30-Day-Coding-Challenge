#include <stdio.h>
#define ZONES 5
#define DAYS 7
void printZoneName(int zone);
void inputWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]);
void displayWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]);
void calculateZoneStats(int *zoneUsage, int *total, float *average, int *peakUsage, int *peakDay);
void detectWaterAlerts(int *zoneUsage, int dailyTarget, int *overLimitDays, int *totalExcess, int *spikeDays, int *alertDays);
void generateAuditReport(int usage[ZONES][DAYS], int dailyTarget[ZONES], int excessByZone[ZONES], int overLimitByZone[ZONES], int spikeByZone[ZONES], int alertByZone[ZONES]);
void rankZones(int excessByZone[ZONES]);
void displayConservationActions(int overLimitByZone[ZONES], int spikeByZone[ZONES], int excessByZone[ZONES]);
int main()
{
    int usage[ZONES][DAYS];
    int dailyTarget[ZONES];
    int excessByZone[ZONES] = {0};
    int overLimitByZone[ZONES] = {0};
    int spikeByZone[ZONES] = {0};
    int alertByZone[ZONES] = {0};
    int choice = 0, reportGenerated = 0;

    printf("===== WATERWISE =====\n");
    inputWaterData(usage, dailyTarget);

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Display Water Data\n");
        printf("2. Generate Audit Report\n");
        printf("3. Rank Zones\n");
        printf("4. Conservation Actions\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayWaterData(usage, dailyTarget);
                break;

            case 2:
                generateAuditReport(usage, dailyTarget, excessByZone,
                                   overLimitByZone, spikeByZone, alertByZone);
                reportGenerated = 1;
                break;

            case 3:
                if(reportGenerated == 1)
                    rankZones(excessByZone);
                else
                    printf("Generate the audit report first.\n");
                break;

            case 4:
                if(reportGenerated == 1)
                    displayConservationActions(overLimitByZone, spikeByZone, excessByZone);
                else
                    printf("Generate the audit report first.\n");
                break;

            case 5:
                printf("Exiting WATERWISE.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 5);

    return 0;
}

void printZoneName(int zone)
{
    switch(zone)
    {
        case 0:
            printf("Academic Block");
            break;
        case 1:
            printf("Hostel");
            break;
        case 2:
            printf("Library");
            break;
        case 3:
            printf("Cafeteria");
            break;
        case 4:
            printf("Sports Complex");
            break;
    }
}

void inputWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES])
{
    int i, j;

    for(i = 0; i < ZONES; i++)
    {
        printf("\nEnter data for ");
        printZoneName(i);
        printf("\n");

        printf("Enter daily target (100 to 50000 litres): ");
        scanf("%d", &dailyTarget[i]);

        while(dailyTarget[i] < 100 || dailyTarget[i] > 50000)
        {
            printf("Invalid target. Enter again: ");
            scanf("%d", &dailyTarget[i]);
        }

        for(j = 0; j < DAYS; j++)
        {
            printf("Day %d consumption (0 to 50000): ", j + 1);
            scanf("%d", &usage[i][j]);

            while(usage[i][j] < 0 || usage[i][j] > 50000)
            {
                printf("Invalid reading. Enter again: ");
                scanf("%d", &usage[i][j]);
            }
        }
    }
}

void displayWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES])
{
    int i, j;

    printf("\n===== WATER CONSUMPTION MATRIX =====\n");

    printf("%-18s", "Zone");

    for(j = 0; j < DAYS; j++)
    {
        printf("Day%d\t", j + 1);
    }

    printf("Target\n");

    for(i = 0; i < ZONES; i++)
    {
        printZoneName(i);
        printf("\t");

        for(j = 0; j < DAYS; j++)
        {
            printf("%d\t", usage[i][j]);
        }

        printf("%d\n", dailyTarget[i]);
    }
}

void calculateZoneStats(int *zoneUsage, int *total, float *average, int *peakUsage, int *peakDay)
{
    int i;

    *total = 0;
    *peakUsage = *zoneUsage;
    *peakDay = 1;

    for(i = 0; i < DAYS; i++)
    {
        *total = *total + *(zoneUsage + i);

        if(*(zoneUsage + i) > *peakUsage)
        {
            *peakUsage = *(zoneUsage + i);
            *peakDay = i + 1;
        }
    }

    *average = (float)*total / DAYS;
}

void detectWaterAlerts(int *zoneUsage, int dailyTarget, int *overLimitDays, int *totalExcess, int *spikeDays, int *alertDays)
{
    int i, over, spike;

    *overLimitDays = 0;
    *totalExcess = 0;
    *spikeDays = 0;
    *alertDays = 0;

    for(i = 0; i < DAYS; i++)
    {
        over = 0;
        spike = 0;

        if(*(zoneUsage + i) > dailyTarget)
        {
            over = 1;
            (*overLimitDays)++;
            *totalExcess = *totalExcess + (*(zoneUsage + i) - dailyTarget);
        }

        if(i > 0 && *(zoneUsage + i) > *(zoneUsage + i - 1) * 1.40)
        {
            spike = 1;
            (*spikeDays)++;
        }

        if(over == 1 || spike == 1)
        {
            (*alertDays)++;
        }
    }
}

void generateAuditReport(int usage[ZONES][DAYS], int dailyTarget[ZONES], int excessByZone[ZONES], int overLimitByZone[ZONES], int spikeByZone[ZONES], int alertByZone[ZONES])
{
    int i, total, peakUsage, peakDay;
    float average;

    printf("\n===== WATER AUDIT REPORT =====\n");

    for(i = 0; i < ZONES; i++)
    {
        calculateZoneStats(&usage[i][0], &total, &average, &peakUsage, &peakDay);

        detectWaterAlerts(&usage[i][0], dailyTarget[i],
                         &overLimitByZone[i], &excessByZone[i],
                         &spikeByZone[i], &alertByZone[i]);

        printf("\nZone: ");
        printZoneName(i);
        printf("\n");

        printf("Weekly total: %d litres\n", total);
        printf("Daily average: %.2f litres\n", average);
        printf("Peak usage: %d litres on Day %d\n", peakUsage, peakDay);
        printf("Over-limit days: %d\n", overLimitByZone[i]);
        printf("Total excess: %d litres\n", excessByZone[i]);
        printf("Spike days: %d\n", spikeByZone[i]);
        printf("Unique alert days: %d\n", alertByZone[i]);
    }

    rankZones(excessByZone);
}

void rankZones(int excessByZone[ZONES])
{
    int i, j, k, rank, highest = 0;

    printf("\n===== ZONE RANKING =====\n");

    for(i = 0; i < ZONES; i++)
    {
        if(excessByZone[i] > highest)
        {
            highest = excessByZone[i];
        }
    }

    if(highest == 0)
    {
        printf("All zones are within their targets.\n");
    }
    else
    {
        printf("Highest excess: %d litres\n", highest);
        printf("Zone(s) with highest excess:\n");

        for(i = 0; i < ZONES; i++)
        {
            if(excessByZone[i] == highest)
            {
                printZoneName(i);
                printf("\n");
            }
        }
    }

    printf("\n===== RANKINGS =====\n");

    for(i = 1; i <= ZONES; i++)
    {
        for(j = 0; j < ZONES; j++)
        {
            rank = 1;

            for(k = 0; k < ZONES; k++)
            {
                if(excessByZone[k] > excessByZone[j])
                {
                    rank++;
                }
            }

            if(rank == i)
            {
                printf("Rank %d: ", rank);
                printZoneName(j);
                printf(" (%d litres)\n", excessByZone[j]);
            }
        }
    }
}
void displayConservationActions(int overLimitByZone[ZONES], int spikeByZone[ZONES], int excessByZone[ZONES])
{
    int i;
    printf("\n===== CONSERVATION ACTIONS =====\n");
    for(i = 0; i < ZONES; i++)
    {
        printf("\nZone: ");
        printZoneName(i);
        printf(" | Excess: %d litres\n", excessByZone[i]);
        if(spikeByZone[i] > 0)
        {
            printf("- Check for leaks or unexpected water usage.\n");
        }
        if(overLimitByZone[i] >= 3)
        {
            printf("- Conduct a water audit and prepare a reduction plan.\n");
        }
        if(overLimitByZone[i] == 1 || overLimitByZone[i] == 2)
        {
            printf("- Monitor those days and inspect taps or valves.\n");
        }

        if(overLimitByZone[i] == 0 && spikeByZone[i] == 0)
        {
            printf("- Maintain current good practices.\n");
        }
    }
}
