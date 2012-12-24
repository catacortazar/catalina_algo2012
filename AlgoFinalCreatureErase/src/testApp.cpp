#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);
    
    serial.listDevices();
    
    serial.setup(5, 115200);

    //ofSetFrameRate(5);
    
//    int 			readBytes(unsigned char * buffer, int length);
//    int 			writeBytes(unsigned char * buffer, int length);
//    bool			writeByte(unsigned char singleByte);
//    int             readByte();  // returns -1 on no read or error...
//    void			flush(bool flushIn = true, bool flushOut = true);
//    int				available();
    
//mi creature
    
     onoff = false;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
	
        
    
    //----------------------------------- start draw for LEDS
    
    
//    ofBackground( (int)( ofGetElapsedTimef() * 100 ) % 255);
//        
//    float sinOfTime = sin( ofGetElapsedTimef() * 10 );
//    float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 0 ,30);
//    ofSetColor( 127 + 127 * sin(ofGetElapsedTimef()));
//    ofCircle(mouseX, ofGetHeight() * .5, sinOfTimeMapped * 10.0);
    
    
    
    
    //----------------mi creature
    
    
    ofEnableAlphaBlending();  //para cambiar la transparencia
    ofSetColor(255,255,255);
    
    stroke.draw();
    
    
    
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    vector < ofPoint > pts = stroke.getVertices();
    
    for (int i = 0; i < pts.size(); i++){
        
        int i_m_1 = MAX(i-1,0);
        int i_p_1 = MIN(i+1, pts.size()-1);
        
        ofPoint pta = pts[i_m_1];
        ofPoint ptb = pts[i];
        ofPoint ptc = pts[i_p_1];
        
        ofPoint diff = ptc - pta;
        
        float angle = atan2(diff.y*cos(angle), diff.x*sin(angle));
        
        angle += PI/2;
        
        float width = 20; //diff.length();
        
        ofPoint offsetA;
        offsetA.x = ptb.x + width * cos(angle);
        offsetA.y = ptb.y + width * sin(angle);
        
        ofPoint offsetB;
        offsetB.x = ptb.x - width * cos(angle);
        offsetB.y = ptb.y - width * sin(angle);
   ofLine(offsetA, offsetB);
        
        //ofColor col;
        //col.setHsb(ofMap(angle, -PI/2, 3*PI/2, 0,255, true), 100,255, ofMap(angle, -PI/2, 3*PI/2, 0,255, true));
        //mesh.addColor(col);
        mesh.addVertex(offsetA);
        //mesh.addColor(col);
        
        mesh.addVertex(offsetB);
        
        
        

    
    // draw the mesh
    ofEnableAlphaBlending();
    //ofSetColor(255,120,0,100);
   ofFill();
    mesh.draw();
            
            if (true){
                
                float sinOfTime = sin( ofGetElapsedTimef() * (0.9) + i * 0.01); //for the speed of on/off
                float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 0, 255);
                
                
                ofSetColor(255,255,255,sinOfTimeMapped);
                //ofFill();
                ofCircle(ptc.x, ptc.y, 0);
                mesh.draw();
                ofLine(offsetA, offsetB);
                
         
                
                
            }    }
            

  
  
    


    
    
    //----------------------------------- end draw for LEDS
    
    
    ofImage imgTemp;
    imgTemp.grabScreen(0, ofGetHeight()/2, ofGetWidth(), 2);
    imgTemp.setImageType(OF_IMAGE_GRAYSCALE );
    
    imgTemp.resize(N_LIGHTS, 2);
    
    unsigned char * pixels = imgTemp.getPixels();
    
    
    
    
        
        if (ofGetFrameNum() % 3 == 0){
            serial.writeByte(255);
            for (int j = 0; j < N_LIGHTS; j++){
                
                float pct = ofMap(pixels[j], 0, 255, 0 , 1, true);
                
                
                float value = ofMap( powf(pct, 2), 0, 1, 0,253, true);
                serial.writeByte(value);
                //if (j %  (int)ofClamp(mouseX, 1, 10) == 0) serial.writeByte(254);
                //else serial.writeByte(0);
                                
            
            }
        }

ofSetColor(255);
    ofRect(0, ofGetHeight()/2, ofGetWidth(), 2);


}
     
  
 
//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 't'){
    
        
        for (int i = 0; i < lines.size(); i++){
          lines.push_back(stroke);
//        
//        stroke.clear();
      }
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

    
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    onoff = true;
    
    // instead of adding every stroke, only add a stroke if it's a certain distance from the last point;
    
    ofPoint prevPt = stroke.getVertices()[stroke.getVertices().size()-1];
    
    float distance = (prevPt - ofPoint(x,y)).length();
    
    if (distance > 10){
        stroke.addVertex(x,y);
    }

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    onoff = true;
    
    stroke.clear();
    
    stroke.addVertex(x,y);

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    onoff = false;
    lines.push_back(stroke);

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

