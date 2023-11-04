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

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  setWindowTitle("Casper Calendar");
  QMainWindow::centralWidget()->layout()->setContentsMargins(1, 1, 1, 1);
  // Sets the left, top, right, and bottom margins to use around the layout
  setWindowIcon(QIcon(":/icons/casper.png"));
  QMainWindow::resize(600, 650);

  // setup the event list
  eventList = QList<Event>();
  // set up day model
  dayListModel = new DayListModel;
  ui->listViewDay->setWordWrap(true);

  setupLookupMonth();
  setupLookupShortDay();

  QString config_file = QString::fromStdString(getenv("HOME"));
  config_file.append("/.config/casper-calendar/settings.conf");

  if (!fileExists(config_file))
  {
    setDefaultPreferences();
  }
  else
  {
    loadSettings();
  }

  setApplicationFontSize(currentPreferences.m_appFontSize);
  setWindowSize(currentPreferences.m_windowWidth, currentPreferences.m_windowHeight);

  eventBackgroundColour.setRgb(currentPreferences.m_eventRed,
                               currentPreferences.m_eventGreen,
                               currentPreferences.m_eventBlue, 255);

  todayBackgroundColour.setRgb(currentPreferences.m_todayRed,
                               currentPreferences.m_todayGreen,
                               currentPreferences.m_todayBlue, 255);

  priorityBackgroundColour.setRgb(currentPreferences.m_priorityRed,
                                  currentPreferences.m_priorityGreen,
                                  currentPreferences.m_priorityBlue, 255);

  publicHolidayBackgroundColour.setRgb(currentPreferences.m_publicRed,
                                       currentPreferences.m_publicGreen,
                                       currentPreferences.m_publicBlue);

  selectedDate = QDate::currentDate();

  dateStatusBarLabel = new QLabel(this);
  dateStatusBarLabel->setText(tr("Selected Date: "));
  selectedDateLabel = new QLabel(this);
  QFont font1 = selectedDateLabel->font();
  font1.setWeight(QFont::Bold);
  selectedDateLabel->setFont(font1);

  selectedDateLabel->setText(selectedDate.toString());

  ui->statusBar->insertPermanentWidget(0, dateStatusBarLabel, 2);
  ui->statusBar->insertPermanentWidget(1, selectedDateLabel, 10);

  selectedMonth = selectedDate.month();
  selectedYear = selectedDate.year();

  // Setup widget Calendar
  ui->tableWidgetCalendar->setColumnCount(columnCount);
  ui->tableWidgetCalendar->setRowCount(rowCount);
  ui->tableWidgetCalendar->horizontalHeader()->setVisible(true);
  ui->tableWidgetCalendar->verticalHeader()->setVisible(false);
  ui->tableWidgetCalendar->setShowGrid(true);
  ui->tableWidgetCalendar->setGridStyle(Qt::SolidLine);
  ui->tableWidgetCalendar->setEditTriggers(QAbstractItemView::NoEditTriggers); // read only

  // day selection
  QPalette p = ui->tableWidgetCalendar->palette();
  p.setBrush(QPalette::Window, ui->tableWidgetCalendar->window()->palette().brush(QPalette::Window));
  ui->tableWidgetCalendar->setPalette(p);

  // Cell Resizing
  ui->tableWidgetCalendar->setWordWrap(true);
  ui->tableWidgetCalendar->setTextElideMode(Qt::ElideRight);
  // ui->tableWidgetCalendar->resizeRowsToContents();

  for (int row = 0; row < ui->tableWidgetCalendar->rowCount(); ++row)
  {
    ui->tableWidgetCalendar->verticalHeader()->setSectionResizeMode(row, QHeaderView::Stretch);
  }

  for (int col = 0; col < ui->tableWidgetCalendar->columnCount(); ++col)
  {
    ui->tableWidgetCalendar->horizontalHeader()->setSectionResizeMode(col, QHeaderView::Stretch);
    // ui->tableWidgetCalendar->setItemDelegateForColumn(col, &elideLeftItem);
  }

  firstDay = Qt::Monday;

  // Keyboard QActions (shortcuts)
  //----------------------------
  gotoTodayAction = new QAction(this);
  gotoTodayAction->setShortcut(Qt::Key_Home);
  connect(gotoTodayAction, SIGNAL(triggered()), this, SLOT(gotoTodaySlot()));
  this->addAction(gotoTodayAction);

  QString monthYearStr = "";
  // monthYearStr.append(QString::number(selectedDate.month()));
  QString monthStr = lookupMonth.value(selectedDate.month());
  monthYearStr.append(monthStr);
  monthYearStr.append(" ");
  monthYearStr.append(QString::number(selectedDate.year()));
  ui->labelMonthYear->setText(monthYearStr);

  // keyboard actions
  gotoNextMonthAction = new QAction(this);
  gotoNextMonthAction->setShortcut(Qt::Key_Right);
  connect(gotoNextMonthAction, SIGNAL(triggered()), this, SLOT(gotoNextMonthSlot()));
  this->addAction(gotoNextMonthAction);

  gotoNextYearAction = new QAction(this);
  gotoNextMonthAction->setShortcut(Qt::Key_Up);
  connect(gotoNextYearAction, SIGNAL(triggered()), this, SLOT(gotoNextYearSlot()));
  this->addAction(gotoNextYearAction);

  gotoPreviousMonthAction = new QAction(this);
  gotoPreviousMonthAction->setShortcut(Qt::Key_Left);
  connect(gotoPreviousMonthAction, SIGNAL(triggered()), this, SLOT(gotoPreviousMonthSlot()));
  this->addAction(gotoPreviousMonthAction);

  gotoPreviousYearAction = new QAction(this);
  gotoPreviousMonthAction->setShortcut(Qt::Key_Down);
  connect(gotoPreviousYearAction, SIGNAL(triggered()), this, SLOT(gotoPreviousYearSlot()));
  this->addAction(gotoPreviousYearAction);

  spacebarAction = new QAction(this);
  spacebarAction->setShortcut(Qt::Key_Space);
  connect(spacebarAction, SIGNAL(triggered()), this, SLOT(speechSlot()));
  this->addAction(spacebarAction);

  upcomingAction = new QAction(this);
  upcomingAction->setShortcut(Qt::Key_U);
  connect(upcomingAction, SIGNAL(triggered()), this, SLOT(upcomingSlot()));
  this->addAction(upcomingAction);

  newEventAction = new QAction(this);
  newEventAction->setShortcut(Qt::Key_Insert);
  newEventAction->setStatusTip(tr("New Event"));
  connect(newEventAction, SIGNAL(triggered()), this, SLOT(newEventSlot()));
  this->addAction(newEventAction);

  escapeAction = new QAction(this);
  escapeAction->setShortcut(Qt::Key_Escape);
  escapeAction->setStatusTip(tr("Escape Day View"));
  connect(escapeAction, SIGNAL(triggered()), this, SLOT(escapeSlot()));
  this->addAction(escapeAction);

  // setup timer
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdateSlot()));
  timer->start(1000); // check for reminders every 1000ms
  QTime currentTime = QTime::currentTime();

  // set up timelabel

  int currentHour = currentTime.hour();
  int currentMinute = currentTime.minute();
  QString timeNow = QString::number(currentHour) + ":" + QString::number(currentMinute);
  dateTimeNow = dateTimeNow.currentDateTime();
  timeLabel = new QLabel(this);
  QFont fontTimeLabel = timeLabel->font();
  fontTimeLabel.setWeight(QFont::Bold);
  timeLabel->setText(dateTimeNow.time().toString("h:mm ap"));
  ui->statusBar->addPermanentWidget(timeLabel);

  speech = new SpeechEngine();

  loadEvents();

  if (currentPreferences.m_talkAtStartup)
  {
    speechSlot(); //  speak at startup
  }

  if (currentPreferences.m_darkStyle)
    setCalendarStyle(1);
  else
    setCalendarStyle(0);

  updateCalendar();
  showEventsOnListViewDay(selectedDate);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::resizeEvent(QResizeEvent *e)
{
  //store last used size
  currentPreferences.m_windowWidth=e->size().width();
  currentPreferences.m_windowHeight=e->size().height();
 

}

void MainWindow::setWindowSize(int width,int height){

  this->resize(width,height);
}

//Menu actions

void MainWindow::on_actionNew_triggered() {  
  eventList.clear();    
  selectedDate = QDate::currentDate(); 
  updateCalendar();  
  showEventsOnListViewDay(selectedDate);    
  gotoTodaySlot();  
}
void MainWindow::on_actionExport_Calendar_triggered() { 
  exportCalendar();
}
void MainWindow::on_actionImport_Calendar_triggered() {  
  importCalendar();
}

void MainWindow::on_actionImport_ICS_File_triggered() {
parseICSFile();
}

void MainWindow::on_actionExit_triggered()
{
    saveSettings();
    saveEvents();
    QApplication::quit();
}
void MainWindow::on_actionPreferences_triggered() {
	 setPreferences();    
}

void MainWindow::on_actionNew_Event_triggered() {
  newEvent();
}

void MainWindow::on_actionSpeak_Event_triggered() {
  //qDebug()<<"speak menu item selected\n";
  speechSlot();
}



void MainWindow::on_actionUpdate_Selected_Event_triggered() {
  
  //need to check that events exist before trying to update
  if(dayListModel->rowCount() == 0) return;  
  Event tmp = dayListModel->getEvent(selectedRowIdx); 
  int id = tmp.m_id;
  updateEvent(id, selectedRowIdx); 
}

void MainWindow::on_actionDelete_All_Events_triggered() {
   
  QMessageBox msgBox;
  msgBox.setWindowTitle("Delete All Events");
  msgBox.setText("Delete all events?");
  msgBox.setStandardButtons(QMessageBox::Yes);
  msgBox.addButton(QMessageBox::No);
  msgBox.setDefaultButton(QMessageBox::No);  
  if (msgBox.exec() == QMessageBox::Yes) {   
  eventList.clear();    
  selectedDate = QDate::currentDate(); 
  updateCalendar();
  showEventsOnListViewDay(selectedDate);  
  gotoTodaySlot(); 
  } else 
  {
   // cancel
    return;
  }  
  
}


void MainWindow::on_actionCapacity_Check_triggered() {

  int numberOfEvents=eventList.count();  
  QString info = "You have ";
  info.append(QString::number(numberOfEvents));
  if (numberOfEvents == 1) {
    info.append(" event in your calendar.");
  } else {
    info.append(" events in your calendar.");
  }
  info.append("\n");
  info.append("Back up calendar using file export.");
 
  QMessageBox::information(this, "Capacity Check",
                           info);

}

void MainWindow::on_actionSpeak_Test_triggered() {

		speech = new SpeechEngine();
	speech->speak("Casper Calendar");
	
	QString diphonePath = QApplication::applicationDirPath() + "/diphone/";
	
	if (!directoryExists(diphonePath))
	{	
	QString str = "Diphones do not exist."
	"\nInstall diphone folder to application path.";	
	QMessageBox::information(this, "Diphones Missing", str);
	return;
	}
	
	if (fileExists("/tmp/talkout.wav"))
	{	
	QMediaPlayer *player = new QMediaPlayer;
	player->setMedia(QUrl::fromLocalFile("/tmp/talkout.wav"));    
	player->setPlaybackRate(1.25);  
	player->play();
	}
	else
	{
	// to do..
	//qDebug() << "missing talk file";
	}
}

void MainWindow::speakReminder() {

	speech = new SpeechEngine();
	speech->speak("Casper Calendar reminder");
	
	QString diphonePath = QApplication::applicationDirPath() + "/diphone/";
	
	if (!directoryExists(diphonePath))
	{	
	QString str = "Diphones do not exist."
	"\nInstall diphone folder to application path.";	
	QMessageBox::information(this, "Diphones Missing", str);
	return;
	}
		
	if (fileExists("/tmp/talkout.wav"))
	{	
	QMediaPlayer *player = new QMediaPlayer;
	player->setMedia(QUrl::fromLocalFile("/tmp/talkout.wav"));    
	player->setPlaybackRate(1.25);  
	player->play();
	}
	else
	{
	// to do..
	//qDebug() << "missing talk file";
	}	
}


void MainWindow::on_actionAbout_triggered() {
		QString about_text = "Casper Calendar is a talking calendar. "
		"This version uses a built-in diphone speech synthesizer. "
		"Built with CopperSpice 1.8.2 on Debian 12 Bookworm. "
		"\nAlan Crispin (2023)";
		QMessageBox::information(this, "Casper Calendar v0.3.0",about_text);
}

//Navigation

void MainWindow::on_actionGoto_Today_triggered(){
	gotoTodaySlot();
}

void MainWindow::on_actionGoto_Next_Month_triggered(){
	 gotoNextMonth();
}
void MainWindow::on_actionGoto_Previous_Month_triggered(){
	 gotoPreviousMonth();
}
void MainWindow::on_actionGoto_Next_Year_triggered(){
	 gotoNextYear();
}
void MainWindow::on_actionGoto_Previous_Year_triggered(){
	 gotoPreviousYear();
}

//-------------------------------------------------------------------
// slots
//-------------------------------------------------------------------

void MainWindow::newEventSlot() {
  newEvent();
}

void MainWindow::escapeSlot() {
  ui->tableWidgetCalendar->setFocus();
}

void MainWindow::timerUpdateSlot() {
  //Current time
  dateTimeNow = dateTimeNow.currentDateTime();
  timeLabel->setText(dateTimeNow.time().toString("h:mm ap"));
  checkForReminders();
}

void MainWindow::closeEvent(QCloseEvent *event)
{    
    saveSettings();
    saveEvents();
}

//--------------------------------------------------------------------
// New Event
//--------------------------------------------------------------------
void MainWindow::newEvent()
{
  DialogEvent *eventDialog = new DialogEvent(this, &selectedDate);
  eventDialog->setModal(true);
  if (eventDialog->exec() == QDialog::Accepted)
  {

    Event evt;
    evt.m_summary = eventDialog->getSummary();
    evt.m_location = eventDialog->getLocation();
    evt.m_description = eventDialog->getDescription();

    QDate startDate = eventDialog->getStartDate();
    evt.m_startYear = startDate.year();
    evt.m_startMonth = startDate.month();
    evt.m_startDay = startDate.day();
    evt.m_startHour = eventDialog->getStartHour();
    evt.m_startMin = eventDialog->getStartMin();

    QDate endDate = eventDialog->getEndDate();   
    evt.m_endYear = endDate.year();
    evt.m_endMonth = endDate.month();
    evt.m_endDay = endDate.day();
    evt.m_endHour = eventDialog->getEndHour();
    evt.m_endMin = eventDialog->getEndMin();

    evt.m_isYearly = eventDialog->getIsYearly();
    evt.m_isAllDay = eventDialog->getIsAllDay();

    evt.m_isPriority = eventDialog->getIsPriority();
    evt.m_hasReminder = eventDialog->getHasReminder();
    evt.m_reminderMinutes = eventDialog->getReminderMins();

    evt.m_id = eventList.count(); // append to end
    eventList.append(evt);
    updateCalendar();
    showEventsOnListViewDay(selectedDate);    
  }
}

//---------------------------------------------------------------------
// Update event
//---------------------------------------------------------------------
void MainWindow::updateEvent(int id, int selectedRowindex) {
  
 //qDebug()<<"UpdateEvent: id = "<<id<<" selectedRowIndex = "<<selectedRowindex<<"\n";
  Event currentEvent = eventList.at(id);
  DialogEvent *eventDialog = new DialogEvent(this, &currentEvent);
  eventDialog->setModal(true);

  if (eventDialog->exec() == QDialog::Accepted) {

    //---------------Delete requested -------------------
    if (eventDialog->getDeleteRequested()) {

      removeEventFromEventList(id);
      //crashes ocasionally here ..try..

      saveEvents();
      reloadEvents();
      showEventsOnListViewDay(selectedDate);
      updateCalendar();      

      return;
    }
    //---------------Update-----------------------

    Event evt;
	evt.m_summary = eventDialog->getSummary();
    evt.m_location= eventDialog->getLocation();
	evt.m_description = eventDialog->getDescription();

    QDate startDate =eventDialog->getStartDate();

	evt.m_startYear = startDate.year();
	evt.m_startMonth = startDate.month();
	evt.m_startDay = startDate.day();
	evt.m_startHour = eventDialog->getStartHour();
	evt.m_startMin = eventDialog->getStartMin();

    QDate endDate =eventDialog->getEndDate();
    evt.m_endYear = endDate.year();
	evt.m_endMonth = endDate.month();
	evt.m_endDay = endDate.day();
    evt.m_endHour = eventDialog->getEndHour();
	evt.m_endMin = eventDialog->getEndMin();

	evt.m_isYearly = eventDialog->getIsYearly();
	evt.m_isAllDay = eventDialog->getIsAllDay();

	evt.m_isPriority = eventDialog->getIsPriority();
	evt.m_hasReminder = eventDialog->getHasReminder();
	evt.m_reminderMinutes = eventDialog->getReminderMins();

    //---------------Update-----------------------

    //remove and re-insert (more todo here)
    removeEventFromEventList(id);
    evt.m_id=eventList.count(); //append to end
    eventList.append(evt);
    saveEvents();
    reloadEvents();
    showEventsOnListViewDay(selectedDate);
    updateCalendar();    

  } //if dialog accepted
  
}

//---------------------------------------------------------
// eventlist methods
//----------------------------------------------------------
void MainWindow::updateEventInEventList(Event evt, int eventId) {
  for (int i = 0; i < eventList.count(); i++) {
    Event e = eventList.at(i);

    if (e.m_id == eventId) {
      eventList.removeAt(i);
      eventList.insert(i, evt);
    }
  }
}


void MainWindow::removeEventFromEventList(int eventId) {
  for (int i = 0; i < eventList.count(); i++) {
    Event e = eventList.at(i);

    if (e.m_id == eventId) {
      eventList.removeAt(i);
    }
  }
}


void MainWindow::clearEventList() {
  eventList.clear();
}


bool MainWindow::getIsPriority(QDate theDate){
	
	bool isPriority=false;
	
	for (int i = 0; i < eventList.size(); i++) {
    Event e = eventList.at(i);
    QDate edate = QDate(e.m_startYear, e.m_startMonth, e.m_startDay);
    if (edate == theDate) {
	 if(e.m_isPriority) isPriority=true;
    }
    //yearly events
    if(e.m_startDay == theDate.day() && e.m_startMonth ==theDate.month()
    && e.m_startYear!=theDate.year() && e.m_isYearly==1) {
	if(e.m_isPriority) isPriority=true;
    }  
	}	
	return isPriority;
}


bool MainWindow::getIsPublicHoliday(QDate theDate){

  bool isHoliday =false;

  QString holStr =getPublicHoliday(theDate);

  if(holStr!="") isHoliday =true;

  return isHoliday;;

}
//-------------------------------------------------------------
// public holidays
//--------------------------------------------------------------

QString MainWindow::getPublicHoliday(QDate date) {
  QString holStr = "";
  int year = date.year();
  int month = date.month();

  if (date == QDate(year, 12, 25))
    holStr = " Christmas";
  if (date == QDate(year, 12, 26))
    holStr = " Boxing Day";
  if (date == QDate(year, 1, 1))
    holStr = " New Year";

  QDate easterDate = calculateEaster(year);
  if (date == easterDate)
    holStr = " Easter";
  if (date == easterDate.addDays(-2))
    holStr = " Good Friday";
  if (date == easterDate.addDays(1))
    holStr = " Easter Monday";

  QDate firstMondayMay(year, 5, 1);
  while (firstMondayMay.dayOfWeek() != Qt::Monday)
    firstMondayMay = firstMondayMay.addDays(1);
  if (date == firstMondayMay)
    holStr = " May Day";
  int daysInMay = QDate(year, month, 1).daysInMonth();
  int plusDays = 0;
  if (firstMondayMay.day() + 28 <= daysInMay) {
    plusDays = 28;
  } else {
    plusDays = 21;
  }
  QDate springbank = firstMondayMay.addDays(plusDays); //spring bank
  if (springbank.isValid()) {
    if (date == springbank)
      holStr = " Spring Bank";
  }

  QDate firstMondayAug(year, 8, 1);
  while (firstMondayAug.dayOfWeek() != Qt::Monday)
    firstMondayAug = firstMondayAug.addDays(1);
  int daysInAugust = QDate(year, 8, 1).daysInMonth();
  int plusAugDays = 0;
  if (firstMondayAug.day() + 28 <= daysInAugust) {
    plusAugDays = 28;
  } else {
    plusAugDays = 21;
  }
  QDate summerBankHol = firstMondayAug.addDays(plusAugDays);
  if (summerBankHol.isValid()) {
    if (date == summerBankHol)
      holStr = " August Bank Holiday";
  }

  return holStr;
}

QDate MainWindow::calculateEaster(int year) {
  QDate easter;
  int Yr = year;
  int a = Yr % 19;
  int b = Yr / 100;
  int c = Yr % 100;
  int d = b / 4;
  int e = b % 4;
  int f = (b + 8) / 25;
  int g = (b - f + 1) / 3;
  int h = (19 * a + b - d - g + 15) % 30;
  int i = c / 4;
  int k = c % 4;
  int L = (32 + 2 * e + 2 * i - h - k) % 7;
  int m = (a + 11 * h + 22 * L) / 451;
  int month = (h + L - 7 * m + 114) / 31;
  int day = ((h + L - 7 * m + 114) % 31) + 1;

  easter.setDate(year, month, day);
  return easter;
}


//------------------------------------------------------------
// Listview
//-------------------------------------------------------------
void MainWindow::showEventsOnListViewDay(QDate theSelectedDate)
{
  dayListModel->clearAllEvents();
  QList<Event> dayList = getDayList(theSelectedDate);
  dayListModel = new DayListModel(dayList);
  dayListModel->isDarkStyle(currentPreferences.m_darkStyle);
  dayListModel->is12HourFormat(currentPreferences.m_12HourFormat);
  ui->listViewDay->setModel(dayListModel);
}

void MainWindow::on_listViewDay_clicked(const QModelIndex &index) { 
  selectedRowIdx = index.row();  
}

void MainWindow::on_listViewDay_doubleClicked(const QModelIndex &index) { 
  selectedRowIdx = index.row();
  Event tmp = dayListModel->getEvent(selectedRowIdx);   
  int id = tmp.m_id;
  updateEvent(id, selectedRowIdx);
}

//-----------------------------------------------------------------
// setup hashes
//------------------------------------------------------------------
void MainWindow::setupLookupMonth()
{
    lookupMonth.insert(1, "January");
    lookupMonth.insert(2, "February");
    lookupMonth.insert(3, "March");
    lookupMonth.insert(4, "April");
    lookupMonth.insert(5, "May");
    lookupMonth.insert(6, "June");
    lookupMonth.insert(7, "July");
    lookupMonth.insert(8, "August");
    lookupMonth.insert(9, "September");
    lookupMonth.insert(10, "October");
    lookupMonth.insert(11, "November");
    lookupMonth.insert(12, "December");
}


void MainWindow::setupLookupShortDay()
{
    lookupShortDay.insert(1, "Mon");
    lookupShortDay.insert(2, "Tue");
    lookupShortDay.insert(3, "Wed");
    lookupShortDay.insert(4, "Thu");
    lookupShortDay.insert(5, "Fri");
    lookupShortDay.insert(6, "Sat");
    lookupShortDay.insert(7, "Sun"); 
}


//--------------------------------------------------------------------
// Update calendar
//--------------------------------------------------------------------
void MainWindow::updateCalendar()
{
  int cellIndex=0;
    ui->tableWidgetCalendar->clearContents();
    //Initailise with empty cells
    for (int row=0; row<ui->tableWidgetCalendar->rowCount(); ++row)
    {
        for(int col=0; col<ui->tableWidgetCalendar->columnCount(); ++col)
        {
            ui->tableWidgetCalendar->setItem(row, col,
                                     new QTableWidgetItem(""));
            cellIndex = (7 * row) + col;
            dayArray[cellIndex]=0;//all cells initialised to zero
        }
    }

    QStringList days;
    QString day="";

    for (int weekDay = 1; weekDay <= 7; ++weekDay) {
      day =lookupShortDay.value(weekDay);
      days.append(day);
    }
    ui->tableWidgetCalendar->setHorizontalHeaderLabels(days);

    QDate date(selectedDate.year(), selectedDate.month(), 1);

    int row=0;
    int dayValue=0;

    while (date.month() == selectedDate.month()) {
        int weekDay = date.dayOfWeek();
        dayValue= date.day();
        cellIndex = (7 * row) + weekDay-1;
        dayArray[cellIndex]=dayValue;

        if (date==QDate::currentDate())
        {
	        //current date (today)
	        QString str="";
	        QString holStr="";
	        int numberOfDayEvents=0;
	        numberOfDayEvents =getNumberOfDayEvents(date);
	        if(currentPreferences.m_publicHolidays) {
	        holStr =getPublicHoliday(date);
	        if(holStr!="") {
	        str.append(" ");
	        str.append(holStr);	        }
		    } //holiday preference

	        if(currentPreferences.m_eventStars){

	        if(numberOfDayEvents>0) str.append(" ");
	        //append a star for each event
	        for(int i=0; i<numberOfDayEvents; i++)
	        {
	        str.append("*");
	        }
		   } //eventstar preference

	        dayItem = new QTableWidgetItem();
		    dayItem->setText(QString::number(dayValue) +str);

	        QFont f = ui->tableWidgetCalendar->font();
	        f.setWeight(QFont::Bold);
	        f.setItalic(true);
	        dayItem->setFont(f);

	        dayItem->setTextAlignment(Qt::AlignCenter |Qt::AlignVCenter);
	        dayItem->setToolTip("Today");
	        if(getIsPriority(date)) dayItem->setBackground(priorityBackgroundColour);
            else if (getIsPublicHoliday(date) && currentPreferences.m_publicHolidays) dayItem->setBackground(publicHolidayBackgroundColour);
	        else dayItem->setBackground(todayBackgroundColour);
	        ui->tableWidgetCalendar->setItem(row, weekDay-1,dayItem); //put item on calendar
        }
        else {
		 //other dates
		 QString str="";
		 QString holStr="";
		 int numberOfDayEvents=0;
         numberOfDayEvents =getNumberOfDayEvents(date);
		 if(currentPreferences.m_publicHolidays) {
		 holStr =getPublicHoliday(date);
		 if(holStr!="") {
			 str.append(" ");
			 str.append(holStr);
		 }
	      } //holiday preference

		 if(currentPreferences.m_eventStars){

         if(numberOfDayEvents>0) str.append(" ");
             //append a star for each event
             for(int i=0; i<numberOfDayEvents; i++)
             {
				 str.append("*");
			 }
		} //eventstar preference

		dayItem = new QTableWidgetItem();
		dayItem->setText(QString::number(dayValue) +str);
		if(holStr!="") dayItem->setToolTip(holStr);
		dayItem->setTextAlignment(Qt::AlignCenter |Qt::AlignVCenter);

		if (getIsPublicHoliday(date) && currentPreferences.m_publicHolidays) dayItem->setBackground(publicHolidayBackgroundColour);

		if(numberOfDayEvents>0) {

			if(getIsPriority(date)) dayItem->setBackground(priorityBackgroundColour);
			else dayItem->setBackground(eventBackgroundColour);
		}

        ui->tableWidgetCalendar->setItem(row, weekDay-1,dayItem); //put item on calendar

		}
        //Move on ...
       date = date.addDays(1); //move to next day
        if (weekDay == 7 && date.month() == selectedDate.month())
        {
            row=row+1;
        }

    }// while selected month

    //update month-year label
    QString monthYearStr="";
    QString monthStr="";

    monthStr=lookupMonth.value(selectedDate.month());
    monthYearStr.append(monthStr);
    monthYearStr.append(" ");
    monthYearStr.append(QString::number(selectedDate.year()));
    ui->labelMonthYear->setText(monthYearStr);
  
}

//--------------------------------------------------------------------
// Goto next month
//--------------------------------------------------------------------
void MainWindow::gotoNextMonth()
{
    selectedMonth =selectedDate.month()+1;
    selectedYear =selectedDate.year();
    selectedDay=1;

    if (selectedMonth >= 13) {
        selectedMonth = 1;
        selectedYear =selectedYear+1;

        updateCalendar();
        selectedDate.setDate(selectedYear,selectedMonth,selectedDay);
        selectedDateLabel->setText(selectedDate.toString());
    }
    selectedDate.setDate(selectedYear,selectedMonth,selectedDay);

    selectedDateLabel->setText(selectedDate.toString());
    updateCalendar();
    showEventsOnListViewDay(selectedDate);

}

//--------------------------------------------------------------------
// Goto previous month
//--------------------------------------------------------------------
void MainWindow::gotoPreviousMonth()
{
    selectedMonth =selectedDate.month()-1;
    selectedYear =selectedDate.year();
    selectedDay=1;

    if (selectedMonth < 1)
    {
        selectedMonth = 12;
        selectedYear=selectedYear-1;       
        updateCalendar();
        selectedDate.setDate(selectedYear,selectedMonth,selectedDay);
        selectedDateLabel->setText(selectedDate.toString());
    }
    selectedDate.setDate(selectedYear,selectedMonth,selectedDay);

    selectedDateLabel->setText(selectedDate.toString());
    updateCalendar();
    showEventsOnListViewDay(selectedDate);


}

void MainWindow::gotoNextYear() {

  selectedMonth =selectedDate.month();
  selectedYear =selectedDate.year()+1;
  selectedDay=1;
  selectedDate.setDate(selectedYear,selectedMonth,selectedDay);
  updateCalendar();
  selectedDateLabel->setText(selectedDate.toString());
  showEventsOnListViewDay(selectedDate);

}

void MainWindow::gotoPreviousYear() {

  selectedMonth =selectedDate.month();
  selectedYear =selectedDate.year()-1;
  selectedDay=1;
  selectedDate.setDate(selectedYear,selectedMonth,selectedDay);
  updateCalendar();
  selectedDateLabel->setText(selectedDate.toString());
  showEventsOnListViewDay(selectedDate);

}
//--------------------------------------------------------------------
// Goto today
//---------------------------------------------------------------------
void MainWindow::gotoToday()
{
    selectedDate=QDate::currentDate();
    selectedDay=selectedDate.day();
    selectedMonth=selectedDate.month();
    selectedYear=selectedDate.year(); 
    updateCalendar();
    showEventsOnListViewDay(selectedDate);    
    selectedDateLabel->setText(selectedDate.toString());
   

}
//--------------------------------------------------------------------
// Dark calendar
//--------------------------------------------------------------------
void MainWindow::setCalendarStyle(bool style)
{

    if (style==false){
        //light background style
        ui->centralWidget->setStyleSheet( "color: black; background-color: white");
        ui->tableWidgetCalendar->setStyleSheet( "color: black; background-color: white");
        ui->listViewDay->setStyleSheet( "color: black; background-color: white");       
        ui->labelMonthYear->setStyleSheet( "color: black; background-color: white");
        ui->splitter->setStyleSheet( "color: black; background-color: white");
       

    }
    else if (style==true){
        //dark style - dim gray
        ui->centralWidget->setStyleSheet( "color: white; background-color: rgb(105,105,105)");
        ui->tableWidgetCalendar->setStyleSheet( "color: white; background-color: rgb(105,105,105)");
        ui->listViewDay->setStyleSheet( "color: white; background-color: rgb(105,105,105)");        
        ui->labelMonthYear->setStyleSheet( "color: white; background-color: rgb(105,105,105)");
        ui->splitter->setStyleSheet( "color: white; background-color: rgb(105,105,105)");        
    }
}



//----------------------------------------------------------------------
// Action Slots
//----------------------------------------------------------------------
void MainWindow::gotoNextMonthSlot()
{
    gotoNextMonth();
}

void MainWindow::gotoNextYearSlot()
{
    gotoNextYear();
}


void MainWindow::gotoPreviousMonthSlot()
{
    gotoPreviousMonth();
}

void MainWindow::gotoPreviousYearSlot()
{
    gotoPreviousYear();
}

void MainWindow::gotoTodaySlot()
{
    gotoToday();
}


//---------------------------------------------------------------
// Calendar click
//----------------------------------------------------------------
void MainWindow::on_tableWidgetCalendar_cellClicked(int row, int column)
{

    int day =dayArray[(7 * row) + column];
      
    //check if day valid
    //to be safe check that day within month range
    int daysInMonth = QDate(selectedDate.year(), selectedDate.month(), 1).daysInMonth();
   
    if (day<1 || day>daysInMonth) return; //stop selection crash    
    //update calendar only puts valid days values into the dayArray
    // and all other cells initialised to zero so
    //if(day<=0) return;
    // works
    selectedDate =QDate(selectedYear,selectedMonth,day);	
    selectedDateLabel->setText(selectedDate.toString());
    showEventsOnListViewDay(selectedDate);
}


//--------------------------------------------------------------------

QList<Event> MainWindow::getTimeSortedDayList(QDate theDate) {

   QList<Event> dayList = getDayList(theDate);

   //sort manually as qSort deprecated (todo:  C++ STL std::sort)
   int n;
   int i;
   for (n=0; n < dayList.count(); n++)
   {
     for (i=n+1; i < dayList.count(); i++)
     {
       Event event1 = dayList.value(n);
       Event event2 = dayList.value(i);

       int event1Hour = event1.m_startHour;
       int event1Min = event1.m_startMin;
       int event2Hour = event2.m_startHour;
       int event2Min = event2.m_startMin;

       int fx = 60 * 60 * event1Hour + 60 * event1Min; //seconds
       int sx = 60 * 60 * event2Hour + 60 * event2Min;

       if (fx > sx)
       {
         dayList.move(i, n);
         n=0;
       }
     } //for i
   } //for n

   return dayList;
 }

QList<Event> MainWindow::getDayListCurrent(QDate theDate) {

  QList<Event> dayList = QList<Event>();


  for (int i = 0; i < eventList.size(); i++) {

    Event e = eventList.at(i);

    QDate eventStartDate =QDate(e.m_startYear, e.m_startMonth,e.m_startDay);
    QDate eventEndDate =QDate(e.m_endYear, e.m_endMonth, e.m_endDay);

    while (eventStartDate <= eventEndDate) {

      if (eventStartDate == theDate) {
        dayList.append(e);
      }

      //yearly events
    if(e.m_startDay == theDate.day() && e.m_startMonth ==theDate.month() && e.m_startYear!=theDate.year() && e.m_isYearly==1) {
        e.m_startYear=theDate.year(); //current
		dayList.append(e);
    }
     eventStartDate = eventStartDate.addDays(1);
    } //while
  } //for
  return dayList;
}

QList<Event> MainWindow::getDayList(QDate theDate) {

  QList<Event> dayList = QList<Event>();


  for (int i = 0; i < eventList.size(); i++) {

    Event e = eventList.at(i);

    QDate eventStartDate =QDate(e.m_startYear, e.m_startMonth,e.m_startDay);
    QDate eventEndDate =QDate(e.m_endYear, e.m_endMonth, e.m_endDay);

    while (eventStartDate <= eventEndDate) {

      if (eventStartDate == theDate) {
        dayList.append(e);
      }

      //yearly events
    if(e.m_startDay == theDate.day() && e.m_startMonth ==theDate.month() && e.m_startYear!=theDate.year() && e.m_isYearly==1) {
		dayList.append(e);
    }
     eventStartDate = eventStartDate.addDays(1);
    } //while
  } //for
  return dayList;
}

int MainWindow::getNumberOfDayEvents(QDate theDate){


	int number =0;
	for (int i = 0; i < eventList.size(); i++) {

    Event e = eventList.at(i);

    QDate eventStartDate =QDate(e.m_startYear, e.m_startMonth,e.m_startDay);
    QDate eventEndDate =QDate(e.m_endYear, e.m_endMonth, e.m_endDay);

    while (eventStartDate <= eventEndDate) {


      if (eventStartDate == theDate) {
        number=number+1;
      }

      //yearly events
      if(e.m_startDay == theDate.day() && e.m_startMonth ==theDate.month()
        && e.m_startYear!=theDate.year() && e.m_isYearly==1)
      {
        number=number+1;
      }

      eventStartDate = eventStartDate.addDays(1);
    } //while

    } //for eventlist

	return number;
}

//----------------------------------------------------------------------
// Preferences
//----------------------------------------------------------------------

//------------------------------------------------------------------
// Default preferences
//-------------------------------------------------------------------
void MainWindow::setDefaultPreferences()
{

  // defaults
  currentPreferences.m_appFontSize = 18;
  currentPreferences.m_windowWidth = 600;
  currentPreferences.m_windowHeight = 600;
  currentPreferences.m_publicHolidays = true;
  currentPreferences.m_eventStars = true;
  currentPreferences.m_darkStyle = true;
  currentPreferences.m_12HourFormat = true;
  currentPreferences.m_todayRed = 50; // lime green
  currentPreferences.m_todayGreen = 205;
  currentPreferences.m_todayBlue = 50; // blue green
  currentPreferences.m_eventRed = 70;
  currentPreferences.m_eventGreen = 150;
  currentPreferences.m_eventBlue = 180;
  currentPreferences.m_priorityRed = 255; // fuchsia
  currentPreferences.m_priorityGreen = 0;
  currentPreferences.m_priorityBlue = 255;
  currentPreferences.m_publicRed = 218; // golden rod
  currentPreferences.m_publicGreen = 165;
  currentPreferences.m_publicBlue = 32;
  currentPreferences.m_audioAlarm = true;
  currentPreferences.m_talkAtStartup = false;
  currentPreferences.m_talkLocation = false;
  currentPreferences.m_talkUpcoming = false;
  currentPreferences.m_lookAheadDays = 7;
  saveSettings();
}

void MainWindow::setPreferences()
{
  DialogPreferences *preferencesDialog = new DialogPreferences(this, &currentPreferences);
  preferencesDialog->setModal(true);

  if (preferencesDialog->exec() == QDialog::Accepted)
  {
    currentPreferences.m_appFontSize = 20;
    currentPreferences.m_appFontSize = preferencesDialog->getAppFontSize();
    // calendar
    currentPreferences.m_publicHolidays = preferencesDialog->isPublicHolidays();
    currentPreferences.m_eventStars = preferencesDialog->isEventStars();
    currentPreferences.m_darkStyle = preferencesDialog->isDarkStyle();
    currentPreferences.m_12HourFormat = preferencesDialog->isAmPmFormat();
    // alarm
    currentPreferences.m_audioAlarm = preferencesDialog->isAudioAlarm();
    // talking
    currentPreferences.m_talkAtStartup = preferencesDialog->isTalkAtStartup();
    currentPreferences.m_talkLocation = preferencesDialog->isTalkLocation();
    currentPreferences.m_talkUpcoming = preferencesDialog->isTalkUpcoming();
    currentPreferences.m_lookAheadDays = preferencesDialog->getUpcomingDayNumber();

    currentPreferences.m_todayRed = preferencesDialog->getTodayRed();
    currentPreferences.m_todayGreen = preferencesDialog->getTodayGreen();
    currentPreferences.m_todayBlue = preferencesDialog->getTodayBlue();

    currentPreferences.m_eventRed = preferencesDialog->getEventRed();
    currentPreferences.m_eventGreen = preferencesDialog->getEventGreen();
    currentPreferences.m_eventBlue = preferencesDialog->getEventBlue();

    currentPreferences.m_priorityRed = preferencesDialog->getPriorityRed();
    currentPreferences.m_priorityGreen = preferencesDialog->getPriorityGreen();
    currentPreferences.m_priorityBlue = preferencesDialog->getPriorityBlue();

    currentPreferences.m_publicRed = preferencesDialog->getPublicRed();
    currentPreferences.m_publicGreen = preferencesDialog->getPublicGreen();
    currentPreferences.m_publicBlue = preferencesDialog->getPublicBlue();

    if (preferencesDialog->isFactoryReset())
    {

      setDefaultPreferences();

      todayBackgroundColour.setRgb(
          currentPreferences.m_todayRed,
          currentPreferences.m_todayGreen,
          currentPreferences.m_todayBlue);

      eventBackgroundColour.setRgb(
          currentPreferences.m_eventRed,
          currentPreferences.m_eventGreen,
          currentPreferences.m_eventBlue);

      priorityBackgroundColour.setRgb(
          currentPreferences.m_priorityRed,
          currentPreferences.m_priorityGreen,
          currentPreferences.m_priorityBlue);

      publicHolidayBackgroundColour.setRgb(
          currentPreferences.m_publicRed,
          currentPreferences.m_publicGreen,
          currentPreferences.m_publicBlue);

      setApplicationFontSize(currentPreferences.m_appFontSize);
      setCalendarStyle(currentPreferences.m_darkStyle); // light
      updateCalendar();
      showEventsOnListViewDay(selectedDate);
    }
    else
    {

      todayBackgroundColour.setRgb(
          currentPreferences.m_todayRed,
          currentPreferences.m_todayGreen,
          currentPreferences.m_todayBlue);

      eventBackgroundColour.setRgb(
          currentPreferences.m_eventRed,
          currentPreferences.m_eventGreen,
          currentPreferences.m_eventBlue);

      priorityBackgroundColour.setRgb(
          currentPreferences.m_priorityRed,
          currentPreferences.m_priorityGreen,
          currentPreferences.m_priorityBlue);

      publicHolidayBackgroundColour.setRgb(
          currentPreferences.m_publicRed,
          currentPreferences.m_publicGreen,
          currentPreferences.m_publicBlue);

      saveSettings();
      setApplicationFontSize(currentPreferences.m_appFontSize);
      setCalendarStyle(currentPreferences.m_darkStyle);
      updateCalendar();
      showEventsOnListViewDay(selectedDate);
    }

  } // accepted
}

bool MainWindow::loadSettings() {

  QSettings settings("casper-calendar", "settings");
  settings.beginGroup("CoreSettings");
  // application
  currentPreferences.m_appFontSize = settings.value("AppFontSize").toInt();
  currentPreferences.m_windowWidth = settings.value("WindowWidth").toInt();
  currentPreferences.m_windowHeight = settings.value("WindowHeight").toInt();

  // calendar
  currentPreferences.m_publicHolidays = settings.value("PublicHolidays").toBool();
  currentPreferences.m_eventStars = settings.value("EventStars").toBool();
  //currentPreferences.m_audioBleep = settings.value("AudioBleep").toBool();
  currentPreferences.m_darkStyle = settings.value("DarkStyle").toBool();
  currentPreferences.m_12HourFormat = settings.value("PmFormat").toBool();

  currentPreferences.m_todayRed = settings.value("TodayRed").toInt();
  currentPreferences.m_todayGreen = settings.value("TodayGreen").toInt();
  currentPreferences.m_todayBlue = settings.value("TodayBlue").toInt();
  currentPreferences.m_eventRed = settings.value("EventRed").toInt();
  currentPreferences.m_eventGreen = settings.value("EventGreen").toInt();
  currentPreferences.m_eventBlue = settings.value("EventBlue").toInt();
  currentPreferences.m_priorityRed = settings.value("PriorityRed").toInt();
  currentPreferences.m_priorityGreen = settings.value("PriorityGreen").toInt();
  currentPreferences.m_priorityBlue = settings.value("PriorityBlue").toInt();
  currentPreferences.m_publicRed = settings.value("PublicRed").toInt();
  currentPreferences.m_publicGreen = settings.value("PublicGreen").toInt();
  currentPreferences.m_publicBlue = settings.value("PublicBlue").toInt();
  // alarm
  currentPreferences.m_audioAlarm = settings.value("AudioAlarm").toBool();
  // speaking
  currentPreferences.m_talkLocation = settings.value("TalkLocation").toBool();
  currentPreferences.m_talkAtStartup = settings.value("TalkAtStartup").toBool();
  currentPreferences.m_talkUpcoming = settings.value("TalkUpcoming").toBool();
  currentPreferences.m_lookAheadDays = settings.value("LookAheadDays").toInt();

  settings.endGroup();

  return true;
}



//void MainWindow::saveSettings() {
void MainWindow::saveSettings() {

  QSettings settings("casper-calendar", "settings");
  settings.beginGroup("CoreSettings");
  // application
  settings.setValue("AppFontSize", currentPreferences.m_appFontSize);
  settings.setValue("WindowWidth", currentPreferences.m_windowWidth);
  settings.setValue("WindowHeight", currentPreferences.m_windowHeight);
  // calendar
  settings.setValue("PublicHolidays", currentPreferences.m_publicHolidays);
  settings.setValue("EventStars", currentPreferences.m_eventStars);
  //settings.setValue("AudioBleep", currentPreferences.m_audioBleep);
  settings.setValue("DarkStyle", currentPreferences.m_darkStyle);
  settings.setValue("PmFormat", currentPreferences.m_12HourFormat);

  settings.setValue("TodayRed", currentPreferences.m_todayRed);
  settings.setValue("TodayGreen", currentPreferences.m_todayGreen);
  settings.setValue("TodayBlue", currentPreferences.m_todayBlue);
  settings.setValue("EventRed", currentPreferences.m_eventRed);
  settings.setValue("EventGreen", currentPreferences.m_eventGreen);
  settings.setValue("EventBlue", currentPreferences.m_eventBlue);

  settings.setValue("PriorityRed", currentPreferences.m_priorityRed);
  settings.setValue("PriorityGreen", currentPreferences.m_priorityGreen);
  settings.setValue("PriorityBlue", currentPreferences.m_priorityBlue);

  settings.setValue("PublicRed", currentPreferences.m_publicRed);
  settings.setValue("PublicGreen", currentPreferences.m_publicGreen);
  settings.setValue("PublicBlue", currentPreferences.m_publicBlue);
  // alarm
  settings.setValue("AudioAlarm", currentPreferences.m_audioAlarm);
  // speaking
  settings.setValue("TalkLocation", currentPreferences.m_talkLocation);
  settings.setValue("TalkAtStartup", currentPreferences.m_talkAtStartup);
  settings.setValue("TalkUpcoming", currentPreferences.m_talkUpcoming);
  settings.setValue("LookAheadDays", currentPreferences.m_lookAheadDays);

  settings.endGroup();
}

void MainWindow::setApplicationFontSize(int fontSize)
{
  QFont appfont = QApplication::font();
  appfont.setPixelSize(fontSize); // DPI
  QApplication::setFont(appfont);
}

//--------------------------------------------------------------------
// load events
//--------------------------------------------------------------------

void MainWindow::loadEvents() { 
  
  if (!fileExists(QApplication::applicationDirPath()+"/events.xml")){
	  //events.xml does not exist (first run)
	  return;
  }
  
  eventList.clear();
  QDomDocument document;
  
   QString filename =QApplication::applicationDirPath()+"/events.xml"; 
   QFile file(filename);
   file.open(QFile::ReadOnly | QFile::Text);
   document.setContent(&file);
   
    QDomElement root = document.firstChildElement();
    QDomNodeList event = root.elementsByTagName("CalendarEvent");

    for (int i = 0; i < event.count(); i++) {
        QDomNode eventnode = event.at(i);
        if (eventnode.isElement()) {
            QDomElement event = eventnode.toElement();

            Event evt;           
            evt.m_summary = event.attribute("Summary");
            evt.m_location = event.attribute("Location");
            evt.m_description = event.attribute("Description");
            evt.m_startYear = event.attribute("StartYear").toInteger<int>();
            evt.m_startMonth = event.attribute("StartMonth").toInteger<int>();
            evt.m_startDay = event.attribute("StartDay").toInteger<int>();
            evt.m_startHour = event.attribute("StartHour").toInteger<int>();
            evt.m_startMin = event.attribute("StartMin").toInteger<int>();
            evt.m_endYear = event.attribute("EndYear").toInteger<int>();
            evt.m_endMonth = event.attribute("EndMonth").toInteger<int>();
            evt.m_endDay = event.attribute("EndDay").toInteger<int>();
            evt.m_endHour = event.attribute("EndHour").toInteger<int>();
            evt.m_endMin = event.attribute("EndMin").toInteger<int>();
            evt.m_isYearly = event.attribute("IsYearly").toInteger<int>();          
            evt.m_isAllDay = event.attribute("IsAllDay").toInteger<int>();
            //evt.m_colour = event.attribute("Colour").toInteger<int>();
            evt.m_isPriority = event.attribute("Priority").toInteger<int>();
            evt.m_hasReminder = event.attribute("HasReminder").toInteger<int>();
            evt.m_reminderMinutes = event.attribute("ReminderMins").toInteger<int>();
                        
            evt.m_id=eventList.count();
            //qDebug()<<"load event: "<<"e.m_id = "<<evt.m_id<<" e.m_title = "<< evt.m_title<<"\n";
            eventList.append(evt);
        }
    }

    file.close();
    selectedDate = QDate::currentDate();
    updateCalendar();
    showEventsOnListViewDay(selectedDate);
    gotoTodaySlot();
}
//--------------------------------------------------------------------
// reload events after update
//--------------------------------------------------------------------

void MainWindow::reloadEvents() {
	  
  if (!fileExists(QApplication::applicationDirPath()+"/events.xml")){	 
	  return;
  }
  eventList.clear();
  QDomDocument document;
  
   QString filename =QApplication::applicationDirPath()+"/events.xml"; 
   QFile file(filename);
   file.open(QFile::ReadOnly | QFile::Text);
   document.setContent(&file);
   
    QDomElement root = document.firstChildElement();
    QDomNodeList event = root.elementsByTagName("CalendarEvent");

    for (int i = 0; i < event.count(); i++) {
        QDomNode eventnode = event.at(i);
        if (eventnode.isElement()) {
            QDomElement event = eventnode.toElement();

            Event evt;           
            evt.m_summary = event.attribute("Summary");
            evt.m_location = event.attribute("Location");
            evt.m_description = event.attribute("Description");
            evt.m_startYear = event.attribute("StartYear").toInteger<int>();
            evt.m_startMonth = event.attribute("StartMonth").toInteger<int>();
            evt.m_startDay = event.attribute("StartDay").toInteger<int>();
            evt.m_startHour = event.attribute("StartHour").toInteger<int>();
            evt.m_startMin = event.attribute("StartMin").toInteger<int>();
            evt.m_endYear = event.attribute("EndYear").toInteger<int>();
            evt.m_endMonth = event.attribute("EndMonth").toInteger<int>();
            evt.m_endDay = event.attribute("EndDay").toInteger<int>();
            evt.m_endHour = event.attribute("EndHour").toInteger<int>();
            evt.m_endMin = event.attribute("EndMin").toInteger<int>();
            evt.m_isYearly = event.attribute("IsYearly").toInteger<int>();          
            evt.m_isAllDay = event.attribute("IsAllDay").toInteger<int>();
            evt.m_isPriority = event.attribute("Priority").toInteger<int>();
            evt.m_hasReminder = event.attribute("HasReminder").toInteger<int>();
            evt.m_reminderMinutes = event.attribute("ReminderMins").toInteger<int>();
           
            evt.m_id=eventList.count();
            //qDebug()<<"reload event: "<<"e.m_id = "<<evt.m_id<<" e.m_summary = "<< evt.m_summaru<<"\n";
            eventList.append(evt);            
        }
    }

   file.close();
   updateCalendar();
   showEventsOnListViewDay(selectedDate);
}



//---------------------------------------------------------------------
// save events
//---------------------------------------------------------------------
void MainWindow::saveEvents() {
	
	QDomDocument document;
    QDomElement root = document.createElement("Events");
    document.appendChild(root);
       
        for (int i = 0; i < eventList.count(); i++) {
        Event evt = eventList.at(i);
        QString summary = evt.m_summary;
        QString location = evt.m_location;
        QString description = evt.m_description;
        QString startYearStr = QString::number(evt.m_startYear);
        QString startMonthStr = QString::number(evt.m_startMonth);
        QString startDayStr = QString::number(evt.m_startDay);
        QString startHourStr = QString::number(evt.m_startHour);
        QString startMinStr = QString::number(evt.m_startMin);
        QString endYearStr = QString::number(evt.m_endYear);
        QString endMonthStr = QString::number(evt.m_endMonth);
        QString endDayStr = QString::number(evt.m_endDay);
        QString endHourStr = QString::number(evt.m_endHour);
        QString endMinStr = QString::number(evt.m_endMin);
        QString isYearlyStr = QString::number(evt.m_isYearly);       
        QString isAllDayStr = QString::number(evt.m_isAllDay);
        QString priority =QString::number(evt.m_isPriority);
        QString hasReminderStr = QString::number(evt.m_hasReminder);
        QString reminderMinsStr = QString::number(evt.m_reminderMinutes);

        QDomElement dEvent = document.createElement("CalendarEvent");       
        dEvent.setAttribute("Summary", summary);
        dEvent.setAttribute("Location", location);
        dEvent.setAttribute("Description", description);
        dEvent.setAttribute("StartYear", startYearStr);
        dEvent.setAttribute("StartMonth", startMonthStr);
        dEvent.setAttribute("StartDay", startDayStr);
        dEvent.setAttribute("StartHour", startHourStr);
        dEvent.setAttribute("StartMin", startMinStr);
        dEvent.setAttribute("EndYear", endYearStr);
        dEvent.setAttribute("EndMonth", endMonthStr);
        dEvent.setAttribute("EndDay", endDayStr);
        dEvent.setAttribute("EndHour", endHourStr);
        dEvent.setAttribute("EndMin", endMinStr);
        dEvent.setAttribute("EndMin", endMinStr);
        dEvent.setAttribute("IsYearly", isYearlyStr);       
        dEvent.setAttribute("IsAllDay", isAllDayStr);
        dEvent.setAttribute("Priority", priority);
        dEvent.setAttribute("HasReminder", hasReminderStr);
        dEvent.setAttribute("ReminderMins", reminderMinsStr);

        root.appendChild(dEvent);
    }

    QString filename =QApplication::applicationDirPath()+"/events.xml"; 
    QFile file(filename);
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream stream(&file);
    stream << document.toString();
    file.flush();
    file.close();	
	
}

//--------------------------------------------------------------------
// import saved calendar (QFileDialog)
//---------------------------------------------------------------------
void MainWindow::importCalendar() {

  QDomDocument document;
  QString filename = QFileDialog::getOpenFileName(this, "Open Events Xml", ".", "Xml files (*.xml)");
  QFile file(filename);

 if (!file.open(QFile::ReadOnly | QFile::Text)) {
    //Failed to open XML file
    file.close();
    return;
   }
  else if (!document.setContent(&file)){
    // Failed to load document
    file.close();
    return;
   }

  else {

      eventList.clear();

      QDomElement root = document.firstChildElement();
      QDomNodeList event = root.elementsByTagName("CalendarEvent");

      for (int i = 0; i < event.count(); i++) {
        QDomNode eventnode = event.at(i);
        if (eventnode.isElement()) {
          QDomElement event = eventnode.toElement();

          Event evt;
          evt.m_summary = event.attribute("Summary");
          evt.m_location = event.attribute("Location");
          evt.m_description = event.attribute("Description");

          evt.m_startYear = event.attribute("StartYear").toInteger<int>();
          evt.m_startMonth = event.attribute("StartMonth").toInteger<int>();
          evt.m_startDay = event.attribute("StartDay").toInteger<int>();
          evt.m_startHour = event.attribute("StartHour").toInteger<int>();
          evt.m_startMin = event.attribute("StartMin").toInteger<int>();

          evt.m_endYear = event.attribute("EndYear").toInteger<int>();
          evt.m_endMonth = event.attribute("EndMonth").toInteger<int>();
          evt.m_endDay = event.attribute("EndDay").toInteger<int>();
          evt.m_endHour = event.attribute("EndHour").toInteger<int>();
          evt.m_endMin = event.attribute("EndMin").toInteger<int>();

          evt.m_isYearly = event.attribute("IsYearly").toInteger<int>();
          evt.m_isAllDay = event.attribute("IsAllDay").toInteger<int>();
          evt.m_isPriority = event.attribute("Priority").toInteger<int>();
          evt.m_hasReminder = event.attribute("HasReminder").toInteger<int>();
          evt.m_reminderMinutes = event.attribute("ReminderMins").toInteger<int>();

          evt.m_id=eventList.count();
          //qDebug()<<"Importing events "<<"e.m_id = "<<evt.m_id<<" e.m_title = "<< evt.m_title<<"\n";
          eventList.append(evt);
         }
       }

      file.close();
      selectedDate = QDate::currentDate();
      updateCalendar();
      showEventsOnListViewDay(selectedDate);
      gotoTodaySlot();
    }
}

//---------------------------------------------------------------------
// export events (QFileDialog)
//---------------------------------------------------------------------

void MainWindow::exportCalendar() {
  QDomDocument document;
    QDomElement root = document.createElement("Events");
    document.appendChild(root);
   
        for (int i = 0; i < eventList.count(); i++) {
        Event evt = eventList.at(i);

        QString summary = evt.m_summary;
        QString location = evt.m_location;
        QString description = evt.m_description;

        QString startYearStr = QString::number(evt.m_startYear);
        QString startMonthStr = QString::number(evt.m_startMonth);
        QString startDayStr = QString::number(evt.m_startDay);
        QString startHourStr = QString::number(evt.m_startHour);
        QString startMinStr = QString::number(evt.m_startMin);

        QString endYearStr = QString::number(evt.m_endYear);
        QString endMonthStr = QString::number(evt.m_endMonth);
        QString endDayStr = QString::number(evt.m_endDay);
        QString endHourStr = QString::number(evt.m_endHour);
        QString endMinStr = QString::number(evt.m_endMin);

        QString isYearlyStr = QString::number(evt.m_isYearly);
        QString isAllDayStr = QString::number(evt.m_isAllDay);

        QString priority =QString::number(evt.m_isPriority);
        QString hasReminderStr = QString::number(evt.m_hasReminder);
        QString reminderMinsStr = QString::number(evt.m_reminderMinutes);

        QDomElement dEvent = document.createElement("CalendarEvent");        
        dEvent.setAttribute("Summary", summary);
        dEvent.setAttribute("Location", location);
        dEvent.setAttribute("Description", description);

        dEvent.setAttribute("StartYear", startYearStr);
        dEvent.setAttribute("StartMonth", startMonthStr);
        dEvent.setAttribute("StartDay", startDayStr);
        dEvent.setAttribute("StartHour", startHourStr);
        dEvent.setAttribute("StartMin", startMinStr);


        dEvent.setAttribute("EndYear", endYearStr);
        dEvent.setAttribute("EndMonth", endMonthStr);
        dEvent.setAttribute("EndDay", endDayStr);
        dEvent.setAttribute("EndHour", endHourStr);
        dEvent.setAttribute("EndMin", endMinStr);

        dEvent.setAttribute("IsYearly", isYearlyStr);        
        dEvent.setAttribute("IsAllDay", isAllDayStr);
        //dEvent.setAttribute("Colour", colour);
        dEvent.setAttribute("Priority", priority);
        dEvent.setAttribute("HasReminder", hasReminderStr);
        dEvent.setAttribute("ReminderMins", reminderMinsStr);

        root.appendChild(dEvent);
    }

    QString filename = QFileDialog::getSaveFileName(this, "Save Events Xml", ".", "Xml files (*.xml)");
    QFile file(filename+".xml");
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        //qDebug() << "Error saving XML file.";
        return;
    } else {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        //qDebug() << "Finished export";
    }  
}

bool MainWindow::directoryExists(QString path)
{
	const QFileInfo outputDir(path);
    if ((!outputDir.exists()) || (!outputDir.isDir()) || (!outputDir.isReadable())) {
        //qWarning() << "output directory does not exist, is not a directory, or is not readable"
                   //<< outputDir.absoluteFilePath();
        return false;
    }
    else {
		return true;
	}
}

bool MainWindow::fileExists(QString path)
{
    QFileInfo check_file(path);
    // check if file exists and if yes: Is it really a file and not directory?
    if (check_file.exists() && check_file.isFile()) {
        return true;
    } else {
        return false;
    }
}


void MainWindow::checkForReminders() {
  QDate currentDate = QDate::currentDate();
  QTime currentTime = QTime::currentTime();
  int currentHour = currentTime.hour();
  int currentMinute = currentTime.minute();
  int currentSecond = currentTime.second();

  for (int i = 0; i < eventList.size(); i++) {
    Event event = eventList.at(i);

    if (event.m_hasReminder == 1) {
      //Event has reminder
      QDate reminderDate = QDate(event.m_startYear, event.m_startMonth, event.m_startDay);

      QTime reminderTime = QTime(event.m_startHour, event.m_startMin);

      if (event.m_reminderMinutes == 5) {

        reminderTime = reminderTime.addSecs(-(5 * 60));
      } else if (event.m_reminderMinutes == 10) {
        reminderTime = reminderTime.addSecs(-(10 * 60));
      } else if (event.m_reminderMinutes == 30) {
        reminderTime = reminderTime.addSecs(-(30 * 60)); // 1hour = 3,600 seconds
      } else if (event.m_reminderMinutes == 60) {
        reminderTime = reminderTime.addSecs(-(60 * 60)); // 1hour = 3,600 seconds
      } else if (event.m_reminderMinutes == 1440) {
        reminderDate = reminderDate.addDays(-1);
      }

      int reminderHour = reminderTime.hour();
      int reminderMinute = reminderTime.minute();
      
      if (reminderDate == currentDate) {
        if (currentHour == reminderHour && currentMinute == reminderMinute && currentSecond == 0) {

          QString str = event.m_summary;

          str.append(" ");
          str.append(" on ");
          str.append(" ");
          QDate date = QDate(event.m_startYear, event.m_startMonth, event.m_startDay);

          str.append(date.toString("dddd dd MMMM yyyy"));
          str.append("\n"); //new line
                            // str.append("Starts at ");

          QTime startTime = QTime(event.m_startHour, event.m_startMin);
          
          QString startTimeStr = "";

          if (event.m_isAllDay) {
            startTimeStr = "All Day Event";
          } //alldayevent
          else {
            startTimeStr.append("Starts at: ");
            startTimeStr.append(startTime.toString("h:mm ap"));
          }

          str.append(startTimeStr);

          if (currentPreferences.m_audioAlarm)
          {           
              speakReminder();
          }
          else
          {
            //qDebug() << "Missing reminder talk";
          }
        
        QMessageBox::information(this, "Reminder", str);
      }
      }
    }
  }
}

//-----------------------------------------------------------------------------------------
// parse ICS file
//-------------------------------------------------------------------------------------------

void MainWindow::parseICSFile() {

  //ICS version 2 files (as used by google)
    //eventList.clear(); //user to clear using NEW

    QString filename = QFileDialog::getOpenFileName(this, "Open Calendar ics ", ".", "ics files (*.ics)");
    //qDebug()<<"filename = "<<filename<<"\n";
    QFile file(filename);

       if (!file.open(QFile::ReadOnly| QFile::Text)) {//failed to open so return
           file.close();
           return ;
       }

       textStream.setDevice(&file);

       QString line;

        while (!textStream.atEnd()) {
            line = textStream.readLine();

             if(line.contains("BEGIN:VEVENT")){
                      //qDebug()<<"event found\n";
                Event evt;
                 evt.m_isYearly = 0;  //default
                 evt.m_isAllDay = 0; //default

                while(!line.contains("END:VEVENT")) {

                    if (line.contains("BEGIN:VALARM")) { //skip alarm entries
                         while(!line.contains("END:VALARM")) {
                        line = textStream.readLine();
                         }
                    }

                    const int deliminatorPosition = line.indexOf(QLatin1Char(':'));
                    const QString key   = line.mid(0, deliminatorPosition);
                    const QString value = line.mid(deliminatorPosition + 1, -1);
                    //qDebug()<<"key = "<<key<<" value = "<<value<<"\n";

                    if (key == QLatin1String("DTSTART;VALUE=DATE")) {

                        //day event
                        //e.g. DTSTART;VALUE=DATE:20110823
                        QDateTime utcTime = QDateTime::fromString(value, "yyyyMMdd");

                        //to do .. need to check a value has been parsed correctly

                        QString day = QLocale{QLocale::English}.toString(utcTime, "dd");
                        evt.m_startDay = day.toInteger<int>();
                        //qDebug() << "day = " <<evt.m_startDay<<"\n";

                        QString month = QLocale{QLocale::English}.toString(utcTime, "MM");
                        evt.m_startMonth =month.toInteger<int>();
                       // qDebug() << "month = " << evt.m_startMonth<<"\n";

                        QString year = QLocale{QLocale::English}.toString(utcTime, "yyyy");
                        evt.m_startYear = year.toInteger<int>();
                        //qDebug() << "year = " << evt.m_startYear<<"\n";

                         evt.m_isAllDay = 1;
                    }

                    if (key == QLatin1String("RRULE")) {

                        //e.g. RRULE:FREQ=YEARLY
                        if (value == QLatin1String("FREQ=YEARLY")) evt.m_isYearly =1;

                    }

                    if (key == QLatin1String("DTEND;VALUE=DATE")) {

                      //Todo: multiday events not currently supported
                      //e.g. DTEND;VALUE=DATE:20110824
                      QDateTime utcTime = QDateTime::fromString(value, "yyyyMMdd");
                      QString eday = QLocale{QLocale::English}.toString(utcTime, "dd");
                      evt.m_endDay = eday.toInteger<int>();

                      //qDebug() << "day = " <<evt.m_startDay<<"\n";

                      QString emonth = QLocale{QLocale::English}.toString(utcTime, "MM");
                      evt.m_endMonth =emonth.toInteger<int>();
                      //qDebug() << "month = " << evt.m_startMonth<<"\n";

                      QString eyear = QLocale{QLocale::English}.toString(utcTime, "yyyy");
                      evt.m_endYear = eyear.toInteger<int>();


                      QString hour = QLocale{QLocale::English}.toString(utcTime, "hh");
                      evt.m_endHour =hour.toInteger<int>();

                    }

                    if(key == QLatin1String("DTSTART")) {

                        //format  DTSTART:20121207T130000Z

                        //standard  event with date and start time
                        QDateTime utcTime = QDateTime::fromString(value, "yyyyMMdd'T'hhmmss'Z'");
                        QDateTime local = utcTime.toLocalTime();

                        //qDebug() << "utc: " << utcTime.toString()<<"\n";


                        QString day = QLocale{QLocale::English}.toString(utcTime, "dd");
                        evt.m_startDay = day.toInteger<int>();

                        //qDebug() << "day = " <<evt.m_startDay<<"\n";

                        QString month = QLocale{QLocale::English}.toString(utcTime, "MM");
                        evt.m_startMonth =month.toInteger<int>();
                        //qDebug() << "month = " << evt.m_startMonth<<"\n";

                        QString year = QLocale{QLocale::English}.toString(utcTime, "yyyy");
                        evt.m_startYear = year.toInteger<int>();
                        //qDebug() << "year = " << evt.m_startYear<<"\n";


                        QString hour = QLocale{QLocale::English}.toString(utcTime, "hh");
                        evt.m_startHour =hour.toInteger<int>();
                        //qDebug() << "hour = " << evt.m_startHour<<"\n";

                        QString minute = QLocale{QLocale::English}.toString(utcTime, "mm");
                        evt.m_startMin =minute.toInteger<int>();
                        //qDebug() << "min = " << evt.m_startMin<<"\n";
                   }

                   if(key == QLatin1String("DTEND")) {
                       //end time
                       //format DTEND:20121207T132000Z
                      //Todoo: multiday events not currently supported

                        //standard  event with date and start time
                        QDateTime utcTime = QDateTime::fromString(value, "yyyyMMdd'T'hhmmss'Z'");


                        QString eday = QLocale{QLocale::English}.toString(utcTime, "dd");
                        evt.m_endDay = eday.toInteger<int>();

                        //qDebug() << "day = " <<evt.m_startDay<<"\n";

                        QString emonth = QLocale{QLocale::English}.toString(utcTime, "MM");
                        evt.m_endMonth =emonth.toInteger<int>();
                        //qDebug() << "month = " << evt.m_startMonth<<"\n";

                        QString eyear = QLocale{QLocale::English}.toString(utcTime, "yyyy");
                        evt.m_endYear = eyear.toInteger<int>();


                        QString hour = QLocale{QLocale::English}.toString(utcTime, "hh");
                        evt.m_endHour =hour.toInteger<int>();
                        //qDebug() << "hour = " << evt.m_endHour<<"\n";

                        QString minute = QLocale{QLocale::English}.toString(utcTime, "mm");
                        evt.m_endMin =minute.toInteger<int>();
                        //qDebug() << "min = " << evt.m_endMin<<"\n";

                   }

                   if (key == QLatin1String("SUMMARY")) {
                       //event summary
                       evt.m_summary = value;
                   }

                   if(key == QLatin1String("LOCATION")) {
                       //event location
                       evt.m_location = value;
                   }

                   if(key == QLatin1String("DESCRIPTION")){
                       //event description
                       evt.m_description = value;

                   }

                 line = textStream.readLine();

                } //while event not ended

                //add event to eventlist
                //defaults
                evt.m_isPriority = 0;
                evt.m_hasReminder = 0;
                evt.m_reminderMinutes = 0;
                evt.m_id=eventList.count();
                //qDebug()<<"parse ics event: "<<"e.m_id = "<<evt.m_id<<" e.m_summary = "<< evt.m_summary<<"\n";
                eventList.append(evt);
            } //if begin event

        }//while textstream

      selectedDate = QDate::currentDate();
      updateCalendar();
      showEventsOnListViewDay(selectedDate);
      gotoTodaySlot();
}

void MainWindow::upcomingSlot()
{	
	//qDebug() << "upcoming slot";	
	speech = new SpeechEngine();
	speech->generateUpcomingEventsTalk(findUpcomingEvents());
	
	QString diphonePath = QApplication::applicationDirPath() + "/diphone/";	
	if (!directoryExists(diphonePath))
	{	
	QString str = "Diphones do not exist."
	"\nInstall diphone folder to application path.";	
	QMessageBox::information(this, "Diphones Missing", str);
	return;
	}
	
	if (fileExists("/tmp/talkout.wav"))
	{	
	QMediaPlayer *player = new QMediaPlayer;
	player->setMedia(QUrl::fromLocalFile("/tmp/talkout.wav"));    
	player->setPlaybackRate(1.25);  
	player->play();
	}
	else
	{
	// to do..
	//qDebug() << "missing talk file";
	}	
}

void MainWindow::speechSlot()
{
	speech = new SpeechEngine();	
		
	QString diphonePath = QApplication::applicationDirPath() + "/diphone/";
	
	if (!directoryExists(diphonePath))
	{     
    QString str = "Diphones do not exist."
	"\nInstall diphone folder to application path.";
	
    QMessageBox::information(this, "Diphones Missing", str);
    return;
	}
	
	
	QList<Event> dateEventList;
    dateEventList = getTimeSortedDayList(selectedDate);
    QList<Event> upcomingList = findUpcomingEvents();	
	speech->generateTalkOut(selectedDate, dateEventList, upcomingList, currentPreferences);
		
	
	if (fileExists("/tmp/talkout.wav"))
	{
	
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("/tmp/talkout.wav"));    
    player->setPlaybackRate(1.25); 
    //player->setVolume(100); //by default the volume is 100. 
    player->play();
	}
	else
	{
    // to do..
    //qDebug() << "missing talk file";
	}
}

QList<Event> MainWindow::findUpcomingEvents()
{

  QList<Event> lookAheadList = QList<Event>();
  QDate todayDate = QDate::currentDate();

  //qDebug() << "lookahead days: " << currentPreferences.m_lookAheadDays;

  for (int j = 1; j <= currentPreferences.m_lookAheadDays; j++) // day after current
  {
    lookAheadList.append(getDayListCurrent(todayDate.addDays(j)));
  }
  return lookAheadList;
}
