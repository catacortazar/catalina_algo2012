#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	ofBackground(255, 255, 255);
	
    for (int i = 0; i < 1; i++){
		fuegos myFire;
	
		fire.push_back(myFire);
	}
    
    
    float radius = 50;
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
  
    for (int j=0; j<fire.size(); j++){
   
        fire[j].update();
      
		
        
    }
    

    
  
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    for (int j=0; j < fire.size(); j++){
        fire[j].posicionx = ofRandom(0, ofGetWidth());
        fire[j].posiciony = ofRandom(0, ofGetHeight());
        fire[j].draw();
     
      
}
    
    
         }
//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
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
void testApp::mouseReleased(){
  
    
}
