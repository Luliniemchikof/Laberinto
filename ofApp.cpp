#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowShape(960, 540);

	pantalla_completa = false;

	milei.load("milei.jpg");
	inicioJuego = true;
	ofBackground(55, 250, 250);

	ofSetFullscreen(pantalla_completa);


	milei.load("milei.jpg");
	caratula.load("caratula.jpg");

	inicioJuego = false;
	juegoGanado = false;
	juegoPerdido = false;

	open = true;
	nivel1 = false;
	nivel2 = false;
	video = false;
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {


	// Escalado proporcional según resolución actual
	float escalaX = (float)ofGetWidth() / 1920.0;
	float escalaY = (float)ofGetHeight() / 1080.0;
	//Escalado del mouse
	float mouseXVirtual = ofGetMouseX() / escalaX;
	float mouseYVirtual = ofGetMouseY() / escalaY;

	if (open) {
		caratula.draw(0, 0, ofGetWidth(), ofGetHeight()); // Escala exacta a la ventana 
		inicioJuego = false;
		juegoGanado = false;
		juegoPerdido = false;
		ofShowCursor();
	}
	if (nivel2) { //----------Nivel2--------------------
		ofPushMatrix();

		ofScale(escalaX, escalaY);

		ofSetColor(0);
		ofDrawRectangle(0, 0, 1920, 50); //1
		ofDrawRectangle(0, 50, 835, 400); //2
		ofDrawRectangle(0, 450, 96, 630); //3
		ofDrawRectangle(95, 813, 1630, 44); //4
		ofDrawRectangle(96, 950, 1824, 130); //5
		ofDrawRectangle(1810, 740, 110, 210); //6
		ofDrawRectangle(1028, 50, 892, 690); //7
		ofDrawRectangle(170, 526, 870, 214); //8
		ofDrawRectangle(885, 470, 100, 56); //9
		ofDrawRectangle(965, 270, 75, 257); //10
		ofDrawRectangle(835, 394, 115, 56); //11
		ofDrawRectangle(850, 340, 115, 35); //12
		ofDrawRectangle(880, 270, 65, 50); //13
		ofDrawRectangle(830, 45, 50, 275); //14

		ofSetColor(255, 255, 0);
		ofDrawRectangle(95, 857, 50, 93);

		ofSetColor(255, 0, 0);
		ofDrawRectangle(880, 50, 161, 220);
		ofPopMatrix(); //Cierre del escalado


	}

	// Verificamos si el mouse está sobre el rectángulo amarillo de inicio
	if (!inicioJuego && nivel2) {
		//defino una zona menor para que el juego no termine antes
		if (mouseXVirtual >= 93 && mouseXVirtual <= 93 + 45 &&
			mouseYVirtual >= 854 && mouseYVirtual <= 854 + 90) {
			inicioJuego = true;
			cout << "¡Juego iniciado!" << endl;
		}
	}

	// Dibujo el cursor si el juego comenzó
	if (inicioJuego && !juegoPerdido && nivel2) {
		ofHideCursor();
		ofSetColor(255, 0, 0);
		ofSetRectMode(OF_RECTMODE_CENTER);
		float size = 7;
		float halfSize = size / 2.0;
		ofDrawRectangle(ofGetMouseX(), ofGetMouseY(), size, size);


		int x = ofGetMouseX();
		int y = ofGetMouseY();

		// Verificación de colisión solo si el juego inició y no se perdió
		ofImage captura;
		captura.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		ofPixels pixeles = captura.getPixels();

		ofColor c1 = pixeles.getColor(x - halfSize, y - halfSize);
		ofColor c2 = pixeles.getColor(x + halfSize, y - halfSize);
		ofColor c3 = pixeles.getColor(x - halfSize, y + halfSize);
		ofColor c4 = pixeles.getColor(x + halfSize, y + halfSize);

		ofColor negro = ofColor(0, 0, 0);
		if (c1 == negro || c2 == negro || c3 == negro || c4 == negro) {
			juegoPerdido = true;
			cout << "¡Perdiste!" << endl;
		}
	}
	if (!juegoGanado && inicioJuego && nivel2) { //Busco posición del cuadrado rojo
		float escalaX = (float)ofGetWidth() / 1920.0;
		float escalaY = (float)ofGetHeight() / 1080.0;
		float mouseXVirtual = ofGetMouseX() / escalaX;
		float mouseYVirtual = ofGetMouseY() / escalaY;


		if (mouseXVirtual >= 880 && mouseXVirtual <= 880 + 161 &&
			mouseYVirtual >= 50 && mouseYVirtual <= 50 + 220) {  //880, 50, 161, 220
			juegoGanado = true;
			cout << "¡Juego Ganado!" << endl;
		}
	}

	ofSetRectMode(OF_RECTMODE_CORNER); // Restaurar modo

	if (juegoPerdido && nivel2) {
		ofSetColor(255); // Asegura color completo
		nivel2 = false;
		nivel1 = true;
		inicioJuego = false;
		juegoPerdido = false;



	}

	if (juegoGanado && nivel2) {
		inicioJuego = false;
		nivel2 = false;
		juegoGanado = false;
		open = true;
	}

	//-------Nivel1----------------------------------------
	if (nivel1) {
		
		ofPushMatrix();

		ofScale(escalaX, escalaY);

		ofSetColor(0);
		ofDrawRectangle(0, 0, 660, 315); //1

		ofDrawRectangle(0, 300, 90, 720);//2

		ofDrawRectangle(90, 300, 40, 140);//3

		ofDrawRectangle(0, 1020, 1840, 60); //4

		ofDrawRectangle(1840, 70, 80, 1010); //5

		ofDrawRectangle(660, 0, 1260, 70); //6

		ofDrawRectangle(240, 300, 420, 140);//7

		ofDrawRectangle(275, 440, 385, 415); //8

		ofDrawRectangle(660, 680, 1015, 175); //9

		ofDrawRectangle(1515, 200, 160, 480);//10

		ofDrawRectangle(787, 200, 730, 107); //11

		ofDrawRectangle(787, 300, 198, 260); //12

		ofDrawRectangle(980, 495, 190, 65); //13

		ofDrawRectangle(1167, 410, 253, 150); //14

		ofDrawRectangle(1020, 365, 400, 65);//15

		ofSetColor(255, 255, 0);
		ofDrawRectangle(130, 315, 110, 125);

		ofSetColor(255, 0, 0);
		ofDrawRectangle(1145, 430, 120, 65);

		ofPopMatrix(); //Cierre del escalado

	}


	// Verificamos si el mouse está sobre el rectángulo amarillo de inicio
	if (!inicioJuego && nivel1) {
		//defino una zona menor para que el juego no termine antes
		if (mouseXVirtual >= 140 && mouseXVirtual <= 140 + 80 &&
			mouseYVirtual >= 320 && mouseYVirtual <= 320 + 100) {
			inicioJuego = true;
			cout << "¡Juego iniciado!" << endl;
		}
	}

	// Dibujo el cursor si el juego comenzó
	if (inicioJuego && !juegoPerdido && nivel1) {
		ofHideCursor();
		ofSetColor(255, 0, 0);
		ofSetRectMode(OF_RECTMODE_CENTER);
		float size = 8;
		float halfSize = size / 2.0;
		ofDrawRectangle(ofGetMouseX(), ofGetMouseY(), size, size);


		int x = ofGetMouseX();
		int y = ofGetMouseY();

		// Verificación de colisión solo si el juego inició y no se perdió
		ofImage captura;
		captura.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		ofPixels pixeles = captura.getPixels();

		ofColor c1 = pixeles.getColor(x - halfSize, y - halfSize);
		ofColor c2 = pixeles.getColor(x + halfSize, y - halfSize);
		ofColor c3 = pixeles.getColor(x - halfSize, y + halfSize);
		ofColor c4 = pixeles.getColor(x + halfSize, y + halfSize);

		ofColor negro = ofColor(0, 0, 0);
		if (c1 == negro || c2 == negro || c3 == negro || c4 == negro) {
			juegoPerdido = true;
			cout << "¡Perdiste!" << endl;
		}
	}
	if (!juegoGanado && inicioJuego && nivel1) { //Busco posición del cuadrado rojo
		float escalaX = (float)ofGetWidth() / 1920.0;
		float escalaY = (float)ofGetHeight() / 1080.0;
		float mouseXVirtual = ofGetMouseX() / escalaX;
		float mouseYVirtual = ofGetMouseY() / escalaY;

		//defino una zona menor para que el juego no termine antes
		if (mouseXVirtual >= 1145 && mouseXVirtual <= 1145 + 120 &&
			mouseYVirtual >= 430 && mouseYVirtual <= 430 + 65) {
			juegoGanado = true;
			cout << "¡Juego Ganado!" << endl;
		}
	}

	ofSetRectMode(OF_RECTMODE_CORNER); // Restaurar modo

	if (juegoPerdido && nivel1) {
		ofSetColor(255); // Asegura color completo
		inicioJuego = false;
		open = true;
		nivel1 = false;
		juegoPerdido = false;
		ofShowCursor();
	}

	if (juegoGanado && nivel1) {
		inicioJuego = false;
		nivel1 = false;
		nivel2 = true;
		juegoGanado = false;
		ofShowCursor();
	}

	






}
//-------------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 'f' || key == 'F')
	{
		ofToggleFullscreen();
		pantalla_completa = !pantalla_completa;
	}

	if (open && key == ' ') {
		open = false;
		nivel1 = true;
	}
}
