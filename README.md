# Music Management & Recommendation System

A high-performance C++17 application for managing music libraries and generating intelligent song recommendations using advanced data structures and graph-based similarity algorithms.

## Features

### Core Functionality
- **Song Storage & Metadata Management**: Efficient storage and retrieval of song information including title, artist, genre, and play statistics
- **Playlist Management**: Create, edit, and organize custom playlists with full CRUD operations
- **Playback Queue**: Circular queue implementation for seamless continuous playback
- **Smart Search**: Trie-based prefix search for ultra-fast song and artist lookups
- **Artist Tokenization**: Intelligent parsing and indexing of artist names for improved search accuracy

### Recommendation Engine
- **Graph-Based Similarity**: Precomputed similarity scores cached to disk (`graph_cache.dat`) for instant recommendations
- **Multi-Factor Ranking**: Weighted algorithm considering artist overlap, genre matching, and play count patterns
- **Trending Analysis**: Dynamic trending score calculation based on popularity and recency
- **Top-K Recommendations**: Priority queue-based selection of most relevant songs

## Data Structures

The system leverages multiple advanced data structures for optimal performance:

- **Doubly Linked List**: Playlist and queue management with bidirectional traversal
- **Circular Queue**: Efficient playback queue with O(1) enqueue/dequeue operations
- **Trie**: Prefix-based search with O(m) lookup time where m is query length
- **Hash Maps**: Fast metadata indexing and retrieval
- **Graph Cache**: Disk-backed similarity matrix for persistent storage
- **Priority Queue (Heap)**: Top-K recommendation selection in O(n log k) time

## Algorithms

### Song Similarity Calculation

The similarity between two songs A and B is computed using a weighted multi-factor formula:

```math
\text{Similarity}(A, B) = w_1 \cdot \text{ArtistMatch} + w_2 \cdot \text{GenreMatch} + w_3 \cdot \left(1 - \frac{|\text{PlayCount}_A - \text{PlayCount}_B|}{\text{MaxPlayCount}}\right)
```

Where:
- `ArtistMatch` ∈ {0, 1} indicates artist overlap
- `GenreMatch` ∈ {0, 1} indicates genre match
- `w₁, w₂, w₃` are tunable weight parameters (w₁ + w₂ + w₃ = 1)

### Score Normalization

All similarity scores are normalized to [0, 1] range:

```math
\text{Norm}(x) = \frac{x - x_{\min}}{x_{\max} - x_{\min}}
```

### Trending Score

Trending songs are identified using play count and recency:

```math
\text{TrendingScore} = \alpha \cdot \log(1 + \text{PlayCount}) + \beta \cdot \text{RecencyFactor}
```

Where:
- `α` controls the weight of popularity
- `β` controls the weight of recency
- `RecencyFactor` decreases exponentially with time since last played

### Final Recommendation Score

The final ranking combines similarity with graph distance:

```math
\text{RankFactor} = \frac{1}{1 + \text{Distance}}
```

```math
\text{FinalScore} = \text{Similarity} \cdot \text{RankFactor}
```

Higher scores indicate stronger recommendations. The top K songs are selected using a max-heap.

## Installation

### Prerequisites
- C++17 compatible compiler (GCC 7+, Clang 5+, or MSVC 2017+)
- Git

### Build Instructions

```bash
git clone https://github.com/Saharsh33/CSL2020.git
cd CSL2020
g++ -std=c++17 */*.cpp main.cpp -o CSL2020App
./CSL2020App
```

## Usage

Launch the application and follow the interactive menu to:
1. Add songs to your library
2. Create and manage playlists
3. Search for songs and artists
4. Get personalized recommendations
5. View trending tracks
6. Manage playback queue

## Performance

- **Search**: O(m) where m is query length (Trie-based)
- **Recommendations**: O(n log k) where n is library size and k is number of recommendations
- **Playlist Operations**: O(1) for add/remove with doubly linked list
- **Similarity Lookup**: O(1) with graph cache

## Authors

- **Aditya Ranjan**
- **Saharsh**

## License

This project is part of the CSL2020 coursework.

---

**Repository**: [https://github.com/Saharsh33/CSL2020](https://github.com/Saharsh33/CSL2020)