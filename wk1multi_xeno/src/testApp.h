#pragma once

#include "ofMain.h"

#define NUM_SHAPES 10

class testApp : public ofBaseApp{

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
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
		float size[NUM_SHAPES];
		int type[NUM_SHAPES];   // 0 = circle, 1 = square
		
		ofColor color[NUM_SHAPES];
        float catchUpSpeed[NUM_SHAPES];		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
	
		
};
