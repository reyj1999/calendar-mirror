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
#include "dialogevent.h"
#include "ui_dialogevent.h"

DialogEvent::DialogEvent(QWidget *parent, QDate *theEventDate) : QDialog(parent),
                                                                 ui(new Ui::DialogEvent) {
  //New event
  ui->setupUi(this);

  ui->checkBoxDelete->hide();
  
  this->eventDate = *theEventDate;
  QString date = eventDate.toString("dddd dd MMMM yyyy");
  setWindowTitle("New Event (" + date + ")");

  ui->dateEditStart->setDate(eventDate);
  ui->dateEditEnd->setDate(eventDate);

  startDate= ui->dateEditStart->date();
  endDate= ui->dateEditEnd->date();


  //uncheck reminder
  ui->checkBoxReminder->setText("Reminder");
  setupComboBoxes();
  ui->checkBoxReminder->setCheckState(Qt::Unchecked);
  ui->checkBoxPriority->setCheckState(Qt::Unchecked);
  ui->comboBoxReminder->setCurrentIndex(0);
  ui->comboBoxReminder->setEnabled(false);

}
//-------------------------------------------------------------
// update
//-------------------------------------------------------------

DialogEvent::DialogEvent(QWidget *parent, Event *theEvent) : QDialog(parent),
                                                             ui(new Ui::DialogEvent) {
  //Update Event
  ui->setupUi(this);
  setWindowTitle("Update Event");
 
  startDate = QDate(theEvent->m_startYear, theEvent->m_startMonth, theEvent->m_startDay);
  endDate =QDate(theEvent->m_endYear, theEvent->m_endMonth, theEvent->m_endDay);

  ui->dateEditStart->setDate(startDate);
  ui->dateEditEnd->setDate(endDate);


  if(startDate != endDate) {

    //multiday event
    QString date = startDate.toString("dddd dd MMMM yyyy");
    setWindowTitle("Update Multiday Event: Starts (" + date + ")");

    ui->checkBoxAllDay->setEnabled(false);
    ui->checkBoxRepeatsYearly->setEnabled(false);
  }

  else {

    //single date
    QString date = startDate.toString("dddd dd MMMM yyyy");
    setWindowTitle("Update Event: (" + date + ")");

    ui->checkBoxAllDay->setEnabled(true);
    ui->checkBoxRepeatsYearly->setEnabled(true);

    if (theEvent->m_isYearly == 0) {
      ui->checkBoxRepeatsYearly->setCheckState(Qt::Unchecked);
    } else {
      ui->checkBoxRepeatsYearly->setCheckState(Qt::Checked);
    }

    isAllDay = theEvent->m_isAllDay;

    if (isAllDay == 1) {
      ui->checkBoxAllDay->setCheckState(Qt::Checked);
    }
  }

 
  ui->spinBoxStartTimeHour->setValue(theEvent->m_startHour);
  ui->spinBoxStartTimeMinute->setValue(theEvent->m_startMin);
  
  ui->spinBoxEndTimeHour->setValue(theEvent->m_endHour);
  ui->spinBoxEndTimeMinute->setValue(theEvent->m_endMin);
  

  setupComboBoxes();
  ui->checkBoxDelete->show();
     

  ui->lineEditSummary->setText(theEvent->m_summary);

  ui->lineEditLocation->setText(theEvent->m_location);
  //populate event description in dialog
   ui->textEditDescription->setText(theEvent->m_description);

  isPriority=theEvent->m_isPriority;
  
  if (isPriority >=1) {
    ui->checkBoxPriority->setCheckState(Qt::Checked);
  }
  
  //valid =false;
  this->hasReminder = theEvent->m_hasReminder;
  this->reminderMins = theEvent->m_reminderMinutes;


  if (hasReminder == 1) {
    ui->checkBoxReminder->setCheckState(Qt::Checked);
    ui->comboBoxReminder->setEnabled(true);

    if (reminderMins == 5) {
      ui->comboBoxReminder->setCurrentIndex(0);
    } else if (reminderMins == 10) {
      ui->comboBoxReminder->setCurrentIndex(1);
    } else if (reminderMins == 30) {
      ui->comboBoxReminder->setCurrentIndex(2);
    } else if (reminderMins == 60) {
      ui->comboBoxReminder->setCurrentIndex(3);
    } else if (reminderMins == 1440) {
      ui->comboBoxReminder->setCurrentIndex(4);
    }
  } else {
    ui->checkBoxReminder->setCheckState(Qt::Unchecked);
    ui->comboBoxReminder->setEnabled(false);
  }

    
}
//--------------------------------------------------------------

DialogEvent::~DialogEvent() {
  delete ui;
}

//OK button checks
void DialogEvent::on_pushButtonOk_clicked()
{
  //qDebug()<<"OK button clicked";
  //QDialog::accept();

 if (this->getSummary().isEmpty()) {
    QMessageBox::information(this, "Empty Details",
                             "Must enter an event summary");
    return;
  }

  else if ((startDate==endDate) && ((endHour < startHour) ||
    (endHour == startHour && endMin < startMin))) {
    QMessageBox::information(this, "Event Time Error",
                             "End time must be greater than start time");
    endHour = startHour;
    endMin = startMin;
    ui->spinBoxStartTimeHour->setValue(startHour);
    ui->spinBoxStartTimeMinute->setValue(startMin);

    ui->spinBoxEndTimeHour->setValue(endHour);
    ui->spinBoxEndTimeMinute->setValue(endMin);
    return;
    }
    else if (endDate < startDate) {
      //check if dates valid
      //qDebug()<<"error: endDate comes before startDate\n";

      QMessageBox::information(this, "Event Date Error",
                               "End date must be equal or greater than start date");

      //endDate=StartDate;
      ui->dateEditStart->setDate(eventDate);
      ui->dateEditEnd->setDate(eventDate);

      startDate= ui->dateEditStart->date();
      endDate= ui->dateEditEnd->date();
      return;

    }
    else {
      //checks ok
      QDialog::accept();
    }

}

//Cancel button
void DialogEvent::on_pushButtonCancel_clicked()
{
  //qDebug()<<"Cancel button clicked";
  QDialog::reject();
}

void DialogEvent::on_dateEditStart_dateChanged(const QDate &date)
{
 
  this->startDate = date;
  QString startDateStr = startDate.toString(); 

  if (startDate != endDate)
  {
    ui->checkBoxAllDay->setEnabled(false);
    ui->checkBoxRepeatsYearly->setEnabled(false);
  }
  else
  {
    ui->checkBoxAllDay->setEnabled(true);
    ui->checkBoxRepeatsYearly->setEnabled(true);
  }
}

void DialogEvent::on_dateEditEnd_dateChanged(const QDate &date)
{
  this->endDate = date;
  QString endDateStr = endDate.toString();
 

  if (startDate != endDate)
  {
    ui->checkBoxAllDay->setEnabled(false);
    ui->checkBoxRepeatsYearly->setEnabled(false);
  }
  else
  {
    ui->checkBoxAllDay->setEnabled(true);
    ui->checkBoxRepeatsYearly->setEnabled(true);
  }
}

QDate DialogEvent::getStartDate() {
  
  return startDate;
}

QDate DialogEvent::getEndDate() {

  return endDate;
}

QString DialogEvent::getSummary() {

	QString tStr =ui->lineEditSummary->text();

	tStr.replace(';', " ");
	tStr.replace('.', " ");
	tStr.replace(',', " ");
	//tStr.replace('\'', " "); //allow for words with an apostrophe
	tStr.replace('\"', " ");
	tStr.replace(QRegularExpression("[\\n|\\r|\\t]+"), " ");
  return tStr;
}

QString DialogEvent::getLocation() {
  QString locStr = ui->lineEditLocation->text();

	locStr.replace(';', " ");
	locStr.replace('.', " ");
	locStr.replace(',', " ");
	locStr.replace('\'', " ");
	locStr.replace('\"', " ");
	locStr.replace(QRegularExpression("[\\n|\\r|\\t]+"), " ");
  return locStr;
}



QString DialogEvent::getDescription() {
  return ui->textEditDescription->toPlainText();
}

int DialogEvent::getStartHour() {
  return this->startHour;
}

int DialogEvent::getStartMin() {
  return this->startMin;
}

int DialogEvent::getEndHour() {
  return this->endHour;
}

int DialogEvent::getEndMin() {
  return this->endMin;
}


int DialogEvent::getIsYearly() {
  return this->isYearly;
}

int DialogEvent::getIsAllDay() {
  return this->isAllDay;
}

int DialogEvent::getIsPriority() {
  return isPriority;
}

bool DialogEvent::getDeleteRequested() {
  return this->deleteRequested;
}

int DialogEvent::getHasReminder() {
  return this->hasReminder;
}

int DialogEvent::getReminderMins() {
  return this->reminderMins;
}

void DialogEvent::setupComboBoxes() {
  //Set up Reminder ComboBox
  ui->comboBoxReminder->addItem("5 Minutes Before Start");
  ui->comboBoxReminder->addItem("10 Minutes Before Start");
  ui->comboBoxReminder->addItem("30 Minutes Before Start");
  ui->comboBoxReminder->addItem("1 Hour Before Start");
  ui->comboBoxReminder->addItem("1 Day Before Start");
 
}


void DialogEvent::on_checkBoxAllDay_stateChanged(int arg1) {
  
  if (arg1 == Qt::Unchecked) {
  isAllDay = 0;     
  ui->spinBoxStartTimeHour->setEnabled(true);
  ui->spinBoxStartTimeMinute->setEnabled(true);  
  ui->spinBoxEndTimeHour->setEnabled(true);
  ui->spinBoxEndTimeMinute->setEnabled(true);
  
  
  } else if (arg1 == Qt::Checked) {
  isAllDay = 1;
  ui->spinBoxStartTimeHour->setEnabled(false);
  ui->spinBoxStartTimeMinute->setEnabled(false);  
  ui->spinBoxEndTimeHour->setEnabled(false);
  ui->spinBoxEndTimeMinute->setEnabled(false);
  
  }
}

void DialogEvent::on_comboBoxReminder_currentIndexChanged(int index) {
  if (index == 0) {
    reminderMins = 5;

  } else if (index == 1) {
    reminderMins = 10;

  } else if (index == 2) {
    reminderMins = 30;

  } else if (index == 3) {
    reminderMins = 60;

  } else if (index == 4) {
    reminderMins = 1440; //minutes in a day i.e. 1 day = (24 hours/day) × (60 minutes/hour) = 1440
  }
}

void DialogEvent::on_spinBoxStartTimeHour_valueChanged(int arg1) {
  this->startHour = arg1; 
}

void DialogEvent::on_spinBoxStartTimeMinute_valueChanged(int arg1) {
  this->startMin = arg1; 
}

void DialogEvent::on_spinBoxEndTimeHour_valueChanged(int arg1) {
  this->endHour = arg1; 
}

void DialogEvent::on_spinBoxEndTimeMinute_valueChanged(int arg1) {
  this->endMin = arg1; 
}

void DialogEvent::on_checkBoxPriority_stateChanged(int arg1) {
  if (arg1 == Qt::Unchecked) {
    isPriority = 0;
  } else if (arg1 == Qt::Checked) {
    isPriority = 1; 
  }
}


void DialogEvent::on_checkBoxRepeatsYearly_stateChanged(int arg1) {
  if (arg1 == Qt::Unchecked) {
    isYearly = 0;
  } else if (arg1 == Qt::Checked) {
    isYearly = 1; 
  }
}


void DialogEvent::on_checkBoxReminder_stateChanged(int arg1) {
  if (arg1 == Qt::Unchecked) {
    hasReminder = 0;
    reminderMins = 5;

    ui->comboBoxReminder->setEnabled(false);

  } else if (arg1 == Qt::Checked) {
    hasReminder = 1;
    //reminderMins=5;

    ui->comboBoxReminder->setEnabled(true);
  }
}

void DialogEvent::on_checkBoxDelete_stateChanged(int arg1) {
  if (arg1 == Qt::Unchecked) {
    deleteRequested = false;
  } else if (arg1 == Qt::Checked) {
    deleteRequested = true;
  }

  valid = true;
}

