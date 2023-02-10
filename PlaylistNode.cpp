#include <iostream>
#include <string>
#include "PlaylistNode.h"
using namespace std;


PlaylistNode::PlaylistNode()
{
	this->artistName = "None";
	this->songName = "None";
	this->uniqueID = "None";
	this->songLength = 0;
	this->nextNodePtr = 0;
};
PlaylistNode::PlaylistNode(string ID, string name, string artist, int length, PlaylistNode* nextLoc)
{
	this->artistName = artist;
	this->songName = name;
	this->uniqueID = ID;
	this->songLength = length;
	this->nextNodePtr =nextLoc;
};
void PlaylistNode::InsertAfter(PlaylistNode* NextLocation)
{
	PlaylistNode* tmpNext = nullptr;

	tmpNext = this->nextNodePtr;
	this->nextNodePtr = NextLocation;
	NextLocation->nextNodePtr = tmpNext;
};
void PlaylistNode::SetNext(PlaylistNode* NextLocation)
{
	this->nextNodePtr = NextLocation;
};
std::string PlaylistNode::GetID() 
{
	return this->uniqueID;
};
std::string PlaylistNode::GetSongName()
{
	return this->songName;
};
std::string PlaylistNode::GetArtistName()
{
	return this->artistName;
};
int PlaylistNode::GetSongLength()
{
	return this->songLength;
};
PlaylistNode* PlaylistNode::GetNext()
{
	return this->nextNodePtr;
};
void PlaylistNode::PrintPlaylistNode()
{
	cout << "Unique ID: " << this->GetID() << endl << "Song Name: " << this->GetSongName() << endl << \
		"Artist Name: " << this->GetArtistName() << endl << "Song Length (in seconds): " << this->GetSongLength() << endl;	
};
//"Copyright [2020] "