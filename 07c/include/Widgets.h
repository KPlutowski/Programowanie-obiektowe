#include <iostream>
#include <vector>

class Widget
{
protected:
    std::string color = "gray";
    std::string nameOfWidget = "Widget";

public:
    Widget(std::string _color = "gray", std::string _nameOfWidget = "Widget") : color(_color), nameOfWidget(_nameOfWidget){};
    std::string widgetDescription() const { return color + " " + nameOfWidget; }
    virtual ~Widget() {}
    void changeColor(const std::string &newColor) { color = newColor; };
};

class Button : public Widget
{
public:
    Button(std::string _color = "gray", std::string _nameOfWidget = "Button") : Widget(_color, _nameOfWidget){};
};

class RadioButton : public Button
{
public:
    RadioButton(std::string _color = "gray", std::string _nameOfWidget = "RadioButton") : Button(_color, _nameOfWidget){};
};

class EditBox : public Widget
{
public:
    EditBox(std::string _color = "gray", std::string _nameOfWidget = "EditBox") : Widget(_color, _nameOfWidget){};
};
class MaskedEditBox : public EditBox
{
public:
    MaskedEditBox(std::string _color = "gray", std::string _nameOfWidget = "MaskedEditBox") : EditBox(_color, _nameOfWidget){};
};

class WidgetPainter
{
public:
    void paintWidgets(std::vector<Widget *> &widgets)
    {
        for (auto widget : widgets)
        {
            if (auto button = dynamic_cast<Button *>(widget))
                button->changeColor(std::string("blue"));
            else if (auto editBox = dynamic_cast<EditBox *>(widget))
                editBox->changeColor(std::string("red"));
        }
    }
};
