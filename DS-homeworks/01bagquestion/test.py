#!/usr/bin/env python
# -*- coding:utf-8 -*-
# @Time  : 27/11/2020 下午 7:36
# @Author: xiaoni
# @File  : test.py

class Solution(object):


    def uniquePaths(self,m,n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        self.relation_matrix = [[1 for i in range(m)] for j in range(n)]  # 创建临接矩阵
        for i in range(m):
            self.relation_matrix[0][i] = 1

        for j in range(n):
            self.relation_matrix[j][0] = 1

        for i in range(1, m):
            for j in range(1, n):
                self.relation_matrix[j][i] = self.relation_matrix[j - 1][i] + self.relation_matrix[j][i - 1]

        saaa=self.relation_matrix[:]
        return self.relation_matrix[n - 1][m - 1]
class Solution1:
    def uniquePaths(self, m: int, n: int) -> int:
        pre = [1] * n
        cur = [1] * n
        for i in range(1, m):
            for j in range(1, n):
                cur[j] = pre[j] + cur[j-1]
            pre = cur[:]
        return pre[-1]


class Solution2(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        grid_mutrexs = grid[:]
        for i in range(1, len(grid[0])):
            grid_mutrexs[0][i] = grid[0][i] + grid[0][i - 1]

        for i in range(1, len(grid)):
            grid_mutrexs[i][0] = grid[i][0] + grid[i - 1][0]

        for j in range(1, len(grid[0])):
            for i in range(1, len(grid)):
                if grid_mutrexs[i - 1][j] < grid_mutrexs[i][j - 1]:
                    grid_mutrexs[i][j] = grid_mutrexs[i - 1][j]+grid[i][j]
                else:
                    grid_mutrexs[i][j] = grid_mutrexs[i][j - 1]+grid[i][j]

        return grid_mutrexs[len(grid_mutrexs) - 1][len(grid_mutrexs[0]) - 1]


class Solution22:
    def minPathSum(self, grid):
        if not grid or not grid[0]:
            return 0

        dp = [float('inf')] * len(grid[0])
        dp[0] = 0
        # dp[1]是真正的起始点，前面没值，用+1替代-1，避免掉 -1超界的情况
        for row in grid:
            for index, num in enumerate(row):
                if index == 0:
                    dp[index] = dp[index] + num
                else:
                    dp[index] = min(dp[index], dp[index - 1]) + num

        return dp[-1]



if __name__ == '__main__':
    grid = [[2, 3, 4], [3, 4, 5]]
    aaa = Solution22().minPathSum(grid)
    print(aaa)

