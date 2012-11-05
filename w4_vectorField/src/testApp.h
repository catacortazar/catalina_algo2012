#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "vectorField.h"
#include "particle.h"

class testApp : public ofSimpleApp{  //receta para un object que tiene una aplicacion - mi codigo la esta extendiendo - se correra mi version de la que el objeto tiene // tiene todas las funciones por ejemplo mouseDragged
	
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed  (int key);
		void keyReleased (int key);
		
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();
		
		vectorField VF;
	
    
    vector <particle> particles; //vector of particles
    
    float prevMouseX;
    float prevMouseY;
   
    
    int drawingStyle; // para el tercer ejemplo
    bool bFade;
};

#endif
	
