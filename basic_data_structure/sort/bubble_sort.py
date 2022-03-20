#!/usr/bin/env python3
# coding=utf-8
from typing import List

class Solution:
    def __init__(self) -> None:
        self.context={"data1":"abc","data2":"def"}
    @staticmethod
    def bubbleSort(nums: List[int]) -> None:
        nums_len=len(nums)
        for i in range(nums_len):
            for j in range(i+1,nums_len):
                if nums[i] < nums[j]:
                    nums[i],nums[j] = nums[j],nums[i]
            
if __name__ == "__main__":
    print("main start")
    input_nums=[1,2,3,4,30,17,44]
    Solution.bubbleSort(nums=input_nums)
    print(input_nums)