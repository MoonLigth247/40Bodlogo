#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility> 

class SnakesAndLadders {
public:
    static int quickestWayUp(std::map<int, int>& ladders, std::map<int, int>& snakes) {
        std::vector<bool> visited(101, false); 
        std::queue<std::pair<int, int>> queue;

        queue.push({1, 0});
        visited[1] = true;

        while (!queue.empty()) {
            std::pair<int, int> current = queue.front();
            queue.pop();

            int position = current.first;
            int moves = current.second;

            if (position == 100) {
                return moves;
            }

            for (int dice = 1; dice <= 6; ++dice) {
                int next = position + dice;
                if (next > 100) {
                    continue;
                }

                if (ladders.count(next)) {
                    next = ladders[next];
                } 
                else if (snakes.count(next)) {
                    next = snakes[next];
                }

                if (!visited[next]) {
                    visited[next] = true;
                    queue.push({next, moves + 1});
                }
            }
        }

        return -1; 
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; 
    std::cin >> t;

    while (t-- > 0) {
        int n; 
        std::cin >> n;
        std::map<int, int> ladders;
        for (int i = 0; i < n; ++i) {
            int start, end;
            std::cin >> start >> end;
            ladders[start] = end;
        }

        int m; 
        std::cin >> m;
        std::map<int, int> snakes;
        for (int i = 0; i < m; ++i) {
            int start, end;
            std::cin >> start >> end;
            snakes[start] = end;
        }

        int result = SnakesAndLadders::quickestWayUp(ladders, snakes);
        std::cout << result << std::endl;
    }

    return 0;
}