#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int N, T;
    cin >> N >> T;

    map<int, string> alunos;

    // Armazenamento com ordem
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;

        int power;
        cin >> power;
        
        alunos[power] = name;
    }

    // Depois de armazenar os jogadores com ordem, eu vou querer criar uma série
    // de vetores que vão corresponder a cada time
    vector<vector<string>> times(T);

    // Escolha de times
    auto it = --alunos.end();
    for (int i = 0; i < N; i++) {
        times[i % T].push_back(it->second); --it;
    }

    // Print
    for (int i = 0; i < T; i++) {
        sort(times[i].begin(), times[i].end());
        std::cout << "Time " << 1+i << std::endl;
        for (int j = 0; j < times[i].size(); j++) {
            std::cout << times[i][j] << std::endl;
        }
        std::cout << '\n';
    }
}