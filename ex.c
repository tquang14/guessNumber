#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 4
#define NUMBER_OF_DIGITS_FROM_MIN_TO_MAX 10 // 0 -> 9
/*
*   \brief compare 2 array, print hit and blow if 2 array is not the same
*   \return 1 if 2 array is the same, 0 if not
*   \param 2 array to compare
*/
int isMatch(char *targets, char *nums);

/*
*   \brief check if "num"(4 element) is valid or not
*   \return true if each digit character is different from other digits else false
*   \param array in char type
*/
int isValidNumber(char *nums);

/*
*   \brief add to array with 4 random digits
*   \param array in char type
*/
void createRandomNumber(char num[]);

int main()
{
    // ger user input
    char userInput[4] = {0};
    int tmpUserInput;

    return 0;
}

int isMatch(char *targets, char *nums)
{
    // check whether 2 arr is macth or not
    int isMatch = 1;
    uint8_t i = 0;
    while (isMatch != 0 && i < ARR_SIZE)
    {
        if (targets[i] != nums[i])
            isMatch = 0;
        i++;
    }
    if (isMatch == 1)
        return isMatch;
    //calculate hit and blow if 2 arr is not match
    uint8_t hit = 0;
    uint8_t blow = 0;
    uint8_t j = 0;
    for (i = 0; i < ARR_SIZE; i++)
    {
        for (j = 0; j < ARR_SIZE; j++)
        {
            if (targets[i] == nums[j] && i == j)
                hit++;
            else if (targets[i] == nums[j] && i != j)
                blow++;
        }
    }
    printf("%d hit, %d blow", hit, blow);
    return isMatch;
}

int isValidNumber(char *nums)
{
    //our array only contain element from 0 -> 9 so this way take not to much memory and the fastest way to find duplicate
    //otherwise use some sorting algorithms to find duplicate
    int tmpArr[NUMBER_OF_DIGITS_FROM_MIN_TO_MAX] = {0};
    for (uint8_t i = 0; i < ARR_SIZE; i++)
    {
        // convert char to int than apply it to index
        if (tmpArr[nums[i] - '0'] != 0)
            return 0;
        tmpArr[nums[i] - '0'] += 1;
    }
    return 1;
}

void createRandomNumber(char nums[])
{
    // hard code to generate array with 10 elements from 0 -> 9
    char tmpArr[NUMBER_OF_DIGITS_FROM_MIN_TO_MAX] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    // shuffle tmpArr to get random array
    srand(time(NULL));
    for (uint8_t i = NUMBER_OF_DIGITS_FROM_MIN_TO_MAX - 1; i > 0; i--)
    {
        uint8_t j = rand() % (i + 1);
        char tmp = tmpArr[j];
        tmpArr[j] = tmpArr[i];
        tmpArr[i] = tmp;
    }
    // assign random array to nums
    for (uint8_t i = 0; i < ARR_SIZE; i++)
    {
        nums[i] = tmpArr[i];
    }
}