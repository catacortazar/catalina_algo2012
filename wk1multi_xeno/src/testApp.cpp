#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){ //build using an example from code for art

 
   
    for(int i=0; i<NUM_SHAPES; i++) 
    {
        pos[i].x = ofRandom(0, ofGetWidth());
		pos[i].y = ofRandom(0, ofGetHeight());
		
		size[i] = ofRandom(10, 100);
		
		color[i].r = ofRandom(100, 255);
		color[i].g = ofRandom(100, 255);
		color[i].b = ofRandom(100, 255);
		color[i].a = ofRandom(100, 255);
            type[i] = (int)ofRandom(2); // casting the random to an integer  
        
       catchUpSpeed[i] = ofRandom(0.01f, 0.2f);
   
    }
}



//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<NUM_SHAPES; i++)
    {   pos[i].x = catchUpSpeed[i] * mouseX + (1-catchUpSpeed[i]) * pos[i].x;
        pos[i].y = catchUpSpeed[i] * mouseY + (1-catchUpSpeed[i]) * pos[i].y;
    }



}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();

    for(int i=0; i<NUM_SHAPES; i++)
    {
        
        //ofSetColor(r[i], g[i], b[i]);
		ofSetColor(color[i]);
        if(type[i]==0)
        {
            
            ofCircle(pos[i].x, pos[i].y, size[i]);
        }
        else if(type[i]==1)
        {
            ofRect(pos[i].x, pos[i].y, size[i], size[i]);
        }

		    }
	ofDisableAlphaBlending();
	
}
//-----------------




//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}