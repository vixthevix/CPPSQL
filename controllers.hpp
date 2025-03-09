#include <conio.h>
#include "gridclass.hpp"
// unfortunately idk how to make a base controller class so all controller classes must have an override of the abstract class listen. or not idfc




class titlecontrol
{
    void isRelational(bool (*isChoice), sbundle (*choice))
    {
        //printf("yo");
        (*isChoice) = true;
        (*choice).setrangecolour(1, 11, YELLOW);
        (*choice).setrangecolour(12, 18, WHITE);

        //(*choice).setallcolour(RED);
    }
    void isSingle(bool (*isChoice), sbundle (*choice))
    {   
        //printf("yo");
        (*isChoice) = false;
        (*choice).setrangecolour(1, 11, WHITE);
        (*choice).setrangecolour(12, 18, YELLOW);
    }
    void moveUp(bool (*isChoice), sbundle (*choice))
    {
        if ((*choice).gety() > 0)
        {
            (*isChoice) = true;
            (*choice).offsetally(-2);
            (*choice).setrangecolour(1, 11, YELLOW);
            (*choice).setrangecolour(12, 18, WHITE);


        }
    }
    void moveDown(bool (*isChoice), sbundle (*choice))
    {
        if ((*choice).gety() < 6)
        {
            (*isChoice) = true;
            (*choice).offsetally(2);

            (*choice).setrangecolour(1, 11, YELLOW);
            (*choice).setrangecolour(12, 18, WHITE);
        }
    }

    void makeChoice(bool (*madeChoice))
    {
        (*madeChoice) = true;
    }

    public:
        bool listen(bool (*isChoice), bool (*madeChoice), sbundle (*choice))
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
                        moveUp(isChoice, choice);
                        detected = true;
                        break;
                    case 's':
                        moveDown(isChoice, choice);
                        detected = true;
                        break;
                    case ' ':
                        makeChoice(madeChoice);
                        detected = true;
                        break;
                }
            }
            return detected;
        }
};