#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <cassert>
using namespace std;

int get_mask(string, char);
void update_mask(string, string, string, char);
bool guess(string, string, char);

int x = 0;

int main(){
    string question;
    string mask;
    string word;
    char letter;
    cout<<"Please give me a word: "<<endl;
    cin >> word;
    cout<<"Please give me a character: "<<endl;
    cin >> letter;
    get_mask(word, letter);
    update_mask(word, mask, question, letter);
}

int get_mask(string word, char letter){
    int mask = 0;
    //picks up letter location and creates mask value
    for(int i = 0; i < word.size(); i++){
        if (word[i] == letter){
            mask += pow(2, ((word.size() - i) - 1));
        }
    }
    return mask;
}

void update_mask(string word, string mask, string question, char letter){
    //first time in update_mask sets ? = to size of word in question
    if(x == 0){
        for(int i = 0; i < word.size(); i++){
            question += '?';
            x += 1;
        }
    }
    assert(question.size() == word.size());
    //Swaps ? from question with letter
    for(int i = 0; i < word.size(); i++){
        if (word[i] == letter){
            question[i] = word[i];
        }
    }
    //Shows locations of new chars and gets new char
    cout << question << endl;
    if(question != word){
        cout<<"Please give me a new character: "<< endl;
        cin >> letter;
    }
    //if the word isn't complete, calls functiona again
    if(question != word){
        update_mask(word, mask, question, letter);
    }
    guess(word, question);
}

bool guess(string word, string question){
    //makes sure the word length and mask length are the same
    assert(question.size() == word.size());
    //returns true is the contents of the strings are the same
    if(question == word){
        return true;
    }
    else{
        return false;
    }
}
