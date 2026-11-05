class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        arr2.sort()

        l, count = len(arr1), 0

        for i in range(l):
            left, right = bisect_left(arr2, arr1[i] - d), bisect_right(arr2, arr1[i] + d)

            if left == right:
                count += 1
        
        return count
            