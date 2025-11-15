class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        prefix_ones = [0] * n
        prefix_zeros = [0] * n
        prefix_ones[0] = 1 if s[0] == "1" else 0
        prefix_zeros[0] = 1 if s[0] == "0" else 0

        for i in range(1, n):
            prefix_zeros[i] = prefix_zeros[i - 1] + (1 if s[i] == "0" else 0)
            prefix_ones[i] = prefix_ones[i - 1] + (1 if s[i] == "1" else 0)

        total = 0
        for i in range(n):
            j = 0
            while j < n:
                n_ones = prefix_ones[j] - (prefix_ones[i - 1] if i - 1 >= 0 else 0)
                n_zeros = prefix_zeros[j] - (prefix_zeros[i - 1] if i - 1 >= 0 else 0)

                if n_ones >= n_zeros ** 2:
                    total += 1

                j += (n_zeros ** 2 - n_ones)

        return total


print( Solution().numberOfSubstrings( "00011" ) )
