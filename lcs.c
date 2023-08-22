#include "lcs.h"



/* Description:
 * - This function takes a reference to an array,
 * - array size, and
 * - reference to store the size of the LCS
 * - Using the insertion sort algorithm
 * - The function will search for the LCS in the array and
 * - stores its size
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns -3 if there is no LCS,
 * (i.e all array elements are not consecutive at all)
 * - returns 0 otherwise
 */
int8_t lcsGetSize(int32_t* array, uint8_t arraySize, uint8_t* sizeofLCS) {

	int8_t retVal = noError;
	uint8_t lcs_temp = 1;

	retVal = insertionSort(array, arraySize);

	if (retVal != arrayEmpty && retVal != errorSize) {

		for (int i = 1; i < arraySize; i++) {

			if (array[i] == array[i-1]+1) {
				lcs_temp++;
				if (*sizeofLCS < lcs_temp) {
					*sizeofLCS = lcs_temp;
				}
			}
			else {
				lcs_temp = 1;
			}

		}

		if (*sizeofLCS == (uint8_t)0) {
			retVal = noLCS;
		}
		else {
			retVal = noError;
		}
	}

	return retVal;
}