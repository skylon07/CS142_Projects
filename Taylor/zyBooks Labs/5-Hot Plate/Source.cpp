// Taylor Brown
// Section 2
// taylor@dvtar.org

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdarg.h>


// PROGRAM SETTINGS

// printing constants
const int WIDTH = 9;
const int PRECISION = 3;

// hotplate dimension constant
const int PLATE_ROWS = 10;
const int PLATE_COLS = 10;

// hotplate stability constant
const double MIN_STABLE_VAL = 0.1;

// hotplate file names
const std::string OUT_FILE = "Hotplate.csv";
const std::string IN_FILE = "Inputplate.txt";


// copies one 2D arrays elements into another
void CopyPlate(double srcPlate[PLATE_ROWS][PLATE_COLS],
               double destPlate[PLATE_ROWS][PLATE_COLS]) {
    // iterate over arrays in plate
    for(int i = 0; i < PLATE_ROWS; ++i) {
        for (int j = 0; j < PLATE_COLS; ++j) {
            // assign the value
            destPlate[i][j] = srcPlate[i][j];
        }
    }
}


// outputs a plate to a given out stream
    // MUST HAVE & after ostream type: pass stream by reference in order to operate on it
void OutputPlate(double plate[PLATE_ROWS][PLATE_COLS], std::ostream& outStream) {
    // set up correct cout parameters
    outStream << std::setprecision(PRECISION) << std::fixed << std::right;

    int row = 0;
    int col = 0;
    // iterate over each row
    for (row = 0; row < PLATE_ROWS; ++row) {
        // iterate over each collumn (except last)
        for (col = 0; col < (PLATE_COLS - 1); ++col) {
            // print value
            outStream << std::setw(WIDTH) << plate[row][col] << ",";
        }
        // print last value, end with newline
        outStream << std::setw(WIDTH) << plate[row][col] << std::endl;
    }
}

// inputs from a stream into a plate
void InputPlate (std::istream& inStream, double plate[PLATE_ROWS][PLATE_COLS]) {
    // iterate over every element
    for (int row = 0; row < PLATE_ROWS; ++row) {
        for (int col = 0; col < PLATE_COLS; ++col) {
            inStream >> plate[row][col];
        }
    }
}


// returns absolute value
template <typename anyType>
anyType abs(anyType var) {
    // if var is negative, switch it
    if (var < 0) {
        var *= -1;
    }
    return var;
}


// detects the maximum change between two elements compared from two 1D arrays
double PlateMaxDiff(double plate1Row[PLATE_COLS], double plate2Row[PLATE_COLS]) {
    double maxValue = plate1Row[0] - plate2Row[0];
    
    // iterate through to find the max
    for (int col = 0; col < PLATE_COLS; ++col) {
        // update max if value is higher in difference
        if (abs(plate1Row[col] - plate2Row[col]) > abs(maxValue)) {
            maxValue = plate1Row[col] - plate2Row[col];
        }
    }

    return maxValue;
}

// detects maximum change over two 2D arrays
double PlateMaxDiff2D(double plate1[PLATE_ROWS][PLATE_COLS],
                       double plate2[PLATE_ROWS][PLATE_COLS]) {
    double maxValue = plate1[0][0] - plate2[0][0];

    // iterate through and find max with 1D function
    for (int row = 0; row < PLATE_ROWS; ++row) {
        // if resulting max is greater than current max, update current max
        double resultMax = PlateMaxDiff((plate1)[row], plate2[row]);
        if (abs(resultMax) > abs(maxValue)) {
            maxValue = resultMax;
        }
    }

    return maxValue;
}


// returns mean of double values
double mean(int numItems, ...) {
    va_list inputNumbers; // numbers passed through function
    va_start(inputNumbers, numItems);

    double sum = 0;
    for (int i = 0; i < numItems; ++i) {
        double temp = va_arg(inputNumbers, double);
        sum += temp;
    }

    return (sum / numItems);
}

// returns average value of neighboring elements given coordinates
double AvgNeighbors(double plate[PLATE_ROWS][PLATE_COLS], int row, int col) {
    // initialize adjacent values
    double up = plate[row-1][col];
    double left = plate[row][col-1];
    double down = plate[row+1][col];
    double right = plate[row][col+1];

    // calculate and return mean of these values
    return mean(4, up, left, down, right);
}

// iterate through a simulation cycle (must pass the hotplate arrays in)
void IterHeatSim(double plate[PLATE_ROWS][PLATE_COLS]) {
    // set a temporary plate to record the state of the current plate
    double plateOld[PLATE_ROWS][PLATE_COLS];
    CopyPlate(plate, plateOld);

    // set each non-edge element to the average of its neighbors initial values
    for (int row = 1; row < (PLATE_ROWS - 1); ++row) {
        for (int col = 1; col < (PLATE_COLS - 1); ++col) {
            // set element to average of temporary plate state
            plate[row][col] = AvgNeighbors(plateOld, row, col);
        }
    }
}

// returns whether the next plate is stable or not
bool IsNextPlateStable (double plate[PLATE_ROWS][PLATE_COLS]) {
    // initialize before and after plates
    double plateAfter[PLATE_ROWS][PLATE_COLS]; // created to not affect current values of plate
    CopyPlate(plate, plateAfter);

    // test if the plate is stable by testing difference in after
    IterHeatSim(plateAfter);

    // return if plate is stable or not
    return (abs(PlateMaxDiff2D(plateAfter, plate)) < MIN_STABLE_VAL);
}


int main() {
    // initialize hotplate board
    double hotplateVals[PLATE_ROWS][PLATE_COLS];

    // populate hotplateVals, given 100 top/bottom, 0 everywhere else
    // populate all items to zero
    for (int row = 0; row < PLATE_ROWS; ++row) {
        for (int col = 0; col < PLATE_COLS; ++col) {
            hotplateVals[row][col] = 0.0;
        }
    }
    // populate top/bottom rows with 100 (no corners)
    for (int col = 1; col < (PLATE_COLS - 1); ++col) {
        hotplateVals[0][col] = 100.0;
        hotplateVals[PLATE_ROWS-1][col] = 100.0;
    }

    std::cout << "Hotplate simulator" << std::endl;
    std::cout << std::endl;


    std::cout << "Printing initial plate..." << std::endl;

    // print initial plate
    OutputPlate(hotplateVals, std::cout);
    std::cout << std::endl;


    std::cout << "Printing plate after one iteration..." << std::endl;

    // iterate plate once
    IterHeatSim(hotplateVals);

    // print plate
    OutputPlate(hotplateVals, std::cout);
    std::cout << std::endl;


    std::cout << "Printing final plate..." << std::endl;

    // while plate isnt stable
    while (!IsNextPlateStable(hotplateVals)) {
        // iterate through next simulation
        IterHeatSim(hotplateVals);
    }
    IterHeatSim(hotplateVals); // set hotplateVals once more to be stable

    // print final plate
    OutputPlate(hotplateVals, std::cout);
    std::cout << std::endl;


    // initialize file stream
    std::ofstream outFile;
    outFile.open(OUT_FILE);

    // output plate into the file
    OutputPlate(hotplateVals, outFile);

    // close file
    outFile.close();


    // initialize input stream
    std::ifstream inFile;
    inFile.open(IN_FILE);

    // read input file
    InputPlate(inFile, hotplateVals);

    // iterate simulation 3 times
    for (int i = 0; i < 3; ++i) {
        IterHeatSim(hotplateVals);
    }

    // print plate values
    OutputPlate(hotplateVals, std::cout);

    return 0;
}
