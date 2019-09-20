//Description: This program starts off with an unknown word hidden by question mask
//then finds each letter one at a time including multiples of a letter

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int get_mask(string word, char letter);
void update_mask(string word, string& mask, char letter);
bool guessed(string word, string mask);

int main() {
    string word = "abcfab";
    assert(get_mask(word,'a') == 34);
    assert(get_mask(word,'b') == 17);
    assert(get_mask(word,'c') == 8);
    assert(get_mask(word,'f') == 4);
    for (char c = 'A'; c <= 'z'; c++) {
        if (word.find(c) == string::npos) {
            assert(get_mask(word,c) == 0);
        }
    }
    
    string mask = "??????";
    assert(!guessed(word,mask));
    
    update_mask(word, mask, 'b');
    assert(mask == "?b???b");
    assert(!guessed(word,mask));
    
    update_mask(word, mask, 'd');
    assert(mask == "?b???b");
    assert(!guessed(word,mask));
    
    update_mask(word, mask, 'f');
    assert(mask == "?b?f?b");
    assert(!guessed(word,mask));
    
    update_mask(word, mask, 'c');
    assert(mask == "?bcf?b");
    assert(!guessed(word,mask));
    
    update_mask(word, mask, 'a');
    assert(mask == "abcfab");
    assert(guessed(word,mask));
    
    update_mask(word, mask, 'Z');
    assert(mask == "abcfab");
}

//Returns an integer indicating the location of where the letter appears in the string
int get_mask(string word, char letter) {
    int retval = 0;
    for (int i = 0; i < word.length(); i++) {
        retval = retval * 2;
        if (word[i] == letter) {
            retval++;
        }
    }
    return retval;
}

// Makes sure the word and mask are of the same length, and mask either has
// the same contents as word, or a '?' where it differs from word
// Also whenever a letter appears in word, the '?" in mask will be updated with letter
void update_mask(string word, string& mask, char letter) {
    assert(word.length() == mask.length());
    for (int i = 0; i < word.length(); i++) {
        assert(word[i] == mask[i] || mask[i] == '?');
    }
    int set_points = get_mask(word, letter);
    
    int n = mask.length() - 1;
    while (set_points > 0) {
        if (set_points % 2 == 1) {
            mask[n] = word[n];
        }
        n--;
        set_points /= 2;
    }
}

// Makes sure that the word and mask are of the same length
// Returns true if word and mask have the same contents, and false otherwise.
bool guessed(string word, string mask) {
    assert(word.length() == mask.length());
    return word == mask;
}

