class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
            
        rows, cols = len(matrix), len(matrix[0])
        left, right, top, bottom = 0, cols - 1, 0, rows - 1
        res = []

        while left <= right and top <= bottom:
            # 1. Move Right
            for i in range(left, right + 1):
                res.append(matrix[top][i])
            top += 1
            
            # 2. Move Down
            for i in range(top, bottom + 1):
                res.append(matrix[i][right])
            right -= 1
            
            # 3. Move Left (Check if row still exists)
            if top <= bottom:
                for i in range(right, left - 1, -1):
                    res.append(matrix[bottom][i])
                bottom -= 1
            
            # 4. Move Up (Check if column still exists)
            if left <= right:
                for i in range(bottom, top - 1, -1):
                    res.append(matrix[i][left])
                left += 1

        return res
