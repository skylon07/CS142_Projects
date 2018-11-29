#ifndef SONG_H
#define SONG_H


#include <iostream>

using namespace std;

class Song {
public:
   
    Song(); 
    Song(string songName, string firstLine);

    string GetSongName();
    string SongLine();
    int NumPlays();

    void SetName(string newName);
    void SetLine(string newFirstLine);

    void PlaySong();
    string ToString();

private:
    string songName = "none";
    string firstLine = "none";
    int numPlays = 0;

    void SetNumPlays(int numTimesPlayed);
};


#endif