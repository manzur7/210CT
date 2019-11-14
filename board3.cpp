#include <iostream>
#include <cstdlib> //srand to get true random shuffles with random_shuffle
#include <ctime> //time
#include <bits/stdc++.h> //unordered_set //Fast element search (file too large) && o librarie 
#include <fstream> //file operations
#include <map>  //map & this is used for task 1 but i havent used it since i could not 
#include <vector> //instead of basic arrays
#include <algorithm> //random_shuffle 

using namespace std;

const size_t handSize = 7; //global constant //can be accessed in any funciton //size_t type
//size_t is the type returned by the sizeof operator and is widely used in the standard library to represent sizes and counts.


struct TILE{      //task 2 struct instead of class & matrice & fiecare element e o structura && class tile 
  char letter;
  int cMultiplier;
  int wMultiplier;

  //constructor pentru object orriented 
  TILE(){
    letter = '*'; //to see the entire board filled with star
    //letter = ' ';
    cMultiplier = 1;
    wMultiplier = 1;
  }

  //declare member functions
  void print();
  void print_board();

};

//define member functions outside of struct
void TILE::print(){
  cout<<letter<<" "<<cMultiplier<<" "<<wMultiplier;
}

void TILE::print_board(){
  cout<<"  "<<letter<< "  ";
}

int i,j,r;
TILE board[15][15]; //constructor is called and the board is generated '0' 1 1 for each tile

void generateStartingBoard(){
  for(i=0;i<15;i++){
    for(j=0;j<15;j++){
      if(  ((i == 0 || i == 14)  &&  (j == 0 || j == 7 || j == 14)) || (i == 7  &&  (j == 0 || j == 14)) )  {
        board[i][j].wMultiplier *= 3; //set triple word multiplier
    } else if( ((i == 0 || i == 7) && (j == 3 || j == 11)) || (i == 2 && (j == 6 || j == 8)) || (i == 3 && (j == 0 || j == 7 || j == 14)) || (i == 6 && (j == 2 || j == 6 || j == 8 || j == 12)) || (i == 8 && (j == 2 || j == 6 || j == 8 || j == 12)) || (i == 11 &&(j == 0 || j == 7 || j == 14)) || (i == 12 && (j == 6 || j == 8)) || (i == 14 && (j == 3 || j == 11))  ){
          board[i][j].cMultiplier *= 2; //set double character multiplier
    } else if( (i == 1 && (j == 1 || j == 13)) || (i == 2 && ( j == 2 || j == 12)) || (i == 3 && (j == 3 || j == 11)) || (i == 4 && (j == 4  || j == 10)) || (i == 7 && j == 7) || (i == 10 && (j == 4  || j == 10)) || (i == 11 && (j == 3 || j == 11)) || (i == 12 && (j == 2 || j == 12)) || (i == 13 && (j == 1 || j == 13))){
          board[i][j].wMultiplier *= 2; //set double word multiplier
    } else if( ((i == 1 || i == 13) && (j == 5 || j == 9)) || ( (i == 5 || i == 9) && (j == 1 || j == 5 || j == 9 || j == 13)) ){
          board[i][j].cMultiplier *= 3; //set triple character multiplie
    } else{
        //if none of the above are true, do nothing
        ;
      }
    }
  }
}


void printBoardDebugg(){ //this prints the task
  for(i=0;i<15;i++){
    for(j=0;j<15;j++){
      //cout<<i<<"-"<<j<<", ";
      //board[i][j].print();
      board[i][j].print_board();
    }
  cout<<" "<<endl;
  }
}
//end




//rest of tasks 
// i think i chose a structure that wasnt good enought to represent the board therefore i couldnt display it so i continued with the one i had by doing a bit of each task 
string filename, word;

// declaring set for storing string data-type
unordered_set <string> stringSet;


bool isValidWord(string key){
  //  find returns end iterator if key is not found,else it returns iterator to that key

  unordered_set <string>::const_iterator got = stringSet.find(key); //un set neordonat de stringuri care e mult mai rapid pentru gasire 
  if(got == stringSet.end()) // daca era array era mult mai mult de gasit 
    return false;
  else
  {
    cout<< "\t" << *got << " is a viable word\n";
    return true;
  }
  }

//some of task 5 

void generate_pool( vector<char>& pool )
{
  //init the pool of letters available
  int i = 0;// for looping
  for( i = 0; i < 12;i++)
        pool.push_back('E');
    for( i = 0; i < 9;i++)
    {
        pool.push_back('A');
        pool.push_back('I');
    }
    for( i = 0; i < 8;i++)
        pool.push_back('O');
    for( i = 0; i < 6;i++)
    {
        pool.push_back('N');
        pool.push_back('R');
        pool.push_back('T');
    }
    for( i = 0; i < 4;i++)
    {
        pool.push_back('L');
        pool.push_back('S');
        pool.push_back('U');
        pool.push_back('D');
    }
    for( i = 0; i < 3;i++)
        pool.push_back('G');

    for( i = 0; i < 2;i++)
    {
        pool.push_back('B');
        pool.push_back('C');
        pool.push_back('M');
        pool.push_back('P');
        pool.push_back('F');
        pool.push_back('H');
        pool.push_back('V');
        pool.push_back('W');
        pool.push_back('Y');
    }

  //just one of those
  pool.push_back('K');
  pool.push_back('J');
  pool.push_back('X');
  pool.push_back('Q');
  pool.push_back('Z');

  //using built-in random generator to shuffle the letters
  random_shuffle( pool.begin(), pool.end() );

  return; //returns nothing
}

void fillHand(vector<char>& pool, vector<char>& hand)
{
  while( hand.size() < handSize )
  {
    if( !pool.empty() )
    {
      hand.push_back( pool.back() );
      pool.pop_back();
    }
    else
      break;// cannot finish filling hand
  }
  return;
}

void showHand( vector<char>& hand )
{
  cout << "hand: " ;
  for(size_t i=0; i<hand.size(); ++i )
    cout << hand[i] << " ";
  cout << endl;
  return;
}

void showPool( vector<char>& pool )
{
  cout << "pool:\n";
  for(size_t i=0; i<pool.size(); ++i )
  {
    cout << pool[i] << " ";
    if( (i+1)%20 == 0 )cout << endl;
  }
  cout << endl;
  return;
}

char playTile( vector<char>& hand, unsigned int tileIndex )
{
  char letterPlayed = '\0';// in case hand is empty
  if( tileIndex < hand.size() )// index is OK
  {
    letterPlayed = hand[ tileIndex ];
    hand.erase( hand.begin() + tileIndex );
  }
  return letterPlayed;
}



void start_game(vector<char> & pool , vector<vector<char> >& p_pools){
  generate_pool(pool); //this fills the pool and shuffles the letters
  showPool(pool);

  for (int i=0; i<p_pools.size(); i++)
    {
      fillHand(pool, p_pools[i]);
      showHand(p_pools[i]);
    }

  return;
}

//end 

int main() //calls the functions && creating of players 
{
  generateStartingBoard();
  board[7][7].letter = '0'; // the game should start from the centre tile
  printBoardDebugg();

  srand(time(0)); //fara asta random_shuffle produce mereu acelasi rezultat ....un seed pentru random 
  
  
  ifstream f;
  filename = "viable_data.txt";
  f.open(filename.c_str());
  //store all viable words in an unordored set
  while (f >> word)
    { //ignore anything but the first word from each line (the second word was the score, \n is the delimiter)
      f.ignore(numeric_limits<streamsize>::max(), '\n');
      stringSet.insert(word);
    }

  //defining the score for each letter
  map< char, int > mp;
  // map<char, int> ::iterator it;
  mp['a'] = 1, mp['e'] = 1 , mp['i'] = 1 , mp['o'] = 1, mp['u'] = 1 , mp['l'] = 1 , mp['n'] = 1  , mp['s'] = 1 , mp['t'] = 1 ,  mp['r'] = 1, mp['d'] = 2, mp['g'] = 2, mp['b'] = 3, mp['c'] = 3, mp['m'] = 3, mp['p'] = 3, mp['f'] = 4, mp['h'] = 4, mp['v'] = 4, mp['w'] = 4, mp['y'] = 4, mp['k'] = 5, mp['j'] = 8, mp['x'] = 8, mp['q'] = 10, mp['z'] = 10;
//taken from task 1 but not used 

  vector<char> main_pool; //declare the letter pool
  vector<char> p1_pool; //and a vector for each player hand
  vector<char> p2_pool;
  vector<char> p3_pool; //if players are less than 4
  vector<char> p4_pool; //some will remain empty
  vector<vector<char>> player_pools; //this will be used as argument (vector with variable size)

  //a game has at least 2 players
  player_pools.push_back(p1_pool);
  player_pools.push_back(p2_pool);

  cout << "How many players? (2/3/4)";
  int nrPlayers;
  cin >>  nrPlayers;
  if(nrPlayers>4 || nrPlayers < 2)
    {
    cout<<"Invalid number of players\n";
    return 0; //exist the program
    }
  else if(nrPlayers == 3)
    player_pools.push_back(p3_pool);
  else if(nrPlayers == 4)
    {
      player_pools.push_back(p3_pool);
      player_pools.push_back(p4_pool);
    }
  else
    ; //if nrPlayers == 2   do nothing/pass

  start_game(main_pool, player_pools);

  string input;
  while(true){
  cout<<"Use your letters: \n";
  cin>> input;
  if(isValidWord(input))
    cout<<"Found " <<input << endl <<"Next:\t";
  else
    cout<<"Invalid word, try again: \n";
  }


return 0;
}
 //asta e tabla mea. e un array 2d && daca nu dai un numar de playeri valid iti zice asta si te scoate din program 
 //it amesteca random literele si da fiecarui player litere 
 //merge cu cuvinte 