#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    onoff = false;
    ofBackground(0,0,0);
    ofSetCircleResolution(100);
 
}
//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

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
        
        float angle = atan2(diff.y, diff.x);
        
        angle += PI/2;
        
        float width = 20; //diff.length();
        
        ofPoint offsetA;
        offsetA.x = ptb.x + width * cos(angle);
        offsetA.y = ptb.y + width * sin(angle);
        
        ofPoint offsetB;
        offsetB.x = ptb.x - width * cos(angle);
        offsetB.y = ptb.y - width * sin(angle);

        ofLine(offsetA, offsetB);
        
        ofCircle(offsetA, 1.7);
        ofCircle(offsetB, 1.7);
        
        
        mesh.addVertex(offsetA); // le dibuja un lado de la cuncuna

        mesh.addVertex(offsetB); // dibuja el otro lado de la cuncuna
        
        if (onoff == false){
            
            float sinOfTime = sin( ofGetElapsedTimef() * (0.7)); //for the speed of on/off
            float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 0, 255);
            
         
            ofSetColor(255,255,255,sinOfTimeMapped);
            ofFill();
            ofCircle(ptc.x, ptc.y, 4);
            mesh.draw();
            ofLine(offsetA, offsetB);
            
            
            /// ---- > lines.push_back(stroke);
              
    
        }
        
        
        if (onoff == true){
         
            // instead of adding every stroke, only add a stroke if it's a certain distance from the last point;
//            ofPoint prevPt = stroke.getVertices()[stroke.getVertices().size()-1];
//            float distance = (prevPt - ofPoint(mouseX, mouseY)).length();
//            if (distance > 10){
//                stroke.addVertex(mouseX, mouseY);
//            }
//            if(stroke.getVertices().size()>30){
//                
//                stroke.getVertices().erase(stroke.getVertices().begin());
//            }
            ofSetColor(255, 255, 255);
            ofFill();
            ofCircle( mouseX, mouseY, 4);
            
        }
    }
    

    
    for (int i = 0; i < lines.size(); i++){
        mesh.clear();
        vector < ofPoint > pts = lines[i].getVertices();
        for (int j = 0; j < pts.size(); j++){
            
            int j_m_1 = MAX(j-1,0);
            int j_p_1 = MIN(j+1, pts.size()-1);
            
            ofPoint pta = pts[j_m_1];
            ofPoint ptb = pts[j];
            ofPoint ptc = pts[j_p_1];
            
            ofPoint diff = ptc - pta;
            
            float angle = atan2(diff.y, diff.x);
            
            angle += PI/2;
            
            float width = 20; //diff.length();
            
            ofPoint offsetA;
            offsetA.x = ptb.x + width * cos(angle);
            offsetA.y = ptb.y + width * sin(angle);
            
            ofPoint offsetB;
            offsetB.x = ptb.x - width * cos(angle);
            offsetB.y = ptb.y - width * sin(angle);
            
            ofLine(offsetA, offsetB);
            
            ofCircle(offsetA, 1.7);
            ofCircle(offsetB, 1.7);
            
            
            mesh.addVertex(offsetA); // le dibuja un lado de la cuncuna
            
            mesh.addVertex(offsetB); // dibuja el otro lado de la cuncuna
            
            if (true){
                
                float sinOfTime = sin( ofGetElapsedTimef() * (0.7) + i * 0.3); //for the speed of on/off
                float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 0, 255);
                
                
                ofSetColor(255,255,255,sinOfTimeMapped);
                ofFill();
                ofCircle(ptc.x, ptc.y, 4);
                mesh.draw();
                ofLine(offsetA, offsetB);
                
                
                /// ---- > lines.push_back(stroke);
                
                
            }
            
            
//            if (onoff == true){
//                
//                               ofSetColor(255, 255, 255);
//                ofFill();
//                ofCircle( mouseX, mouseY, 4);
//                
//            }
        }
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
    

   onoff = true;
    
    // instead of adding every stroke, only add a stroke if it's a certain distance from the last point;
    ofPoint prevPt = stroke.getVertices()[stroke.getVertices().size()-1];
    float distance = (prevPt - ofPoint(mouseX, mouseY)).length();
    if (distance > 10){
        stroke.addVertex(mouseX, mouseY);
    }
    if(stroke.getVertices().size()>30){

        stroke.getVertices().erase(stroke.getVertices().begin());
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}