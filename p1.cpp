#include <iostream>
#include <tuple>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

bool IsLetters(string input)
{
  for (int i = 0; i < input.size(); i++)
  {
    int testedChar = input[i];
    if (testedChar < 'a' || testedChar > 'z')
    {
      return false;
    }
  }
  return true;
}


int main() {
  string word, filename;
  //defining the score for each letter
  map< char, int > mp;
  // map<char, int> ::iterator it;
  mp['a'] = 1, mp['e'] = 1 , mp['i'] = 1 , mp['o'] = 1, mp['u'] = 1 , mp['l'] = 1 , mp['n'] = 1  , mp['s'] = 1 , mp['t'] = 1 ,  mp['r'] = 1, mp['d'] = 2, mp['g'] = 2, mp['b'] = 3, mp['c'] = 3, mp['m'] = 3, mp['p'] = 3, mp['f'] = 4, mp['h'] = 4, mp['v'] = 4, mp['w'] = 4, mp['y'] = 4, mp['k'] = 5, mp['j'] = 8, mp['x'] = 8, mp['q'] = 10, mp['z'] = 10;

  vector<tuple<string, int>> data;

  ifstream f;
  filename = "data.txt";
  f.open(filename.c_str());
  while (f >> word)
  {
    if(IsLetters(word))
    {
      int wordScore = 0;
      for (int i=0; i < word.size(); i++) {
        char letter = word[i];
        int letterPoints =  mp.find(letter)->second;
        wordScore += letterPoints;
      }

      data.emplace_back(word, wordScore);

      // auto tp = std::make_tuple(word,wordScore);
      // cout << std::get<0>(tp) << " "<< std::get<1>(tp) << endl;
    }
  }
  //here we have a list of tuples in:   data

  cout<<"Found " << data.size() << " viable tuple(s)!" << endl;

  //to print this list to the screen
  tuple<string, int> viable;

  //open the file to write data
  ofstream myfile;
  myfile.open ("viable_data.txt");

  for (auto i = data.begin(); i!= data.end(); ++i)
  {
    viable = *i;
    myfile << std::get<0>(viable) <<" "<<std::get<1>(viable)<<"\n";
    cout <<"Word: " << std::get<0>(viable) << " ->  Score: " << std::get<1>(viable)<< endl;
  }

  //close files
  f.close();
  myfile.close();

  cout << "END";
}
