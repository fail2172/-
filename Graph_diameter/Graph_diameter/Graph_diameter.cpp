#include <iostream>
#include <fstream>
#include <vector>;
using namespace std;


int Array[100][100];
int timer[100], visit[100];
int Columns, Lines, ROOT;


int End_of_edge(int j) {
    for (int i = 0; i < Lines; i++) {
        if (Array[i][j] == 1)
            return i;
    }
    cout << "Не удалось получить данные из файла...";
    exit(0);
}

void DFS(int number_of_vertex, int time = 0) {
    vector<int> queue;
    visit[number_of_vertex] = true;
    if (timer[number_of_vertex] > time)timer[number_of_vertex] = time;
    for (int i = 0, end_of_edge; i < Columns; i++) {
        if (Array[number_of_vertex][i] == -1) {
            end_of_edge = End_of_edge(i);
            if (!visit[end_of_edge])
                queue.push_back(end_of_edge);
        }
    }
    if (!queue.size())return;
    while (queue.size()) {
        int next_vertex = queue[0];
        queue.erase(queue.begin());
        DFS(next_vertex, time + 1);
        visit[next_vertex] = false;
    }
    if (number_of_vertex == ROOT)return;
}

int main()
{
    setlocale(LC_ALL, "ru");
    ifstream file("1");
    int TEST = 1;
    while (!file.eof()) {
        file >> Lines >> Columns;
        for (int i = 0; i < Lines; i++)
            for (int j = 0; j < Columns; j++)
                file >> Array[i][j];
        int eccentricity[100];
        fill(eccentricity, eccentricity + Lines, 0);
        fill(visit, visit + Lines, 0);
        for (int vertex = 0; vertex < Lines; vertex++) {
            fill(timer, timer + Lines, 100);
            ROOT = vertex;
            DFS(vertex);
            for (int i = 0; i < Lines; i++) {
                if (timer[i] == 100)timer[i] = 0;
            }
            for (int j = 0; j < Lines; j++) {
                if (eccentricity[ROOT] < timer[j])
                    eccentricity[ROOT] = timer[j];
            }
        }
        cout << "TEST " << TEST++ << " :\n\n";
        int diametr = 0;

        for (int i = 0; i < Lines; i++) {
            if (diametr < eccentricity[i])diametr = eccentricity[i];
        }

        for (int i = 0; i < Lines; i++) {
            cout << "Эксцентреситет вершины " << i + 1 << " : " << eccentricity[i] << endl;
        }cout << endl;

        cout << "Диаметр графа : " << diametr << endl << endl;

        cout << "Номера переферийных вершин : ";
        for (int i = 0; i < Lines; i++) {
            if (eccentricity[i] == diametr)cout << i + 1 << " ";
        }cout << endl << endl;
        for (int i = 0; i < Lines; i++)
            fill(Array[i], Array[i] + Columns, 0);
    }
    return 0;
}