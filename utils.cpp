#include "utils.h"
#include <bits/stdc++.h>

using namespace std;

string toBinary(char c) {
  string res;
  for (int i = 0; i < 8; i++) {
    int bit = ((1 << i) & c) > 0 ? 1 : 0;
    res += (char) bit + '0';
  }
  return res;
}

string toBinary(string s) {
  string res;
  for (char c : s) {
    res += toBinary(c);
  }
  return res;
}

string toBinary(int number, int k_bit) {
  string res;
  for (int i = 0; i < k_bit; i++) {
    int bit = ((1 << i) & number) > 0 ? 1 : 0;
    res += bit + '0';
  }
  return res;
}

char toChar(string b) {
  int res = 0;
  for (int i = 0; i < 8; i++) {
    res += (1 << i) * (b[i] - '0');
  }
  return res;
}

void writeCodesToFile(string s, string filename) {
  ofstream ofs(filename);
  ofs << s;
}

char getSymbol(stringstream ss) {
  int res = 0;
  for (int i = 0; i < 8; i++) {
    char c; ss >> c;
    res += (1 << i) * (c - '0');
  }
  return res;
}
