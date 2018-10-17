#include <iostream>
#include <array>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {

   const int TEN_SQUARE = 10;
   int i = 0; //rows
   int j = 0; //columns
   ifstream inputFile;

   
   double hotPlate[TEN_SQUARE][TEN_SQUARE];
   
   cout << "Hotplate simulator" << endl;
   cout << endl;
   cout << "Printing initial plate..." << endl;
   
   for (i = 0; i < TEN_SQUARE; i++) {
      for (j = 0; j < TEN_SQUARE; j++) {
            if (i == 0 && j > 0 && j < 9){
               hotPlate[i][j] = 100.000;
               cout << fixed <<  setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }            
             if (i == 9 && j > 0 && j < 9){
               hotPlate[i][j] = 100.000;
               cout << fixed <<  setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }
         
           //corners
            if ( i == 0 && j == 0) {
               hotPlate[i][j] = 0.000;
               cout << fixed << setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }
            if ( i == 9 && j == 0){
               hotPlate[i][j] = 0.000;
               cout << fixed << setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }
            if ( i == 0 && j == 9){
               hotPlate[i][j] = 0.000;
               cout << fixed << setprecision(3) << setw(9) << hotPlate[i][j];
            }
            if ( i == 9 && j == 9){
               hotPlate[i][j] = 0.000;
               cout << fixed << setprecision(3) << setw(9) << hotPlate[i][j];
            }
            if ( j == 9 && i > 0 && i < 9) {
               hotPlate[i][j] = 0.000;
               cout << fixed <<  setprecision(3) << setw(9) << hotPlate[i][j];
            }
             if ( j == 0 && i > 0 && i < 9) {
               hotPlate[i][j] = 0.000;
               cout << fixed <<  setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }
            
            if (i > 0 && j > 0 && i < 9 && j < 9) {
               hotPlate[i][j] = 0.000;
               cout << fixed <<  setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }
          
       }
      cout << endl;
   }
   
cout << "Printing plate after one iteration..." << endl;
   
   for (i = 0; i < TEN_SQUARE; i++) {
      for (j = 0; j < TEN_SQUARE; j++) {
            if (i == 0 && j > 0 && j < 9){
               hotPlate[i][j] = 100.000;
               cout << fixed <<  setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }            
             if (i == 9 && j > 0 && j < 9){
               hotPlate[i][j] = 100.000;
               cout << fixed <<  setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }
         
           //corners
            if ( i == 0 && j == 0) {
               hotPlate[i][j] = 0.000;
               cout << fixed << setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }
            if ( i == 9 && j == 0){
               hotPlate[i][j] = 0.000;
               cout << fixed << setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }
            if ( i == 0 && j == 9){
               hotPlate[i][j] = 0.000;
               cout << fixed << setprecision(3) << setw(9) << hotPlate[i][j];
            }
            if ( i == 9 && j == 9){
               hotPlate[i][j] = 0.000;
               cout << fixed << setprecision(3) << setw(9) << hotPlate[i][j];
            }
            if ( j == 9 && i > 0 && i < 9) {
               hotPlate[i][j] = 0.000;
               cout << fixed <<  setprecision(3) << setw(9) << hotPlate[i][j];
            }
            if ( j == 0 && i > 0 && i < 9) {
               hotPlate[i][j] = 0.000;
               cout << fixed <<  setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }
            if (i == 1 && j > 0 && j < 9) {
               hotPlate[i][j] = (hotPlate[i-1][j] + hotPlate[0][0] + hotPlate[1][0])/4 ;
               cout << fixed <<  setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }
            if (i == 8 && j > 0 && j < 9) {
               hotPlate[i][j] = hotPlate[i][0] + hotPlate[i+1][0] + hotPlate[i+1][1]/4;
               cout << fixed <<  setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }  
            if (i > 1 && i < 8 && j > 0 && j < 9) {
               hotPlate[i][j] = 0.000;
               cout << fixed <<  setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }
       }
      cout << endl;
   }

cout << "Printing final plate..." << endl;
   
   for (i = 0; i < TEN_SQUARE; i++) {
      for (j = 0; j < TEN_SQUARE; j++) {
            if (i == 0 && j > 0 && j < 9){
               hotPlate[i][j] = 100.000;
               cout << fixed <<  setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }            
             if (i == 9 && j > 0 && j < 9){
               hotPlate[i][j] = 100.000;
               cout << fixed <<  setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }
         
           //corners
            if ( i == 0 && j == 0) {
               hotPlate[i][j] = 0.000;
               cout << fixed << setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }
            if ( i == 9 && j == 0){
               hotPlate[i][j] = 0.000;
               cout << fixed << setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }
            if ( i == 0 && j == 9){
               hotPlate[i][j] = 0.000;
               cout << fixed << setprecision(3) << setw(9) << hotPlate[i][j];
            }
            if ( i == 9 && j == 9){
               hotPlate[i][j] = 0.000;
               cout << fixed << setprecision(3) << setw(9) << hotPlate[i][j];
            }
            if ( j == 9 && i > 0 && i < 9) {
               hotPlate[i][j] = 0.000;
               cout << fixed <<  setprecision(3) << setw(9) << hotPlate[i][j];
            }
            if ( j == 0 && i > 0 && i < 9) {
               hotPlate[i][j] = 0.000;
               cout << fixed <<  setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }
            if (i > 0 && i < 9 && j > 0 && j < 9) {
               hotPlate[i][j] = (hotPlate[i-1][j] + hotPlate[i][j+1] + hotPlate[i+1][j] + hotPlate[i][j-1])/4 ;   //[0][3] + array[1][4] + array[2][3] + array[1][2])/4
               cout << fixed <<  setprecision(3) << setw(9) << hotPlate[i][j] << ",";
            }
       }
      cout << endl;
   }
  
   
   
   
  
  return 0;
}