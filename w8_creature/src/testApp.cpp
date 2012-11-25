#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(255,255,255);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    ofEnableSmoothing();
    
    //escribir las particulas que forman los springs
	particle myParticle;
    myParticle.setInitialCondition(323,400,0,0);
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(168,350,0,0);
	particles.push_back(myParticle);
	
    
    myParticle.setInitialCondition(500,109,0,0);
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(700,203,0,0);
	particles.push_back(myParticle);
    
    myParticle.setInitialCondition(0,309,0,0);
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(100,203,0,0);
	particles.push_back(myParticle);

    //escribir las particulas que hacen los ojos
    
   particle myOjos;
    myOjos.setInitialCondition(500,500,0,0);
	ojos.push_back(myOjos);
    
    myOjos.setInitialCondition(600,500,0,0);
	ojos.push_back(myOjos);
    
    myOjos.setInitialCondition(700,300,0,0);
	ojos.push_back(myOjos);
    
    myOjos.setInitialCondition(800,300,0,0);
	ojos.push_back(myOjos);
    
    
    myOjos.setInitialCondition(300,300,0,0);
	ojos.push_back(myOjos);
    
    myOjos.setInitialCondition(400,300,0,0);
	ojos.push_back(myOjos);
    
   //escribir los springs
    
    spring mySpring;
		

		//mySpring.distance		= 500; no se usa si esta definido abajo 
    
	// primer creature
    

	mySpring.distance		= (particles[0].pos - particles[1].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[0]);
	mySpring.particleB = & (particles[1]);
	springs.push_back(mySpring);
//
//    
    mySpring.distance		= (particles[0].pos - ojos[0].pos).length();
	mySpring.springiness	= 0.1f;
	mySpring.particleA = & (particles[0]);
	mySpring.particleB = & (ojos[0]);
	springs.push_back(mySpring);
//
    mySpring.distance		= (particles[1].pos - ojos[1].pos).length();
	mySpring.springiness	= 0.1f;
	mySpring.particleA = & (particles[1]);
	mySpring.particleB = & (ojos[1]);
	springs.push_back(mySpring);
    
    
    mySpring.distance		= (ojos[0].pos - ojos[1].pos).length();
	mySpring.springiness	= 1.0f;
	mySpring.particleA = & (ojos[0]);
	mySpring.particleB = & (ojos[1]);
	springs.push_back(mySpring);
//
//    
//	// segunda creature
//    
    mySpring.distance		= (particles[2].pos - particles[3].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[2]);
	mySpring.particleB = & (particles[3]);
	springs.push_back(mySpring);
    
    
    mySpring.distance		= (particles[2].pos - ojos[2].pos).length();
	mySpring.springiness	= 0.1f;
	mySpring.particleA = & (particles[2]);
	mySpring.particleB = & (ojos[2]);
	springs.push_back(mySpring);
    
    mySpring.distance		= (particles[3].pos - ojos[3].pos).length();
	mySpring.springiness	= 0.1f;
	mySpring.particleA = & (particles[3]);
	mySpring.particleB = & (ojos[3]);
	springs.push_back(mySpring);
    
    
    mySpring.distance		= (ojos[2].pos - ojos[3].pos).length();
	mySpring.springiness	= 1.0f;
	mySpring.particleA = & (ojos[2]);
	mySpring.particleB = & (ojos[3]);
	springs.push_back(mySpring);
//
    // tercera creature
    
    mySpring.distance		= (particles[4].pos - particles[4].pos).length();
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[4]);
	mySpring.particleB = & (particles[5]);
	springs.push_back(mySpring);
    
    
    mySpring.distance		= (particles[4].pos - ojos[4].pos).length();
	mySpring.springiness	= 0.1f;
	mySpring.particleA = & (particles[4]);
	mySpring.particleB = & (ojos[4]);
	springs.push_back(mySpring);
    
    mySpring.distance		= (particles[5].pos - ojos[5].pos).length();
	mySpring.springiness	= 0.1f;
	mySpring.particleA = & (particles[5]);
	mySpring.particleB = & (ojos[5]);
	springs.push_back(mySpring);
    
    
    mySpring.distance		= (ojos[4].pos - ojos[5].pos).length();
	mySpring.springiness	= 1.0f;
	mySpring.particleA = & (ojos[4]);
	mySpring.particleB = & (ojos[5]);
	springs.push_back(mySpring);
//
    
	
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
		//particles[i].addRepulsionForce(mouseX, mouseY, 300, 0.7f);
       // particles[i].addClockwiseForce(particles[i], 300, 0.7f);
	}
    
    for (int i = 0; i < ojos.size(); i++){
		ojos[i].resetForce();
		ojos[i].addAttractionForce(mouseX, mouseY, 300, 0.7f); //solo a los ojos
       // no me resulta esta fuerza ojos[i].addAttractionForce(ojos[i].pos.x, ojos[i].pos.y, 300, 0.3f); //solo a los ojos
	}
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].update();
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].bounceOffWalls();
		particles[i].addDampingForce();
		particles[i].update();
	}
    
    for (int i = 0; i < ojos.size(); i++){
		ojos[i].bounceOffWalls();
		ojos[i].addDampingForce();
		ojos[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	

	
    ofEnableSmoothing();
	
	for (int i = 0; i < particles.size(); i++){
        particles[i].radio = 0;
		particles[i].draw();
	}
	
    for (int i = 0; i < ojos.size(); i++){
       
       ofNoFill(); //para que haga stroke - question: what size is the outline???
        ofSetColor(255, 0, 0);//rojo
        ojos[0].radio = 30;
        ojos[1].radio = 30;
        ojos[2].radio = 10;
        ojos[3].radio = 10;
        
        ojos[4].radio = 40;
        ojos[5].radio = 40;
        
        ojos[i].draw();
         
        
        ofFill(); //para que llene el circulo del centro
        ofSetColor(0, 0, 0); //negro
        ojos[0].radio = 20;
        ojos[1].radio = 20;
        ojos[2].radio = 5;
        ojos[3].radio = 5;
        
        ojos[4].radio = 30;
        ojos[5].radio = 30;
        ojos[i].draw();
        
        
        
    if(abs(ojos[i].vel.x) <= 1 && abs(ojos[i].vel.y) <=  1 ){ //tiene que ser el modulo de la velocidad.
            ofSetColor(0, 0, 0); //negro
            ojos[0].radio = 31;
         ojos[1].radio = 31;
         ojos[2].radio = 11;
         ojos[3].radio = 11;
        
        ojos[4].radio = 41;
        ojos[5].radio = 41;
            ojos[i].draw();
        }
        
	}
	
    for (int i = 0; i < springs.size(); i++){ //no dibujar para que se vean solo los ojos
//         ofSetColor(20, 25, 255);//blanco
//		springs[i].draw();
	}

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
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}

