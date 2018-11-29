#include <iostream>
#include <string>
#include <sstream>

#include "Song.h"

using namespace std;

Song::Song() { }

Song::Song(string songName, string firstLine) {
    SetName(songName);
    SetLine(firstLine);
}

string Song::GetSongName() { 
    return songName;
}

string Song::SongLine() {
    return firstLine;
}

int Song::NumPlays() {
    return numPlays;
}

void Song::SetName(string newName) {
    songName = newName;
}

void Song::SetLine(string newFirstLine) {
    firstLine = newFirstLine;
}

void Song::SetNumPlays(int numTimesPlayed) {
    numPlays = numTimesPlayed;
}

string Song::ToString (){
    ostringstream outStream;
    string totalString;

    outStream << songName << ": " << "\"" << firstLine << "\"" << ", " << numPlays << " play(s)." << endl;
    totalString = outStream.str();
    return totalString;
}

void Song::PlaySong() {
    cout << SongLine() << endl;
    SetNumPlays(NumPlays() + 1);
}