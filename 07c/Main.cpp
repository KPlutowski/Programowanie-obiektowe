/* Celem zadania jest odnalezienie hierarchi klas i wykorzystanie odpowiedniego sposobu rzutowania
 * dla klas polimorficznych.
 * Należy wykonać tylko dwa rzutowania.
 */
#include <iostream>
#include "Widgets.h"
#include <vector>
int main() {

    std::vector<Widget*> widgets;
    widgets.push_back(new Button());
    widgets.push_back(new EditBox());
    widgets.push_back(new RadioButton());
    widgets.push_back(new MaskedEditBox());
    for (auto x: widgets)
        std::cout<<x->widgetDescription()<<std::endl;

    (new WidgetPainter())->paintWidgets(widgets);

    for (auto x: widgets)
        std::cout<<x->widgetDescription()<<std::endl;
    return 0;
}
//Wynik:
//gray button
//gray editbox
//gray radiobutton
//gray maskededitbox

//blue button
//red editbox
//blue radiobutton
//red maskededitbox