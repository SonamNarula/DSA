class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        int litterCount = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        // Find S and assign IDs to L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        int totalMasks = 1 << litterCount;
        int fullMask = totalMasks - 1;

        /*
            best[r][c][mask] =
            maximum energy with which we have reached
            (r, c) after collecting 'mask'
        */

        vector<vector<vector<short>>> best(
            m,
            vector<vector<short>>(
                n,
                vector<short>(totalMasks, -1)
            )
        );

        struct State {
            int r;
            int c;
            int mask;
            int energy;
        };

        queue<State> q;

        best[sr][sc][0] = energy;

        q.push({sr, sc, 0, energy});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [r, c, mask, e] = q.front();
                q.pop();

                // All litter collected
                if (mask == fullMask) {
                    return moves;
                }

                // No energy -> cannot make another move
                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    // Reset energy
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    /*
                        Dominance optimization:

                        If we have already reached the same
                        (nr, nc, nmask) with >= energy,
                        this state can never be better.
                    */

                    if (ne <= best[nr][nc][nmask])
                        continue;

                    best[nr][nc][nmask] = ne;

                    q.push({
                        nr,
                        nc,
                        nmask,
                        ne
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};