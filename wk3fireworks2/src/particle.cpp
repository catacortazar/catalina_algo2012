#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
    ofSetCircleResolution(100);
	setInitialCondition(0,0,0,0);
	damping = 0.01f; //amortiguacion f - float number
    
    onoff = false;

}

//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame - para que no sea acumulativa - pej: la fuerza de gravedad NO va creciendo
    frc.set(0,0); 
}

    
//------------------------------------------------------------
void particle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void particle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity 
	// damping is a force operating in the oposite direction of the 
	// velocity vector
	
    frc.x = frc.x + (- vel.x * damping);
    frc.y = frc.y + (- vel.y * damping);
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
}

//------------------------------------------------------------
void particle::update(){
  
	vel = vel + frc;
	pos = pos + vel;
    onoff = true;
    if (onoff  == true) {
        
        stroke.addVertex(ofPoint(pos.x,pos.y)); //para que la linea sea continua y empezar a dibujar
        if(stroke.getVertices().size()>ofRandom(3,10)){
        stroke.getVertices().erase(stroke.getVertices().begin());
        }
    }

   
}

//------------------------------------------------------------
void particle::draw(){
    ofEnableAlphaBlending();
    ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
    ofCircle(pos.x, pos.y, ofRandom(0.5, 3.0));
    ofSetLineWidth(3); //set the width of the line
    stroke.draw();


}


//------------------------------------------------------------

