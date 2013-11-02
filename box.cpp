#include "defs.h"
extern int lbox;
extern int lid;
extern int lid_angle;
extern int wood_tex,tiles_tex;

void compile_box(){
	//box
	lbox = glGenLists(1);
	glNewList(lbox,GL_COMPILE); 
		//base
		glBegin(GL_QUADS);
			glNormal3f(0.0, -1.0, 0.0);
			glTexCoord2d(0.0,0.0); glVertex3f(1.0,0.0,0.0);
			glTexCoord2d(1.0,0.0); glVertex3f(1.0,0.0,1.0);
			glTexCoord2d(1.0,1.0); glVertex3f(-1.0,0.0,1.0);
			glTexCoord2d(0.0,1.0); glVertex3f(-1.0,0.0,0.0);

		//back

			glNormal3f(0.0, 0.0, -1.0);
			glTexCoord2d(0.0,0.0); glVertex3f(-1.0,1.0,0.0);
			glTexCoord2d(1.0,0.0); glVertex3f(1.0,1.0,0.0);
			glTexCoord2d(1.0,1.0); glVertex3f(1.0,0.0,0.0);
			glTexCoord2d(0.0,1.0); glVertex3f(-1.0,0.0,0.0);	

		//left

			glNormal3f(-1.0, 0.0, 0.0);
			glTexCoord2d(0.0,0.0); glVertex3f(-1.0,1.0,1.0);
			glTexCoord2d(1.0,0.0); glVertex3f(-1.0,1.0,0.0);
			glTexCoord2d(1.0,1.0); glVertex3f(-1.0,0.0,0.0);
			glTexCoord2d(0.0,1.0); glVertex3f(-1.0,0.0,1.0);

		//right

			glNormal3f(1.0, 0.0, 0.0);
			glTexCoord2d(0.0,0.0); glVertex3f(1.0,0.0,1.0);
			glTexCoord2d(1.0,0.0); glVertex3f(1.0,0.0,0.0);
			glTexCoord2d(1.0,1.0); glVertex3f(1.0,1.0,0.0);
			glTexCoord2d(0.0,1.0); glVertex3f(1.0,1.0,1.0);

		//front

			glNormal3f(0.0, 0.0, 1.0);
			glTexCoord2d(0.0,0.0); glVertex3f(-1.0,0.0,1.0);
			glTexCoord2d(1.0,0.0); glVertex3f(1.0,0.0,1.0);
			glTexCoord2d(1.0,1.0); glVertex3f(1.0,1.0,1.0);
			glTexCoord2d(0.0,1.0); glVertex3f(-1.0,1.0,1.0);
		glEnd();
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
	glBindTexture(GL_TEXTURE_2D,0);
	glDisable(GL_TEXTURE_2D);
}
