# Route Optimization System (Dijkstra Graph Algorithm in C++)

Sistema em C++17 de otimização de rotas logísticas e redução de custos de transporte utilizando Grafos com Lista de Adjacência e o Algoritmo de Dijkstra com Fila de Prioridade (`std::priority_queue`).

## 🚀 Como Compilar e Executar

Usando o `g++` via terminal do VS Code:

```bash
g++ -std=c++17 src/GrafoLogistico.cpp src/OtimizadorDijkstra.cpp src/main.cpp -Iinclude -o otimizador_rotas
./otimizador_rotas