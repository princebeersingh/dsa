#include <iostream>
#include <array>

using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode {
public:
    array<TrieNode*, ALPHABET_SIZE> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {
        fill(children.begin(), children.end(), nullptr);
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    // Convert character to index ('a' -> 0, 'b' -> 1, ..., 'z' -> 25)
    int charToIndex(char ch) {
        return ch - 'a';
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = charToIndex(ch);
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

    // Search for a word in the Trie
    bool search(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = charToIndex(ch);
            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return current->isEndOfWord;
    }
};

int main() {
    Trie trie;

    // Insert words into the Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");

    // Search for words in the Trie
    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not found") << endl;
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not found") << endl;
    cout << "Search 'orange': " << (trie.search("orange") ? "Found" : "Not found") << endl;

    return 0;
}
