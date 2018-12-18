#ifndef _MATRIC_H_
#define _MATRIC_H_

#include <vector>
using namespace std;

template <typename T>
class matric
{
    public:
      matric(int rows, int cols) : array(rows)
      {
          for(auto & thisRow : array)
              thisRow.resize(cols);
      }

      matric(vector<vector<T>> vv) : array{vv}
      {}
      matric(vector<vector<T>> &&vv) : array{move(vv)} 
      {}

      const vector<T> & operator[] (int row) const
      {
          return array[row];
      }
      vector<T> & operator[] (int row)
      {
          return array[row];
      }

      int numRows() const
      {
          return array.size();
      }
      int numCols() const
      {
          return numRows() ? array[0].size() : 0;
      }

    private:
      vector<vector<T>> array;
};

#endif