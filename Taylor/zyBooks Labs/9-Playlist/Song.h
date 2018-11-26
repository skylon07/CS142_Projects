#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>


class Song {
public:
    // constructors
    Song(); // default
    Song(std::string songName, std::string firstLine);

    // getters for variables
    std::string GetName();
    std::string GetLine();
    int GetNumPlays();

    // setters for variables
    void SetName(std::string newName);
    void SetLine(std::string newFirstLine);

    // function that "plays" the song (prints the first line, increments play count)
    void PlaySong();

private:
    // data members
    std::string songName = "none";
    std::string firstLine = "none";
    int numPlays = 0;

    // setter for number of times played
    void SetNumPlays(int numTimesPlayed);
};


#endif