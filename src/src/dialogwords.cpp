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


#include "dialogwords.h"
#include "ui_dialogwords.h"


DialogWords::DialogWords(QWidget *parent) :
QDialog(parent),
ui(new Ui::DialogWords) {

  ui->setupUi(this);

  setWindowTitle("Speech Words");

  speechWordsList  = QStringList{
    "Activity",
    "Airport",
    "Anniversary",
    "Appointment",
    "Bank",
    "Birthday",
    "Bus",
    "Car",
    "Church",
    "Code",
    "Decorating",
    "Delivery",
    "Dentist",
    "Development",
    "DIY",
    "Doctor",
    "Engagement",
    "Family",
    "Film",
    "Friends",
    "Funeral",
    "Garden",
    "Holiday",
    "Hospital",
    "Important",
    "Information",
    "Meal",
    "Medical",
    "Meeting",
    "Meetup",
    "Netflix",
    "Note",
    "Party",
    "Payment",
    "Radio",
    "Reminder",
    "Restaurant",
    "Retirement",
    "School",
    "Service",
    "Shopping",
    "Social",
    "Sport",
    "Station",
    "Train",
    "Travel",
    "Visit",
    "Wedding"};

    model = new QStringListModel();
    model->setStringList(speechWordsList);
    ui->listViewWords->setModel(model);

    connect(ui->lineEditSearch, SIGNAL(returnPressed()),this,SLOT(on_pushButtonSearch_clicked()));

}


DialogWords::~DialogWords() {
  delete ui;
}


QString DialogWords::getSpeechWord() {

  speechWord ="unknown";
  int row= ui->listViewWords->currentIndex().row();
  qDebug()<<"selected row = "<<row;  
  QModelIndex idx = model->index(row,0);
  speechWord = model->data(idx,0).toString();
  qDebug()<<"speech word = "<<speechWord<<"\n";
  return speechWord;
}

void DialogWords::on_pushButtonReset_clicked()
{
    model->setStringList(speechWordsList);
    ui->listViewWords->setModel(model);
    ui->lineEditSearch->setText("");
}

QString DialogWords::toCamelCase(const QString& s)
{
    
    QStringList parts = s.split(' ', QStringParser::SkipEmptyParts);
    for (int i = 0; i < parts.size(); ++i)
        parts[i].replace(0, 1, parts[i][0].toUpper());

    return parts.join(" ");
}

void DialogWords::on_pushButtonSearch_clicked()
{
  // qDebug()<<"pushButtonSearch pressed\n";
  QString leStr = getLineEditText();
  // qDebug()<<"lineedit str = "<<leStr;
   QString filterStr = toCamelCase(leStr); 
  //qDebug()<<"filter str = "<<filterStr;
  // filter Qt::CaseInsensitive 0 Qt::CaseSensitive 1 no effect 
  // so use toCamelCase()
  QStringList result;  
  result = speechWordsList.filter(filterStr, Qt::CaseInsensitive);
  // qDebug()<<result;
  model->setStringList(result);
  ui->listViewWords->setModel(model);
}

QString DialogWords::getLineEditText() {

  QString searchStr =ui->lineEditSearch->text();
  searchStr.replace(';', " ");
  searchStr.replace('.', " ");
  searchStr.replace(',', " ");
  searchStr.replace('!', " ");
  searchStr.replace('?', " ");
  //searchStr.replace('\'', " "); //allow for words with an apostrophe
  searchStr.replace('\"', " ");
  searchStr.replace(QRegularExpression("[\\n|\\r|\\t]+"), " ");
  qDebug()<<"search string = "<<searchStr;
  return searchStr;

}

void DialogWords::on_pushButtonOk_clicked()
{
  QDialog::accept();
}

void DialogWords::on_pushButtonCancel_clicked()
{
  QDialog::reject();
}
