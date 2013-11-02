#include "defs.h"
extern int cube,t3,t2,t1,Neck,Head,Sh,UArm,Elbow,LArm,Wrist,Hand,Hip,Thigh,Knee,Leg,Ankle,Foot;
extern int body_angles[34];
extern int wood_tex,tiles_tex,face_tex;

void compile_man(){
	cube = glGenLists(1);
	glNewList(cube,GL_COMPILE); 
		
		//glTranslatef(-0.5,-0.5,-0.5);

		glBegin(GL_QUADS);
		//top
			glNormal3f(0.0, 1.0, 0.0);
			glTexCoord2d(0.0,1.0); glVertex3f(-0.5,0.5,-0.5);
			glTexCoord2d(1.0,1.0); glVertex3f(-0.5,0.5,0.5);
			glTexCoord2d(1.0,0.0); glVertex3f(0.5,0.5,0.5);
			glTexCoord2d(0.0,0.0); glVertex3f(0.5,0.5,-0.5);

		//base
			glNormal3f(0.0, -1.0, 0.0);
			glTexCoord2d(0.0,0.0); glVertex3f(0.5,-0.5,-0.5);
			glTexCoord2d(1.0,0.0); glVertex3f(0.5,-0.5,0.5);
			glTexCoord2d(1.0,1.0); glVertex3f(-0.5,-0.5,0.5);
			glTexCoord2d(0.0,1.0); glVertex3f(-0.5,-0.5,-0.5);

		//back
			glNormal3f(0.0, 0.0, -1.0);
			glTexCoord2d(0.0,0.0); glVertex3f(-0.5,0.5,-0.5);
			glTexCoord2d(1.0,0.0); glVertex3f(0.5,0.5,-0.5);
			glTexCoord2d(1.0,1.0); glVertex3f(0.5,-0.5,-0.5);
			glTexCoord2d(0.0,1.0); glVertex3f(-0.5,-0.5,-0.5);	

		//left
			glNormal3f(-1.0, 0.0, 0.0);
			glTexCoord2d(0.0,0.0); glVertex3f(-0.5,0.5,0.5);
			glTexCoord2d(1.0,0.0); glVertex3f(-0.5,0.5,-0.5);
			glTexCoord2d(1.0,1.0); glVertex3f(-0.5,-0.5,-0.5);
			glTexCoord2d(0.0,1.0); glVertex3f(-0.5,-0.5,0.5);

		//right
			glNormal3f(1.0, 0.0, 0.0);
			glTexCoord2d(0.0,0.0); glVertex3f(0.5,-0.5,0.5);
			glTexCoord2d(1.0,0.0); glVertex3f(0.5,-0.5,-0.5);
			glTexCoord2d(1.0,1.0); glVertex3f(0.5,0.5,-0.5);
			glTexCoord2d(0.0,1.0); glVertex3f(0.5,0.5,0.5);
		
		//front
			glNormal3f(0.0, 0.0, 1.0);
			glTexCoord2d(0.0,0.0); glVertex3f(-0.5,-0.5,0.5);
			glTexCoord2d(1.0,0.0); glVertex3f(0.5,-0.5,0.5);
			glTexCoord2d(1.0,1.0); glVertex3f(0.5,0.5,0.5);
			glTexCoord2d(0.0,1.0); glVertex3f(-0.5,0.5,0.5);
		glEnd();
	glEndList();
	
	t3 = glGenLists(1);
	glNewList(t3,GL_COMPILE);
		glPushMatrix();
		glScalef(1.2,1.2,0.4);
		glCallList(cube);
		glPopMatrix();
	glEndList();

	t2 = glGenLists(1);
	glNewList(t2,GL_COMPILE);		
		glPushMatrix();
		glScalef(1.4,0.4,0.6);
		glCallList(cube);
		glPopMatrix();		
	glEndList();

	t1 = glGenLists(1);
	glNewList(t1,GL_COMPILE);
		glPushMatrix();
		glScalef(1.6,1.6,0.8);
		glCallList(cube);
		glPopMatrix();
	glEndList();

	Sh = glGenLists(1);
	glNewList(Sh,GL_COMPILE);
		glPushMatrix();
		glScalef(0.3,0.3,0.3);
		glCallList(cube);
		glPopMatrix();
	glEndList();

	UArm = glGenLists(1);
	glNewList(UArm,GL_COMPILE);
		glPushMatrix();
		glScalef(0.3,1.0,0.3);
		glCallList(cube);
		glPopMatrix();
	glEndList();

	Elbow = glGenLists(1);
	glNewList(Elbow,GL_COMPILE);
		glPushMatrix();
		glScalef(0.3,0.3,0.3);
		glCallList(cube);
		glPopMatrix();
	glEndList();

	LArm = glGenLists(1);
	glNewList(LArm,GL_COMPILE);
		glPushMatrix();
		glScalef(0.3,1.0,0.3);
		glCallList(cube);
		glPopMatrix();
	glEndList();

	Wrist = glGenLists(1);
	glNewList(Wrist,GL_COMPILE);
		glPushMatrix();
		glScalef(0.3,0.3,0.3);
		glCallList(cube);
		glPopMatrix();
	glEndList();

	Hand = glGenLists(1);
	glNewList(Hand,GL_COMPILE);
		glPushMatrix();
		glScalef(0.5,0.5,0.5);
		glCallList(cube);
		glPopMatrix();
	glEndList();

	Hip = glGenLists(1);
	glNewList(Hip,GL_COMPILE);
		glPushMatrix();
		glScalef(0.3,0.3,0.3);
		glCallList(cube);
		glPopMatrix();
	glEndList();

	Thigh = glGenLists(1);
	glNewList(Thigh,GL_COMPILE);
		glPushMatrix();
		glScalef(0.3,1.0,0.3);
		glCallList(cube);
		glPopMatrix();
	glEndList();

	Knee = glGenLists(1);
	glNewList(Knee,GL_COMPILE);
		glPushMatrix();
		glScalef(0.3,0.3,0.3);
		glCallList(cube);
		glPopMatrix();
	glEndList();

	Leg = glGenLists(1);
	glNewList(Leg,GL_COMPILE);
		glPushMatrix();
		glScalef(0.3,1.0,0.3);
		glCallList(cube);
		glPopMatrix();
	glEndList();

	Ankle = glGenLists(1);
	glNewList(Ankle,GL_COMPILE);
		glPushMatrix();
		glScalef(0.3,0.3,0.3);
		glCallList(cube);
		glPopMatrix();
	glEndList();


	Foot = glGenLists(1);
	glNewList(Foot,GL_COMPILE);
		glPushMatrix();
		glScalef(0.3,0.3,0.6);
		glCallList(cube);
		glPopMatrix();
	glEndList();

	Neck = glGenLists(1);
	glNewList(Neck,GL_COMPILE);
		glPushMatrix();
		glScalef(0.3,0.3,0.3);
		glCallList(cube);
		glPopMatrix();
	glEndList();

	Head = glGenLists(1);
	glNewList(Head,GL_COMPILE);
		glPushMatrix();
		glBegin(GL_QUADS);
		//top
			glTexCoord2d(0.1+0.0/2,2.0/3);; glVertex3f(-0.5,0.5,-0.5);
			glTexCoord2d(0.1+1.0/2,2.0/3); glVertex3f(-0.5,0.5,0.5);
			glTexCoord2d(0.1+1.0/2,3.0/3); glVertex3f(0.5,0.5,0.5);
			glTexCoord2d(0.1+0.0/2,3.0/3); glVertex3f(0.5,0.5,-0.5);

		//base

			glTexCoord2d(0.1+1.0/2,0.0/3); glVertex3f(0.5,-0.5,-0.5);
			glTexCoord2d(0.1+1.0/2,1.0/3); glVertex3f(0.5,-0.5,0.5);
			glTexCoord2d(0.1+0.0/2,1.0/3); glVertex3f(-0.5,-0.5,0.5);
			glTexCoord2d(0.1+0.0/2,0.0/3); glVertex3f(-0.5,-0.5,-0.5);

		//back

			glTexCoord2d(0.1+0.0/2,2.0/3); glVertex3f(-0.5,0.5,-0.5);
			glTexCoord2d(0.1+1.0/2,2.0/3); glVertex3f(0.5,0.5,-0.5);
			glTexCoord2d(0.1+1.0/2,1.0/3); glVertex3f(0.5,-0.5,-0.5);
			glTexCoord2d(0.1+0.0/2,1.0/3); glVertex3f(-0.5,-0.5,-0.5);	

		//left

			glTexCoord2d(0.1+2.0/2,2.0/3); glVertex3f(-0.5,0.5,0.5);
			glTexCoord2d(0.1+1.0/2,2.0/3); glVertex3f(-0.5,0.5,-0.5);
			glTexCoord2d(0.1+1.0/2,1.0/3); glVertex3f(-0.5,-0.5,-0.5);
			glTexCoord2d(0.1+2.0/2,1.0/3); glVertex3f(-0.5,-0.5,0.5);

		//right

			glTexCoord2d(0.1+1.0/2,2.0/3); glVertex3f(0.5,-0.5,0.5);
			glTexCoord2d(0.1+2.0/2,2.0/3); glVertex3f(0.5,-0.5,-0.5);
			glTexCoord2d(0.1+2.0/2,3.0/3); glVertex3f(0.5,0.5,-0.5);
			glTexCoord2d(0.1+1.0/2,3.0/3); glVertex3f(0.5,0.5,0.5);
		
		//front

			glTexCoord2d(0.1+1.0/2,0.0/3); glVertex3f(-0.5,-0.5,0.5);
			glTexCoord2d(0.1+2.0/2,0.0/3); glVertex3f(0.5,-0.5,0.5);
			glTexCoord2d(0.1+2.0/2,1.0/3); glVertex3f(0.5,0.5,0.5);
			glTexCoord2d(0.1+1.0/2,1.0/3); glVertex3f(-0.5,0.5,0.5);
		
		glEnd();
		glPopMatrix();
	glEndList();

}

void draw_man(){
	glEnable( GL_TEXTURE_2D );
	glBindTexture(GL_TEXTURE_2D,tiles_tex);
	glPushMatrix();
		glCallList(t3);		//torso 3
		glPushMatrix();
			glTranslatef(0.0,0.8,0.0);
			glCallList(t2);		//torso 2	
			glPushMatrix();
				glRotatef(body_angles[5],0,0,1);
				glRotatef(body_angles[3],1,0,0);
				glRotatef(body_angles[4],0,1,0);
				glTranslatef(0.0,1.0,0.0);
				glCallList(t1);		//torso 1

				glPushMatrix();
					glColor3f(1.0,0.0,0.0);
					glTranslatef(0.8+0.15,0.8-0.15,0.0);		
					glCallList(Sh);		//Right Shoulder
					glPushMatrix();
						glColor3f(1.0,1.0,0.0);
						glRotatef(body_angles[15],0,0,1);
						glRotatef(body_angles[13],-1,0,0);
						glRotatef(body_angles[14],0,1,0);
						glTranslatef(0.0,-0.65,0.0);
						glCallList(UArm);	// R Upper Arm
						glPushMatrix();		
							glColor3f(1.0,0.0,0.0);
							glTranslatef(0.0,-0.65,0.0);
							glCallList(Elbow);	// R Elbow 
							glPushMatrix();
								glRotatef(body_angles[16],-1,0,0);
								glColor3f(1.0,1.0,0.0);
								glTranslatef(0.0,-0.65,0.0);
								glCallList(LArm);	// R Lower Arm
								glPushMatrix();		
									glColor3f(1.0,0.0,0.0);
									glTranslatef(0.0,-0.65,0.0);
									glCallList(Wrist);	// R Wrist 
									glPushMatrix();		
										glColor3f(0.0,0.0,1.0);
										glRotatef(body_angles[19],0,0,1);
										glRotatef(body_angles[17],-1,0,0);
										glRotatef(body_angles[18],0,1,0);
										glTranslatef(0.0,-0.4,0.0);
										glCallList(Hand);	// R Hand 
									glPopMatrix();
								glPopMatrix();
							glPopMatrix();
						glPopMatrix();						
					glPopMatrix();
				glPopMatrix();
				
				glPushMatrix();
					glColor3f(1.0,0.0,0.0);
					glTranslatef(-0.8-0.15,0.8-0.15,0.0);		
					glCallList(Sh);		//Left Shoulder
					glPushMatrix();
						glColor3f(1.0,1.0,0.0);
						glRotatef(body_angles[8],0,0,1);
						glRotatef(body_angles[6],-1,0,0);
						glRotatef(body_angles[7],0,1,0);
						glTranslatef(0.0,-0.65,0.0);
						glCallList(UArm);	// L Upper Arm
						glPushMatrix();		
							glColor3f(1.0,0.0,0.0);
							glTranslatef(0.0,-0.65,0.0);
							glCallList(Elbow);	// L Elbow 
							glPushMatrix();
								glColor3f(1.0,1.0,0.0);
								glRotatef(body_angles[9],-1,0,0);
								glTranslatef(0.0,-0.65,0.0);
								glCallList(LArm);	// L Lower Arm
								glPushMatrix();		
									glColor3f(1.0,0.0,0.0);
									glTranslatef(0.0,-0.65,0.0);
									glCallList(Wrist);	// L Wrist 
									glPushMatrix();
										glRotatef(body_angles[12],0,0,1);
										glRotatef(body_angles[10],-1,0,0);
										glRotatef(body_angles[11],0,1,0);	
										glColor3f(0.0,0.0,1.0);
										glTranslatef(0.0,-0.4,0.0);
										glCallList(Hand);	// L Hand 
									glPopMatrix();
								glPopMatrix();
							glPopMatrix();
						glPopMatrix();						
					glPopMatrix();
				glPopMatrix();

				glPushMatrix();
					glColor3f(1.0,0.0,0.0);
					glTranslatef(0.0,0.8+0.15,0.0);
					glCallList(Neck);			//Neck	
					glPushMatrix();
						glColor3f(1.0,1.0,1.0);
						glRotatef(body_angles[2],0,0,1);
						glRotatef(body_angles[0],-1,0,0);
						glRotatef(body_angles[1],0,1,0);
						glTranslatef(0.0,0.5+0.15,0.0);
						glBindTexture(GL_TEXTURE_2D,face_tex);
						glCallList(Head);		//Head
						glBindTexture(GL_TEXTURE_2D,tiles_tex);
					glPopMatrix();
				glPopMatrix();


			glPopMatrix();			
		glPopMatrix();
		
		glPushMatrix();
			glColor3f(1.0,0.0,0.0);
			glTranslatef(-0.6+0.15,-0.6-0.15,0.0);		
			glCallList(Hip);		//Left Hip
			glPushMatrix();
				glColor3f(1.0,1.0,0.0);
				glRotatef(body_angles[22],0,0,1);
				glRotatef(body_angles[20],-1,0,0);
				glRotatef(body_angles[21],0,1,0);
				glTranslatef(0.0,-0.65,0.0);
				glCallList(Thigh);	// L Thigh
				glPushMatrix();		
					glColor3f(1.0,0.0,0.0);
					glTranslatef(0.0,-0.65,0.0);
					glCallList(Knee);	// L Knee 
					glPushMatrix();
						glColor3f(1.0,1.0,0.0);
						glRotatef(body_angles[23],1,0,0);
						glTranslatef(0.0,-0.65,0.0);
						glCallList(Leg);	// L Leg
						glPushMatrix();		
							glColor3f(1.0,0.0,0.0);
							glTranslatef(0.0,-0.65,0.0);
							glCallList(Ankle);	// L Ankle 
							glPushMatrix();		
								glColor3f(1.0,1.0,0.0);
								glRotatef(body_angles[26],0,0,1);
								glRotatef(body_angles[24],-1,0,0);
								glRotatef(body_angles[25],0,1,0);
								glTranslatef(0.0,-0.3,0.15);
								glCallList(Foot);	// L Foot 
							glPopMatrix();
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();						
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();
			glColor3f(1.0,0.0,0.0);
			glTranslatef(0.6-0.15,-0.6-0.15,0.0);		
			glCallList(Hip);		//Right Hip
			glPushMatrix();
				glColor3f(1.0,1.0,0.0);
				glRotatef(body_angles[29],0,0,1);
				glRotatef(body_angles[27],-1,0,0);
				glRotatef(body_angles[28],0,1,0);
				glTranslatef(0.0,-0.65,0.0);
				glCallList(Thigh);	// R Thigh
				glPushMatrix();		
					glColor3f(1.0,0.0,0.0);
					glTranslatef(0.0,-0.65,0.0);
					glCallList(Knee);	// R Knee 
					glPushMatrix();
						glColor3f(1.0,1.0,0.0);
						glRotatef(body_angles[30],1,0,0);
						glTranslatef(0.0,-0.65,0.0);
						glCallList(Leg);	// R Leg
						glPushMatrix();		
							glColor3f(1.0,0.0,0.0);
							glTranslatef(0.0,-0.65,0.0);
							glCallList(Ankle);	// R Ankle 
							glPushMatrix();		
								glColor3f(1.0,1.0,0.0);
								glRotatef(body_angles[33],0,0,1);
								glRotatef(body_angles[31],-1,0,0);
								glRotatef(body_angles[32],0,1,0);
								glTranslatef(0.0,-0.3,0.15);
								glCallList(Foot);	// R Foot 
							glPopMatrix();
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();						
			glPopMatrix();
		glPopMatrix();


	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D,0);
	glDisable( GL_TEXTURE_2D );

}

