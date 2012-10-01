#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that:
	
	ofSetVerticalSync(true);
    ofSetCircleResolution(100); //number of points used to draw the cicle - fine circle v/s 10 rough cirlce
    ofEnableSmoothing();
	
    myMusic.loadSound("sounds/water.mp3"); //uploads mi cancion
    
    counter = 0; // to change on/off when mouse pressed
    
    angulo = 0;
    onoff = false;
   
   
    
}

//--------------------------------------------------------------
void testApp::update(){

	ofBackground(255,255,255);
	// update the sound playing system:
	ofSoundUpdate();
  
}

//--------------------------------------------------------------
void testApp::draw(){
    
 
    if (onoff == true) {
//       
        myMusic.play();
//        
        angulo = (ofGetElapsedTimef()/PI);
//    
        if(angulo%2==0){
                float cosOfTime = cos(ofGetElapsedTimef() * (1)); //for the speed of on/off
                float cosOfTimeMapped = ofMap( cosOfTime, -1, 1, 0, 255);
                ofEnableAlphaBlending(); //para cambiar la transparencia
                ofSetColor(0,0,0,255);
                ofCircle(ofGetWidth()/2, ofGetHeight()/2,  cosOfTimeMapped);
           }
        else  {
    
                float cosOfTime = cos(ofGetElapsedTimef() * (1)); //for the speed of on/off
                float cosOfTimeMapped = ofMap( cosOfTime, -1, 1, 0, 255);
                ofEnableAlphaBlending(); //para cambiar la transparencia
                ofSetColor(0,0,0,255);
                ofCircle(ofGetWidth()/2, ofGetHeight()/2,  cosOfTimeMapped);
                ofSetColor(255,255,255,cosOfTimeMapped);
                ofCircle(ofGetWidth()/2, ofGetHeight()/2,  (cosOfTimeMapped/2));
      }
//       
  }

     
     if (onoff == false){
         myMusic.stop();
     }

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){


}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
 
   counter = counter ++;
	
    if (counter%2 == 0){       //if the reminder is 0 play music
  
        onoff = true;
    }
    else {                   //if the number is impar stop playing
        
        onoff = false;
   }
  

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
