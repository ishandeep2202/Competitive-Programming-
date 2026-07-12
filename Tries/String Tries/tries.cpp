#include <bits/stdc++.h>

using namespace std;

/*
Operations - 
1. Insert a word
2. Count number of words
3. Count number of prefix 
4. remove a word
*/

class Node {
public:
    vector <Node*> childs;
    int pre_count;
    int word_count;
    Node() : childs{26, nullptr}, pre_count{0}, word_count{0} {}
};

class Trie {
    Node* root;
public:
    Trie(): root{new Node()} {};
    void insert_word(const string& word) {
        Node* node = root;
        for (auto &ch: word) {
            if (!node->childs[ch-'a']) {
                node->childs[ch-'a'] = new Node();
            }
            node = node->childs[ch-'a'];
            node->pre_count++;
        }
        node->word_count++;
    }
    int count_word(const string& word) {
        Node* node = root;
        for (auto &ch: word) {
            if (!node->childs[ch-'a']) {
                return 0;
            }
            node = node->childs[ch-'a'];
        }
        return node->word_count;
    }
    int count_prefix(const string& word) {
        Node* node = root;
        for (auto &ch: word) {
            if (!node->childs[ch-'a']) {
                return 0;
            }
            node = node->childs[ch-'a'];
        }
        return node->pre_count;
    }
    bool contains_word(const string& word) {
        return count_word(word);
    }
    bool contains_prefix(const string&  word) {
        return count_prefix(word);
    }
    void remove_word(const string& word) {
        if (!contains_word(word)) return;
        Node* node = root;
        vector<pair<Node*, int>> path;
        for (char ch : word) {
            int idx = ch - 'a';
            path.push_back({node, idx});

            node = node->childs[idx];
            node->pre_count--;
        }
        node->word_count--;
        for (int i = path.size() - 1; i >= 0; i--) {
            Node* parent = path[i].first;
            int idx = path[i].second;
            Node* child = parent->childs[idx];
            if (child->pre_count == 0) {
                delete child;
                parent->childs[idx] = nullptr;
            }
            else {
                break;
            }
        }
    }
};

#include <bits/stdc++.h>
using namespace std;

int main() {
    Trie trie;

    cout << boolalpha;   

    cout << "========== EMPTY TRIE TEST ==========\n";
    cout << "search(\"apple\")      : " << trie.contains_word("apple") << '\n';
    cout << "startsWith(\"app\")   : " << trie.contains_prefix("app") << '\n';

    cout << "\n========== INSERT TEST ==========\n";

    trie.insert_word("apple");
    trie.insert_word("app");
    trie.insert_word("bat");
    trie.insert_word("ball");
    trie.insert_word("banana");
    trie.insert_word("cat");
    trie.insert_word("dog");

    cout << "Inserted:\n";
    cout << "apple app bat ball banana cat dog\n";

    cout << "\n========== SEARCH TEST ==========\n";

    cout << "search(\"apple\")   : " << trie.contains_word("apple") << '\n';
    cout << "search(\"app\")     : " << trie.contains_word("app") << '\n';
    cout << "search(\"bat\")     : " << trie.contains_word("bat") << '\n';
    cout << "search(\"banana\")  : " << trie.contains_word("banana") << '\n';

    cout << "\nWords that should NOT exist\n";
    cout << "search(\"ap\")       : " << trie.contains_word("ap") << '\n';
    cout << "search(\"apply\")    : " << trie.contains_word("apply") << '\n';
    cout << "search(\"balls\")    : " << trie.contains_word("balls") << '\n';
    cout << "search(\"cats\")     : " << trie.contains_word("cats") << '\n';

    cout << "\n========== PREFIX TEST ==========\n";

    cout << "startsWith(\"a\")      : " << trie.contains_prefix("a") << '\n';
    cout << "startsWith(\"ap\")     : " << trie.contains_prefix("ap") << '\n';
    cout << "startsWith(\"app\")    : " << trie.contains_prefix("app") << '\n';
    cout << "startsWith(\"appl\")   : " << trie.contains_prefix("appl") << '\n';
    cout << "startsWith(\"b\")      : " << trie.contains_prefix("b") << '\n';
    cout << "startsWith(\"ba\")     : " << trie.contains_prefix("ba") << '\n';
    cout << "startsWith(\"ban\")    : " << trie.contains_prefix("ban") << '\n';
    cout << "startsWith(\"cat\")    : " << trie.contains_prefix("cat") << '\n';
    cout << "startsWith(\"do\")     : " << trie.contains_prefix("do") << '\n';

    cout << "\nPrefixes that should NOT exist\n";
    cout << "startsWith(\"z\")      : " << trie.contains_prefix("z") << '\n';
    cout << "startsWith(\"cae\")    : " << trie.contains_prefix("cae") << '\n';
    cout << "startsWith(\"baz\")    : " << trie.contains_prefix("baz") << '\n';

    cout << "\n========== COUNT TEST ==========\n";

    trie.insert_word("apple");
    trie.insert_word("apple");
    trie.insert_word("app");

    cout << "countWordsEqualTo(\"apple\") = "
         << trie.count_word("apple") << '\n';

    cout << "countWordsEqualTo(\"app\") = "
         << trie.count_word("app") << '\n';

    cout << "countWordsStartingWith(\"app\") = "
         << trie.count_prefix("app") << '\n';

    cout << "countWordsStartingWith(\"ba\") = "
         << trie.count_prefix("ba") << '\n';
    

    cout << "\n========== ERASE TEST ==========\n";

    trie.remove_word("apple");

    cout << "After erasing one apple\n";
    cout << "search(\"apple\") : "
         << trie.contains_word("apple") << '\n';

    trie.remove_word("app");

    cout << "search(\"app\") : "
         << trie.contains_word("app") << '\n';

    cout << "startsWith(\"app\") : "
         << trie.contains_prefix("app") << '\n';
    

    cout << "\n========== STRESS TEST ==========\n";

    vector<string> words = {
        "abc","abcd","abcde","abcdef",
        "xyz","xy","x","hello","hell","heaven","heavy"
    };

    for (auto &w : words)
        trie.insert_word(w);

    for (auto &w : words)
        cout << setw(10) << w << " -> "
             << trie.contains_word(w) << '\n';

    cout << "\n========== TEST COMPLETE ==========\n";

    return 0;
}
