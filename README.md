# Music Management & Recommendation System

A high-performance C++17 music management application featuring intelligent song recommendations powered by graph-based similarity algorithms, advanced data structures, and efficient caching mechanisms.

## Overview

This system provides a comprehensive solution for managing music libraries with smart recommendations. It combines multiple data structures and algorithms to deliver fast search, efficient playlist management, and personalized song suggestions based on listening patterns and metadata similarity.

## Features

### Core Functionality

- **Music Library Management**: Comprehensive storage and retrieval of song metadata including title, artist, genre, play count, and timestamps
- **Playlist Creation & Editing**: Full playlist management with add, remove, reorder, and merge operations
- **Dynamic Playback Queue**: Circular queue implementation enabling continuous playback with forward/backward navigation
- **Smart Prefix Search**: Trie-based autocomplete and search for instant song and artist lookup
- **Artist Tokenization**: Intelligent parsing of artist names supporting multiple artists per track
- **Persistent Storage**: Save and load songs and playlists between sessions

### Recommendation Engine

- **Graph-Based Similarity**: Precomputed pairwise song similarities cached to disk for instant access
- **Multi-Factor Analysis**: Considers artist overlap, genre matching, and play count patterns
- **Trending Detection**: Identifies popular songs using logarithmic play count weighting and time decay
- **Priority-Based Ranking**: Heap-based selection of top recommendations with distance-weighted scoring
- **Cache Optimization**: Disk-backed graph cache (`graph_cache.dat`) eliminates redundant computations

## Architecture

### Data Structures

The system leverages specialized data structures for optimal performance:

| Structure | Purpose | Complexity |
|-----------|---------|------------|
| **Doubly Linked List** | Playlist track ordering with bidirectional traversal | O(1) insert/delete |
| **Circular Queue** | Playback queue with wraparound capability | O(1) enqueue/dequeue |
| **Trie** | Prefix-based search indexing | O(m) lookup |
| **Hash Maps** | Fast metadata indexing and duplicate detection | O(1) average access |
| **Graph Cache** | Persistent similarity matrix storage | O(1) retrieval |
| **Priority Queue (Max-Heap)** | Top-K recommendation extraction | O(n log k) |

### Key Components

- **Globals**: Shared state and configuration management
- **Playlist Management**: Core playlist CRUD operations
- **PlaylistOps**: Advanced playlist operations (merge, shuffle, filter)
- **String Helpers**: Text processing utilities for search and comparison
- **Artist Tokenization**: Multi-artist parsing and normalization
- **SaveSong/SavePlaylist**: Persistence layer for data serialization
- **GraphCache**: Similarity matrix with lazy loading and write-back caching
- **Trie**: Autocomplete engine for search functionality
- **SearchFunc**: Query processing and result ranking
- **Recommendation**: Similarity calculation and ranking algorithms
- **Queue Management**: Playback queue operations
- **PlaySong**: Audio playback interface
- **QueueNavigation**: Queue traversal and position management

## Algorithms & Formulas

### 1. Song Similarity Calculation

The similarity between songs A and B is computed using a weighted combination of matching factors:

```math
\text{Similarity}(A, B) = w_1 \cdot \text{ArtistMatch} + w_2 \cdot \text{GenreMatch} + w_3 \cdot \left(1 - \frac{|\text{PlayCount}_A - \text{PlayCount}_B|}{\text{MaxPlayCount}}\right)
```

**Where:**
- `ArtistMatch` ∈ {0, 1} indicates whether songs share any artist
- `GenreMatch` ∈ {0, 1} indicates genre compatibility
- Weight coefficients satisfy: w₁ + w₂ + w₃ = 1
- PlayCount difference normalized by maximum play count in library

### 2. Score Normalization

All similarity values are normalized to the [0, 1] range for consistent comparison:

```math
\text{Norm}(x) = \frac{x - x_{\min}}{x_{\max} - x_{\min}}
```

This ensures fair ranking regardless of the scale of individual factors.

### 3. Trending Score

Trending songs are identified using a logarithmic popularity measure combined with time decay:

```math
\text{TrendingScore} = \alpha \cdot \log(1 + \text{PlayCount}) + \beta \cdot \text{RecencyFactor}
```

**Parameters:**
- `α`: Weight for popularity component (logarithmic to prevent over-emphasis on viral hits)
- `β`: Weight for recency component (exponential decay favors recently played tracks)
- `RecencyFactor`: Exponentially decreases with time since last play

### 4. Final Recommendation Score

The ranking combines similarity with graph distance to favor both similar and closely related songs:

```math
\text{RankFactor} = \frac{1}{1 + \text{Distance}}
```

```math
\text{FinalScore} = \text{Similarity} \cdot \text{RankFactor}
```

**Interpretation:**
- Higher `Similarity` indicates better content match
- Lower `Distance` in the song graph indicates stronger relationships
- `RankFactor` provides smooth distance penalty (approaches 1 for close songs, 0 for distant ones)

The top K songs with highest `FinalScore` are selected using a max-heap for efficient extraction.

## Build Instructions

### Prerequisites

- **Compiler**: GCC 7+, Clang 5+, or any C++17 compliant compiler
- **Operating System**: Windows, macOS, or Linux
- **Git**: For cloning the repository

### Compilation

#### macOS / Linux

```bash
# Clone the repository
git clone https://github.com/Saharsh33/CSL2020.git
cd CSL2020

# Compile with C++17 standard
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

# Run the application
./musicplayer
```

#### Windows

```powershell
# Clone the repository
git clone https://github.com/Saharsh33/CSL2020.git
cd CSL2020

# Compile with C++17 standard
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

# Run the application
.\musicplayer.exe
```
## Usage

The application provides an interactive command-line interface with the following operations:

1. **Library Management**: Add new songs, view library, update metadata
2. **Search**: Prefix-based search for songs and artists with autocomplete
3. **Playlists**: Create, edit, delete, and merge playlists
4. **Playback**: Play songs with queue management and navigation
5. **Recommendations**: Get personalized suggestions based on current song or listening history
6. **Trending**: View trending songs based on recent popularity
7. **Data Persistence**: Save and load your library and playlists

## Performance Characteristics

| Operation | Time Complexity | Notes |
|-----------|----------------|-------|
| Song Search | O(m) | m = query length (Trie) |
| Add to Playlist | O(1) | Doubly linked list append |
| Remove from Playlist | O(n) | Linear scan required |
| Get Recommendations | O(n log k) | n = library size, k = top-K |
| Similarity Lookup | O(1) | Graph cache hit |
| Trending Calculation | O(n log n) | Sorting by trending score |
| Queue Navigation | O(1) | Circular buffer operations |

## Data Files

The application generates the following data files:

- **`graph_cache.dat`**: Binary file storing precomputed similarity scores
- **`songs.dat`**: Serialized song metadata
- **`playlists.dat`**: Saved playlist configurations

These files enable persistence across sessions and reduce computation overhead.

## Project Members

- **Saharsh Thakor** - B24CS1105
- **Aditya Ranjan** - B24CM1004
- **Pal Vaghasiya** - B24CS1078
- **Vishwajeet Parmar** - B24CS1089

---