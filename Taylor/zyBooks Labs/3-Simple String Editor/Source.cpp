/*
Taylor Brown, Section 2, taylor@davtar.org

Test Case 1:
Input - (input-"i like testing things", make sentence-'y', add text-'n', operation-"find", substr-" things", action-"delete")
Exp. Out - ("I like texting things.", "I like testing.")
Act. Out - Resulted in saying "no change made" when one was made,
           leading to the discovery of falsely comparing std::string::npos

Test Case 2:
Input - (input-"this is a great test", make sentence-'y', add text-'y', insert-" totally", idx-7, 
         operation-"find", substr-"a great test", action-"replace", substr-"an awesome test")
Exp. Out - ("This is a great test.", "This is totally a great test.", "This is totally an awesome test.")
Act. Out - Success!

Test Case 3:
Input - (input-"THIS HAD BETTER WORK_!!!", make sentence-'y', add text-'n',
         operation-"copy", copy index-20, length-4, paste index-24)
Exp. Out - ("THIS HAD BETTER WORK_!!!", "THIS HAD BETTER WORK_!!!_!!!")
Act. Out - Success!

*/

#include <iostream>
#include <string>

// first block that gets and stores user input
void FirstInputBlock(std::string *userInput) {
   std::cout << "Welcome to the Simple Editor. Enter a string to be edited: ";
   getline(std::cin, *userInput);
   std::cout << std::endl << *userInput << std::endl << std::endl;
}

// second block that formats string into a sentence
void ReformatBlock(std::string *userInput) {
   char userChoice = '\0';
   
   std::cout << "Do you want to make this string a sentence (y/n)? " << std::endl;
   std::cin >> userChoice;
   std::cin.ignore();
   
   /*
   // error checking
   while (userChoice != 'y' && userChoice != 'n') {
      std::cout << "Please enter 'y' for yes or 'n' for no: ";
      std::cin >> userChoice;
      std::cout << std::endl;
      std::cin.ignore();
   }
   */
   
   // do the sentence reformatting
   if (userChoice == 'y') {
      (*userInput).at(0) = std::toupper((*userInput).at(0)); // capitalize first character
      
      // add "." if no other punctuation at last character
      switch ((*userInput).at((*userInput).size() - 1)) {
         default:
            *userInput += ".";
         case '.':
         case '!':
         case '?':
            break;
      }
      
      std::cout << *userInput << std::endl << std::endl;
   }
}

// third block that inserts a substring
void ExtensionInputBlock(std::string *userInput) {
   char userChoice = '\0';
   std::string userInputExt;
   int insertIdx = 0;
   
   std::cout << "Do you want to insert more text into your current text (y/n)? ";
   std::cin >> userChoice; 
   std::cout << std::endl;
   std::cin.ignore();
   
   /*
   // error checking
   while (userChoice != 'y' && userChoice != 'n') {
      std::cout << "Please enter 'y' for yes or 'n' for no: ";
      std::cin >> userChoice;
      std::cout << std::endl;
      std::cin.ignore();
   }
   */
   
   // insertion branch
   if (userChoice == 'y') {
      std::cout << "Enter text to be inserted: ";
      getline(std::cin, userInputExt);
      std::cout << "Enter position where text is to be inserted: ";
      std::cin >> insertIdx;
      std::cout << std::endl;
      std::cin.ignore();
      
      /*
      // error checking
      while (insertIdx < 0 || insertIdx > (*userInput).size()) {
         std::cout << "Error: index must be non-negative and less than the length of the current text (" 
            << (*userInput).size() << "): ";
         std::cin >> insertIdx;
         std::cout << std::endl;
         std::cin.ignore();
      }
      */
      if (insertIdx < 0 || insertIdx > (*userInput).size()) {
         std::cout << "No change made. Position must be non-negative and not exceed "
            << (*userInput).size() << ", the length of the current text.";
      }
      else {
         (*userInput).insert(insertIdx, userInputExt);
         std::cout << *userInput << std::endl << std::endl;
      }
   }
}

void FindOrCopyBlock(std::string *userInput) {
   std::string userChoice;
   
   // used for 'find'
   std::string userSubStr; // substring used for multiple potential operations
   int userSubStrIdx = 0; // location of substring
   std::string endMessage; // temporary variable
   std::string userReplacement; // user entered replacement text
   
   // used for 'copy'
   int copyLength = 0; // length to copy
   int copyIdx = 0; // copy from index
   int pasteIdx = 0; // paste to index
   std::string copiedSubStr;
   
   std::cout << "If you would like to find/replace or copy/paste, enter find or copy: ";
   std::cin >> userChoice;
   std::cout << std::endl;
   std::cin.ignore();
   
   /*
   // error checking
   while (userChoice != "find" && userChoice != "copy") {
      std::cout << "Please enter either 'find' or 'copy': ";
      std::cin >> userChoice;
      std::cout << std::endl;
      std::cin.ignore();
   }
   */
   
   // find substring logic
   if (userChoice == "find") {
      std::cout << "Enter substring to find: ";
      getline(std::cin, userSubStr);
      std::cout << "Do you want to find if/where the substring occurs, delete it, or replace it (find, delete, replace)? ";
      std::cin >> userChoice;
      std::cout << std::endl;
      std::cin.ignore();
      
      // find the index where the substring starts
      userSubStrIdx = (*userInput).find(userSubStr);
      
      /*
      I thought that the part about using "only 1 if statement" applied to the entirety of part 4, but I now
      realize that it was just on the error checking part. This is why the switch statement with the weird
      character checking is here (as well as the conditional assigning of endMessage).
      */
      // process user selection
      switch (userChoice.at(0)) {
         case 'f': // find
            endMessage = userSubStr + " ";
            endMessage += (userSubStrIdx != std::string::npos) ?
               " was found at position " + std::to_string(userSubStrIdx) + "." : " was not found.";
            std::cout << endMessage << std::endl;
            break;
            
         case 'd': // delete (This is when I realized I could use multiple ifs)
            if (userSubStrIdx != std::string::npos) { // match made
               (*userInput).replace(userSubStrIdx, userSubStr.size(), "");
            }
            else { // no match
               std::cout << userSubStr << " was not found. No change made." << std::endl;
            }
            break;
            
         case 'r': // replace
            if (userSubStrIdx != std::string::npos) { // match made
               std::cout << "Enter replacement string: ";
               getline(std::cin, userReplacement);
               
               (*userInput).replace(userSubStrIdx, userSubStr.size(), userReplacement);
            }
            else { // no match
               std::cout << userSubStr << " was not found. No change made." << std::endl;
            }
      }
   }
   
   // copy substring logic
   else {
      std::cout << "Enter position and length of text to be copied, and position for paste: ";
      std::cin >> copyIdx >> copyLength >> pasteIdx;
      std::cout << std::endl;
      std::cin.ignore();
      
      /*
      // error checking
      while (copyIdx < 0 || copyLength < 0 || copyIdx + copyLength > (*userInput).size() ||
             pasteIdx > (*userInput).size()) {
         std::cout << "Values entered do not support copy/paste." << std::endl;
         std::cout << "Please re-enter (start position, length, paste position): ";
         std::cin >> copyIdx >> copyLength >> pasteIdx;
         std::cout << std::endl;
         std::cin.ignore();
      }
      */
      
      if (copyIdx < 0 || copyLength < 0 || copyIdx + copyLength > (*userInput).size() ||
         pasteIdx > (*userInput).size()) {
            std::cout << "Values entered do not support copy/paste." << std::endl;
         }
         
      else {
         copiedSubStr = (*userInput).substr(copyIdx, copyLength);
         (*userInput).insert(pasteIdx, copiedSubStr);
      }
   }
}

// the end result after all changes are made
void FinalPrintBlock(std::string userInput) {
   std::cout << "Final text is" << std::endl;
   std::cout << userInput << std::endl;
}

// structured to call multiple functions for separation of functionality
int main() {
   std::string userInput;
   
   // stores the beginning string in userInput
   FirstInputBlock(&userInput);
   
   // optional block to format into sentence
   ReformatBlock(&userInput);
   
   // optional extension block
   ExtensionInputBlock(&userInput);
   
   // find/replace block
   FindOrCopyBlock(&userInput);
   
   // final printing of userInput
   FinalPrintBlock(userInput);
   
   return 0;
}