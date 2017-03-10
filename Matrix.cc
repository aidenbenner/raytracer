#include <cassert>
#include <cstdio>
#include <iostream>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(int row, int col){
  height = row;
  width = col;
  assert(row > 0 && height > 0); 
  mat.resize(row); 
  for(int i = 0; i<row; i++){
    mat[i].resize(col); 
    for(int k = 0; k<height; k++){
      mat[i][k] = 0; 
    }

  }
}

void Matrix::RowSwap(int a, int b){
  for(int i = 0; i<width; i++){
    double hold = mat[a][i]; 
    mat[a][i] = mat[b][i];
    mat[b][i] = hold;
  }
}

void Matrix::RowConstMult (int row, double c){
  for(int i = 0; i<width; i++){
    mat[row][i] *= c;
  }
}

void Matrix::RowAddMult (int row, int rowB, double c){
  for(int i = 0; i<width; i++){
    mat[row][i] += mat[rowB][i] * c;
  }
}

void Matrix::Transpose() {
  for(int i = 0; i<width; i++){
    for(int k = 0; k<height; k++){
      double hold = mat[i][k]; 
      mat[i][k] = mat[k][i]; 
      mat[k][i] = hold;
    }
  }
}

void Matrix::Inverse() {
  assert(width == height);
}

void Matrix::Print() {
  for(int i = 0; i<height; i++){
    cout << "[";
    for(int k = 0; k<width; k++){
      cout <<  mat[i][k];
      if(k != width - 1)
        cout << ",";
    }
    cout << "]" << endl;
  }
}

void mat_test(){
  Matrix mat(5,5); 
  mat[1][2] = 5; 
  cout << mat[1][2] << endl;
  mat.Print(); 
}



