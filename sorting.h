//
//  sorting.h
//  Project3_sorting
//
//  Created by Noah Schlickeisen on 3/8/21.
//  CS 3358 Data Structures and Algorithms (Section 3358-256)
//
//
// This file has a series of functions containing sorting
// algoritms that count the number of times the arrar is
// written to (eg: array[i] = value) while exicuting.
// The sorthing algoritms within this file consist of
// selection, insertion, and a quicksort/insertionsort hybrid.
// The file also counts the number of times an array is written to.
//

#ifndef sorting_h
#define sorting_h
#include <iostream>
using namespace std;

// Data type for arrays
template <typename ItemType>

class Sorting
{
private:
    
    int count = 0;          // Total Quick sort writes

    
    /*----------------------------------------------------------------
                                Swap
     Swaps the array elements passed through the function. After
     elements have been swaped the number of array writes inclemented
     during the writes is returned. Parametes consists *x and *y which
     represent the array elements count (the number of writes).
    ------------------------------------------------------------------*/
    int swap(ItemType *x, ItemType *y, int count)
    {
        ItemType temp = *x;
        *x = *y;
        *y = temp;
        
        return count += 2;
    }
    
    // Divides arrrays for quick sort
    int partition(ItemType values[], int low, int high);
    
    // Genarates random pivot for quick sort
    int partitionRand(ItemType values[], int low, int high);
    
public:
    // Functions containing sorting algorithms
    int SelectionSort(ItemType values[], int numValues);
    int InsertionSort(ItemType values[], int numValues);
    int QuickSort(ItemType values[], int left, int right);
    
};


/*----------------------------------------------------------------
                        Selection sort
Sorts the values in the array using the selection sort algorithm.
Parameters int values array with the template data type, and the
sizer of the arrray numValues. The function returns the number of
time the array has been written to.
------------------------------------------------------------------*/
template <typename ItemType>
int Sorting<ItemType>::SelectionSort(ItemType values[], int numValues)
{
    
    int i, j, mindex;
    
    // total writes
    int count = 0;
    
    // Iterate through array
    for (i = 0; i < numValues-1; i++)
    {
        mindex = i;
        
        // Iterate through array till lowest value found
        for (j = i+1; j < numValues; j++)
        {
            if (values[j] < values[mindex])
            {
                mindex = j;
                
            }
        }
        // Swap the lowest value for value in currrent spot
        count = swap(&values[mindex], &values[i], count);

    }
    // Return total writes
    return count;
}


/*----------------------------------------------------------------
                        Insertion sort
Sorts the values in the array using the inserrtion sort algorithm.
Parameters int values array with the template data type, and the
sizer of the arrray numValues. The function returns the number of
time the array has been written to.
------------------------------------------------------------------*/
template <typename ItemType>
int Sorting<ItemType>::InsertionSort(ItemType values[], int numValues)
{
    int i, key, j;
    
    // Total writes
    int count = 0;
    
    // Iterates through arrray intitatng a key value
    // and index behind key
    for (i = 1; i < numValues; i++)
    {
        key = values[i];
        j = i - 1;
        
        // Iterate j till j value greater then key found
        while (j >= 0 && values[j] > key)
        {
            values[j + 1] = values[j];
            j -= 1;
            count += 1;
        }
        // Assign key to index ahead j
        values[j + 1] = key;
        count += 1;
    }
    return count;
}



/*----------------------------------------------------------------
                         partition
This function goes through an array and sparates it based on values
less or greater then a pivot value. The parameters in the is array
include the values array. the left most index of the array and the
right most index in the array. The function return the index of pivot.
------------------------------------------------------------------*/
template <typename ItemType>
int Sorting<ItemType>::partition(ItemType values[], int left, int right)
{
    int pivot = values[right];
    
    int i = (left - 1);
    
    // Values lest then pivot go behind pivot
    for (int j = left; j < right; j++)
    {
        if(values[j] <= pivot)
        {
            i++;
            count = swap(&values[i], &values[j], count);
        }
    }

    count = swap(&values[i+1], &values[right], count);
    
    // return pivot index
    return (i + 1);
}


/*----------------------------------------------------------------
                        Partition Rand
This function generates a random values to serve as the index of
the pivot in the array being passed throught partition function.
The parameters in the is array include the values array. the left
most index of the array and the right most index in the array.
------------------------------------------------------------------*/
template <typename ItemType>
int Sorting<ItemType>::partitionRand(ItemType values[], int left, int right)
{
    // Generate random number between left and right
    srand(time(NULL));
    int random = left + rand() % (right - left);
    
    // Make the random the most right element
    count = swap(&values[random], &values[right], count);
    
    return partition(values, left, right);
}


/*----------------------------------------------------------------
                         Quick Sort
This function sorts and arrray using the quick sort a;lgorithm. The
quick sort recursively dived arrays based on its values being less
then of equal a random pivot chossen. Once there is no more diving,
the array will be sorted The parameters in the is array. The parameters
consist of the values array, the left most index and the right most index.
The function return the number writes implemented by the algoritm.
------------------------------------------------------------------*/
template <typename ItemType>
int Sorting<ItemType>::QuickSort(ItemType values[], int left, int right)
{
    // If there are still array to be partioned
    if (left < right)
    {
        // Use insertion sort to sort the smallerr arrays
        if((right - left) + 1 < 70)
        {
            count += InsertionSort(values, (right - left) + 1);
        } else
        {
            
            // Split the arrays based on pivot
            int pivot = partitionRand(values, left, right);

            QuickSort(values, left, pivot - 1);
            
           // pivot = partitionRand(values, left, right);
            QuickSort(values, pivot + 1, right);

        }
    }
    return count;
}


#endif /* sorting_h */

