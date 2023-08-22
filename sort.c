#include "sort.h"

/* Description:
 * - This function takes a reference to an array of integers
 * - Sorts the array in ascending order
 * - Using the insertion sort algorithm
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns 0 if sorting is done without errors
 */
int8_t insertionSort(int32_t* array, uint8_t arraySize) {

	int8_t retVal = noError;
	int32_t temp ;
	int32_t j;

	if (array[0] == ' ' && arraySize == 0) {
		retVal = arrayEmpty;
	}
	else if (arraySize == 0 || arraySize > 10) {
		retVal = errorSize;
	}
	else {
		for (int i = 1; i < arraySize; i++) {
			temp = array[i];
			j = i - 1;
			while (j >= 0 && temp < array[j]) {
				array[j + 1] = array[j];
				j--;
			}
			array[j + 1] = temp;
		}
		retVal = noError;
	}
	return retVal;
}




/* Description:
 * - This function takes a reference to an array of integers
 * - Prints all array elements
 * Return:
 * - Nothing to return
 */
void printArray(int32_t* array, uint8_t arraySize) {

	for (int i = 0; i < arraySize; i++) {
		printf("%d\t", array[i]);
	}
	printf("\n\n");
}