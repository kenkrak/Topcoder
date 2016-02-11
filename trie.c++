#include<iostream>
#include<map>
#include<set>
#include<string>
#include<algorithm>

using namespace std;
#define ALPHABET_SIZE (26)

class TrieNode {

    public:

    TrieNode(): suffixes(0),currStr(""),word(false) {}  //initializer lists
    void setIsWord() {
        word = true;
    }
    bool hasWord() {
        return word;
    }
    void incrementSuffixCount() {
        suffixes++;
    }
    void setCurrString(string s) {
        currStr = s;
    }
    string getCurrString() {
        return currStr;
    }
 std::map<char,TrieNode*> children;
    private:
       bool word;
       int suffixes;
       string currStr;

};

typedef std::map<char, TrieNode*>::iterator it_type;

bool insertString(TrieNode* root, string s) {
    string currString = "";
    TrieNode* temp = new TrieNode();
    int countLetters = 0;
    temp = root;

    for(char c: s) {
        currString+=c;
        temp->setCurrString(currString);

        TrieNode* nextNode = new TrieNode();
        countLetters++;
        if(!temp->children[c]) {
            temp->children[c] = nextNode;
            temp = nextNode;
        }
        else {
            if(temp->hasWord())
                return false;
            temp = temp->children[c];
        }
        if(s.length()==countLetters) {
            if(temp->hasWord())
                return false;
            temp->setIsWord();
        }
    }
    return true;
}

// bool doesSuffixExist(string s, TrieNode* root) {
//     TrieNode* temp = new TrieNode();
//     temp = root;
//     int strLen = s.length()-1;
//     int i=0;
//     while(strLen--) {
//         if(temp->hasWord() && strLen!=0)
//             return true;
//         temp = temp->children[s[i]];
//         i++;
//     }
//     return false;
// }

int main() {
    TrieNode *root = new TrieNode();
    int countLines, countDup;
    string failedStr;
    bool isBad = false;
    string s;
    cin>>countLines;

    while(countLines--) {
        cin>>s;
        bool p = insertString(root, s);
        if(!p && !isBad) {
          isBad = true;
          failedStr = s;
        }
    }

    if(isBad) {
        cout<<"BAD SET"<<endl<<failedStr<<endl;
    }
    else
        cout<<"GOOD SET"<<endl;
}
