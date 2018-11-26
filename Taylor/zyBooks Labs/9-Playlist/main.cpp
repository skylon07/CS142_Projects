// functions that free memory:
// MenuDeletePlaylist (line 282)
// MenuDeleteSongFromLibrary (line 326)
// MenuQuitProgram (lines 342, 350)

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Song.h"
#include "Playlist.h"

#include <string>
#include <vector>
#include <sstream>


// PROGRAM SETTINGS

// a constant that contains the number of menu options
const int NUM_MENU_OPTIONS = 11;
// a list of valid menu options
const std::string MENU_OPTIONS[NUM_MENU_OPTIONS] = {
    "add", // add a list of songs to the library
    "list", // list songs in the library
    "addp", // add a new playlist
    "addsp", // add a song to a playlist
    "listp", // list all playlists
    "play", // play a playlist
    "delp", // delete a playlist
    "delsp", // delete a song from a playlist
    "delsl", // delete a song from the library (and all playlists)
    "options", // print the options menu
    "quit", // quit the program
};
// a list of descriptions to each menu option
const std::string MENU_OPTION_DESCS[NUM_MENU_OPTIONS] = {
    "Adds a list of songs to the library",
    "Lists all the songs in the library",
    "Adds a new playlist",
    "Adds a song to a playlist",
    "Lists all the playlists",
    "Plays a playlist",
    "Deletes a playlist",
    "Deletes a song from a playlist",
    "Deletes a song from the library (and all playlists)",
    "Prints this options menu",
    "Quits the program",
};
// a list of functions that are run with their selected menu options
// - must accept parameters for song list and playlist list
void MenuAddSongs(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect);
void MenuListSongs(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect);
void MenuAddPlaylist(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect);
void MenuAddSongToPlaylist(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect);
void MenuListPlaylists(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect);
void MenuPlayPlaylist(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect);
void MenuDeletePlaylist(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect);
void MenuDeleteSongFromPlaylist(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect);
void MenuDeleteSongFromLibrary(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect);
void MenuPrintOptions(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect);
void MenuQuitProgram(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect);

// list of pointers to above functions
// - new type is defined as "pointer to function that returns void and takes two arguments"
typedef void (*MenuFunc) (std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect);
const MenuFunc MENU_OPTION_FUNCS[NUM_MENU_OPTIONS] = {
    MenuAddSongs,
    MenuListSongs,
    MenuAddPlaylist,
    MenuAddSongToPlaylist,
    MenuListPlaylists,
    MenuPlayPlaylist,
    MenuDeletePlaylist,
    MenuDeleteSongFromPlaylist,
    MenuDeleteSongFromLibrary,
    MenuPrintOptions,
    MenuQuitProgram,
};


// gets the users input given a prompt
std::string GetUserInput(std::string inputPrompt = "") {
    std::cout << inputPrompt;

    // get the input
    std::string userInput;
    std::getline(std::cin, userInput);
    std::cout << std::endl; // zybooks mimic enter

    // return the input
    return userInput;
}

// gets input from the user, forcing it to be an integer
int GetUserInputInt(std::string inputPrompt = "", std::string errorPrompt = "") {
    // declare variables
    int userInputInt = 0;
    std::istringstream inputConverter;

    // get initial input
    std::string userInputRaw = GetUserInput(inputPrompt);
    // set converter string to raw string
    inputConverter.str(userInputRaw);
    // attempt to convert to int
    inputConverter >> userInputInt;

    // check for errors
    while (inputConverter.fail()) {
        // clear any possible fails
        inputConverter.clear();

        // get input again
        std::string userInputRaw = GetUserInput(errorPrompt);
        inputConverter.str(userInputRaw);
        inputConverter >> userInputInt;
    }

    // return validated input
    return userInputInt;
}


// print the available menu options
void PrintMenuOptions() {
    // output options and descriptions
    for (int i = 0; i < NUM_MENU_OPTIONS; ++i) {
        // output option and description tabbed spaces over
        std::cout << std::setw(9) << std::left << MENU_OPTIONS[i] << MENU_OPTION_DESCS[i] << std::endl;
    }
}


// removes a given song from all playlists
void RemoveSongFromAllPlaylists(Song* songToRemove, std::vector<Playlist*>& playlistVect) {
    // iterate over all playlists
    for (unsigned int i = 0; i < playlistVect.size(); ++i) {
        std::string currSongName = songToRemove->GetName();
        Playlist* currPlaylist = playlistVect.at(i);
        // remove the song from the playlist
        // - note that this function removes nothing (and returns nullptr) if the song was not found
        currPlaylist->RemoveSongByName(currSongName);
    }
}


// process the menu selection
// - returns if the program exits
bool ProcessMenuSelection(std::string userInput, std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect) {
    // find the index of the menu option
    int optionIdx; // declared outside to be used after loop exits
    for (optionIdx = 0; optionIdx < NUM_MENU_OPTIONS; ++optionIdx) {
        // if the options match, remember the index
        if (MENU_OPTIONS[optionIdx] == userInput) {
            break;
        }
    }

    // test if option was not found
    if (optionIdx == NUM_MENU_OPTIONS) {
        // print options
        PrintMenuOptions();
        // keep the program running: should quit? false
        return false;
    }

    // run the function in the options index
    MENU_OPTION_FUNCS[optionIdx](songList, playlistVect);
    
    // unless the option was quit, keep running the program
    return (userInput == "quit");
}

// definitions of menu functions
void MenuAddSongs(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect) {
    // print instructions
    std::cout << "Read in Song names and first lines (type \"STOP\" when done):" << std::endl;

    // loop input
    while (true) {
        // get the song name
        std::string songName = GetUserInput("Song Name: ");
        // test for stop command
        if (songName == "STOP") {
            break;
        }

        // get song line
        std::string songLine = GetUserInput("Song's first line: ");

        // create song pointer
        Song* songPointer = new Song(songName, songLine);

        // add song to list
        songList.push_back(songPointer);
    }
}

void MenuListSongs(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect) {
    // print all songs
    for (unsigned int i = 0; i < songList.size(); ++i) {
        Song* currSong = songList.at(i);
        // print the song name, the first line, then the play count
        std::cout << currSong->GetName() << ": \"" << currSong->GetLine() << "\", "
            << currSong->GetNumPlays() << " play(s)." << std::endl;
    }
}

void MenuAddPlaylist(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect) {
    // get the playlist name
    std::string playlistName = GetUserInput("Playlist name: ");

    // create the playlist
    Playlist* newPlaylist = new Playlist(playlistName);
    // add to the vector
    playlistVect.push_back(newPlaylist);
}

void MenuAddSongToPlaylist(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect) {
    // print all playlist names
    for (unsigned int i = 0; i < playlistVect.size(); ++i) {
        // print song index and name
        std::cout << std::setw(2) << i << ": " << playlistVect.at(i)->GetNameList() << std::endl;
    }

    // get the input playlist
    int playlistIdx = GetUserInputInt("Pick a playlist index number: ");
    Playlist* selectedPlaylist = playlistVect.at(playlistIdx);

    // print all song names
    for (unsigned int i = 0; i < songList.size(); ++i) {
        // print song index and name
        std::cout << std::setw(2) << i << ": " << songList.at(i)->GetName() << std::endl;
    }

    // get the input song
    int songIdx = GetUserInputInt("Pick a song index number: ");
    Song* selectedSong = songList.at(songIdx);

    // add the song to the playlist
    selectedPlaylist->AddSong(selectedSong);
}

void MenuListPlaylists(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect) {
    // iterate over all playlists
    for (unsigned int i = 0; i < playlistVect.size(); ++i) {
        // print the index and the playlist name
        std::cout << std::setw(2) << i << ": " << playlistVect.at(i)->GetNameList() << std::endl;
    }
}

void MenuPlayPlaylist(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect) {
    // print all playlist names
    for (unsigned int i = 0; i < playlistVect.size(); ++i) {
        // print song index and name
        std::cout << std::setw(2) << i << ": " << playlistVect.at(i)->GetNameList() << std::endl;
    }

    // get the input 
    int playlistIdx = GetUserInputInt("Pick a playlist index number: ");
    Playlist* listToPlay = playlistVect.at(playlistIdx);

    // print message
    std::cout << "Playing first lines of playlist: " << listToPlay->GetNameList() << std::endl;

    // "play" the playlist
    listToPlay->PlaySongsInList();
}

void MenuDeletePlaylist(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect) {
    // print all playlist names
    for (unsigned int i = 0; i < playlistVect.size(); ++i) {
        // print song index and name
        std::cout << std::setw(2) << i << ": " << playlistVect.at(i)->GetNameList() << std::endl;
    }

    // get the input 
    int playlistIdx = GetUserInputInt("Pick a playlist index number to delete: ");

    // deallocate playlist
    delete playlistVect.at(playlistIdx);
    // erase pointer
    playlistVect.erase(playlistVect.begin() + playlistIdx);
}

void MenuDeleteSongFromPlaylist(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect) {
    // print all playlist names
    for (unsigned int i = 0; i < playlistVect.size(); ++i) {
        // print song index and name
        std::cout << std::setw(2) << i << ": " << playlistVect.at(i)->GetNameList() << std::endl;
    }

    // get the input playlist
    int playlistIdx = GetUserInputInt("Pick a playlist index number: ");
    Playlist* selectedPlaylist = playlistVect.at(playlistIdx);

    // print songs at the playlist
    for (int i = 0; i < selectedPlaylist->GetSizeList(); ++i) {
        // print song index and name
        std::cout << std::setw(2) << i << ": " << selectedPlaylist->GetSongAt(i)->GetName() << std::endl;
    }

    // get the input song
    int songIdx = GetUserInputInt("Pick a song index number to delete: ");
    Song* selectedSong = selectedPlaylist->GetSongAt(songIdx);

    // remove the song from the playlist
    selectedPlaylist->RemoveSongByName(selectedSong->GetName());
}

void MenuDeleteSongFromLibrary(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect) {
    // print all song names
    for (unsigned int i = 0; i < songList.size(); ++i) {
        // print song index and name
        std::cout << std::setw(2) << i << ": " << songList.at(i)->GetName() << std::endl;
    }

    // get the input 
    int songIndex = GetUserInputInt("Pick a song index number: ");

    // remove song from all playlists
    RemoveSongFromAllPlaylists(songList.at(songIndex), playlistVect);

    // deallocate song
    delete songList.at(songIndex);
    // erase pointer
    songList.erase(songList.begin() + songIndex);
}

void MenuPrintOptions(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect) {
    PrintMenuOptions();
}

void MenuQuitProgram(std::vector<Song*>& songList, std::vector<Playlist*>& playlistVect) {
    // print message
    std::cout << "Goodbye!" << std::endl;

    // deallocate memory for all playlists
    for (unsigned int i = 0; i < playlistVect.size(); ++i) {
        // free memory
        delete playlistVect.at(0);
        // erase pointer from list
        playlistVect.erase(playlistVect.begin());
    }

    // deallocate memory for all songs
    for (unsigned int i = 0; i < songList.size(); ++i) {
        // free memory for song object
        delete songList.at(0);
        // erase pointer from the list
        songList.erase(songList.begin());
    }
}


// main program entry
int main() {
    // main storage variables
    std::vector<Song*> songList;
    std::vector<Playlist*> playlistVect;

    // print welcome message
    std::cout << "Welcome to the Firstline Player!  Enter options to see menu options." << std::endl;

    // main menu loop
    bool programRunning = true;
    while (programRunning) {
        // separator
        std::cout << std::endl;

        // get the user input
        std::string userInput = GetUserInput("Enter your selection now: ");

        // process the users selection, check if program keeps running
        programRunning = !ProcessMenuSelection(userInput, songList, playlistVect);
    }

    return 0;
}