#ifndef OTIMIZADOR_DIJKSTRA_HPP
#define OTIMIZADOR_DIJKSTRA_HPP

#include "GrafoLogistico.hpp"
#include <string>
#include <vector>
#include <unordered_map>

struct ResultadoRota {
    double custoTotal;
    std::vector<std::string> caminho;
    bool rotaEncontrada;
};

class OtimizadorDijkstra {
public:
    static ResultadoRota calcularRotaMaisCurta(const GrafoLogistico& grafo, 
                                                const std::string& origem, 
                                                const std::string& destino);
};

#endif // OTIMIZADOR_DIJKSTRA_HPP