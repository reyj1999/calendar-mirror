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

#include "daylistmodel.h"

DayListModel::DayListModel(QObject *parent) {
  Q_UNUSED(parent)
  this->modelEventList = QList<Event>();
}

DayListModel::DayListModel(const QList<Event> &eventList, QObject *parent) {
  Q_UNUSED(parent)
  this->modelEventList = eventList;
  timeSortDayList();
}

//-------------------------------------
void  DayListModel::timeSortDayList() {

   //do it manually as qSort no longer available
   int n;
   int i;
   for (n=0; n < modelEventList.count(); n++)
   {
     for (i=n+1; i < modelEventList.count(); i++)
     {
       Event event1 = modelEventList.value(n);
       Event event2 = modelEventList.value(i);

       int event1Hour = event1.m_startHour;
       int event1Min = event1.m_startMin;
       int event2Hour = event2.m_startHour;
       int event2Min = event2.m_startMin;

       int fx = 60 * 60 * event1Hour + 60 * event1Min; //seconds
       int sx = 60 * 60 * event2Hour + 60 * event2Min;

       if (fx > sx)
       {
         modelEventList.move(i, n);
         n=0;
       }
     } //for i
   } //for n

 }

void DayListModel::addEvent(Event &event) {
  beginInsertRows(QModelIndex(), rowCount(), rowCount());
  this->modelEventList.append(event);
  endInsertRows();
}

void DayListModel::updateEvent(Event &event, int index) {
  
  beginInsertRows(QModelIndex(), rowCount(), rowCount());
  Event e = modelEventList.value(index);
  e.m_summary = event.m_summary;
  e.m_location =event.m_location;
  e.m_description = event.m_description;
  e.m_isAllDay = event.m_isAllDay;

  e.m_startYear =event.m_startYear;
  e.m_startMonth=event.m_startMonth;
  e.m_startDay =event.m_startDay;
  e.m_startHour = event.m_startHour;
  e.m_startMin = event.m_startMin;


  e.m_endYear=event.m_endYear;
  e.m_endMonth=event.m_endMonth;
  e.m_endDay =event.m_endDay;
  e.m_endHour = event.m_endHour;
  e.m_endMin = event.m_endMin;

  
  modelEventList.removeAt(index);
  modelEventList.insert(index, e);
  endInsertRows();
}

Event DayListModel::getEvent(int index) {
  Event e = modelEventList.value(index);
  return e;
}

void DayListModel::clearAllEvents() {
  beginResetModel();
  modelEventList.clear();
  endResetModel();
}

void DayListModel::removeEvent(int idx) {
  beginRemoveRows(QModelIndex(), 0, rowCount());
  modelEventList.removeAt(idx);
  endRemoveRows();
}


void DayListModel::isDarkStyle(bool flag) {  
  flagDarkStyle=flag;
}

void DayListModel::is12HourFormat(bool flag) {  
  flag12HourFormat=flag;
}

//-----------------------------------
QString DayListModel::get12HourTimeStr(const int hour, const int min) const {

   QString timeStr="";
   int clockHour;
   int clockMin;
   clockHour=hour;
   clockMin=min;

   if(hour==12) {
     clockHour=12;
     timeStr.append(QString::number(clockHour));
     timeStr.append(":");
     if(min <=9){
       timeStr.append(QString::number(0));
     }
     timeStr.append(QString::number(clockMin));
     timeStr.append(" pm ");
   } //if sHour==12

   else if(hour>12) {
     clockHour=hour-12;
     timeStr.append(QString::number(clockHour));
     timeStr.append(":");
     if(min <=9){
       timeStr.append(QString::number(0));
     }
     timeStr.append(QString::number(clockMin));
     timeStr.append(" pm ");
   } //if sHour>12

   else {
     timeStr.append(QString::number(clockHour));
     timeStr.append(":");
     if(min <=9){
       timeStr.append(QString::number(0));
     }
     timeStr.append(QString::number(clockMin));
     timeStr.append(" am ");
   }
   return timeStr;
}

//--------------------------------

QString DayListModel::get24HourTimeStr(const int hour, const int min) const {

  QString timeStr="";
   int clockHour;
   int clockMin;
   clockHour=hour;
   clockMin=min;

  timeStr.append(QString::number(clockHour));
  timeStr.append(":");
  if(min <=9){
    timeStr.append(QString::number(0));
  }
  timeStr.append(QString::number(clockMin));

  return timeStr;
}


int DayListModel::rowCount(const QModelIndex &parent) const {
  Q_UNUSED(parent)
  return modelEventList.size();
}

QVariant DayListModel::data(const QModelIndex &index, int role) const {


  if (!index.isValid())
    return QVariant();
  if (index.row() >= modelEventList.size() || index.row() < 0)
    return QVariant();
  const Event &event = modelEventList.at(index.row());

  if (role == Qt::DisplayRole) {


    QString details = "";

    QString startTimeStr="";
    QString endTimeStr="";

    int sYear =event.m_startYear;
    int sMonth=event.m_startMonth;
    int sDay =event.m_startDay;

    int sHour =event.m_startHour;
    int sMin =event.m_startMin;

    int eYear=event.m_endYear;
    int eMonth =event.m_endMonth;
    int eDay =event.m_endDay;

    int eHour =event.m_endHour;
    int eMin =event.m_endMin;

    QDate startDate =QDate(sYear, sMonth, sDay);
    QDate endDate =QDate(eYear, eMonth, eDay);

    if(startDate == endDate && event.m_isAllDay)
    {
      details.append("All Day Event: ");
      details.append(" ");
      details.append(event.m_summary);

      if (!event.m_location.isEmpty()) {
        details.append("\n");
        details.append("Location: ");
        details.append(event.m_location);
      }

      if (!event.m_description.isEmpty()) {
        details.append("\n");
        details.append(event.m_description);
      }
      return details;

    } //all day

    else if (startDate == endDate && !event.m_isAllDay) {


      if(flag12HourFormat) {
        startTimeStr=get12HourTimeStr(sHour, sMin);
        endTimeStr=get12HourTimeStr(eHour, eMin);
      }
      else {
        startTimeStr=get24HourTimeStr(sHour, sMin);
        endTimeStr=get24HourTimeStr(eHour, eMin);
      } //else 24 hour


      details.append(startTimeStr);
      details.append(" to ");
      details.append(endTimeStr);
      details.append(" ");
      details.append(event.m_summary);

      if (!event.m_location.isEmpty()) {
        details.append("\n");
        details.append("Location: ");
        details.append(event.m_location);
      }

      if (!event.m_description.isEmpty()) {
        details.append("\n");
        details.append(event.m_description);
      }

      return details;
    }// if startdate==endDate and not all day

    else {
      //multiday event
      details.append ("Multi-day event: ");
       details.append(event.m_summary);
      details.append("\n");

      QDate startDate =QDate(sYear, sMonth, sDay);
      QDate endDate =QDate(eYear,eMonth,eDay);

      if(flag12HourFormat) {
        startTimeStr=get12HourTimeStr(sHour, sMin);
        endTimeStr=get12HourTimeStr(eHour, eMin);
      }
      else {
        //24 hour format
        startTimeStr=get24HourTimeStr(sHour, sMin);
        endTimeStr=get24HourTimeStr(eHour, eMin);
      } //else 24 hour

      details.append(startTimeStr);
      details.append(" ");
      details.append(startDate.toString());

      details.append(" to ");
      details.append(endTimeStr);
      details.append(" ");
      details.append(endDate.toString());
      //details.append("\n");
      //details.append(event.m_summary);

      if (!event.m_location.isEmpty()) {
        details.append("\n");
        details.append("Location: ");
        details.append(event.m_location);
      }

      if (!event.m_description.isEmpty()) {
        details.append("\n");
        details.append(event.m_description);
      }

      return details;

    } //else multiday

  } // if role Qt::DisplayRole



 if (role == Qt::ForegroundRole) {
  QColor colour = Qt::black;
  if(flagDarkStyle) colour=Qt::white;
  return colour;
  }


  if (role == Qt::BackgroundRole) {
  QColor colour = Qt::white;
  if(flagDarkStyle) colour =QColor(105, 105, 105,255); //grey
  return colour;
  }


  if (role == Qt::DecorationRole) {
    //no decorations
  
  }

  return QVariant();
 
}
