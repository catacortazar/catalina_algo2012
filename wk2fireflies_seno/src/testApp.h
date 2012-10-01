#pragma once

#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "circle.h" //add this file

class testApp : public ofBaseApp{ //porque simpleApp y  no baseApp ????

	public:
		void setup();
		void update();
		void draw();
		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
    
        circle myCircle[30]; //reemplaza la variable circle con el objeto mycircle que tiene la info
    };

#endif
