
#include "Header.h"

//FUNCTION DEFINITIONS


bool isDigits(string str1) {
	return (str1.find_first_not_of("0123456789") == string::npos);
}


void readFile(int*& tempArray, int& tempSize) {

    ifstream inFile("A1input.txt");

    if (!inFile.is_open()) {
        cout << "ERROR: A1input.txt could not be opened." << endl;
        return;
    }

    string currentLine;
    string combinedLine;

    while (getline(inFile, currentLine)) {
        combinedLine += currentLine + " "; //combine lines with space in between
    }

    inFile.close();

    stringstream ss(combinedLine);
    string tempString;
    int numberCount = 0;

    //count the number of extractions needed using whitespace as delimeter
    while (ss >> tempString) {
        numberCount++;
    }

    //create the array based on the numberCount, assign tempSize to the numberCount
    tempArray = new int[numberCount];
    tempSize = numberCount;

    //reset stringstream before reading the string again, this time adding values to the array
    ss.clear();
    ss.str(combinedLine);

    int index = 0;
    while (ss >> tempString) {
        //use try-catch to convert string to integer when adding to the array, warning message if exception is thrown
        try {
            
            if (!isDigits(tempString)) {
                throw invalid_argument("ERROR: Non-integer data found: " + tempString);
            }
            
            tempArray[index++] = stoi(tempString);
        }

        catch (invalid_argument e) {
            cout << e.what() << endl;
        }
    }

    //once the function is completed, output the appropriate message
    cout << "The data from A1input.txt has been loaded into an array." << endl;


}


void operations(int arr[], int arrSize) {

    string userSelect;
    int userNum;

    cout << "\n\nWhat would you like to do next ? " << endl;

    while (true) {
        //display the menu
        cout << "\n1. Check if an integer exists in the array.\n"
            << "2. Change an integer's value at a specified index.\n"
            << "3. Add an integer to the end of the array.\n"
            << "4. Remove an integer from a specific index.\n"
            << "5. Exit the program." << endl;

        //get user input
        cout << "\n\nPlease enter your choice: ";
        cin >> userSelect;

        //validate input
        if (!isDigits(userSelect)) {
            cout << "ERROR: Invalid input. Please enter either 1, 2, 3, 4, or 5." << endl;
            continue;
        }

        //convert input to integer
        userNum = stoi(userSelect);

        //based on userNum, call either doesExist, modifyValue, addInteger, removeIdx, or end the program
        //if the userNum is not valid, ask for proper input
        if (userNum == 1) {
        
            doesExist(arr, arrSize);

            cout << "\n\nWhat would you like to do next?" << endl;
        }

        else if (userNum == 2) {
            
            modifyValue(arr, arrSize);

            cout << "\n\nWhat would you like to do next?" << endl;
        }
        else if (userNum == 3) {
            
            addInteger(arr, arrSize);
            
            cout << "\n\nWhat would you like to do next?" << endl;
        }
        else if (userNum == 4) {
            
            removeIdx(arr, arrSize);

            cout << "\n\nWhat would you like to do next?" << endl;
        }
        else if (userNum == 5) {
            cout << "\nExiting the program...\n" << endl;
            break;
        }
        else {
            cout << "ERROR: Invalid input. Please enter either 1, 2, 3, 4, or 5." << endl;
        }
    }


};


bool doesExist(int arr[], int arrSize) {
    
    string userNum;

    //set validInput to false
    bool validInput = false;

    //initialize while loop and try-catch blocks to verify user input
    while (!validInput) {

        cout << "Enter the value you want to find in the array: " << endl;
        cin >> userNum;


        try {

            //throw exceptions if the userNum is not an integer
            if (!isDigits(userNum)) {
                throw invalid_argument("\nERROR: Value needs to be an integer.");
            }
        
            else {
               
                for (int i = 0; i < arrSize; i++) {
                    if (arr[i] == stoi(userNum)) {
                        cout << "\nThe number " << userNum << " was found at index " << i << endl;
                        validInput = true;
                        
                        return true;
                    }
                }

                cout << "\nThe number " << userNum << " was not found in the array." << endl;
                validInput = true;
                
                return false;


            }

        }

        //catch block tells the user the error, prompts for input
        catch (invalid_argument e) {
            cout << e.what() << endl;
            cout << "Please try again.\n" << endl;
        }

    }

}


void modifyValue(int arr[], int arrSize) {

    string idx, newNum;

    //set validInput to false
    bool validInput = false;

    //initialize while loop and try-catch blocks to verify user input
    while (!validInput) {
        
        cout << "Enter the index number you would like to modify: " << endl;
        cin >> idx;


        try {

            //throw exceptions if the idx is not an integer or out of bounds
            if (!isDigits(idx)) {
                throw invalid_argument("\nERROR: Index needs to be an integer value.");
            }
            else if (stoi(idx) < 0 || stoi(idx) >= arrSize) {
                throw invalid_argument("\nERROR: Index out of bounds.");
            }

            else {

                cout << "\nEnter the value you want at index " << idx << ": " << endl;
                cin >> newNum;

                //throw exception if the value given is not an integer
                if (!isDigits(newNum)) {
                    throw invalid_argument("\nERROR: Value needs to be an integer.");
                }

                //output the old and new values, update validInput to true
                cout << "The old value at index " << idx << " was " << arr[stoi(idx)] << endl;
                arr[stoi(idx)] = stoi(newNum);

                cout << "The new value at index " << idx << " is " << arr[stoi(idx)] << endl;

                validInput = true;


            }

        }

        //catch block tells the user the error, prompts for input
        catch (invalid_argument e) {
            cout << e.what() << endl;
            cout << "Please try again.\n" << endl;
        }
    
    }

}


void addInteger(int*& arr, int& arrSize) {
    
    string newInt;

    //set validInput to false
    bool validInput = false;

    //initialize while loop and try-catch blocks to verify user input
    while (!validInput) {

        cout << "Enter the number you would like to add to the end of the array: " << endl;
        cin >> newInt;


        try {

            //throw exceptions if the newInt is not an integer
            if (!isDigits(newInt)) {
                throw invalid_argument("\nERROR: Number needs to be an integer value.");
            }
           
            //update newSize to current arrSize + 1 and create a new array using the newSize
            int newSize = arrSize + 1;
            int* newArr = new int[newSize];

            //use for loop to copy all existing elements in the current arr to newArr
            for (int i = 0; i < arrSize; i++) {
                newArr[i] = arr[i];
            }

            //add the new element, update the array size
            newArr[arrSize] = stoi(newInt);

            arrSize = newSize;

            //delete the old array and reassign arr to newArr
            delete[] arr;
            arr = newArr;

            cout << "\nThe number " << newInt << " was added to the end of the array." << endl;

            validInput = true;


            }

        //catch block tells the user the error, prompts for input
        catch (invalid_argument e) {
            cout << e.what() << endl;
            cout << "Please try again.\n" << endl;
        }

    }

}


void removeIdx(int*& arr, int& arrSize) {
    
    string idx;

    //set validInput to false
    bool validInput = false;

    //initialize while loop and try-catch blocks to verify user input
    while (!validInput) {

        cout << "Enter the index number of the value to remove: " << endl;
        cin >> idx;


        try {

            //throw exceptions if the idx is not an integer
            if (!isDigits(idx)) {
                throw invalid_argument("\nERROR: Index needs to be an integer value.");
            }
            else if (stoi(idx) < 0 || stoi(idx) >= arrSize) {
                throw invalid_argument("\nERROR: Index out of bounds.");
            }

            //update smallerSize to arrSize -1 and create a smallerArr using the smallerSize
            int smallerSize = arrSize - 1;
            int* smallerArr = new int[smallerSize];

            //use a for loop to copy all existing elements into the smallerArr, EXCEPT for the element at idx
            for (int i = 0, j = 0; i < arrSize; i++) {
                if (i != stoi(idx)) {
                    smallerArr[j] = arr[i];
                    j++;
                }
            }

            //update the arrSize to smallerSize, delete the old array, reassign arr to smallerArr
            arrSize = smallerSize;

            delete[] arr;
            arr = smallerArr;

            cout << "\nThe value at index " << idx << " was removed." << endl;

            validInput = true;


        }

        //catch block tells the user the error, prompts for input
        catch (invalid_argument e) {
            cout << e.what() << endl;
            cout << "Please try again.\n" << endl;
        }

    }

}


