# CSL2020 – Major Project  
**Data Structures & Algorithms**  
**Indian Institute of Technology Jodhpur**

## 📘 Introduction
This repository contains the **Major Project** for the course **CSL2020: Data Structures & Algorithms** at **IIT Jodhpur**.  
The project demonstrates the implementation of several fundamental and advanced **data structures**, **graph algorithms**, and **recommendation logic**, with a strong emphasis on correctness, efficiency, and modular design.

Our goal was to build a complete system that integrates:
- Efficient data storage using appropriate data structures  
- Smart traversal, searching, and sorting techniques  
- Mathematical modeling (trending score, recommendation ranking)  
- Graph theory concepts for similarity finding  

---

## 🚀 Project Highlights
- A complete music-management + recommendation system  
- Efficient playlist handling using **Doubly Linked Lists**  
- Song queues managed using **Circular Queues**  
- Artist token processing using **Hash Maps**  
- Graph-based recommendation system using **Adjacency Lists**, **BFS**, **Similarity Scoring**  
- Trending score calculation using mathematical normalization  

---

# **📂 Data Structures Used (With Purpose + Explanation + Formulas)**

## **1. Doubly Linked List (Playlist Management)**
Used to maintain a playlist where songs can be:
- Added efficiently  
- Removed efficiently  
- Traversed forward/backward  

### **Why this structure?**  
O(1) insertion & deletion when pointer is known.

### **Operations**
| Operation | Complexity |
|----------|------------|
| Insert at head/tail | O(1) |
| Delete a node | O(1) |
| Traverse | O(n) |

---

## **2. Circular Queue (Song Playing Queue)**
Used to maintain the **play queue**, ensuring:
- FIFO behavior  
- Constant-time insertion & deletion  
- Memory-efficient wrap-around  

### **Mathematical Model (Index Wrapping)**  
If `rear` moves past end:

\[
rear = (rear + 1) \mod capacity
\]

Same for `front`.

### **Complexities**
| Operation | Complexity |
|----------|------------|
| enqueue | O(1) |
| dequeue | O(1) |
| peek | O(1) |

---

## **3. Hash Map (Artist Tokenization + Song Lookup)**
Used to store:
- Artist → list of songs  
- Song title → song object  

### **Why Hash Map?**  
Average O(1) lookup.

### **Hashing Formula**
The polynomial rolling hash function:

\[
H(s) = (s_0 \cdot p^{0} + s_1 \cdot p^{1} + \ldots + s_{n-1} \cdot p^{n-1}) \mod m
\]

Common choices:  
`p = 31` or `53`, `m = 1e9+7`

---

## **4. Adjacency List Graph (Song Recommendation Engine)**  
Graph nodes = songs  
Edges = similarity based on:
- Artist  
- Genre  
- Play count  
- User interaction  

### **Why adjacency list?**  
Space-efficient for sparse graphs.

### **Similarity Edge Weight Formula**
We designed a similarity score between song *A* and *B* as:

\[
Similarity(A, B) = w_1 \cdot GenreMatch + w_2 \cdot ArtistMatch + w_3 \cdot f(PlayCount)
\]

Where:  
- `GenreMatch = 1 if same else 0`  
- `ArtistMatch = 1 if same else 0`  
- `f(PlayCount)` = normalized play difference:

\[
f = 1 - \frac{|P_A - P_B|}{\max(P)}
\]

This score is stored as edge weight.

---

## **5. Graph Traversal (BFS for Recommendations)**
Used to find recommended songs by exploring similar nodes.

### **BFS Traversal Formula**
Queue-driven exploration:

\[
Queue.push(start)  
\]
\[
while\ Queue\ not\ empty:\  
\quad node = Queue.pop()  
\quad push\ neighbors  
\]

BFS ensures closest (most similar) songs in the graph come first.

---

## **6. Heap / Priority Queue (Top-K Trending Songs)**
Trending songs sorted using **max-heap** based on trending score.

### **Trending Score Formula**
\[
TrendingScore = \alpha \cdot \log(1 + playcount) + \beta \cdot recencyFactor
\]

Used to pick **top K** songs efficiently with complexity:

\[
O(n \log K)
\]

---

# **📊 Algorithms Used (With Purpose)**

| Algorithm | Purpose | Complexity |
|----------|----------|------------|
| BFS | Graph-based recommendation | O(V + E) |
| Heap (priority queue) | Top-K trending | O(n log k) |
| Polynomial Hashing | Artist-token mapping | O(n) |
| Sorting (Quicksort / Mergesort variant) | Trending order | O(n log n) |
| Linked List ops | Playlist edit | O(1) |
| Queue ops | Play order | O(1) |

---

# **🧮 Mathematical Models Used**

## **1. Normalization Function**
Used to scale metrics (playcount, trending score):

\[
norm(x) = \frac{x - min(x)}{max(x) - min(x)}
\]

## **2. Weighted Similarity Score**
\[
Score = \sum_{i=1}^{n} w_i \cdot feature_i
\]

## **3. Logarithmic Popularity Adjustment**
\[
score = \log(1 + plays)
\]

Prevents large playcounts from overpowering small ones.

## **4. BFS Layer Distance**
Used to rank recommendations:

\[
Rank = \frac{1}{1 + Distance(level)}
\]

---

# 📁 Directory Structure
