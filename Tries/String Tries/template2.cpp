const int letters = 26;

struct TrieNode {
    vector <int> children;
    int strings_ending_here;
    int strings_going_below;
    TrieNode() {
        children.resize(letters, -1);
        strings_ending_here = 0;
        strings_going_below = 0;
    }
};

struct Trie {
    vector <TrieNode> TrieTree;
    int sizeOfTrie = 0;
    
    Trie() {
        TrieTree.push_back(TrieNode());
        sizeOfTrie++;
    }

    void add(string word) {
        int currNode = 0;
        for (auto ch: word) {
            int index = ch-'a';
            if (TrieTree[currNode].children[index] == -1) {
                TrieTree[currNode].children[index] = sizeOfTrie;
                TrieTree.push_back(TrieNode());
                sizeOfTrie++;
            }
            currNode = TrieTree[currNode].children[index];
            TrieTree[currNode].strings_going_below++;
        }
        TrieTree[currNode].strings_ending_here++;
    }

    bool search(string word) {
        int currNode = 0;
        for (auto ch: word) {
            int index = ch-'a';
            if (TrieTree[currNode].children[index] == -1) 
                return false;
            currNode = TrieTree[currNode].children[index];
        }
        return TrieTree[currNode].strings_ending_here > 0;
    }

    void deleteS(string word) {
        if (search(word) == false) 
            return;
        int currNode = 0;
        for (auto ch: word) {
            int index = ch-'a';
            int child = TrieTree[currNode].children[index];
            TrieTree[child].strings_going_below--;
            if (TrieTree[child].strings_going_below == 0) 
                TrieTree[currNode].children[index] = -1;
            currNode = child;
        }
        TrieTree[currNode].strings_ending_here--;
    }    
};
