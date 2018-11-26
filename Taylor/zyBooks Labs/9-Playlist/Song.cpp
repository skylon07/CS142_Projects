#include "Song.h"

// default constructor does nothing
Song::Song() { }

// constructor that sets name and first line
Song::Song(std::string songName, std::string firstLine) {
    SetName(songName);
    SetLine(firstLine);
}


// getters for members
std::string Song::GetName() { 
    return songName;
}

std::string Song::GetLine() {
    return firstLine;
}

int Song::GetNumPlays() {
    return numPlays;
}


// setters for variables
void Song::SetName(std::string newName) {
    songName = newName;
}

void Song::SetLine(std::string newFirstLine) {
    firstLine = newFirstLine;
}

void Song::SetNumPlays(int numTimesPlayed) {
    numPlays = numTimesPlayed;
}


// function that "plays" the song
// - prints first line and increments play count
void Song::PlaySong() {
    std::cout << GetLine() << std::endl;
    SetNumPlays(GetNumPlays() + 1); // incrememt by 1
}