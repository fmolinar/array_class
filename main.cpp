#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Array.h"

using namespace std;
// note only use new when you use a pointer
int main()
{
    cout<<"creating my first array "<<endl;

    Array A1(20);
    cout<<"size of the Array "<<A1.getsize()<<endl;
    cout<<"Display array "<<endl;
    A1.Display();
    cout<<"Adding an element at the beginning of the array: \n";
    A1.addElementBeginnig(20);
    A1.Display();
    cout<<"Adding an element at the end of the array \n";
    A1.addElementEnd(21);
    A1.Display();
    cout<<"Removing an element at the beginning of the array \n";
    A1.removeBeginning();
    A1.Display();
    cout<<"Removing an element at the end of the array \n";
    A1.removeEnd();
    A1.Display();
    cout<<"Reverse the order of the array \n";
    A1.inverse();
    A1.Display();
    cout<<"Sum of the elements in the array: ";
    cout<<A1.sumArray()<<endl;
    cout<<"Saving data into txt file \n";
    Array A(20);
    A.fDisplay("Data.txt");

    cout<<"Concatenate 2 arrays of size n and m: \n";
    Array C(20);
    Array B(10);
    int * DD;

    DD = C + B;
    for(int i=0; i<(C.getsize()+B.getsize());i++)
        cout<<DD[i]<<" ";



    cout<<"\n";
    return 0;
}
