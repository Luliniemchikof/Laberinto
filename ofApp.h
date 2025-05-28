#pragma once  // Evita incluir este archivo m�s de una vez

#include "ofMain.h"  // Incluye funcionalidades b�sicas de oF

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

    ofPixels pixelesLaberintoAzul;
    bool inicioJuego=false; //Variable para iniciar
    bool juegoGanado = false; //Variable para terminar

};