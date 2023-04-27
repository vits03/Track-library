#ifndef TRACK_H
#define TRACK_H


/*
track class
stores the details of a track
member variables consist of information about track


*/


#include <string>

class Track{

private:
std::string title ;
std::string artist;
int duration;
bool deleted =false;
public:
   Track(std::string  title,std::string artist,int duration);
   ~Track(); //destructor
 bool  getDeleteStatus();
   void deleteTrack();
   
   //getters for member variables
   std::string getTitle();
   std::string getArtist();
   int getDuration();
};








#endif