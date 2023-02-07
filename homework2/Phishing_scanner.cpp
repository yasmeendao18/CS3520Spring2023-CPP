// Yasmeen Dao
// 2/7/23 Finds phishing words in text

#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> 
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;


// function to check if word in file matches word in phishing word list
void findMatch(vector<string> &file_words, vector<int> &points, vector<string> &phish_words,vector<string> &found_phishword, vector<int> &count_phishword,vector<int> &phish_point)
{
  // iterate through file words
  for(int i=0; i < file_words.size(); i++)
  {
    // iterate through phish words
    for(int j=0; j<phish_words.size(); j++)
    {
      // if words are equal
        if(file_words[i] == phish_words[j])
        {
          // find the word
          if (std::find(found_phishword.begin(), found_phishword.end(), phish_words[j]) != found_phishword.end())
          {
            // create new variable 
            int temp = 0;
            temp = std::find(found_phishword.begin(), found_phishword.end(),  phish_words[j])-found_phishword.begin();
            // add it to the count
            count_phishword[temp]++;
          }
          else
            {
            // word not found
            found_phishword.push_back(phish_words[j]); 
            count_phishword.push_back(1);
            phish_point.push_back(points[j]); 
            }
        }
    }
  }
  cout<<endl;
}

int main() 
{
  /* pseudocode: 
   - list of phishing words
   - assign point to each for likliness to be in message
   - scans  a  file  of  text  for  these  terms  and  phrases. 
   - For  each  occurrence  of  a  keyword  or  phrase  within  the  text  file,       add  the  assigned point  value  to  the  total  points  for  that  word          or  phrase.  (total points = count*points)
  - For  each  keyword  or  phrase  found, output one line with the word or       
    phrase, the number of occurrences and the point total. Then 
    show the point total  for the entire  message.  
  */

  char token = ' ';
  string line;
  string words; 
  
  // vector for phishing words
  //std::vector<string> phish_words {"free", "Facebook", "high", "less", "ssn", "verify","account","secure","password","Google","name","verify","alert","immediate","password","attention","action","requires","urgent","number","expire","confirm","Chase","payPal","Microsoft","miss","update","now","protected","fraud"};


const char* args[] = {"free", "Facebook", "high", "less", "ssn", "verify","account","secure","password","Google","name","verify","alert","immediate","password","attention","action","requires","urgent","number","expire","confirm","Chase","payPal","Microsoft","miss","update","now","protected","fraud"};
std::vector<std::string> phish_words(args, args + sizeof(args)/sizeof(args[0]));
 
  // vector for points
  //std::vector<int> points {2,1,2,3,1,2,3,3,2,1,3,2,3,3,2,3,3,3,3,2,2,1,1,1,1,2,1,2,3,2};
vector<int> points;
points.push_back(2);
points.push_back(1);
points.push_back(2);
points.push_back(3);
points.push_back(1);
points.push_back(2);
points.push_back(3);
points.push_back(3);
points.push_back(2);
points.push_back(1);
points.push_back(3);
points.push_back(2);
points.push_back(3);
points.push_back(3);
points.push_back(2);
points.push_back(3);
points.push_back(3);
points.push_back(3);
points.push_back(3);
points.push_back(2);
points.push_back(2);
points.push_back(1);
points.push_back(1);
points.push_back(1);
points.push_back(1);
points.push_back(2);
points.push_back(1);
points.push_back(2);
points.push_back(3);
points.push_back(2);
  // store words from file in vector
  std::vector< string > file_words;
  std::vector< string > found_phishword;
  std::vector< int > count_phishword;
  std::vector< int > phish_point;
  int total_points = 0;
  string word; 

  // open file
  ifstream infile("in.txt");
  if (!infile) 
  {
    cout << "can't open the in file" << endl;
    return EXIT_FAILURE;
  }
  // loop through file
   while (getline(infile, line, '\n')) 
  {
    istringstream ss(line);
    while(getline(ss, words, token))
    {
      // remove punctuation
      for(int i = words.size()-1; i>=0; i--)
        {
          if(ispunct((words[i])))
          {
            // remove punctuation
            words.erase(i,1);
          }
        }
      // add to vector
      file_words.push_back(words);
    }
  }

   // print
  cout<<setw(10)<<"Word: "<<setw(15)<<"Count: "<< setw(15)<< "Points: "<<endl;

  // call function
  findMatch(file_words,points,phish_words,found_phishword,count_phishword,phish_point);
  
  //for all the found words
  for(int i = 0; i<count_phishword.size();i++)
    {
      cout<<setw(12)<<found_phishword[i]<<setw(10)<<count_phishword[i]<<setw(15)<<phish_point[i]<<endl;
      
    // calculate total points
    total_points+= count_phishword[i] * phish_point[i];
    }
   cout<<endl;
   cout<<"Total Points: "<<total_points<<endl;
return 0; 

}// end of main

/*

Questions:
The program doesn't assign an extremely high point total to some phishing e-mails I receieved because there are usually some spelling errors in the phishing email. It does assign a higher point total to legitimate e-mails because they usally use these key words to be professional. 

References:
https://cplusplus.com/reference/cctype/ispunct/

*/