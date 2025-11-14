# Music Management & Recommendation System
![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![Build](https://img.shields.io/badge/build-passing-brightgreen.svg)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)
![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Contributions](https://img.shields.io/badge/contributions-welcome-orange.svg)
![Project Status](https://img.shields.io/badge/status-active-success.svg)

A high-performance C++17 music management application featuring intelligent song recommendations powered by graph-based similarity algorithms, advanced data structures, and efficient caching mechanisms.

**CSL2020 Data Structures & Algorithms - Major Project**  
*Indian Institute of Technology Jodhpur*

## Overview
This system provides a comprehensive solution for managing music libraries with smart recommendations. It combines multiple data structures and algorithms to deliver fast search, efficient playlist management, and personalized song suggestions based on listening patterns and metadata similarity.

## Features

### Core Functionality
- Music Library Management
- Playlist Creation & Editing
- Dynamic Playback Queue
- Smart Prefix Search using Trie
- Artist Tokenization & Multi-Artist Support
- Persistent Storage for Songs & Playlists

### Recommendation Engine
- Graph-based similarity  
- Multi-factor scoring system  
- Trending score computation  
- Top-K ranking using max-heap  
- Cached graph for instant lookup  

## Architecture

### Data Structures Used
| Structure | Purpose | Complexity |
|----------|---------|------------|
| Doubly Linked List | Playlist operations | O(1) |
| Circular Queue | Playback queue | O(1) |
| Trie | Fast prefix search | O(m) |
| Hash Maps | Metadata indexing | O(1) |
| Graph (Adjacency List) | Song similarity graph | O(V+E) |
| Max-Heap | K-best recommendation extraction | O(n log k) |
| Binary File Cache | Graph persistence | O(1) load/access |

### Main Components
- Globals  
- Playlist Management  
- PlaylistOps  
- String Helpers  
- Artist Tokenization  
- SaveSong / SavePlaylist  
- GraphCache  
- Trie (Autocomplete)  
- SearchFunc  
- Recommendation  
- QueueManagement  
- PlaySong  
- QueueNavigation  

## Algorithms & Formulas (Exact Implementation)

### 1. Cosine Similarity (Gi & Ai)
CosineSim(A, B) = (A · B) / (||A|| · ||B||)

### 2. Graph Edge Similarity
Sim = 0.5×GenreScore + 0.5×ArtistScore  
GenreScore = 1 or 0.3  
ArtistScore = 1 or 0.5  

### 3. Graph Similarity (Ci)
Ci = EdgeWeight(cur,i) / Wmax

### 4. Popularity Score (Pn)
Pn = log(1+PlayCount) / log(1+Pmax)

### 5. Trending Score (Ti)
Ti = TrendingScore_i / Tmax

### 6. Diversity Score (Di)
Di = 1 - (0.5Gi + 0.5Ai)

### 7. Final Recommendation Score (S)
S = 0.20Ci + 0.10Pn + 0.15Gi + 0.35Ai + 0.10Di + 0.10Ti

## Build Instructions

### Prerequisites
- GCC 7+, Clang 5+, MinGW, MSVC (C++17 support)
- Windows / Linux / macOS
- Git installed

### macOS / Linux
git clone https://github.com/Saharsh33/CSL2020.git
cd CSL2020
g++ -std=c++17 main.cpp \
    Globals/Globals.cpp \
    playlist_management/playlist_managment.cpp \
    PlaylistOps/PlaylistOps.cpp \
    String_helpers/String_helpers.cpp \
    Artist_Tokenization/Artist_tokenization.cpp \
    SaveSong/SaveSong.cpp \
    SavePlaylist/SavePlaylist.cpp \
    GraphCache/GraphCache.cpp \
    Trie/Trie.cpp \
    SearchFunc/SearchFunc.cpp \
    Recommendation/Recommendation.cpp \
    Queue_Management/QManage.cpp \
    PlaySong/PlaySong.cpp \
    QueueNavigation/QNav.cpp \
    -o musicplayer
./musicplayer

### Windows
git clone https://github.com/Saharsh33/CSL2020.git
cd CSL2020
g++ -std=c++17 main.cpp `
    Globals/Globals.cpp `
    playlist_management/playlist_managment.cpp `
    PlaylistOps/PlaylistOps.cpp `
    String_helpers/String_helpers.cpp `
    Artist_Tokenization/Artist_tokenization.cpp `
    SaveSong/SaveSong.cpp `
    SavePlaylist/SavePlaylist.cpp `
    GraphCache/GraphCache.cpp `
    Trie/Trie.cpp `
    SearchFunc/SearchFunc.cpp `
    Recommendation/Recommendation.cpp `
    Queue_Management/QManage.cpp `
    PlaySong/PlaySong.cpp `
    QueueNavigation/QNav.cpp `
    -o musicplayer.exe
.\musicplayer.exe

### Single-Line Build
g++ -std=c++17 main.cpp Globals/Globals.cpp playlist_management/playlist_managment.cpp PlaylistOps/PlaylistOps.cpp String_helpers/String_helpers.cpp Artist_Tokenization/Artist_tokenization.cpp SaveSong/SaveSong.cpp SavePlaylist/SavePlaylist.cpp GraphCache/GraphCache.cpp Trie/Trie.cpp SearchFunc/SearchFunc.cpp Recommendation/Recommendation.cpp Queue_Management/QManage.cpp PlaySong/PlaySong.cpp QueueNavigation/QNav.cpp -o musicplayer && ./musicplayer

## Usage
The application provides an interactive CLI offering:
1. Add / view / edit songs  
2. Prefix-based search  
3. Playlist creation & editing  
4. Playback system with next/previous navigation  
5. Smart Recommendations  
6. Trending Songs  
7. Data saving and loading  

## Project Members
- Saharsh Thakor — B24CS1105  
- Aditya Ranjan — B24CM1004  
- Pal Vaghasiya — B24CS1078  
- Vishwajeet Parmar — B24CS1089  

## Repository
https://github.com/Saharsh33/CSL2020
