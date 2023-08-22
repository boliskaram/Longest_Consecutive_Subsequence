#pragma once
#include "Types.h"

enum { errorSize = -2, arrayEmpty = -1, noError = 0 };
void printArray(int32_t* array, uint8_t arraySize);

int8_t insertionSort(int32_t* array, uint8_t arraySize);