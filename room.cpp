#include "defs.h"

extern int cube,room,door,table_top,table_leg,chair_back, arm_rest ,back_frame, side_frame, book_shelf,lamp_post, lamp_base , mirror_frame;
extern int wood_tex,tiles_tex,stone_tex,door_tex;
extern int door_angle;
extern int mode;



void compile_room(){
	room = glGenLists(1);
	glNewList(room,GL_COMPILE); 
			
		//top
			glPushMatrix();
				glTranslatef(0,0.5,0);
				glScalef(1,0.02,1);
				glCallList(cube);
			glPopMatrix();	
			
		//base
			glPushMatrix();
				glTranslatef(0,-0.5,0);
				glScalef(1,0.02,1);
				glCallList(cube);
			glPopMatrix();	
		//back
			glPushMatrix();
				glTranslatef(0,0,-0.5);
				glScalef(1,1,0.02);
				glCallList(cube);
			glPopMatrix();	
		//left
			glPushMatrix();
				glTranslatef(-0.5,0,0);
				glScalef(0.02,1,1);
				glCallList(cube);
			glPopMatrix();	
		//right
			glPushMatrix();
				glTranslatef(0.5,0,0);
				glScalef(0.02,1,1);
				glCallList(cube);
			glPopMatrix();	
			if(mode != 1){	
				//front left

				glPushMatrix();
					glTranslatef(-0.3,0,0.5);
					glScalef(0.4,1,0.02);
					glCallList(cube);
				glPopMatrix();


				//front right
				glPushMatrix();
					glTranslatef(0.3,0,0.5);
					glScalef(0.4,1,0.02);
					glCallList(cube);
				glPopMatrix();
				//front mid 
				glPushMatrix();
						glTranslatef(0.0,0.25,0.5);
						glScalef(0.2,0.5,0.02);
						glCallList(cube);
				glPopMatrix();
			}

	glEndList();

	door = glGenLists(1);
	glNewList(door,GL_COMPILE);
		glPushMatrix();
				glTranslatef(0.1,0.25,0.01);
				glScalef(0.2,0.5,0.02);
				glCallList(cube);
		glPopMatrix();
	glEndList();


	table_top = glGenLists(1);
	glNewList(table_top, GL_COMPILE);
		glPushMatrix();
			glScalef(1.0, 0.1, 1.0);
			glCallList(cube);
		glPopMatrix();
	glEndList();
	
	table_leg = glGenLists(1);
	glNewList(table_leg, GL_COMPILE);
		glPushMatrix();
			glScalef(0.1, 0.6, 0.1);
			glCallList(cube);
		glPopMatrix();
	glEndList();

	chair_back = glGenLists(1);
	glNewList(chair_back, GL_COMPILE);
			glPushMatrix();
				glScalef(1.0, 1.0, 0.1);
				glCallList(cube);
			glPopMatrix();
	glEndList();
	
	arm_rest = glGenLists(1);
	glNewList(arm_rest, GL_COMPILE);
		glPushMatrix();
				glScalef(0.1, 0.1, 0.8);
				glCallList(cube);
		glPopMatrix();
	glEndList();	

	
	back_frame = glGenLists(1);
	glNewList(back_frame, GL_COMPILE);
		glPushMatrix();
			glScalef(1.0, 2.0, 0.1);
			glCallList(cube);
		glPopMatrix();
	glEndList();
		
	side_frame = glGenLists(1);
	glNewList(side_frame, GL_COMPILE);
		glPushMatrix();
			glScalef(0.1, 2.0, 0.5);
			glCallList(cube);
		glPopMatrix();
	glEndList();
	
	book_shelf = glGenLists(1);
	glNewList(book_shelf, GL_COMPILE);
		glPushMatrix();
			glScalef(1.1, 0.1, 0.5);
			glCallList(cube);
		glPopMatrix();
	glEndList();

	lamp_base = glGenLists(1);
	glNewList(lamp_base, GL_COMPILE);
		glPushMatrix();
			glScalef(0.5, 0.05, 0.5);
			glCallList(cube);
		glPopMatrix();
	glEndList();
	
	lamp_post = glGenLists(1);
	glNewList(lamp_post, GL_COMPILE);
		glPushMatrix();
			glScalef(0.05, 1.0, 0.05);
			glCallList(cube);
		glPopMatrix();
	glEndList();

	mirror_frame = glGenLists(1);
	glNewList(mirror_frame, GL_COMPILE);
		glPushMatrix();
			glPushMatrix();
				glTranslatef(0,0.5,0);
				glScalef(0.05, 1.0, 0.05);
				glCallList(cube);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(1,0.5,0);
				glScalef(0.05, 1.0, 0.05);
				glCallList(cube);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.5,0,0);
				glScalef(1.0, 0.05,0.05 );
				glCallList(cube);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.5,1,0);
				glScalef(1.0, 0.05, 0.05);
				glCallList(cube);
			glPopMatrix();
		glPopMatrix();
	glEndList();
}

void draw_room(){
	
	
	glPushMatrix();
		//glTranslatef(5,3,3);
		glScalef(14,6,10);		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,stone_tex);
		glCallList(room);


		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D,door_tex);
			glTranslatef(-0.1,-0.5 ,0.5 );
			glRotatef(-door_angle,0,1,0);
			if(mode != 1)
				glCallList(door);
		glPopMatrix();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D,wood_tex);
	
	glPushMatrix();				//Table
		glTranslatef(-7,-3,-5);
		glScalef(3,3,3);
		glTranslatef(0.5,0.65,0.5);
		glCallList(table_top);	

		glPushMatrix();
			glTranslatef(-0.4, -0.35, -0.4);	//L1
			glCallList(table_leg);
		glPopMatrix();
	
		glPushMatrix();
			glTranslatef(0.4, -0.35, -0.4); 	//L2
			glCallList(table_leg);
		glPopMatrix();
	
		glPushMatrix();
			glTranslatef(0.4, -0.35, 0.4);	//L3
			glCallList(table_leg);
		glPopMatrix();
	
		glPushMatrix();
			glTranslatef(-0.4, -0.35, 0.4);	//L4
			glCallList(table_leg);
		glPopMatrix();	
	glPopMatrix();

	glPushMatrix();		// Chair
		glTranslatef(-3,-3,-5);
		glScalef(1.5,1.5,1.5);
		glTranslatef(0.5,0.65,0.5);

		glCallList(table_top);		// Chair top
		
		glPushMatrix();
			glTranslatef(-0.4, -0.35, -0.4);	//L1
			glCallList(table_leg);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(0.4, -0.35, -0.4); 	//L2
			glCallList(table_leg);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(0.4, -0.35, 0.4);	//L3
			glCallList(table_leg);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-0.4, -0.35, 0.4);	//L4
			glCallList(table_leg);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(0, 0.5, -0.45);	// Chair back
			glCallList(chair_back);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-0.45, 0.3, -0.1); 	//A1
			glCallList(arm_rest);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(0.45, 0.3, -0.1); 	//A2
			glCallList(arm_rest);
		glPopMatrix();
	glPopMatrix();


	glPushMatrix();				//Book Shelf
		glTranslatef(7,-3,-2);
		glRotatef(-90 ,0,1,0);
		glScalef(4,2,2);
		glPushMatrix();
			glTranslatef(0.5, 1.0, 0.05);
			glCallList(back_frame);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.05, 1.0, 0.25);
			glCallList(side_frame);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.05, 1.0, 0.25);
			glCallList(side_frame);
		glPopMatrix();
	
		glPushMatrix();
			glTranslatef(0.55, 0.05, 0.25);
			glCallList(book_shelf);
		glPopMatrix();
	
		glPushMatrix();
			glTranslatef(0.55, 0.55, 0.25);
			glCallList(book_shelf);
		glPopMatrix();
	
		glPushMatrix();
			glTranslatef(0.55, 1.05, 0.25);
			glCallList(book_shelf);
		glPopMatrix();
	
		glPushMatrix();
			glTranslatef(0.55, 1.55, 0.25);
			glCallList(book_shelf);
		glPopMatrix();
	
		glPushMatrix();
			glTranslatef(0.55, 2.05, 0.25);
			glCallList(book_shelf);
		glPopMatrix();
	glPopMatrix();	

	glPushMatrix(); //	Lamp
		glTranslatef(0,-3,-5);	
		glScalef(3,3,3);
		GLUquadric* qobj;
		qobj = gluNewQuadric();
		GLUquadric* qobj2;
		qobj2 = gluNewQuadric();	

		glColor3f(1.0,1.0,0.0);
		glPushMatrix();	
			glTranslatef(0.25, 0.025, 0.25);
			glCallList(lamp_base);
		glPopMatrix();
	
		glPushMatrix();
			glTranslatef(0.25, 0.5, 0.25);
			glCallList(lamp_post);
		glPopMatrix();
		
		glBindTexture(GL_TEXTURE_2D,0);
		glDisable( GL_TEXTURE_2D );
	
		glPushMatrix();
			glTranslatef(0.25, 0.5, 0.25);
			glRotatef(-90, 1.0, 0.0, 0.0);		
		  	gluCylinder(qobj, 0.4, 0.2, 0.5, 100, 16);	  		
		glPopMatrix();
	
		glPushMatrix();		
			glTranslatef(0.25, 1.0, 0.25);
			glRotatef(-90, 1.0, 0.0, 0.0);		
		  	gluDisk(qobj2, 0.0, 0.2, 100, 16);	
		glPopMatrix();

	glPopMatrix();

	if (mode != 1){
		glPushMatrix(); 	//Mirror frame
			glBindTexture(GL_TEXTURE_2D,wood_tex);
			glEnable( GL_TEXTURE_2D );
			glTranslatef(-5.0,-2.0,4.6);
			glScalef(2.0,4.0,1.0);
			glCallList(mirror_frame);
		glPopMatrix();
	}

	glBindTexture(GL_TEXTURE_2D,0);
	glDisable(GL_TEXTURE_2D);
}
