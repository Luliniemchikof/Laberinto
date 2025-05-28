#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowShape(900, 750);
    ofSetBackgroundColor(0);
    
   
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
    //Laberinto

    ofSetColor(255, 0, 0);

    //inicio ROJO
    ofBeginShape();

    ofVertex(20, 30);
    ofVertex(20, 111);
    ofVertex(80, 111);
    ofVertex(80, 30);


    ofEndShape(true);

    ofSetColor(60, 60, 230);
    // Forma 1
    ofBeginShape();

    ofVertex(12, 111);
    ofVertex(12, 500);
    ofVertex(144, 500);
    ofVertex(144, 111);


    ofEndShape(true);

    //Forma 2
    ofBeginShape();

    ofVertex(36, 500);
    ofVertex(144, 500);
    ofVertex(144, 678);
    ofVertex(36, 678);

    ofEndShape(true);

    //Forma 3
    ofBeginShape();

    ofVertex(144, 550);
    ofVertex(144, 678);
    ofVertex(820, 678);
    ofVertex(820, 550);

    ofEndShape(true);

    //Forma 4
    ofBeginShape();

    ofVertex(820, 200);
    ofVertex(820, 678);
    ofVertex(880, 678);
    ofVertex(880, 200);

    ofEndShape(true);

    //Forma 5
    ofBeginShape();

    ofVertex(475, 200);
    ofVertex(475, 250);
    ofVertex(820, 250);
    ofVertex(820, 200);

    ofEndShape(true);

    //Forma 6
    ofBeginShape();

    ofVertex(430, 80);
    ofVertex(430, 250);
    ofVertex(475, 250);
    ofVertex(475, 80);

    ofEndShape(true);

    //Forma 7
    ofBeginShape();

    ofVertex(264, 80);
    ofVertex(264, 118);
    ofVertex(475, 118);
    ofVertex(475, 80);

    ofEndShape(true);

    //Forma 8
    ofBeginShape();

    ofVertex(226, 90);
    ofVertex(226, 319);
    ofVertex(264, 319);
    ofVertex(264, 90);

    ofEndShape(true);

    //Forma 9
    ofBeginShape();

    ofVertex(264, 287);
    ofVertex(264, 319);
    ofVertex(760, 319);
    ofVertex(760, 287);

    ofEndShape(true);

    //Forma 10
    ofBeginShape();

    ofVertex(730, 319);
    ofVertex(760, 319);
    ofVertex(760, 495);
    ofVertex(730, 495);

    ofEndShape(true);

    //Forma 11
    ofBeginShape();

    ofVertex(370, 466);
    ofVertex(370, 495);
    ofVertex(730, 495);
    ofVertex(730, 466);

    ofEndShape(true);

    //Forma 12
    ofBeginShape();

    ofVertex(370, 349);
    ofVertex(370, 466);
    ofVertex(397, 466);
    ofVertex(397, 349);

    ofEndShape(true);

    //Forma 13
    ofBeginShape();

    ofVertex(397, 349);
    ofVertex(397, 410);
    ofVertex(530, 410);
    ofVertex(530, 349);

    ofEndShape(true);

    ofSetColor(255, 255, 0);
    //final AMARILLO
    ofBeginShape();

    ofVertex(530, 345);
    ofVertex(530, 415);
    ofVertex(555, 415);
    ofVertex(555, 345);

    ofEndShape(true);

    //Cuadrado mouse

    //Screenshot para mantenerse dentro de los límites del azul
    ofImage screenshot;
    screenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    pixelesLaberintoAzul = screenshot.getPixels();

    // Coordenadas del mouse
    // Tamaño y centro del cuadrado
    float size = 15;
    float halfSize = size / 2.0;

    // Coordenadas del mouse
    float mouseX = ofGetMouseX();
    float mouseY = ofGetMouseY();

    if (!inicioJuego) {
        if (mouseX >= 20 && mouseX <= 80 && mouseY >= 30 && mouseY <= 111) {
            inicioJuego = true;
        }
    }

    // Si el juego comenzó, mostramos el cuadrado solo si está completamente en azul
    if (inicioJuego) {
        float size = 15;
        float halfSize = size / 2.0;

        ofColor azul = ofColor(60, 60, 230);

        ofColor c1 = pixelesLaberintoAzul.getColor(mouseX - halfSize, mouseY - halfSize);
        ofColor c2 = pixelesLaberintoAzul.getColor(mouseX + halfSize, mouseY - halfSize);
        ofColor c3 = pixelesLaberintoAzul.getColor(mouseX - halfSize, mouseY + halfSize);
        ofColor c4 = pixelesLaberintoAzul.getColor(mouseX + halfSize, mouseY + halfSize);

        if (c1 == azul && c2 == azul && c3 == azul && c4 == azul) {
            ofSetColor(255, 0, 0);
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofDrawRectangle(mouseX, mouseY, size, size);
        }
    }

    // Si el juego ya fue iniciado y aún no se ganó
    if (inicioJuego && !juegoGanado) {
        float size = 15;
        float halfSize = size / 2.0;

        float mouseX = ofGetMouseX();
        float mouseY = ofGetMouseY();

        // Verificamos si el cuadrado está completamente sobre el azul
        ofColor azul = ofColor(60, 60, 230);

        ofColor c1 = pixelesLaberintoAzul.getColor(mouseX - halfSize, mouseY - halfSize);
        ofColor c2 = pixelesLaberintoAzul.getColor(mouseX + halfSize, mouseY - halfSize);
        ofColor c3 = pixelesLaberintoAzul.getColor(mouseX - halfSize, mouseY + halfSize);
        ofColor c4 = pixelesLaberintoAzul.getColor(mouseX + halfSize, mouseY + halfSize);

        if (c1 == azul && c2 == azul && c3 == azul && c4 == azul) {
            ofSetColor(255, 0, 0);
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofDrawRectangle(mouseX, mouseY, size, size);

            // Verificar si está dentro del área amarilla
            float left = mouseX - halfSize;
            float right = mouseX + halfSize;
            float top = mouseY - halfSize;
            float bottom = mouseY + halfSize;

            if (left >= 530 && right <= 555 && top >= 345 && bottom <= 415) {
                juegoGanado = true;
            }
        }
    }
}