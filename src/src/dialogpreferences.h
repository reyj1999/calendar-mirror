/***************************************************************************
 *   Author Alan Crispin                 *
 *   crispinalan@gmail.com                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation.                                  *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

#ifndef DIALOGPREFERENCES_H
#define DIALOGPREFERENCES_H

#include "preferences.h"
#include <QDebug>
#include <QDialog>
#include <QColor>
#include <QColorDialog>

namespace Ui {
  class DialogPreferences;
}

class DialogPreferences : public QDialog {
  CS_OBJECT(DialogPreferences)

public: 
  explicit DialogPreferences(QWidget *parent = nullptr, Preferences *thePreferences = nullptr);
  ~DialogPreferences();

	//Application
	int getAppFontSize(); 
	
	//Calendar
	bool isPublicHolidays();
	bool isEventStars();	
	bool isDarkStyle();
	bool isAmPmFormat();
	
	
	//Alarm
	bool isAudioAlarm();
		
//Factory reset

    bool isFactoryReset();

    //colour
    int getTodayRed();
    int getTodayGreen();
    int getTodayBlue();

    int getEventRed();
    int getEventGreen();
    int getEventBlue();

    int getPriorityRed();
    int getPriorityGreen();
    int getPriorityBlue();

    int getPublicRed();
    int getPublicGreen();
    int getPublicBlue();

	bool isTalkAtStartup();    
    bool isTalkUpcoming();
    bool isTalkLocation();
	int getUpcomingDayNumber();

 

private:

	
	//Application  
	CS_SLOT_1(Private, void on_spinBoxApplicationFontSize_valueChanged(int arg1))
	CS_SLOT_2(on_spinBoxApplicationFontSize_valueChanged)
	
	//Calendar
	CS_SLOT_1(Private, void on_checkBoxPublicHolidays_stateChanged(int arg1))
	CS_SLOT_2(on_checkBoxPublicHolidays_stateChanged)  
	
	CS_SLOT_1(Private, void on_checkBoxEventStars_stateChanged(int arg1))
	CS_SLOT_2(on_checkBoxEventStars_stateChanged)
	
	// CS_SLOT_1(Private, void on_checkBoxAudioBleep_stateChanged(int arg1))
	// CS_SLOT_2(on_checkBoxAudioBleep_stateChanged)
	
	CS_SLOT_1(Private, void on_checkBoxDarkStyle_stateChanged(int arg1))
	CS_SLOT_2(on_checkBoxDarkStyle_stateChanged)
	
	CS_SLOT_1(Private, void on_checkBoxAmPmFormat_stateChanged(int arg1))
	CS_SLOT_2(on_checkBoxAmPmFormat_stateChanged)


	CS_SLOT_1(Private, void on_checkBoxFactoryReset_stateChanged(int arg1))
	CS_SLOT_2(on_checkBoxFactoryReset_stateChanged)
	
	//colours
	CS_SLOT_1(Private, void on_pushButtonTodayColour_clicked())
	CS_SLOT_2(on_pushButtonTodayColour_clicked)

	CS_SLOT_1(Private, void on_pushButtonEventColour_clicked())
	CS_SLOT_2(on_pushButtonEventColour_clicked)

	CS_SLOT_1(Private, void on_pushButtonPriorityColour_clicked())
	CS_SLOT_2(on_pushButtonPriorityColour_clicked)

	CS_SLOT_1(Private, void on_pushButtonPublicColour_clicked())
	CS_SLOT_2(on_pushButtonPublicColour_clicked)

	
	//Alarm
	CS_SLOT_1(Private, void on_checkBoxAudioAlarm_stateChanged(int arg1))
	CS_SLOT_2(on_checkBoxAudioAlarm_stateChanged)

	//Talk
	CS_SLOT_1(Private, void on_checkBoxTalkLocation_stateChanged(int arg1))
	CS_SLOT_2(on_checkBoxTalkLocation_stateChanged)
	
	CS_SLOT_1(Private, void on_checkBoxTalkStartup_stateChanged(int arg1))
	CS_SLOT_2(on_checkBoxTalkStartup_stateChanged)

	CS_SLOT_1(Private, void on_checkBoxUpcoming_stateChanged(int arg1))
	CS_SLOT_2(on_checkBoxUpcoming_stateChanged)

	CS_SLOT_1(Private, void on_spinBoxUpcomingDays_valueChanged(int arg1))
	CS_SLOT_2(on_spinBoxUpcomingDays_valueChanged)

	//OK Cancel
	CS_SLOT_1(Private, void on_pushButtonOk_clicked()) 
    CS_SLOT_2(on_pushButtonOk_clicked)
    
    CS_SLOT_1(Private, void on_pushButtonCancel_clicked()) 
    CS_SLOT_2(on_pushButtonCancel_clicked)


	
private:
  Ui::DialogPreferences *ui;

  //Application
  int appFontSize = 20;
  //Calendar
  bool publicHolidays = false;
  bool eventStars=true; 
  bool darkStyle=false;
  bool ampmFormat=false;
 
  //alarm
  bool audioAlarm = false;
  bool factoryReset=false;
  //colour
  int todayRed = 50; //lime green
  int todayGreen =205;
  int todayBlue =50;

  int eventRed=70; //blue green
  int eventGreen =150;
  int eventBlue=180;

  int priorityRed=255; //fuchsia
  int priorityGreen=0;
  int priorityBlue =255;

  int publicRed=218; //golden rod
  int publicGreen=165;
  int publicBlue=32;

  bool talkAtStartup = false;
  bool talkUpcoming = false;
  bool talkLocation =false;
  int upcomingDays=7;


};

#endif // DIALOGPREFERENCES_H
