#include <bits/stdc++.h>
using namespace std;

// Abstract class (SortStrategy)
class SortingStrategy
{
public:
  virtual void sort(vector<int> &vec) = 0;
  virtual ~SortingStrategy() = default;
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
      for (int j = 0; j < vec.size() - 1; j++)
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
  unique_ptr<SortingStrategy> strategy;

public:
  SortingContext(unique_ptr<SortingStrategy> s) : strategy(move(s)) {};

  // set strategy
  void setStrategy(unique_ptr<SortingStrategy> s)
  {
    strategy = move(s);
  }

  void sort(vector<int> &vec)
  {

    this->strategy->sort(vec);
    cout << "Sorting Done " << endl;
  }
};

int main()
{
  SortingContext sctx(make_unique<BubbleSorting>());
  vector<int> vec = {8, 6, 3, 9, 7};
  sctx.sort(vec);

  // print
  for (auto it : vec)
  {
    cout << it << " ";
  }
  cout << endl;

  // change the startegy
  vector<int> vec1 = {8, 7, 6, 5, 4, 3, 2, 1};

  sctx.setStrategy(make_unique<SelectionSorting>());
  sctx.sort(vec1);

  // print
  for (auto it : vec1)
  {
    cout << it << " ";
  }
  cout << endl;
}