class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        for (int r = 0; r < 4; r++) {

            // Step 1: Transpose
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    swap(mat[i][j], mat[j][i]);
                }
            }

            // Step 2: Reverse every row
            for (int i = 0; i < n; i++) {
                reverse(mat[i].begin(), mat[i].end());
            }

            // Step 3: Compare with target
            bool same = true;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] != target[i][j]) {
                        same = false;
                        break;
                    }
                }

                if (!same)
                    break;
            }

            if (same)
                return true;
        }

        return false;
    }
};