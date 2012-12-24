#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ball.h"


#include "particle.h"
#define N_LIGHTS 96
#define N_VALUE 3 // number of elements



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
    
        ball myBall[N_VALUE]; 
        int byte[N_VALUE];
    
        int byte2[N_VALUE];

    
        float sinOfTime[N_VALUE];
        float sinOfTimeMapped[N_VALUE];
    
    
    // let's make a vector of them
    vector <particle> particles;
	
    bool	bRepel;
    float	radius;
    float	strength;
    

    
    
};

#endif
