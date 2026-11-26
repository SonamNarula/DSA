class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], labels: str, k: int) -> int:

        graph = [[] for _ in range(n)]

        for s , d , w in edges:
            graph[s].append((d , w))

        distance = defaultdict(lambda:defaultdict(lambda:defaultdict(lambda:float('inf'))))

        start = labels[0]
        distance[0][start][1] = 0
        heap = [(0,0,start,1)]

        while heap:

            cost , node , last_char , run_len = heapq.heappop(heap)

            if node == n - 1:
                return cost

            if cost > distance[node][last_char][run_len]:
                continue

            for next_node , weight in graph[node]:

                next_char = labels[next_node]
                new_run = 0
                if next_char == last_char:
                    new_run = run_len + 1

                    if new_run > k:
                        continue
                else:
                    new_run = 1
                            
                new_cost = cost + weight

                if new_cost < distance[next_node][next_char][new_run]:
                    distance[next_node][next_char][new_run] = new_cost

                    heapq.heappush(heap,(new_cost , next_node , next_char , new_run))
                        
        return -1