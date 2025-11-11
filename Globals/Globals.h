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

#endif