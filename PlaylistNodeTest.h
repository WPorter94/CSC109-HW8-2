#pragma once

#include <iostream>
#include <string>
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H


#include <cxxtest/TestSuite.h>
#include "PlaylistNode.h"
  //Include your classes header file(s) below and uncomment.
  //#include "myClass.h"
  //Include cxx test file! Project->Properties->Inlude directories arrow->clcik white space then options-> set directory.
#include "PlaylistNode.h"

class newCxxTest : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testDefaultConstructor()
    {
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions. 
        PlaylistNode song1;

        std::string expect_ID = "None";
        std::string expect_artist = "None";
        std::string expect_songname = "None";
        int expect_songlength = 0;
        PlaylistNode* expect_ptr = 0;
        
        TS_ASSERT_EQUALS(song1.GetID(), expect_ID);
        TS_ASSERT_EQUALS(song1.GetArtistName(), expect_artist);
        TS_ASSERT_EQUALS(song1.GetSongName(), expect_songname);
        TS_ASSERT_EQUALS(song1.GetSongLength(), expect_songlength);
        TS_ASSERT_EQUALS(song1.GetNext(), expect_ptr);
    }


    void testsecondConstructor()
    {
        std::string artist = "Jack Johnson";
        std::string ID = "2";
        std::string songname = "Bubbles";
        int songlength = 180;
        PlaylistNode* ptr = 0;

        PlaylistNode song1(ID,songname,artist,songlength,ptr);

        std::string expect_ID = "2";
        std::string expect_artist = "Jack Johnson";
        std::string expect_songname = "Bubbles";
        int expect_songlength = 180;
        PlaylistNode* expect_ptr = 0;

        TS_ASSERT_EQUALS(song1.GetID(), expect_ID);
        TS_ASSERT_EQUALS(song1.GetArtistName(), expect_artist);
        TS_ASSERT_EQUALS(song1.GetSongName(), expect_songname);
        TS_ASSERT_EQUALS(song1.GetSongLength(), expect_songlength);
        TS_ASSERT_EQUALS(song1.GetNext(), expect_ptr);
    }

    void testInsertAfterFunction()
    {
        PlaylistNode* tempsong = 0;
        PlaylistNode* headersong1 = 0;
        PlaylistNode* nextsong = 0;

        std::string artist = "Jack Johnson";
        std::string ID = "1";
        std::string songname = "Bubbles";
        int songlength = 180;
   
        headersong1 = new PlaylistNode(ID, songname, artist, songlength);
        
        std::string artist2 = "John Mayer";
        std::string ID2 = "2";
        std::string songname2 = "Good People";
        int songlength2 = 200;
        nextsong = new PlaylistNode(ID2, songname2, artist2, songlength2);
        headersong1->InsertAfter(nextsong);
        
        tempsong = headersong1;
        tempsong = tempsong->GetNext();

        std::string expect_ID = tempsong->GetID();
        std::string expect_artist = tempsong->GetArtistName();
        std::string expect_songname = tempsong->GetSongName();
        int expect_songlength = tempsong->GetSongLength();
       

        TS_ASSERT_EQUALS(nextsong->GetID(), expect_ID);
        TS_ASSERT_EQUALS(nextsong->GetArtistName(), expect_artist);
        TS_ASSERT_EQUALS(nextsong->GetSongName(), expect_songname);
        TS_ASSERT_EQUALS(nextsong->GetSongLength(), expect_songlength);
     

    }
    void testSetNextFunction()
    {
        PlaylistNode* tempsong = 0;
        PlaylistNode* headersong1 = 0;
        PlaylistNode* nextsong = 0;
        PlaylistNode* nextsong2 = 0;

        std::string artist = "Jack Johnson";
        std::string ID = "1";
        std::string songname = "Bubbles";
        int songlength = 180;

        headersong1 = new PlaylistNode(ID, songname, artist, songlength);

        std::string artist2 = "John Mayer";
        std::string ID2 = "2";
        std::string songname2 = "Good People";
        int songlength2 = 200;
        nextsong = new PlaylistNode(ID2, songname2, artist2, songlength2);
        headersong1->InsertAfter(nextsong);
        std::string artist3 = "Snoop";
        std::string ID3 = "3";
        std::string songname3 = "thats that";
        int songlength3 = 1000;
        nextsong2 = new PlaylistNode(ID3, songname3, artist3, songlength3);
        nextsong->InsertAfter(nextsong2);

        tempsong = headersong1;
        headersong1->SetNext(nextsong->GetNext());
        nextsong2->SetNext(tempsong->GetNext());
        nextsong->SetNext(nullptr);

        tempsong = headersong1->GetNext();
        
        

        std::string expect_ID = tempsong->GetID();
        std::string expect_artist = tempsong->GetArtistName();
        std::string expect_songname = tempsong->GetSongName();
        int expect_songlength = tempsong->GetSongLength();


        TS_ASSERT_EQUALS(nextsong2->GetID(), expect_ID);
        TS_ASSERT_EQUALS(nextsong2->GetArtistName(), expect_artist);
        TS_ASSERT_EQUALS(nextsong2->GetSongName(), expect_songname);
        TS_ASSERT_EQUALS(nextsong2->GetSongLength(), expect_songlength);
    }
    void testGetIDFunction()
    {
        PlaylistNode* headersong1;

        std::string artist = "ASDWERSDTgdfgfdgj23222332143!!!";
        std::string ID = "-A1X00";
        std::string songname = " ";
        int songlength = 180;

        headersong1 = new PlaylistNode(ID, songname, artist, songlength);

        std::string expect_ID = "-A1X00";
        TS_ASSERT_EQUALS(headersong1->GetID(), expect_ID);
    }
    void testGetArtistNameFunction()
    {
        PlaylistNode* headersong1;

        std::string artist = "ASDWERSDTgdfgfdgj23222332143!!!";
        std::string ID = "-A1X00";
        std::string songname = " ";
        int songlength = 180;

        headersong1 = new PlaylistNode(ID, songname, artist, songlength);

        std::string expect_artist = "ASDWERSDTgdfgfdgj23222332143!!!";
        TS_ASSERT_EQUALS(headersong1->GetArtistName(), expect_artist);
    }
    void testGetSongNameFunction()
    {
        PlaylistNode* headersong1;

        std::string artist = "ASDWERSDT   gdfgfdgj23222332143!!!";
        std::string ID = "-A1 X00";
        std::string songname = " ";
        int songlength = 180;

        headersong1 = new PlaylistNode(ID, songname, artist, songlength);

        std::string expect_song = " ";
        TS_ASSERT_EQUALS(headersong1->GetSongName(), expect_song);
    }
    void testGetSongLengthFunction()
    {
        PlaylistNode* headersong1;

        std::string artist = "ASDWERSDT   gdfgfdgj23222332143!!!";
        std::string ID = "-A1 X00";
        std::string songname = " ";
        int songlength = 2982838585;

        headersong1 = new PlaylistNode(ID, songname, artist, songlength);

        int expect_songlength = 2982838585;
        TS_ASSERT_EQUALS(headersong1->GetSongLength(), expect_songlength);
    }
    void testGetNextFunction()
    {
        PlaylistNode* headersong1 = 0;
        PlaylistNode* nextsong = 0;

        std::string artist = "Jack Johnson";
        std::string ID = "1";
        std::string songname = "Bubbles";
        int songlength = 180;

        headersong1 = new PlaylistNode(ID, songname, artist, songlength);

        std::string artist2 = "John Mayer";
        std::string ID2 = "2";
        std::string songname2 = "Good People";
        int songlength2 = 200;
        nextsong = new PlaylistNode(ID2, songname2, artist2, songlength2);
        headersong1->InsertAfter(nextsong);

        TS_ASSERT_EQUALS(headersong1->GetNext(), nextsong);
    }
    void testPrintFunction()
    {
        
        PlaylistNode* headersong1 = 0;
        PlaylistNode* nextsong = 0;
        PlaylistNode* nextsong2 = 0;

        std::string artist = "Jack Johnson";
        std::string ID = "1";
        std::string songname = "Bubbles";
        int songlength = 180;

        headersong1 = new PlaylistNode(ID, songname, artist, songlength);

        std::string artist2 = "John Mayer";
        std::string ID2 = "2";
        std::string songname2 = "Good People";
        int songlength2 = 200;
        nextsong = new PlaylistNode(ID2, songname2, artist2, songlength2);
        headersong1->InsertAfter(nextsong);
        std::string artist3 = "Snoop";
        std::string ID3 = "3";
        std::string songname3 = "thats that";
        int songlength3 = 1000;
        nextsong2 = new PlaylistNode(ID3, songname3, artist3, songlength3);
        nextsong->InsertAfter(nextsong2);
        headersong1->PrintPlaylistNode();

    }
};
#endif /* NEWCXXTEST_H */
//"Copyright [2020] "
