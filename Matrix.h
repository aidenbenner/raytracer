
#ifndef MATRIX_H
#define MATRIX_H 

#include <vector>
using namespace std;
class Matrix { 
  public:
    void Transform(double x); 
    void Transpose();
    void Inverse();

    Matrix(int row, int height); 

    inline vector<double> & operator [] (int row) {
      return mat[row];
    };

    void RowSwap(int a, int b);
    void RowConstMult (int row, double c);
    void RowAddMult (int row, int rowB, double c);
    void Print(); 

    inline int getWidth(){ return width; };
    inline int getHeight(){ return height; }; 

  private:
    int width;
    int height;
    vector<vector<double>> mat;  
};

#endif 
