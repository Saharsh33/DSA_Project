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
This system provides a comprehensive solution for managing music libraries with smart recommendations...

## Features
### Core Functionality
- Music Library Management
- Playlist Creation & Editing
- Playback Queue
- Trie-Based Smart Search
- Artist Tokenization
- Persistent Storage

### Recommendation Engine
- Graph-based similarity
- Multi-factor scoring
- Trending detection
- Priority-based ranking
- Cached similarity graph

## Architecture
### Data Structures
| Structure | Purpose | Complexity |
|-----------|---------|------------|
| Doubly Linked List | Playlist operations | O(1) |
| Circular Queue | Playback queue | O(1) |
| Trie | Prefix search | O(m) |
| Hash Maps | Metadata indexing | O(1) |
| Graph Cache | Similarity matrix | O(1) |
| Max-Heap | Top-K recommendation | O(n log k) |

## Algorithms & Formulas

### 1. Cosine Similarity (Gi & Ai)
CosineSim(A, B) = (A · B) / (||A|| · ||B||)

### 2. Graph Edge Similarity
Sim = 0.5×GenreScore + 0.5×ArtistScore  
(GenreScore = 1 or 0.3, ArtistScore = 1 or 0.5)

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
(unchanged)

## Usage
(unchanged)

## Project Members
- Saharsh Thakor  
- Aditya Ranjan  
- Pal Vaghasiya  
- Vishwajeet Parmar

Repository: https://github.com/Saharsh33/CSL2020
