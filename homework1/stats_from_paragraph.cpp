// Calculates Stats from Paragraph
// Yasmeen Dao 1/24/23

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {

  // variables
  int i, word_count = 1;
  string par;
  int consonant = 0;
  int vowel = 0;
  int start_vowel = 0;
  int punct = 0;
  int vowel_start = 0;
  bool vow_bool = true;
  int user_num; // length of word
  int len_greater = 0;
  int word_length = 0;
  int ran_num;
  int len_smaller = 0;
  int smaller_word_length = 0;

  // get user paragraph
  cout << "Enter paragraph: ";
  getline(cin, par);
  // cout << par << endl;

  /// Print number of total words///
  for (i = 0; par[i] != '\0'; ++i) {
    // check first word
    if (i == 0) {
      /// if the first word is a vowel///
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
    /// print number of words that have punctuation///
    else if (par[i] == '!' || par[i] == '$' || par[i] == '.' || par[i] == ',' ||
             par[i] == ';' || par[i] == '"' || par[i] == '?' ||
             par[i] == '\'') {
      punct += 1;
    }
    /// print number of vowels and consonants///
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

  // print outputs
  cout << "There are " << word_count << " words in paragraph" << endl;
  cout << vowel << " vowels" << endl;
  cout << consonant << " consonants" << endl;
  cout << punct << " word(s) with punctuation" << endl;
  cout << vowel_start << " word(s) that start with vowel" << endl;

  /// words with length GREATER than the user provided///
  // ask user to enter number
  cout << "Enter a number: ";
  cin >> user_num;
  // loop through characters
  for (i = 0; par[i] != '\0'; ++i) {
    if (par[i] == ' ') {
      // check if wordlength is greater than user number
      if (word_length > user_num) {
        len_greater++;
      }
      word_length = 0;
    } else {
      word_length++;
    }
  }
  if (word_length > user_num) {
    // checks next word to see if length is larger
    len_greater++;
  }
  cout << len_greater << " words greater than " << user_num << endl;

  /// Number of words with length smaller than the random///
  srand((int)time(0));
  // generate random numbers 6-10
  ran_num = 6 + (rand() % 5);
  cout << "Random number is " << ran_num << endl;
  // cout << ran_num << endl;
  //  loop through characters
  for (i = 0; par[i] != '\0'; ++i) {
    if (par[i] == ' ') {
      if (smaller_word_length < ran_num) {
        len_smaller++;
      }
      smaller_word_length = 0;
    } else {
      smaller_word_length++;
    }
  }
  if (smaller_word_length < ran_num) {
    // checks next word to see if length is smaller
    len_smaller++;
  }
  cout << len_smaller << " words smaller than " << ran_num << endl;
  return 0;

} // end of main

// Didn't make functions but next time would create function that determined if
// letter was a vowel and checked for punctuation
// would also break up each separate task into a function
