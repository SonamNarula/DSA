class Solution:
    def minOperations(self, nums: List[int], x: int, k: int) -> int:
        n = len(nums)
        lower = SortedList()
        upper = SortedList()
        lower_sum = 0
        upper_sum = 0
        min_ops = []

        for i in range(n):
            if not lower or nums[i] <= lower[-1]:
                lower.add(nums[i])
                lower_sum += nums[i]
            else:
                upper.add(nums[i])
                upper_sum += nums[i]

            if i >= x:
                out_num = nums[i - x]
                if out_num in lower:
                    lower.remove(out_num)
                    lower_sum -= out_num
                else:
                    upper.remove(out_num)
                    upper_sum -= out_num

            if len(lower) < len(upper):
                val = upper[0]
                upper.remove(val)
                lower.add(val)
                upper_sum -= val
                lower_sum += val
            elif len(lower) - len(upper) > 1:
                val = lower[-1]
                lower.remove(val)
                upper.add(val)
                lower_sum -= val
                upper_sum += val

            if i >= x - 1:
                median = lower[-1]
                ops = (median * len(lower) - lower_sum) + (upper_sum - median * len(upper))
                min_ops.append(ops)

        m = len(min_ops)
        prev = [float('inf')] * (m + 1)
        for i in range(m + 1):
            prev[i] = 0

        for j in range(1, k + 1):
            curr = [float('inf')] * (m + 1)
            min_val = float('inf')
            for i in range(1, m + 1):
                min_val = min(min_val, prev[max(0, i - x)] + min_ops[i - 1])
                curr[i] = min_val
            prev = curr

        return prev[m]