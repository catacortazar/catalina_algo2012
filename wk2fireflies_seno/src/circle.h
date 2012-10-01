#ifndef circle_h    //compiler only compile this files once 
#define circle_h

#include "ofMain.h" //access to methods and objects from OF

class circle {

	public:
    

//Constructor
    circle();
	
    
//Method
    void draw();
 
    
//Properties
       
    int x;
    int y;
    ofColor color;
    float xSpeed;
    float ySpeed;

    
    
};

#endif // CIRCLE_H
