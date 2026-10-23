#include <iostream>
#include "supp_dll.h"
#include <string>

int main() {
    //initialize songs
    DoubleList<std::string>* song1 = AddSong<std::string>("Kenshi Yonezu - Campanella");
    DoubleList<std::string>* song2 = AddSong<std::string>("Kenshi Yonezu - Kanden");
    DoubleList<std::string>* song3 = AddSong<std::string>("Kenshi Yonezu - Lemon");
    DoubleList<std::string>* song4 = AddSong<std::string>("Kenshi Yonezu - Machigai Sagashi");
    DoubleList<std::string>* song5 = AddSong<std::string>("Kenshi Yonezu - Canary");
    DoubleList<std::string>* song6 = AddSong<std::string>("Kenshi Yonezu - Uma to Shika");

    //order from 1 to 6
    song1->next = song2;
    song2->next = song3;
    song3->next = song4;
    song4->next = song5;
    song5->next = song6;
    
    //reverse order from 1 to 6
    song2->prev = song1;
    song3->prev = song2;
    song4->prev = song3;
    song5->prev = song4;
    song6->prev = song5;

    PlayList(song1);

    //adding songs
    InsertStart<std::string>("Kenshi Yonezu - Karasu", song1);
    InsertEnd<std::string>("Kenshi Yonezu - Yodaka", song1);
    InsertAfter<std::string>("Kenshi Yonezu - Jane Doe", song3);
    PlayList(song1);
    
    //deleting song
    DeleteSong<std::string>("Kenshi Yonezu - Kanden", song1);
    PlayList(song1);

    //looping songs n times
    LoopTimes(2, song1);

    //play from end
    ReversePlay(song1);

    return 0;
}