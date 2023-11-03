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
#include "dialogpreferences.h"
#include "ui_dialogpreferences.h"

DialogPreferences::DialogPreferences(QWidget *parent, Preferences *thePreferences) : QDialog(parent),
                                                                                     ui(new Ui::DialogPreferences) {
  ui->setupUi(this);

  setWindowTitle("Preferences");

	appFontSize = 20;
	//Defaults checkbox settings
	//calendar 
	ui->checkBoxPublicHolidays->setCheckState(Qt::Unchecked);
	ui->checkBoxEventStars->setCheckState(Qt::Unchecked);	
	ui->checkBoxDarkStyle->setCheckState(Qt::Unchecked); 
	ui->checkBoxAmPmFormat->setCheckState(Qt::Unchecked); 
	//alarm
	ui->checkBoxAudioAlarm->setCheckState(Qt::Unchecked);  
	//Application
	ui->spinBoxApplicationFontSize->setRange(12, 38);
	ui->spinBoxApplicationFontSize->setValue(20);
		
	//Set checkboxs using preferences  
	
	//application font
	ui->spinBoxApplicationFontSize->setValue(thePreferences->m_appFontSize);
	
	//Calendar
	if (thePreferences->m_publicHolidays == false) {
	ui->checkBoxPublicHolidays->setCheckState(Qt::Unchecked);
	} else {
	ui->checkBoxPublicHolidays->setCheckState(Qt::Checked);
	}	
	if (thePreferences->m_eventStars== false) {
	ui->checkBoxEventStars->setCheckState(Qt::Unchecked);
	} else {
	ui->checkBoxEventStars->setCheckState(Qt::Checked);
	}	
	if (thePreferences->m_darkStyle == false) {
	ui->checkBoxDarkStyle->setCheckState(Qt::Unchecked);
	} else {
	ui->checkBoxDarkStyle->setCheckState(Qt::Checked);
	}
	if (thePreferences->m_12HourFormat == false) {
	ui->checkBoxAmPmFormat->setCheckState(Qt::Unchecked);
	} else {
	ui->checkBoxAmPmFormat->setCheckState(Qt::Checked);
	}
		
	//alarm
	if (thePreferences->m_audioAlarm == true) {
	ui->checkBoxAudioAlarm->setCheckState(Qt::Checked);
	} else {
	ui->checkBoxAudioAlarm->setCheckState(Qt::Unchecked);
	}

  if (thePreferences->m_talkAtStartup == true)
  {
    ui->checkBoxTalkStartup->setCheckState(Qt::Checked);
  }
  else
  {
    ui->checkBoxTalkStartup->setCheckState(Qt::Unchecked);
  }

  // Upcoming
  if (thePreferences->m_talkUpcoming == false)
  {
    ui->checkBoxUpcoming->setCheckState(Qt::Unchecked);
  }
  else
  {
    ui->checkBoxUpcoming->setCheckState(Qt::Checked);
  }
  ui->spinBoxUpcomingDays->setRange(1, 14);
  ui->spinBoxUpcomingDays->setValue(7);
  ui->spinBoxUpcomingDays->setValue(thePreferences->m_lookAheadDays);

  //set current colours
	 todayRed = thePreferences->m_todayRed;
     todayGreen =thePreferences->m_todayGreen;
     todayBlue =thePreferences->m_todayBlue;

     eventRed = thePreferences->m_eventRed;
     eventGreen =thePreferences->m_eventGreen;
     eventBlue =thePreferences->m_eventBlue;

     priorityRed = thePreferences->m_priorityRed;
     priorityGreen =thePreferences->m_priorityGreen;
     priorityBlue =thePreferences->m_priorityBlue;

     publicRed = thePreferences->m_publicRed;
     publicGreen =thePreferences->m_publicGreen;
     publicBlue =thePreferences->m_publicBlue;

}

DialogPreferences::~DialogPreferences() {
  delete ui;
}

void DialogPreferences::on_pushButtonOk_clicked()
{
  qDebug()<<"OK button clicked";
  QDialog::accept();
}

void DialogPreferences::on_pushButtonCancel_clicked()
{
  qDebug()<<"Cancel button clicked";
  QDialog::reject();
}

//Application-----------------------------------------------------------

int DialogPreferences::getAppFontSize() {
  return appFontSize;
}

void DialogPreferences::on_spinBoxApplicationFontSize_valueChanged(int arg1) {
  appFontSize = arg1;
}
//Calendar ------------------------------------------------------------

bool DialogPreferences::isPublicHolidays() {
  return publicHolidays;
}
bool DialogPreferences::isEventStars() {
  return eventStars;
}

bool DialogPreferences::isDarkStyle() {	
  return darkStyle;
}

bool DialogPreferences::isAmPmFormat() {	
  return ampmFormat;
}
void DialogPreferences::on_checkBoxPublicHolidays_stateChanged(int arg1) {
  if (arg1 == Qt::Unchecked) {
    publicHolidays = false;
  } else if (arg1 == Qt::Checked) {
    publicHolidays = true;
  }
}

void DialogPreferences::on_checkBoxEventStars_stateChanged(int arg1) {
  if (arg1 == Qt::Unchecked) {
    eventStars = false;
  } else if (arg1 == Qt::Checked) {
    eventStars = true;
  }
}

void DialogPreferences::on_checkBoxDarkStyle_stateChanged(int arg1) {
  if (arg1 == Qt::Unchecked) {	  
    darkStyle = false; 
  } else if (arg1 == Qt::Checked) {
    darkStyle = true;    
  }
}

void DialogPreferences::on_checkBoxAmPmFormat_stateChanged(int arg1) {
  if (arg1 == Qt::Unchecked) {	  
    ampmFormat = false; 
  } else if (arg1 == Qt::Checked) {
    ampmFormat = true;    
  }
}

//---------------------------------------------------------------
// Alarm
//---------------------------------------------------------------

bool DialogPreferences::isAudioAlarm() {
  return audioAlarm;
}

void DialogPreferences::on_checkBoxAudioAlarm_stateChanged(int arg1) {
  if (arg1 == Qt::Unchecked) {
    audioAlarm = false;
  } else if (arg1 == Qt::Checked) {
    audioAlarm = true;
  }
}

//---------------------------------------------------------------
// Colour
//--------------------------------------------------------------

int DialogPreferences::getTodayRed() {
  return todayRed;
}
int DialogPreferences::getTodayGreen() {
  return todayGreen;
}
int DialogPreferences::getTodayBlue() {
  return todayBlue;
}

int DialogPreferences::getEventRed() {
  return eventRed;
}
int DialogPreferences::getEventGreen() {
  return eventGreen;
}
int DialogPreferences::getEventBlue() {
  return eventBlue;
}

int DialogPreferences::getPriorityRed() {
  return priorityRed;
}
int DialogPreferences::getPriorityGreen() {
  return priorityGreen;
}
int DialogPreferences::getPriorityBlue() {
  return priorityBlue;
}

int DialogPreferences::getPublicRed() {
  return publicRed;
}

int DialogPreferences::getPublicGreen() {
  return publicGreen;
}
int DialogPreferences::getPublicBlue() {
  return publicBlue;
}

void DialogPreferences::on_pushButtonTodayColour_clicked(){

   QColor currentTodayColour;
   currentTodayColour.setRgb(todayRed,todayGreen,todayBlue);

   QColor color = QColorDialog::getColor(currentTodayColour, this);
   if( color.isValid() )
   {
     todayRed = color.red();
     todayGreen =color.green();
     todayBlue =color.blue();
//      qDebug()<<"todayRed = "<<todayRed<<"\n";
//      qDebug()<<"todayGreen = "<<todayGreen<<"\n";
//      qDebug()<<"todayBlue = "<<todayBlue<<"\n";
   }
}

void DialogPreferences::on_pushButtonEventColour_clicked(){

  QColor currentEventColour;
   currentEventColour.setRgb(eventRed,eventGreen,eventBlue);

   QColor color = QColorDialog::getColor(currentEventColour, this);
   if( color.isValid() )
   {
     eventRed = color.red();
     eventGreen =color.green();
     eventBlue =color.blue();
   }
}

void DialogPreferences::on_pushButtonPriorityColour_clicked(){

   QColor currentPriorityColour;
   currentPriorityColour.setRgb(priorityRed,priorityGreen,priorityBlue);

   QColor color = QColorDialog::getColor(currentPriorityColour, this);
   if( color.isValid() )
   {
     priorityRed = color.red();
     priorityGreen =color.green();
     priorityBlue =color.blue();
   }
}

void DialogPreferences::on_pushButtonPublicColour_clicked(){

    QColor currentPublicColour;
   currentPublicColour.setRgb(publicRed,publicGreen,publicBlue);

   QColor color = QColorDialog::getColor(currentPublicColour, this);
   if( color.isValid() )
   {
     publicRed = color.red();
     publicGreen =color.green();
     publicBlue =color.blue();
   }
}

//--------------------------------------------------------------------
// Reset All
//--------------------------------------------------------------------

bool DialogPreferences::isFactoryReset() {
  return factoryReset;
}

void DialogPreferences::on_checkBoxFactoryReset_stateChanged(int arg1) {
  if (arg1 == Qt::Unchecked) {
    factoryReset = false;
  } else if (arg1 == Qt::Checked) {
    factoryReset = true;
  }
}

//Talk

bool DialogPreferences::isTalkAtStartup() {
  return talkAtStartup;
}

bool DialogPreferences::isTalkUpcoming() {
  return talkUpcoming;
}

void DialogPreferences::on_checkBoxTalkStartup_stateChanged(int arg1) {
  if (arg1 == Qt::Unchecked) {
    talkAtStartup = false;
  } else if (arg1 == Qt::Checked) {
    talkAtStartup = true;
  }
}

void DialogPreferences::on_checkBoxUpcoming_stateChanged(int arg1) {
  if (arg1 == Qt::Unchecked) {
    talkUpcoming = false;
  } else if (arg1 == Qt::Checked) {
    talkUpcoming = true;
  }
}

int DialogPreferences::getUpcomingDayNumber() {
  return upcomingDays;
}

void DialogPreferences::on_spinBoxUpcomingDays_valueChanged(int arg1) {
  upcomingDays = arg1;
}
