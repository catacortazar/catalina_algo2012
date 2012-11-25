#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(0,0,0);
    
	 ofEnableSmoothing();
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	for (int i = 0; i < 100; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(500,550),ofRandom(500,550),0,0);
		particles.push_back(myParticle);
	}
	
	particles[0].bFixed = true;
	
	for (int i = 1; i < 100; i++){
		spring mySpring;
		mySpring.distance		= ofRandom(0,250);
		mySpring.springiness	= 0.2f;
		mySpring.particleA = & (particles[0]);
		mySpring.particleB = & (particles[i]);
		springs.push_back(mySpring);
	}
	

	 bSavePdf = false;
	
  
		
	
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
			particles[i].addRepulsionForce(particles[j], 20, 0.03);
		}
	}
	
	for (int i = 0; i < springs.size(); i++){
     
		springs[i].update();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addDampingForce();
		particles[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
    if (bSavePdf == true){
        ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".pdf", false);
        
    }

    
	for (int i = 0; i < particles.size(); i++){
        
        float hue = fmodf(ofGetElapsedTimef()*10,255); //changing color / time
        
        int step = 5;
        
        ofColor color = ofColor::fromHsb(hue,
                                         ofMap( particles[i].pos.x, 0,ofGetWidth(), 0,255),
                                         ofMap( particles[i].pos.y, ofGetHeight(),0, 0,255) );
        color.a = ofRandom(0,255);
        ofSetColor( color );
        ofFill();
        

		particles[i].draw();
	}
    
    if( bSavePdf ){
		ofEndSaveScreenAsPDF();
        bSavePdf = false;
	}
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    
    if (key == 'p'){
        
        bSavePdf = true;
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

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	//particles[0].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	
	//particles[0].bFixed = false;
}

