# CODE2THINK – CHALLENGE 10
## Campus Eco Monitor

### About the Project
The Campus Eco Monitor is a menu-driven C program that analyses environmental conditions in five university campus zones over seven days.

It records temperature, humidity and Air Quality Index (AQI) readings and uses them to calculate averages, detect risk days, calculate the Green Index and provide environmental recommendations.

### Campus Zones
1. Academic Block
2. Hostel
3. Library
4. Cafeteria
5. Sports Area

### Features
- Stores seven days of environmental readings.
- Uses three separate 2D arrays for temperature, humidity and AQI.
- Checks whether entered readings are within the valid range.
- Displays all three data matrices.
- Calculates average temperature, humidity and AQI for each zone.
- Detects risk days based on the given conditions.
- Calculates the Green Index for all five zones.
- Displays zone rankings, including tied ranks.
- Gives recommendations for environmental improvement.
- Uses a menu to perform different operations.

### Algorithm

1. Start the program.
2. Declare three 2D arrays for temperature, humidity and AQI.
3. Display the menu with seven options.
4. Ask the user to enter their choice.
5. If the user selects Input Data, enter readings for all five zones for seven days.
6. Check every reading and ask again if it is outside the allowed range.
7. If Display Data is selected, display all three matrices.
8. If Zone-wise Averages is selected, calculate and display the average temperature, humidity and AQI.
9. If Detect Risk Days is selected, check whether AQI is above 150, temperature is above 35°C or humidity is above 80%. Count each risk day only once.
10. If Green Index and Ranking is selected, calculate the three scores, find the Green Index and display the zones from highest to lowest rank. Give equal ranks to zones with equal scores.
11. If Recommendations is selected, display suitable suggestions based on the average readings and risk days.
12. If Exit is selected, stop the program.
13. Repeat the menu until the user chooses Exit.

### Functions Used

| Function | Purpose |
|---|---|
| `inputData()` | Reads and validates readings. |
| `displayData()` | Displays the three matrices. |
| `calculateAverages()` | Calculates zone-wise averages. |
| `detectRiskZones()` | Finds and counts risk days. |
| `computeGreenIndex()` | Calculates the Green Index. |
| `displayRanking()` | Displays the ranking of zones. |
| `displayRecommendations()` | Gives environmental suggestions. |

### Green Index Formula

AQI Score = 100 - (Average AQI / 5)

Temperature Score = 100 - (4 × Absolute Difference from 25)

Humidity Score = 100 - (2 × Absolute Difference from 50)

Green Index = (0.4 × AQI Score) + (0.3 × Temperature Score) + (0.3 × Humidity Score)

Negative component scores are treated as zero.

### Technologies Used
- Programming Language: C
- Compiler: GCC
- Concepts: 2D Arrays, Loops, Functions, If-Else, Switch Case and Menu-Driven Programming.

### How to Run

Save the program as `eco.c`.

Compile using:

```bash
gcc eco.c -o eco
```

Run using:

```bash
./eco
```

### Testing
The program was tested using different readings to check:
- Normal environmental readings.
- AQI risk conditions.
- Temperature and humidity risk conditions.
- Multiple risk conditions on the same day.
- No risk days.
- Negative Green Index component scores.
- Tied Green Index rankings.
- Invalid input values.

### What I Learned

Through this challenge, I learned how to use 2D arrays to store environmental data. I understood how to create and call user-defined functions in C. I also learned to calculate averages and check different conditions using loops and if-else statements. I understood how to calculate the Green Index and rank different zones. This challenge helped me improve my logical thinking and problem-solving skills.

### Note
Any sample readings used for testing are simulated data and are not actual campus measurements.

---
**Project:** CODE2THINK – Challenge 10  
**Name:** Rohan Thapliyal
**Language:** C
