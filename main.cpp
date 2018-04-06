#include<windows.h>
#include<math.h>
#include <GL/glut.h>
#include<stdio.h>

GLfloat LeftCarX = -60;
const GLint LeftCarY = 5;
GLfloat RightCarX = 25;
const GLfloat RightCarY = -17;
const GLfloat UpCarX = 17;
GLfloat UpCarY = 30;
const GLfloat DowntCarX = -17;
GLfloat DownCarY = -30;
GLfloat spin = 90;
GLfloat spinTraffic = 90;
GLfloat SignalRightR=1;
GLfloat SignalRightG=0;
GLfloat SignalUpDownR=1;
GLfloat SignalUpDownG=0;
char StateLR = 'o';
char StateUD = 'o';
GLfloat PositionLeftCar[50];
GLfloat PositionRightCar[50];
GLfloat PositionUpCar[50];
GLfloat PositionDownCar[50];



void DrawCarLeftRight(GLfloat R, GLfloat G, GLfloat B);
void DrawCarUp(GLfloat R, GLfloat G, GLfloat B);
void DrawCarDown(GLfloat R, GLfloat G, GLfloat B);
void DrawPatternForRoad();
void DrawEnvironment();
void DrawHouse(GLfloat x, GLfloat y, GLfloat H, GLfloat W);
void Locality();
void LocalityFullArea();
void Signal(GLfloat R, GLfloat G, GLfloat B);
void DrawAllSignal();
void StartLeftRightCar();
void StartUpDownCar();
void Circle(GLfloat R, GLfloat G, GLfloat B, GLdouble);
void traffic();
void People(GLfloat Rota);
void ProduceCar();
void Bench();
void allBench();
void allPeople();


static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    DrawEnvironment();
    DrawPatternForRoad();
    LocalityFullArea();
    DrawAllSignal();
    ProduceCar();
    traffic();
    StartLeftRightCar();
    StartUpDownCar();
    allBench();
    allPeople();
    glFlush();
}

void SpecialKeyFunc(int Input, int x, int y){
    switch(Input){
    case GLUT_KEY_RIGHT:
        StateLR = 's';
        StateUD = 'o';
        glutIdleFunc(StartLeftRightCar);
        break;
    case GLUT_KEY_LEFT:
        StateLR = 'o';
        StartLeftRightCar();
        break;
    case GLUT_KEY_UP:
        StateUD = 's';
        StateLR = 'o';
        glutIdleFunc(StartUpDownCar);
        break;
    case GLUT_KEY_DOWN:
        StateUD = 'o';
        StartUpDownCar();
        break;
    }
}

void InItGL(){
    glClearColor(0.337, 0.423, 0.411, 0);
    glOrtho(-100, 100, -100, 100, -1, 1);
}

void CarPos(){
    GLint CarDist = 0;
    for(int i=0; i<50; i++){
        PositionRightCar[i] = RightCarX + CarDist;
        PositionLeftCar[i] = LeftCarX - CarDist;
        PositionDownCar[i] = DownCarY - CarDist;
        PositionUpCar[i] = UpCarY + CarDist;
        CarDist += 35;
     }
}

//main Function
int main(int argc, char *argv[]){
    CarPos();
    glutInit(&argc, argv);
    glutInitWindowSize(720,720);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    InItGL();
    glutDisplayFunc(display);
    glutSpecialFunc(SpecialKeyFunc);
    glutMainLoop();

    return 0;
}
//Function for drawing car

void allBench(){

    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glTranslatef(-65, -27, 0);
    Bench();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-35, -27, 0);
    Bench();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-80, -27, 0);
    Bench();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(35, 27, 0);
    glRotatef(-180, 0, 0, 1);
    Bench();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(90, 27, 0);
    glRotatef(-180, 0, 0, 1);
    Bench();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(35, -27, 0);
    Bench();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 0, 0, 1);
    glTranslatef(-65, -27, 0);
    Bench();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(90, -27, 0);
    Bench();
    glPopMatrix();


    glPushMatrix();
    glRotatef(90, 0, 0, 1);
    glTranslatef(65, -27, 0);
    Bench();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180, 0, 0, 1);
    glTranslatef(40, -27, 0);
    Bench();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180, 0, 0, 1);
    glTranslatef(80, -27, 0);
    Bench();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glTranslatef(65, -27, 0);
    Bench();
    glPopMatrix();


}

void StartLeftRightCar(){
    //code for before stopping car
    if(StateLR == 's'){
            for(int i =0; i<50; i++){
                PositionRightCar[i] -= .05;
                PositionLeftCar[i] += .05;
            }
            SignalRightR=0.0;
            SignalRightG=1.0;
            spinTraffic = 0;
            glutPostRedisplay();

    } else{
        //code for after stooping the car
        for(int i = 0; i<50; i++){
                //right side car code
            if(PositionRightCar[i]<10&&PositionRightCar[i]>-150){
                PositionRightCar[i]-=.05;
                if(PositionRightCar[i+1]>10&&PositionRightCar[i+1]<11){

                }
                else if(PositionRightCar[i+1]>10 && PositionRightCar[i+1]<100){
                    PositionRightCar[i+1]-=.05;
                    PositionRightCar[i+2] -= .05;
                    PositionRightCar[i+3] -= .05;
                    PositionRightCar[i+4] -= .05;
                    PositionRightCar[i+5] -= .05;
                    PositionRightCar[i+6] -= .05;

                }
            } else{
                PositionRightCar[i];
            }
            //left side car code
            if(PositionLeftCar[i]>-50 && PositionLeftCar[i]<150){
                PositionLeftCar[i]+=.05;
                if(PositionLeftCar[i+1]<-50 && PositionLeftCar[i+1]>-51){

                } else if(PositionLeftCar[i+1]<-50 && PositionLeftCar[i+1]>-100){
                    PositionLeftCar[i+1] += .05;
                    PositionLeftCar[i+2] += .05;
                    PositionLeftCar[i+3] += .05;
                    PositionLeftCar[i+4] += .05;
                    PositionLeftCar[i+5] += .05;
                    PositionLeftCar[i+6] += .05;

                }
            } else{
                PositionLeftCar[i];
            }
        }

        SignalRightR=1.0;
        SignalRightG=0.0;
        spinTraffic = 90;
        glutPostRedisplay();
    }

}

void StartUpDownCar(){
    if(StateUD == 's'){
            for(int i =0; i<50; i++){
                PositionDownCar[i] += .05;
                PositionUpCar[i] -= .05;
            }
            SignalUpDownR=0.0;
            SignalUpDownG=1.0;
            spinTraffic = 90;
            glutPostRedisplay();
    } else{
        for(int i = 0; i<50; i++){
                //right side car code
            if(PositionDownCar[i]>-10&&PositionDownCar[i]<150){
                PositionDownCar[i]+=.05;
                if(PositionDownCar[i+1]<-10&&PositionDownCar[i+1]>-11){

                }
                else if(PositionDownCar[i+1]<-10 && PositionDownCar[i+1]>-100){
                    PositionDownCar[i+1] +=.05;
                    PositionDownCar[i+2] += .05;
                    PositionDownCar[i+3] += .05;
                    PositionDownCar[i+4] += .05;
                    PositionDownCar[i+5] += .05;
                    PositionDownCar[i+6] += .05;

                }
            } else{
                PositionDownCar[i];
            }
            //left side car code
            if(PositionUpCar[i]<10 && PositionUpCar[i]>-150){
                PositionUpCar[i]-=.05;
                if(PositionUpCar[i+1]>10 && PositionUpCar[i+1]<11){

                } else if(PositionUpCar[i+1]>10 && PositionUpCar[i+1]<150){
                    PositionUpCar[i+1] -= .05;
                    PositionUpCar[i+2] -= .05;
                    PositionUpCar[i+3] -= .05;
                    PositionUpCar[i+4] -= .05;
                    PositionUpCar[i+5] -= .05;
                    PositionUpCar[i+6] -= .05;

                }
            } else{
                PositionUpCar[i];
            }
        }
        UpCarY;
        DownCarY;
        SignalUpDownR=1.0;
        SignalUpDownG=0.0;
        spinTraffic = 0;
        glutPostRedisplay();
    }

}

void DrawCarLeftRight(GLfloat R, GLfloat G, GLfloat B){
    glScalef(.5,.5,0);
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
        glVertex2f(17.33, 20.31);
        glVertex2f(17.33, 5.11);
        glVertex2f(20.93, 1.64);
        glVertex2f(54.93, 1.64);
        glVertex2f(58.33, 5.11);
        glVertex2f(58.33, 20.37);
        glVertex2f(54.93, 23.91);
        glVertex2f(20.93, 23.91);
    glEnd();
    glColor3f(0.898, 0.933, 0.886);
    glBegin(GL_POLYGON);
        glVertex2f(19.1, 5.71);
        glVertex2f(24.15, 3.41);
        glVertex2f(24.15, 22.14);
        glVertex2f(19.1, 20.44);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(49, 2.52);
        glVertex2f(54.86, 5.05);
        glVertex2f(54.86, 20.5);
        glVertex2f(49, 23.02);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(22.57, 0);
        glVertex2f(27.61, 0);
        glVertex2f(27.61, 1.64);
        glVertex2f(22.57, 1.64);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(47.99, 0);
        glVertex2f(53.03, 0);
        glVertex2f(53.03, 1.64);
        glVertex2f(47.99, 1.64);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(22.57,23.91);
        glVertex2f(22.57,25.61);
        glVertex2f(27.61, 25.61);
        glVertex2f(27.61, 23.91);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(47.99, 23.91);
        glVertex2f(47.99, 25.61);
        glVertex2f(53.58, 25.61);
        glVertex2f(53.48, 23.61);
    glEnd();
    glColor3f(0.898, 0.933, 0.886);
    glBegin(GL_POLYGON);
        glVertex2f(25.91, 3.78);
        glVertex2f(26.48, 2.52);
        glVertex2f(34.68, 2.52);
        glVertex2f(35.94, 3.78);
    glEnd();
     glBegin(GL_POLYGON);
        glVertex2f(37.2,3.78);
        glVertex2f(37.77,2.52);
        glVertex2f(45.97,2.52);
        glVertex2f(47.23,3.78);
    glEnd();
     glBegin(GL_POLYGON);
        glVertex2f(26.23,21.80);
        glVertex2f(26.79, 23.10);
        glVertex2f(34.99, 23.10);
        glVertex2f(36.26,21.80);
    glEnd();
     glBegin(GL_POLYGON);
        glVertex2f(37.52,21.80);
        glVertex2f(38.09,23.10);
        glVertex2f(46.29, 23.10);
        glVertex2f(47.55, 21.80);
    glEnd();

}

void DrawCarUp(GLfloat R, GLfloat G, GLfloat B){

    glScalef(.5,.5,0);
    glRotatef(spin, 0.0, 0.0, 1.0);
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
        glVertex2f(17.33, 20.31);
        glVertex2f(17.33, 5.11);
        glVertex2f(20.93, 1.64);
        glVertex2f(54.93, 1.64);
        glVertex2f(58.33, 5.11);
        glVertex2f(58.33, 20.37);
        glVertex2f(54.93, 23.91);
        glVertex2f(20.93, 23.91);
    glEnd();
    glColor3f(0.898, 0.933, 0.886);
    glBegin(GL_POLYGON);
        glVertex2f(19.1, 5.71);
        glVertex2f(24.15, 3.41);
        glVertex2f(24.15, 22.14);
        glVertex2f(19.1, 20.44);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(49, 2.52);
        glVertex2f(54.86, 5.05);
        glVertex2f(54.86, 20.5);
        glVertex2f(49, 23.02);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(22.57, 0);
        glVertex2f(27.61, 0);
        glVertex2f(27.61, 1.64);
        glVertex2f(22.57, 1.64);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(47.99, 0);
        glVertex2f(53.03, 0);
        glVertex2f(53.03, 1.64);
        glVertex2f(47.99, 1.64);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(22.57,23.91);
        glVertex2f(22.57,25.61);
        glVertex2f(27.61, 25.61);
        glVertex2f(27.61, 23.91);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(47.99, 23.91);
        glVertex2f(47.99, 25.61);
        glVertex2f(53.58, 25.61);
        glVertex2f(53.48, 23.61);
    glEnd();
    glColor3f(0.898, 0.933, 0.886);
    glBegin(GL_POLYGON);
        glVertex2f(25.91, 3.78);
        glVertex2f(26.48, 2.52);
        glVertex2f(34.68, 2.52);
        glVertex2f(35.94, 3.78);
    glEnd();
     glBegin(GL_POLYGON);
        glVertex2f(37.2,3.78);
        glVertex2f(37.77,2.52);
        glVertex2f(45.97,2.52);
        glVertex2f(47.23,3.78);
    glEnd();
     glBegin(GL_POLYGON);
        glVertex2f(26.23,21.80);
        glVertex2f(26.79, 23.10);
        glVertex2f(34.99, 23.10);
        glVertex2f(36.26,21.80);
    glEnd();
     glBegin(GL_POLYGON);
        glVertex2f(37.52,21.80);
        glVertex2f(38.09,23.10);
        glVertex2f(46.29, 23.10);
        glVertex2f(47.55, 21.80);
    glEnd();

}

void DrawCarDown(GLfloat R, GLfloat G, GLfloat B){

    glScalef(.5,.5,0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
        glVertex2f(17.33, 20.31);
        glVertex2f(17.33, 5.11);
        glVertex2f(20.93, 1.64);
        glVertex2f(54.93, 1.64);
        glVertex2f(58.33, 5.11);
        glVertex2f(58.33, 20.37);
        glVertex2f(54.93, 23.91);
        glVertex2f(20.93, 23.91);
    glEnd();
    glColor3f(0.898, 0.933, 0.886);
    glBegin(GL_POLYGON);
        glVertex2f(19.1, 5.71);
        glVertex2f(24.15, 3.41);
        glVertex2f(24.15, 22.14);
        glVertex2f(19.1, 20.44);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(49, 2.52);
        glVertex2f(54.86, 5.05);
        glVertex2f(54.86, 20.5);
        glVertex2f(49, 23.02);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(22.57, 0);
        glVertex2f(27.61, 0);
        glVertex2f(27.61, 1.64);
        glVertex2f(22.57, 1.64);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(47.99, 0);
        glVertex2f(53.03, 0);
        glVertex2f(53.03, 1.64);
        glVertex2f(47.99, 1.64);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(22.57,23.91);
        glVertex2f(22.57,25.61);
        glVertex2f(27.61, 25.61);
        glVertex2f(27.61, 23.91);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(47.99, 23.91);
        glVertex2f(47.99, 25.61);
        glVertex2f(53.58, 25.61);
        glVertex2f(53.48, 23.61);
    glEnd();
    glColor3f(0.898, 0.933, 0.886);
    glBegin(GL_POLYGON);
        glVertex2f(25.91, 3.78);
        glVertex2f(26.48, 2.52);
        glVertex2f(34.68, 2.52);
        glVertex2f(35.94, 3.78);
    glEnd();
     glBegin(GL_POLYGON);
        glVertex2f(37.2,3.78);
        glVertex2f(37.77,2.52);
        glVertex2f(45.97,2.52);
        glVertex2f(47.23,3.78);
    glEnd();
     glBegin(GL_POLYGON);
        glVertex2f(26.23,21.80);
        glVertex2f(26.79, 23.10);
        glVertex2f(34.99, 23.10);
        glVertex2f(36.26,21.80);
    glEnd();
     glBegin(GL_POLYGON);
        glVertex2f(37.52,21.80);
        glVertex2f(38.09,23.10);
        glVertex2f(46.29, 23.10);
        glVertex2f(47.55, 21.80);
    glEnd();

}
//Function for drawing pattern on road
void DrawPatternForRoad(){
    glColor3f(1,1,1);
    glLineWidth(10);
    for(float i=-100; i<=-40; i+=20){
        glBegin(GL_LINES);
            glVertex2f(i, 0);
            glVertex2f(i+10, 0);
        glEnd();
    }
    for(float i=150; i>=20; i-=20){
        glBegin(GL_LINES);
            glVertex2f(i, 0);
            glVertex2f(i+10, 0);
        glEnd();
    }
    for(float i=-100; i<=-40; i+=20){
        glBegin(GL_LINES);
            glVertex2f(0, i);
            glVertex2f(0, i+10);
        glEnd();
    }
    for(float i=30; i<=100; i+=20){
        glBegin(GL_LINES);
            glVertex2f(0, i);
            glVertex2f(0, i+10);
        glEnd();
    }
}
//Function for Environment
void DrawEnvironment(){
    glColor3f(0.654, 0.713, 0.803);
    glBegin(GL_POLYGON);
        glVertex2f(-100, 20);
        glVertex2f(-20, 20);
        glVertex2f(-20, 100);
        glVertex2f(-100, 100);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(100, 20);
        glVertex2f(20, 20);
        glVertex2f(20, 100);
        glVertex2f(100, 100);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-100, -20);
        glVertex2f(-20, -20);
        glVertex2f(-20, -100);
        glVertex2f(-100, -100);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(100, -20);
        glVertex2f(20, -20);
        glVertex2f(20, -100);
        glVertex2f(100, -100);
    glEnd();
}
//Function for house
void DrawHouse(GLfloat x, GLfloat y, GLfloat H, GLfloat W){
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x, y+H);
        glVertex2f(x+W, y+H);
        glVertex2f(x+W, y);
    glEnd();
}
//Function for LocalArea
void Locality(){
        glColor3d(0.725, 0.650, 0.392);
        DrawHouse(-100, 90, 10, 10);
        DrawHouse(-89, 90, 15, 10);
        glColor3d(0.505, 0.329, 0.752);
        DrawHouse(-78, 90, 15, 10);
        DrawHouse(-67, 90, 15, 10);
        glColor3d(0.725, 0.650, 0.392);
        DrawHouse(-56, 90, 15, 10);
        glColor3d(0.505, 0.329, 0.752);
        DrawHouse(-45, 90, 15, 10);
        DrawHouse(-34, 90, 15, 12);
        glColor3d(0.725, 0.650, 0.392);
        DrawHouse(-79, 85, -20, -20);
        DrawHouse(-78, 65, 20, 10);
        glColor3d(0.925, 0.941, 0.019);
        DrawHouse(-67, 65, 20, 10);
        DrawHouse(-56, 65, 20, 13);
        glColor3d(0.505, 0.329, 0.752);
        DrawHouse(-22, 85, -20, -20);
        DrawHouse(-22, 58, -30, -30);
        glColor3d(0.780, 0.964, 0.474);
        DrawHouse(-78, 43, 15, 10);
        DrawHouse(-67, 43, 15, 14);
        DrawHouse(-78, 43-15, 13, 10);
        glColor3d(0.925, 0.941, 0.019);
        DrawHouse(-67, 43-15, 13, 14);
        DrawHouse(-99, 58, -30, 20);

}
//Full Locality area
void LocalityFullArea(){

    glPushMatrix();
    glRotatef(-90,0,0,1);
    glTranslatef(-17,5, 0);
    Locality();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180,0,0,1);
    glTranslatef(-10, 10, 0);
    Locality();
    glPopMatrix();

    glPushMatrix();
    glRotatef(0,90,0,1);
    glTranslatef(-10, 10, 0);
    Locality();
    glPopMatrix();

    glPushMatrix();
    glRotatef(0,90,0,1);
    glTranslatef(-10,-143, 0);
    Locality();
    glPopMatrix();

}

void Signal(GLfloat R,GLfloat G,GLfloat B){

    GLdouble rad = 2;
    GLint points = 130;
	GLdouble delTheta = (2.0 * 3.1416) / (GLdouble)points;
	GLdouble theta = 0.0;
    GLint i=0;
	glBegin(GL_POLYGON);
	{
		for(i = 0; i <=points-1; i++, theta += delTheta )
		{   glColor3f(R,G,B);
			glVertex2f(rad * cos(theta),rad * sin(theta));
		}
	}
	glEnd();
}

void Circle(GLfloat R,GLfloat G,GLfloat B, GLdouble rad){

    GLint points = 130;
	GLdouble delTheta = (2.0 * 3.1416) / (GLdouble)points;
	GLdouble theta = 0.0;
    GLint i=0;
	glBegin(GL_POLYGON);
	{
		for(i = 0; i <=points-1; i++, theta += delTheta )
		{   glColor3f(R,G,B);
			glVertex2f(rad * cos(theta),rad * sin(theta));
		}
	}
	glEnd();
}

void DrawAllSignal(){
    //right signal
    glPushMatrix();
    glTranslatef(-23, 24, 0);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(0, -1);
        glVertex2f(3, -1);
        glVertex2f(3, 1);
        glVertex2f(0, 1);
    glEnd();
    Signal(SignalRightR,SignalRightG,0);
    glPopMatrix();
    //Down signal
    glPushMatrix();
    glTranslatef(23, 24, 0);
    glColor3f(0,0,0);
        glBegin(GL_POLYGON);
        glVertex2f(-1, 0);
        glVertex2f(-1, -4);
        glVertex2f(1, -4);
        glVertex2f(1, 0);
    glEnd();
    Signal(SignalUpDownR,SignalUpDownG,0);
    glPopMatrix();
    //Left signal
    glPushMatrix();
    glTranslatef(23, -24, 0);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(0, -1);
        glVertex2f(-3, -1);
        glVertex2f(-3, 1);
        glVertex2f(0, 1);
    glEnd();
    Signal(SignalRightR,SignalRightG,0);
    glPopMatrix();
    //up signal
    glPushMatrix();
    glTranslatef(-23, -24, 0);
    glColor3f(0,0,0);
        glBegin(GL_POLYGON);
        glVertex2f(-1, 0);
        glVertex2f(-1, 4);
        glVertex2f(1, 4);
        glVertex2f(1, 0);
    glEnd();
    Signal(SignalUpDownR,SignalUpDownG,0);
    glPopMatrix();
}

void traffic(){
        //draw man
    glPushMatrix();
    glRotatef(spinTraffic, 0.0, 0.0, 1.0);
    glColor3f(0,0,0);
    glLineWidth(4);
    //left hand
    glBegin(GL_LINES);
        glVertex2f(0, 3);
        glVertex2f(-2, 3);
    glEnd();
    //right hand
    glBegin(GL_LINES);
        glVertex2f(0, -3);
        glVertex2f(-2, -3);
    glEnd();


    Circle(0.984, 0.819, 0.619, 2.5);
    //sholder mark left
    glLineWidth(2);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
        glVertex2f(0, -2.5);
        glVertex2f(0, 2.5);
    glEnd();
    Circle(1, 1, 1, 1);
    glPopMatrix();
}

void People(GLfloat Rota){
        //draw man
    glPushMatrix();
    glRotatef(Rota, 0.0, 0.0, 1.0);
    glColor3f(0,0,0);
    glLineWidth(4);
    //left hand
    glBegin(GL_LINES);
        glVertex2f(0, 3);
        glVertex2f(-2, 3);
    glEnd();
    //right hand
    glBegin(GL_LINES);
        glVertex2f(0, -3);
        glVertex2f(-2, -3);
    glEnd();
    Circle(0.984, 0.819, 0.619, 2.5);
    Circle(0, 0, 0, 1);
    glPopMatrix();
}
//producing cars
void ProduceCar(){
    //right car
    for(int i = 0; i<50; i++){
        glPushMatrix();

        glTranslatef(PositionRightCar[i], RightCarY, 0);

        if(i%2==0){
            DrawCarLeftRight(0.9*i, 7.0/i-.96602, 0.7*i-2);
        } else if(i%3==0){
            DrawCarLeftRight(0.9/i, 7.0*i-.96602, 0.7*i-2);
        } else{
            DrawCarLeftRight(0.9*i, 7.0/i-.96602, 9.0/i-2);
        }
        glPopMatrix();
    }
//left car
    for(int i = 0; i<50; i++){
        glPushMatrix();
        glTranslatef(PositionLeftCar[i], LeftCarY, 0);

        if(i%2==0){
            DrawCarLeftRight(10.0/i-4, 7.0/i-.96602, 0.7*i-2);
        } else if(i%3==0){
            DrawCarLeftRight(2.0/i, 7.0/i-.96602, 0.7*i-2);
        } else{
            DrawCarLeftRight(2.0*i, .50/i-.96602, 5.0/i-2);
        }
        glPopMatrix();
    }

    for(int i = 0; i<50; i++){
        glPushMatrix();
        glTranslatef(UpCarX, PositionUpCar[i], 0);
        if(i%2==0){
            DrawCarUp(0.0/i-4, 10.0/i-3.96602, 15.7*i-2);
        } else if(i%3==0){
            DrawCarUp(15.0/i-6, 0.06/i-.96602, 2.7*i-2);
        } else{
            DrawCarUp(6.0*i-4, 2.50/i-.96602, 0.0/i-2);
        }
        glPopMatrix();
    }

    for(int i = 0; i<50; i++){
        glPushMatrix();
        glTranslatef(DowntCarX, PositionDownCar[i], 0);
        if(i%2==0){
            DrawCarDown(.4*i, 1.0/i-.96602, 7*i-2);
        } else if(i%3==0){
            DrawCarDown(7/i, 0.09*i-.96602, 0.2*i-2);
        } else{
            DrawCarDown(0.9*i, 7.0/i-.96602, 9.0/i-2);
        }
        glPopMatrix();
    }

}

void Bench(){

    glColor3f(0, 0.682, 0.937);
    glBegin(GL_POLYGON);
        glVertex2f(-6.6, -2.15);
        glVertex2f(5.33, -2.15);
        glVertex2f(5.33, 1.61);
        glVertex2f(-6.6, 1.61);
    glEnd();
    glColor3f(0.447, 0.4, 0.345);
    glBegin(GL_POLYGON);
        glVertex2f(-4.65, -1.08);
        glVertex2f(-5.61, -3.09);
        glVertex2f(-6.6, -3.09);
        glVertex2f(-5.75, -1.08);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(4.65, -1.08);
        glVertex2f(3.69, -3.09);
        glVertex2f(2.7, -3.09);
        glVertex2f(3.55, -1.08);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(4.48, -2.65);
        glVertex2f(4.32, -3.65);
        glVertex2f(-7.91, -3.65);
        glVertex2f(-7.34, -2.65);
    glEnd();

}

void allPeople(){

    glPushMatrix();
    glTranslatef(39, 25, 0);
    People(90);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(31, 25, 0);
    People(90);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(38+56, -25, 0);
    People(-90);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(32+54, -25, 0);
    People(-90);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-44, 25, 0);
    People(90);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-35, 25, 0);
    People(90);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-43-42, -25, 0);
    People(-90);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-36-41, -25, 0);
    People(-90);
    glPopMatrix();

}
