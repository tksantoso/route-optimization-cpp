#include "../include/GrafoLogistico.hpp"
#include <iomanip>

void GrafoLogistico::adicionarLocalidade(const std::string& nome) {
    if (listaAdjacencia.find(nome) == listaAdjacencia.end()) {
        listaAdjacencia[nome] = std::vector<Aresta>();
    }
}

void GrafoLogistico::adicionarRota(const std::string& origem, const std::string& destino, double peso, bool bidirecional) {
    adicionarLocalidade(origem);
    adicionarLocalidade(destino);

    listaAdjacencia[origem].push_back(Aresta(destino, peso));

    if (bidirecional) {
        listaAdjacencia[destino].push_back(Aresta(origem, peso));
    }
}

const std::unordered_map<std::string, std::vector<Aresta>>& GrafoLogistico::getListaAdjacencia() const {
    return listaAdjacencia;
}

bool GrafoLogistico::existeLocalidade(const std::string& nome) const {
    return listaAdjacencia.find(nome) != listaAdjacencia.end();
}

void GrafoLogistico::exibirGrafo() const {
    std::cout << "\n=========================================================\n";
    std::cout << "          MALHA LOGÍSTICA DE ROTAS (GRAFO)\n";
    std::cout << "=========================================================\n";

    for (const auto& [local, rotas] : listaAdjacencia) {
        std::cout << "📍 [" << local << "] conecta com:\n";
        for (const auto& aresta : rotas) {
            std::cout << "   ↳ -> " << std::left << std::setw(20) << aresta.destino 
                      << " (Custo/Distância: " << aresta.peso << " km)\n";
        }
    }
    std::cout << "=========================================================\n\n";
}