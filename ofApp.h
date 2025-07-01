#pragma once  // Evita incluir este archivo más de una vez

#include "ofMain.h"  // Incluye funcionalidades básicas de oF

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);

    ofImage laberintoNivel1;
    ofImage laberintoNivel2;
    ofImage milei;


    ofPixels pixelesLaberintoAzul;
    ofPixels pixelesLaberintoRojo;

    bool inicioJuego; //Variable para iniciar
    bool juegoGanado; //Variable para terminar

    bool pantalla_completa;
};