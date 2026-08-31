class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};


class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {

        TrieNode* current = root;

        for (char ch : word) {

            int index = ch - 'a';

            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }

            current = current->children[index];
        }

        // Mark the end of the complete word
        current->isEnd = true;
    }

    bool search(string word) {

        TrieNode* current = root;

        for (char ch : word) {

            int index = ch - 'a';

            // Character path doesn't exist
            if (current->children[index] == nullptr) {
                return false;
            }

            current = current->children[index];
        }

        // Complete word must end here
        return current->isEnd;
    }

    bool startsWith(string prefix) {

        TrieNode* current = root;

        for (char ch : prefix) {

            int index = ch - 'a';

            // Prefix path doesn't exist
            if (current->children[index] == nullptr) {
                return false;
            }

            current = current->children[index];
        }

        // Prefix exists
        return true;
    }
};