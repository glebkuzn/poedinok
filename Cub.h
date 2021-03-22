#ifndef CUB_H_INCLUDED
#define CUB_H_INCLUDED
void draw_blackcub()
{
    float X[]={0.2,0,0};
    float A[]={1,0.7,0.8};
    {
        glBegin(GL_QUADS); //cube!!!
        glColor3fv(X);
        glVertex3f(0.69, 0.69, 0.69);
        glVertex3f(-0.69, 0.69, 0.69);
        glVertex3f(-0.69, -0.69, 0.69);
        glVertex3f(0.69, -0.69, 0.69);

        glColor3fv(A);
        glVertex3f(0.15, 0.15, 0.70);
        glVertex3f(-0.15, 0.15, 0.70);
        glVertex3f(-0.15, -0.15, 0.70);
        glVertex3f(0.15, -0.15, 0.70);
// 1

        glColor3fv(X);
        glVertex3f(0.69, 0.69, -0.69);
        glVertex3f(-0.69, 0.69, -0.69);
        glVertex3f(-0.69, -0.69, -0.69);
        glVertex3f(0.69, -0.69, -0.69);

        glColor3fv(A);
        glVertex3f(0.15, 0.15, -0.70);
        glVertex3f(0.45, 0.15, -0.70);
        glVertex3f(0.45, -0.15, -0.70);
        glVertex3f(0.15, -0.15, -0.70);

        glColor3fv(A);
        glVertex3f(-0.15, -0.15, -0.70);
        glVertex3f(-0.45, -0.15, -0.70);
        glVertex3f(-0.45, 0.15, -0.70);
        glVertex3f(-0.15, 0.15, -0.70);

        glColor3fv(A);
        glVertex3f(0.15, 0.3, -0.70);
        glVertex3f(0.45, 0.3, -0.70);
        glVertex3f(0.45, 0.6, -0.70);
        glVertex3f(0.15, 0.6, -0.70);

        glColor3fv(A);
        glVertex3f(-0.15, -0.3, -0.70);
        glVertex3f(-0.45, -0.3, -0.70);
        glVertex3f(-0.45, -0.6, -0.70);
        glVertex3f(-0.15, -0.6, -0.70);

        glColor3fv(A);
        glVertex3f(-0.15, 0.3, -0.70);
        glVertex3f(-0.45, 0.3, -0.70);
        glVertex3f(-0.45, 0.6, -0.70);
        glVertex3f(-0.15, 0.6, -0.70);

        glColor3fv(A);
        glVertex3f(0.15, -0.3, -0.70);
        glVertex3f(0.45, -0.3, -0.70);
        glVertex3f(0.45, -0.6, -0.70);
        glVertex3f(0.15, -0.6, -0.70);
//6


        glColor3fv(X);
        glVertex3f(0.69, 0.69, -0.69);
        glVertex3f(-0.69, 0.69, -0.69);
        glVertex3f(-0.69, 0.69, 0.69);
        glVertex3f(0.69, 0.69, 0.69);

        glColor3fv(A);
        glVertex3f(0.3, 0.70, 0.3);
        glVertex3f(0.3, 0.70, 0.6);
        glVertex3f(0.6, 0.70, 0.6);
        glVertex3f(0.6, 0.70, 0.3);

        glColor3fv(A);
        glVertex3f(-0.3, 0.70, -0.3);
        glVertex3f(-0.3, 0.70, -0.6);
        glVertex3f(-0.6, 0.70, -0.6);
        glVertex3f(-0.6, 0.70, -0.3);
//2

        glColor3fv(X);
        glVertex3f(0.69, -0.69, -0.69);
        glVertex3f(-0.69, -0.69, -0.69);
        glVertex3f(-0.69, -0.69, 0.69);
        glVertex3f(0.69, -0.69, 0.69);

        glColor3fv(A);
        glVertex3f(0.15, -0.70, -0.15);
        glVertex3f(-0.15, -0.70, -0.15);
        glVertex3f(-0.15, -0.70, 0.15);
        glVertex3f(0.15, -0.70, 0.15);


        glColor3fv(A);
        glVertex3f(0.3, -0.70, 0.3);
        glVertex3f(0.6, -0.70, 0.3);
        glVertex3f(0.6, -0.70, 0.6);
        glVertex3f(0.3, -0.70, 0.6);

        glColor3fv(A);
        glVertex3f(-0.3, -0.70, -0.3);
        glVertex3f(-0.6, -0.70, -0.3);
        glVertex3f(-0.6, -0.70, -0.6);
        glVertex3f(-0.3, -0.70, -0.6);

        glColor3fv(A);
        glVertex3f(-0.3, -0.70, 0.3);
        glVertex3f(-0.6, -0.70, 0.3);
        glVertex3f(-0.6, -0.70, 0.6);
        glVertex3f(-0.3, -0.70, 0.6);

        glColor3fv(A);
        glVertex3f(0.3, -0.70, -0.3);
        glVertex3f(0.6, -0.70, -0.3);
        glVertex3f(0.6, -0.70, -0.6);
        glVertex3f(0.3, -0.70, -0.6);
//5

        glColor3fv(X);
        glVertex3f(-0.69, 0.69, -0.69);
        glVertex3f(-0.69, -0.69, -0.69);
        glVertex3f(-0.69, -0.69, 0.69);
        glVertex3f(-0.69, 0.69, 0.69);


        glColor3fv(A);
        glVertex3f(-0.70, 0.15, -0.15);
        glVertex3f(-0.70, -0.15, -0.15);
        glVertex3f(-0.70, -0.15, 0.15);
        glVertex3f(-0.70, 0.15, 0.15);

        glColor3fv(A);
        glVertex3f(-0.70,0.3,  0.3);
        glVertex3f(-0.70,0.3,  0.6);
        glVertex3f(-0.70, 0.6, 0.6);
        glVertex3f(-0.70, 0.6, 0.3);

        glColor3fv(A);
        glVertex3f(-0.70, -0.3, -0.3);
        glVertex3f(-0.70, -0.3, -0.6);
        glVertex3f(-0.70, -0.6, -0.6);
        glVertex3f(-0.70, -0.6, -0.3);
//3

        glColor3fv(X);
        glVertex3f(0.69, 0.69, -0.69);
        glVertex3f(0.69, -0.69, -0.69);
        glVertex3f(0.69, -0.69, 0.69);
        glVertex3f(0.69, 0.69, 0.69);

        glColor3fv(A);
        glVertex3f(0.70, 0.3, 0.3);
        glVertex3f(0.70, 0.3, 0.6);
        glVertex3f(0.70, 0.6, 0.6);
        glVertex3f(0.70, 0.6, 0.3);


        glColor3fv(A);
        glVertex3f(0.70, -0.3, 0.3);
        glVertex3f(0.70, -0.3, 0.6);
        glVertex3f(0.70, -0.6, 0.6);
        glVertex3f(0.70, -0.6, 0.3);


        glColor3fv(A);
        glVertex3f(0.70, 0.3, -0.3);
        glVertex3f(0.70, 0.3, -0.6);
        glVertex3f(0.70, 0.6, -0.6);
        glVertex3f(0.70, 0.6, -0.3);


        glColor3fv(A);
        glVertex3f(0.70, -0.3, -0.3);
        glVertex3f(0.70, -0.3, -0.6);
        glVertex3f(0.70, -0.6, -0.6);
        glVertex3f(0.70, -0.6, -0.3);
//4

        glEnd();
    }
}
void draw_blackking()
{
    float X[]={0.2,0,0};
    {
        glBegin(GL_QUADS); //cube!!!
        glColor3fv(X);
        glVertex3f(0.69, 0.69, 0.69);
        glVertex3f(-0.69, 0.69, 0.69);
        glVertex3f(-0.69, -0.69, 0.69);
        glVertex3f(0.69, -0.69, 0.69);


        glColor3fv(X);
        glVertex3f(0.69, 0.69, -0.69);
        glVertex3f(-0.69, 0.69, -0.69);
        glVertex3f(-0.69, -0.69, -0.69);
        glVertex3f(0.69, -0.69, -0.69);

        glColor3fv(X);
        glVertex3f(0.69, 0.69, -0.69);
        glVertex3f(-0.69, 0.69, -0.69);
        glVertex3f(-0.69, 0.69, 0.69);
        glVertex3f(0.69, 0.69, 0.69);

        glColor3fv(X);
        glVertex3f(0.69, -0.69, -0.69);
        glVertex3f(-0.69, -0.69, -0.69);
        glVertex3f(-0.69, -0.69, 0.69);
        glVertex3f(0.69, -0.69, 0.69);

        glColor3fv(X);
        glVertex3f(-0.69, 0.69, -0.69);
        glVertex3f(-0.69, -0.69, -0.69);
        glVertex3f(-0.69, -0.69, 0.69);
        glVertex3f(-0.69, 0.69, 0.69);

        glColor3fv(X);
        glVertex3f(0.69, 0.69, -0.69);
        glVertex3f(0.69, -0.69, -0.69);
        glVertex3f(0.69, -0.69, 0.69);
        glVertex3f(0.69, 0.69, 0.69);


        glEnd();
    }
}

void draw_whitecub()
{
    float A[]={0.5,0,0.5};
    float X[]={0.8,1,0.4};
    {
        glBegin(GL_QUADS); //cube!!!
        glColor3fv(X);
        glVertex3f(0.69, 0.69, 0.69);
        glVertex3f(-0.69, 0.69, 0.69);
        glVertex3f(-0.69, -0.69, 0.69);
        glVertex3f(0.69, -0.69, 0.69);

        glColor3fv(A);
        glVertex3f(0.15, 0.15, 0.70);
        glVertex3f(-0.15, 0.15, 0.70);
        glVertex3f(-0.15, -0.15, 0.70);
        glVertex3f(0.15, -0.15, 0.70);
// 1

        glColor3fv(X);
        glVertex3f(0.69, 0.69, -0.69);
        glVertex3f(-0.69, 0.69, -0.69);
        glVertex3f(-0.69, -0.69, -0.69);
        glVertex3f(0.69, -0.69, -0.69);

        glColor3fv(A);
        glVertex3f(0.15, 0.15, -0.70);
        glVertex3f(0.45, 0.15, -0.70);
        glVertex3f(0.45, -0.15, -0.70);
        glVertex3f(0.15, -0.15, -0.70);

        glColor3fv(A);
        glVertex3f(-0.15, -0.15, -0.70);
        glVertex3f(-0.45, -0.15, -0.70);
        glVertex3f(-0.45, 0.15, -0.70);
        glVertex3f(-0.15, 0.15, -0.70);

        glColor3fv(A);
        glVertex3f(0.15, 0.3, -0.70);
        glVertex3f(0.45, 0.3, -0.70);
        glVertex3f(0.45, 0.6, -0.70);
        glVertex3f(0.15, 0.6, -0.70);

        glColor3fv(A);
        glVertex3f(-0.15, -0.3, -0.70);
        glVertex3f(-0.45, -0.3, -0.70);
        glVertex3f(-0.45, -0.6, -0.70);
        glVertex3f(-0.15, -0.6, -0.70);

        glColor3fv(A);
        glVertex3f(-0.15, 0.3, -0.70);
        glVertex3f(-0.45, 0.3, -0.70);
        glVertex3f(-0.45, 0.6, -0.70);
        glVertex3f(-0.15, 0.6, -0.70);

        glColor3fv(A);
        glVertex3f(0.15, -0.3, -0.70);
        glVertex3f(0.45, -0.3, -0.70);
        glVertex3f(0.45, -0.6, -0.70);
        glVertex3f(0.15, -0.6, -0.70);
//6


        glColor3fv(X);
        glVertex3f(0.69, 0.69, -0.69);
        glVertex3f(-0.69, 0.69, -0.69);
        glVertex3f(-0.69, 0.69, 0.69);
        glVertex3f(0.69, 0.69, 0.69);

        glColor3fv(A);
        glVertex3f(0.3, 0.70, 0.3);
        glVertex3f(0.3, 0.70, 0.6);
        glVertex3f(0.6, 0.70, 0.6);
        glVertex3f(0.6, 0.70, 0.3);

        glColor3fv(A);
        glVertex3f(-0.3, 0.70, -0.3);
        glVertex3f(-0.3, 0.70, -0.6);
        glVertex3f(-0.6, 0.70, -0.6);
        glVertex3f(-0.6, 0.70, -0.3);
//2

        glColor3fv(X);
        glVertex3f(0.69, -0.69, -0.69);
        glVertex3f(-0.69, -0.69, -0.69);
        glVertex3f(-0.69, -0.69, 0.69);
        glVertex3f(0.69, -0.69, 0.69);

        glColor3fv(A);
        glVertex3f(0.15, -0.70, -0.15);
        glVertex3f(-0.15, -0.70, -0.15);
        glVertex3f(-0.15, -0.70, 0.15);
        glVertex3f(0.15, -0.70, 0.15);


        glColor3fv(A);
        glVertex3f(0.3, -0.70, 0.3);
        glVertex3f(0.6, -0.70, 0.3);
        glVertex3f(0.6, -0.70, 0.6);
        glVertex3f(0.3, -0.70, 0.6);

        glColor3fv(A);
        glVertex3f(-0.3, -0.70, -0.3);
        glVertex3f(-0.6, -0.70, -0.3);
        glVertex3f(-0.6, -0.70, -0.6);
        glVertex3f(-0.3, -0.70, -0.6);

        glColor3fv(A);
        glVertex3f(-0.3, -0.70, 0.3);
        glVertex3f(-0.6, -0.70, 0.3);
        glVertex3f(-0.6, -0.70, 0.6);
        glVertex3f(-0.3, -0.70, 0.6);

        glColor3fv(A);
        glVertex3f(0.3, -0.70, -0.3);
        glVertex3f(0.6, -0.70, -0.3);
        glVertex3f(0.6, -0.70, -0.6);
        glVertex3f(0.3, -0.70, -0.6);
//5

        glColor3fv(X);
        glVertex3f(-0.69, 0.69, -0.69);
        glVertex3f(-0.69, -0.69, -0.69);
        glVertex3f(-0.69, -0.69, 0.69);
        glVertex3f(-0.69, 0.69, 0.69);


        glColor3fv(A);
        glVertex3f(-0.70, 0.15, -0.15);
        glVertex3f(-0.70, -0.15, -0.15);
        glVertex3f(-0.70, -0.15, 0.15);
        glVertex3f(-0.70, 0.15, 0.15);

        glColor3fv(A);
        glVertex3f(-0.70,0.3,  0.3);
        glVertex3f(-0.70,0.3,  0.6);
        glVertex3f(-0.70, 0.6, 0.6);
        glVertex3f(-0.70, 0.6, 0.3);

        glColor3fv(A);
        glVertex3f(-0.70, -0.3, -0.3);
        glVertex3f(-0.70, -0.3, -0.6);
        glVertex3f(-0.70, -0.6, -0.6);
        glVertex3f(-0.70, -0.6, -0.3);
//3

        glColor3fv(X);
        glVertex3f(0.69, 0.69, -0.69);
        glVertex3f(0.69, -0.69, -0.69);
        glVertex3f(0.69, -0.69, 0.69);
        glVertex3f(0.69, 0.69, 0.69);

        glColor3fv(A);
        glVertex3f(0.70, 0.3, 0.3);
        glVertex3f(0.70, 0.3, 0.6);
        glVertex3f(0.70, 0.6, 0.6);
        glVertex3f(0.70, 0.6, 0.3);


        glColor3fv(A);
        glVertex3f(0.70, -0.3, 0.3);
        glVertex3f(0.70, -0.3, 0.6);
        glVertex3f(0.70, -0.6, 0.6);
        glVertex3f(0.70, -0.6, 0.3);


        glColor3fv(A);
        glVertex3f(0.70, 0.3, -0.3);
        glVertex3f(0.70, 0.3, -0.6);
        glVertex3f(0.70, 0.6, -0.6);
        glVertex3f(0.70, 0.6, -0.3);


        glColor3fv(A);
        glVertex3f(0.70, -0.3, -0.3);
        glVertex3f(0.70, -0.3, -0.6);
        glVertex3f(0.70, -0.6, -0.6);
        glVertex3f(0.70, -0.6, -0.3);
//4

        glEnd();
    }
}

void draw_whiteking()
{
    float X[]={0.8,1,0.4};
    {
        glBegin(GL_QUADS); //cube!!!
        glColor3fv(X);
        glVertex3f(0.69, 0.69, 0.69);
        glVertex3f(-0.69, 0.69, 0.69);
        glVertex3f(-0.69, -0.69, 0.69);
        glVertex3f(0.69, -0.69, 0.69);

        glColor3fv(X);
        glVertex3f(0.69, 0.69, -0.69);
        glVertex3f(-0.69, 0.69, -0.69);
        glVertex3f(-0.69, -0.69, -0.69);
        glVertex3f(0.69, -0.69, -0.69);

        glColor3fv(X);
        glVertex3f(0.69, 0.69, -0.69);
        glVertex3f(-0.69, 0.69, -0.69);
        glVertex3f(-0.69, 0.69, 0.69);
        glVertex3f(0.69, 0.69, 0.69);

        glColor3fv(X);
        glVertex3f(0.69, -0.69, -0.69);
        glVertex3f(-0.69, -0.69, -0.69);
        glVertex3f(-0.69, -0.69, 0.69);
        glVertex3f(0.69, -0.69, 0.69);

        glColor3fv(X);
        glVertex3f(-0.69, 0.69, -0.69);
        glVertex3f(-0.69, -0.69, -0.69);
        glVertex3f(-0.69, -0.69, 0.69);
        glVertex3f(-0.69, 0.69, 0.69);

        glColor3fv(X);
        glVertex3f(0.69, 0.69, -0.69);
        glVertex3f(0.69, -0.69, -0.69);
        glVertex3f(0.69, -0.69, 0.69);
        glVertex3f(0.69, 0.69, 0.69);


        glEnd();
    }
}


#endif // CUB_H_INCLUDED
