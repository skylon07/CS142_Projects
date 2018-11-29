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

    void AddPlayers (vector <string> &playerNames, int numPlayers){
        string playerName;
        
        for (int i = 0; i < numPlayers; i++){
            cout << "Enter Player " << i + 1 << endl;
            getline(cin,playerName);
            cout << "Welcome " << playerName << "." << endl;
            playerNames.push_back(playerName);
            sleepFor(1.5);
        }

    }


int main () {

    //Varibles and What not
        bool programRunning = true;
        int numPlayers = 0;
        string randPlayer;
        int randTruth;
        int randDare;
        int playedRounds = 0;
        int numRounds = 0;
        string playerInput;
        string pastPlayer = " ";
       
        
        srand (time (0));

    //Vectors
        vector <string> ranPlayer;
        vector <string> ranTruth;
        vector <string> ranDare;
        vector <string> playerNames;

    
    // Welcome and gathering number of players
        cout << "Welcome to Truth or Dare" << endl;

        sleepFor(2);
       
        cout << "Enter Number of rounds" << endl;
        cin  >> numRounds;

    
        cout << "Please enter the number of Players" << endl;
        cin  >> numPlayers;
        cin.ignore();

        if (numPlayers <= 1 ){
            cout << "Incorrect Number of Players"<< endl;
        }

        else {
            AddPlayers(playerNames, numPlayers);
            cout << endl;
        }

    //Actual Game
       for (playedRounds = 0; playedRounds < numRounds; playedRounds++){
           //Generate a random player
            int randnum = ranint(0,(playerNames.size()-1));
            randPlayer = playerNames.at(randnum);

            while (randPlayer == pastPlayer){
                 randnum = ranint(0,(playerNames.size()-1));
                 randPlayer = playerNames.at(randnum);
            }
            
            pastPlayer = randPlayer;

    
           // Getting Player Input
            cout << randPlayer << " truth or dare?" << endl;
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
            ranTruth.push_back("What was the last thing you searched for on your phone?");
            ranTruth.push_back("Did you have an imaginary friend growing up?");
            ranTruth.push_back("What is your worst habit?");

            randTruth = ranint(1,ranTruth.size());

           // Dares
            ranDare.push_back("Eat a slice of lemmon");
            ranDare.push_back("Sing \"I am a Little Teapot\" in the hallway at the top of your lungs");
            ranDare.push_back("Put five marshmallows in your mouth and sing \"Twinkle, Twinkle, Little Star\"");
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
            ranDare.push_back("Find try to lick your elbow until the next prompt appears");
            ranDare.push_back("Fake cry");
            ranDare.push_back("Lick the bottom of your shoe or foot");
            ranDare.push_back("Act like an animal of the group’s choosing");
            ranDare.push_back("Draw on your face with permanent marker");
            ranDare.push_back("Let the person to your right put duct tape on any part of your body they choose and rip it off.");

            randDare = ranint(1, ranDare.size());


           // Outputs Truth or Dare Question
            if (playerInput == "truth" || playerInput == "Truth"){
                cout << endl;
                cout << ranTruth[randTruth] << endl;
                cout << endl;
               sleepFor(10);
            }

            if (playerInput == "dare" || playerInput == "Dare") {
                cout << endl;
                cout << ranDare [randDare] << endl;
                cout << endl;
                sleepFor(15);
            }

       }

    cout << "GAME OVER" << endl;
     return 0;
}
