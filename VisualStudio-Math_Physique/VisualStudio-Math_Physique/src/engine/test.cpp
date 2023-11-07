#include <iostream>
#include "Quaternion.h"

void print_quaternion(Quaternion q){
    std::cout << "Quaternion(" << q.w << " " << q.x << " " << q.y << " " << q.z << ")" << std::endl;
}

int main(){
    std::cout << "bonjour" << std::endl;
    Quaternion q1 = Quaternion(1,2,3,4);
    print_quaternion(q1);
    Quaternion q2 = Quaternion(0,1,1,0);
    print_quaternion(q2);
    Quaternion q3 = Quaternion(0,0,0,1);
    print_quaternion(q3);
    Quaternion q4 = Quaternion(0,0,0,0);
    print_quaternion(q4);
    Quaternion q5 = Quaternion(0.5,0.5,0.5,0.5);
    print_quaternion(q5);
    Quaternion q6 = Quaternion(Vecteur3D(1,2,3), 0);
    print_quaternion(q6);
    Quaternion q7 = Quaternion(Vecteur3D(1,2,3), 3.141592653);
    print_quaternion(q7);
    return 0;
}