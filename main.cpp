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
    int gridx = 40, gridy = 10;
    grid title = grid(gridx, gridy);
    // sbundle intro = sbundle("intro", "textfiles/intro.txt");
    // intro.setallcolour(RED);
    // intro.makespecial();

    // title.addbundle(intro);
    bundle select = bundle("select", "textfiles/title/select.txt");
    select.offsetallx(1);
    select.offsetally(0);
    bundle create = bundle("create", "textfiles/title/create.txt");
    create.offsetallx(1);
    create.offsetally(2);
    bundle import = bundle("import", "textfiles/title/import.txt");
    import.offsetallx(1);
    import.offsetally(4);
    bundle exportb = bundle("export", "textfiles/title/export.txt");
    exportb.offsetallx(1);
    exportb.offsetally(6);

    sbundle choice = sbundle("choice", "textfiles/title/choice1.txt");
    choice.makespecial();
    bool isChoice = true;
    choice.offsetallx(7);
    choice.offsetally(0);
    // choice.setcolour(1, YELLOW);
    // choice.setcolour(2, YELLOW);
    // choice.setcolour(3, YELLOW);
    // choice.setcolour(4, YELLOW);
    // choice.setcolour(5, YELLOW);
    // choice.setcolour(6, YELLOW);
    // choice.setcolour(7, YELLOW);
    // choice.setcolour(8, YELLOW);
    // choice.setcolour(9, YELLOW);
    // choice.setcolour(10, YELLOW);

    choice.setrangecolour(1, 11, YELLOW);
    choice.setrangecolour(12, 18, WHITE);

    // choice.setcolour(12, WHITE);
    // choice.setcolour(13, WHITE);
    // choice.setcolour(14, WHITE);
    // choice.setcolour(15, WHITE);
    // choice.setcolour(16, WHITE);
    // choice.setcolour(17, WHITE);

    title.addbundle(select);
    title.addbundle(create);
    title.addbundle(import);
    title.addbundle(exportb);
    title.addbundle(choice);

    titlecontrol titleCon;

    bool changeOccur = false;
    bool madeChoice = false;

    grid selectscreen = grid(gridx, gridy);
    sbundle coolio = sbundle("coolio", "textfiles/cool.txt");
    coolio.setallcolour(GREEN);
    coolio.makespecial();
    selectscreen.addbundle(coolio);


    bool greatergoing = true;
    bool titlegoing = true;
    bool coolgoing = false;
    while (greatergoing)
    {
        while (titlegoing)
        {
            title.display();
            if (titleCon.listen(&isChoice, &madeChoice, &choice))
            {
                title.updatebundle(choice);
                changeOccur = true;
                //printf("sick");
            }
            if (madeChoice)
            {
                madeChoice = false;
                titlegoing = false;
                coolgoing = true;
            }
        }
        while (coolgoing)
        {
            selectscreen.display();
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