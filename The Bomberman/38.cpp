#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
class Result {
public:
    static std::vector<std::string> bomberMan(int n, const std::vector<std::string>& grid) {
        if (n == 1) {
            return grid;
        }

        int rows = grid.size();
        int cols = grid[0].length();

        if (n % 2 == 0) {
            return createFullGrid(rows, cols);
        }
        std::vector<std::string> stateAfterFirstDetonation = detonate(grid);

        std::vector<std::string> stateAfterSecondDetonation = detonate(stateAfterFirstDetonation);

        if (n % 4 == 3) {
            return stateAfterFirstDetonation;
        } else { 
            return stateAfterSecondDetonation;
        }
    }

private:
    static std::vector<std::string> createFullGrid(int rows, int cols) {
        std::string fullRow(cols, 'O');
        std::vector<std::string> fullGrid(rows, fullRow);
        return fullGrid;
    }

    static std::vector<std::string> detonate(const std::vector<std::string>& grid) {
        int rows = grid.size();
        int cols = grid[0].length();

        std::vector<std::vector<char>> current(rows, std::vector<char>(cols));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                current[i][j] = grid[i][j];
            }
        }

        std::vector<std::vector<char>> next(rows, std::vector<char>(cols, 'O'));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (current[i][j] == 'O') {
                    next[i][j] = '.'; 
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                            next[ni][nj] = '.';
                        }
                    }
                }
            }
        }

        std::vector<std::string> result;
        for (int i = 0; i < rows; ++i) {
            result.push_back(std::string(next[i].begin(), next[i].end()));
        }
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int r, c, n_val;
    std::cin >> r >> c >> n_val; 

    std::vector<std::string> grid(r);
    for (int i = 0; i < r; ++i) {
        std::cin >> grid[i]; 
    }

    std::vector<std::string> result = Result::bomberMan(n_val, grid);

    for (const std::string& row : result) {
        std::cout << row << std::endl;
    }

    return 0;
}
