class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isterminal;
    
    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
        children[i] = NULL;
        }
        isterminal = false;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        insertUtil(root,word);
    }
    
    bool search(string word) {
        return searchUtil(root,word);
    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(root,prefix);
    }
    
    
    void insertUtil(TrieNode* root, string word){
        if(word.size()==0){
            root->isterminal = true;
            return ;
        }
        
        // if present
        int index = word[0]-'a';
        TrieNode* child ;
        if(root->children[index]!= NULL){
            child = root->children[index];
        }
        
        // absent
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        insertUtil(child,word.substr(1));
    }
    
    bool searchUtil(TrieNode* root, string word){
        if(word.size()==0){
            return root->isterminal;
        }
        
        // present
        int index = word[0]-'a';
        TrieNode* child ;
        if(root->children[index]!= NULL){
            child = root->children[index];
        }
        // absent
        else{
            return false;
        }
        return searchUtil(child,word.substr(1));
    }
    
    bool startsWithUtil(TrieNode* root, string word){
        if(word.size()==0) return true;
        
        // present
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index]!= NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        return startsWithUtil(child,word.substr(1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */