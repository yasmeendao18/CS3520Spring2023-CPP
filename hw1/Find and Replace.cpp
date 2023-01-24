#include <iostream>
using namespace std;

// Write a program that reads a paragraph from the keyboard and then finds a
// given word. User may provide that word from keyboard (which should have
///// length of 2 or more characters).////////

int main() {
  int i, find_word_count = 0;
  string par;
  string user_word;
  // position word is found
  int pos;

  cout << "Enter paragraph: ";
  getline(cin, par);
  cout << par << endl;
  // check two or more words

  // prompt for user word
  cout << "Enter word to find: ";
  cin >> user_word;
  cout << user_word << endl;

  for (i = 0; par[i] != '\0'; ++i) {
    if (par.compare(user_word) == 0) {
      // find word
      find_word_count += 1;
      // find position
      pos = par.find(user_word);
      cout << user_word << " found at position " << pos << endl;
    }
  } // end of for
  cout << user_word << " found " << find_word_count << " times" << endl;

  // Replace the word you were searching for with a new user-provided word and
  // print the new
  //  paragraph neatly.

  // get new user word
  string new_word;

  cout << "Enter another word ";
  cin >> new_word;
  par.replace(par.find(user_word), user_word.length(), new_word);
  // print out paragraph with new word
  cout << par << endl;

} // end of main