/***************************************************************************
 *   Author Alan Crispin                  *
 *   crispinalan@gmail.com                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation.                                 *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/
#ifndef DIALOGEVENT_H
#define DIALOGEVENT_H

#include <QDialog>
#include <QDate>
#include <QTime>
#include <QDebug>
#include <QMessageBox>


#include "event.h"
#include "dialogwords.h"

namespace Ui {
class DialogEvent;
}

class DialogEvent : public QDialog
{
    CS_OBJECT(DialogEvent)

public:
   
    explicit DialogEvent(QWidget *parent = nullptr, QDate *theEventDate=nullptr);
    explicit DialogEvent(QWidget *parent = nullptr, Event *theEvent=nullptr);
    ~DialogEvent();


    QString getSummary();
    QString getLocation();
    QString getDescription();

    QDate getStartDate();
    QDate getEndDate();
    
    int getStartHour();
    int getStartMin();
    int getEndHour();
    int getEndMin();
  
  
    int getIsYearly();   
    int getIsAllDay();    
    int getIsPriority();  
    bool getDeleteRequested();
    int getHasReminder();
    int getReminderMins();


private :
    //OK Cancel
	CS_SLOT_1(Private, void on_pushButtonOk_clicked()) 
    CS_SLOT_2(on_pushButtonOk_clicked)
    
    CS_SLOT_1(Private, void on_pushButtonCancel_clicked()) 
    CS_SLOT_2(on_pushButtonCancel_clicked)

    //speech words
    CS_SLOT_1(Private, void on_pushButtonSpeechWord_clicked()) 
    CS_SLOT_2(on_pushButtonSpeechWord_clicked)

    //DateEdits
    CS_SLOT_1(Private, void on_dateEditStart_dateChanged(const QDate & date))
    CS_SLOT_2(on_dateEditStart_dateChanged) 
    
    CS_SLOT_1(Private, void on_dateEditEnd_dateChanged(const QDate & date))
    CS_SLOT_2(on_dateEditEnd_dateChanged) 


    CS_SLOT_1(Private, void on_checkBoxAllDay_stateChanged(int arg1))
    CS_SLOT_2(on_checkBoxAllDay_stateChanged) 

    CS_SLOT_1(Private, void on_comboBoxReminder_currentIndexChanged(int index))
    CS_SLOT_2(on_comboBoxReminder_currentIndexChanged) 
    
    CS_SLOT_1(Private, void on_spinBoxStartTimeHour_valueChanged(int arg1))
    CS_SLOT_2(on_spinBoxStartTimeHour_valueChanged) 
    
    CS_SLOT_1(Private, void on_spinBoxStartTimeMinute_valueChanged(int arg1))
    CS_SLOT_2(on_spinBoxStartTimeMinute_valueChanged) 
    
    CS_SLOT_1(Private, void on_spinBoxEndTimeHour_valueChanged(int arg1))
    CS_SLOT_2(on_spinBoxEndTimeHour_valueChanged) 
    
    CS_SLOT_1(Private, void on_spinBoxEndTimeMinute_valueChanged(int arg1))
    CS_SLOT_2(on_spinBoxEndTimeMinute_valueChanged) 
    
    CS_SLOT_1(Private, void on_checkBoxPriority_stateChanged(int arg1))
    CS_SLOT_2(on_checkBoxPriority_stateChanged)
   
    CS_SLOT_1(Private, void on_checkBoxRepeatsYearly_stateChanged(int arg1))
    CS_SLOT_2(on_checkBoxRepeatsYearly_stateChanged) 

    CS_SLOT_1(Private, void on_checkBoxReminder_stateChanged(int arg1))
    CS_SLOT_2(on_checkBoxReminder_stateChanged) 

    CS_SLOT_1(Private, void on_checkBoxDelete_stateChanged(int arg1))
    CS_SLOT_2(on_checkBoxDelete_stateChanged) 
  
    
private:
    Ui::DialogEvent *ui;

    QDate startDate;
    QDate endDate;
    QDate eventDate;

    int startHour=0;
    int startMin=0;
    int endHour=0;
    int endMin=0;
    
    int isYearly=0;
    int isMonthly=0;
    int isAllDay=0; //no
    int isPriority =0;  
    QString title="";
   
    //Reminders
    int hasReminder=0; //no
    int reminderMins=0; //none
    bool deleteRequested=false;
    bool valid =false; //valid event

    void setupComboBoxes();

};

#endif // DIALOGEVENT_H
