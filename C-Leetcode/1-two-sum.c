/* 两数之和
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值 target 的那 两个整数，并返回它们的数组下标。你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 */

#include <stdlib.h>
#include <stdio.h>

void twoSum(int* nums, int size, int target, int* returnIndex) {
  int find = 0;
  for (int i=0; i<size-1; i++) {
    if (nums[i] >= target)
      continue;
    else {
      for (int j=i+1; j<size; j++) {
        if (nums[j] == target - nums[i]) {
          returnIndex[0] = i;
          returnIndex[1] = j;
          find = 1;
          break;
        }
      }
    }
    if (find) break;
  }
}

int main() {
  int size = 6;
  int nums[6] = {6,2,7,5,15,4};
  int target = 9;
  int returnIndex[2];
  twoSum(nums, size, target, returnIndex);
  printf("nums[%d]: %d\n", returnIndex[0], nums[*returnIndex]);
  printf("nums[%d]: %d\n", returnIndex[1], nums[*(returnIndex+1)]);
}
