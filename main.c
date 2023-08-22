#include "main.h"

int main() {

    uint8_t anotherSequence = ' ';
    do {
    uint32_t arraySize = 0;
    int32_t checkInput ;
    int8_t checkEmpty;
    int32_t* P_arr;
    int32_t check;
    int8_t lcs_size = 0;
    char inputStr[100];

    printf("Enter array size : ");
    fgets(inputStr, sizeof(inputStr), stdin);
    sscanf_s(inputStr, "%d", &arraySize);


    P_arr = (int32_t*)malloc(arraySize * sizeof(int32_t));

    for (int i = 0; i < arraySize; i++) {

        printf("Enter element %d: ", i + 1);
        fgets(inputStr, sizeof(inputStr), stdin);
        checkEmpty = sscanf_s(inputStr, "%d", &checkInput);

        if (checkEmpty == emptyInput) {
            if (P_arr != NULL) {
                P_arr[0] = ' ';
                arraySize = 0;
            }
            break;
        }
        else {
            if (P_arr != NULL) {
                P_arr[i] = checkInput;
            }
        }
    }

     
    #ifdef sort
        // To check Sorting algorithim
        check = insertionSort(P_arr, arraySize);
        if (check == arrayEmpty) {
            printf("Error, Empty Array\n");
        }
        else if (check == errorSize) {
            printf("Error, Array Size = 0 or >10\n");
        }
        else {
            printArray(P_arr, arraySize);
        }
    #endif // sort

    
    #ifdef lcs
        // to get LCS 
        check = lcsGetSize(P_arr, arraySize, &lcs_size);
        if (check == arrayEmpty) {

            printf("Error, Empty Array\n");
        }
        else if (check == errorSize) {
            printf("Error, Array Size = 0 or >10\n");
        }
        else if (check == noLCS) {
            printArray(P_arr, arraySize);
            printf("Sorry,there isn't LCS\n");
        }
        else {
            printArray(P_arr, arraySize);
            printf("lcsSize = %d\n", lcs_size);
        }

    #endif // lcs

    
    

         printf("If Want To Enter Another Sequence press y/Y If Not Press any Key ");
        fgets(inputStr, sizeof(inputStr), stdin);
        sscanf_s(inputStr, "%c", &anotherSequence , 1);
    } while (anotherSequence == 'y' || anotherSequence == 'Y');
    
}