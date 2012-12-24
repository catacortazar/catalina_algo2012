#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "timePoint.h"
#include "timePointRecorder.h"

#define N_LIGHTS 16


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    void exit(){
        serial.close();
    }

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

        ofSerial serial;
    
        timePointRecorder		TPR;
        float					playbackStartTime;

        float fade;
    
    
};

#endif
