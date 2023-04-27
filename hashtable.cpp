#include "hashtable.h"
#include "track.h"
#include <string>
#include <iostream>


/*constructor for hashtable class
@param integer size,the size of the hashtable
@param pointer to track,array of track pointers
*/
HashTable::HashTable(unsigned size){
     this->size = size;
    Table= new Track*[size]{};
     
}

/*destructor for hashtable class*/
HashTable::~HashTable(){
std::cout << "hash closed";
delete [] Table;
}

//getter for member variables
unsigned HashTable::getSize(){
  return this->size;


}


/**function to resize hashtable when file is loaded*/
void HashTable::resize(unsigned newsize){
  unsigned new_capacity = (newsize+size)*1.4;
  Track** temp = new Track*[new_capacity]{};
  for ( unsigned int i = 0; i < size;i++){
    if (Table[i] == NULL || Table[i]->getDeleteStatus() ){
      continue;
    }
    temp[i]= Table[i];
  }
  delete[] Table;
  Table = temp;
   this->size = new_capacity-1;
 
}


//hashing function 
unsigned HashTable::hash(std::string key){
    unsigned long capacity = getSize();
    int factor =31;
    long long int sum= 0 ;
     for (unsigned int i = 0; i < key.size(); i++)
        {   
            sum = ((sum) + ((int(key[i])) * factor) );
            factor = ((factor) * (31 ) % INT16_MAX);   
        }
    

    return sum%capacity;
}


/*
inserts the track object into the hashtable
also handles collisions

*/
void HashTable::insert(Track* song){

    std::string extracted[3];
    unsigned int  key ;
    unsigned count = 0 ;
    std::string data;
    unsigned capacity = getSize();
    Track* result ;
   
    key = HashTable::hash(song->getArtist());
   
  
    if (Table[key] == NULL ){

       //empty cell--insert into array cell
      
       Table[key]= song;
     
    } 
   
    else if ( Table[key]->getDeleteStatus() == true)
    {
       //empty cell--insert into array cell
      
       Table[key]= song;
      
    } 
    else {
        do
          { 
            count++;
            key++;
            key%=capacity;
           
            result =Table[key];
            if (result == NULL ||count >= capacity){
                break;
            }
            
          } while ( result->getDeleteStatus() == false  );
          if (count >= capacity){
            std::cout << "Hash table is full";
          }
          else {
             Table[key]= song;
            
          }
    }

}


/*searches for specific track object in hashtable*/
unsigned HashTable::search(std::string artistName){
    unsigned count = 0;
    unsigned key = HashTable::hash(artistName);
     unsigned long capacity = getSize();
    Track* result = Table[key];
              
         if (result == NULL ) {
              std::cout << "item not found";
              key=0;
              return key;
            //if it doesn't match keep probing until an empty slot is found.if object status is deleted ,keep probing.
            //return track object or null.
         }
         else if (result->getDeleteStatus()){
            std::cout << "item not found";
              key=0;
              return key;
         }
         else if (result->getArtist() == artistName){
              std::cout << "----------------------------------------------------";
              std::cout << "Artist Name-----------------Title------------------Duration----\n";
             std::cout << result->getArtist() <<"|"<< result->getTitle() << "|"<<result->getDuration() << std::endl;
             return key;
             
         }
          else {
            do
          { 
            count++;
            key++;
            key%=capacity;
            result =Table[key];
            if (result == NULL|| count >= capacity ){
                break;
            }
          } while (result->getArtist() != artistName   );
         }

            if (result == NULL){
               std::cout << "item not found";
            }

           else if (result->getArtist() == artistName ) {
              if (result->getDeleteStatus()){
                   std::cout << "item not found";
              }
              else {

                std::cout << "----------------------------------------------------";
              std::cout << "Artist Name-----------------Title------------------Duration----\n";
             std::cout << result->getArtist() <<"|"<< result->getTitle() << "|"<<result->getDuration() << std::endl;

                 return key;
              }
             
           }
           else {
                
                std::cout << "item not found";

           } 
    return key;
}


/*   removes a track object from the hashtable */
void HashTable::removes(std::string artistName){
     unsigned long capacity = getSize();
     unsigned key = HashTable::hash(artistName);
     unsigned int count = 0;
     Track* result =   Table[key];
          if ( result == NULL  ){
            std::cout << "Song doesn't exist "; 
         }
         else if (result->getArtist() == artistName){
             result->deleteTrack();
             std::cout << "song has been removed";
         }
         else {
              do
                        { 
                            count++;
                            key++;
                            key%=capacity;
                            result =Table[key];
                            if (result == NULL || count >= capacity ){
                                break;
                            }
                        } while ((result->getDeleteStatus() == false && result->getArtist() != artistName ) );
            
                    if (result == NULL || count >= capacity){
                    std::cout << "song doesn't exists";
                }
                else {
                    result->deleteTrack();
                    std::cout << "Song successfully removed";
                }
         }
          
 }