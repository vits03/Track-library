#include "track.h"
#include <iostream>

/*track class constructor 
@param string title ,the title of the song
@param string artist , the name of the artist
@param integer duration, the duration of the song


*/
Track::Track(std::string title,std::string artist,int duration){
    this->title = title;
    this->artist = artist;
    this->duration = duration;
}

/*track destructor*/
Track::~Track(){
    std::cout << "closing";
}

void Track::deleteTrack(){
   this->deleted = true;
  
   
}

/*getters for member variables*/
bool  Track::getDeleteStatus(){
    return deleted;
}

std::string Track::getArtist(){
    return artist;
}
std::string Track::getTitle(){
    return title;
}

int Track::getDuration(){
    return duration;
}
