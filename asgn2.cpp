#include <GL/glut.h>
#include<stdio.h>
#include<iostream>
#include "defs.h"

float LA[9]= {0.0, 0.0, 12.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
				
int body_angles[34] = 	{//	x    y    z									
							0.0, 0.0, 0.0,  	//Neck	 		0-2			
							0.0, 0.0, 0.0,		//Torso			3-5			
							0.0, 0.0, 0.0,		//LShoulder		6-8			
							0.0,				//LElbow		9			
							0.0, 0.0, 0.0,		//LWrist		10-12	
							0.0, 0.0, 0.0,		//RShoulder		13-15		
							0.0,				//RElbow		16			
							0.0, 0.0, 0.0,		//RWrist		17-19		
							0.0, 0.0, 0.0,		//LHip			20-22		
							0.0,				//LKnee			23			
							0.0, 0.0, 0.0,		//LAnkle		24-26		
							0.0, 0.0, 0.0,		//RHip			27-29		
							0.0,				//RKnee			30		
							0.0, 0.0, 0.0,		//RAnkle		31-33		
						};

int min_limit[34] = {	//	x    y    z									
							-90.0, -90.0, -90.0,  	//Neck	 		0-2			
							-90.0, -90.0, -90.0,	//Torso			3-5			
							-90.0, -90.0, -90.0,	//LShoulder		6-8			
							-90.0,					//LElbow		9			
							-90.0, -90.0, -90.0,	//LWrist		10-12	
							-90.0, -90.0, -90.0,	//RShoulder		13-15		
							-90.0,					//RElbow		16			
							-90.0, -90.0, -90.0,	//RWrist		17-19		
							-90.0, -90.0, -90.0,	//LHip			20-22		
							-90.0,					//LKnee			23			
							-90.0, -90.0, -90.0,	//LAnkle		24-26		
							-90.0, -90.0, -90.0,	//RHip			27-29		
							-90.0,					//RKnee			30		
							-90.0, -90.0, -90.0,	//RAnkle		31-33		
						};

int max_limit[34] = {	//	x    y    z									
							90.0, 90.0, 90.0,  		//Neck	 		0-2			
							90.0, 90.0, 90.0,		//Torso			3-5			
							90.0, 90.0, 90.0,		//LShoulder		6-8			
							90.0,					//LElbow		9			
							90.0, 90.0, 90.0,		//LWrist		10-12	
							90.0, 90.0, 90.0,		//RShoulder		13-15		
							90.0,					//RElbow		16			
							90.0, 90.0, 90.0,		//RWrist		17-19		
							90.0, 90.0, 90.0,		//LHip			20-22		
							90.0,					//LKnee			23			
							90.0, 90.0, 90.0,		//LAnkle		24-26		
							90.0, 90.0, 90.0,		//RHip			27-29		
							90.0,					//RKnee			30		
							90.0, 90.0, 90.0,		//RAnkle		31-33		
						};


int world_rotate[3] = {0,0,0};
int win_h,win_w;

int lid_angle= 60,door_angle=60;

int lbox,lid,lift;

int cube,t3,t2,t1,Neck,Head,Sh,UArm,Elbow,LArm,Wrist,Hand,Hip,Thigh,Knee,Leg,Ankle,Foot;

int room,door,table_top,table_leg,chair_back, arm_rest ,back_frame, side_frame, book_shelf,lamp_post, lamp_base,mirror_frame;

float z_sel = 0;
int mode = 0; // 0 - normal , 1 - point selection , 2 - animation

float px=0,py=0,pz = 0;
GLfloat ctrlpoints [100][3];
int point_count = 0;
GLfloat result [3];


int curr_joint=0;
int curr_num=0;
int prev_num=0;

bool l1=true,l2 = true;

GLuint wood_tex,tiles_tex,face_tex,stone_tex,door_tex;

GLdouble eqn1[4] = { 0.0, 0.0, -1.0, 4.6 };
	
void evalBezier(float t, int num){
	float temp [100][3];

	for ( int i=0;i<num;i++){
		for(int j=0;j<3;j++){
			temp[i][j] = ctrlpoints[i][j];
		}
	}

	for ( int i=0;i<3;i++){
		for(int j=num-1;j>0;j--){
			for(int k = 0 ; k < j ; k++){
				temp[k][i] = (1-t)*temp[k][i]+t*temp[k+1][i];
			}
		}
	}
	
	result[0] = temp [0][0];
	result[1] = temp [0][1];
	result[2] = temp [0][2];

} 

void draw_curve(){
	glBegin(GL_LINES);
		evalBezier(0.0 , point_count);
		for(int i=0;i<100;i++){
			glVertex3f(result[0],result[1],result[2]);
			evalBezier((float)i/100.0 , point_count);
			glVertex3f(result[0],result[1],result[2]);
		}		
	glEnd();

}



void init(void) 
{

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_DEPTH_TEST);
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH); 

	glEnable( GL_TEXTURE_2D );
	loadBMP_custom("textures/wood.bmp",wood_tex);
	loadBMP_custom("textures/tiles.bmp",tiles_tex);
	loadBMP_custom("textures/face.bmp",face_tex);
	loadBMP_custom("textures/stone.bmp",stone_tex);
	loadBMP_custom("textures/door.bmp",door_tex);
	glDisable( GL_TEXTURE_2D );



	glEnable(GL_COLOR_MATERIAL);	
	glColorMaterial(GL_FRONT, GL_DIFFUSE);


	// Lamp light
	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	// Wall light
	GLfloat light_ambient1[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse1[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular1[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);

	compile_man();
	compile_box();
	compile_room();
}

void loadBMP_custom(const char * imagepath,GLuint& textureID){
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;

	FILE * file = fopen(imagepath,"rb");
	if (!file){
		printf("Image could not be opened\n"); 
		return;
	}
	
	if ( fread(header, 1, 54, file)!=54 ){ 
		// If not 54 bytes read : problem
		printf("Not a correct BMP file\n");
   		return;
	}

	if ( header[0]!='B' || header[1]!='M' ){
		printf("Not a correct BMP file\n");
		return;
	}
	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);

	if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos==0)      dataPos=54; // The BMP header is done that way

	// Create a buffer
	data = new unsigned char [imageSize];
	 
	// Read the actual data from the file into the buffer
	fread(data,1,imageSize,file);
	 
	//Everything is in memory now, the file can be closed
	fclose(file);

	
	glGenTextures(1, &textureID);
	 
	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);
	 
	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

}




void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glLoadIdentity ();          
    GLint buffers = GL_NONE;

    // get the current color buffer being drawn to
    glGetIntegerv( GL_DRAW_BUFFER, &buffers );

	gluLookAt (LA[0],LA[1],LA[2],LA[3],LA[4],LA[5],LA[6],LA[7],LA[8]);
	


	glPushMatrix();
		glRotatef (world_rotate[0],1.0,0.0,0.0);  
		glRotatef (world_rotate[1],0.0,1.0,0.0);


		if(mode != 1){
			glPushMatrix();						//Code for adding mirror
					// set the clear value
					glClearStencil( 0 );
					// clear the stencil buffer
					glClear( GL_STENCIL_BUFFER_BIT  );
					// always pass the stencil test
					glStencilFunc(GL_ALWAYS, 1, 1 );
					// set the operation to modify the stencil buffer
					glStencilOp( GL_REPLACE, GL_REPLACE, GL_REPLACE );
					// disable drawing to the color buffer
					glDrawBuffer( GL_NONE );
					// enable stencil
					glEnable( GL_STENCIL_TEST );

					// draw the stencil mask
					glBegin( GL_QUADS );
						glVertex3f(-5.0,-2.0,4.6);
						glVertex3f(-3.0,-2.0,4.6);
						glVertex3f(-3.0,2.0,4.6);
						glVertex3f(-5.0,2.0,4.6);
					glEnd();

					// reenable drawing to color buffer
					glDrawBuffer( (GLenum) buffers );
					// make stencil buffer read only
					glStencilOp( GL_KEEP, GL_KEEP, GL_KEEP );
					// clear the color and buffers
					glClear( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT );

					glPushMatrix();
						// invert image about xy plane
						glTranslatef(0.0,0.0,4.6);
						glScalef( 1.0f, 1.0f, -1.0f );
						glTranslatef(0.0,0.0,-4.6);

						// clip one side of the plane
						glClipPlane( GL_CLIP_PLANE0, eqn1 );
						glEnable( GL_CLIP_PLANE0 );

						// draw only where the stencil buffer == 1
						glStencilFunc( GL_EQUAL, 1, 1 );
						// draw the object
				
						glPushMatrix();
							draw_room();
							glTranslatef(-5.5,-0.9,-4);
							glPushMatrix();
								draw_box();			
							glPopMatrix();
						glPopMatrix();

						// turn off clipping plane
						glDisable( GL_CLIP_PLANE0 );
					glPopMatrix( );

					// disable the stencil buffer
					glDisable( GL_STENCIL_TEST );
					// disable drawing to the color buffer
					glDrawBuffer( GL_NONE );

					// draw the mirror pane into depth buffer -
					// to prevent object behind mirror from being render
					glBegin( GL_QUADS );
						glVertex3f(-5.0,-2.0,4.6);
						glVertex3f(-3.0,-2.0,4.6);
						glVertex3f(-3.0,2.0,4.6);
						glVertex3f(-5.0,2.0,4.6);
					glEnd();

					// enable drawing to the color buffer
					glDrawBuffer( (GLenum) buffers );
			glPopMatrix();
		}


		glPushMatrix();
			draw_room();
			glTranslatef(-5.5,-0.9,-4);
			glPushMatrix();
				draw_box();			
			glPopMatrix();
		glPopMatrix();
	

		if(mode == 1){
			glColor3f(1.0,1.0,0.0);
			glBegin(GL_QUADS);
					
					glVertex3f(-7.0,-3.0,z_sel);
					glVertex3f(7.0,-3.0,z_sel);
					glVertex3f(7.0,3.0,z_sel);
					glVertex3f(-7.0,3.0,z_sel);
			glEnd();
	

			for(int i=0;i<point_count;i++){
				glPushMatrix();
					glTranslatef(ctrlpoints[i][0],ctrlpoints[i][1],ctrlpoints[i][2]);
					glScalef(0.1,0.1,0.1);
					glColor3f(1.0,0.0,0.0);
					glCallList(cube);
				glPopMatrix();
			}
	
			draw_curve();
		}

		GLfloat light_position[] = {0.0f, 0.0f, -4.5f, 1.0f};
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);

		GLfloat light_position1[] = {0.0f, 1.5f, 4.5f, 1.0f};
		glLightfv(GL_LIGHT1, GL_POSITION, light_position1);

	glPopMatrix();



	glutSwapBuffers ();
}

void reshape (int w, int h)
{
   win_h=h,win_w=w;
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0*((double)h/w), 1.0*((double)h/w), 1.0, 30.0);
   glMatrixMode (GL_MODELVIEW);
}

void animate(int value){
	if(mode == 2 && value < 1000 ){
		evalBezier(float(value) / 1000.0 , point_count);
		LA[0]= result[0]; LA[1]= result[1]; LA[2]= result[2];

		glutPostRedisplay();
		glutTimerFunc (10, animate, value+1);
	}	
}

void keyboard( unsigned char key, int x, int y ) {

	if('0' <= key && key <= '9'){
		prev_num = curr_num;
		curr_num = key - '0';
		curr_joint = prev_num*10 + curr_num;
	}

	switch(key) {
		case '.': 
			if(lid_angle<90)
				lid_angle++;
			break;
		case ',': 
			if(lid_angle>0)
				lid_angle--;
			break;
		case ';': 
			if(door_angle<90)
				door_angle++;
			break;
		case 39: 
			if(door_angle>0)
				door_angle--;
			break;
		case 'w': 
			world_rotate[0]++;
			break;
		case 's': 
			world_rotate[0]--;
			break;
		case 'a': 
			world_rotate[1]++;
			break;
		case 'd': 
			world_rotate[1]--;
			break;
		case 'k': 
			LA[2]+=0.5;
			LA[5]+=0.5;
			break;
		case 'i': 
			LA[2]-=0.5;
			LA[5]-=0.5;
			break;
		case 'l': 
			LA[0]+=0.5;
			LA[3]+=0.5;
			break;
		case 'j': 
			LA[0]-=0.5;
			LA[3]-=0.5;
			break;
		case 'z': 
			z_sel+=0.2;
			break;
		case 'x': 
			z_sel-=0.2;
			break;
		case 'b': 		// normal mode
			glEnable(GL_LIGHTING);
			mode = 0;
			compile_room();
			break;
		case 'e':		//set the view to look at the man 
			LA[0] = -5.5; LA[1]=1.0; LA[2]= -2.0; LA[3]= -5.5; LA[4]= -1.0; LA[5]= -4.0; LA[6]= 0.0; LA[7]= 1.0; LA[8]= 0.0;
			world_rotate[0] = 0.0;world_rotate[1] = 0.0;world_rotate[2] = 0.0;
			break;
		case 'r':		//reset the view ( bring to clicking view in mode 1
			LA[0] = 0.0; LA[1]=0.0; LA[2]= 12.0; LA[3]= 0.0; LA[4]= 0.0; LA[5]= 0.0; LA[6]= 0.0; LA[7]= 1.0; LA[8]= 0.0;
			world_rotate[0] = 0.0;world_rotate[1] = 0.0;world_rotate[2] = 0.0;
			break;
		case 'c': 		// change to point clicking mode
			glDisable(GL_LIGHTING);
			LA[0] = 0.0; LA[1]=0.0; LA[2]= 12.0; LA[3]= 0.0; LA[4]= 0.0; LA[5]= 0.0; LA[6]= 0.0; LA[7]= 1.0; LA[8]= 0.0;
			world_rotate[0] = 0.0;world_rotate[1] = 0.0;world_rotate[2] = 0.0;
			point_count = 0;
			mode = 1;
			compile_room();
			break;
		case 'v': 		//animation mode
			glEnable(GL_LIGHTING);
			LA[3]= -6.0; LA[4]= -1.0; LA[5]= -4.0;			// making lookat towards box
			mode = 2; 
			compile_room();
			glutTimerFunc (10, animate, 0);
			//animate();
			break;
		case '[':		
			if(0<= curr_joint<=34){
				if(body_angles[curr_joint]>min_limit[curr_joint])
					body_angles[curr_joint]--;
			}
			break;
		case ']':
			if(0<= curr_joint<=34){
				if(body_angles[curr_joint]<max_limit[curr_joint])
					body_angles[curr_joint]++;
			}
			break;
		case 'n': 
			l1 = !l1;
			if(l1)
				glEnable(GL_LIGHT0);
			else
				glDisable(GL_LIGHT0);
			break;
		case 'm': 
			l2 = !l2;
			if(l2)
				glEnable(GL_LIGHT1);
			else
				glDisable(GL_LIGHT1);
			break;

	}	
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) 
{   
	if (state == GLUT_DOWN) 
     {
       if (button == GLUT_LEFT_BUTTON) 
		 {
			if(mode == 1){
				pz = z_sel;
				px =  (x - win_w/2.0) * (12 - z_sel) *2/ (double) win_w ;
				py =  -(y - win_h/2.0) * (12 - z_sel) *2/ (double) win_w ;
				ctrlpoints[point_count][0] = px;
				ctrlpoints[point_count][1] = py;
				ctrlpoints[point_count][2] = pz;
				point_count++;
			}	
		 }
     }
   glutPostRedisplay();
}   


int main(int argc, char** argv)
{
	win_h=700,win_w=700;
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH  | GLUT_STENCIL);
	glutInitWindowSize (700, 700); 
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Man and Box");
	init ();
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc( keyboard );
	glutMouseFunc( mouse );

	glutMainLoop();
	return 0;
}



