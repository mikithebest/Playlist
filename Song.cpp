/*
 Mikayla Cheng, Section 4, mikaylacheng@gmail.com
 Song.cpp
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <string>
#include "Song.h"
using namespace std;

Song::Song()
{
    songName = "none";
    firstLine = "none";
}

Song::Song(string songNameToSet, string firstLineToSet)
{
    songName = songNameToSet;
    firstLine = firstLineToSet;
}

void Song::SetName(string nameToSet)
{
    songName = nameToSet;
}

string Song:: GetName()
{
    return songName;
}

void Song::SetFirstLine(string firstLineToSet)
{
    firstLine = firstLineToSet;
}

string Song::GetFirstLine()
{
    return firstLine;
}

void Song::SetPlayCount(int playCountToSet)
{
    playCount = playCountToSet;
}

int Song::GetPlayCount()
{
    return playCount;
}



