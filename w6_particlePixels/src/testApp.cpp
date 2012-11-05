#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
    particleSize = 10;
    
    for (int i=0; i<=ofGetWidth(); i=i+particleSize-1){
        for (int j = 0; j<=ofGetHeight(); j=j+particleSize) {
            particle myParticle;
            myParticle.setInitialCondition(i,j,0,0);
            particles.push_back(myParticle);
        }
    }

    
    //set color
    
    changeColor = false;
    
    
    //set up counter y boolean para guardar la imagen
    
    snapCounter = 0;
    bSnapshot = false;
    
    //set up timer
    
    startTime = ofGetElapsedTimeMillis(); //gets start time



	
    
  	
}

//--------------------------------------------------------------
void testApp::update(){

    for (int i=0; i<=ofGetWidth(); i=i+particleSize-1){
        for (int j = 0; j<=ofGetHeight(); j=j+particleSize) {
            particle myParticle;
            myParticle.setInitialCondition(i,j,0,0);
            particles.push_back(myParticle);
        }
    }
    
    
    

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();

 for (int i=0; i<=ofGetWidth(); i=i+particleSize-1){
         for (int j = 0; j<= ofGetHeight(); j=j+particleSize) {
             
             particles[i,j].pos.x=i;
             particles[i,j].pos.y=j;
        
             ofPoint diff = ofPoint(mouseX, mouseY) - particles[i,j].pos; //ver la posicion del mouse en relacion a mi particle
             
             //cout << ofPoint(mouseX, mouseY) << endl;
             
             if (diff.length() < 10 && changeColor ==true){
            
             ofSetColor(0,0,0, 255);
              
        
                

                
             }
                else if (diff.length() > 10){
                     
                      ofSetColor(255,255,255, 255);
                     
                     
                 }
              
             particles[i,j].draw();
           
             //  particle myParticles;
             //particles.push_back(myParticles);
                // cout << particles[i,j].pos.x << endl;
                // cout << particles[i,j].pos.y << endl;

        }
        
      }
    
    
    
    
    
    //if snapsot == true - record the screen
    
    if(bSnapshot == true){
    
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        string fileName = "snapshot_"+ofToString(10000+snapCounter)+".png";
        img.saveImage(fileName);
        sprintf(snapString, "saved %s", fileName.c_str());
        snapCounter ++;
        bSnapshot = false;
                
    }
    
    
    //timer y guarda la foto
    
    int timer = ofGetElapsedTimeMillis() - startTime;
    
    if (timer%20==0){
    
        
        bSnapshot = true;
    
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

    changeColor = true; //turn black
  
   

    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    changeColor = true; //turn black
    
 

}

//--------------------------------------------------------------
void testApp::mouseReleased(){
    
    changeColor = false; //vuelve a la normalidad - blanco

}
