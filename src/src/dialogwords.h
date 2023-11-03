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
#ifndef DIALOGWORDS_H
#define DIALOGWORDS_H

#include <QDebug>
#include <QDialog>
#include <QStringList>
#include <QStringListModel>

namespace Ui {
  class DialogWords;
}

class DialogWords : public QDialog {

  CS_OBJECT(DialogWords)

public:
  explicit DialogWords(QWidget *parent = nullptr);
  ~DialogWords();

 QString getSpeechWord();

private :
   //button slots
    CS_SLOT_1(Private, void on_pushButtonSearch_clicked())
    CS_SLOT_2(on_pushButtonSearch_clicked) 
    CS_SLOT_1(Private, void on_pushButtonReset_clicked())
    CS_SLOT_2(on_pushButtonReset_clicked) 
    CS_SLOT_1(Private, void on_pushButtonOk_clicked())
    CS_SLOT_2(on_pushButtonOk_clicked) 
    CS_SLOT_1(Private, void on_pushButtonCancel_clicked())
    CS_SLOT_2(on_pushButtonCancel_clicked) 

private:
  Ui::DialogWords *ui;

  QStringList speechWordsList;
  QStringListModel *model;
  QString getLineEditText();

  QString toCamelCase(const QString& s);

  QString speechWord="";


};

#endif // DIALOGWORDS_H
