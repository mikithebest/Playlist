/*
 Mikayla Cheng
 Song.h
 */

#ifndef Song_h
#define Song_h
#include <iostream>
#include <vector>
using namespace std;

class Song
{
public:
    Song();
    Song(string songNameToSet, string firstLineToSet);
    void SetName(string nameToSet);
    string GetName();
    void SetFirstLine(string firstLineToSet);
    string GetFirstLine();
    void SetPlayCount(int playCountToSet);
    int GetPlayCount();
    
private:
    string songName = "";
    string firstLine = "";
    int playCount = 0;
};
#endif
