// Implement the Trie class with the following functions:

// insert(word): Inserts the string word into the trie.
// search(word): Returns true if word exists in the trie; otherwise returns false.
// isPrefix(word): Returns true if word is a prefix of at least one string stored in the trie; otherwise returns false.
// For input, the driver uses a 2D array query[][], where each query is one of the following:
// Type 1: [1, word] -> Calls insert(word).
// Type 2: [2, word] -> Calls search(word) and stores the returned value.
// Type 3: [3, word] -> Calls isPrefix(word) and stores the returned value.
// The output consists of the results of all Type 2 and Type 3 queries in the order they are processed.
class Trie {
public:
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;

            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->child[index] == NULL) {
                curr->child[index] = new Node();
            }

            curr = curr->child[index];
        }

        curr->isEnd = true;
    }

    bool search(string word) {
        Node* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->child[index] == NULL) {
                return false;
            }

            curr = curr->child[index];
        }

        return curr->isEnd;
    }

    bool isPrefix(string word) {
        Node* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->child[index] == NULL) {
                return false;
            }

            curr = curr->child[index];
        }

        return true;
    }
};