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


#ifndef SPEECHENGINE_H
#define SPEECHENGINE_H

#include <QString>
#include <QUrl>
#include <QDebug>
#include <QHash>
#include <QApplication>
#include <QDate>
#include <QList>

#include "wavcat.h"
#include "event.h"
#include "preferences.h"


class SpeechEngine
{
public:
	SpeechEngine();
	
	void generateTalkOut(QDate date, QList<Event> dateEventList, QList<Event> upcomingList, Preferences currentPreferences);
	void generateTalkOut();
	void generateUpcomingEventsTalk(QList<Event> upcomingList);

	
private: 

	QString getWavPath(QString word);
	QHash<int, QString> lookupOrdinalNumber;
	QHash<int, QString> lookupCardinalNumber;
	QHash<int, QString> lookupMonth;
	QHash<int, QString> lookupDay;
	void setupLookupOrdinalNumber();
	void setupLookupCardinalNumber();
	void setupLookupMonth();
	void setupLookupDay();
	bool CheckForDayEventOverlap(QList<Event> eventListDay); 
	QDate calculateEaster(int year);
	QString getSpeechWords(QString summary);
	QString getNumberWords(int num);
	QString getNumberUpcomingWords(int num);
	
};

#endif //SPEECHENGINE_H
