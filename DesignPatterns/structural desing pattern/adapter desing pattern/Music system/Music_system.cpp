#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// song
class Song
{
  string name;
  string singer;

public:
  Song(string name, string singer) : name(name), singer(singer) {};

  const string getSongName() const { return this->name; }
  const string getSingerName() const { return this->singer; }

  void getDesc()
  {
    cout << "Song Name: " << this->getSongName() << endl;
    cout << "Singer Name: " << this->getSingerName() << endl;
  }
};

// music player
class MusicPlayer
{
public:
  virtual void play(Song *song) = 0;
  virtual ~MusicPlayer() = default;
};

class Speaker
{
public:
  void playWithSpeaker(Song *song)
  {
    cout << song->getSongName() << " is playing via speaker" << endl;
  }
};

class Bluetooth
{
public:
  void playWithBluetooth(Song *song)
  {
    cout << song->getSongName() << " is playing via Bluetooth" << endl;
  }
};
class HeadPhone
{
public:
  void playWithHeadPhone(Song *song)
  {
    cout << song->getSongName() << " is playing via HeadPhone" << endl;
  }
};

// adapters
class BluetoothAdapter : public MusicPlayer
{
  Bluetooth *bluetooth;

public:
  BluetoothAdapter(Bluetooth *blue) : bluetooth(blue) {};
  void play(Song *song) override
  {
    bluetooth->playWithBluetooth(song);
  }
};

class SpeakerAdapter : public MusicPlayer
{
  Speaker *speaker;

public:
  SpeakerAdapter(Speaker *speak) : speaker(speak) {};
  void play(Song *song) override
  {
    speaker->playWithSpeaker(song);
  }
};

class HeadPhoneAdapter : public MusicPlayer
{
  HeadPhone *headphone;

public:
  HeadPhoneAdapter(HeadPhone *headphone) : headphone(headphone) {};
  void play(Song *song) override
  {
    headphone->playWithHeadPhone(song);
  }
};

// song Manager
class SongManager
{
  vector<Song *> songs;
  MusicPlayer *player = nullptr;

public:
  SongManager() {};

  void setPlayer(MusicPlayer *p)
  {
    player = p;
    cout << "Music output device changed\n";
  }

  void addSong(Song *song)
  {
    songs.push_back(song);
    cout << song->getSongName() << " added successfully" << endl;
  }
  void removeSong(Song *song)
  {
    songs.erase(remove(songs.begin(), songs.end(), song), songs.end());
    cout << song->getSongName() << " removed successfully" << endl;
  }
  void showAllSongs()
  {
    int count = 1;
    for (auto &it : songs)
    {
      cout << count << ". " << it->getSongName() << " -  by " << it->getSingerName() << endl;
      count++;
    }
  }

  void playSong(int index)
  {
    auto song = songs[index - 1];
    player->play(song);
  }
};

int main()
{
  SongManager manager1;

  Song s1("Tum Hi Ho", "Arijit Singh");
  Song s2("Believer", "Imagine Dragons");
  Song s3("Shape of You", "Ed Sheeran");
  Song s4("Kesariya", "Arijit Singh");

  manager1.addSong(&s1);
  manager1.addSong(&s2);
  manager1.addSong(&s3);
  manager1.addSong(&s4);

  Bluetooth bluetooth;
  Speaker speaker;
  HeadPhone headphone;

  // create adpaters
  BluetoothAdapter bluetoothAdp(&bluetooth);
  SpeakerAdapter speakerAdp(&speaker);
  HeadPhoneAdapter heaphoneAdp(&headphone);

  // manager1.setPlayer(&bluetoothAdp);
  manager1.setPlayer(&speakerAdp);
  cout << endl;
  manager1.showAllSongs();
  cout << endl;
  manager1.playSong(2);
  cout << endl;
}