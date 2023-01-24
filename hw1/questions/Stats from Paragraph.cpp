// Stats from a paragraph

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {

  int i, word_count = 1;
  string par;
  int consonant = 0;
  int vowel = 0;
  int start_vowel = 0;
  int punct = 0;
  int vowel_start = 0;
  bool vow_bool = true;

  // get user paragraph
  cout << "Enter paragraph: ";
  getline(cin, par);
  // cout << par << endl;

  // Print number of total words
  for (i = 0; par[i] != '\0'; ++i) {
    // check first word
    if (i == 0) {
      // if the first word is a vowel
      if (par[i] == 'a' || par[i] == 'e' || par[i] == 'i' || par[i] == 'o' ||
          par[i] == 'u' || par[i] == 'A' || par[i] == 'E' || par[i] == 'I' ||
          par[i] == 'O' || par[i] == 'U') {
        vowel_start++; // add to count
      }
    }
    // check for spaces
    if (par[i] == ' ') {
      // if character is space, indicates word
      word_count++;
      if (par[i + 1] == 'a' || par[i + 1] == 'e' || par[i + 1] == 'i' ||
          par[i + 1] == 'o' || par[i + 1] == 'u' || par[i + 1] == 'A' ||
          par[i + 1] == 'E' || par[i + 1] == 'I' || par[i + 1] == 'O' ||
          par[i + 1] == 'U') {
        vowel_start++; // add to count
      }
    }
    // print number of words that have punctuation attached
    else if (par[i] == '!' || par[i] == '$' || par[i] == '.' || par[i] == ',' ||
             par[i] == ';' || par[i] == '"' || par[i] == '?' ||
             par[i] == '\'') {
      punct += 1;
    }
    // print number of vowels and consonants
    else if (par[i] == 'a' || par[i] == 'e' || par[i] == 'i' || par[i] == 'o' ||
             par[i] == 'u' || par[i] == 'A' || par[i] == 'E' || par[i] == 'I' ||
             par[i] == 'O' || par[i] == 'U') {
      vowel += 1;
      // created boolean just to check in test cases
      vow_bool = true;
    } else {
      // letter is consonant
      consonant += 1;
      vow_bool = false;
    }

  } // end of for

  // print
  cout << "there are " << word_count << " words in paragraph" << endl;
  cout << vowel << " vowels" << endl;
  cout << consonant << " consonants" << endl;
  cout << punct << " word(s) with punctuation" << endl;
  cout << vowel_start << " word(s) that start with vowel" << endl;

  // Now, prompt the user to enter a number (i.e., length of a word) and then
  // calculate {and   // print} the following:Number of words with length
  // GREATER than the user provided length.
  /*
    int num; // length of word
    int len_greater = 0;
    int wordlength = 0;
    // ask user to enter number
    cout << "Enter a number: ";
    cin >> num;
    for (i = 0; par[i] != '\0'; ++i) {
      if (par[i] == ' ') {
        if (wordlength > num) {
          len_greater++;
        }
        wordlength = 0;
      } else {
        wordlength++;
      }
    }
    if (wordlength > num) {
      len_greater++;
    }

    // print
    cout << len_greater << " words greater than " << num << endl;
  */
  // Now, update your program to automatically select a random number between
  // [6-10] and print:Number of words with length smaller than the random
  // length.
  int ran_num;
  cout << ran_num << endl;
  int len_smaller;
  int wordslength = 0;
  ran_num = 6 + (rand() % 10;
  cout << ran_num;
  for (i = 0; par[i] != '\0'; ++i) {
    if (par[i] == ' ') {
      if (wordslength < ran_num) {
        len_smaller++;
      }
      wordslength = 0;
    } else {
      wordslength++;
    }
  }
  if (wordslength < ran_num) {
    len_smaller++;
  }
  // print
  cout << len_smaller << " words smaller than " << ran_num << endl;

  return 0;

} // end of main

// Didn't make functions but next time would create function that determined if
// letter was a vowel