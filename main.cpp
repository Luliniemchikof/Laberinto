#include "ofMain.h"
#include "ofApp.h"  // Incluye la clase que definiste

//========================================================================
int main() {
    ofSetupOpenGL(1024, 768, OF_WINDOW);  // Tamaño de la ventana
    ofRunApp(new ofApp());              // Crea una instancia de tu app
}
