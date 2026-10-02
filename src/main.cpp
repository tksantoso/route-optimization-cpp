#include "../include/GrafoLogistico.hpp"
#include "../include/OtimizadorDijkstra.hpp"
#include <iostream>
#include <iomanip>

void exibirRotaCalculada(const ResultadoRota& res, const std::string& origem, const std::string& destino) {
    std::cout << "\n=========================================================\n";
    std::cout << " 🚚 RESULTADO DA OTIMIZAÇÃO DE ROTA LOGÍSTICA\n";
    std::cout << "=========================================================\n";
    std::cout << " Origem:  " << origem << "\n";
    std::cout << " Destino: " << destino << "\n";

    if (res.rotaEncontrada) {
        std::cout << " Custo/Distância Total Mínima: " << std::fixed << std::setprecision(2) << res.custoTotal << " km\n";
        std::cout << "\n 🛣️ Rota Otimizada (Passo a Passo):\n ";
        for (size_t i = 0; i < res.caminho.size(); ++i) {
            std::cout << res.caminho[i];
            if (i < res.caminho.size() - 1) {
                std::cout << " ➔ ";
            }
        }
        std::cout << "\n";
    } else {
        std::cout << " ❌ Nenhuma rota válida foi encontrada entre os pontos especificados.\n";
    }
    std::cout << "=========================================================\n\n";
}

int main() {
    GrafoLogistico malha;

    // Montando Malha Logística do Estado de São Paulo
    malha.adicionarRota("CD Osasco", "CD Lapa", 12.5);
    malha.adicionarRota("CD Osasco", "Hub Campinas", 88.0);
    malha.adicionarRota("CD Lapa", "Hub Guarulhos", 25.0);
    malha.adicionarRota("Hub Campinas", "Filial Ribeirao Preto", 220.0);
    malha.adicionarRota("Hub Guarulhos", "Filial SJC", 85.0);
    malha.adicionarRota("Hub Guarulhos", "Hub Campinas", 95.0);
    malha.adicionarRota("Filial SJC", "Filial Taubate", 45.0);
    malha.adicionarRota("Filial Taubate", "Filial Ribeirao Preto", 310.0);
    malha.adicionarRota("Hub Campinas", "Filial Taubate", 130.0);

    // Exibe a malha completa
    malha.exibirGrafo();

    // Caso de Teste 1: Rota Otimizada de Osasco até Ribeirão Preto
    std::string origem = "CD Osasco";
    std::string destino = "Filial Ribeirao Preto";

    ResultadoRota rota1 = OtimizadorDijkstra::calcularRotaMaisCurta(malha, origem, destino);
    exibirRotaCalculada(rota1, origem, destino);

    // Caso de Teste 2: Rota Otimizada de Osasco até Taubaté
    origem = "CD Osasco";
    destino = "Filial Taubate";

    ResultadoRota rota2 = OtimizadorDijkstra::calcularRotaMaisCurta(malha, origem, destino);
    exibirRotaCalculada(rota2, origem, destino);

    return 0;
}