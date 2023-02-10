#ifndef CONTACTNODE_H
#define CONTACTNODE_H
#include <iostream>



class PlaylistNode {
public:
	PlaylistNode();
	PlaylistNode(std::string ID,std::string name,std::string artist,int length, PlaylistNode* nextLoc = 0);
	void InsertAfter(PlaylistNode* nodePtr);
	void SetNext(PlaylistNode* nodePtr);
	std::string GetID();
	std::string GetSongName();
	std::string GetArtistName();
	int GetSongLength();
	PlaylistNode* GetNext();
	void PrintPlaylistNode();
private: 
	std::string uniqueID;
	std::string songName;
	std::string artistName;
	int songLength;
	PlaylistNode* nextNodePtr;

};
#endif /* PlaylistNode_H */
//"Copyright [2020] "