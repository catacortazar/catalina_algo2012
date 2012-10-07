#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle
{
    public:
        ofVec3f pos;
        ofVec3f vel;
        ofVec3f frc;   // frc is also know as acceleration (newton says "f=ma") we consider m=1
			
        particle();
		

        void resetForce();
        void addForce(float x, float y);
        void addDampingForce();
        void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void draw();
		
	
		float damping;

    //que se dibuje
    ofPolyline stroke;
    bool onoff;
    
    vector < ofPolyline > lines;
    
 

};

#endif // PARTICLE_H
