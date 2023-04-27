#include <iostream>
#include <string>
#include "hashtable.h"
#include "track.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <typeinfo>
#include <algorithm>
#include <regex>

/*
function  that checks if a file exists 
*/
bool is_file_exist(const char * fileName) {
  std::ifstream infile(fileName);
  return infile.good();
}


/*
function  that checks if a file exists 
*/

void saveToFile(HashTable hashtable){
  std::regex file_regex("^[\\w,\\s-]+\\.[A-Za-z]{3}$");
   char filename[100];
   unsigned capacity=hashtable.getSize();
   
   do {
    std::cout << "Input the file name:";
    std::cin >> filename;
  }
  while ((regex_match(filename,file_regex)) == false);
  // Create and open a text file
  std::ofstream MyFile(filename);
  for (unsigned int i =0 ; i < capacity;i++){
    if (hashtable.Table[i] == NULL || hashtable.Table[i]->getDeleteStatus()){
      continue;
    }
      MyFile <<   hashtable.Table[i]->getTitle()<<"\t" << hashtable.Table[i]->getArtist()<<"\t" <<hashtable.Table[i]->getDuration() << "\n";
  }
  MyFile.close();
}




/*
function loads a new file and add the objects into the hash table.

*/


void LoadFile(HashTable hashtable){
  char filename[100];
  std::string track_details[3];
  std::string sub;
   std::ifstream infile;
   std::string myText;
  unsigned number_of_lines = 0;
    std::string line;
    
  do {
    std::cout << "Input the file name:";
    std::cin >> filename;
    if (is_file_exist(filename) == false) {
      std::cout << "File not Found! Please enter a valid file name and format\n";
    }

  }
  while (is_file_exist(filename) == false);
std::ifstream myfile(filename);


    while (std::getline(myfile, line)){
        ++number_of_lines;
    std::cout << "Number of lines in text file: " << number_of_lines;}

   hashtable.resize(number_of_lines);

   infile.open(filename);
   while (getline(infile, myText)) {
   for ( int i =0;i<3;i++){ 
    int pos = myText.find("\t");
    sub = myText.substr(0, pos);
    track_details[i] = sub;
    myText = myText.substr(pos+1);
   }
   hashtable.insert(new Track(track_details[0],track_details[1],stoi(track_details[2])));
  }
}







int main(){

unsigned key;
int i;
std::string choice;
std::regex choice_regx("[0-4]|(-1)");
char filename[100];
std::string track_details[3];
std::string sub;

  //take file name as input until a valid filename is entered
  do {
    std::cout << "Input the file name:";
    std::cin >> filename;
    if (is_file_exist(filename) == false) {
      std::cout << "File not Found! Please enter a valid file name and format\n";
    }

  }
  while (is_file_exist(filename) == false);
  int number_of_lines = 0;
  std::string line;
  std::ifstream myfile(filename);

    while (std::getline(myfile, line)){
    ++number_of_lines;
   }




    std::string s;

    //initialises hashtable with size as argument
    HashTable Table((number_of_lines*1.3));
  std::string artistName;
  std::string myText;
  std::ifstream infile;
  
  
  /* opens file and extract song details from each line*/
  infile.open(filename);
  while (getline(infile, myText)) {
   for ( int i =0;i<3;i++){ 
    int pos = myText.find("\t");
    sub = myText.substr(0, pos);
    track_details[i] = sub;
    myText = myText.substr(pos+1);
   }
   Table.insert(new Track(track_details[0],track_details[1],stoi(track_details[2])));
  }
  
  //show menu
do {
  std::cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "---------------------------------------------Please choose an option---------------------------------------------------\n";
    std::cout << "1.LOAD OTHER FILES\n";
    std::cout << "2.SAVE TRACKS IN FILE\n";
    std::cout << "3.SEARCH BY ARTIST/BAND NAME.\n";
    std::cout << "4.REMOVE A TRACK.\n";
       std::cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    do {
      std::cout << "Please enter a number between 1 and 4 to choose an option OR type -1 to quit:  ";
      std::cin >> choice;
    } while (regex_match(choice, choice_regx) == false);

    i = stoi(choice);
    std::cout << i;
    switch (i) {
    case 1:
       
     LoadFile(Table);
      break;
    case 2:
      saveToFile(Table);
      break;
    case 3:
      std::cout << "input artist name";
       std::cin >> artistName;
       std::cin.getline(filename,100);
        s = filename;   
       key =Table.search(artistName+s);
      std::cout << Table.Table[key]->getTitle();
      break;
    case 4:

       std::cout << "input artist name";
       std::cin >> artistName;
       std::cin.getline(filename,100);
        s = filename;
       Table.removes(artistName+s);
     
      break;
    default:
      break;
    }
  } while (i != -1);
  

    return 0; 
}