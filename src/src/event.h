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
#ifndef EVENT_H
#define EVENT_H

#include <QString>

//Todo: update to handle ICS file multiday events
struct Event {

    Event(int id = 0,

          const QString &summary = QString(),
          const QString &location = QString(),
          const QString &description = QString(),

          int startYear = 2020,
          int startMonth = 1,
          int startDay = 1,
          int startHour = 9,
          int startMin = 0,
          int endYear = 2020,
          int endMonth = 1,
          int endDay = 1,
          int endHour = 10,
          int endMin = 0,
          int isYearly = 0,
          int isAllDay = 0,
          int isPriority = 0,
          int hasReminder = 0,
          int reminderMins = 0) : m_id(id),
                                  m_summary(summary),
                                  m_location(location),
                                  m_description(description),
                                  m_startYear(startYear),
                                  m_startMonth(startMonth),
                                  m_startDay(startDay),
                                  m_startHour(startHour),
                                  m_startMin(startMin),
                                  m_endYear(endYear),
                                  m_endMonth(endMonth),
                                  m_endDay(endDay),
                                  m_endHour(endHour),
                                  m_endMin(endMin),
                                  m_isYearly(isYearly),
                                  m_isAllDay(isAllDay),
                                  m_isPriority(isPriority),
                                  m_hasReminder(hasReminder),
                                  m_reminderMinutes(reminderMins) {
    }
    int m_id;
    QString m_summary;
    QString m_location;
    QString m_description;
    int m_startYear;
    int m_startMonth;
    int m_startDay;
    int m_startHour;
    int m_startMin;
    int m_endYear;
    int m_endMonth;
    int m_endDay;
    int m_endHour;
    int m_endMin;
    int m_isYearly;
    int m_isAllDay;
    int m_isPriority;
    int m_hasReminder;
    int m_reminderMinutes;
    //equals operator
    bool operator==(const Event &other) const {
        if (this->m_id == (other.m_id)) {
            return true;
        }
        return false;
    }
};

#endif // EVENT_H
