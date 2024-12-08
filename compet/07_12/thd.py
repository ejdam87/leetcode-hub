import heapq
from math import sqrt
class Solution:

    def is_prime(self, k):
        if k == 1 or k == 0:
            return False

        for t in range( 2, int(sqrt(k)) + 1 ):
            if k % t == 0:
                return False

        return True

    def minOperations(self, n: int, m: int) -> int:
        
        if self.is_prime(n):
            return -1

        pq = []
        heapq.heappush( pq, ( n, n ) )
        visited = set()
        costs = {n : n}

        preds = {n : None}

        while pq != []:
            cost, k = heapq.heappop( pq )
            if k == m:
                return cost

            if k in visited:
                continue

            visited.add(k)

            sk = []
            nk = k
            while nk > 0:
                sk.append( nk % 10 )
                nk //= 10
            
            sk.reverse()

            for i, digit in enumerate(sk):

                adjs = []
                if digit != 9:
                    sk[i] += 1
                    adjs.append( int( "".join( [str(x) for x in sk] ) ) )
                    sk[i] -= 1

                if digit != 0 and (i != 0 or digit != 1):
                    sk[i] -= 1
                    adjs.append( int( "".join( [str(x) for x in sk] ) ) )
                    sk[i] += 1
    
                for adj in adjs:
                    if not self.is_prime(adj):
                        if adj not in visited or costs[adj] > (costs[k] + adj):
                            costs[adj] = costs[k] + adj
                            heapq.heappush( pq, ( cost + adj, adj ) )
                            preds[adj] = k

        return -1


print( Solution().minOperations( 17, 72 ) )
