#pragma once
#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    short children_count=0; 
    bool isEndOfWord=false;
};

TrieNode* getNewNode(void);
void insert(TrieNode*, string);
bool search(TrieNode*, string);
bool isEmpty(TrieNode*);
void all_words(TrieNode*, int ind, char buf[], string& res, const string& start, int* counter = new int(0));
TrieNode* remove(TrieNode*, string, int depth = 0);
