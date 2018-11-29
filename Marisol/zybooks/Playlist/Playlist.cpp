#include "Playlist.h"
#include <vector>

using namespace std;

Playlist::Playlist() { }

Playlist::Playlist(string listName) {
    SetNameList(listName);
}

int Playlist::GetSizeList() {
    return songList.size();
}

string Playlist::GetNameList() {
    return listName;
}

void Playlist::SetNameList(string newName) {
    listName = newName;
}

void Playlist::PlaySongs() {
    for (int i = 0; i < GetSizeList(); ++i) {
        songList.at(i)->PlaySong();
    }
}

void Playlist::AddSongToPlaylist(Song* songPointer) {
    songList.push_back(songPointer);
}
void Playlist::ListSongsOnly() {
    for (unsigned int i = 0; i < songList.size(); i++){
        cout << i << ": " << songList.at(i) ->GetSongName() << endl;
    }
}
void Playlist::DeleteSongToPlaylist(int loctionToDelete) {
    songList.erase(songList.begin() + loctionToDelete);
}
void Playlist::DeleteSongFromLibrary(Song* songToDelete) {
    for (unsigned int i = 0; i < songList.size(); i++) {
        if(songList.at(i) == songToDelete) {
            songList.erase(songList.begin() + i);
        }
    }
}