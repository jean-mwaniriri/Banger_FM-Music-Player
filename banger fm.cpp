//search Feature for Banger FM Music Player

void searchSong()
{
	string searchName;
	// ask the user to enter the song they want
	cout << "\nEnter song name:";
	cin.ignore();
	getline(cin,searchName);
	
	bool found = false;
	
	//go through all songs one by one
	for(int i = 0; i < 15; i++)
	{
	 check whether the song tittle matches
	 if(songs[i].tittle == searchName)
	 {cout << "\nSong found!" << endl;
	 cout << "Tittle:" << songs[i].tittle << endl;
	 cout << "Artist:" << songs[i].artist << endl;
	 
	 found = true
	 }
	}
	//Display message if no song was found
	if(found == false)
	{
		cout << "Soung not found." << endl;
	}
}


// Genre Category Feature
void showGenre()
{
  sting genreChoice;

  //Ask user to enter a genre
  cout << "\nEnter genre(pop,Hip Hop,Jazz)" << endl;
  cin.ignore();
  getline(cin, genreChoice);
 
  cout << "\nSongs in" << genrechoice << ":" << endl; 
  bool found = false;
 
 //check every song in the library
 for(int i = 0;i < 15; i++)
 {
 	//Displays songs that belong to the selected genre
 	if(songs[i].genre == genreChoice)
 	{
 		cout << songs[i].tittle << endl;
		 found = true;]
	 }
 }
 //Message shown when no songs match the genre
 if(found == false)
 {
 	cout <<"No songs available in this genre." << endl;
  } 
}