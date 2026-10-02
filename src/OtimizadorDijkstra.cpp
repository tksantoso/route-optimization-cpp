#include "../include/OtimizadorDijkstra.hpp"
#include <queue>
#include <limits>
#include <algorithm>
#include <iostream>

// Par para Fila de Prioridade: <Distância Acumulada, Nome do Vértice>
typedef std::pair<double, std::string> ParDistanciaVertice;

ResultadoRota OtimizadorDijkstra::calcularRotaMaisCurta(const GrafoLogistico& grafo, 
                                                         const std::string& origem, 
                                                         const std::string& destino) {
    ResultadoRota resultado;
    resultado.custoTotal = 0.0;
    resultado.rotaEncontrada = false;

    if (!grafo.existeLocalidade(origem) || !grafo.existeLocalidade(destino)) {
        return resultado;
    }

    const auto& adj = grafo.getListaAdjacencia();

    // Tabela de distâncias mínimas inicializada com Infinito
    std::unordered_map<std::string, double> distancias;
    // Tabela de predecessores para reconstrução do caminho
    std::unordered_map<std::string, std::string> predecessores;

    for (const auto& [vertice, _] : adj) {
        distancias[vertice] = std::numeric_limits<double>::infinity();
    }

    // Min-Heap (Fila de Prioridade ordenada do menor para o maior custo)
    std::priority_queue<ParDistanciaVertice, 
                        std::vector<ParDistanciaVertice>, 
                        std::greater<ParDistanciaVertice>> pq;

    distancias[origem] = 0.0;
    pq.push({0.0, origem});

    while (!pq.empty()) {
        auto [distAtual, verticeAtual] = pq.top();
        pq.pop();

        if (verticeAtual == destino) {
            resultado.rotaEncontrada = true;
            break;
        }

        if (distAtual > distancias[verticeAtual]) {
            continue;
        }

        auto it = adj.find(verticeAtual);
        if (it != adj.end()) {
            for (const auto& aresta : it->second) {
                double novaDist = distAtual + aresta.peso;

                if (novaDist < distancias[aresta.destino]) {
                    distancias[aresta.destino] = novaDist;
                    predecessores[aresta.destino] = verticeAtual;
                    pq.push({novaDist, aresta.destino});
                }
            }
        }
    }

    // Reconstrução da Rota Otimizada
    if (resultado.rotaEncontrada) {
        resultado.custoTotal = distancias[destino];
        std::string passo = destino;

        while (passo != origem) {
            resultado.caminho.push_back(passo);
            passo = predecessores[passo];
        }
        resultado.caminho.push_back(origem);
        
        // Inverte para ter a rota da origem -> destino
        std::reverse(resultado.caminho.begin(), resultado.caminho.end());
    }

    return resultado;
}