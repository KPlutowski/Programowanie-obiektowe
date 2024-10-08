#include <iostream>
#include <vector>

struct Object{
    std::string text = "Object";
    virtual std::string print(){
        return text;
    }
};

struct ConsoleObject:public Object{
    ConsoleObject(){
        text="ConsoleObject";
    }
   
};

struct ConsoleLine:public ConsoleObject{
    ConsoleLine(){
        text="ConsoleLine";
    }

};

struct ConsoleText:public ConsoleObject{
        ConsoleText(){
        text="ConsoleText";
    }

};


struct GuiObject:public Object{
    GuiObject(){
        text="GuiObject";
    }

};

struct GuiLine:public GuiObject{
    GuiLine(){
        text="GuiLine";
    }

};

struct GuiText:public GuiObject{
    GuiText(){
        text="GuiText";
    }

};



int main()
{
    std::vector<Object*> objs;
    ConsoleObject*console0=new ConsoleLine();
    ConsoleObject*console1=new ConsoleText();
    GuiObject* gui0=new GuiLine();
    GuiObject* gui1=new GuiText();
    objs.push_back(console0); objs.push_back(console1);
    objs.push_back(gui0); objs.push_back(gui1);
    for(unsigned i=0; i !=objs.size();i++)
    std::cout<<objs[i]->print()<<",";
}
// wynik działania:
// Console Line,Console Text,Gui Line,Gui Text,