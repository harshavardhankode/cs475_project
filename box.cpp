#include "defs.h"
extern int lbox,lid,lift,cube;
extern int lid_angle;
extern int wood_tex,tiles_tex;

void compile_box(){
	//box
	lbox = glGenLists(1);
	glNewList(lbox,GL_COMPILE); 
		//base
			glPushMatrix();
				glTranslatef(0,0,0.5);
				glScalef(2,0.02,1);
				glCallList(cube);
			glPopMatrix();	
		//back
			glPushMatrix();
				glTranslatef(0.0,0.5,0.0);
				glScalef(2,1,0.02);
				glCallList(cube);
			glPopMatrix();		
		//left
			glPushMatrix();
				glTranslatef(-1.0,0.5,0.5);
				glScalef(0.02,1,1);
				glCallList(cube);
			glPopMatrix();	
		//right
			glPushMatrix();
				glTranslatef(1.0,0.5,0.5);
				glScalef(0.02,1,1);
				glCallList(cube);
			glPopMatrix();	
		//front
			glPushMatrix();
				glTranslatef(0.0,0.5,1.0);
				glScalef(2,1,0.02);
				glCallList(cube);
			glPopMatrix();		
	glEndList();

	//lid
	lid = glGenLists(1);
	glNewList(lid,GL_COMPILE); 
		//lid top
		glBegin(GL_QUADS);
			//glColor3f(0.6,0.6,0.0);
			glTexCoord2d(0.0,0.0); glVertex3f(-1.0,0.1,0.0);
			glTexCoord2d(1.0,0.0); glVertex3f(-1.0,0.1,1.0);
			glTexCoord2d(1.0,1.0); glVertex3f(1.0,0.1,1.0);
			glTexCoord2d(0.0,1.0); glVertex3f(1.0,0.1,0.0);
		glEnd();
		//glDisable(GL_TEXTURE_2D);
		//thickness
		glBegin(GL_QUAD_STRIP);
			//glColor3f(0.5,0.5,0.3);
			glVertex3f(-1.0,0.1,0.0);
			glVertex3f(-1.0,0.0,0.0);
			glVertex3f(-1.0,0.1,1.0);
			glVertex3f(-1.0,0.0,1.0);
			glVertex3f(1.0,0.1,1.0);
			glVertex3f(1.0,0.0,1.0);
			glVertex3f(1.0,0.1,0.0);
			glVertex3f(1.0,0.0,0.0);
			glVertex3f(-1.0,0.1,0.0);
			glVertex3f(-1.0,0.0,0.0);
		glEnd();	
		//glEnable(GL_TEXTURE_2D);
		//lid bottom
		glBegin(GL_QUADS);
			//glColor3f(0.3,0.3,0.3);
			glTexCoord2d(0.0,0.0); glVertex3f(1.0,0.0,0.0);
			glTexCoord2d(1.0,0.0); glVertex3f(1.0,0.0,1.0);
			glTexCoord2d(1.0,1.0); glVertex3f(-1.0,0.0,1.0);
			glTexCoord2d(0.0,1.0); glVertex3f(-1.0,0.0,0.0);
		glEnd();

	glEndList();


	//lift
	lift = glGenLists(1);
	glNewList(lift,GL_COMPILE); 		
			glPushMatrix();
				glTranslatef(0,0,0.5);
				glScalef(2,0.02,1);
				glCallList(cube);
			glPopMatrix();
	glEndList();
}





void draw_box(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,wood_tex);
	glColor3f (1.0, 1.0, 1.0);
	glCallList(lbox);
	glPushMatrix();
		glTranslatef(0.0,1.0,0.0);
		glRotatef(-lid_angle,1,0,0);
		glCallList(lid);
	glPopMatrix();	
	glPushMatrix();
		glTranslatef(0.0,lid_angle/120.0,0.0);
		glCallList(lift);
		glPushMatrix();	
			glTranslatef(0.0,0.0,0.5);
			glScalef(0.13,0.13,0.13);
			glTranslatef(0.0,3.8,0.0);
			draw_man();
		glPopMatrix();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D,0);
	glDisable(GL_TEXTURE_2D);
}
