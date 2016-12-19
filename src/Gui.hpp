/*
 * Gui.hpp
 *
 *  Created on: Dec 19, 2016
 *      Author: eroc
 */

#ifndef GUI_HPP_
#define GUI_HPP_
#include <TGUI/TGUI.hpp>

void inline updateText(tgui::Label::Ptr label, tgui::EditBox::Ptr editBox){
	label->setText(editBox->getText());
}

void inline testGuiSetup(tgui::Gui& gui){
	gui.removeAllWidgets();
	tgui::Theme::Ptr blackTheme = std::make_shared<tgui::Theme>("assets/gui/Black.txt");
	tgui::Label::Ptr fpsCount = blackTheme->load("Label");
	tgui::Panel::Ptr textPanel = blackTheme->load("Panel");
	tgui::EditBox::Ptr editBox = blackTheme->load("EditBox");
	tgui::Button::Ptr updateButton = blackTheme->load("Button");

	//fpsCount
	fpsCount->setText("fuck");
	fpsCount->setTextColor(sf::Color::White);
	fpsCount->setPosition(gui.getView().getSize().x - 80, 20);

	//textPanel
	textPanel->setSize(tgui::bindSize(fpsCount));
	textPanel->setPosition(bindPosition(fpsCount));

	//editBox
	editBox->setSize(gui.getView().getSize().x/5 , 40);
	editBox->setPosition(40, 20);

	//updateButton
	updateButton->setText("Upd@t3");
	updateButton->setPosition(editBox->getPosition().x , editBox->getPosition().y + editBox->getSize().y + 10);
	updateButton->setSize(tgui::bindSize(editBox));

	gui.add(textPanel);
	gui.add(fpsCount, "fpsCount");
	gui.add(editBox);
	gui.add(updateButton);

	updateButton->connect("pressed", updateText, fpsCount, editBox);

}



#endif /* GUI_HPP_ */
