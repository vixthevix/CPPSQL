//#include "gridclass.hpp"
#include <functional>
#include <unordered_map>
#include "controllers.hpp"

struct keyfunc
{
    char key;
    void (*func)();
};



int main(void)
{
    //potentially have multiple displays for now
    //maybe include a thing on special colours
    grid title = grid(40, 10);
    // sbundle intro = sbundle("intro", "textfiles/intro.txt");
    // intro.setallcolour(RED);
    // intro.makespecial();

    // title.addbundle(intro);
    bundle select = bundle("select", "textfiles/select.txt");
    select.offsetx(1);
    select.offsety(0);
    bundle create = bundle("create", "textfiles/create.txt");
    create.offsetx(1);
    create.offsety(2);
    bundle import = bundle("import", "textfiles/import.txt");
    import.offsetx(1);
    import.offsety(4);
    bundle exportb = bundle("export", "textfiles/export.txt");
    exportb.offsetx(1);
    exportb.offsety(6);

    sbundle choice = sbundle("choice", "textfiles/choice1.txt");
    choice.makespecial();
    bool isChoice = true;
    choice.offsetx(7);
    choice.offsety(0);
    choice.setcolour(1, YELLOW);
    choice.setcolour(2, YELLOW);
    choice.setcolour(3, YELLOW);
    choice.setcolour(4, YELLOW);
    choice.setcolour(5, YELLOW);
    choice.setcolour(6, YELLOW);
    choice.setcolour(7, YELLOW);
    choice.setcolour(8, YELLOW);
    choice.setcolour(9, YELLOW);
    choice.setcolour(10, YELLOW);

    choice.setcolour(12, WHITE);
    choice.setcolour(13, WHITE);
    choice.setcolour(14, WHITE);
    choice.setcolour(15, WHITE);
    choice.setcolour(16, WHITE);
    choice.setcolour(17, WHITE);

    title.addbundle(select);
    title.addbundle(create);
    title.addbundle(import);
    title.addbundle(exportb);
    title.addbundle(choice);

    titlecontrol titleCon;

    bool changeOccur = false;
    bool going = true;
    while (going)
    {
        title.display();
        if (titleCon.listen(&isChoice, &choice))
        {
            title.updatebundle(choice);
            changeOccur = true;
            //printf("sick");
        }
        // if (changeOccur)
        // {
        //     changeOccur = false;
        //     if (isChoice)
        //     {

        //     }
        // }
        // if (titleCon.listen(&isChoice) == false){title.display();};
    }
    return 0;
}