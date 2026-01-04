class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:

        visited = set()
        for i, row in enumerate(grid):
            for j, col in enumerate(row):
                if (i,j) not in visited:
                    if (self.bfs( (i,j), grid, visited)):
                        return True

        return False

    def bfs(self, node:Set[str], grid: List[List[str]], visited: Set[str]) -> bool:


        row_size = len(grid)
        col_size = len(grid[0])

        neighbours = [(-1,0), (0,-1), (0,1), (1,0)]

        queue = collections.deque()

        # (row, cloumn), parent
        queue.append(( node, -1))
        visited.add(node)

        while queue:

            cur, parent = queue.popleft()

            for neigh in neighbours:
                r = cur[0] + neigh[0]
                c = cur[1] + neigh[1]

                # bound check
                if r < 0 or r > row_size - 1 or c < 0 or c > col_size - 1:
                    continue
                # check only for similar value neighbours
                if grid[r][c] != grid[cur[0]][cur[1]]:
                    continue

                if (r,c) not in visited:
                    visited.add((r,c))
                    queue.append( ( (r,c), cur) )

                elif parent != (r,c):
                    return True

        return False


