#include <bits/stdc++.h>
using namespace std;

// Abstract class (SortStrategy)
class SortingStrategy
{
public:
  virtual void sort(vector<int> &vec) = 0;
};

// concrete strategies
// buble sort
class BubbleSorting : public SortingStrategy
{
public:
  void sort(vector<int> &vec)
  {
    for (int i = 0; i < vec.size(); i++)
    {
      for (int j = 0; j <= vec.size() - 1; j++)
      {
        if (i != j && vec[j] > vec[j + 1])
        {
          swap(vec[j], vec[j + 1]);
        }
      }
    }
  }
};

// selection sort
class SelectionSorting : public SortingStrategy
{
public:
  void sort(vector<int> &vec)
  {
    for (int i = 0; i < vec.size(); i++)
    {
      int idx = i;
      for (int j = i + 1; j < vec.size(); j++)
      {
        if (vec[j] < vec[idx])
        {
          idx = j;
        }
      }
      swap(vec[i], vec[idx]);
    }
  }
};

// create a context
class SortingContext
{
  SortingStrategy *strategy;

public:
  SortingContext()
  {
    // by default bubble sorting
    this->strategy = new BubbleSorting();
  }

  // set strategy
  void setStrategy(SortingStrategy &str)
  {
    this->strategy = &str;
  }

  void sort(vector<int> &vec)
  {

    this->strategy->sort(vec);
    cout << "Sorting Done " << endl;
  }

  ~SortingContext()
  {
    delete strategy;
  }
};

int main()
{
  SortingContext *sctx = new SortingContext();
  vector<int> vec = {8, 6, 3, 9, 7};
  sctx->sort(vec);

  // print
  for (auto it : vec)
  {
    cout << it << " ";
  }
  cout << endl;

  // change the startegy
  vector<int> vec1 = {8, 7, 6, 5, 4, 3, 2, 1};
  SelectionSorting s;
  sctx->setStrategy(s);
  sctx->sort(vec1);

    // print
  for (auto it : vec1)
  {
    cout << it << " ";
  }
  cout << endl;
  delete sctx;
}