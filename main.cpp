/*
 Mikayla Cheng
 main.cpp
 Free memory in line 144 using CleanUp function(line 86).
*/

#include<iostream>
#include<ios>
#include<iomanip>
#include<string>
#include <vector>
#include "Song.h"
#include "Playlist.h"

using namespace std;
void AddSongToLibrary(vector<Song*> &songLibrary)
{
    string newName;
    string newFirstLine;
    cout << "Read in Song names and first lines (type \"STOP\" when done):" << endl;
    
    while (true)
    {
        cout << "Song Name: " << endl;
        getline(cin, newName);
        
        if (newName == "STOP")
            break;
        
        cout << "Song's first line: " << endl;
        getline(cin, newFirstLine);
        
        Song* songToAdd = new Song(newName, newFirstLine);
        songLibrary.push_back(songToAdd);
    }
}

void PrintOptionsMenu()
{
    cout << "add      Adds a list of songs to the library" << endl;
    cout << "list     Lists all the songs in the library" << endl;
    cout << "addp     Adds a new playlist" << endl;
    cout << "addsp    Adds a song to a playlist" << endl;
    cout << "listp    Lists all the playlists" << endl;
    cout << "play     Plays a playlist" << endl;
    cout << "delp     Deletes a playlist" << endl;
    cout << "delsp    Deletes a song from a playlist" << endl;
    cout << "delsl    Deletes a song from the library (and all playlists)" << endl;
    cout << "options  Prints this options menu" << endl;
    cout << "quit     Quits the program" << endl << endl;
}

void AddPlaylist(vector<Playlist*>& playlistLibrary, string nameOfPlaylist)
{
    Playlist* playlistPtr = new Playlist();
    playlistPtr->SetName(nameOfPlaylist);
    playlistLibrary.push_back(playlistPtr);
}

void ListPlaylists(vector<Playlist*> playlistsToList)
{
    for(int i = 0; i < playlistsToList.size(); ++i)
    {
        cout << i << ": " << playlistsToList.at(i)->GetName() << endl;
    }
}

void ListLibrary(vector<Song*> &songLibrary)
{
    for(int i = 0; i < songLibrary.size(); ++i)
    {
        cout << songLibrary.at(i)->GetName() << ": \"" << songLibrary.at(i)->GetFirstLine() <<"\", " << songLibrary.at(i)->GetPlayCount() << " play(s)." << endl;
    }
    cout << endl;
}

void ListSongNames(vector<Song*> songLibrary)
{
    for(int i = 0; i < songLibrary.size(); ++i)
    {
        cout << i << ": " << songLibrary.at(i)->GetName() << endl;
    }
    cout << endl;
}

void Cleanup(vector<Song*>& libraryToClean, vector<Playlist*>& playlistsToClean)
{
    //delete songs
    for(int i = 0; i < libraryToClean.size(); ++i)
    {
        Song* songToDelete = libraryToClean.at(i);
        delete songToDelete;
    }
    
    //delete playlists
    for(int j = 0; j < playlistsToClean.size(); ++j)
    {
        Playlist* playlistToDelete = playlistsToClean.at(j);
        delete playlistToDelete;
    }
}

void DeleteSongInLibrary(vector<Song*>& songLibrary, vector<Playlist*>& playlists)
{
    int songIndex = 0;
    cout << "Pick a song index number: " << endl;
    cin >>songIndex;
    Song* indexToDelete = songLibrary.at(songIndex);
 
    for(int i = 0; i < playlists.size(); i++)
    {
        Playlist *playlistToCheck = playlists.at(i);
        for(int j = 0; j < playlistToCheck->GetSize(); j++)
        {
            if(playlistToCheck->GetPlayListSongs().at(j)->GetName() == songLibrary.at(songIndex)->GetName())
            {
                playlistToCheck->DeleteSongFromPlaylist(j);
                break;
            }
        }
    }
    
    songLibrary.erase(songLibrary.begin() + songIndex);
    delete indexToDelete;
    cin.ignore();
}


int main()
{
    vector<Song*> songLibrary;
    vector<Playlist*> playlists;
    string userOption;
    cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;
    
    while(true)
    {
        cout << "Enter your selection now:" << endl;
        cin >> userOption;
        cin.ignore();
        
        if(userOption == "quit")
        {
            Cleanup(songLibrary, playlists);
            break;
        }
        else if(userOption == "add")
        {
            AddSongToLibrary(songLibrary);
        }
        else if(userOption == "list")
        {
            ListLibrary(songLibrary);
        }
        else if(userOption == "addp")
        {
            string playlistName;
            cout << "Playlist name: " << endl << endl;
            getline(cin, playlistName);
            
            AddPlaylist(playlists, playlistName);
        }
        else if(userOption == "addsp")
        {
            int playlistIndex = 0;
            int songIndex;
            
            ListPlaylists(playlists);
            cout << "Pick a playlist index number: " << endl;
            cin >> playlistIndex;
            
            ListSongNames(songLibrary);
            cout << "Pick a song index number: " << endl << endl;
            cin >>songIndex;
            
            Song* songToAdd = songLibrary.at(songIndex);
            playlists.at(playlistIndex)->AddSong(songToAdd);
        }
        else if(userOption == "listp")
        {
            ListPlaylists(playlists);
        }
        else if(userOption == "play")
        {
            int playlistIndex = 0;
            
            ListPlaylists(playlists);
            cout << "Pick a playlist index number:" << endl;
            cin >> playlistIndex;
            
            playlists.at(playlistIndex)->Play();
        }
        else if(userOption == "delp")
        {
            int playlistIndex = 0;
            
            ListPlaylists(playlists);
            cout << "Pick a playlist index number to delete: " << endl;
            cin >> playlistIndex;
            
            Playlist* playlistTemp = playlists.at(playlistIndex);
            
            playlists.erase(playlists.begin() + playlistIndex);
            
            delete playlistTemp;
        }
        else if(userOption == "delsp") //delete a song from playlist
        {
            int playlistIndex = 0;
            int songIndex;
            
            ListPlaylists(playlists);
            cout << "Pick a playlist index number: " << endl;
            cin >> playlistIndex;
            
            playlists.at(playlistIndex)->List();
            cout << "Pick a song index number to delete: " << endl;
            cin >>songIndex;
            
            playlists.at(playlistIndex)->DeleteSongFromPlaylist(songIndex);
        }
        
        else if(userOption == "delsl") //delete song from library
        {
            ListSongNames(songLibrary);
            DeleteSongInLibrary(songLibrary, playlists);
        }
        else
        {
            PrintOptionsMenu();
        }
    }
    cout << "Goodbye!";
}
