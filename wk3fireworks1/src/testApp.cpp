#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	ofBackground(255, 255, 255);
	
	for (int i = 0; i < 50; i++){
		particle myParticle;
		myParticle.setInitialCondition(600,300,ofRandom(-10,10), ofRandom(-10,10));
		// more interesting with diversity :)
		myParticle.damping = ofRandom(0.001, 0.05);
		particles.push_back(myParticle);
	}
	
    int lastSecond = 0; //initia el ultimo segundo a cero
    
    float radius = 50;
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
            particles[i].addForce(0.0, 0.28);
            particles[i].addDampingForce(); 
            particles[i].update();
            

        
    }
    

    
  
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableAlphaBlending();
   
    
    for (int i = 0; i < particles.size(); i++){
        
        particles[i].draw();
    }
    
  
    int s = ofGetSeconds();
//    int m = ofGetMinutes();
//    int h = ofGetHours();
 
  
    
    if (s != lastSecond){
        printf("time %d \n", ofGetSeconds());
        
        lastSecond = s;
        
    }
    if (s%2==0){
              
     
            for (int i = 0; i < particles.size(); i++){
               
                           float angle = ofRandom(0.0, 360.0);
                //            positionx = ofRandom(0, ofGetWidth());
                //            positiony = ofRandom(0, ofGetHeight());

    particles[i].setInitialCondition(100,100,(i * cos(angle)),(i * -sin(angle))); // to start as circle;
 //particles[i].setInitialCondition(positionx,positiony,(i * cos(angle)),(i * -sin(angle))); // to start as circle;
    }
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
