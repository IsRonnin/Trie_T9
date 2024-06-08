#include <iostream>
#include "Trie.h"

using namespace std;


TrieNode* getNewNode(void)
{

    struct TrieNode* pNode = new TrieNode;
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}



void insert(TrieNode* root, string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
       
        int index = key[i] - 'a';



        if (!node->children[index])
            node->children[index] = getNewNode();
        node = node->children[index];
        node->children_count++;
    }


    node->isEndOfWord = true;
}


bool search(struct TrieNode* root, string key)
{
    struct TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return false;

        node = node->children[index];
    }

    return (node != nullptr && node->isEndOfWord);
}


bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

TrieNode* remove(TrieNode* root, string key, int depth)
{

    if (!root)
        return nullptr;


    if (depth == key.size()) {

        if (root->isEndOfWord)
            root->isEndOfWord = false;
        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }

        return root;
    }
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }

    return root;
}


void all_words(TrieNode* start_root, int ind, char buf[], string& res, const string& start, int* counter) {
    if (start_root->isEndOfWord) {
       buf[ind] = '\0';
       res += to_string(*counter) + ": " + start + string(buf) + "\n";
       (*counter)++;
    }

    if(start_root->children_count == 0){
        return;
    }
    else {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (start_root->children[i]) {
                buf[ind] = 'a' + i;
                all_words(start_root->children[i], ind + 1, buf, res, start, counter);
            }
        }
    }
}