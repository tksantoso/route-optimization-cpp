#ifndef GRAFO_LOGISTICO_HPP
#define GRAFO_LOGISTICO_HPP

#include "Aresta.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

class GrafoLogistico {
private:
    // Mapeia: Vertice Origem -> Lista de Arestas Saindo da Origem
    std::unordered_map<std::string, std::vector<Aresta>> listaAdjacencia;

public:
    GrafoLogistico() = default;

    void adicionarLocalidade(const std::string& nome);
    void adicionarRota(const std::string& origem, const std::string& destino, double peso, bool bidirecional = true);

    const std::unordered_map<std::string, std::vector<Aresta>>& getListaAdjacencia() const;
    bool existeLocalidade(const std::string& nome) const;
    void exibirGrafo() const;
};

#endif // GRAFO_LOGISTICO_HPP