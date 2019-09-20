// Description: This program asks for a word and a letter to be used in a hangman style game. Where a new letter is asked
// in order to complete the word, where the rest is hidden with question marks.

#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
using namespace std;

void get_mask(string, string, string, char);

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
    update_mask(word, mask, question, letter);
}

//Gets mask over the word given, as well as changes the values of the mask based on the letter given
void get_mask(string word, string question, char letter){
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
}
