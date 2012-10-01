#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofBackground(0,0,0);
	
	
	for (int i = 0; i < NUM_SHAPES; i++){
		
		myShapes[i].pos.x = ofRandom(0, ofGetWidth());
		myShapes[i].pos.y = ofRandom(0, ofGetHeight());
        myShapes[i].r = ofRandom(100,255);
        myShapes[i].g = ofRandom(100,255);
        myShapes[i].b = ofRandom(100,255);
        myShapes[i].a = ofRandom(100,255);
        myShapes[i].size = ofRandom(1,30);
        catchUpSpeed[i] = ofRandom(0.01f, 0.2f);
        type[i] = (int)ofRandom(2);
			
	}
								
} 

//--------------------------------------------------------------
void testApp::update(){
	
	
    for(int i=0; i<NUM_SHAPES; i++)
    {   myShapes[i].pos.x = catchUpSpeed[i] * mouseX + (1-catchUpSpeed[i]) * myShapes[i].pos.x;
        myShapes[i].pos.y  = catchUpSpeed[i] * mouseY + (1-catchUpSpeed[i]) * myShapes[i].pos.y;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
  ofEnableAlphaBlending();
	for (int i = 0; i<NUM_SHAPES; i++){
	  if(type[i]==0){
		myShapes[i].drawRectangle();
      }
      else if(type[i]==1)
      {
        myShapes[i].drawCircle();
	}
	
    }
	ofEnableAlphaBlending();
	
	
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
