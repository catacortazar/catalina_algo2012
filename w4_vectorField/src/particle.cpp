#include "particle.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
    ofSetColor(0, 0, 0);
	damping = 1.0f;  //0.07f; //friccion que va aumentando con el paso de los f = frames - hasta que se detiene
}

//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame // las fuerzas NO se suman - por ejemplo gravedad tiene siempre el mismo valor
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
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
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
}

//------------------------------------------------------------
void particle::draw(){
    ofCircle(pos.x, pos.y, 3); //mi particula
}


//------------------------------------------------------------
void particle::bounceOffWalls(){ //para que se siga moviendo off walls
	
	// sometimes it makes sense to damped, when we hit - control or restrain
	bool bDampedOnCollision = true; 
	bool bDidICollide = false; // the particle hits the border of the canvas
	
	// what are the walls
	float minx = 0;
	float miny = 0;
	float maxx = ofGetWidth();
	float maxy = ofGetHeight();
	
	if (pos.x > maxx){
		pos.x = maxx; // move to the edge, (important!)
		vel.x *= -1; //al multimplicar por -1 no deberia devolverse?
		bDidICollide = true;
	} else if (pos.x < minx){
		pos.x = minx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	}
	
	if (pos.y > maxy){
		pos.y = maxy; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	} else if (pos.y < miny){
		pos.y = miny; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	}
	
	if (bDidICollide == true && bDampedOnCollision == true){
		vel *= 0.3;
	}
	
}

