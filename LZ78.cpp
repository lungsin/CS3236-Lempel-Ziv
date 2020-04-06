#include "LZ78.h"
#include "huffman.h"
#include "utils.h"

#include <bits/stdc++.h>
using namespace std;


string LZ78_binary_encode(string input) {
  input = toBinary(input);
  
  map<pair<int, char> , int> trie; 
  int largest_phrase_id = 0, cur_node = 0, k_bit = 0;
  string codes;
  
  for (char c : input) {
    if (trie[{cur_node, c}]) {
      cur_node = trie[{cur_node, c}];
    } else {
      codes += toBinary(cur_node, k_bit) + c;
      // codes += toBinary(cur_node, k_bit) + toBinary(c);
      trie[{cur_node, c}] = (++largest_phrase_id);
      cur_node = 0;
      
      // if k bit is not enough
      if ((1 << k_bit) <= largest_phrase_id) {
        k_bit++;
      }
    }
  }
  
  if (cur_node != 0) {
    codes += toBinary(cur_node, k_bit);
  }
  return codes;
}

string LZ78_ascii_encode(string input) {
  map<pair<int, char> , int> trie; 
  int largest_phrase_id = 0, cur_node = 0, k_bit = 0;
  string codes;
  
  for (char c : input) {
    if (trie[{cur_node, c}]) {
      cur_node = trie[{cur_node, c}];
    } else {
      // codes += toBinary(cur_node, k_bit) + c;
      codes += toBinary(cur_node, k_bit) + toBinary(c);
      trie[{cur_node, c}] = (++largest_phrase_id);
      cur_node = 0;
      
      // if k bit is not enough
      if ((1 << k_bit) <= largest_phrase_id) {
        k_bit++;
      }
    }
  }
  
  if (cur_node != 0) {
    codes += toBinary(cur_node, k_bit);
  }
  return codes;
}

string LZ78_ascii_huffman_encode(string input) {
  map<char, string> mapping;
  string encoded_tree;
  build_tree(input, mapping, encoded_tree);
  
  map<pair<int, char> , int> trie; 
  int largest_phrase_id = 0, cur_node = 0, k_bit = 0;
  string codes = encoded_tree;
  
  for (char c : input) {
    if (trie[{cur_node, c}]) {
      cur_node = trie[{cur_node, c}];
    } else {
      codes += toBinary(cur_node, k_bit) + mapping[c];
      trie[{cur_node, c}] = (++largest_phrase_id);
      cur_node = 0;
      
      // if k bit is not enough
      if ((1 << k_bit) <= largest_phrase_id) {
        k_bit++;
      }
    }
  }
  
  if (cur_node != 0) {
    codes += toBinary(cur_node, k_bit);
  }
  return codes;
}
