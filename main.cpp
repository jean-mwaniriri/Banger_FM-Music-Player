#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
 
using namespace std;
 
struct Song {
    string title;
    string artist;
    string genre;
    string filepath;
};
 
vector<Song> songs = {
    {"Test Song", "Test Artist", "Pop", "test.wav"},
    {"Another Song", "Artist Two",  "RnB", "songs/song2.wav"},
};
 
int currentIndex = 0;
 
void stopSong() {
    PlaySound(NULL, NULL, 0);
    cout << "Playback stopped." << endl;
}
 
void pauseSong() {
    stopSong();
    cout << "Paused." << endl;
}
 
void playSong(const string& filepath) {
    bool result = PlaySound(filepath.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
    if (result) {
        cout << "Now playing: " << filepath << endl;
    } else {
        cout << "Error: Could not play " << filepath << endl;
        cout << "Make sure the file is a valid WAV file." << endl;
    }
}
 
void nextTrack() {
    currentIndex = (currentIndex + 1) % songs.size();
    playSong(songs[currentIndex].filepath);
    cout << "Now playing: " << songs[currentIndex].title
         << " by " << songs[currentIndex].artist << endl;
}
 
void displaySongs(const vector<Song>& songList) {
    if (songList.empty()) { cout << "No songs found." << endl; return; }
    for (int i = 0; i < (int)songList.size(); i++) {
        cout << i+1 << ". " << songList[i].title
             << " | " << songList[i].artist
             << " | " << songList[i].genre << endl;
    }
}
 
vector<Song> searchByArtist(const string& artistName) {
    vector<Song> results;
    string lowerInput = artistName;
    transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);
    for (const Song& s : songs) {
        string lowerArtist = s.artist;
        transform(lowerArtist.begin(), lowerArtist.end(), lowerArtist.begin(), ::tolower);
        if (lowerArtist.find(lowerInput) != string::npos)
            results.push_back(s);
    }
    return results;
}
 
vector<Song> filterByGenre(const string& genre) {
    vector<Song> results;
    for (const Song& s : songs) {
        if (s.genre == genre) results.push_back(s);
    }
    return results;
}
 
int main() {
    int choice;
    cout << "==============================" << endl;
    cout << "   BANGER FM MUSIC PLAYER     " << endl;
    cout << "==============================" << endl;
    do {
        cout << "\n1. View All Songs" << endl;
        cout << "2. Play Song" << endl;
        cout << "3. Pause" << endl;
        cout << "4. Stop" << endl;
        cout << "5. Next Track" << endl;
        cout << "6. Search by Artist" << endl;
        cout << "7. Filter by Genre" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: displaySongs(songs); break;
            case 2: {
                displaySongs(songs);
                cout << "Enter song number: ";
                int num; cin >> num;
                if (num >= 1 && num <= (int)songs.size()) {
                    currentIndex = num - 1;
                    playSong(songs[currentIndex].filepath);
                } else cout << "Invalid number." << endl;
                break;
            }
            case 3: pauseSong(); break;
            case 4: stopSong(); break;
            case 5: nextTrack(); break;
            case 6: {
                string name;
                cout << "Enter artist name: "; cin >> name;
                displaySongs(searchByArtist(name)); break;
            }
            case 7: {
                string genre;
                cout << "Enter genre: "; cin >> genre;
                displaySongs(filterByGenre(genre)); break;
            }
            case 0: cout << "Goodbye!" << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 0);
    return 0;
}
 
 