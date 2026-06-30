// -- DISPLAY / GUI --
HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);

void colour(int c) { SetConsoleTextAttribute(con, c); }
void reset()       { SetConsoleTextAttribute(con, 7); }

void line(char s = '=') {
    colour(3);
    for (int i = 0; i < 50; i++) cout << s;
    cout << endl;
    reset();
}

void banner() {
    system("cls");
    line();
    colour(11); cout << "\n      B A N G E R S   F M\n";
    colour(14); cout << "    Your Kenyan Music Experience\n\n";
    reset();
    line();
}

void menu() {
    line('-');
    colour(14); cout << "        M A I N   M E N U\n"; reset();
    line('-');
    colour(11); cout << "  [1]"; reset(); cout << " View All Songs\n";
    colour(11); cout << "  [2]"; reset(); cout << " Play a Song\n";
    colour(11); cout << "  [3]"; reset(); cout << " Pause\n";
    colour(11); cout << "  [4]"; reset(); cout << " Stop\n";
    colour(11); cout << "  [5]"; reset(); cout << " Next Track\n";
    colour(11); cout << "  [6]"; reset(); cout << " Search by Artist\n";
    colour(11); cout << "  [7]"; reset(); cout << " Filter by Genre\n";
    colour(12); cout << "  [0]"; reset(); cout << " Exit\n";
    line('-');
    colour(14); cout << "  Choice: "; reset();
}

void songTable(const vector<Song>& list) {
    if (list.empty()) {
        colour(12); cout << "\n  No songs found.\n\n"; reset(); return;
    }
    cout << endl;
    colour(14); cout << "  #  Title              Artist          Genre\n"; reset();
    line('-');
    for (int i = 0; i < (int)list.size(); i++) {
        colour(11); cout << "  " << i+1 << ". "; reset();
        cout << list[i].title << "\t\t";
        colour(10); cout << list[i].artist << "\t"; reset();
        colour(14); cout << list[i].genre << "\n"; reset();
    }
    line('-');
}

void nowPlaying(const Song& s) {
    cout << endl; line();
    colour(10); cout << "  [ NOW PLAYING ]\n"; reset();
    colour(15); cout << "  " << s.title << "\n"; reset();
    colour(10); cout << "  by " << s.artist << "\n"; reset();
    colour(14); cout << "  Genre: " << s.genre << "\n"; reset();
    line();
}

void ok(const string& msg)     { colour(10); cout << "\n  >> " << msg << "\n\n"; reset(); }
void err(const string& msg)    { colour(12); cout << "\n  !! " << msg << "\n\n"; reset(); }
void prompt(const string& msg) { colour(14); cout << "\n  "   << msg << " ";    reset(); }

void bye() {
    system("cls"); line();
    colour(11); cout << "\n  Thanks for listening to Boomba FM!\n";
    cout <<           "  Tuonane baadaye :)\n\n"; reset();
    line();
}
