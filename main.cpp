#include<windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "Cub.h"
#include "Move.h"
#include "Area.h"

void draw_blackcub();
void draw_whitecub();
using namespace std;
float White[3]= {0.9,1,0.9};
float Black[3]= {0.1,0,0.2};
int is_win = 0,wmove=1;
int cursor_place=15, step_place=0, end_place=0;
cub A[10],B[10];
GLuint _displayListId_blackArea;
GLuint _displayListId_whiteArea;
GLuint _displayListId_whitecub;
GLuint _displayListId_blackcub;
GLuint _displayListId_blackking;
GLuint _displayListId_whiteking;
GLuint _displayListId_cursor;
GLuint _displayListId_togo;
GLuint _displayListId_step;
int num=4;
int is_pressed=0;
int Places_to_move[16];
int iter=0;
void esc(unsigned char key,int x,int y)
{
    switch(key)
    {
    case 27:
        exit(0);
    }
    if(wmove==0)
    {

    switch(key)
    {
    case 'w':
        if(cursor_place>19)
            cursor_place-=10;
        break;
    case 's':
        if(cursor_place<90)
            cursor_place+=10;
        break;
    case 'd':
        if(cursor_place%10>1)
            cursor_place--;
        break;
    case 'a':
        if(cursor_place%10<9)
            cursor_place++;
        break;
    }}
}

void handleKeypress(int key,int x,int y)
{
    //enter start
    if(wmove==1)
    {if(key==GLUT_KEY_F12)
    {
        for(int i = 0; i < 9; i++)
        {
            if((A[i].place==cursor_place)&&(wmove==1))
            {
                num=i;
                if(is_pressed==1)
                    is_pressed=0;
                else
                    is_pressed=1;
            }
            if((B[i].place==cursor_place)&&(wmove==0))
            {
                num=i;
                if(is_pressed==1)
                    is_pressed=0;
                else
                    is_pressed=1;
            }
        }
    }
    if(key==GLUT_KEY_F11)
    {
        step_place=cursor_place;
    }
    if(key==GLUT_KEY_F10)
    {
        end_place=cursor_place;
    }
    //enter cursor
    switch(key)
    {
    case GLUT_KEY_DOWN:
        if(cursor_place>19)
            cursor_place-=10;
        break;
    case GLUT_KEY_UP:
        if(cursor_place<90)
            cursor_place+=10;
        break;
    case GLUT_KEY_LEFT:
        if(cursor_place%10>1)
            cursor_place--;
        break;
    case GLUT_KEY_RIGHT:
        if(cursor_place%10<9)
            cursor_place++;
        break;
    }
}
    if(wmove==0)
    {if(key==GLUT_KEY_F1)
    {
        for(int i = 0; i < 9; i++)
        {
            if((A[i].place==cursor_place)&&(wmove==1))
            {
                num=i;
                if(is_pressed==1)
                    {is_pressed=0;step_place=0;}
                else
                    is_pressed=1;
            }
            if((B[i].place==cursor_place)&&(wmove==0))
            {
                num=i;
                if(is_pressed==1)
                    {is_pressed=0;step_place=0;}
                else
                    is_pressed=1;
            }
        }
    }
    if(key==GLUT_KEY_F2)
    {
        step_place=cursor_place;
    }
    if(key==GLUT_KEY_F3)
    {
        end_place=cursor_place;
    }
    //enter cursor

}
    key=0;
}

void initRendering()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(0.0f,0.0f,0.2f,1.0f);

    _displayListId_blackArea = glGenLists(1); //комната для отображения
    glNewList(_displayListId_blackArea, GL_COMPILE); //начало отображения
    draw_blackArea(); //для рисования черных клеточек
    glEndList(); //конец отображения


    _displayListId_whiteArea = glGenLists(2); //создание комнтаы
    glNewList(_displayListId_whiteArea, GL_COMPILE); //начало
    draw_whiteArea(); //для рисования белых
    glEndList(); //конец

    _displayListId_blackcub = glGenLists(3);
    glNewList(_displayListId_blackcub, GL_COMPILE);
    draw_blackcub();
    glEndList();


    _displayListId_whitecub = glGenLists(4); //создание комнтаы
    glNewList(_displayListId_whitecub, GL_COMPILE); //начало
    draw_whitecub();
    glEndList(); //конец

    _displayListId_blackking = glGenLists(5); //комната для отображения
    glNewList(_displayListId_blackking, GL_COMPILE); //начало отображения
    draw_blackking();
    glEndList(); //конец отображения


    _displayListId_whiteking = glGenLists(6); //создание комнтаы
    glNewList(_displayListId_whiteking, GL_COMPILE); //начало
    draw_whiteking();
    glEndList(); //конец

    _displayListId_cursor = glGenLists(7); //создание комнтаы
    glNewList(_displayListId_cursor, GL_COMPILE); //начало
    draw_cursor();
    glEndList(); //конец

    _displayListId_togo = glGenLists(7); //создание комнтаы
    glNewList(_displayListId_togo, GL_COMPILE); //начало
    draw_togo();
    glEndList();

    _displayListId_step = glGenLists(7); //создание комнтаы
    glNewList(_displayListId_step, GL_COMPILE); //начало
    draw_step();
    glEndList();
}

void handleResize(int w,int h)//изменять обзор
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(56.0,(double)w/(double)h,1.0,300);
    gluLookAt(-1.0f,5.5f, 15.0f,
              0.0f,0.0f,0.0f,
              0.0f,1.0f,0.0f);

}
void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(-90, 0, 1.0f, 0.0f);
    glRotatef(180*wmove, 0, 1.0f, 0.0f);
    glRotatef(30, 0, 0.0f, 1.0f);
    glRotatef(-60*(1-wmove), 0, 0, 1.0f);

    glTranslatef(-3*1.5, 0.0, 6.5);
//draw field
    for(int i=10; i<99; i++)
    {
        if(i%10==9)
            i++;
        if((i%2+i/10%2)==1)
        {
            glPushMatrix();
            glTranslatef(-3+i/10*1.5,0.0,-i%10*1.5);
            glCallList(_displayListId_blackArea);
            glPopMatrix();
        }
        else
        {
            glPushMatrix();
            glTranslatef(-3+i/10*1.5,0.0,-i%10*1.5);
            glCallList(_displayListId_whiteArea);
            glPopMatrix();
        }
    }
//draw cubes
    for(int i=0; i<9; i++)
    {
        if(i==4)//kings draw
        {
            glPushMatrix();
            glTranslatef(-3+B[i].place/10*1.5+0.75,1.05,B[i].place%10*1.5-19*0.75);
            glCallList(_displayListId_blackking);
            glPopMatrix();
            glPushMatrix();
            glTranslatef(-3+A[i].place/10*1.5+0.75,1.05,A[i].place%10*1.5-19*0.75);
            glCallList(_displayListId_whiteking);
            glPopMatrix();
            i++;
        }
        if(B[i].place!=0)
        {glPushMatrix();//black draw
        glTranslatef(-3+B[i].place/10*1.5+0.75,1.05,B[i].place%10*1.5-19*0.75);
        rotation(B[i]);
        glCallList(_displayListId_blackcub);
        glPopMatrix();}

        if(A[i].place!=0)
        {glPushMatrix();//white draw
        glTranslatef(-2.25+A[i].place/10*1.5,1.05,A[i].place%10*1.5-19*0.75);
        rotation(A[i]);
        glCallList(_displayListId_whitecub);
        glPopMatrix();}
    }
    //cursor
    if(wmove==1)
    {
        if(is_pressed==0)
        {
            glPushMatrix();
            glTranslatef(-3+cursor_place/10*1.5+0.75,-2.3,cursor_place%10*1.5-19*0.75);
            glCallList(_displayListId_cursor);
            glPopMatrix();

            for(int i = 0; i < 9; i++)
            {
                if(A[i].place == cursor_place)
                {
                    num=i;
                    {
                    glPushMatrix();
                    glTranslatef(-3+cursor_place/10*1.5+0.75,-.5,cursor_place%10*1.5-19*0.75);
                    glCallList(_displayListId_cursor);
                    glPopMatrix();
//possible move
                    iter=0;
                    for(int k = 11; k < 100; k++)
                    {
                        int flag = 1, p=cursor_place;
                        if(k%10==0)
                        {
                            k++;
                        }
                        if(abs(p%10-k%10) + abs(p/10-k/10) != A[num].top)
                        {
                            flag = 0;
                        }
                        else
                        {
                            int hor = 1;
                            int ver = 1;
                            //prove possibility vertical
                            if(vmove(p, k/10*10+p%10, A, B)*hmove(k/10*10+p%10, k, A, B) == 0)
                                ver = 0;
                            //prove possibility horisontal
                            if(vmove((p/10)*10+k%10, k, A, B)*hmove(p, (p/10)*10+k%10, A, B) == 0)
                                hor = 0;

                            //is just vertical
                            if(p/10-k/10 == 0)
                            {
                                ver = 0;
                            }
                            //is just horisontal
                            else if(p%10-k%10 == 0)
                            {
                                hor = 0;
                            }
                            if(ver+hor == 0)
                                flag = 0;
                            if(flag == 1)
                            {
                                Places_to_move[iter]=k;
                                iter++;
                            }
                        }
                    }

                    //draw possible places
                    for(int i=0; i<iter; i++)
                    {
                        glPushMatrix();
                        glTranslatef(-3+Places_to_move[i]/10*1.5+0.75,-2.3,Places_to_move[i]%10*1.5-19*0.75);
                        glCallList(_displayListId_togo);
                        glPopMatrix();
                        for(int j = 0; j < 9; j++)
                        {
                            //draw places to eat cube
                            int g=0;
                            if((A[j].place == Places_to_move[i]))
                                g=1;
                            if((B[j].place == Places_to_move[i]))
                                g=1;
                            if(g==1)
                            {
                                glPushMatrix();
                                glTranslatef(-3+Places_to_move[i]/10*1.5+0.75,-.5,Places_to_move[i]%10*1.5-19*0.75);
                                glCallList(_displayListId_togo);
                                glPopMatrix();
                            }
                        }

                    }
                }


                }
                if(B[i].place == cursor_place)
                {
                    num=i;
                    {
                    glPushMatrix();
                    glTranslatef(-3+cursor_place/10*1.5+0.75,-.5,cursor_place%10*1.5-19*0.75);
                    glCallList(_displayListId_cursor);
                    glPopMatrix();
//possible move
                    iter=0;
                    for(int k = 11; k < 100; k++)
                    {
                        int flag = 1, p=cursor_place;
                        if(k%10==0)
                        {
                            k++;
                        }
                        if(abs(p%10-k%10) + abs(p/10-k/10) != B[num].top)
                        {
                            flag = 0;
                        }
                        else
                        {
                            int hor = 1;
                            int ver = 1;
                            //prove possibility vertical
                            if(vmove(p, k/10*10+p%10, B, A)*hmove(k/10*10+p%10, k, B, A) == 0)
                                ver = 0;
                            //prove possibility horisontal
                            if(vmove((p/10)*10+k%10, k, B, A)*hmove(p, (p/10)*10+k%10, B, A) == 0)
                                hor = 0;

                            //is just vertical
                            if(p/10-k/10 == 0)
                            {
                                ver = 0;
                            }
                            //is just horisontal
                            else if(p%10-k%10 == 0)
                            {
                                hor = 0;
                            }
                            if(ver+hor == 0)
                                flag = 0;
                            if(flag == 1)
                            {
                                Places_to_move[iter]=k;
                                iter++;
                            }
                        }
                    }

                    //draw possible places
                    for(int i=0; i<iter; i++)
                    {
                        glPushMatrix();
                        glTranslatef(-3+Places_to_move[i]/10*1.5+0.75,-2.3,Places_to_move[i]%10*1.5-19*0.75);
                        glCallList(_displayListId_togo);
                        glPopMatrix();
                        for(int j = 0; j < 9; j++)
                        {
                            //draw places to eat cube
                            int g=0;
                            if((A[j].place == Places_to_move[i]))
                                g=1;
                            if((B[j].place == Places_to_move[i]))
                                g=1;
                            if(g==1)
                            {
                                glPushMatrix();
                                glTranslatef(-3+Places_to_move[i]/10*1.5+0.75,-.5,Places_to_move[i]%10*1.5-19*0.75);
                                glCallList(_displayListId_togo);
                                glPopMatrix();
                            }
                        }

                    }
                }

                }

                }
        }
        //show future condition
        if(is_pressed==1)
        {
            glPushMatrix();
            glTranslatef(-3+cursor_place/10*1.5+0.75,-2.3,cursor_place%10*1.5-19*0.75);
            glCallList(_displayListId_step);
            glPopMatrix();
            //draw shades of future cubes
            //1 verticsl move
            if(step_place%10-A[num].place%10==0)
                for(int i=0; i<iter; i++)
                {
                    if(step_place/10-Places_to_move[i]/10==0)
                    {
                        {
                            //copy to buffer

                            A[9].botton = A[num].botton;
                            A[9].down = A[num].down;
                            A[9].up = A[num].up;
                            A[9].left = A[num].left;
                            A[9].right = A[num].right;
                            A[9].top = A[num].top;
                            A[9].place = A[num].place;
                            int lon=A[9].place%10-Places_to_move[i]%10;
                            int high=-A[9].place/10+Places_to_move[i]/10;
                            if(high>0)
                                for(int j=0; j<high; j++) A[9].move_up();
                            else
                                for(int j=0; j<-high; j++) A[9].move_down();
                            if(lon>0)
                                for(int j=0; j<lon; j++) A[9].move_left();
                            else
                                for(int j=0; j<-lon; j++) A[9].move_right();
                            if(num!=4)
                            {
                                glPushMatrix();//white draw
                                glTranslatef(-2.25+A[9].place/10*1.5,1.5,A[9].place%10*1.5-19*0.75);
                                //rotation
                                rotation(A[9]);
                                glCallList(_displayListId_whitecub);
                                glPopMatrix();
                            }
                            else
                            {
                                glPushMatrix();//white draw
                                glTranslatef(-2.25+A[9].place/10*1.5,1.5,A[9].place%10*1.5-19*0.75);
                                //rotation
                                rotation(A[9]);
                                glCallList(_displayListId_whiteking);
                                glPopMatrix();
                            }
                        }
                        if(end_place==Places_to_move[i])
                        {
                            int lon=A[num].place%10-end_place%10;
                            int high=-A[num].place/10+end_place/10;
                            if(high>0)
                                for(int j=0; j<high; j++) A[num].move_up();
                            else
                                for(int j=0; j<-high; j++) A[num].move_down();
                            if(lon>0)
                                for(int j=0; j<lon; j++) A[num].move_left();
                            else
                                for(int j=0; j<-lon; j++) A[num].move_right();
                            for(int o=0; o<9; o++)
                                if(B[o].place==end_place)
                                    B[o].place=0;
                            //prove of win
                            if(B[4].place==0||A[4].place==95)
                            {
                                cout <<"White won! Congratulations!";
                                exit(0);
                            }

                            is_pressed=0;
                            end_place=0;
                            step_place=0;
                            wmove=0;

                        }
                    }
                }
            //1 horisontal move
            if(step_place/10-A[num].place/10==0)
                for(int i=0; i<iter; i++)
                {
                    if(step_place%10-Places_to_move[i]%10==0)
                    {
                        {
                            //copy to buffer

                            A[9].botton = A[num].botton;
                            A[9].down = A[num].down;
                            A[9].up = A[num].up;
                            A[9].left = A[num].left;
                            A[9].right = A[num].right;
                            A[9].top = A[num].top;
                            A[9].place = A[num].place;
                            int lon=A[9].place%10-Places_to_move[i]%10;
                            int high=-A[9].place/10+Places_to_move[i]/10;
                            if(lon>0)
                                for(int j=0; j<lon; j++) A[9].move_left();
                            else
                                for(int j=0; j<-lon; j++) A[9].move_right();
                            if(high>0)
                                for(int j=0; j<high; j++) A[9].move_up();
                            else
                                for(int j=0; j<-high; j++) A[9].move_down();
                            if(num!=4)
                            {
                                glPushMatrix();//white draw
                                glTranslatef(-2.25+A[9].place/10*1.5,1.5,A[9].place%10*1.5-19*0.75);
                                //rotation
                                rotation(A[9]);
                                glCallList(_displayListId_whitecub);
                                glPopMatrix();
                            }
                            else
                            {
                                glPushMatrix();//white draw
                                glTranslatef(-2.25+A[9].place/10*1.5,1.5,A[9].place%10*1.5-19*0.75);
                                //rotation
                                rotation(A[9]);
                                glCallList(_displayListId_whiteking);
                                glPopMatrix();
                            }
                            if(end_place==Places_to_move[i])
                            {
                                int lon=A[num].place%10-end_place%10;
                                int high=-A[num].place/10+end_place/10;
                                if(lon>0)
                                    for(int j=0; j<lon; j++) A[num].move_left();
                                else
                                    for(int j=0; j<-lon; j++) A[num].move_right();
                                if(high>0)
                                    for(int j=0; j<high; j++) A[num].move_up();
                                else
                                    for(int j=0; j<-high; j++) A[num].move_down();
                                for(int o=0; o<9; o++)
                                    if(B[o].place==end_place)
                                        B[o].place=0;
                                //prove of win
                                if(B[4].place==0||A[4].place==95)
                                {
                                cout <<"White won! Congratulations!";
                                    exit(0);
                                }

                                is_pressed=0;
                                end_place=0;
                                step_place=0;
                                wmove=0;
                            }
                        }
                    }
                }
        }
    }
    if(wmove==0)
    {
        if(is_pressed==0)
        {
            glPushMatrix();
            glTranslatef(-3+cursor_place/10*1.5+0.75,-2.3,cursor_place%10*1.5-19*0.75);
            glCallList(_displayListId_cursor);
            glPopMatrix();

            for(int i = 0; i < 9; i++)
            {
                if(A[i].place == cursor_place)
                {
                    num=i;
                    {
                    glPushMatrix();
                    glTranslatef(-3+cursor_place/10*1.5+0.75,-.5,cursor_place%10*1.5-19*0.75);
                    glCallList(_displayListId_cursor);
                    glPopMatrix();
//possible move
                    iter=0;
                    for(int k = 11; k < 100; k++)
                    {
                        int flag = 1, p=cursor_place;
                        if(k%10==0)
                        {
                            k++;
                        }
                        if(abs(p%10-k%10) + abs(p/10-k/10) != A[num].top)
                        {
                            flag = 0;
                        }
                        else
                        {
                            int hor = 1;
                            int ver = 1;
                            //prove possibility vertical
                            if(vmove(p, k/10*10+p%10, A, B)*hmove(k/10*10+p%10, k, A, B) == 0)
                                ver = 0;
                            //prove possibility horisontal
                            if(vmove((p/10)*10+k%10, k, A, B)*hmove(p, (p/10)*10+k%10, A, B) == 0)
                                hor = 0;

                            //is just vertical
                            if(p/10-k/10 == 0)
                            {
                                ver = 0;
                            }
                            //is just horisontal
                            else if(p%10-k%10 == 0)
                            {
                                hor = 0;
                            }
                            if(ver+hor == 0)
                                flag = 0;
                            if(flag == 1)
                            {
                                Places_to_move[iter]=k;
                                iter++;
                            }
                        }
                    }

                    //draw possible places
                    for(int i=0; i<iter; i++)
                    {
                        glPushMatrix();
                        glTranslatef(-3+Places_to_move[i]/10*1.5+0.75,-2.3,Places_to_move[i]%10*1.5-19*0.75);
                        glCallList(_displayListId_togo);
                        glPopMatrix();
                        for(int j = 0; j < 9; j++)
                        {
                            //draw places to eat cube
                            int g=0;
                            if((A[j].place == Places_to_move[i]))
                                g=1;
                            if((B[j].place == Places_to_move[i]))
                                g=1;
                            if(g==1)
                            {
                                glPushMatrix();
                                glTranslatef(-3+Places_to_move[i]/10*1.5+0.75,-.5,Places_to_move[i]%10*1.5-19*0.75);
                                glCallList(_displayListId_togo);
                                glPopMatrix();
                            }
                        }

                    }
                }


                }
                if(B[i].place == cursor_place)
                {
                    num=i;
                    {
                    glPushMatrix();
                    glTranslatef(-3+cursor_place/10*1.5+0.75,-.5,cursor_place%10*1.5-19*0.75);
                    glCallList(_displayListId_cursor);
                    glPopMatrix();
//possible move
                    iter=0;
                    for(int k = 11; k < 100; k++)
                    {
                        int flag = 1, p=cursor_place;
                        if(k%10==0)
                        {
                            k++;
                        }
                        if(abs(p%10-k%10) + abs(p/10-k/10) != B[num].top)
                        {
                            flag = 0;
                        }
                        else
                        {
                            int hor = 1;
                            int ver = 1;
                            //prove possibility vertical
                            if(vmove(p, k/10*10+p%10, B, A)*hmove(k/10*10+p%10, k, B, A) == 0)
                                ver = 0;
                            //prove possibility horisontal
                            if(vmove((p/10)*10+k%10, k, B, A)*hmove(p, (p/10)*10+k%10, B, A) == 0)
                                hor = 0;

                            //is just vertical
                            if(p/10-k/10 == 0)
                            {
                                ver = 0;
                            }
                            //is just horisontal
                            else if(p%10-k%10 == 0)
                            {
                                hor = 0;
                            }
                            if(ver+hor == 0)
                                flag = 0;
                            if(flag == 1)
                            {
                                Places_to_move[iter]=k;
                                iter++;
                            }
                        }
                    }

                    //draw possible places
                    for(int i=0; i<iter; i++)
                    {
                        glPushMatrix();
                        glTranslatef(-3+Places_to_move[i]/10*1.5+0.75,-2.3,Places_to_move[i]%10*1.5-19*0.75);
                        glCallList(_displayListId_togo);
                        glPopMatrix();
                        for(int j = 0; j < 9; j++)
                        {
                            //draw places to eat cube
                            int g=0;
                            if((A[j].place == Places_to_move[i]))
                                g=1;
                            if((B[j].place == Places_to_move[i]))
                                g=1;
                            if(g==1)
                            {
                                glPushMatrix();
                                glTranslatef(-3+Places_to_move[i]/10*1.5+0.75,-.5,Places_to_move[i]%10*1.5-19*0.75);
                                glCallList(_displayListId_togo);
                                glPopMatrix();
                            }
                        }

                    }
                }

                }

                }


        }
        //show future condition
        if(is_pressed==1)
        {
            glPushMatrix();
            glTranslatef(-3+cursor_place/10*1.5+0.75,-2.3,cursor_place%10*1.5-19*0.75);
            glCallList(_displayListId_step);
            glPopMatrix();
            //draw shades of future cubes
            //1 verticsl move
            if(step_place%10-B[num].place%10==0)
                for(int i=0; i<iter; i++)
                {
                    if(step_place/10-Places_to_move[i]/10==0)
                    {
                        {
                            //copy to buffer

                            B[9].botton = B[num].botton;
                            B[9].down = B[num].down;
                            B[9].up = B[num].up;
                            B[9].left = B[num].left;
                            B[9].right = B[num].right;
                            B[9].top = B[num].top;
                            B[9].place = B[num].place;
                            int lon=B[9].place%10-Places_to_move[i]%10;
                            int high=-B[9].place/10+Places_to_move[i]/10;
                            if(high>0)
                                for(int j=0; j<high; j++) B[9].move_up();
                            else
                                for(int j=0; j<-high; j++) B[9].move_down();
                            if(lon>0)
                                for(int j=0; j<lon; j++) B[9].move_left();
                            else
                                for(int j=0; j<-lon; j++) B[9].move_right();
                            if(num!=4)
                            {
                                glPushMatrix();//white draw
                                glTranslatef(-2.25+B[9].place/10*1.5,1.5,B[9].place%10*1.5-19*0.75);
                                //rotation
                                rotation(B[9]);
                                glCallList(_displayListId_blackcub);
                                glPopMatrix();
                            }
                            else
                            {
                                glPushMatrix();//white draw
                                glTranslatef(-2.25+B[9].place/10*1.5,1.5,B[9].place%10*1.5-19*0.75);
                                //rotation
                                rotation(B[9]);
                                glCallList(_displayListId_blackking);
                                glPopMatrix();
                            }
                        }
                        if(end_place==Places_to_move[i])
                        {
                            int lon=B[num].place%10-end_place%10;
                            int high=-B[num].place/10+end_place/10;
                            if(high>0)
                                for(int j=0; j<high; j++) B[num].move_up();
                            else
                                for(int j=0; j<-high; j++) B[num].move_down();
                            if(lon>0)
                                for(int j=0; j<lon; j++) B[num].move_left();
                            else
                                for(int j=0; j<-lon; j++) B[num].move_right();

                            for(int o=0; o<9; o++)
                                if(A[o].place==end_place)
                                    A[o].place=0;
                            if(A[4].place==0||B[4].place==15)
                            {
                                cout <<"Black won! Congratulations!";
                                exit(0);
                            }

                            is_pressed=0;
                            end_place=0;
                            step_place=0;
                            wmove=1;
                        }
                    }
                }
            //1 horisontal move
            if(step_place/10-B[num].place/10==0)
                for(int i=0; i<iter; i++)
                {
                    if(step_place%10-Places_to_move[i]%10==0)
                    {
                        {
                            //copy to buffer

                            B[9].botton = B[num].botton;
                            B[9].down = B[num].down;
                            B[9].up = B[num].up;
                            B[9].left = B[num].left;
                            B[9].right = B[num].right;
                            B[9].top = B[num].top;
                            B[9].place = B[num].place;
                            int lon=B[9].place%10-Places_to_move[i]%10;
                            int high=-B[9].place/10+Places_to_move[i]/10;
                            if(lon>0)
                                for(int j=0; j<lon; j++) B[9].move_left();
                            else
                                for(int j=0; j<-lon; j++) B[9].move_right();
                            if(high>0)
                                for(int j=0; j<high; j++) B[9].move_up();
                            else
                                for(int j=0; j<-high; j++) B[9].move_down();
                            if(num!=4)
                            {
                                glPushMatrix();//white draw
                                glTranslatef(-2.25+B[9].place/10*1.5,1.5,B[9].place%10*1.5-19*0.75);
                                //rotation
                                rotation(B[9]);
                                glCallList(_displayListId_blackcub);
                                glPopMatrix();
                            }
                            else
                            {
                                glPushMatrix();//white draw
                                glTranslatef(-2.25+B[9].place/10*1.5,1.5,B[9].place%10*1.5-19*0.75);
                                //rotation
                                rotation(B[9]);
                                glCallList(_displayListId_blackking);
                                glPopMatrix();
                            }
                            if(end_place==Places_to_move[i])
                            {
                                int lon=B[num].place%10-end_place%10;
                                int high=-B[num].place/10+end_place/10;
                                if(lon>0)
                                    for(int j=0; j<lon; j++) B[num].move_left();
                                else
                                    for(int j=0; j<-lon; j++) B[num].move_right();
                                if(high>0)
                                    for(int j=0; j<high; j++) B[num].move_up();
                                else
                                    for(int j=0; j<-high; j++) B[num].move_down();
                                for(int o=0; o<9; o++)
                                    if(A[o].place==end_place)
                                        A[o].place=0;
                                if(A[4].place==0||B[4].place==15)
                                {
                                cout <<"Black won! Congratulations!";
                                    exit(0);
                                }

                                is_pressed=0;
                                end_place=0;
                                step_place=0;
                                wmove=1;
                            }
                        }
                    }
                }

        }
        }

        glutSwapBuffers();

    }
    int main(int argc,char** argv)
    {
        {
            //(A)white initialize
            for(int i = 0; i < 4; i++)
            {
                wfill(A[3-i]);
                A[3-i].place = 14;

                wfill(A[5+i]);
                A[5+i].place = 16;

                for(int j = 1; j <= i; j++)
                {
                    A[3-i].move_left();
                    A[5+i].move_left();
                    A[5+i].place+=2;
                }
            }
            fillking(A[4]);
            A[4].place = 15;
            //(B)black initialize
            for(int i = 0; i < 4; i++)
            {
                bfill(B[3-i]);
                B[3-i].place = 94;

                bfill(B[5+i]);
                B[5+i].place = 96;
                for(int j = 1; j <= i; j++)
                {
                    B[3-i].move_right();
                    B[3-i].place-=2;
                    B[5+i].move_right();
                }
            }
            fillking(B[4]);
            B[4].place = 95;
        }
//end initialize
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
        glutInitWindowSize(800,800);

        glutCreateWindow("Poedinok");
        initRendering();
        glutFullScreen();

        glutDisplayFunc(drawScene);
        glutIdleFunc(drawScene);
        glutKeyboardFunc(esc);
        glutSpecialFunc(handleKeypress);
        glutReshapeFunc(handleResize);

        glutMainLoop();//nothing to add
        return 0;
    }
