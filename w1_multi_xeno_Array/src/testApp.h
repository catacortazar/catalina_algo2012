#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "shapes.h"

#define NUM_SHAPES 10
class testApp : public ofSimpleApp{

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

		shapes myShapes[NUM_SHAPES];
        float catchUpSpeed[NUM_SHAPES];		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
	
	int type[NUM_SHAPES]; 
};

#endif

