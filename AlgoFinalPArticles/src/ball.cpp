//
//  ball.cpp
//  02algofinal
//
//  Created by Noa Dolberg on 12/15/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "ball.h"


//------------------------------------------------------------------
ball::ball(){

}

//------------------------------------------------------------------
void ball::draw(float posx, float posy, float radius) {
    ofSetColor(255);
    ofCircle(posx, posy, radius);
}
