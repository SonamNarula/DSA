
from sortedcontainers import SortedList
import heapq

class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:

        # Initially, all servers are available
        available = SortedList(range(k))

        # Min heap: (finish_time, server_id)
        busy = []

        # Count requests handled by each server
        count = [0] * k

        for i in range(len(arrival)):

            # Step 1: Free servers whose requests are completed
            while busy and busy[0][0] <= arrival[i]:
                finish_time, server = heapq.heappop(busy)
                available.add(server)

            # Step 2: Find preferred server
            preferred = i % k

            # Step 3: Find the next available server
            idx = available.bisect_left(preferred)

            # Circular search: wrap around if necessary
            if idx == len(available):
                idx = 0

            # If no server is available, drop the request
            if not available:
                continue

            # Step 4: Assign request
            server = available.pop(idx)

            # Update request count
            count[server] += 1

            # Calculate finishing time and add to heap
            finish_time = arrival[i] + load[i]
            heapq.heappush(busy, (finish_time, server))

        # Step 5: Find servers with maximum requests
        maximum = max(count)

        return [
            i for i in range(k)
            if count[i] == maximum
        ]