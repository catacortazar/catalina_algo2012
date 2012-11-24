#include "spring.h"

//---------------------------------------------------------------------
spring::spring(){
	particleA = NULL;
	particleB = NULL;
}

//---------------------------------------------------------------------
void spring::update(){
	if ((particleA == NULL) || (particleB == NULL)){
		return;
	}
//    color.x = 0.95f * color.x + 0.05 * colorTarget.x;
//    color.y = 0.95f * color.y + 0.05 * colorTarget.y;
//    color.z = 0.95f * color.z + 0.05 * colorTarget.z;
    
	ofVec2f pta = particleA->pos;
	ofVec2f ptb = particleB->pos;
	
	float theirDistance = (pta - ptb).length();
	float springForce = (springiness * (distance - theirDistance));
	ofVec2f frcToAdd = (pta-ptb).normalized() * springForce;
	
	particleA->addForce(frcToAdd.x, frcToAdd.y);
	particleB->addForce(-frcToAdd.x, -frcToAdd.y);
    
  
}


//---------------------------------------------------------------------
void spring::draw(){
	
	if ((particleA == NULL) || (particleB == NULL)){
		return;
	}
    color.x = 0.95f * color.x + 0.05 * colorTarget.x;
    color.y = 0.95f * color.y + 0.05 * colorTarget.y;
    color.z = 0.95f * color.z + 0.05 * colorTarget.z;
	
	ofLine(particleA->pos.x, particleA->pos.y, particleB->pos.x, particleB->pos.y);
}