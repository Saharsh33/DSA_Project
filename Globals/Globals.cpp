#include "Globals.h"

vector<Song> songs;
string songsFile = "songs.txt";
string playlistFile = "playlists.txt";
string graphCacheFile = "graph_cache.dat";
unordered_map<string, vector<int>> playlists;

unordered_map<string, int> genreIndex;
unordered_map<string, int> artistIndex;
int GENRE_DIM = 0, ARTIST_DIM = 0;

unordered_map<int, vector<pair<int, double>>> graph;