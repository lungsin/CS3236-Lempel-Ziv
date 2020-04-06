#include <bits/stdc++.h>
using namespace std;

#include "utils.h"

struct Tree {
  char v;
  Tree *l, *r;
  
  Tree(char v): v(v), l(0), r(0) {}
  Tree(Tree *l, Tree *r): v(0), l(l), r(r) {}
  
  ~Tree() { delete l; delete r;}
};

void dfs(Tree *node, map<char, string> &mapping, string &encoded_tree,
      string cur = "") {
  if (node -> l == 0) {
    mapping[node -> v] = cur;
    encoded_tree += toBinary(node -> v);
    encoded_tree += toBinary(0);
  } else {
    dfs(node -> l, mapping, encoded_tree, cur + '0');
    dfs(node -> r, mapping, encoded_tree, cur + '1');  
  }
}

void build_tree(string input, 
    map<char, string> &mapping, string &encoded_tree) {
      
  map<char, int> freq;
  for (char c : input) freq[c] += 1;
  
  priority_queue<pair<int, Tree*> > pq;
  for (auto x : freq) {
    int frequency = x.second;
    char c = x.first;
    pq.push({-frequency, new Tree(c)});
  }
  
  while (pq.size() > 1) {
    auto a = pq.top(); pq.pop();
    auto b = pq.top(); pq.pop();
    Tree* merge = new Tree(a.second, b.second);
    pq.push({a.first + b.first, merge});
  }
  
  Tree *root = pq.top().second;
  dfs(root, mapping, encoded_tree);
  delete root;
}

string huffman_encode(string input) {
  map<char, string> mapping;
  string encoded_tree, codes;
  build_tree(input, mapping, encoded_tree);
  
  codes += encoded_tree;
  for (char c : input) {
    codes += mapping[c];
  }
  
  return codes;
}

