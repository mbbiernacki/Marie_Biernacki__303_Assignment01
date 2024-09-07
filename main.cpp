//CS303 ASSIGNMENT 01: 1-D ARRAY
//NAME: Marie Biernacki
//CREATED: August 31st, 2024
//DUE: September 9th, 2024

#include "Header.h"


int main()
{
    //initalize temporary array which will store the data from the file
    int* tempArray = new int[1] {0};
    int tempSize = 1;

    //call readFile and operations functions
    readFile(tempArray, tempSize);

    operations(tempArray, tempSize);

}
