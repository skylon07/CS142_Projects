#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include <vector>
#include <string>

using namespace std;


class Playlist {
    public:
        Playlist();
        Playlist(string listName);

        string GetNameList();
       
        int GetSizeList();
    
        void SetNameList(string newName);
        void PlaySongs();
        void AddSongToPlaylist(Song* songPointer);
        void DeleteSongToPlaylist(int loctionToDelete);
        void DeleteSongFromLibrary(Song* songtoDelete);
        void ListSongsOnly();

        Song* RemoveSongByName(string songName); 

    private:
        string listName = "none";
        vector<Song*> songList;
};


#endif