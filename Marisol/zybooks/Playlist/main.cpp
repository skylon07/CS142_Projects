//Marisol Mattson
//marisolrm2000@gmail.com
//section 2


#include <iostream>
#include <vector>
#include <string>

#include "Song.h"
#include "Playlist.h"

using namespace std;

string GetUserInput(string inputPrompt="") {
    cout << inputPrompt;
    
    string userInput;
    getline(cin, userInput);
    cout << endl; 

    return userInput;
}

void DisplayOptionsMenu() {
    cout<< "add      Adds a list of songs to the library" << endl;
    cout<< "list     Lists all the songs in the library" << endl;
    cout<< "addp     Adds a new playlist" << endl;
    cout<< "addsp    Adds a song to a playlist" << endl;
    cout<< "listp    Lists all the playlists" << endl;
    cout<< "play     Plays a playlist" << endl;
    cout<< "delp     Deletes a playlist" << endl;
    cout<< "delsp    Deletes a song from a playlist" << endl;
    cout<< "delsl    Deletes a song from the library (and all playlists)" << endl;
    cout<< "options  Prints this options menu" << endl;
    cout<< "quit     Quits the program" << endl;
}

void AddSong (vector <Song*> &listOfSongs){
    string userInput = "";
    cout << "Read in Song names and first lines (type \"STOP\" when done):" << endl;

        while (true) {
        string songName = GetUserInput("Song Name: ");

        if (songName == "STOP") {
            break;
        }
        string songLine = GetUserInput("Song's first line: ");
        Song* songPointer = new Song(songName, songLine);
        listOfSongs.push_back(songPointer);
    }
}

void ListSongs (const vector <Song*> listOfSongs){
    for (int i = 0; i < listOfSongs.size(); i++){
        cout << listOfSongs.at(i) -> ToString();
    }
}

void AddPlayList (vector <Playlist*>& listOfPlayLists){
    string userInput = "";

    string songName = GetUserInput("Playlist name: ");

    Playlist* songPointer = new Playlist(songName);
    listOfPlayLists.push_back(songPointer);
}

void ListPlaylist (const vector <Playlist*> listOfPlayLists){
    for (unsigned int i = 0; i < listOfPlayLists.size(); i++){
        cout << i << ": " << listOfPlayLists.at(i) -> GetNameList() << endl; 
    }
}
void RemovePlaylist(vector <Playlist*>& listOfPlayLists, int deleteNum) {
    delete listOfPlayLists.at(deleteNum);
    listOfPlayLists.erase(listOfPlayLists.begin() + deleteNum);
}


void PlayPlayList (int userNum, vector <Playlist*> &listOfPlayLists){
    cout << "Playing first lines of playlist: " << listOfPlayLists.at(userNum) -> GetNameList();
    listOfPlayLists.at(userNum) -> PlaySongs();
}
void RemoveSongFromLibrary(int index, vector <Song*>& listOfSongs, vector <Playlist*>& listOfPlayLists ){
    for (unsigned int i = 0; i < listOfPlayLists.size(); i++) {
        listOfPlayLists.at(i) -> DeleteSongFromLibrary(listOfSongs.at(i));
    }
    delete listOfSongs.at(index);
    listOfSongs.erase(listOfSongs.begin() + index);
}

int main() {

  vector <Song*> listOfSongs;
  vector <Playlist*> listOfPlayLists;
  bool programRunning = true;
  string userSelection = "";
  int playlistNum = -1;
  int delNum = -1;


 cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl;

    while (programRunning == true){
        
        userSelection = GetUserInput("Enter your selection now: ");

        if (userSelection == "add") {
            AddSong (listOfSongs);
        }

        else if (userSelection == "list") {
            ListSongs(listOfSongs);   
        }

        else if (userSelection == "addp") {
            AddPlayList(listOfPlayLists);
        }

        else if (userSelection == "addsp") {
            int playListIndex;
            int songIndex;
            
            ListPlaylist(listOfPlayLists);

            cout << "Pick a playlist index number: "<< endl;
            cin  >> playListIndex;
            
             for (unsigned int i = 0; i < listOfSongs.size(); i++) {
                cout << i << ": "<< listOfSongs.at(i) -> GetSongName() << endl;
             }
            cout << "Pick a song index number: " << endl;
            cin  >> songIndex;
            listOfPlayLists.at(playListIndex) -> AddSongToPlaylist(listOfSongs.at(songIndex));

        }

        else if (userSelection == "listp") {
            ListPlaylist(listOfPlayLists);
        }

        else if (userSelection == "options") {
            DisplayOptionsMenu();
            cout << endl;

        }

        else if (userSelection == "play"){
            ListPlaylist(listOfPlayLists);

            cout << "Pick a playlist index number: " << endl;
            cin  >> playlistNum;
            PlayPlayList(playlistNum, listOfPlayLists);
        }

        else if (userSelection == "delp"){
            cout << "Pick a playlist index number to delete: " << endl;
            cin  >> delNum;
            RemovePlaylist(listOfPlayLists, delNum);
        }

        else if (userSelection == "delsp"){
            int playListIndex;
            int songIndex;

            ListPlaylist(listOfPlayLists);
            cout << "Pick a playlist index number: " << endl;
            cin  >> playListIndex;

            listOfPlayLists.at(playListIndex) ->ListSongsOnly();
            cout << "Pick a song index number to delete: " << endl;
            cin  >> songIndex;

            listOfPlayLists.at(playListIndex) -> DeleteSongToPlaylist(songIndex);
        }

        else if (userSelection == "delsl"){
            int songIndex;
            ListSongs(listOfSongs);

            cout << "Pick a song index number: " << endl;
            cin  >> songIndex;
            RemoveSongFromLibrary(songIndex, listOfSongs, listOfPlayLists);
        }

        else if (userSelection == "quit") {
            cout << "Goodbye!" << endl;
            
                for (unsigned int i = 0; i < listOfPlayLists.size(); ++i) {
                    delete listOfPlayLists.at(0);
                    listOfPlayLists.erase(listOfPlayLists.begin());
                }

                for (unsigned int i = 0; i < listOfSongs.size(); ++i) {
                    delete listOfSongs.at(0);
                    listOfSongs.erase(listOfSongs.begin());
                }
            programRunning = false;
        }

        else {
            DisplayOptionsMenu();
            cout << endl;
        }

    }

    return 0;
}