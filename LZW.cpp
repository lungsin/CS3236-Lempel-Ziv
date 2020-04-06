#include "LZW.h"
#include "utils.h"

#include <bits/stdc++.h>
using namespace std;

string LZW_encode(string input, map<pair<int, char> , int> &trie) {
  int largest_phrase_id = trie.size(), cur_node = 0, k_bit = 0;
  while ((1 << k_bit) <= largest_phrase_id) k_bit++;
  string codes;
  
  for (char c : input) {
    if (trie[{cur_node, c}]) {
      cur_node = trie[{cur_node, c}];
    } else {
      codes += toBinary(cur_node, k_bit);
      trie[{cur_node, c}] = (++largest_phrase_id);
      cur_node = trie[{0, c}];
      
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

string LZW_binary_encode(string input) {
  input = toBinary(input);
  
  map<pair<int, char> , int> trie; 
  trie[{0, '0'}] = 1;
  trie[{0, '1'}] = 2;
  return LZW_encode(input, trie);
}

string LZW_ascii_encode(string input) {
  map<pair<int, char> , int> trie; 
  for (int i = 0; i < 256; i++) {
    trie[{0, i}] = i + 1;
  }
  return LZW_encode(input, trie);
}
