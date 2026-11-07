#include <stdio.h>
#define ZONES 5
#define DAYS 7
void inputData(float temp[5][7], float humidity[5][7], int aqi[5][7]);
void displayData(float temp[5][7], float humidity[5][7], int aqi[5][7]);
void calculateAverages(float temp[5][7], float humidity[5][7], int aqi[5][7], float avgTemp[5], float avgHumidity[5], float avgAQI[5]);
void detectRiskZones(float temp[5][7], float humidity[5][7], int aqi[5][7], int riskDays[5]);
void computeGreenIndex(float avgTemp[5], float avgHumidity[5], float avgAQI[5], float greenIndex[5]);
void displayRanking(float greenIndex[5]);
void displayRecommendations(float avgTemp[5], float avgHumidity[5], float avgAQI[5], int riskDays[5]);

void zoneName(int i)
{
    if (i == 0)
        printf("Academic Block");
    else if (i == 1)
        printf("Hostel");
    else if (i == 2)
        printf("Library");
    else if (i == 3)
        printf("Cafeteria");
    else
        printf("Sports Area");
}

void inputData(float temp[5][7], float humidity[5][7], int aqi[5][7])
{
    int i, j;

    for (i = 0; i < 5; i++)
    {
        printf("Enter data for ");
        zoneName(i);
        printf("\n");

        for (j = 0; j < 7; j++)
        {
            printf("Day %d\n", j + 1);

            do
            {
                printf("Temperature (10-50): ");
                scanf("%f", &temp[i][j]);
            } while (temp[i][j] < 10 || temp[i][j] > 50);

            do
            {
                printf("Humidity (0-100): ");
                scanf("%f", &humidity[i][j]);
            } while (humidity[i][j] < 0 || humidity[i][j] > 100);

            do
            {
                printf("AQI (0-500): ");
                scanf("%d", &aqi[i][j]);
            } while (aqi[i][j] < 0 || aqi[i][j] > 500);
        }
    }

    printf("Data entered successfully!\n");
}

void displayData(float temp[5][7], float humidity[5][7], int aqi[5][7])
{
    int i, j;

    printf("TEMPERATURE DATA\n");

    for (i = 0; i < 5; i++)
    {
        zoneName(i);

        for (j = 0; j < 7; j++)
            printf("  %.1f", temp[i][j]);

        printf("\n");
    }

    printf("HUMIDITY DATA\n");

    for (i = 0; i < 5; i++)
    {
        zoneName(i);

        for (j = 0; j < 7; j++)
            printf("  %.1f", humidity[i][j]);

        printf("\n");
    }

    printf("AQI DATA\n");

    for (i = 0; i < 5; i++)
    {
        zoneName(i);

        for (j = 0; j < 7; j++)
            printf("  %d", aqi[i][j]);

        printf("\n");
    }
}

void calculateAverages(float temp[5][7], float humidity[5][7], int aqi[5][7], float avgTemp[5], float avgHumidity[5], float avgAQI[5])
{
    int i, j;
    float t, h, a;

    for (i = 0; i < 5; i++)
    {
        t = 0;
        h = 0;
        a = 0;

        for (j = 0; j < 7; j++)
        {
            t = t + temp[i][j];
            h = h + humidity[i][j];
            a = a + aqi[i][j];
        }

        avgTemp[i] = t / 7;
        avgHumidity[i] = h / 7;
        avgAQI[i] = a / 7;

        printf("\n");
        zoneName(i);
        printf("Average Temperature: %.2f", avgTemp[i]);
        printf("Average Humidity: %.2f", avgHumidity[i]);
        printf("Average AQI: %.2f\n", avgAQI[i]);
    }
}

void detectRiskZones(float temp[5][7], float humidity[5][7], int aqi[5][7], int riskDays[5])
{
    int i, j;

    for (i = 0; i < 5; i++)
    {
        riskDays[i] = 0;

        printf("\n");
        zoneName(i);
        printf("\nRisk Days: ");

        for (j = 0; j < 7; j++)
        {
            if (aqi[i][j] > 150 || temp[i][j] > 35 || humidity[i][j] > 80)
            {
                riskDays[i]++;
                printf("%d ", j + 1);
            }
        }

        if (riskDays[i] == 0)
            printf("No risk");

        printf("\nTotal Risk Days: %d\n", riskDays[i]);
    }
}

void computeGreenIndex(float avgTemp[5], float avgHumidity[5], float avgAQI[5], float greenIndex[5])
{
    int i;
    float a, t, h, diff;

    for (i = 0; i < 5; i++)
    {
        a = 100 - (avgAQI[i] / 5);

        if (a < 0)
            a = 0;

        if (avgTemp[i] > 25)
            diff = avgTemp[i] - 25;
        else
            diff = 25 - avgTemp[i];

        t = 100 - (4 * diff);

        if (t < 0)
            t = 0;

        if (avgHumidity[i] > 50)
            diff = avgHumidity[i] - 50;
        else
            diff = 50 - avgHumidity[i];

        h = 100 - (2 * diff);

        if (h < 0)
            h = 0;

        greenIndex[i] = (0.4 * a) + (0.3 * t) + (0.3 * h);
    }
}

void displayRanking(float greenIndex[5])
{
    int i, j, rank;

    printf("\nGREEN INDEX RANKING\n");

    for (rank = 1; rank <= 5; rank++)
    {
        for (i = 0; i < 5; i++)
        {
            int r = 1;

            for (j = 0; j < 5; j++)
            {
                if (greenIndex[j] > greenIndex[i])
                    r++;
            }

            if (r == rank)
            {
                printf("Rank %d: ", rank);
                zoneName(i);
                printf(" = %.2f\n", greenIndex[i]);
            }
        }
    }
}

void displayRecommendations(float avgTemp[5], float avgHumidity[5], float avgAQI[5], int riskDays[5])
{
    int i, found;

    printf("ENVIRONMENTAL RECOMMENDATIONS\n");

    for (i = 0; i < 5; i++)
    {
        found = 0;

        printf("\n");
        zoneName(i);
        printf("\n");

        if (avgAQI[i] > 150)
        {
            printf("- Reduce vehicle idling and improve ventilation.\n");
            found = 1;
        }

        if (avgTemp[i] > 35)
        {
            printf("- Provide shade and plant more trees.\n");
            found = 1;
        }

        if (avgHumidity[i] > 80)
        {
            printf("- Improve ventilation and check stagnant water.\n");
            found = 1;
        }

        if (found == 0 && riskDays[i] > 0)
        {
            printf("- Check the individual risk days.\n");
            found = 1;
        }

        if (found == 0)
            printf("- No major risk. Continue monitoring.\n");
    }
}

int main()
{
    float temp[5][7], humidity[5][7];
    int aqi[5][7];

    float avgTemp[5], avgHumidity[5], avgAQI[5];
    float greenIndex[5];

    int riskDays[5];
    int choice;
    int dataReady = 0;

    do
    {
        printf("\n====== CAMPUS ECO MONITOR ======\n");
        printf("1. Input / Update Data\n");
        printf("2. Display Data\n");
        printf("3. Zone-wise Averages\n");
        printf("4. Detect Risk Days\n");
        printf("5. Green Index and Ranking\n");
        printf("6. Recommendations\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                inputData(temp, humidity, aqi);
                dataReady = 1;
                break;

            case 2:
                if (dataReady == 1)
                    displayData(temp, humidity, aqi);
                else
                    printf("\nPlease enter data first!\n");
                break;

            case 3:
                if (dataReady == 1)
                    calculateAverages(temp, humidity, aqi, avgTemp, avgHumidity, avgAQI);
                else
                    printf("\nPlease enter data first!\n");
                break;

            case 4:
                if (dataReady == 1)
                    detectRiskZones(temp, humidity, aqi, riskDays);
                else
                    printf("\nPlease enter data first!\n");
                break;

            case 5:
                if (dataReady == 1)
                {
                    calculateAverages(temp, humidity, aqi, avgTemp, avgHumidity, avgAQI);
                    computeGreenIndex(avgTemp, avgHumidity, avgAQI, greenIndex);
                    displayRanking(greenIndex);
                }
                else
                    printf("\nPlease enter data first!\n");
                break;

            case 6:
                if (dataReady == 1)
                {
                    calculateAverages(temp, humidity, aqi, avgTemp, avgHumidity, avgAQI);
                    detectRiskZones(temp, humidity, aqi, riskDays);
                    displayRecommendations(avgTemp, avgHumidity, avgAQI, riskDays);
                }
                else
                    printf("\nPlease enter data first!\n");
                break;

            case 7:
                printf("\nThank you! Program ended.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}
