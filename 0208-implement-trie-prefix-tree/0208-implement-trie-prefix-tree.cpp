class Trie {
public:

    bool isLeaf;
    Trie* children[26];

    Trie() {

        isLeaf = false;
        for (int i = 0; i < 26 ; i++) {
            children[i] = nullptr;
        }
        
    }
    
    void insert(string word) {
        Trie* curr = this;

        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new Trie();
            }
            curr = curr->children[idx];
        }

        curr->isLeaf = true;
    }
    bool search(string word) {
        Trie* curr = this;

        for (char c : word) {
            int idx = c-'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        if (curr->isLeaf) {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;

        for (char c : prefix) {
            int idx = c-'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }

        return true;
        
    }
};