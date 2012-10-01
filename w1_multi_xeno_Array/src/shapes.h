

#include "ofMain.h"

class shapes {

	public:
	
        shapes();
	
		void drawRectangle();
    void drawCircle();
		    
   	// take this pct of where I want to be, and 1-catchUpSpeed of my pos
		
		ofPoint		pos;
    float size;
		
   	float a;
    float r;
    float g;
    float b;
};

