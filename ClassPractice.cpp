#include "ClassPractice.h"
#include <iostream>
using namespace std;
ClassPractice::ClassPractice()
{
    cout << "no parameters" << endl;
    val1=0;
    val2=0;
}
ClassPractice::ClassPractice(int n, int m)
{

    val1 = n;
    val2 = m;
    //cout << "n:" << n << endl;
    //cout << "m:" << m << endl;
    //ctor
}

void ClassPractice::printValues(){
    cout << "n:" << val1 << " and m:"<< val2<< endl;
}
