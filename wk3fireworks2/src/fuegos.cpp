#include "particle.h"
#include "fuegos.h"
#include "ofMain.h"


//------------------------------------------------------------
fuegos::fuegos(){
    
    ofSetCircleResolution(100);
	    onoff = false;
    
    int lastSecond = 0; //initia el ultimo segundo a cero
    
    for (int i = 0; i < 70; i++){
		particle myParticle;
		
        float angle = ofRandom(0.0, 360.0);
        myParticle.setInitialCondition(posicionx, posiciony,(i * cos(angle)),(i * -sin(angle))); // to start as circle;
        
		// more interesting with diversity :)
		myParticle.damping = ofRandom(0.001, 0.05);
		particles.push_back(myParticle);
	}
}


//------------------------------------------------------------
void fuegos::draw(){
    ofEnableAlphaBlending();
    for (int i = 0; i < particles.size(); i++){
        
        particles[i].draw();
    }
   
    
    
    int s = ofGetSeconds();
    //    int m = ofGetMinutes();
    //    int h = ofGetHours();
    
    
    
    if (s != lastSecond){
        printf("time %d \n", ofGetSeconds());  
        lastSecond = s;
        if (s%5==0){
            for (int i = 0; i < particles.size(); i++){
                float angle = ofRandom(0.0, 360.0);
                particles[i].setInitialCondition(posicionx, posiciony,(i * cos(angle)),(i * -sin(angle))); // to start as circle;
                
                particles[i].stroke.clear();
            }
        
    }

        
    }
    


}


//------------------------------------------------------------
void fuegos::update(){
for (int i = 0; i < particles.size(); i++){
    
    particles[i].resetForce();
    particles[i].addForce(0.0, 0.28);
    particles[i].addDampingForce();
    particles[i].update();
    
}
    
}