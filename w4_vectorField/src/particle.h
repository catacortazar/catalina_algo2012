#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle
{
    public: //para que se pueda llamar de cualquier lugar- si es private solo se puede llamar within the class
	
        ofVec2f pos; //posicion 2D
        ofVec2f vel; //velocidad 2D
        ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
			
        particle(); //constructor
		virtual ~particle(){}; //busca en la extension de la funcion y ve si hay algo re-define ahi

        void resetForce(); //clear las fuerzas every frame - no queremos sumar las fuerzas every frame - por ejemplo la fuerza de gravedadd es la misma every frame, NO la suma.
        void addForce(float x, float y); //suma las fuerzas
        void addDampingForce(); //como friccion - fuerza en el sentido opuesto hasta que se detiene
        void setInitialCondition(float px, float py, float vx, float vy); //posicion y velocidad inicial
        void update(); //updates
        void draw(); //draws
    
    
    void bounceOffWalls(); //se sale de las paredes del canvas
	
		float damping; //define el numero que queremos como friccion

    protected: //no tengo idea :( me imagino que esta relacionado con el comment de public
private: // me imagino que es lo opuesto a public - ver el comment

};

#endif // PARTICLE_H
