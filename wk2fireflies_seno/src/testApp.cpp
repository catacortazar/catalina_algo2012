#include "testApp.h"
#include "ofMain.h"



//--------------------------------------------------------------
void testApp::setup(){
	
    // macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that:
	
	ofSetVerticalSync(true);
	
	// set background:
    ofBackground(0,0,0);
	
	ofSetCircleResolution(100); //number of points used to draw the cicle - fine circle v/s 10 rough cirlce
    ofEnableSmoothing();
    
    //fixed frame rate
    ofSetFrameRate(30);
    
    // posicion inicial
    for ( int i=0; i < 30; i ++){
        myCircle[i].x = ofRandom(ofGetWindowWidth());
        myCircle[i].y = ofRandom(ofGetWindowHeight());

    
    myCircle[i].xSpeed = i + 10;
    myCircle[i].ySpeed = i + 10;
        }
}


//--------------------------------------------------------------
void testApp::update(){
     
    
    for ( int i=0; i < 30; i ++){
        if(i<5){
            float sinOfTime = sin(ofGetElapsedTimef() * (0.3)); //for the speed of on/off
            float sinOfTimeMapped = ofMap(sinOfTime, -1, 1, 0, 255);
            ofEnableAlphaBlending(); //para cambiar la transparencia
            myCircle[i].color = (255, 250, 205, sinOfTimeMapped); //initial color amarillo un poco
                
            
        if(sinOfTimeMapped <= 50){
            myCircle[i].x = ofRandom(ofGetWindowWidth());
            myCircle[i].y = ofRandom(ofGetWindowHeight());
        }
                
        else{
//            
//            myCircle[i].y --;
//            myCircle[i].x ++;
            
            }
            
            
            
            
            
            
            
            
       if(myCircle[i].x > ofGetWindowWidth() ||   myCircle[i].x < 0) {
                 myCircle[i].x = ofRandom(ofGetWindowWidth());
            }
            
       if(  myCircle[i].y > ofGetWindowHeight() ||   myCircle[i].y < 0) {
                myCircle[i].y = ofRandom(ofGetWindowHeight());
            }
        }
        
        
        else {
            float sinOfTime = sin( ofGetElapsedTimef() * (i/3)); //sino es muy rapido el cambio
            float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 0, 255);
            ofEnableAlphaBlending(); //para cambiar la transparencia
            myCircle[i].color = (255, 250, 205, sinOfTimeMapped); //initial color amarillo un poco
        
            if(sinOfTimeMapped == 0){
                myCircle[i].x = ofRandom(ofGetWindowWidth());
                myCircle[i].y = ofRandom(ofGetWindowHeight());
                }
            else{
//                myCircle[i].y --;
//                myCircle[i].x ++;
                
                }
            if( myCircle[i].x > ofGetWindowWidth() ||   myCircle[i].x < 0) {
                myCircle[i].x = ofRandom(ofGetWindowWidth());
                }
            
            if( myCircle[i].y > ofGetWindowHeight() ||   myCircle[i].y < 0) {
                myCircle[i].y = ofRandom(ofGetWindowHeight());
                }
        }
    }
    
    
    
    

    
}

//--------------------------------------------------------------
void testApp::draw(){
	
	for ( int i=0; i < 30; i ++){
	myCircle[i].draw();
    }
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

