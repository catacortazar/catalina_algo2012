#include "shapes.h"


//------------------------------------------------------------------
shapes::shapes(){
	
}

//------------------------------------------------------------------
void shapes::drawRectangle() {
    
    
	ofFill();
     ofSetColor(r,g,b,a);
    
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
   
    ofRect(pos.x, pos.y, size,size);
}


//------------------------------------------------------------------
void shapes::drawCircle() {
	ofFill();
    ofSetColor(r,g,b,a);
    
    
    ofCircle(pos.x, pos.y, size);
   
}