#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    onoff = true;
ofBackground(0, 0, 0, 255);
    
    //old OF default is 96 - but this results in fonts looking larger than in other programs.
	ofTrueTypeFont::setGlobalDpi(72);
    
	verdana14.loadFont("verdana.ttf", 14, true, true);
	verdana14.setLineHeight(18.0f);
	verdana14.setLetterSpacing(1.037);
  

    

}

//--------------------------------------------------------------
void testApp::update(){
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(225);
    verdana14.drawString(typeStr, 30, 40);
    ofSetColor(225);
    str.draw();
    
  

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
		typeStr = typeStr.substr(0, typeStr.length()-1);
	}
	else
    {
		typeStr.append(1, (char)key);
	}
    if(key == OF_KEY_DOWN){
        onoff = !onoff;
    }
   

}


//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    if (onoff  == true) {
    
    str.addVertex(ofPoint(x,y)); //para que la linea sea continua y empezar a dibujar
}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if (onoff  == true) {
    str.addVertex(ofPoint(x,y)); //para dibujar un punto
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