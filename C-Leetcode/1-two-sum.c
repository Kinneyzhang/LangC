/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>

void twoSum(int* nums, int numsSize, int target, int* returnSize){
  for(int i=0; i<numsSize; i++) {
    if(nums[i] > target) continue;
    else if(nums[i] = target) {
      *returnSize = nums[i];
    }
    else {
      int a = nums[i];
      int b = target-a;
      twoSum(&nums[i+1], numsSize-i-1, b, returnSize);
    }
  }
}

int main() {
  int nums[4] = {2,7,11,15};
  int numsSize = 4;
  int target = 9;
  int *returnSize = (int*)malloc(sizeof(int));
  twoSum(nums, numsSize, target, returnSize);
  printf("%d\n", *returnSize);
  printf("%d\n", *(returnSize+1));
}
