#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED
int Max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}
int Min(int a, int b)
{
    if(a<b)
        return a;
    return b;
}
struct cub
{
    int top;
    int right;
    int left;
    int up;
    int down;
    int botton;
    int place;



    void move_down()
    {
        int b;
        b = this->botton;
        this->botton = this->down;
        this->down = this->top;
        this->top = this->up;
        this->up = b;
        place-=10;
    }
    void move_up()
    {
        int b;
        b = this->botton;
        this->botton = this->up;
        this->up = this->top;
        this->top = this->down;
        this->down = b;
        place+=10;
    }
    void move_right()
    {
        int b;
        b = this->top;
        this->top = this->left;
        this->left = this->botton;
        this->botton = this->right;
        this->right = b;
        place++;
    }
    void move_left()
    {
        int b;
        b = this->top;
        this->top = this->right;
        this->right = this->botton;
        this->botton = this->left;
        this->left = b;
        place--;
    }
};

//prove possibility of vertical move
int vmove(int a, int b, cub A[], cub B[])
{
    int x = Max(a, b), y = Min(a, b);
    if((x%10 < 1)&&(y%10 < 1)&&(x > 99))
        return 0;
    if(a/10 > b/10)
        for(int i = b; i < a; i += 10)
        {
            for(int j = 0; j < 9; j++)
            {
                if(A[j].place == i)
                    return 0;
                if(i != b)
                    if(B[j].place == i)
                        return 0;
            }
        }
    if(a/10 < b/10)
        for(int i = a+10; i <= b; i += 10)
        {
            for(int j = 0; j < 9; j++)
            {
                if(A[j].place == i)
                    return 0;
                if(i != b)
                    if(B[j].place == i)
                        return 0;
            }
        }
    return 1;
}
//prove possibility of horisontal move
int hmove(int a, int b, cub A[], cub B[])
{
    int x = Max(a, b), y = Min(a, b);
    if(y < 11 || x > 99 || ((x%10) * (y%10) == 0))
        return 0;
    if(a%10 < b%10)
    {
        for(int i = a+1; i <= b; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(A[j].place == i)
                    return 0;
                if(i != b)
                    if(B[j].place == i)
                        return 0;
            }
        }
    }
    if(a%10 > b%10)
    {
        for(int i = b; i < a; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(A[j].place == i)
                    return 0;
                if(i!=b)
                    if(B[j].place==i)
                        return 0;
            }
        }
    }
    return 1;
}
//fill sides of cubes
void wfill(cub &a)
{
    a.botton = 1;
    a.down = 3;
    a.right = 2;
    a.top = 6;
    a.left = 5;
    a.up = 4;

}

void bfill(cub &a)
{
    a.botton = 1;
    a.down = 4;
    a.right = 5;
    a.top = 6;
    a.left = 2;
    a.up = 3;
}

void fillking(cub &a)
{
    a.botton = 1;
    a.down = 1;
    a.right = 1;
    a.top = 1;
    a.left = 1;
    a.up = 1;
}

void rotation(cub A)
{
            if(A.up==4)
                switch(A.top)
                {
                case 1:
                    glRotatef(-90, 1, 0, 0);
                    break;
                case 5:
                    glRotatef(-180, 1, 0, 0);
                    break;
                case 6:
                    glRotatef(90, 1, 0, 0);
                    break;
                }

            if(A.up==3)
            {
                glRotatef(180, 0, 0, 1);
                switch(A.top)
                {
                case 6:
                    glRotatef(-90, 1, 0, 0);
                    break;
                case 2:
                    glRotatef(-180, 1, 0, 0);
                    break;
                case 1:
                    glRotatef(90, 1, 0, 0);
                    break;
                }
            }

            if(A.up==2)
            {
                glRotatef(-90, .0f, 0.0f, 1.0f);
                switch(A.top)
                {
                case 3:
                    break;
                case 6:
                    glRotatef(90, .0f, 1, 0);
                    break;
                case 1:
                    glRotatef(-90, .0f, 1, 0);
                    break;
                case 4:
                    glRotatef(180, .0f, 1, 0);
                    break;
                }
            }

            if(A.up==5)
            {
                glRotatef(90, .0f, 0.0f, 1.0f);
                switch(A.top)
                {
                case 4:
                    break;
                case 1:
                    glRotatef(90, .0f, 1, 0);
                    break;
                case 6:
                    glRotatef(-90, .0f, 1, 0);
                    break;
                case 3:
                    glRotatef(180, .0f, 1, 0);
                    break;
                }
            }

            if(A.up==1)
            {
                glRotatef(90, .0f, 1, 0);
                switch(A.top)
                {
                case 2:
                    break;
                case 4:
                    glRotatef(90, .0f, 0, 1);
                    break;
                case 5:
                    glRotatef(180, .0f, 0, 1);
                    break;
                case 3:
                    glRotatef(-90, .0f, 0, 1);
                    break;
                }
            }

            if(A.up==6)
            {
                glRotatef(-90, .0f, 1, 0);
                switch(A.top)
                {
                case 2:
                    break;
                case 4:
                    glRotatef(90, .0f, 0, 1);
                    break;
                case 5:
                    glRotatef(180, .0f, 0, 1);
                    break;
                case 3:
                    glRotatef(-90, .0f, 0, 1);
                    break;
                }
            }
        }


#endif // MOVE_H_INCLUDED
