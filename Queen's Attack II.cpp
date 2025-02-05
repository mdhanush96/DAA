#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */
 
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    // Directional distances
    int up = n - r_q;
    int down = r_q - 1;
    int right = n - c_q;
    int left = c_q - 1;
    int up_right = min(up, right);
    int up_left = min(up, left);
    int down_right = min(down, right);
    int down_left = min(down, left);
    
    // Store obstacle positions in a set for quick lookup
    set<pair<int, int>> obstacleSet;
    for (auto &obstacle : obstacles) {
        obstacleSet.insert({obstacle[0], obstacle[1]});
    }
    
    // Adjust distances based on obstacles
    for (auto &obstacle : obstacles) {
        int r_o = obstacle[0], c_o = obstacle[1];
        if (c_o == c_q) { // Same column
            if (r_o > r_q) up = min(up, r_o - r_q - 1);
            else down = min(down, r_q - r_o - 1);
        } else if (r_o == r_q) { // Same row
            if (c_o > c_q) right = min(right, c_o - c_q - 1);
            else left = min(left, c_q - c_o - 1);
        } else if (abs(r_o - r_q) == abs(c_o - c_q)) { // Diagonal
            if (r_o > r_q && c_o > c_q) up_right = min(up_right, r_o - r_q - 1);
            else if (r_o > r_q && c_o < c_q) up_left = min(up_left, r_o - r_q - 1);
            else if (r_o < r_q && c_o > c_q) down_right = min(down_right, r_q - r_o - 1);
            else if (r_o < r_q && c_o < c_q) down_left = min(down_left, r_q - r_o - 1);
        }
    }
    
    return up + down + left + right + up_right + up_left + down_right + down_left;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);
    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));
    int n = stoi(first_multiple_input[0]);
    int k = stoi(first_multiple_input[1]);
    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);
    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));
    int r_q = stoi(second_multiple_input[0]);
    int c_q = stoi(second_multiple_input[1]);
    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        string obstacles_row_temp;
        getline(cin, obstacles_row_temp);
        vector<string> obstacles_row = split(rtrim(obstacles_row_temp));
        obstacles[i] = {stoi(obstacles_row[0]), stoi(obstacles_row[1])};
    }
    int result = queensAttack(n, k, r_q, c_q, obstacles);
    fout << result << "\n";
    fout.close();
    return 0;
}

string ltrim(const string &str) {
    return str.substr(str.find_first_not_of(" "));
}

string rtrim(const string &str) {
    return str.substr(0, str.find_last_not_of(" ") + 1);
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, ' ')) {
        tokens.push_back(token);
    }
    return tokens;
}
