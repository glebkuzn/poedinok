#ifndef AREA_H_INCLUDED
#define AREA_H_INCLUDED

void draw_blackArea()
{
// glPushMatrix();
//glTranslatef(1.5f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glTranslatef(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(1.50f,0.0f,0.0f);
    glVertex3f(1.5f,0.3f,0.0f);
    glVertex3f(0.0f,0.3f,0.0f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,-1.5f);
    glVertex3f(0.0f,0.3f,-1.5f);
    glVertex3f(0.0f,0.3f,0.0f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glEnd();
    glVertex3f(1.5f,0.0f,-1.5f);
    glVertex3f(1.5f,0.0f,0.0f);
    glVertex3f(1.5f,0.3f,-1.5f);
    glVertex3f(1.5f,0.3f,0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glVertex3f(0.0f,0.0f,-1.5f);
    glVertex3f(1.50f,0.0f,-1.5f);
    glVertex3f(1.5f,0.3f,-1.5f);
    glVertex3f(0.0f,0.3f,-1.5f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(1.50f,0.0f,0.0f);
    glVertex3f(1.5f,0.0f,-1.5f);
    glVertex3f(0.0f,0.0f,-1.5f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.3f,0.0f);
    glVertex3f(1.50f,0.3f,0.0f);
    glVertex3f(1.5f,0.3f,-1.5f);
    glVertex3f(0.0f,0.3f,-1.5f);
    glEnd();
//    glPopMatrix();

}
void draw_whiteArea()
{
// glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glTranslatef(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(1.50f,0.0f,0.0f);
    glVertex3f(1.5f,0.3f,0.0f);
    glVertex3f(0.0f,0.3f,0.0f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,-1.5f);
    glVertex3f(0.0f,0.3f,-1.5f);
    glVertex3f(0.0f,0.3f,0.0f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glVertex3f(1.5f,0.0f,0.0f);
    glVertex3f(1.5f,0.0f,-1.5f);
    glVertex3f(1.5f,0.3f,-1.5f);
    glVertex3f(1.5f,0.3f,0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glVertex3f(0.0f,0.0f,-1.5f);
    glVertex3f(1.50f,0.0f,-1.5f);
    glVertex3f(1.5f,0.3f,-1.5f);
    glVertex3f(0.0f,0.3f,-1.5f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.05f,0.05f,0.05f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(1.50f,0.0f,0.0f);
    glVertex3f(1.5f,0.0f,-1.5f);
    glVertex3f(0.0f,0.0f,-1.5f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f(0.0f,0.3f,0.0f);
    glVertex3f(1.50f,0.3f,0.0f);
    glVertex3f(1.5f,0.3f,-1.5f);
    glVertex3f(0.0f,0.3f,-1.5f);
    glEnd();
// glPopMatrix();

}

void draw_cursor()
{
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
        glVertex3f(0.15,2.70, 0.15);
        glVertex3f(-0.15,2.70, 0.15);
        glVertex3f(-0.15, 2.70, -0.15);
        glVertex3f(0.15, 2.70, -0.15);
    glEnd();
}

void draw_togo()
{
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
        glVertex3f(0.15,2.70, 0.15);
        glVertex3f(-0.15,2.70, 0.15);
        glVertex3f(-0.15, 2.70, -0.15);
        glVertex3f(0.15, 2.70, -0.15);
    glEnd();
}

void draw_step()
{
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
        glVertex3f(0.15,2.70, 0.15);
        glVertex3f(-0.15,2.70, 0.15);
        glVertex3f(-0.15, 2.70, -0.15);
        glVertex3f(0.15, 2.70, -0.15);
    glEnd();
}

#endif // AREA_H_INCLUDED
