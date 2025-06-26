#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i=0;i<26;i++)
                children[i] = NULL;
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word){ //because we doing it by recursion
            if(word.length()==0){
                root->isTerminal = true;
                return;
            }
            
            //Assuming words are in Capital Letters.
            int index = word[0] - 'A';
            TrieNode* child;

            //present
            if(root->children[index] != NULL){
                child = root->children[index];
            }
            //absent
            else{
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            //RECURSION
            insertUtil(child,word.substr(1));
        }

        void insertWord(string word){
            insertUtil(root,word);
        }

        bool searchUtil(TrieNode* root,string word){
            if(word.length()==0){
                return root->isTerminal;
            }
            
            //Assuming words are in Capital Letters.
            int index = word[0] - 'A';
            TrieNode* child;

            //present
            if(root->children[index] != NULL){
                child = root->children[index];
            }
            //absent
            else{
                return false;
            }

            //RECURSION
            return searchUtil(child,word.substr(1));
        }
        bool searchWord(string word){
            return searchUtil(root,word);
        }

        // DELETION
        // void del(TrieNode* root, string word){
        //     if(word.length() == 0){
        //         root->isTerminal = false;
        //         return;
        //     }
        
        //     int index = word[0] - 'A';
        //     TrieNode* child = root->children[index];
        
        //     if(child == NULL){
        //         // Word doesn't exist
        //         return;
        //     }
        
        //     del(child, word.substr(1));
        // }
        // void deleteWord(string word){
        //     del(root, word);
        // }
        

};

int main()
{
    Trie *t = new Trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    cout<<"Present Or Not: "<<t->searchWord("TIME")<<endl;
    cout<<"Present Or Not: "<<t->searchWord("TIM")<<endl;
    return 0;
}