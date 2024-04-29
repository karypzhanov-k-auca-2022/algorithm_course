#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    // Считываем количество тестовых случаев
    int times;
    cin >> times;

    // Для каждого тестового случая
    while (times--) {
        // Считываем размеры лабиринта
        int row, col;
        cin >> row >> col;

        // Создаем матрицу для хранения лабиринта и матрицу для хранения минимальных стоимостей
        vector<vector<int>> matrix(row, vector<int>(col));
        vector<vector<int>> dp(row, vector<int>(col));

        // Заполняем матрицу лабиринта
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> matrix[i][j];
            }
        }

        // Инициализируем первую ячейку матрицы стоимостей
        dp[0][0] = matrix[0][0];

        // Заполняем первый столбец матрицы стоимостей
        for (int i = 1; i < row; i++) {
            dp[i][0] = dp[i - 1][0] + matrix[i][0];
        }

        // Заполняем первую строку матрицы стоимостей
        for (int j = 1; j < col; j++) {
            dp[0][j] = dp[0][j - 1] + matrix[0][j];
        }

        // Заполняем остальные ячейки матрицы стоимостей
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                // Минимальная стоимость для ячейки (i, j) - это минимум из стоимостей ячеек (i-1, j) и (i, j-1) плюс стоимость ячейки (i, j)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
            }
        }

        // Выводим минимальную стоимость для последней ячейки
        cout << dp[row - 1][col - 1] << endl;
    }

    return 0;
}
