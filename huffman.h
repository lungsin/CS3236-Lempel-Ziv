#pragma once

#include <bits/stdc++.h>
using namespace std;

void build_tree(
    string input, map<char, string> &mapping, string &encoded_tree);
    
string huffman_encode(string input);
