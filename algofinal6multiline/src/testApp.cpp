#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);
    
    serial.listDevices();
    
    serial.setup(5, 115200);
    
    TPR.setup();
	playbackStartTime = 0;
    
    fade = 0;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
	
    
    
    //----------------------------------- start draw for LEDS
    
    
    //    ofBackground( (int)( ofGetElapsedTimef() * 100 ) % 255);
    
    //    float sinOfTime = sin( ofGetElapsedTimef() * 10 );
    //    float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 0 ,30);
    //    ofSetColor( 127 + 127 * sin(ofGetElapsedTimef()));
    //    ofCircle(mouseX, ofGetHeight() * .5, sinOfTimeMapped * 10.0);
    
    
	// -------------------------- draw the line
	
    
    ofSetColor(fade);
    ofSetLineWidth(5);
    TPR.draw();
	
	// -------------------------- draw the point at the current time
	if (TPR.bHaveADrawing()){			// if we have a drawing to work with
		
		// figure out what time we are at, and make sure we playback cyclically (!)
		// use the duration here and make sure our timeToCheck is in the range of 0 - duration
		float timeToCheck = ofGetElapsedTimef() - playbackStartTime;
		while (timeToCheck > TPR.getDuration() && TPR.getDuration() > 0){
			timeToCheck -= TPR.getDuration();
		}
		
		// get the position and velocity at timeToCheck
		ofPoint pos = TPR.getPositionForTime(timeToCheck);
		ofPoint vel = TPR.getVelocityForTime(timeToCheck);
		
		// since velocity is a line, we want to know how long it is. 
		float lengthOfVel = ofDist(0,0,vel.x, vel.y);
		
		ofFill();
        float sinOfTime = sin( ofGetElapsedTimef() * 5 );
        float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 10 ,40);
        ofSetColor( 127 + 127 * sin(ofGetElapsedTimef()));
        //    ofCircle(mouseX, ofGetHeight() * .5, sinOfTimeMapped * 10.0);
		ofCircle(pos.x, pos.y, 2 + lengthOfVel/5.0);
		
		
	}
	
    
    
    
    //----------------------------------- end draw for LEDS
    
    
    ofImage imgTemp;
    imgTemp.grabScreen(0, ofGetHeight()/2, ofGetWidth(), 6);
    imgTemp.setImageType(OF_IMAGE_GRAYSCALE );
    
    imgTemp.resize(N_LIGHTS, 6);
    
    unsigned char * pixels = imgTemp.getPixels();
    
    
    
    
    
    if (ofGetFrameNum() % 3 == 0){
        serial.writeByte(255);
        for (int j = 0; j < N_LIGHTS; j++){
            float pct = ofMap(pixels[j], 0, 255, 0 , 1, true);
            float value = ofMap( powf(pct, 2), 0, 1, 0,253, true);
            serial.writeByte(value);
            
            //if (j %  (int)ofClamp(mouseX, 1, 10) == 0) serial.writeByte(254);
            //else serial.writeByte(0);
        }
    }
    
    ofSetColor(127);
    ofFill();
    ofRect(0, ofGetHeight()/2, ofGetWidth(), 6);
    
}



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
    TPR.addPoint(x,y);
    fade = 255;
    
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    TPR.startDrawing(x,y);
    fade = 255;
    
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    TPR.endDrawing();
	playbackStartTime = ofGetElapsedTimef();
    fade = 0;
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

