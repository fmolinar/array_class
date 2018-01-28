#include "Array.h"
#include <iostream>
#include <fstream> // ofstream
#include <stdlib.h>


Array::Array(){ } //Default constructor creation

Array::Array(int val) // copy constructor with size
{
    sizeOfArray = val; // desire user size
    // arrayData = (int*) malloc(sizeof(int)*sizeOfArray); // allocation using malloc (C)
   arrayData = new int[sizeOfArray];

   // assign arbitrary values for the new array
    for(int i = 0; i < sizeOfArray; i++)
    {
        arrayData[i] = i;
    }

}
Array::~Array(){ } // Destructor for the class
int Array::getsize()
   {
        return sizeOfArray;
   }
void Array::Display()
{
    for(int i = 0; i < sizeOfArray; i++)
    {
        std::cout<<arrayData[i]<<" ";
    }
    std::cout<<std::endl;
}
void Array::addElementBeginnig(int Top)
{
   sizeOfArray = sizeOfArray + 1; // expand the array for the new elem
    arrayData = (int*)realloc(arrayData,sizeof(int) * sizeOfArray); // reallocate new size
    // of the array in the heap

    for(int i = sizeOfArray - 1; i > 0; i--)
    {   arrayData[i] = arrayData[i-1];}
        arrayData[0] = Top;

}
void Array::addElementEnd(int Bottom)
{
    sizeOfArray = sizeOfArray + 1; // expand the size of the array
    arrayData = (int*)realloc(arrayData, sizeof(int) * sizeOfArray);

    arrayData[sizeOfArray - 1] = Bottom;
}
void Array::removeBeginning()
{
    for(int i = 0; i < sizeOfArray; i++)
    { arrayData[i] = arrayData[i + 1];} // shift the elements to the right
    arrayData[sizeOfArray - 1] = NULL; // delete last element
}
void Array::removeEnd()
{
    arrayData[sizeOfArray - 1] = NULL; // delete last element
}
void Array::inverse()
{
    /*reverse the array by cutting it in half and swapping the elements*/
    int temp;

    for(int i = 0; i < sizeOfArray/2; i++ )
    {
        temp = arrayData[i];
        arrayData[i] = arrayData[sizeOfArray - i - 1];
        arrayData[sizeOfArray - i - 1] = temp;
    }
}
int Array::sumArray()
{
    int sum = 0;
    for(int i = 0; i < sizeOfArray; i++)
                sum += arrayData[i];
    return sum;

}
void Array::fDisplay(char* filename)
{
    std::ofstream myfile;
    myfile.open(filename);
    for(int i = 0; i < sizeOfArray; i++)
    {
        myfile<<arrayData[i]<<"\n";
    }
    myfile.close();
}
int* Array::oddNumber()
{
    bool isOdd = true;
    for(int i = 0; i < sizeOfArray; i++)
    {
        if(arrayData[i] % 2 == 0)
        {
            isOdd = false;
            break;
        }
    }
    if(isOdd) return arrayData;
    else return NULL;
}

int* Array::operator+(const Array& M) const
{
    int totalSize = this->sizeOfArray + M.sizeOfArray; // getting total size of arr_n[] + arr_m[]
    int* result = new int[totalSize]; // creating new array = N + M arrays

    for(int i = 0; i < totalSize; i++)
    {
        if(i < this -> sizeOfArray)
            result[i] = this -> arrayData[i];
        else
            result[i] = M.arrayData[i - this -> sizeOfArray];

    }
    return result;
}
