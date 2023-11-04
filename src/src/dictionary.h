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


#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QString>
#include <QUrl>
#include <QDebug>
#include <QHash>
#include <QApplication>
#include <QDate>
#include <QList>


class Dictionary
{
public:
	Dictionary();
	
	QString wordToDiphones(QString);

private: 

QHash<QString, QString> diphoneDictionary;

void setupDictionary();


};   

#endif //DICTIONARY_H
