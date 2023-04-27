/*hashtable class 
  used to store the tracks objects
  member variable consist of the size of the table
  member function used to manipulate the hashtable.
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "track.h"
#include <string>
class HashTable{

private:
     unsigned size; 
     unsigned total;
    
public:
   
   Track** Table= NULL;
   HashTable(unsigned size);
  ~HashTable();
 //  getter for hashtable size
   unsigned getSize();
   void removes(std::string artistName);
   unsigned hash(std::string key);
   unsigned search(std::string artistName);
   void insert(Track* song);
   void resize(unsigned newsize);
 
 
};

   

#endif


