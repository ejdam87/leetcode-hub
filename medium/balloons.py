
class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """

        spoints = sorted(points, key=lambda x: x[0])
        sr = max(points, key=lambda x: x[1])[1]
        arrows = 0
        i = 0

        while i < len(points):
            left = spoints[i]
            redge = left[1]

            j = i
            leftmost = [0, sr]
            while j < len(points) and spoints[j][0] <= redge:

                if spoints[j][1] < leftmost[1]:
                    leftmost = spoints[j]

                j += 1

            arrows += 1

            while i < len(points) and spoints[i][0] <= leftmost[1]:
                i += 1

        return arrows

print( Solution().findMinArrowShots( [[3,9],[7,12],[3,8],[6,8],[9,10],[2,9],[0,9],[3,9],[0,6],[2,8]] ) )
