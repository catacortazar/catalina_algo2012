#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofBackground(30,30,30);
	
	
	// set the "a" and "b" positions of the rectangle...
	
	myRectangle.posa.x = 10;
	myRectangle.posa.y = 100;
	myRectangle.posb.x = 500;
	myRectangle.posb.y = 100;
	myRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 0;							// a variable we can alter...
    counter = 0;
} 

//--------------------------------------------------------------
void testApp::update(){
	
	// to see pct in the console
	//printf("%f \n", pct)
	 
	pct += 0.007f;							// increase by a certain amount
	if (pct > 1) {
		pct = 0;							// just between 0 and 1 (0% and 100%)
	}	
	myRectangle.interpolateByPct(pct);		// go between pta and ptb

}

//--------------------------------------------------------------
void testApp::draw(){
	myRectangle.draw();
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
    
    //counter = counter ++; DOUBT: if i use one = it doesn't work! 
    
    counter ++;// double = is testing equality
    
    //  counter = counter + 1;
    //  counter <----- counter + 1;
    
   
    if (counter%2==0){              //if the reminder is 0 change posa and use a fix posb
        myRectangle.posb.x = mouseX;
        myRectangle.posb.y = mouseY;
     
        
    }
       
       else {                   //if the number is impar - change posb and use a fix posa
          
           myRectangle.posa.x = mouseX;
           myRectangle.posa.y = mouseY;
      
       }
    	
    pct = 0;
    }
//--------------------------------------------------------------
void testApp::mouseReleased(){
}
