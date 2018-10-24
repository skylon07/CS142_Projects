// Problems: GetNumOfWords function
// while loop printing input prompt too often

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int GetNumOfNonWSCharacters(string inputStr) {
   int num = count(inputStr.begin(), inputStr.end(), ' ');
   int numNonWs = inputStr.size() - num;
   return numNonWs;
}

int GetNumOfWords(string inputStr){
   int numspace = 0;
   for (int i=0; i<int(inputStr.length()); i++){  
      char nextChar = inputStr.at(i); // gets a character
		if (isalpha(inputStr[i-1]) && isspace(inputStr[i])){
			 numspace++;
		}
		
		else if ((inputStr[i+1]) && isspace(inputStr[i])){
		   numspace++;
		}
	}
   return (numspace - 5);
   }

int FindText(string inputStr, string searchText) {
    int numWords = 0;
    stringstream stack(inputStr);
    string word;

    while (stack >> word) {
        if (word == searchText) {
            numWords++;
        }
    }
    return numWords;
}

void  ShortenSpace(string inputStr){
   bool prev(false);
   char rem(' ');
   auto iter = remove_if(inputStr.begin(), inputStr.end(), [&] (char c) -> bool {
      if (c == rem && prev) {
         return true;
      }
      prev = (c == rem);
    return false;
   });
   inputStr.erase(iter, inputStr.end()); 
}

void ReplaceExclamation(string inputStr){
   bool isTrue = true;
   while( isTrue = true ){
      if (inputStr.find ('.') != string::npos){
         inputStr.replace(inputStr.find("."), 1 , "!");
      }
      
      else if (inputStr.find ('.') == string :: npos){ 
         isTrue = false;
   }
}
}
   
char PrintMenu(string inputStr){
char option = ' ';
string searchText = " " ;

cout << "Enter a sample text: ";
   getline(cin,inputStr);
   cout << endl;
   cout << "You entered: " << inputStr << endl;

while ( option != 'q') {
   
   switch(option){
      case 'c':
         cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(inputStr) << endl;
         break;

      case 'w':
         cout << "Number of words: " << GetNumOfWords(inputStr) << endl;
      break;
    
      case 'f':
         cout << "Enter a word or phrase to be found:" << endl;
         cin.ignore();
         getline(cin, searchText);
         cout << " \"" << searchText << "\" instances: " << FindText(inputStr, searchText);
      break;
      
      case 'r':
        ReplaceExclamation(inputStr);
         cout << "Edited text: " << inputStr << endl;
        break;
      
      case 's':
        ShortenSpace(inputStr);
         cout << "Edited text: " << inputStr;
        break;
      
      case 'q':
         break; 
   }
    cout << "MENU" << endl;
   cout <<  "c - Number of non-whitespace characters" << endl;
   cout << "w - Number of words" << endl;
   cout << "f - Find text" << endl;
   cout << "r - Replace all !'s" << endl;
   cout << "s - Shorten spaces" << endl;
   cout << "q - Quit" << endl;
   cout << endl;
   cout << "Choose an option: " << endl;
   cin.get(option);
}
}

int main() {
string inputStr;
char option;

      PrintMenu(inputStr);

   return 0;
}