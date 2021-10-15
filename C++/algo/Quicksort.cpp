
#include <stdio.h>
#include <vector>

using namespace std;

template <class T>
void quicksort(vector<T> &vec, int low, int high)
{
  if (low >= high)
    return;

  int mid = (low + high) / 2;
  // choose mid point to be pivot (not a good choice (could do mm5 instead))
  swap(vec[mid], vec[low]);
  int hole = low + 1;
  T pivot = vec[low];
  for (int i = low + 1; i <= high; i++)
  {
    if (vec[i] < pivot)
    {
      swap(vec[i], vec[hole]);
      hole++;
    }
  }
  swap(vec[hole - 1], vec[low]);
  quicksort(vec, low, hole - 2);
  quicksort(vec, hole, high);
}

template <class T>
void quicksort(vector<T> &vec)
{
  quicksort(vec, 0, (int)vec.size() - 1);
}
