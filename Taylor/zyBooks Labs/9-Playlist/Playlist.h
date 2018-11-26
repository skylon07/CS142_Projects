#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include <vector>
#include <string>


class Playlist {
public:
    // constructors
    Playlist(); // default
    Playlist(std::string listName);

    // member getters
    std::string GetNameList();
    int GetSizeList();
    Song* GetSongByName(std::string songName); // returns first occurence, nullptr
    Song* GetSongAt(int songIdx);

    // member setters
    void SetNameList(std::string newName);

    // manipulators
    void AddSong(Song* newSong);
    Song* RemoveSongByName(std::string songName); // removes first occurence

    // function that "plays" the playlist
    void PlaySongsInList();

private:
    std::string listName = "none";
    std::vector<Song*> songList;
};


#endif