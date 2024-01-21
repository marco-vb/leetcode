class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix.front().size();

        vector<vector<int>> score = matrix;
        for (int i = 1; i < r; i++) {
            score[i].assign(c, 1e9);
        }

        using ii = pair<int, int>;

        queue<ii> q;
        for (int i = 0; i < c; i++) q.push({0, i});

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            if (i == r - 1) continue;
            if (j > 0 && score[i+1][j-1] > score[i][j] + matrix[i+1][j-1]) {
                score[i+1][j-1] = score[i][j] + matrix[i+1][j-1];
                q.push({ i+1, j-1 });
            }
            if (score[i+1][j] > score[i][j] + matrix[i+1][j]) {
                score[i+1][j] = score[i][j] + matrix[i+1][j];
                q.push({ i+1, j });
            }
            if (j < c - 1 && score[i+1][j+1] > score[i][j] + matrix[i+1][j+1]) {
                score[i+1][j+1] = score[i][j] + matrix[i+1][j+1];
                q.push({ i+1, j+1 });
            }
        }

        auto last = score.back();
        return *min_element(last.begin(), last.end());
    }
};

