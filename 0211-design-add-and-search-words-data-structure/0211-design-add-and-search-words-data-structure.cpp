class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_word;

    TrieNode() {
        is_word = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.count(c) == 0) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->is_word = true;
    }

    bool search_helper(TrieNode* node, string word, int index) {
        if (index == word.length()) {
            return node->is_word;
        }
        char c = word[index];
        if (c == '.') {
            for (auto& p : node->children) {
                if (search_helper(p.second, word, index+1)) {
                    return true;
                }
            }
            return false;
        } else {
            if (node->children.count(c) == 0) {
                return false;
            }
            return search_helper(node->children[c], word, index+1);
        }
    }

    bool search(string word) {
        return search_helper(root, word, 0);
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */