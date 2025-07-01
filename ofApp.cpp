#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowShape(960, 540);
    ofHideCursor();

    pantalla_completa = false;

    laberintoNivel1.load("laberinto1.jpg");
    laberintoNivel2.load("laberinto2.jpg");
    milei.load("milei.jpg");
    inicioJuego = true;
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
    // Dibuja la imagen escalada al tamaño de la ventana
    laberintoNivel1.draw(0, 0, ofGetWidth(), ofGetHeight());

    // Coordenadas del mouse en la ventana
    int mouseX = ofGetMouseX();
    int mouseY = ofGetMouseY();

    // Escala las coordenadas del mouse al tamaño real de la imagen (1920x1080)
    float escalaX = laberintoNivel1.getWidth() / (float)ofGetWidth();
    float escalaY = laberintoNivel1.getHeight() / (float)ofGetHeight();

    int imgX = mouseX * escalaX;
    int imgY = mouseY * escalaY;

    // Verificamos si está dentro de la imagen
    if (imgX >= 0 && imgX < laberintoNivel1.getWidth() &&
        imgY >= 0 && imgY < laberintoNivel1.getHeight()) {

        ofPixels& pixeles = laberintoNivel1.getPixels();
        ofColor color = pixeles.getColor(imgX, imgY);

       

       /* // Si el juego ya comenzó, mostramos el cuadrado rojo
       * 
       * //esto rompe la imágen
        if (inicioJuego) {
            float size = 16;
            ofSetColor(255, 0, 0);
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofDrawRectangle(mouseX, mouseY, size, size);
        }*/
    }
}
//--------------------------------------------------------------------
// Para ir cambiando del modo ventana al fullscreen con la tecla 'f'.
void ofApp::keyPressed(int key)
{
    if (key == 'f' || key == 'F')
    {
        ofToggleFullscreen();
        pantalla_completa = !pantalla_completa;
    }
}

