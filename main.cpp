#include "gridclass.hpp"

int main(void)
{
    //potentially have multiple displays for now
    //maybe include a thing on special colours
    grid title = grid(30, 10);
    sbundle intro = sbundle("intro", "textfiles/intro.txt");
    intro.setallcolour(RED);
    intro.makespecial();

    title.addbundle(intro);
    bool going = true;
    while (going)
    {
        title.display();
    }
    return 0;
}