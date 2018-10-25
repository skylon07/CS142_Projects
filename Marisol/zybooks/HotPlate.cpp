// Marisol Mattson
// Section 2
// marisolrm2000@gmail.com

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdarg.h>

using namespace std;

// Constants
const int WIDTH = 9;
const int PRECISION = 3;

const int P_ROWS = 10;
const int P_COLS = 10;

const double M_S_V = 0.1; //MINUM STABLE VALUE

// File names
const string OUT_FILE = "Hotplate.csv";
const string IN_FILE = "Inputplate.txt";

// copies one 2D arrays elements into another
    void CopyPlate(double srcPlate[P_ROWS][P_COLS],
                   double destPlate[P_ROWS][P_COLS]) {
        for(int i = 0; i < P_ROWS; ++i) {
            for (int j = 0; j < P_COLS; ++j) {
                destPlate[i][j] = srcPlate[i][j];
            }
        }
    }


// outputs a plate to a given out stream
    void OutPlate(double plate[P_ROWS][P_COLS], ostream& outStream) {
        outStream << setprecision(PRECISION) << fixed << right;
        int row = 0;
        int col = 0;

        for (row = 0; row < P_ROWS; ++row) {
            for (col = 0; col < (P_COLS - 1); ++col) {
                outStream << setw(WIDTH) << plate[row][col] << ",";
            }
            outStream << setw(WIDTH) << plate[row][col] << endl;
        }
    }

//inputs stream into a plate
    void InputPlate (istream& inStream, double plate[P_ROWS][P_COLS]) {
        for (int row = 0; row < P_ROWS; ++row) {
            for (int col = 0; col < P_COLS; ++col) {
                inStream >> plate[row][col];
            }
        }
    }

//absolute value
    template <typename anyType>
    anyType abs(anyType var) {
        if (var < 0) {
            var *= -1;
       }
    return var;
    }

//maximum change between two elements from two 1D arrays
    double  maxDif(double plate1Row[P_COLS], double plate2Row[P_COLS]) {
        double maxValue = plate1Row[0] - plate2Row[0];
        for (int col = 0; col < P_COLS; ++col) {
            if (abs(plate1Row[col] - plate2Row[col]) > abs(maxValue)) {
                maxValue = plate1Row[col] - plate2Row[col];
            }
        }
    return maxValue;
    }

// detects maximum change over two 2D arrays
    double  maxDif2D(double plate1[P_ROWS][P_COLS],
    
    double plate2[P_ROWS][P_COLS]) {
    double maxValue = plate1[0][0] - plate2[0][0];
    for (int row = 0; row < P_ROWS; ++row) {
        double resultMax =  maxDif((plate1)[row], plate2[row]);
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

// returns average value of near elements given coordinates
    double AvgNear(double plate[P_ROWS][P_COLS], int row, int col) {
        double top = plate[row-1][col];
        double front = plate[row][col-1];
        double bottom = plate[row+1][col];
        double back = plate[row][col+1];

        return mean(4, top, front, bottom, back);
    }

//simulation cycle
    void cycHeatInter(double plate[P_ROWS][P_COLS]) {
        double plateOld[P_ROWS][P_COLS];
        CopyPlate(plate, plateOld);

        for (int row = 1; row < (P_ROWS - 1); ++row) {
            for (int col = 1; col < (P_COLS - 1); ++col) {
                plate[row][col] = AvgNear(plateOld, row, col);
            }
        }
    }

// returns whether the next plate is stable or not
    bool plateIsStable (double plate[P_ROWS][P_COLS]) {
        double plateAfter[P_ROWS][P_COLS];
        CopyPlate(plate, plateAfter);
        cycHeatInter(plateAfter);
        return (abs( maxDif2D(plateAfter, plate)) < M_S_V);
    }

int main() {
// initialize hotplate
    double hotplateVals[P_ROWS][P_COLS];
    for (int row = 0; row < P_ROWS; ++row) {
        for (int col = 0; col < P_COLS; ++col) {
            hotplateVals[row][col] = 0.0;
        }
    }
    for (int col = 1; col < (P_COLS - 1); ++col) {
        hotplateVals[0][col] = 100.0;
        hotplateVals[P_ROWS-1][col] = 100.0;
    }
//Beginning of Output
    cout << "Hotplate simulator" << endl;
    cout << endl;

//Initial Plate
    cout << "Printing initial plate..." << endl;
    OutPlate(hotplateVals, cout);
    cout << endl;

// One Iteration
    cout << "Printing plate after one iteration..." << endl;
    cycHeatInter(hotplateVals);

    OutPlate(hotplateVals, cout);
    cout << endl;

//Final Plate
    cout << "Printing final plate..." << endl;
        while (!plateIsStable(hotplateVals)) {
            cycHeatInter(hotplateVals);
            }
        cycHeatInter(hotplateVals);

        OutPlate(hotplateVals, cout);
        cout << endl;

        ofstream out;
        out.open(OUT_FILE);

        OutPlate(hotplateVals, out);
        out.close();

        ifstream inFile;
        inFile.open(IN_FILE);

        InputPlate(inFile, hotplateVals);

        for (int i = 0; i < 3; ++i) {
            cycHeatInter(hotplateVals);
        }
        OutPlate(hotplateVals, cout);

    return 0;
}
