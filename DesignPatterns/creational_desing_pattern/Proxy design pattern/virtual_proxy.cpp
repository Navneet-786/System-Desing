#include <iostream>
#include <string>
using namespace std;

// load the things when needed
class Image
{
public:
  virtual void display() = 0;
  virtual ~Image() = default;
};

// heavy object->subject
class HDRealImage : public Image
{
  string fileName;

public:
  HDRealImage(const string name) : fileName(name)
  {
    cout << "Loading HD Image " << name << endl;
  };

  void display() override
  {
    cout << "displaying image " << fileName << endl;
  }
};

// proxy
class HDImageProxy : public Image
{
  Image *hdRealImage;
  string fileName;

public:
  HDImageProxy(const string name) : fileName(name), hdRealImage(nullptr) {};

  void display() override
  {
    // verify image exist or not
    if (!hdRealImage)
    {
      // laod the image
      hdRealImage = new HDRealImage(fileName);
    }
    hdRealImage->display();
  }

  ~HDImageProxy()
  {
    delete hdRealImage;
  }
};

int main()
{
  Image *user1 = new HDImageProxy("image1.png");
  user1->display();

  Image *user2 = new HDImageProxy("image2.png");
  user2->display();
}