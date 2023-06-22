class Solution {
public:

    // declare a structure for TrieNode

    struct TrieNode
    {
        bool is_end;

        string word;

        TrieNode* child[26];

        TrieNode()
        {
            is_end = false;

            word = "";

            for(int i = 0; i < 26; i++)
            {
                child[i] = NULL;
            }
        }
    };

    // declare root of the Trie

    TrieNode* root = new TrieNode();

    // function for inserting word into Trie

    void insert(string& str)
    {
        int n = str.size();

        TrieNode* curr = root;

        for(int i = 0; i < n; i++)
        {
            int idx = str[i] - 'a';

            // if no subtree is present then insert the new node

            if(curr -> child[idx] == NULL)
            {
                curr -> child[idx] = new TrieNode();
            }

            curr = curr -> child[idx];
        }

        // update is_end and word

        curr -> is_end = true;

        curr -> word = str;
    }

    // dfs function

    vector<string> res;

    // direction co-ordinates of all four directions

    vector<int> dx = {-1, 0, 1, 0};

    vector<int> dy = {0, 1, 0, -1};

    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m, TrieNode* curr)
    {
        // base case
         
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '#')
        {
            return;
        }

        int idx = grid[i][j] - 'a';

        // if there is no word starting with curr character then return

        if(curr -> child[idx] == NULL)
        {
            return;
        }

        // move curr

        curr = curr -> child[idx];

        // if we found a word

        if(curr -> is_end)
        {
            res.push_back(curr -> word);

            // mark is_end with false to avoid duplicate result

            curr -> is_end = false;
        }

        // store the val of curr cell

        char val = grid[i][j];

        // mark the curr cell visited

        grid[i][j] = '#';

        // explore all the four directions

        for(int k = 0; k < 4; k++)
        {
            int new_i = i + dx[k];

            int new_j = j + dy[k];

            // call dfs

            dfs(grid, new_i, new_j, n, m, curr);
        }

        // backtrack

        grid[i][j] = val;
    }
    
    vector<string> findWords(vector<vector<char>>& grid, vector<string>& words) {
        
        int n = grid.size();
        
        int m = grid[0].size();

        // insert all the words into trie

        for(auto word : words)
        {
            insert(word);
        }

        // start dfs from all the cell and find possible result

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                dfs(grid, i, j, n, m, root);
            }
        }

        return res;
    }
};