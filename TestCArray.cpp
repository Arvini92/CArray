#include "TestCArray.h"

CArray<int> intArray;
CArray<string> stringArray;

void testIntInserting20RandNumb()
{
  srand((int)time(0));
  int intArraySize = 20;

  for (int i = 0; i < intArraySize; i++)
  {
    intArray.push_back(randNum(0, 100));
  }

  printArray(intArray, intArray.size(), "Inserting 20 Random Numbers");
}

void testIntAscendingSort()
{
  int low = 0;
  quickSort(intArray, low, intArray.size() -1);
  printArray(intArray, intArray.size(), "Ascending Sort");
}

void testIntDeletingEachSecondElement()
{
  for (int i = intArray.size() - 1; i >= 0; i-=2)
  {
    intArray.erase(i);
  }

  printArray(intArray, intArray.size(), "Deleting Each Second Element");
}

void testIntInserting10RandNumbAtRandPos()
{
  int randomCount = 10;
  
  for (int i = 0; i < randomCount; i++)
  {
    intArray.insert(randPos(intArray), randNum(0, 100));
  }

  printArray(intArray, intArray.size(), "Inserting 10 Random Numbers At Random Positions");
}

void testIntClearContainer()
{
  intArray.clear();
  printArray(intArray, intArray.size(), "Clearing Container");
}


void testStringInserting15RandWordsConsistLatinLowCase()
{
  const int stringArraySize = 15;
  string * words = randWords(stringArraySize);

  for (int i = 0; i < stringArraySize; i++)
  {
    stringArray.push_back(words[i]);
  }

  delete [] words;
  words = nullptr;
  std::cout << "\n\n\n\n" << std::endl;
  printArray(stringArray, stringArray.size(), "Inserting 15 Random Words Consist of Latin Lower Case");
}

void testStringAscendingSort()
{
  int low = 0;
  quickSort(stringArray, low, stringArray.size() - 1);
  printArray(stringArray, stringArray.size(), "Ascending Sort");
}

void testStringDeletingEachWordConsistOfabcde()
{
  for (int i = stringArray.size() - 1; i >= 0; i--)
  {
    
    bool found = stringArray[i].find_first_of("abcde") < 100;
    
    if (found)
    {
      stringArray.erase(i);
    }
  }

  printArray(stringArray, stringArray.size(), "Deleting Each Word Consist Of 'abcde'");
}

void testStringInserting3RandWordAtRandPos()
{
  const int randomCount = 3;
  string * words = randWords(randomCount);

  for (int i = 0; i < randomCount; i++)
  {
    stringArray.insert(randPos(stringArray), words[i]);
  }

  delete [] words;
  words = nullptr;
  printArray(stringArray, stringArray.size(), "Inserting 3 Random Words At Random Positions");
}

int randNum(
    int from,
    int to
  )
{
  return (from + rand() % to);
}

string * const randWords(
    int randomCount
  )
{
  int * randomLineNumbers = new int[randomCount];
  string * randomWords = new string[randomCount];

  for (int i = 0; i < randomCount; i++)
  {
    randomLineNumbers[i] = randNum(1, 200);
  }


  std::ifstream file("words.txt");
  if (file.is_open())
  {
    string line;
    int lineNumber = 1;
    int count = 0;
    while (getline(file, line))
    {
      for (int i = 0; i < randomCount; i++)
      {
        if (randomLineNumbers[i] == lineNumber)
        {
          randomWords[count] = line;
          count++;
        }
      }
      lineNumber++;
    }
  }
  file.close();
  delete [] randomLineNumbers;
  return randomWords;
}