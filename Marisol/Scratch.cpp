//Libraries 
    #include <iostream>
    #include <string>
    #include <cctype>
    #include <cstdlib>
    #include <chrono> 
    #include <vector>

using namespace std;

    //Functions
        int ranint (int low, int high) {
            int randval = rand(); 
            int range = high - low + 1 ; // plus one makes it enclusive of high
            randval = randval % range;
            return randval + low; 

        }



int main () {

    //Varibles and What not
        bool programRunning = true;
        const int numTruth = 5;
        const int numDare = 4;
        int numPlayers = 0;
        int randPlayer;
        int randTruth;
        int randDare;
        int x = 0;
        string playerOne;
        string playerTwo;
        string playerThree;
        string playerFour;
        string playerFive;
        string playerSix;
        string playerInput;
        string playerTruth;
      
        
        
        srand (time (0));
    // Main Loop
    
    //Vectors
        vector <string> ranPlayer;
        vector <string> ranTruth;
        vector <string> ranDare;

    // Welcome and gathering number of players
        cout << "Welcome to Truth or Dare" << endl;
       while (programRunning)
       { cout << "Please enter the number of Players (3 to 6 players needed)" << endl;
        cin  >> numPlayers;

        if (numPlayers < 3 || numPlayers > 6){
            cout << "Incorrect Number of Players"<< endl;
        }

        else {
        cout << "Input Players names" << endl;
    // Getting players names
        switch(numPlayers) {
            case 3:
                cout << "Enter player 1"<< endl;
                cin.ignore();
                getline (cin, playerOne);

                cout << "Enter player 2"<< endl;
                getline (cin, playerTwo);

                cout << "Enter player 3"<< endl;
                getline (cin, playerThree);
            break;

            case 4:
                cout << "Enter player 1"<< endl;
                cin.ignore();
                getline (cin, playerOne);

                cout << "Enter player 2"<< endl;
                getline (cin, playerTwo);
                
                cout << "Enter player 3"<< endl;
                getline (cin, playerThree);

                cout << "Enter Player 4"<< endl;
                getline(cin, playerFour);

            break;

            case 5:

                cout << "Enter player 1"<< endl;
                cin.ignore();
                getline (cin, playerOne);

                cout << "Enter player 2"<< endl;
                getline (cin, playerTwo);

                cout << "Enter player 3"<< endl;                
                getline (cin, playerThree);

                cout << "Enter Player 4" << endl;
                getline(cin, playerFour);

                cout << "Enter Player 5" << endl;
                getline(cin, playerFive);

            break;

            case 6: 
                cout << "Enter player 1"<< endl;
                cin.ignore();
                getline (cin, playerOne);

                cout << "Enter player 2"<< endl;
                getline (cin, playerTwo);

                cout << "Enter player 3"<< endl;                
                getline (cin, playerThree);

                cout << "Enter Player 4" << endl;
                getline(cin, playerFour);

                cout << "Enter Player 5" << endl;
                getline(cin, playerFive);

                cout << "Enter Player 6" << endl;
                getline(cin,playerSix);
            break;

            default:
                cout << "Try again";
            break;
        }}
    while ( x <= 7){
        //Generate a random player
            randPlayer = ranint (0 , numPlayers - 1);
                ranPlayer.push_back(playerOne);
                ranPlayer.push_back(playerTwo);
                ranPlayer.push_back(playerThree);
                ranPlayer.push_back(playerFour);
                ranPlayer.push_back(playerFive);
                ranPlayer.push_back(playerSix);
    // Getting Player Input
        cout << ranPlayer [randPlayer] << " truth or dare?" << endl;
        getline(cin, playerInput);

   
    
    // Truths
        string truthOne   = "Descride your first crush (at least 3 traits)";
        string truthTwo   = "What was the last lie you told?" ;
        string truthThree = "Who would you date in our FHE group?";
        string truthFour  = "What is your greatest fear?" ;
        string truthFive  = "What are three things you have in common with a loaf of bread?";
        string truthSix   = "What is your most embrassing fart story?";
        string truthSeven = "What is the worse date you have ever been on?";
        string truthEight = "What is one thing that you never want your parents to know about?";
        string truthNine  = "What is the most childish thing you do?";
        string truthTen   = "What is something that people would think you would never do, but you have?";
        string truthEleven = "What is the dumbest thing you have done?";
        string truthTwelve = "Who is the hottest (besides yourself) here?";
        string truthThriteen = "When was the last time you picked your nose?";
        string truthFourteen = "What is the longest you have worn the same pair of underwear?";
        string truthFifteen  = "What is one thing that you would want to change about yourself?";
        string truth16 = "What are you most self-conscious about?";
        string truth17 = "What is the meanest you have been to someone that didn’t deserve it?";
        string truth18 = "Where is the strangest place you have peed?";
        string truth19 = "What is the scariest dream you have ever had?";
        string truth20 = "What is something that you have never told anyone?";
        string truth21 = "What would you do if you were the opposite gender for a day?"; 


        ranTruth.push_back(truthOne);
        ranTruth.push_back(truthTwo);
        ranTruth.push_back(truthThree);
        ranTruth.push_back(truthFour);
        ranTruth.push_back(truthFive);
        ranTruth.push_back(truthSix);
        ranTruth.push_back(truthSeven);
        ranTruth.push_back(truthEight);
        ranTruth.push_back(truthNine);
        ranTruth.push_back(truthTen);
        ranTruth.push_back(truthEleven);
        ranTruth.push_back(truthTwelve);
        ranTruth.push_back(truthThriteen);
        ranTruth.push_back(truthFourteen);
        ranTruth.push_back(truthFifteen);
        ranTruth.push_back(truth16);
        ranTruth.push_back(truth17);
        ranTruth.push_back(truth18);
        ranTruth.push_back(truth19);
        ranTruth.push_back(truth20);
        ranTruth.push_back(truth21);
        
        

        randTruth = ranint(1,22);

    // Dares
        string dareOne   = "Eat a slice of lemmon";
        string dareTwo   = "I am a little teapot in the hallway at the top of your lungs";
        string dareThree = "Put five marshmallows in your mouth and sing twinkle, twinkle, little start";
        string dareFour  = "Take an embarrassing selfie and post it as your profile picture";
        string dareFive  = "Go next door with a measuring cup and ask for a cup of sugar";
        string dareSix   = "Howl like a wolf for 30 seconds in the hall";
        string dareSeven = "Call your crush";
        string dareEight = "Talk to a pillow like it's your crush";
        string dareNine  = "Eat a tablespoon of Mayo";
        string dareTen   = "Let someone text a random person in a contact list whatever they want";
        string dareEleven = "Let someone go through phone for 2 minutes";
        string dareTwelve = "Remove your socks with your teeth";
        string dareThriteen = "Pick the nose of the person next to you.";
        string dareFourteen = "Attempt to breakdance";
        string dareFifteen = "Do your best impersonation of the person to your right";

        ranDare.push_back(dareOne);
        ranDare.push_back(dareTwo);
        ranDare.push_back(dareThree);
        ranDare.push_back(dareFour);
        ranDare.push_back(dareFive);
        ranDare.push_back(dareSix);
        ranDare.push_back(dareSeven);
        ranDare.push_back(dareEight);
        ranDare.push_back(dareNine);
        ranDare.push_back(dareTen);
        ranDare.push_back(dareEleven);
        ranDare.push_back(dareTwelve);
        ranDare.push_back(dareThriteen);
        ranDare.push_back(dareFourteen);
        ranDare.push_back(dareFifteen);
        randDare = ranint(1, 16);
   


    // Outputs Truth or Dare Question
        if (playerInput == "truth" || playerInput == "Truth"){
            cout << ranTruth[randTruth] << endl;
            cout << endl;
         }

        if (playerInput == "dare" || playerInput == "Dare") {
            cout << ranDare [randDare] << endl;
            cout << endl;
        }
     x = x + 1;}
     }
     return 0;
}
