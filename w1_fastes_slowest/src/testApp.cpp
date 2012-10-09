#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofBackground(30,30,30);
	
	// now we are using multiple rectangles....
	// set the "a" and "b" positions of the
	for (int i = 0; i < 2; i++){
		myRectangles[i].posa.x = 0;
		myRectangles[i].posa.y = 100 + i*(20+10) ;
		myRectangles[i].posb.x = 400;
		myRectangles[i].posb.y = 100 + i*(20+10);
	
		myRectangles[i].interpolateByPct(0);	// start at 0 pct
	}
	pct = 0;							// a variable we can alter...
} 

//--------------------------------------------------------------
void testApp::update(){
	
	for (int i = 0; i < 2; i++){
        
    if(i == 0){                         // fastest - imperceptible
        pct += 0.02f;							// increase by a certain amount
        if (pct > 1) pct = 0;					// just between 0 and 1 (0% and 100%)
      
		myRectangles[0].interpolateByPct(pct);		// go between pta and ptb
	
    }
        
    if(i == 1){                                 //  continuous (not discrete jumps

        pct += 0.00055f;							// increase by a certain amount
        if (pct > 1) pct = 0;					// just between 0 and 1 (0% and 100%)
        
		myRectangles[1].interpolateByPct(pct);
     }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
	for (int i = 0; i < 2; i++){
		ofSetColor(198,246,55);
		
		myRectangles[i].draw();
	}
	
	ofSetColor(255,255,255);
	for (int i = 0; i < 3; i++){
		ofLine(0,(90 + i*(20+10)), ofGetWidth(), (90 + i*(20+10)));
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
