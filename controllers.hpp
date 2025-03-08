#include <conio.h>
#include "gridclass.hpp"
// unfortunately idk how to make a base controller class so all controller classes must have an override of the abstract class listen. or not idfc




class titlecontrol
{
    void isRelational(bool (*isChoice), sbundle (*choice))
    {
        //printf("yo");
        (*isChoice) = true;
        (*choice).setcolour(1, YELLOW);
        (*choice).setcolour(2, YELLOW);
        (*choice).setcolour(3, YELLOW);
        (*choice).setcolour(4, YELLOW);
        (*choice).setcolour(5, YELLOW);
        (*choice).setcolour(6, YELLOW);
        (*choice).setcolour(7, YELLOW);
        (*choice).setcolour(8, YELLOW);
        (*choice).setcolour(9, YELLOW);
        (*choice).setcolour(10, YELLOW);

        (*choice).setcolour(12, WHITE);
        (*choice).setcolour(13, WHITE);
        (*choice).setcolour(14, WHITE);
        (*choice).setcolour(15, WHITE);
        (*choice).setcolour(16, WHITE);
        (*choice).setcolour(17, WHITE);

        //(*choice).setallcolour(RED);
    }
    void isSingle(bool (*isChoice), sbundle (*choice))
    {   
        //printf("yo");
        (*isChoice) = false;
        (*choice).setcolour(1, WHITE);
        (*choice).setcolour(2, WHITE);
        (*choice).setcolour(3, WHITE);
        (*choice).setcolour(4, WHITE);
        (*choice).setcolour(5, WHITE);
        (*choice).setcolour(6, WHITE);
        (*choice).setcolour(7, WHITE);
        (*choice).setcolour(8, WHITE);
        (*choice).setcolour(9, WHITE);
        (*choice).setcolour(10, WHITE);

        (*choice).setcolour(12, YELLOW);
        (*choice).setcolour(13, YELLOW);
        (*choice).setcolour(14, YELLOW);
        (*choice).setcolour(15, YELLOW);
        (*choice).setcolour(16, YELLOW);
        (*choice).setcolour(17, YELLOW);
    }
    void moveUp(sbundle (*choice))
    {
        if ((*choice).gety() > 0)
        {
            (*choice).offsety(-2);
        }
    }
    void moveDown(sbundle (*choice))
    {
        if ((*choice).gety() < 6)
        {
            (*choice).offsety(2);
        }
    }
    public:
        bool listen(bool (*isChoice), sbundle (*choice))
        {
            bool detected = false;
            if (kbhit())
            {
                char key = getch();
                switch (key)
                {
                    case 'a':
                        isRelational(isChoice, choice);
                        detected = true;
                        break;
                    case 'd':
                        isSingle(isChoice, choice);
                        detected = true;
                        break;
                    case 'w':
                        moveUp(choice);
                        detected = true;
                        break;
                    case 's':
                        moveDown(choice);
                        detected = true;
                        break;
                }
            }
            return detected;
        }
};