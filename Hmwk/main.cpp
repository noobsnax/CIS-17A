#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void sort(string [], int);
int binarysearch(string[], int, string);
void reversestr(string& );

int main(int argc, char** argv) {
    
    
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                                "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                                "Taylor, Terri", "Johnson, Jill",
                                "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                                "James, Jean", "Weaver, Jim", "Pore, Bob",
                                "Rutherford, Greg", "Javens, Renee",
                                "Harrison, Rose", "Setzer, Cathy",
                                "Pike, Gordon", "Holland, Beth" };
    int holder;
    string employee;
    
    //this is a selection sort
    sort(names,NUM_NAMES);    
       
    cout << "Enter the employee you wish to search for:";
    getline(cin,employee);
    
    holder = binarysearch(names,NUM_NAMES,employee);
   
            
    if(holder==-1)
        cout << "That employee doesn't exist in the array";
    else   
        cout << "Employee is found in element " << holder << " in the array\n";
      
    
    return 0;
}


//selection sorting 
void sort(string employee[], int size){
    int scan, minIndex;
    string minimum;
    
    for (scan = 0; scan < (size -1); scan++)
    {
        minIndex = scan;
        minimum = employee[scan];
        for (int index = (scan + 1); index < size; index++)
        {
            if(employee[index]<minimum)
            {
                minimum = employee[index];
                minIndex = index;
            }
        }
        employee[minIndex] = employee[scan];
        employee[scan] = minimum;
   }
}   

//binary search
int binarysearch(string names[], int NUM_NAMES, string value)
{
    int first = 0,
            last = NUM_NAMES - 1,
            middle, 
            pos = - 1;
    bool found = false;
    
    while(!found && first <= last)
    {
        middle = (first + last) / 2;
        if(names[middle]==value)
        {
            found = true;
            pos = middle;
        }
        else if(names[middle] > value)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return pos;
}

/*output the array contents*/
void showArray(string array[], int size){
    for (int count = 0; count < size; count++)
    {
        cout << array[count] << "\t\n";
    }
}

