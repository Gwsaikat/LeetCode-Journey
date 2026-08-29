# Count Servers That Communicate — Brute Force → Optimized (Row & Column Counting)

# Intuition

Think of every `1` as a server.

A server can communicate with another server if there is **at least one other server in the same row OR the same column**.

For example:

    1  0  1
    0  1  0
    0  0  1

The server at `(0,0)` can communicate with `(0,2)` because they are in the same row.

The server at `(0,2)` can communicate with `(0,0)` because they are in the same row.

But the server at `(1,1)` cannot communicate with anyone because there is no other `1` in its row or column.

So the key question for every server is simply:

> "Does my row contain another server OR does my column contain another server?"

There are two ways to answer this.

# Approach 1 — Brute Force

For every server `(row, col)`:

1. Check its entire row.
2. Check its entire column.
3. If we find another server in either direction, this server can communicate.
4. Add it to our answer.

For example:

    1  0  1
    0  1  0
    1  0  0

For the server at `(0,0)`:

    Row → 1  0  1
           ↑     ↑
           |     |
        another server

So it can communicate.

For the server at `(1,1)`:

    Row → 0  1  0
    Col ↓
          0
          1
          0

There is no other server in its row or column, so it cannot communicate.

The brute-force idea is straightforward, but we repeatedly scan the same rows and columns.

# Complexity — Brute Force

Let:

    rows = m
    cols = n

For each of the `m * n` cells, we may scan:

    n cells in the row
    +
    m cells in the column

Therefore:

    Time Complexity: O(m * n * (m + n))

    Space Complexity: O(1)

# Code — Brute Force

```cpp
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int result = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {

                // Only servers need to be checked
                if (grid[row][col] == 0)
                    continue;

                bool canCommunicate = false;

                // Check the entire row
                for (int c = 0; c < cols; ++c) {
                    if (c != col && grid[row][c] == 1) {
                        canCommunicate = true;
                        break;
                    }
                }

                // If not found in the row, check the column
                if (!canCommunicate) {
                    for (int r = 0; r < rows; ++r) {
                        if (r != row && grid[r][col] == 1) {
                            canCommunicate = true;
                            break;
                        }
                    }
                }

                if (canCommunicate)
                    ++result;
            }
        }

        return result;
    }
};
```
# Approach 2 - Optimized

The brute-force solution checks the entire row and column for every server.

We can optimize this by **counting the number of servers in each row and column beforehand**.

We use two arrays:

    rowCount[row] = number of servers in that row
    colCount[col] = number of servers in that column

First, traverse the entire grid and update both counts whenever we find a server.

Then, traverse the grid again.

For every server at `(row, col)`:

    rowCount[row] > 1

means there is another server in the same row.

OR

    colCount[col] > 1

means there is another server in the same column.

So the server can communicate if:

    rowCount[row] > 1 || colCount[col] > 1

This turns the repeated row/column scanning of the brute-force solution into an `O(1)` check for every server.

# Complexity

- Time complexity: $$O(m \times n)$$

- Space complexity: $$O(m + n)$$

# Code

```cpp
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int result = 0;
        int rowSize = grid.size();
        int colSize = grid[0].size();

        vector<int> rowCount(rowSize, 0);
        vector<int> colCount(colSize, 0);

        // Count servers in every row and column
        for (int row = 0; row < rowSize; ++row) {
            for (int col = 0; col < colSize; ++col) {
                if (grid[row][col] == 1) {
                    ++rowCount[row];
                    ++colCount[col];
                }
            }
        }

        // Count servers that can communicate
        for (int row = 0; row < rowSize; ++row) {
            for (int col = 0; col < colSize; ++col) {
                if (grid[row][col] == 1 &&
                    (rowCount[row] > 1 || colCount[col] > 1)) {
                    ++result;
                }
            }
        }

        return result;
    }
};