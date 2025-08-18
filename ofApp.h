#pragma once  // Evita incluir este archivo m�s de una vez

#include "ofMain.h"  // Incluye funcionalidades b�sicas de oF

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
    uint64_t tiempoVictoria;   // para guardar el momento en que gan�
    bool mostrarMilei;         // flag para mostrar la imagen unos segundos
    ofVideoPlayer videoPlayer; // video

    bool open; //car�tula del juego
    ofRectangle button;//bot�n de inicio
    ofTrueTypeFont fuente;

    bool nivel1;
   // bool nivel2;
    bool video;
  

    bool pantalla_completa;
};