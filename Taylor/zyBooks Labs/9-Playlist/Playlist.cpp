#include "Playlist.h"

// default constructor does nothing
Playlist::Playlist() { }

// constructor that sets the list name
Playlist::Playlist(std::string listName) {
    SetNameList(listName);
}


// gets the name of the list
std::string Playlist::GetNameList() {
    return listName;
}

// sets the name of the list
void Playlist::SetNameList(std::string newName) {
    listName = newName;
}


// gets the size of the list
int Playlist::GetSizeList() {
    return songList.size();
}


// returns a song pointer given a name
Song* Playlist::GetSongByName(std::string songName) {
    // iterate over all songs
    for (int i = 0; i < GetSizeList(); ++i) {
        // test if namees match
        if (GetSongAt(i)->GetName() == songName) {
            // return the song
            return GetSongAt(i);
        }
    }
    // return nullptr if not found
    return nullptr;
}

// adds a song to the list
void Playlist::AddSong(Song* newSong) {
    songList.push_back(newSong);
}

// removes a song from the playlist given a name, returning that song
Song* Playlist::RemoveSongByName(std::string songName) {
    // iterate over all songs
    for (int i = 0; i < GetSizeList(); ++i) {
        // test if namees match
        if (GetSongAt(i)->GetName() == songName) {
            // temporary pointer
            Song* foundSong = GetSongAt(i);
            // remove the song
            songList.erase(songList.begin() + i);
            // return the song
            return foundSong;
        }
    }
    // return nullptr if not found
    return nullptr;
}


// returns a song pointer given an index
Song* Playlist::GetSongAt(int songIdx) {
    return songList.at(songIdx);
}


// "play" all songs in the playlist
void Playlist::PlaySongsInList() {
    // iterate over all songs
    for (int i = 0; i < GetSizeList(); ++i) {
        // play the song
        GetSongAt(i)->PlaySong();
    }
}