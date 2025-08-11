#pragma once  // Evita incluir este archivo más de una vez

#include "ofMain.h"  // Incluye funcionalidades básicas de oF

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    
    

    ofImage caratula;
    ofImage milei;
    ofImage captura;

    ofPixels pixelesLaberintoAzul;
    ofPixels pixelesLaberintoRojo;

    bool inicioJuego; //Variable para iniciar
    bool juegoGanado; //Variable para terminar
    bool juegoPerdido;//Variable para interrumpir

    bool open; //carátula del juego
    bool nivel1;
    bool nivel2;
    bool video;

    bool pantalla_completa;
};