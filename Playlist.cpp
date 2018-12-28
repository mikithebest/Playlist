/*
 Mikayla Cheng
 Playlist.cpp
 */

#include "Playlist.h"


Playlist::Playlist()
{
    playlistName = "";
    vector<Song*> playlistSongs;
}

Playlist::Playlist(string playlistNameToSet, vector<Song*> playlistSongsToSet)
{
    playlistName = playlistNameToSet;
    vector<Song*> playlistSongs = playlistSongsToSet;
}

string Playlist::GetName()
{
    return playlistName;
}

void Playlist:: SetName(string nameToSet)
{
    playlistName = nameToSet;
}

void Playlist::AddSong(Song* songToAdd)
{
    playlistSongs.push_back(songToAdd);
}

void Playlist::List()
{
    for(int i = 0; i < playlistSongs.size(); ++i)
    {
        cout << i << ": " << playlistSongs.at(i)->GetName() << endl;
    }
}

void Playlist::Play()
{
    cout << "Playing first lines of playlist: " << GetName() << endl;
    
    for(int i = 0; i < playlistSongs.size(); ++i)
                            
    {
        playlistSongs.at(i)->SetPlayCount(playlistSongs.at(i)->GetPlayCount() + 1);
        cout << playlistSongs.at(i)->GetFirstLine() << endl;
    }
}

void Playlist::DeleteSongFromPlaylist(int indexToDelete)
{
    playlistSongs.erase(playlistSongs.begin() + indexToDelete);
}

long Playlist:: GetSize()
{
    return playlistSongs.size();
}

vector<Song*> Playlist:: GetPlayListSongs()
{
    return playlistSongs;
}
