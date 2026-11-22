# WATERWISE – Campus Water Consumption Monitor

## About the Project
WATERWISE is a C programming project that monitors and analyses water consumption across five campus zones for seven days. It helps identify over-limit usage, sudden increases in consumption, and zones that need more attention.

The program uses simulated water usage data for testing and analysis. These readings are not actual campus measurements.

## Zones
- Academic Block
- Hostel
- Library
- Cafeteria
- Sports Complex

## Features
- Stores water usage for 5 zones over 7 days using a 2D array.
- Accepts and validates daily water targets and consumption readings.
- Displays the water consumption matrix.
- Calculates weekly total, daily average, peak usage, and peak day.
- Detects over-limit days and calculates excess water usage.
- Identifies sudden spikes when usage increases by more than 40% compared to the previous day.
- Counts unique alert days.
- Ranks zones based on total excess water usage.
- Displays water conservation recommendations.

## Concepts Used
- C programming
- 2D arrays
- Pointers and pointer arithmetic
- User-defined functions
- Loops and conditional statements
- Input validation
- Basic calculations

## How to Compile and Run

Compile the program:

```bash
gcc waterwise.c -o waterwise
```

Run it:

```bash
./waterwise
```

## Menu Options
1. Display Water Data
2. Generate Audit Report
3. Rank Zones
4. Conservation Actions
5. Exit

## Testing
The program was tested using different simulated datasets for:

- Normal water usage
- Over-limit readings
- Sudden spikes
- Exactly 40% increase
- Over-limit and spike on the same day
- Tied zone rankings
- No-alert conditions
- Invalid input values

## Water Conservation Action
The Library zone was selected for the water conservation action note. The proposed action is to check taps and washbasins for leakage and encourage students to avoid unnecessary water usage.

The impact can be measured by recording daily water usage for seven days and comparing it with the baseline consumption.

## What I Learned
This project helped me understand pointer arithmetic, 2D arrays, function-based programming, input validation, and how to analyse data using C. I also learned how to use pointers to traverse arrays and how to identify usage patterns through calculations.

---

**Challenge:** CODE2THINK – Challenge 11  
**Project:** WATERWISE
