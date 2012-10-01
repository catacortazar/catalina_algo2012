#include "circle.h"


//------------------------------------------------------------------
circle::circle(){ //to create an object we need to call the class constructor

    //map el color al seno of time 
    
    float sinOfTime = sin( ofGetElapsedTimef() * 1);
	float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 0, 255);
    ofEnableAlphaBlending(); //para cambiar la transparencia
	color.set(255, 250, 205, sinOfTimeMapped); //initial color amarillo un poco
  
    

    
}


//------------------------------------------------------------------


//------------------------------------------------------------------
void circle::draw() {

    ofSetColor(color);
    
    ofCircle(x, y, ofRandom(0.7, 1.7));
}

