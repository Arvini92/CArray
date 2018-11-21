#include "CArray.h"
#include "TestCArray.h"

int main() {
  testIntInserting20RandNumb();
  testIntAscendingSort();
  testIntDeletingEachSecondElement();
  testIntInserting10RandNumbAtRandPos();
  testIntClearContainer();

  testStringInserting15RandWordsConsistLatinLowCase();
  testStringAscendingSort();
  testStringDeletingEachWordConsistOfabcde();
  testStringInserting3RandWordAtRandPos();
}