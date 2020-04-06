#include <bits/stdc++.h>

#include "huffman.h"
#include "LZ78.h"
#include "LZW.h"
#include "utils.h"

using namespace std;

int main() {
  string filename;
  while (cin >> filename) {
    ifstream ifs("data/" + filename);
    string content ((istreambuf_iterator<char>(ifs)), 
        (istreambuf_iterator<char>()));
    
    int num_of_char = content.size();
    int num_of_bits = num_of_char * 8;
    printf("Filename: %s\n", filename.c_str());
    printf("Content size: %d bits\n", num_of_bits);
    
    string huffman_code = huffman_encode(content);
    float huffman_compression_ratio = (float) huffman_code.size() / num_of_bits * 100.0;
    printf("Huffman Code: %.2f%% deflated\n", huffman_compression_ratio);
    writeCodesToFile(huffman_code, "output/" + filename + ".huffman");
    
    string LZ78_binary_code = LZ78_binary_encode(content);
    float LZ78_binary_compression_ratio = (float) LZ78_binary_code.size() / num_of_bits * 100.0;
    printf("LZ78_binary Code: %.2f%% deflated\n", LZ78_binary_compression_ratio);
    writeCodesToFile(LZ78_binary_code, "output/" + filename + ".LZ78_binary");
    
    string LZ78_ascii_code = LZ78_ascii_encode(content);
    float LZ78_ascii_compression_ratio = (float) LZ78_ascii_code.size() / num_of_bits * 100.0;
    printf("LZ78_ascii Code: %.2f%% deflated\n", LZ78_ascii_compression_ratio);
    writeCodesToFile(LZ78_ascii_code, "output/" + filename + ".LZ78_ascii");
    
    string LZ78_ascii_huffman_code = LZ78_ascii_huffman_encode(content);
    float LZ78_ascii_huffman_compression_ratio = (float) LZ78_ascii_huffman_code.size() / num_of_bits * 100.0;
    printf("LZ78_ascii_huffman Code: %.2f%% deflated\n", LZ78_ascii_huffman_compression_ratio);
    writeCodesToFile(LZ78_ascii_huffman_code, "output/" + filename + ".LZ78_ascii_huffman");
    
    string LZW_binary_code = LZW_binary_encode(content);
    float LZW_binary_compression_ratio = (float) LZW_binary_code.size() / num_of_bits * 100.0;
    printf("LZW_binary Code: %.2f%% deflated\n", LZW_binary_compression_ratio);
    writeCodesToFile(LZW_binary_code, "output/" + filename + ".LZW_binary");
    
    string LZW_ascii_code = LZW_ascii_encode(content);
    float LZW_ascii_compression_ratio = (float) LZW_ascii_code.size() / num_of_bits * 100.0;
    printf("LZW_ascii Code: %.2f%% deflated\n", LZW_ascii_compression_ratio);
    writeCodesToFile(LZW_ascii_code, "output/" + filename + ".LZW_ascii");
    
    puts("================");
  }
}
