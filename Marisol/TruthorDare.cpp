//Libraries 
    #include <iostream>
    #include <string>
    #include <cctype>
    #include <cstdlib>
    #include <chrono> 
    #include <vector>
    #include <thread>
    #include <ctime>


using namespace std;

    //Functions
        int ranint (int low, int high) {
            int randval = rand(); 
            int range = high - low + 1 ; // plus one makes it enclusive of high
            randval = randval % range;
            return randval + low; 

        }

        void sleepFor (int seconds){
            for(int i = 0; i < seconds; i++){
                system("timeout /t 1 >nul");
            }
            
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
        int numRounds = 30;
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

        sleepFor(2);
       
       cout << "Please enter the number of Players (3 to 6 players needed)" << endl;
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
    
    while ( x <= numRounds){
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

   
    
    // Truth
        ranTruth.push_back("Descride your first crush (at least 3 traits)");
        ranTruth.push_back("What was the last lie you told?");
        ranTruth.push_back("Who would you date in our FHE group?");
        ranTruth.push_back("What is your greatest fear?" );
        ranTruth.push_back("What are three things you have in common with a loaf of bread?");
        ranTruth.push_back("What is your most embrassing fart story?");
        ranTruth.push_back("What is the worse date you have ever been on?");
        ranTruth.push_back("What is one thing that you never want your parents to know about?");
        ranTruth.push_back("What is the most childish thing you do?");
        ranTruth.push_back("What is something that people would think you would never do, but you have?");
        ranTruth.push_back("What is the dumbest thing you have done?");
        ranTruth.push_back("Who is the hottest (besides yourself) here?");
        ranTruth.push_back("When was the last time you picked your nose?");
        ranTruth.push_back("What is the longest you have worn the same pair of underwear?");
        ranTruth.push_back("What is one thing that you would want to change about yourself?");
        ranTruth.push_back("What are you most self-conscious about?");
        ranTruth.push_back( "What is the meanest you have been to someone that didn’t deserve it?");
        ranTruth.push_back("Where is the strangest place you have peed?");
        ranTruth.push_back("What is the scariest dream you have ever had?");
        ranTruth.push_back("What is something that you have never told anyone?");
        ranTruth.push_back("What would you do if you were the opposite gender for a day?");
        
        randTruth = ranint(1,22);

    // Dares
        ranDare.push_back("Eat a slice of lemmon");
        ranDare.push_back("Sing I am a little teapot in the hallway at the top of your lungs");
        ranDare.push_back("Put five marshmallows in your mouth and sing twinkle, twinkle, little star");
        ranDare.push_back("Take an embarrassing selfie and post it as your profile picture");
        ranDare.push_back("Go next door with a measuring cup and ask for a cup of sugar");
        ranDare.push_back("Howl like a wolf for 30 seconds in the hall");
        ranDare.push_back("Call your crush");
        ranDare.push_back("Talk to a pillow like it's your crush");
        ranDare.push_back("Eat a tablespoon of Mayo");
        ranDare.push_back("Let someone go through phone for 2 minutes");
        ranDare.push_back("Remove your socks with your teeth");
        ranDare.push_back("Pick the nose of the person next to you.");
        ranDare.push_back("Attempt to breakdance");
        ranDare.push_back("Do your best impersonation of the person to your right");
        ranDare.push_back("Spin around 10 times and try to run straight.");
        ranDare.push_back("");
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
     x = x + 1;
    sleepFor(15);
     }
     return 0;
}
