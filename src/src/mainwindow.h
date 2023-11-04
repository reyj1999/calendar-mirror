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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDate>
#include <QDebug>
#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QTextCharFormat>
#include <QTextEdit>
#include <QTime>
#include <QTimer>

#include <QDesktopServices>
#include <QDomDocument>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QKeyEvent>
#include <QList>
#include <QSettings>

#include <QTableWidgetItem>
#include <QUrl>
#include <QXmlStreamWriter>
#include <QDateTime>
//audio
#include <QSound>
#include <QSoundEffect>
#include <QEventLoop>
#include <QRegularExpression>
#include <QProcess>


#include <QColorDialog>
#include <QMediaPlayer>
#include <QMediaPlayerControl>

#include "daylistmodel.h"
#include "dialogevent.h"
#include "event.h"
#include "preferences.h"
#include "dialogpreferences.h"
#include "speechengine.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    CS_OBJECT(MainWindow)

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
      
 protected:
    void closeEvent(QCloseEvent *event) override;     
    void resizeEvent(QResizeEvent *e) override;
    
private :	
	
	//keyboard and action slots
	CS_SLOT_1(Private, void gotoNextMonthSlot())
	CS_SLOT_2(gotoNextMonthSlot) 
    CS_SLOT_1(Private, void gotoNextYearSlot())
	CS_SLOT_2(gotoNextYearSlot)

    CS_SLOT_1(Private, void gotoPreviousMonthSlot())
	CS_SLOT_2(gotoPreviousMonthSlot) 
    CS_SLOT_1(Private, void gotoPreviousYearSlot())
	CS_SLOT_2(gotoPreviousYearSlot)

    CS_SLOT_1(Private, void gotoTodaySlot())
	CS_SLOT_2(gotoTodaySlot)
	
    //calendar table widget
	CS_SLOT_1(Private, void on_tableWidgetCalendar_cellClicked(int row,int column))
	CS_SLOT_2(on_tableWidgetCalendar_cellClicked)  
	
	//new event
	CS_SLOT_1(Private, void newEventSlot())
	CS_SLOT_2(newEventSlot)
		
	//timer
	CS_SLOT_1(Private, void timerUpdateSlot())
	CS_SLOT_2(timerUpdateSlot)
	
	//menu actions		
	// new, export calendar, import calendar
	CS_SLOT_1(Private, void on_actionNew_Event_triggered())
	CS_SLOT_2(on_actionNew_Event_triggered)
	
	CS_SLOT_1(Private, void on_actionImport_Calendar_triggered())
	CS_SLOT_2(on_actionImport_Calendar_triggered)
	
	CS_SLOT_1(Private, void on_actionExport_Calendar_triggered())
	CS_SLOT_2(on_actionExport_Calendar_triggered)

    CS_SLOT_1(Private, void on_actionImport_ICS_File_triggered())
	CS_SLOT_2(on_actionImport_ICS_File_triggered)
	
	//exit action
	CS_SLOT_1(Private, void on_actionExit_triggered())
	CS_SLOT_2(on_actionExit_triggered) 
	
	//edit
	CS_SLOT_1(Private, void on_actionPreferences_triggered())
	CS_SLOT_2(on_actionPreferences_triggered)
	

	//events
	CS_SLOT_1(Private, void on_actionNew_triggered())
	CS_SLOT_2(on_actionNew_triggered)

    CS_SLOT_1(Private, void on_actionSpeak_Event_triggered())
	CS_SLOT_2(on_actionSpeak_Event_triggered)
	
	CS_SLOT_1(Private, void on_actionUpdate_Selected_Event_triggered())
	CS_SLOT_2(on_actionUpdate_Selected_Event_triggered)
		
	CS_SLOT_1(Private, void on_actionDelete_All_Events_triggered())
	CS_SLOT_2(on_actionDelete_All_Events_triggered)
	
	//tools	
	
	CS_SLOT_1(Private, void on_actionCapacity_Check_triggered())
	CS_SLOT_2(on_actionCapacity_Check_triggered)

    CS_SLOT_1(Private, void on_actionSpeak_Test_triggered())
	CS_SLOT_2(on_actionSpeak_Test_triggered)
		
  
    //navigation
    CS_SLOT_1(Private, void on_actionGoto_Today_triggered())
	CS_SLOT_2(on_actionGoto_Today_triggered)

    CS_SLOT_1(Private, void on_actionGoto_Next_Month_triggered())
	CS_SLOT_2(on_actionGoto_Next_Month_triggered)

	CS_SLOT_1(Private, void on_actionGoto_Previous_Month_triggered())
	CS_SLOT_2(on_actionGoto_Previous_Month_triggered)

    CS_SLOT_1(Private, void on_actionGoto_Next_Year_triggered())
	CS_SLOT_2(on_actionGoto_Next_Year_triggered)

    CS_SLOT_1(Private, void on_actionGoto_Previous_Year_triggered())
	CS_SLOT_2(on_actionGoto_Previous_Year_triggered)

    //pushButton navigation

    CS_SLOT_1(Private, void on_pushButtonNextMonth_clicked()) 
    CS_SLOT_2(on_actionGoto_Next_Month_triggered)
    
    CS_SLOT_1(Private, void on_pushButtonPreviousMonth_clicked()) 
    CS_SLOT_2(on_actionGoto_Previous_Month_triggered)
   
    CS_SLOT_1(Private, void on_pushButtonNextYear_clicked()) 
    CS_SLOT_2(on_actionGoto_Next_Year_triggered)
     
    CS_SLOT_1(Private, void on_pushButtonPreviousYear_clicked()) 
    CS_SLOT_2(on_actionGoto_Previous_Year_triggered)
	
	//about
	CS_SLOT_1(Private, void on_actionAbout_triggered())
	CS_SLOT_2(on_actionAbout_triggered)
	
	//list view slots
	CS_SLOT_1(Private, void on_listViewDay_doubleClicked(const QModelIndex &index))
	CS_SLOT_2(on_listViewDay_doubleClicked)
	
	CS_SLOT_1(Private, void on_listViewDay_clicked(const QModelIndex &index))
	CS_SLOT_2(on_listViewDay_clicked)
	
	//escape list view
    CS_SLOT_1(Private, void escapeSlot())
    CS_SLOT_2(escapeSlot)

    //speaking
    CS_SLOT_1(Private, void speechSlot())
    CS_SLOT_2(speechSlot)

    //Upcoming events
    CS_SLOT_1(Private, void upcomingSlot())
    CS_SLOT_2(upcomingSlot)


    
private:
    Ui::MainWindow *ui;
    
   
  //Event List
  QList<Event> eventList; //all events 

  void newEvent();
  void updateEvent(int id, int selectedRowindex);
 
  void updateEventInEventList(Event evt, int eventId);
  void removeEventFromEventList(int eventId);
  void clearEventList();
 
  //Models
  DayListModel *dayListModel;
 
  void showEventsOnListViewDay(QDate theSelectedDate);

  QList<Event> getDayList(QDate theDate);
  QList<Event> getDayListCurrent(QDate theDate);

  QList<Event> getTimeSortedDayList(QDate theDate);
   
  int getNumberOfDayEvents(QDate theDate);
  bool getIsPriority(QDate theDate);

  bool getIsPublicHoliday(QDate theDate);
  
  //Event items
  int eventId = 0;
  QString summary = "";
  QString location = "";
  QString description = "";
  int year = 2020;
  int month = 1;
  int day = 1;
  int startHour = 9;
  int startMin = 0;
  int endHour = 10;
  int endMin = 0;
  int isYearly = 0; 
  int isAllDay = 0;
  int colour = 0;
  int priority = 0;
  int hasReminder = 0;
  int reminderMinutes = 0;
  
  
  //Dates
  QDate selectedDate;
  QDateTime dateTime;
  int selectedYear=2000;
  int selectedMonth=1;
  int selectedDay=1;
  int firstDay=1;
  QLabel *selectedDateLabel;
  QLabel *dateStatusBarLabel;

  
  //Widget Calendar
  int columnCount=7;
  int rowCount=6;
  //int dayArray[6][7];
  int dayArray[6*7];
  void updateCalendar();   

  void setCalendarStyle(bool flag);
  
  QColor todayBackgroundColour;
  QColor eventBackgroundColour;
  QColor priorityBackgroundColour;
  QColor publicHolidayBackgroundColour;
  
  QHash<int, QString> lookupShortDay;
  void setupLookupShortDay();
  
  QTableWidgetItem *dayItem;
  QTableWidgetItem *eventItem;
  
  
  //Navigation   
  void gotoNextMonth();
  void gotoPreviousMonth();
  void gotoNextYear();
  void gotoPreviousYear();
  void gotoToday();
  //void showDayEvents();
  QHash<int, QString> lookupMonth;
  void setupLookupMonth();

  //actions

  QAction *gotoNextMonthAction;
  QAction *gotoNextYearAction;
  QAction *gotoPreviousMonthAction;
  QAction *gotoPreviousYearAction;
  QAction *gotoTodayAction;  
  QAction *newEventAction;
  QAction *escapeAction;
 
  //speak actions
  QAction *spacebarAction;
  QAction *upcomingAction;

  QString getPublicHoliday(QDate date);
  QDate calculateEaster(int year);

  //Actions
  QAction *keyQAction;
   
  //Timers
  QTimer *timer;
  QLabel *timeLabel;
  QDateTime dateTimeNow;

  //Reminders
  void checkForReminders();
  void checkForScanHour();

  void speakReminder();

  QList<Event> findUpcomingEvents();

  Preferences currentPreferences;
  void setPreferences();
  bool loadSettings();
  void saveSettings();
  void setDefaultPreferences();

  void setApplicationFontSize(int fontSize);
  void setWindowSize(int width, int height);

  void loadEvents();
  void reloadEvents();
  void saveEvents();

  //Export Import
  void exportCalendar();
  void importCalendar();
  void parseICSFile();
  QTextStream textStream;
 
  SpeechEngine *speech;

  bool directoryExists(QString path);
  bool fileExists(QString path);
    //event selection
  int selectedRowIdx=0;  
  
};

#endif // MAINWINDOW_H
