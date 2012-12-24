#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(255, 255, 255);
	
	ofSetCircleResolution(100);
    
    serial.listDevices();
    
    serial.setup(5, 115200);
    ofSetVerticalSync(true);


	for (int i = 0; i < 1000; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}
	
	bRepel		= true;
	radius		= 40;
	strength	= 0.5f;
	


    //ofSetFrameRate(5);
    
//    int 			readBytes(unsigned char * buffer, int length);
//    int 			writeBytes(unsigned char * buffer, int length);
//    bool			writeByte(unsigned char singleByte);
//    int             readByte();  // returns -1 on no read or error...
//    void			flush(bool flushIn = true, bool flushOut = true);
//    int				available();

    
}

//--------------------------------------------------------------
void testApp::update(){
    // on every frame
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		
		particles[i].addAttractionForce(mouseX, mouseY, 80, 1.2);
        
        particles[i].addRepulsionForce(mouseX, mouseY, 250, 0.4);
		
        
		for (int j = 0; j < i; j++){
			if (bRepel){
				particles[i].addRepulsionForce(particles[j], radius, strength);
			} else {
                particles[i].addAttractionForce(particles[j], radius, strength);
			}
		}
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addDampingForce();
		particles[i].update();
	}
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
	
        
    
    //----------------------------------- start draw for LEDS
    
    
//    ofBackground( (int)( ofGetElapsedTimef() * 100 ) % 255);
//        
//    float sinOfTime = sin( ofGetElapsedTimef() * 10 );
//    float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 0 ,30);
//    ofSetColor( 127 + 127 * sin(ofGetElapsedTimef()));
//    ofCircle(mouseX, ofGetHeight() * .5, sinOfTimeMapped * 10.0);
//    
//    
    
    //------- my particles 
   
    ofEnableAlphaBlending();
    
    //if it's close enough to the mouse have another color
    
    
    
    for (int i = 0; i < particles.size(); i++){
        
        
        
        ofPoint diff = ofPoint(mouseX, mouseY) - particles[i].pos;
        
        if (diff.length() < 40){
            
            ofSetColor(0,0,0, ofRandom(200, 255));
            particles[i].draw();
            
        } else {
            
            if (ofGetFrameNum() % 50 == 0){
                particles[i].colorTarget.set(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255));
            }
            ofSetColor(particles[i].color.x, particles[i].color.y, particles[i].color.z);
            particles[i].draw();
            
        }
        
        
        
	}


    
    
    //----------------------------------- end draw for LEDS
    
    
    ofImage imgTemp;
    imgTemp.grabScreen(0, ofGetHeight()/2, ofGetWidth(), 2);
    imgTemp.setImageType(OF_IMAGE_GRAYSCALE );
    
    imgTemp.resize(N_LIGHTS, 2);
    
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

ofSetColor(255);
    ofRect(0, ofGetHeight()/2, ofGetWidth(), 2);

    
    
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
    particles.erase(particles.begin());
	particle myParticle;
	myParticle.setInitialCondition(x,y,0,0);
	particles.push_back(myParticle);


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

