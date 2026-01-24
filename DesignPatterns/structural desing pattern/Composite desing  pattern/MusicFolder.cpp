#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class MusicComponent
{
public:
  virtual void play() = 0;
  virtual ~MusicComponent() = default;
};

// songs
class Song : public MusicComponent
{
  string name;

public:
  Song(const string name) : name(name) {};
  void play() override
  {
    cout << "    song: " << name << endl;
  }
};

class PlayList : public MusicComponent
{
  string name;
  vector<MusicComponent *> list;

public:
  PlayList(const string name) : name(name) {};

  void addSong(MusicComponent *song)
  {
    list.push_back(song);
  }

  void play() override
  {
    cout << "PlayList: " << name << endl;
    for (auto it : list)
    {
      it->play();
    }
  }

  void removeSong(MusicComponent *song)
  {
    list.erase(remove(list.begin(), list.end(), song), list.end());
  }

  ~PlayList()
  {
    for (auto s : list)
      delete s;
  }
};

// cline code
int main()
{
  Song s1("Beliver");
  Song s2("Twinkle Twinkle Little star");
  Song s3("stars in the sky");
  Song s4("Lighter than light");

  PlayList p1("MyFavs");
  p1.addSong(&s1);
  p1.addSong(&s2);
  p1.addSong(&s3);

  PlayList mainPlayList("Music");
  mainPlayList.addSong(&s4);
  mainPlayList.addSong(&p1);

  mainPlayList.play();
}
