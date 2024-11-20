#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Функция Алгоритма Дейкстры
void Dijkstra(int n, int st, const vector<vector<int>>& w)
{
    vector<bool> visited(n, false); 
    vector<int> D(n, INT_MAX);      

    D[st] = 0;

    for (int i = 0; i < n; i++)
    {
        int min = INT_MAX, index = -1;

        // Поиск непосещённой вершины с минимальным расстоянием
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && D[j] < min)
            {
                min = D[j];
                index = j;
            }
        }

        if (index == -1) break; // Все вершины обработаны или нет доступных вершин
        int u = index;
        visited[u] = true;

        // Обновление расстояний до соседних вершин
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && w[u][j] != INT_MAX && D[u] != INT_MAX && (D[u] + w[u][j] < D[j]))
            {
                D[j] = D[u] + w[u][j];
            }
        }
    }

    // Вывод результата
    cout << "Стоимость пути из начальной вершины до остальных (Алгоритм Дейкстры):\n";
    for (int i = 0; i < n; i++)
    {
        if (D[i] != INT_MAX)
            cout << st << " -> " << i << " = " << D[i] << endl;
        else
            cout << st << " -> " << i << " = маршрут недоступен" << endl;
    }
}

// Функция для проверки алгоритма
void TestDijkstra()
{
    int n = 5; // Количество вершин
    vector<vector<int>> graph = {
        {0, 10, 3, INT_MAX, INT_MAX},
        {10, 0, 1, 2, INT_MAX},
        {3, 1, 0, 8, 2},
        {INT_MAX, 2, 8, 0, 7},
        {INT_MAX, INT_MAX, 2, 7, 0} };

    cout << "Тестовый запуск алгоритма Дейкстры:" << endl;
    Dijkstra(n, 0, graph);
}

int main()
{
    TestDijkstra();
    return 0;
}