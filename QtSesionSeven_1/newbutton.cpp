#include "newbutton.h"
/*
newbutton::newbutton(QWdiget *parent) :QPushButton(parent){
    isButtonClicked=true;
    connect(this,SIGNAL(clicked()),this,SLOT(clickManuel()))
}

void newbutton::clickManuel(){
isButtonClicked=!isButtonClicked;
}
*/
newbutton::newbutton()
{
    isButtonClicked=true;
    connect(this,SIGNAL(clicked()),this,SLOT(clickManuel()));
}
void newbutton::clickManuel(){
isButtonClicked=!isButtonClicked;
}
