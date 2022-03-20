'''
给定一个实数，设计一个最有效的算法，找到一个综合最大的区间

'''


def getMaxSumSection(arr: list) -> tuple:
    if not arr:
        return None
    sum_max = val_max = l = r = 0
    total_len = len(arr)
    val_max = (arr[l], 0, 0)
    sum_max += arr[l]
    while True:
        #print(f"{l= },{r=},{sum_max=} {total_len=} {val_max=}")
        if sum_max <= 0:
            l = r+1
            r = l
            if r >= total_len:
                break
            sum_max = arr[r]
        else:
            r += 1
            if r >= total_len:
                break
            sum_max += arr[r]
        if val_max[0] < sum_max:
            val_max = (sum_max, l, r)
            
    return val_max[1:]


if __name__ == "__main__":
    test_list1 = [1.5, -12.3, 3.2, -5.5, 23.2,
                  3.2, -1.4, -12.2, 34.2, 5.4, -7.8, 1.1, -4.9]
    test_list2=[1.5, -12.3, 3.2, -5.5, 23.2,
                  3.2, -1.4,-62.2,44.2,5.4,-7.8,1.1,-4.9]
    print(getMaxSumSection(test_list1))
    print(getMaxSumSection(test_list2))