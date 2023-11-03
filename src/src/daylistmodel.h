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

#ifndef DAYLISTMODEL_H
#define DAYLISTMODEL_H

#include "event.h"
#include <QAbstractListModel>
#include <QColor>
#include <QDebug>
#include <QFont>
#include <QIcon>
#include <QTime>

class DayListModel : public QAbstractListModel {
public:
  DayListModel(QObject *parent = nullptr);
  DayListModel(const QList<Event> &appointmentList,
               QObject *parent = nullptr);

  void addEvent(Event &event);
  void updateEvent(Event &event, int index);
  Event getEvent(int index);
  void clearAllEvents();
  void removeEvent(int idx);

  void isDarkStyle(bool flag);
  void is12HourFormat(bool flag);
  
  bool flagDarkStyle=false;
  bool flag12HourFormat=false; 
   

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;

  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;

private:
  QList<Event> modelEventList;
  void timeSortDayList();
  QString get12HourTimeStr(int hour, int min) const;
  QString get24HourTimeStr(int hour, int min) const;
};

#endif // DAYLISTMODEL_H
