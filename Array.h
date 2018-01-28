#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

class Array
{
public:
    Array(); // constructor
    Array(int); // copy constructor
    ~Array(); // destructor

    int getsize(); // Function to access the size
    void Display(); // Display the content of the array
    void addElementBeginnig(int); // Function to Add an element at the beginning
    void addElementEnd(int); // Function to Add an element at the end
    void removeBeginning(); // Function to Remove an element at the beginning
    void removeEnd(); // Function to Remove an element at the end
    void inverse(); // inverse the order of elem in array
    int sumArray(); // return the sum of the elements of the array
    void fDisplay(char*); // Function to Display the content of the array in a file through fstream
    int* oddNumber(); // return array with odd numbers
    int* operator+(const Array&)const; // concat 2 arrays of size n and m into a new array

    int sizeOfArray; // size of the array

    int *arrayData; // array

protected:

private:

};


#endif // ARRAY_H_INCLUDED
