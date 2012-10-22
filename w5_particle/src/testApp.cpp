#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	for (int i = 0; i < 1000; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}
	
	bRepel		= true;
	radius		= 40;
	strength	= 0.5f; 
	
	
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
		
        //para las fuerzas entre las particulas
//		for (int j = 0; j < i; j++){
//			particles[i].addRepulsionForce(particles[j], 50, 0.4);
//			particles[i].addAttractionForce(particles[j], 500, 0.005);
//		}
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
	
	ofEnableAlphaBlending();
    
    //if it's close enough to the mouse have another color
    
    for (int i = 0; i < particles.size(); i++){
            if (((particles[i].pos.x < mouseX && (mouseX - particles[i].pos.x ) <= 40) || ((particles[i].pos.x > mouseX && (- mouseX + particles[i].pos.x ) <= 40)) ) && (((particles[i].pos.y < mouseY && (mouseY - particles[i].pos.y ) <= 40))   ||((particles[i].pos.y > mouseY && (- mouseY + particles[i].pos.y ) <= 40)))
                
                
                ){
        
                
    ofSetColor(0,0,0, ofRandom(200, 255));
                    //ofSetColor(11,37,232, ofRandom(0, 255));
                       particles[i].draw();
               }
        
            else {
    ofSetColor(ofRandom(0, 255),ofRandom(0, 255),ofRandom(0, 255), 200);
    particles[i].draw();
    }
	}
//	string reportString =	"(space) = reset\n(a/s) strength = " + ofToString(strength) +
//							"\n(z/x) radius = " + ofToString(radius) + 
//							"\n(r) toggle mode = " + (bRepel ? "repelling" : "attracting");
	
//	ofSetColor(40,40,0);
//	ofRect(10,10,300,80);
//	ofSetColor(255,255,255);
//	ofDrawBitmapString(reportString, 30, 30);
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
//	switch (key){
//			
//		case ' ':
//			// reposition everything: 
//			for (int i = 0; i < particles.size(); i++){
//				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
//			}
//			break;
//		case 'a':
//			strength += 0.02f;
//			break;
//		case 's':
//			strength -= 0.02f;
//			if (strength <= 0) strength = 0.02f;
//			break;
//		case 'z':
//			radius += 5.0f;
//			break;
//		case 'x':
//			radius -= 5.0f;
//			if (radius <= 0) radius = 5.0f;
//			break;
//		case 'r':
//			bRepel = !bRepel;
//			break;
//	}
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
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
void testApp::mouseReleased(){
}
