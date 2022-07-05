/* 两数之和
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值 target 的那 两个整数，并返回它们的数组下标。你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 */

#include <stdlib.h>
#include <stdio.h>

void twoSum(int* nums, int numsSize, int target, int* returnSize){
  
}

int main() {
  int nums[4] = {6,2,7,5,15,4};
  int numsSize = 6;
  int target = 9;
  int *returnSize = (int*)malloc(sizeof(int));
  
  twoSum(nums, numsSize, target, returnSize);
  printf("%d\n", *returnSize);
  printf("%d\n", *(returnSize+1));
}
