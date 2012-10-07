#ifndef FUEGOS_H
#define FUEGOS_H

#include "ofMain.h"

#include "particle.h"

class fuegos
{
    public:
    fuegos();
    bool onoff;
    void draw();
     void update();
    
    vector <particle> particles;
    
    //hagamos un timer
    int s;
    int m;
    int h;
    int lastSecond;
    
    float posicionx;
    float posiciony;
    
    //        ofVec3f pos;
//        ofVec3f vel;
//        ofVec3f frc;   // frc is also know as acceleration (newton says "f=ma") we consider m=1
//			
//        particle();
//		virtual ~particle(){};
//
//        void resetForce();
//        void addForce(float x, float y);
//        void addDampingForce();
//        void setInitialCondition(float px, float py, float vx, float vy);
//       

//		
//	
//		float damping;
//
//    protected:
//    private:
//    
//    //que se dibuje
//    ofPolyline stroke;
//    bool onoff;
//    
//    vector < ofPolyline > lines;
    
 

};

#endif // FUEGOS_H
