// Finds word in paragraph and replaces
// Yasmeen Dao 1/24/23

#include <iostream>
using namespace std;

int main() {
  int i, find_word_count = 0;
  string par;
  string user_word;
  // position word is found
  size_t pos = 0;
  int count = 0;
  cout << "Enter paragraph: ";
  getline(cin, par);
  cout << par << endl;
  // check two or more words

  // prompt for user word
  cout << "Enter word to find: ";
  cin >> user_word;
  cout << user_word << endl;

  // validate user word
  if (user_word.length() < 2) {
    cout << "enter another word : " << endl;
    cin >> user_word;
  }
  while ((pos = par.find(user_word, pos)) != string::npos) {
    // get position that word is at
    cout << "Word found at position: " << pos << endl;
    pos += user_word.length();
    // count number of times word is found
    count++;
  }
  cout << "Word found " << count << " times" << endl;

  // get new user word
  string new_word;

  cout << "Enter another word ";
  cin >> new_word;
  // loop for every word that matches
  while ((pos = par.find(user_word)) != string::npos) {
    par.replace(pos, user_word.length(), new_word);
  }
  // print out paragraph with new word
  cout << par << endl;

} // end of main