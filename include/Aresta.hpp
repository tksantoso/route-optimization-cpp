#ifndef ARESTA_HPP
#define ARESTA_HPP

#include <string>

struct Aresta {
    std::string destino;
    double peso; // Distância (km) ou tempo (minutos)

    Aresta(std::string dest, double p) : destino(dest), peso(p) {}
};

#endif // ARESTA_HPP