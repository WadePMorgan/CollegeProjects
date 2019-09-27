#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>

/**
Author:   Wade P Morgan
Date:     4/4/19
*/

#include<stdio.h>

using namespace std;
  // swaps two elements
  void swap(float* a, float* b)
  {
    float t = *a;
    *a = *b;
    *b = t;
  }

  /**
  Summary:  sets last element as pivot and places all elements
      smaller than pivot to left of pivot and all elements
      greater to right of pivot
  @Params
      an array named arr of floating point values to be sorted
      an integer named low to indicate the starting index
      an integer named high to indicate the final index
  @Return
      an integer
  */
  int partition(float arr[], int low, int high)
  {
    float pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
      // check if current element <= pivot
      if (arr[j] <= pivot)
      {
        i++;
        swap(&arr[i], &arr[j]);
      }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
  }

    /*
    Sumary:  The function for implementing QuickSort
    @Params
        an array named arr of floating point values to be sorted
        an integer named low to indicate the starting index
        an integer named high to indicate the final index
    */
  void quickSort(float arr[], int low, int high)
  {
    if (low < high)
    {
      // pIndex is the partitioning index
      int pIndex = partition(arr, low, high);

      // Divide & Conquer
      quickSort(arr, low, pIndex - 1);
      quickSort(arr, pIndex + 1, high);
    }
  }

  // Random Number Generator
  void generateRandomNumbers(float*arr, int j)
  {
    srand((unsigned)time(0));
    for (int i = 0; i < j; i++)
    {
      arr[i] = rand();
    }
  }

  // Driver
  int main()
  {
    clock_t start, end;
    double msecs, avgmsecs;
    ofstream outfile, avgoutfile;
    outfile.open("Morgan_Wade_executiontime.txt");
    avgoutfile.open("Morgan_Wade_averageExecutiontime.txt");
    outfile << "input size               execution time(in millisecs)" << endl;
    avgoutfile << "input size               average execution time(in millisecs)" << endl;

    for (int j = 10; j < 100001; j = j * 10)
    {
      avgmsecs = 0;
      for (int i = 0; i < 100; i++)
      {
        float* arr = new float[j];
        generateRandomNumbers(arr, j);
        start = clock();

        quickSort(arr, 0, j - 1);

        end = clock();
        msecs = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        outfile << " " << j << "                   " << msecs << endl;

        avgmsecs += msecs;
      }
      avgoutfile << " " << j << "                   " << avgmsecs << endl;
    }

    return 0;
  }
