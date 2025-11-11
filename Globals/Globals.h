#ifndef GLOBALS_H
#define GLOBALS_H

#include <bits/stdc++.h>
using namespace std;

struct Song//song structure
{
    int id;
    string title;
    string artist;
    string genre;
    long long play_count;
    double trending_score;
};
//global variables
extern vector<Song> songs;
extern string songsFile;
extern string playlistFile;
extern string graphCacheFile;
extern unordered_map<string, vector<int>> playlists;

extern unordered_map<string, int> genreIndex;
extern unordered_map<string, int> artistIndex;
extern int GENRE_DIM;
extern int ARTIST_DIM;

extern unordered_map<int, vector<pair<int, double>>> graph;

#endif