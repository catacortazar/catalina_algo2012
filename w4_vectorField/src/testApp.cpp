#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    ofBackground(250, 11, 218); 

	VF.setupField(VF.fieldWidth, VF.fieldHeight,ofGetWidth(), ofGetHeight()); //internal dimensions of //the filed - declared in vectorField files - external dimensions of hte field
	//VF.randomizeField(6.5); //funcion que determina el largo de la "flecha" - random field de fuerzas para comenzar
    
    
    for (int i=0; i < 1000; i++){ //100 numero de particles, y la posicion random en el canvas y la
 
        particle myParticle;
      
        myParticle.setInitialCondition(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()), 0, 0);
        particles.push_back(myParticle);
    }
    
    bFade = false;
}

//--------------------------------------------------------------
void testApp::update(){

    
    for(int i=0; i < particles.size(); i++){
    
        particles[i].resetForce(); //a cada particle de mi vector le vamos a reset forces
        
        ofVec2f frc; 
        
        frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y); //vector field get forces from position
    
        particles[i].addForce(frc.x, frc.y);
        particles[i].addDampingForce();
       
        
        ofEnableAlphaBlending();
        float transparency = ofMap((particles[i].frc.y)*100, -100, 100, 0, 255); //map el transparency de acuerdo a una fuerza ????
        
        
        ofSetColor(0, 0, 0, transparency);
         particles[i].update();
        
    }
    
    
    
    
    if (bFade ==true){
        
        VF.fadeField(0.99f); //la velocidad en que aparece y desaparece - si es 0.79 no alcanza a crecer y ya desaparecio, si es 1.29 esta siempre porque aparece muy rapido.
        
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();
   //VF.draw(); //dibuja las lineas y las perpendiculares
	
    
    
    for (int i=0; i < particles.size(); i++) {
        
        if(particles[i].vel.x != 0  && particles[i].vel.y != 0){ //if they are changing their speed - influenced by the vector field.
            ofSetColor(0,0, 0); //para que no se vean las particulas al inicio
            //   ofSetColor(250, 11, 218);
            particles[i].draw();
        }
    }
		ofDisableAlphaBlending();
    
  
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
    
    float diffx = x - prevMouseX;
    float diffy = y - prevMouseY;
     
    
    	VF.addVectorCircle((float)x, (float)y, diffx*0.3, diffy*0.3, 20, 0.9f); //las hecha en la direccion del VF.
    
      //VF.addClockwiseCircle((float)x, (float)y, 60, 0.7f);
//VF.addCounterClockwiseCircle((float)x, (float)y, 40, 0.3f);
 VF.addInwardCircle((float)x, (float)y, 20, 0.9f);
       // VF.addOutwardCircle((float)x, (float)y, 160, 0.7f);
//    
    
    
    
    
    //	if (button == 0){ //cuando el button esta DOWN - o sea 0
//		VF.addOutwardCircle(x,y, 100, 0.3) ;
//	} else {
//		VF.addCounterClockwiseCircle(x, y, 200, 0.3);
//	}
//    
    prevMouseX = x;
	prevMouseY = y;
    
 

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    prevMouseX = x;
    prevMouseY = y;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
