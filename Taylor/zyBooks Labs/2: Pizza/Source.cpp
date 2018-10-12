/*
Taylor Brown, Section 2, taylor@davtar.org

Test case 1: test large pizza division
Input - (14 people)
Exp. Out - (2 large, 0 med, 0 small, ...)
Act. Out - Same as expected

Test case 2: test all pizza division
Input - (25 people)
Exp. Out - (3 large, 1 med, 1 small, ...)
Act. Out - Same as expected

Test case 3: test pizza division and area calc
Input - (40 people)
Exp. Out - (5 large, 1 med, 2 small, 1,998.0529254 in2, 49.951323135 in2/guest, ...)
Act. Out - (..., 618.319 in2, 15.708 in2/guest, ...)
Solution: Forgot to multiply by number of pizzas of each size

Test case 4: test all features
Input - (100 people, 10 tip)
Exp. Out - (14 large, 0 med, 2 small, 4624.4243808 in2, 46.244243808 in2/guest, $242 price)
Act. Out - Same as expected

Test case 5: test all features
Input - (354 people, 15 tip)
Exp Out - (50 large, 1 med, 1 small, 16,022.122515 in2, 45.260233093 in2/guest, $866 price)
*/

#include <iostream>
#include <cmath>

int main() {
   int numGuests = 0;
   int numLargePizzas = 0;
   int numMedPizzas = 0;
   int numSmallPizzas = 0;
   const int NUM_FED_LARGE = 7;
   const int NUM_FED_MED = 3;
   const int NUM_FED_SMALL = 1;
   const int DIAM_LARGE_PIZZA = 20;
   const int DIAM_MED_PIZZA = 16;
   const int DIAM_SMALL_PIZZA = 12;
   const double PRICE_LARGE_PIZZA = 14.68;
   const double PRICE_MED_PIZZA = 11.48;
   const double PRICE_SMALL_PIZZA = 7.28;
   const double PI = 3.14159265;
   double totalArea = 0.0;
   int tipPercent = 0;
   double totalCost = 0.0;
   
   // Gather numGuest input
   std::cout << "Please enter the number of guests: ";
   std::cin >> numGuests;
   std::cout << std::endl; // Only exists to mimic "Enter" press that zyBooks misses
   
   // Calculate number of pizzas
   int numGuestsTemp = numGuests; // used to reset value later
   numLargePizzas = numGuests / NUM_FED_LARGE;
   numGuests %= NUM_FED_LARGE;
   numMedPizzas = numGuests / NUM_FED_MED;
   numGuests %= NUM_FED_MED;
   numSmallPizzas = numGuests / NUM_FED_SMALL;
   numGuests = numGuestsTemp; // reset value of numGuests
   
   // Output number of each pizza size
   std::cout << numLargePizzas << " large pizzas, " << numMedPizzas << " medium pizzas, and " 
      << numSmallPizzas << " small pizzas will be needed." << std::endl << std::endl;
      
   // Calculate total area
   totalArea += numLargePizzas * PI * (DIAM_LARGE_PIZZA * DIAM_LARGE_PIZZA) / 4.0;
   // ~ / 4.0 works because r = d / 2, (d / 2) ^ 2 = (d ^ 2) / 4
   totalArea += numMedPizzas * PI * (DIAM_MED_PIZZA * DIAM_MED_PIZZA) / 4.0;
   totalArea += numSmallPizzas * PI * (DIAM_SMALL_PIZZA * DIAM_SMALL_PIZZA) / 4.0;
      
   // Output number of square inches
   std::cout << "A total of " << totalArea << " square inches of pizza will be purchased (" 
      << totalArea / numGuests << " per guest)." << std::endl << std::endl;
      
   // Get input for tip percentage
   std::cout << "Please enter the tip as a percentage (i.e. 10 means 10%): ";
   std::cin >> tipPercent;
   std::cout << std::endl;
   
   // Calculate total cost, ie all pizzas + tip
   totalCost += numLargePizzas * PRICE_LARGE_PIZZA;
   totalCost += numMedPizzas * PRICE_MED_PIZZA;
   totalCost += numSmallPizzas * PRICE_SMALL_PIZZA;
   totalCost *= 1 + (tipPercent / 100.0); // "1 +" because you multiply by 100% + tip%
   totalCost = round(totalCost);
   
   // Output total cost
   std::cout << "The total cost of the event will be: $" << totalCost << std::endl;
   
   return 0;
}