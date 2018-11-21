#pragma once
#include "CArray.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using std::string;

void testIntInserting20RandNumb();
void testIntAscendingSort();
void testIntDeletingEachSecondElement();
void testIntInserting10RandNumbAtRandPos();
void testIntClearContainer();

void testStringInserting15RandWordsConsistLatinLowCase();
void testStringAscendingSort();
void testStringDeletingEachWordConsistOfabcde();
void testStringInserting3RandWordAtRandPos();

int randNum(
    int from,
    int to
  );

string * const randWords(
    int randomCount
  );

template<typename TData>
void printArray(
    CArray<TData> & array,
    int size,
    string nameOfTest
  )
{
  std::cout << "---------------------------- " << nameOfTest << " Test" << " -----------------------------" << std::endl;
  if (size <= 0)
  {
    std::cout << "Container size: " << size << std::endl;
    return;
  }

  int i = 0;
  for (auto elem : array)
  {
    std::cout << "Index: " << i << "\tvalue: " << elem << std::endl;
    i++;
  }
}

template<typename TData>
void quickSort(
    CArray<TData> & array,
    int low,
    int high
  )
{
  int i = low;
  int j = high;
  TData pivot = array[(i + j) / 2];
  TData temp;

  while (i <= j)
  {
    while (array[i] < pivot)
      i++;
    while (array[j] > pivot)
      j--;
    if (i <= j)
    {
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
      i++;
      j--;
    }
  }
  if (j > low)
    quickSort(array, low, j);
  if (i < high)
    quickSort(array, i, high);
}

template<typename TData>
int randPos(
    CArray<TData> & array
  )
{
  int dinamicArraySize = array.size() - 1;
  if (dinamicArraySize == 0)
  {
    dinamicArraySize = 1;
  }
  return (0 + rand() % dinamicArraySize);
}