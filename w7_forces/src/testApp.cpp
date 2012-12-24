#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	 
    ofEnableAlphaBlending();
	ofBackground(0,0,0);
	ofSetBackgroundAuto(false);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
      bSavePdf = false;
	
	
	for (int i = 0; i < 10; i++){
		particle myParticle;
		
		float x = 500 + 100 * cos ( (i / 200.0) * TWO_PI);
		float y = 500 + 100 * sin ( (i / 200.0) * TWO_PI);
		
		myParticle.setInitialCondition(x,y ,0,0);
		particles.push_back(myParticle);
	}
	
	// change this to
	// for (int i = 0; i < 10; i++){
	// to see a chain
	
	for (int i = 0; i < particles.size(); i++){
		spring mySpring;
		mySpring.distance		= 10;
		mySpring.springiness	= 0.2f;
		mySpring.particleA = & (particles[i  ]);
		mySpring.particleB = & (particles[(i+1) % particles.size()]);
		springs.push_back(mySpring);
	}
	
    //set up timer
    
    startTime = ofGetElapsedTimeMillis(); //gets start time
    duration = 10;
	
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
		
		particles[i].addRepulsionForce(mouseX, mouseY, 200, 0.7f);
		
		for (int j = 0; j < i; j++){
			particles[i].addRepulsionForce(particles[j], 200, 0.2f);
		}
	}
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].update();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].bounceOffWalls();
		particles[i].addDampingForce();
		particles[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
  
	
    int timer = ofGetElapsedTimeMillis() - startTime;
   
//    if (timer%20==0){
//        
//        
//       ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".pdf", false);
//        
//        
//        
//    }

  
    
	 ofSetColor(0xffffff);
   
    for (int i = 0; i < particles.size(); i++){
  
        if(particles[i].pos.x <= 200){
            
            ofSetColor(2, 0, 127, ofRandom(0,255));
        
        }
        
        if(particles[i].pos.x >= 201 && particles[i].pos.x <= 400){
            
            ofSetColor(3, 35, 191,ofRandom(0,255));
        }
        
        if(particles[i].pos.x >= 401 && particles[i].pos.x <= 600){
            
            ofSetColor(5, 0, 255, ofRandom(0,255));
        }
        
        if(particles[i].pos.x >= 601 && particles[i].pos.x <= 800){
            
            ofSetColor(0, 163, 255, ofRandom(0,255));
        }
        if(particles[i].pos.x >= 801 && particles[i].pos.x <= 1000){
            
            ofSetColor(4, 0, 229, ofRandom(0,255));
        }
        
		particles[i].draw();
	}
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].draw();
	}
   
startTime = ofGetElapsedTimeMillis();
    
  
    
    
    

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    
    if (key == 'p'){
   ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".pdf", false);
           }
	
	switch (key){
			
		case ' ':
			// reposition everything: 
			for (int i = 0; i < particles.size(); i++){
				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
			}
			break;
	}
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	particles[0].pos.set(mouseX, mouseY);
	//particles.erase(particles.begin());
	/*particle myParticle;
	myParticle.setInitialCondition(x,y,0,0);
	particles.push_back(myParticle);*/
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particles[0].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	
	particles[0].bFixed = false;
}

