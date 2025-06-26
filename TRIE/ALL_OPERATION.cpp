#include<iostream>
using namespace std;

class TrieNode{
    public:
        char val;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char val){
            this->val = val;
            for(int i=0;i<26;i++) children[i] = NULL;
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode('\0');
        }

        void ins(TrieNode* root,string word){
            if(word.length()==0){
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL){
                child = root->children[index];
            }
            else{
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            ins(child,word.substr(1));
        }
        void insert(string word){
            ins(root,word);
        }

        void del(TrieNode* root, string word){
            if(word.length() == 0){
                root->isTerminal = false;
                return;
            }
        
            int index = word[0] - 'A';
            TrieNode* child = root->children[index];
        
            if(child == NULL){
                // Word doesn't exist
                return;
            }
        
            del(child, word.substr(1));
        }
        void deleteWord(string word){
            del(root, word);
        }
        
        bool search(TrieNode* root, string word){
            if(word.length()==0){
                return root->isTerminal;
            }

            int index = word[0]-'A';
            TrieNode* child;

            if(root->children[index] != NULL){
                child = root->children[index];
            }
            else{
                return false;
            }

            return search(child,word.substr(1));
        }
        bool search(string word){
            return search(root,word);
        }

};

int main()
{
    Trie* t = new Trie();
    t->insert("ASHISH");
    t->insert("ROLAN");
    t->insert("ASHI");
    t->insert("ROLANDO");

    cout << (t->search("ROLAN") ? "Found" : "Not Found") << endl;
    cout << (t->search("ASHI") ? "Found" : "Not Found") << endl;
    cout << (t->search("ROLANDO") ? "Found" : "Not Found") << endl;
    cout << (t->search("UNKNOWN") ? "Found" : "Not Found") << endl;

    t->deleteWord("ROLAN");

    cout << (t->search("ROLAN") ? "Found" : "Not Found") << endl;

    return 0;
}
