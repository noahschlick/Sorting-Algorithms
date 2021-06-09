//
//  testsorting.cpp
//  Project3_sorting
//
//  Created by Noah Schlickeisen on 3/8/21.
//  CS 3358 Data Structures and Algorithms (Section 3358-256)
//
//
// This file test sorting algoritms and displays the number of
// the array being sorrted was assigned a value. The file uses
// sorting.h for an insertion sort, selectionsort, and quick sort
// algoritm. The file, testsorting.cpp contains a function for
// counting sort and only displays the result of the arrays for
// counting sort.
//
//

#include<iostream>
#include "sorting.h"

using namespace std;

// Fill the array in incremental order
// Parameters include array and the number
// of values it holds.
// The function returns the array.
int* fillForwards(int values[], int numValues)
{
    for(int i = 0; i < numValues; i++)
        values[i] = i;
    return values;
}

// Fill the array in decremental order
// Parameters include array and the number
// of values it holds.
// The function returns the array.
int* fillBackwards(int values[], int numValues)
{
    for(int i = 0; i < numValues; i++)
        values[i] = -i;
    return values;
}

// Fill the array withe incrementing evenas and decrementing odds
// Parameters include array and the number
// of values it holds.
// The function returns the array.
int* fillOddBackwards(int values[], int numValues)
{
    for(int i = 0; i < numValues; i++)
        if (i % 2 == 0)
            values[i] = i;
        else
            values[i] = -i;
    return values;
}

// Display the firs 5 values in the array
// Parameters include array and the number
// of values it holds.
void displayFirstFifty(int values[], int numValues)
{
    for(int i = 0; i < 50; i++)
    {
        cout << values[i];
            
        if (i < 49)
            cout << ",";
    }
    cout << "...";
}

// Get the max value in the array.
// Parameters include array and the number
// of values it holds.
// Thhe function return the max number in the array
int getMax(int array[], int size)
{
   int max = array[1];
    
   for(int i = 2; i<=size; i++) {
      if(array[i] > max)
         max = array[i];
   }
    
   return max; //the max element from the array
}

/*----------------------------------------------------------------
                        Counting sort
This fucntion sorts an array using the counting sort algoritm.
The counting sort algoritm will count the total number of the same
values within the array. The algorthm will then use the total number
of values with the orginal array for indexing tosorting. Parameters
 include array and the number of values it holds.
------------------------------------------------------------------*/
void countSort(int *array, int size)
{
    // add arrray size to each value to accomodate negative values
    for (int i = 0; i <= size; i++)
    {
        array[i] += size;
    }
    
   int output[size+1];
    
   int max = getMax(array, size);
    
    // Create array to count the number of each element
    int count[max+1];
    
    //initialize count array to all zero
    for (int i = 0; i<=max; i++)
        count[i] = 0;
    
    //Count the values in the orginal array
    for (int i = 1; i <=size; i++)
        count[array[i]]++;
    
    //Index the the total number of value one apot ahead
    for (int i = 1; i<=max; i++)
        count[i] += count[i-1];
    
    // index the values in the orginal arrays, acording
    // to the values in the count array
    for (int i = size + 1; i >= 0; i--)
    {
        output[count[array[i]]] = array[i];
        count[array[i]] -= 1;
    }
    
    //store to main array
    for (int i = 0; i < size; i++)
    {
        
            array[i] = (output[i + 1] - (size));
    }
    
  
}

// Display the test reesults for all arrays being sorted
// under selection sort.
// // The function calls selection sort method is sorting.h
// Parameters include values array, size of array and a
// sorting class object.
void displaySelection(int values[], int numValues, Sorting<int> sort)
{
    int writes = 0;
    cout << "Before: ";
    displayFirstFifty(values, numValues);
    cout << endl;
    
    writes = sort.SelectionSort(values, numValues);
    
    cout << "After: ";
    displayFirstFifty(values, numValues);
    cout << endl;
    
    cout << "Total writes: ";
    cout << writes << endl << endl;
}


// Display the test reesults for all arrays being sorted
// under Insertion sort.
// The function calls Insertion sort method is sorting.h
// Parameters include values array, size of array and a
// sorting class object.
void displayInsertion(int values[], int numValues, Sorting<int> sort)
{
    int writes = 0;
    cout << "Before: ";
    displayFirstFifty(values, numValues);
    cout << endl;
    
    writes = sort.InsertionSort(values, numValues);
    
    cout << "After: ";
    displayFirstFifty(values, numValues);
    cout << endl;
    
    cout << "Total writes: ";
    cout << writes << endl << endl;
}

// Display the test reesults for all arrays being sorted
// under Quicksort.
// The function calls quick sort method is sorting.h
// Parameters include values array, size of array and a
// sorting class object.
int displayQuickSort(int values[], int numValues, Sorting<int> sort)
{
    int writes = 0;
    cout << "Before: ";
    displayFirstFifty(values, numValues);
    cout << endl;
    
    // Sort the arrray
    writes = sort.QuickSort(values, 0, numValues - 1);
    
    cout << "After: ";
    displayFirstFifty(values, numValues);
    cout << endl;
    
    cout << "Total writes: ";
    cout << writes << endl << endl;
    
    return writes;
}

// Display the test reesults for all arrays being sorted
// under Counting sort.
// Parameters include values array, size of array.
void displayCountingSort(int values[], int numValues)
{
    cout << "Before: ";
    
    for(int i = 0; i <= 50; i++)
       cout << values[i] << ",";
    cout << "...";
    
    cout << endl;
    // Sort the array
    countSort(values, numValues);
    cout << "After: ";
    
    for(int i = 0; i <= 50 ; i++)
       cout << values[i] << ",";
    cout << "...";
    
    cout << endl << endl;
}

int main() {
    
    Sorting<int> sort;
    
    
    int numValues = 10000;  // Arrray size
    
    int countArrSz = 1000;  // Array size for counting sort
    
    // Total number of wortes to the arrray during sorting
    int writes = 0;
    
    // Sort arrays
    int test1Array[numValues];
    int test2Array[numValues];
    int test3Array[numValues];
    
    // Count sort arrays
    int countArray1[countArrSz + 1];
    int countArray2[countArrSz + 1];
    int countArray3[countArrSz + 1];
    
    
    
    
//  Selection Sort Test
//  /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
    // ReSuffle
    *test1Array = *fillForwards(test1Array, numValues);
    *test2Array = *fillBackwards(test2Array, numValues);
    *test3Array = *fillOddBackwards(test3Array, numValues);

    // Test
    cout << "Array Size for Selction, Insertion and Quick Sort "
         << numValues << endl;

    cout << "Array Size for Count Sort: " << countArrSz << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Testing selection sort...." << endl << endl;
    
    cout << "Sorted Array:" << endl;
    displaySelection(test1Array, numValues, sort);
    
    cout << "Decremented Odds:" << endl;
    displaySelection(test2Array, numValues, sort);
    
    cout << "Negative odds" << endl;
    displaySelection(test3Array, numValues, sort);
    
//  Insertion Sort Test
//  /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
    cout << "-------------------------------------------" << endl;
    // ReSuffle
    *test1Array = *fillForwards(test1Array, numValues);
    *test2Array = *fillBackwards(test2Array, numValues);
    *test3Array = *fillOddBackwards(test3Array, numValues);
    
    // Test
    cout << "Testing insertion sort...." << endl << endl;
    
    cout << "Sorted Array:" << endl;
    displayInsertion(test1Array, numValues, sort);
    
    cout << "Decremented Odds:" << endl;
    displayInsertion(test2Array, numValues, sort);
    
    cout << "Negative odds" << endl;
    displayInsertion(test3Array, numValues, sort);
    
//  Quick Sort Test
//  /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
    cout << "-------------------------------------------" << endl;
    // ReSuffle
    *test1Array = *fillForwards(test1Array, numValues);
    *test2Array = *fillBackwards(test2Array, numValues);
    *test3Array = *fillOddBackwards(test3Array, numValues);
    
    // Test
    cout << "Testing Quick sort...." << endl << endl;
    cout << "Sorted Array:" << endl;
    writes = displayQuickSort(test1Array, numValues, sort);
    
    cout << "Decremented Odds:" << endl;
    writes = displayQuickSort(test2Array, numValues, sort);
    
    cout << "Negative odds" << endl;
    writes = displayQuickSort(test2Array, numValues, sort);

    
//  Counting Sort Test
//  /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
    cout << "-------------------------------------------" << endl;
    // ReShuffle
    *countArray1 = *fillForwards(countArray1, countArrSz);
    *countArray2 = *fillBackwards(countArray2, countArrSz);
    *countArray3 = *fillOddBackwards(countArray3, countArrSz);

    

    cout << "Testing counting sort...." << endl << endl;
    
    cout << "Sorted Array:" << endl;
    displayCountingSort(countArray1, countArrSz);
    
    cout << "Decremented Odds:" << endl;
    displayCountingSort(countArray2, countArrSz);
    
    cout << "Negative odds" << endl;
    displayCountingSort(countArray3, countArrSz);
    
    srand(time(NULL));
    int random;
    for(int i = 0; i < numValues; i++)
    {
        random = 0 + rand() % (999);
        countArray3[i] = random;
    }
    
    cout << "RRandom Value Array" << endl;
    displayCountingSort(countArray3, countArrSz);

    
    return 0;
}

