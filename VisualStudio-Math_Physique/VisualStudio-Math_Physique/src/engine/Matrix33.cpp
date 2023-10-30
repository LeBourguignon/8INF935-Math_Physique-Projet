#include "Matrix33.h"
#include <array>

Matrix33::Matrix33(){
    this->values = std::array<std::array<double, 3>, 3>();
}
Matrix33::Matrix33(std::array<std::array<double, 3>, 3> values){
    this->values = values;
}

Matrix33 Matrix33::operator+(Matrix33 other){
    std::array<std::array<double, 3>, 3> ret = std::array<std::array<double, 3>, 3>();
    for (int i=0 ; i<3 ; i+=1){
        for (int j=0 ; j<3 ; j+=1){
            ret[i][j] = this->values[i][j] + other.values[i][j];
        }
    }
    return Matrix33(ret);
}

Matrix33 Matrix33::operator-(Matrix33 other){
    std::array<std::array<double, 3>, 3> ret = std::array<std::array<double, 3>, 3>();
    for (int i=0 ; i<3 ; i+=1){
        for (int j=0 ; j<3 ; j+=1){
            ret[i][j] = this->values[i][j] - other.values[i][j];
        }
    }
    return Matrix33(ret);
}

Matrix33 Matrix33::operator-(){
    std::array<std::array<double, 3>, 3> ret = std::array<std::array<double, 3>, 3>();
    for (int i=0 ; i<3 ; i+=1){
        for (int j=0 ; j<3 ; j+=1){
            ret[i][j] = -this->values[i][j];
        }
    }
    return Matrix33(ret);
}

Matrix33 Matrix33::operator*(Matrix33 other){
    std::array<std::array<double, 3>, 3> ret = std::array<std::array<double, 3>, 3>();
    for (int i=0 ; i<3 ; i+=1){
        for (int j=0 ; j<3 ; j+=1){
            ret[i][j] = this->values[i][0]*other.values[0][j] + this->values[i][1]*other.values[1][j] + this->values[i][2]*other.values[2][j];
        }
    }
    return Matrix33(ret);
}

Matrix33 Matrix33::operator*(double x){
    std::array<std::array<double, 3>, 3> ret = std::array<std::array<double, 3>, 3>();
    for (int i=0 ; i<3 ; i+=1){
        for (int j=0 ; j<3 ; j+=1){
            ret[i][j] = this->values[i][j] * x;
        }
    }
    return Matrix33(ret);
}

Matrix33 Matrix33::operator/(double x){
    std::array<std::array<double, 3>, 3> ret = std::array<std::array<double, 3>, 3>();
    for (int i=0 ; i<3 ; i+=1){
        for (int j=0 ; j<3 ; j+=1){
            ret[i][j] = this->values[i][j] / x;
        }
    }
    return Matrix33(ret);
}

double Matrix33::determinant(){
    double a = this->values[0][0];
    double b = this->values[0][1];
    double c = this->values[0][2];
    double d = this->values[1][0];
    double e = this->values[1][1];
    double f = this->values[1][2];
    double g = this->values[2][0];
    double h = this->values[2][1];
    double i = this->values[2][2];
    return a*e*i + d*h*c + g*b*f - a*h*f - g*e*c - d*b*i;
}

Matrix33 Matrix33::inverse(){
    double det = this->determinant();
    double a = this->values[0][0];
    double b = this->values[0][1];
    double c = this->values[0][2];
    double d = this->values[1][0];
    double e = this->values[1][1];
    double f = this->values[1][2];
    double g = this->values[2][0];
    double h = this->values[2][1];
    double i = this->values[2][2];
    std::array<std::array<double, 3>, 3> ret = std::array<std::array<double, 3>, 3>();
    ret[0][0] = e*i - f*h;
    ret[0][1] = c*h - b*i;
    ret[0][2] = b*f - c*e;
    ret[1][0] = f*g - d*i;
    ret[1][1] = a*i - c*g;
    ret[1][2] = c*d - a*f;
    ret[2][0] = d*h - e*g;
    ret[2][1] = b*g - a*h;
    ret[2][2] = a*e - b*d;
    return Matrix33(ret)/det;
}