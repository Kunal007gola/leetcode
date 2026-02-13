class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        rows = len(grid)
        cols = len(grid[0])

        visited = set()
        count = 0

        for i in range(rows):
            for j in range(cols):
                node = (i,j)
                if grid[i][j] == "1" and node not in visited:
                    count += 1
                    self.bfs(node, grid, visited)
        
        return count
    
    def bfs(self, node: tuple[str], grid: List[List[str]], visited: Set[tuple[str]]):

        neighbours = [(-1,0), (0,-1), (0,1), (1,0)]
        rows = len(grid)
        cols = len(grid[0])

        que = collections.deque()
        que.append(node)

        visited.add(node)

        while que:
            node = que.popleft()
            # node = que.pop() # change the popleft to pop to make it DFS

            for neigh in neighbours:
                r = node[0] + neigh[0]
                c = node[1] + neigh[1]

                if r in range(rows) and c in range(cols) and grid[r][c] == "1" and (r,c) not in visited:
                    visited.add((r,c))
                    que.append((r,c))

                # if r < 0 or r >= rows or c < 0 or c >= cols:
                #     continue
                
                # neigh_node = (r,c)
                # if grid[r][c] == "1" and neigh_node not in visited:
                #     visited.add(neigh_node)
                #     que.append(neigh_node)
                

