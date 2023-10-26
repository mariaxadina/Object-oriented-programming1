#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Melodie {
    string id ;
    string titlu ;
    string artist;
    string album;
    float durata;

public:
    Melodie(string _id = " ", string _titlu = " ", string _artist = " ", string _album = " ", float _durata = 3)
            : id(_id), titlu(_titlu), artist(_artist), album(_album), durata(_durata) {}

    Melodie(const Melodie &alt_obj) {
        id = alt_obj.id;
        titlu = alt_obj.titlu;
        artist = alt_obj.artist;
        album = alt_obj.album;
        durata = alt_obj.durata;
    }

    Melodie &operator=(const Melodie &alt_obj) {
        if (this != &alt_obj) {
            id = alt_obj.id;
            titlu = alt_obj.titlu;
            artist = alt_obj.artist;
            album = alt_obj.album;
            durata = alt_obj.durata;
        }
        return *this;
    }
    ~Melodie() {}

    void afisare_informatii() {
        cout << "   Nume melodie: " << titlu << ", ID Melodie: " << id << ", Artist: " << artist
             << ", Album: " << album << ", Durata: " << durata << endl;
    }

    void play() {
        cout << "Now playing: " << titlu << " by " << artist << endl;
    }

    void adauga_in_playlist() {
        cout << titlu << " by " << artist << " added to playlist" << endl;
    }

    friend ostream &operator<<(ostream &os, const Melodie &melodie) {
        os << "   Nume melodie: " << melodie.titlu << ", ID Melodie: " << melodie.id << ", Artist: " << melodie.artist
           << ", Album: " << melodie.album << ", Durata: " << melodie.durata;
        return os;
    }
};

class Playlist {
    string nume_playlist;
    vector<Melodie> melodii;

public:
    Playlist(const string &_numePlaylist, const vector<Melodie> &_melodii)
            : nume_playlist(_numePlaylist), melodii(_melodii) {}

     Playlist(const Playlist& alt_obj) {
        nume_playlist = alt_obj.nume_playlist;
        melodii = alt_obj.melodii;
     }

    Playlist &operator=(const Playlist &alt_obj) {
        if (this != &alt_obj) {
            nume_playlist = alt_obj.nume_playlist;
            melodii = alt_obj.melodii;
        }
        return *this;
    }

    ~Playlist() {}

    void adauga_melodie(const Melodie &melodie) {
        melodii.push_back(melodie);
    }

    void afisare_playlist() {
        cout << "Playlist: " << nume_playlist << endl;
        for (const Melodie &melodie : melodii) {
            cout << melodie << endl;
        }
    }

    int numar_melodii() const {
        return melodii.size();
    }


    friend ostream &operator<<(ostream &os, const Playlist &playlist) {
        os << "Nume playlist: " << playlist.nume_playlist << endl;
        for (const Melodie &melodie : playlist.melodii) {
            os << melodie << endl;
        }
        return os;
    }
};

class Album {
    string nume_album;
    string artist;
    vector<Melodie> melod;

public:
    Album(const string &_nume_album = "", const string &_artist = "") : nume_album(_nume_album), artist(_artist) {}

    Album &operator=(const Album &alt_obj) {
        if (this != &alt_obj) {
            nume_album = alt_obj.nume_album;
            artist = alt_obj.artist;
            melod = alt_obj.melod;
        }
        return *this;
    }

    Album(const Album& alt_obj) {
        nume_album = alt_obj.nume_album;
        artist = alt_obj.artist;
        melod = alt_obj.melod;
    }

    ~Album() {}


    void adauga_melodie_in_album(const Melodie& melodie) {
        melod.push_back(melodie);
    }

    void afisare_melodii_din_album() {
        cout << "Melodii din albumul " << nume_album << " - Artist: " << artist << ":\n";
        for (const Melodie& melodie : melod) {
        cout << melodie << endl;
        }
    }

    friend ostream &operator<<(ostream &os, const Album &album) {
        os << "*Nume album: " << album.nume_album << ", Artist: " << album.artist << endl;
        //os << "Melodii din album:" << endl;
        for (const Melodie &melodie : album.melod) {
            os << melodie << endl;
        }
        return os;
    }
};

class Artist{
    string artist;
    Album album;
    vector<Album> albumx;
public:
    Artist(const string &_artist = "") : artist(_artist) {}

    Artist &operator=(const Artist &alt_obj) {
        if (this != &alt_obj) {
            album = alt_obj.album;
            artist = alt_obj.artist;
            albumx = alt_obj.albumx;
        }
        return *this;
    }

     Artist(const Artist& alt_obj) {
        artist = alt_obj.artist;
        album = alt_obj.album;
        albumx = alt_obj.albumx;
    }

    ~Artist() {}

    void afisare_informatii_artist() {
        cout << "Nume artist: " << artist << endl;
        cout << "Albume artist:\n";
        for (const Album& album : albumx) {
            cout << album << endl;
        }
    }

    void adauga_album(const Album& album) {
        albumx.push_back(album);
    }

    friend ostream& operator<<(ostream& os, const Artist& artist) {
        os << "Nume artist: " << artist.artist << endl;
        os << "Albume artist:\n";
        for (const Album& album : artist.albumx) {
            os << album << endl;
        }
        return os;
    }
};

int main() {
    cout << "~Informatii melodii create ca obicete:" << endl;
    Melodie melodie1("1", "Blank Space", "Taylor Swift", "1989", 3.52);
    Melodie melodie2("2", "Shake it Off", "Taylor Swift", "1989", 3.39);
    Melodie melodie3("3", "God is a woman", "Ariana Grande", "Sweetner", 3.18);
    Melodie melodie4("4", "7 rings", "Ariana Grande", "thank u,next", 2.59);
    Melodie melodie5("5", "breathin", "Ariana Grande", "Sweetner", 3.20);

    cout << melodie1 << endl;
    cout << melodie2 << endl;
    cout << melodie3 << endl;
    cout << melodie4 << endl;
    cout << melodie5 << endl;
    //melodie1.afisare_informatii();
    //melodie2.afisare_informatii();
    //melodie3.afisare_informatii();
    //melodie4.afisare_informatii();
    //melodie5.afisare_informatii();
    cout << endl <<endl;


    Playlist playlist1("CAR MUSIC", vector<Melodie>{melodie1, melodie2});
    Playlist playlist2("ShOwEr MuSiC", vector<Melodie>{melodie2, melodie3});

    cout << "~Playlist-uri create ca obiecte:\n";
    cout << playlist1 << endl;
    cout << playlist2 << endl;
    ///playlist1.afisare_playlist();
    ///playlist2.afisare_playlist();
    cout << endl <<endl;

    cout <<"~Adaug o melodie in playlist-ul ShOwEr MuSiC:\n";
    playlist2.adauga_melodie(melodie1);
    ///playlist2.afisare_playlist();
    cout << playlist2 << endl;
    cout << endl << endl;

    Album album("1989", "Taylor Swift");
    album.adauga_melodie_in_album(melodie1);
    album.adauga_melodie_in_album(melodie2);

    cout << "~Informatii album creat:\n";
    ///album.afisare_melodii_din_album();
    cout << album << endl;
    cout << endl << endl;

    cout << "~Creare artist si afisare albume:\n";
    Artist artist("Ariana Grande");
    Album album1("Sweetner", "Ariana Grande");
    Album album2("thank u,next", "Ariana Grande");
    artist.adauga_album(album1);
    artist.adauga_album(album2);

    cout << artist << endl;
    ///artist.afisare_informatii_artist();
    album1.adauga_melodie_in_album(melodie3);
    album1.adauga_melodie_in_album(melodie5);

    cout << album1 << endl;
    ///album1.afisare_melodii_din_album();
    album2.adauga_melodie_in_album(melodie4);
    cout << album2 << endl;
    ///album2.afisare_melodii_din_album();
    cout << endl << endl;



    return 0;
}
