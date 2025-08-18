#pragma once  // Evita incluir este archivo más de una vez

#include "ofMain.h"  // Incluye funcionalidades básicas de oF

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void mouseMoved(int x, int y);
    
    

    ofImage caratula;
    ofImage milei;
    ofImage captura;

    ofPixels pixelesLaberintoAzul;
    ofPixels pixelesLaberintoRojo;

    bool inicioJuego; //Variable para iniciar
    bool juegoGanado; //Variable para terminar
    bool juegoPerdido;//Variable para interrumpir
    bool pantallaGanada;
    uint64_t tiempoVictoria;   // para guardar el momento en que ganó
    bool mostrarMilei;         // flag para mostrar la imagen unos segundos
    ofVideoPlayer videoPlayer; // video

    bool open; //carátula del juego
    ofRectangle button;//botón de inicio
    ofTrueTypeFont fuente;

    bool nivel1;
   // bool nivel2;
    bool video;
  

    bool pantalla_completa;
};