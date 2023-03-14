// Yasmeen Dao
// 2/13/23 Read words from file and get information

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// store vowels in global char
char vowels[10] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
// structure to store word information
struct WordInfo 
{
  string word; // actual word
  int count;   // number of occurances
  int length;  // length of word
};

// sort based on count
bool sort_count(const WordInfo &a, const WordInfo &b)
{
  return a.count > b.count;
}

// function vowel_counter
//  count the words that start with a vowel
int vowel_counter(map<string, int> word_list) 
{

  // container for words with vowels
  int counter = 0;
  std::map<string, int>::iterator iter = word_list.begin();
  for (iter = word_list.begin(); iter != word_list.end(); iter++) {
    string word = iter->first;
    for (int i = 0; i < 10; i++) {
      if (word[0] == vowels[i]) {
        counter += iter->second;
      }
    }
  }
  return counter;
}

// lowercase
char tolower(char low) {
  if (low <= 'Z' && low >= 'A')
    return low - ('Z' - 'z');
  return low;
}

// check if word starts with vowel
bool vowel_start(string wd) // string word
{
  bool is_vowel = false;
  for (int i = 0; i < 10; i++) {
    is_vowel =  wd[0] == vowels[i] || is_vowel;
  }
  return is_vowel;
}

// determine words with vowels less than length
int compare_word_length(vector<WordInfo> struct_words, int length) 
{
  vector<WordInfo> iter;
  int counter = 0;
  for (auto &iter : struct_words) {
    if (iter.length <= length) {
      counter++;
    }
  }
  return counter;
}

int main() {

  string usertext;
  cout << "Which file, 'small.txt' or 'large.txt' ? " << endl;
  cin >> usertext;
  cout << endl;
  // read input from file
  ifstream infile("./" + usertext);
  // ** have to type "small.txt or large.txt" or else won't open file
  if (!infile) {
    cout << "can't open the in file" << endl;
  }

  // create map to store all words
  map<string, int> word_list;

  map<string, int> unique_lower_words; // lower-case words unique

  string word;
  int count = 0;
  while (infile >> word) {
    string lower = word;
    word_list[word]++;
    count++;
    lower[0] = tolower(lower[0]);
    if (word_list.find(word) == word_list.end()) {
      word_list.insert(pair<string, int>(word, 1));
      unique_lower_words.insert(pair<string, int>(lower, 1));
    } else {
      // word_list[word]++;
      unique_lower_words[lower]++;
      
    }
  }

  int num_vowels = vowel_counter(word_list);
  ///////only want to print out words that start with vowel
  // declare vector for pairs
  vector<WordInfo> struct_words;
  map<string, int>::iterator i = word_list.begin();
  for (i = word_list.begin(); i != word_list.end(); i++) {
    // structure object
    WordInfo vowel_words;
    string a = i->first;
    int count = i->second;
    int length = a.length();
    vowel_words.word = a;
    vowel_words.count = count;
    vowel_words.length = length;

    // add words to vector
    struct_words.push_back(vowel_words);
  }

  vector<WordInfo>::iterator iter = struct_words.begin();
  sort(struct_words.begin(), struct_words.end(), sort_count);
  // print out information to outfile
  ofstream outfile("statistics.txt"); // open or overwrite
  if (!outfile) {
    cout << "can't open the out file" << endl;
    return EXIT_FAILURE;
  }

  // print total number of words
  outfile << usertext << " has " << count << " number of words" << endl;

  outfile << endl;
  outfile << usertext << " has " << num_vowels
          << " words that start with a vowel " << endl;
  // sort words by count
  sort(struct_words.begin(), struct_words.end(), sort_count);
  for (iter = struct_words.begin(); iter != struct_words.end(); iter++) 
  {
    // prints out the words that start with vowels
    if (vowel_start(iter->word)) {
      outfile << iter->word << "{Word Length:" << iter->length
              << "}:" << iter->count << endl;
    }
  }
  outfile << endl;

  // threshold for user to choose for distinct vowels and consonants both
  int thresh;
  cout<<"Enter threshold for distinct words: "<<endl;
  cin>>thresh;
  int num_below_equal = thresh; 
  int threshold = compare_word_length(struct_words, num_below_equal);
  outfile << usertext << " has " << threshold << " distinct words with length "
          << num_below_equal << " or less";
  outfile << endl; 

} // end of main

