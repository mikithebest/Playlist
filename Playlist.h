/*
 Mikayla Cheng
 Playlist.h
 */

#ifndef Playlist_h
#define Playlist_h
#include <iostream>
#include <vector>
#include "Song.h"
using namespace std;

class Playlist
{
public:
    Playlist();
    Playlist(string playlistNameToSet, vector<Song*> playlistSongs);
    string GetName();
    void SetName(string nameToSet);
    void AddSong(Song* songToAdd);
    void List();
    void Play();
    void DeleteSongFromPlaylist(int indexToDelete);
    long GetSize();
    vector<Song*> GetPlayListSongs();
private:
    string playlistName;
    vector<Song*> playlistSongs;
};
#endif


