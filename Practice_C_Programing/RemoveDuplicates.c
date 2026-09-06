#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int*, int);

int main(int argc, char const *argv[])
{
    int nums[10] = {0,0,1,1,1,2,2,3,3,4};

    int newLength = removeDuplicates(nums, sizeof(nums) / sizeof(nums[0]));

    printf("New length: %d\n", newLength);

    for(int i = 0; i < newLength; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}

int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0){
        return 0;
    }

    for(int i = 0; i < numsSize - 1; i++){
        if(nums[i] == nums[i+1]){
            for(int j = i + 1; j <numsSize - 1; j++){
                nums[j] = nums[j+1];
            }
            numsSize--;
            i--;
        }
    }
    return numsSize;
}
