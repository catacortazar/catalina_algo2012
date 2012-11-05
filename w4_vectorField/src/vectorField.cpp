#include "vectorField.h"



//------------------------------------------------------------------------------------
vectorField::vectorField(){
	
	//inner dimensions of the field
	
	fieldWidth  = 70;
    fieldHeight = 50;
	
}

//------------------------------------------------------------------------------------
void vectorField::setupField(int innerW, int innerH, int outerW, int outerH){
	
	fieldWidth			= innerW;
	fieldHeight			= innerH;
	externalWidth		= outerW;
	externalHeight		= outerH;
	
	field.clear(); 
	
	fieldSize = fieldWidth * fieldHeight;
	for (int i = 0; i < fieldSize; i++){
		ofVec2f pt;  
		pt.set(0,0);
		field.push_back(pt);
	}
}


//------------------------------------------------------------------------------------
void vectorField::clear(){
    for (int i = 0; i < fieldSize; i++){
        field[i].set(0,0);
    }
}


//------------------------------------------------------------------------------------
void vectorField::fadeField(float fadeAmount){ //is f
	for (int i = 0; i < fieldSize; i++){
        field[i].set(field[i].x*fadeAmount,field[i].y*fadeAmount);
    }
}

//------------------------------------------------------------------------------------
void vectorField::randomizeField(float scale){ //largo del vector field inicial - o hasta donde puede llegar la "flecha"
	for (int i = 0; i < fieldSize; i++){
        // random between -1 and 1
        float x =  1*scale;    //(float)(ofRandom(-1,1)) * scale;
        float y = 1*scale;    //(float)(ofRandom(-1,1)) * scale;
        field[i].set(x,y);
    }
}

//------------------------------------------------------------------------------------
void vectorField::draw(){
	
    float scalex = (float)externalWidth / (float)fieldWidth; //duda los (float)
    float scaley = (float)externalHeight / (float)fieldHeight;
	
    for (int i = 0; i < fieldWidth; i++){
        for (int j = 0; j < fieldHeight; j++){

            // pos in array
            int pos = j * fieldWidth + i;
            // pos externally
            float px = 	i * scalex;
            float py = 	j * scaley;
            float px2 = px + field[pos].x *5; //la posicion de la punta - el factor 5 da el largo de la linea
            float py2 = py + field[pos].y * 5;
			
            ofLine(px,py, px2, py2); //linea por dos puntos en 2D
			
			
			// draw an baseline to show direction - la linea perpendicular abajo
			// get the line as vector, calculate length, then normalize. 
			// rotate and draw based on length
			
//			ofVec2f line;
//			line.set(px2-px, py2-py); //linea
//			float length = line.length(); //longitud
//			line.normalize(); //vector con magnitud = 1.0 - si se saca es gigante la perpendicular
//			line.rotate(90);  // rota con respecto a la linea original o sea queda perpendicular - these are angles in degrees
//			ofLine(px - line.x*length*1.2, py - line.y*length*1.2, px + line.x*length*1.2, py + line.y*length*1.2); //dibuja la linea perpendicular

			
        }
    }
}


//------------------------------------------------------------------------------------
ofVec2f vectorField::getForceFromPos(float xpos, float ypos){ //fuerzas dependiendo de la posicion
	
	ofVec2f frc; //frc is also know as acceleration (newton says "f=ma")
	frc.set(0,0); //frc inicial ?
	
	// convert xpos and ypos into pcts = // para ver donde me encuentro del canvas - porcentaje, empieza el mapping entre las dos - amount of flechas y size total del canvas
	float xPct = xpos / (float)externalWidth; //mi posicion en x en relacion to el wdth total - que %
	float yPct = ypos / (float)externalHeight; //mi posicion en y en relacion to el wdth total - que %
	
	// if we are less then 0 or greater then 1 in x or y, return no force.
	if ((xPct < 0 || xPct > 1) || (yPct < 0 || yPct > 1)){//el porcentaje tiene que estar entre 0 y 1
		return frc;	
	} 
	
    // where are we in the array - in the field - en el inner width
    int fieldPosX = (int)(xPct * fieldWidth); //aqui encuentra la posicion en el field mapeada desde el total del canvas. 
    int fieldPosY = (int)(yPct * fieldHeight);

    // saftey :)
    fieldPosX = MAX(0, MIN(fieldPosX, fieldWidth-1));
    fieldPosY = MAX(0, MIN(fieldPosY, fieldHeight-1));

    // va determninando la posicion en el field - in array - llenando columna por columna)
    int pos = fieldPosY * fieldWidth + fieldPosX; 
	
	frc.set(field[pos].x * 0.1, field[pos].y * 0.1 );  // scale here as values are pretty large.
	return frc;
}

//------------------------------------------------------------------------------------
void vectorField::addInwardCircle(float x, float y, float radius, float strength){ //posicion del centro del circulo?, radio, fuerza
	
    // x y and radius are in external dimensions.  Let's put them into internal dimensions:
	// first convert to pct:
	
	float pctx			= x / (float)externalWidth; //el mismo mapping que antes
	float pcty			= y / (float)externalHeight;
	float radiusPct		= radius / (float)externalWidth;   //me imagino que podria ser con externalHeight tambien
	
	// then, use them here: llevandolo al internal 
    int fieldPosX		= (int)(pctx * (float)fieldWidth);
    int fieldPosY		= (int)(pcty * (float)fieldHeight);
	float fieldRadius	= (float)(radiusPct * fieldWidth);
	
	// we used to do this search through every pixel, ie: 
	//    for (int i = 0; i < fieldWidth; i++){
	//    for (int j = 0; j < fieldHeight; j++){
	// but we can be smarter :)
	// now, as we search, we can reduce the "pixels" we look at by 
	// using the x y +/- radius.
	// use min and max to make sure we don't look over the edges //ver si la particula esta cerca del circulo de influencia ? - creo -
    
    //voy a chequear: en X =startx que es en el centro del circulo menos el radio y cero
    //y desde el la posicion mas el radio y el field width.
	
	int startx	= MAX(fieldPosX - fieldRadius, 0);    
	int starty	= MAX(fieldPosY - fieldRadius, 0);
	int endx	= MIN(fieldPosX + fieldRadius, fieldWidth);
	int endy	= MIN(fieldPosY + fieldRadius, fieldHeight);
	
	
    for (int i = startx; i < endx; i++){
        for (int j = starty; j < endy; j++){
			
            int pos = j * fieldWidth + i; //va viendo (o llenando) columna por columna desde (0,0) hasta (fieldWidth, fieldHeight) - la distancia para ver si le afecta la fuerza o no
            
            float distance = (float)sqrt((fieldPosX-i)*(fieldPosX-i) +
                                         (fieldPosY-j)*(fieldPosY-j)); //d^2 = x^2 + y^2
            
			if (distance < 0.0001) distance = 0.0001;  // since we divide by distance, do some checking here, devide by 0 is BADDDD
			
			if (distance < fieldRadius){ //si esta siendo afectada por la fuerza:
				
				float pct = 1.0f - (distance / fieldRadius); //pct * fieldRadius = fieldRadius - distance = pct de proximidad con el centro del circulo; del fieldRadius
				
                float strongness = strength * pct; //strength se le da en el text app... y ve que porcentaje de ese strength basado en el porcentaje del fieldRadius - cercania al centro del circulo le aplica a que particula
                float unit_px = ( fieldPosX - i) / distance; //unit_px * distance = fieldPosX - i
                float unit_py = ( fieldPosY - j) / distance;//unit_py * distance = fieldPosY - j
                
                field[pos].x += unit_px * strongness;
                field[pos].y += unit_py * strongness;
            }
        }
    }
}


//------------------------------------------------------------------------------------
void vectorField::addOutwardCircle(float x, float y, float radius, float strength){
	
	
	// x y and radius are in external dimensions.  Let's put them into internal dimensions:
	// first convert to pct:
	
	float pctx			= x / (float)externalWidth;
	float pcty			= y / (float)externalHeight;
	float radiusPct		= radius / (float)externalWidth;   
	
	// then, use them here: 
    int fieldPosX		= (int)(pctx * (float)fieldWidth);
    int fieldPosY		= (int)(pcty * (float)fieldHeight);
	float fieldRadius	= (float)(radiusPct * fieldWidth);
	
	// we used to do this search through every pixel, ie: 
	//    for (int i = 0; i < fieldWidth; i++){
	//    for (int j = 0; j < fieldHeight; j++){
	// but we can be smarter :)
	// now, as we search, we can reduce the "pixels" we look at by 
	// using the x y +/- radius.
	// use min and max to make sure we don't look over the edges 
	
	int startx	= MAX(fieldPosX - fieldRadius, 0);    
	int starty	= MAX(fieldPosY - fieldRadius, 0);
	int endx	= MIN(fieldPosX + fieldRadius, fieldWidth);
	int endy	= MIN(fieldPosY + fieldRadius, fieldHeight);

	
    for (int i = startx; i < endx; i++){
        for (int j = starty; j < endy; j++){

            int pos = j * fieldWidth + i;
            float distance = (float)sqrt((fieldPosX-i)*(fieldPosX-i) +
                                         (fieldPosY-j)*(fieldPosY-j));
            
			if (distance < 0.0001) distance = 0.0001;  // since we divide by distance, do some checking here, devide by 0 is BADDDD
			
			if (distance < fieldRadius){
               
				float pct = 1.0f - (distance / fieldRadius);
                float strongness = strength * pct;
                float unit_px = ( fieldPosX - i) / distance;
                float unit_py = ( fieldPosY - j) / distance;
				
				//printf(" overall length = %f \n", sqrt(unit_px* unit_px + unit_py* unit_py));

                field[pos].x -= unit_px * strongness;
                field[pos].y -= unit_py * strongness;
            }
        }
    }
}

//------------------------------------------------------------------------------------
void vectorField::addClockwiseCircle(float x, float y, float radius, float strength){
	
	
	
    // x y and radius are in external dimensions.  Let's put them into internal dimensions:
	// first convert to pct:
	
	float pctx			= x / (float)externalWidth;
	float pcty			= y / (float)externalHeight;
	float radiusPct		= radius / (float)externalWidth;   
	
	// then, use them here: 
    int fieldPosX		= (int)(pctx * (float)fieldWidth);
    int fieldPosY		= (int)(pcty * (float)fieldHeight);
	float fieldRadius	= (float)(radiusPct * fieldWidth);
	
	// we used to do this search through every pixel, ie: 
	//    for (int i = 0; i < fieldWidth; i++){
	//    for (int j = 0; j < fieldHeight; j++){
	// but we can be smarter :)
	// now, as we search, we can reduce the "pixels" we look at by 
	// using the x y +/- radius.
	// use min and max to make sure we don't look over the edges 
	
	int startx	= MAX(fieldPosX - fieldRadius, 0);    
	int starty	= MAX(fieldPosY - fieldRadius, 0);
	int endx	= MIN(fieldPosX + fieldRadius, fieldWidth);
	int endy	= MIN(fieldPosY + fieldRadius, fieldHeight);
	
	
    for (int i = startx; i < endx; i++){
        for (int j = starty; j < endy; j++){
			
            int pos = j * fieldWidth + i;
            float distance = (float)sqrt((fieldPosX-i)*(fieldPosX-i) +
                                         (fieldPosY-j)*(fieldPosY-j));
            
			if (distance < 0.0001) distance = 0.0001;  // since we divide by distance, do some checking here, devide by 0 is BADDDD
			
			if (distance < fieldRadius){
				
				float pct = 1.0f - (distance / fieldRadius);
				
                float strongness = strength * pct;
                float unit_px = ( fieldPosX - i) / distance;
                float unit_py = ( fieldPosY - j) / distance;
                field[pos].x += unit_py * strongness;   /// Note: px and py switched, for perpendicular
                field[pos].y -= unit_px * strongness;
            }
        }
    }
}



//------------------------------------------------------------------------------------
void vectorField::addCounterClockwiseCircle(float x, float y, float radius, float strength){
	
	
	
    // x y and radius are in external dimensions.  Let's put them into internal dimensions:
	// first convert to pct:
	
	float pctx			= x / (float)externalWidth;
	float pcty			= y / (float)externalHeight;
	float radiusPct		= radius / (float)externalWidth;   
	
	// then, use them here: 
    int fieldPosX		= (int)(pctx * (float)fieldWidth);
    int fieldPosY		= (int)(pcty * (float)fieldHeight);
	float fieldRadius	= (float)(radiusPct * fieldWidth);
	
	// we used to do this search through every pixel, ie: 
	//    for (int i = 0; i < fieldWidth; i++){
	//    for (int j = 0; j < fieldHeight; j++){
	// but we can be smarter :)
	// now, as we search, we can reduce the "pixels" we look at by 
	// using the x y +/- radius.
	// use min and max to make sure we don't look over the edges 
	
	int startx	= MAX(fieldPosX - fieldRadius, 0);    
	int starty	= MAX(fieldPosY - fieldRadius, 0);
	int endx	= MIN(fieldPosX + fieldRadius, fieldWidth);
	int endy	= MIN(fieldPosY + fieldRadius, fieldHeight);
	
	
    for (int i = startx; i < endx; i++){
        for (int j = starty; j < endy; j++){
			
            int pos = j * fieldWidth + i;
            float distance = (float)sqrt((fieldPosX-i)*(fieldPosX-i) +
                                         (fieldPosY-j)*(fieldPosY-j));
            
			if (distance < 0.0001) distance = 0.0001;  // since we divide by distance, do some checking here, devide by 0 is BADDDD
			
			if (distance < fieldRadius){
				
				float pct = 1.0f - (distance / fieldRadius);
				
                float strongness = strength * pct;
                float unit_px = ( fieldPosX - i) / distance;
                float unit_py = ( fieldPosY - j) / distance;
                field[pos].x -= unit_py * strongness;   /// Note: px and py switched, for perpendicular
                field[pos].y += unit_px * strongness;
            }
        }
    }
}


//------------------------------------------------------------------------------------
void vectorField::addVectorCircle(float x, float y, float vx, float vy, float radius, float strength){
	
	
	
	// x y and radius are in external dimensions.  Let's put them into internal dimensions:
	// first convert to pct:
	
	float pctx			= x / (float)externalWidth;
	float pcty			= y / (float)externalHeight;
	float radiusPct		= radius / (float)externalWidth;   
	
	// then, use them here: 
    int fieldPosX		= (int)(pctx * (float)fieldWidth);
    int fieldPosY		= (int)(pcty * (float)fieldHeight);
	float fieldRadius	= (float)(radiusPct * fieldWidth);
	
	// we used to do this search through every pixel, ie: 
	//    for (int i = 0; i < fieldWidth; i++){
	//    for (int j = 0; j < fieldHeight; j++){
	// but we can be smarter :)
	// now, as we search, we can reduce the "pixels" we look at by 
	// using the x y +/- radius.
	// use min and max to make sure we don't look over the edges 
	
	int startx	= MAX(fieldPosX - fieldRadius, 0);    
	int starty	= MAX(fieldPosY - fieldRadius, 0);
	int endx	= MIN(fieldPosX + fieldRadius, fieldWidth);
	int endy	= MIN(fieldPosY + fieldRadius, fieldHeight);
	
	
    for (int i = startx; i < endx; i++){
        for (int j = starty; j < endy; j++){
			
            int pos = j * fieldWidth + i;
            float distance = (float)sqrt((fieldPosX-i)*(fieldPosX-i) +
                                         (fieldPosY-j)*(fieldPosY-j));
            
			if (distance < 0.0001) distance = 0.0001;  // since we divide by distance, do some checking here, devide by 0 is BADDDD
			
			if (distance < fieldRadius){
				
				float pct = 1.0f - (distance / fieldRadius);
                float strongness = strength * pct;
                field[pos].x += vx * strongness;   
                field[pos].y += vy * strongness;
            }
        }
    }
}



//------------------------------------------------------------------------------------
vectorField::~vectorField(){

}
