#include <iostream>
#include <string>
#include "PlaylistNode.h"
using namespace std;

void PrintMenu(string playlist);

int main(int argc,char* argv[])
{
	string playlistTitle;
	cout << "Enter playlist's title:\n";
	getline(cin, playlistTitle);
	PrintMenu(playlistTitle);



}
void PrintMenu(string playlist)
{
	PlaylistNode* headSong = 0;
	PlaylistNode* nextSong = 0;
	PlaylistNode* nextSong1 = 0;
	PlaylistNode* currSong = 0;
	PlaylistNode* tempSong = 0;
	string tempID;
	string tempSongName;
	string tempArtist;
	int tempLength;
	int posistionTemp;
	int posistionDest;
	char menuselection;


do {
		cout << endl << playlist <<" PLAYLIST MENU\na - Add song\nd - Remove song\nc \
- Change position of song\ns - Output songs by specific artist\nt - Output total time of playlist (in seconds)\no \
- Output full playlist\nq - Quit\n\n";
		cout << "Choose an option:\n";
		cin >> menuselection;
		cin.ignore();
	while (menuselection != 'a' && menuselection != 'd' && menuselection != 'c' && menuselection != 's' && menuselection != 't' && menuselection != 'o' && menuselection != 'q')
		{
			cout << "Choose an option:\n";
			cin >> menuselection;
			cin.ignore();
		}
	switch (menuselection){
		case 'a':
			cout << "ADD SONG" << endl << "Enter song's unique ID:" << endl;
			getline(cin, tempID);
			cout << "Enter song's name:" << endl;
			getline(cin, tempSongName);
			cout << "Enter artist's name:" << endl;
			getline(cin, tempArtist);
			cout << "Enter song's length (in seconds):" << endl;
			cin >> tempLength;
			currSong = headSong;
			nextSong = currSong;
			while (nextSong != 0)
			{
				nextSong = nextSong->GetNext();
				if (nextSong == 0)
				{
					nextSong = new PlaylistNode(tempID, tempSongName, tempArtist, tempLength);
					currSong->InsertAfter(nextSong);
					break;
				}
				currSong = currSong->GetNext();
			}
			
			if (headSong == 0)
			{
				headSong = new PlaylistNode(tempID, tempSongName,tempArtist, tempLength);
			}
			break;

		case 'd':
			cout << "REMOVE SONG\nEnter song's unique ID:\n";
			getline(cin, tempID);

			currSong = headSong;
			nextSong = currSong;
			while (currSong->GetID() != tempID)
			{
				nextSong = nextSong->GetNext();
				if (nextSong->GetID() == tempID)
				{
					cout << "\"" << nextSong->GetSongName() << "\" removed." << endl;
					currSong->SetNext(nextSong->GetNext());
					delete nextSong;
					break;

				}
				currSong = currSong->GetNext();
			}
			if (currSong->GetID() == tempID)
			{
				cout << "\"" << tempID << "\" removed" << endl;
				headSong = headSong->GetNext();
				delete nextSong;
			}

			break;

		case 'c':
			cout << "CHANGE POSITION OF SONG\nEnter song's current position:\n";
			cin >> posistionTemp;
			cout << "Enter new position for song:\n";
			cin >> posistionDest;
			tempSong = headSong;
			int count;
			int j;
			for(count = 1;tempSong->GetNext() != nullptr;)
			{
				tempSong = tempSong->GetNext();
				count++;
			}
			if (posistionTemp < 1){posistionTemp = 1;}
			if (posistionDest < 1){posistionDest = 1;}
			if (posistionTemp > count){posistionTemp = count;}
			if (posistionDest > count){posistionDest = count;}
			tempSong = headSong;
			do {
				if (posistionTemp > posistionDest) {j = 1; }
				if (posistionTemp < posistionDest) {j = 0; }

				for (int i = 0,a = 1,b = 1; i != posistionTemp || j != posistionDest; )
				{
					if (i < posistionTemp) { i++; }
					if (j < posistionDest) { j++; }
					if (i == posistionTemp && a == 1) { currSong = tempSong; a++; }
					if (j == posistionDest && b == 1) { nextSong = tempSong; b++; }
					if (i == posistionTemp - 1) { nextSong1 = tempSong; }

					if (i == posistionTemp && posistionDest == 1)
					{
						cout << "\"" << currSong->GetSongName() << "\" " << "moved to position " << posistionDest << endl;
						nextSong1->SetNext(currSong->GetNext());
						tempSong = headSong;
						headSong = currSong;
						headSong->SetNext(tempSong->GetNext());
						headSong->InsertAfter(tempSong);
						break;
					}
					if (j == posistionDest && posistionTemp == 1)
					{
						cout << "\"" << currSong->GetSongName() << "\" " << "moved to position " << posistionDest << endl;
						currSong = headSong;
						headSong = headSong->GetNext();
						nextSong->InsertAfter(currSong);
						break;
					}
					if (a == 2 && b == 2)
					{
						cout << "\"" << currSong->GetSongName() << "\" " << "moved to position " << posistionDest << endl;
						nextSong1->SetNext(currSong->GetNext());
						nextSong->InsertAfter(currSong);
						break;
					}
					tempSong = tempSong->GetNext();
				}
				break;
			}while (posistionTemp != posistionDest);
			break;

		case 's':
			cout << "OUTPUT SONGS BY SPECIFIC ARTIST\nEnter artist's name:\n";
			getline(cin, tempArtist);
			currSong = headSong;
			for (int i = 1; currSong != 0; i++)
			{
				if (currSong->GetArtistName() == tempArtist)
				{
					cout << "\n" << i << "." << endl;
					currSong->PrintPlaylistNode();
				}
				
				currSong = currSong->GetNext();
			}

			break;

		case 't':
			cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\nTotal time: ";
			currSong = headSong;
			
			for (int total = 0;currSong != 0;)
			{
				total = total + currSong->GetSongLength();
				currSong = currSong->GetNext();
				if (currSong == 0)
				{
					cout << total << " seconds"<< endl;
					break;
				}
			}
			
			break;

		case 'o':
			cout << playlist << " - OUTPUT FULL PLAYLIST\n";
			currSong = headSong;
			if (currSong == 0)
			{
				cout << "Playlist is empty" << endl;
			}
			for(int i = 1; currSong != 0; i++) {
				cout << i << ".\n";
					currSong->PrintPlaylistNode();
					currSong = currSong->GetNext();
					
					if (currSong != 0) { cout << endl; }
					
			}
			break;

		case 'q':

			break;
		}
	} while (menuselection != 'q');

};
