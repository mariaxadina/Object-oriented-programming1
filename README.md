Tema 1 - Programare Orientata pe obiecte

Codul atasat descrie o aplicate de gestionare a informatiilor despre melodii, playlist-uri, artisti si albume, folosind urmatoarele clase:
- Clasa "Melodie" ce contine:
id - un identificator unic pentru melodie
titlu - titlul melodiei
artist - numele artistului care interpretează melodia
album - numele albumului în care se găsește melodia
durata - durata melodiei în minute

- Clasa "Playlist" ce contine numele playlist-ului (nume_playlist) si o lista de melodii (obiecte - "Melodie")
  
- Clasa "Album" reprezinta tot o lista de melodii de ale aceluiasi artist
nume_album - stochează numele albumului
artist - stochează numele artistului la care aparține albumul
melod - un vector care conține obiecte Melodie reprezentând melodiile din album

- Clasa "Artist" ce poate avea mai multe obiecte de tip Album
nume_artist - stochează numele artistului
albumx - un vector care conține obiecte Album reprezentând albumele artistului

Pentru fiecare clasa am creat constructor de initializare, destructor, operator de copiere si constructior de copiere. In functia main se creeaza obiectele claselor de mai sus, apoi se apeleaza functiile pentru gestionarea melodiilor si afisarea acestora.
