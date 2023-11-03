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

#include "speechengine.h"

SpeechEngine::SpeechEngine()
{
  setupLookupOrdinalNumber();
  setupLookupCardinalNumber();
  setupLookupMonth();
  setupLookupDay();
}

QDate SpeechEngine::calculateEaster(int year) {
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

QString SpeechEngine::getWavPath(QString word){

	//word

	//Days of week
	if (word=="monday") return QApplication::applicationDirPath()+"/dict/day/monday.wav";
	else if (word=="tuesday") return QApplication::applicationDirPath()+"/dict/day/tuesday.wav";
	else if (word=="wednesday") return QApplication::applicationDirPath()+"/dict/day/wednesday.wav";
	else if (word=="thursday") return QApplication::applicationDirPath()+"/dict/day/thursday.wav";
	else if (word=="friday") return QApplication::applicationDirPath()+"/dict/day/friday.wav";
	else if (word=="saturday") return QApplication::applicationDirPath()+"/dict/day/saturday.wav";
	else if (word=="sunday") return QApplication::applicationDirPath()+"/dict/day/sunday.wav";

	//months
	else if (word=="january") return QApplication::applicationDirPath()+"/dict/month/january.wav";
	else if (word=="february") return QApplication::applicationDirPath()+"/dict/month/february.wav";
	else if (word=="march") return QApplication::applicationDirPath()+"/dict/month/march.wav";
	else if (word=="april") return QApplication::applicationDirPath()+"/dict/month/april.wav";
	else if (word=="may") return QApplication::applicationDirPath()+"/dict/month/may.wav";
	else if (word=="june") return QApplication::applicationDirPath()+"/dict/month/june.wav";
	else if (word=="july") return QApplication::applicationDirPath()+"/dict/month/july.wav";
	else if (word=="august") return QApplication::applicationDirPath()+"/dict/month/august.wav";
	else if (word=="september") return QApplication::applicationDirPath()+"/dict/month/september.wav";
	else if (word=="october") return QApplication::applicationDirPath()+"/dict/month/october.wav";
	else if (word=="november") return QApplication::applicationDirPath()+"/dict/month/november.wav";
	else if (word=="december") return QApplication::applicationDirPath()+"/dict/month/december.wav";

	//ordinal numbers
	else if (word=="first") return QApplication::applicationDirPath()+"/dict/ordinal/first.wav";
	else if (word=="second") return QApplication::applicationDirPath()+"/dict/ordinal/second.wav";
	else if (word=="third") return QApplication::applicationDirPath()+"/dict/ordinal/third.wav";
	else if (word=="fourth") return QApplication::applicationDirPath()+"/dict/ordinal/fourth.wav";
	else if (word=="fifth") return QApplication::applicationDirPath()+"/dict/ordinal/fifth.wav";
	else if (word=="sixth") return QApplication::applicationDirPath()+"/dict/ordinal/sixth.wav";
	else if (word=="seventh") return QApplication::applicationDirPath()+"/dict/ordinal/seventh.wav";
	else if (word=="eighth") return QApplication::applicationDirPath()+"/dict/ordinal/eighth.wav";
	else if (word=="ninth") return QApplication::applicationDirPath()+"/dict/ordinal/ninth.wav";
	else if (word=="tenth") return QApplication::applicationDirPath()+"/dict/ordinal/tenth.wav";
	else if (word=="eleventh") return QApplication::applicationDirPath()+"/dict/ordinal/eleventh.wav";
	else if (word=="twelfth") return QApplication::applicationDirPath()+"/dict/ordinal/twelfth.wav";
	else if (word=="thirteenth") return QApplication::applicationDirPath()+"/dict/ordinal/thirteenth.wav";
	else if (word=="fourteenth") return QApplication::applicationDirPath()+"/dict/ordinal/fourteenth.wav";
	else if (word=="fifteenth") return QApplication::applicationDirPath()+"/dict/ordinal/fifteenth.wav";
	else if (word=="sixteenth") return QApplication::applicationDirPath()+"/dict/ordinal/sixteenth.wav";
	else if (word=="seventeeth") return QApplication::applicationDirPath()+"/dict/ordinal/seventeenth.wav";
	else if (word=="eighteenth") return QApplication::applicationDirPath()+"/dict/ordinal/eighteenth.wav";
	else if (word=="nineteenth") return QApplication::applicationDirPath()+"/dict/ordinal/nineteenth.wav";
	else if (word=="twentieth") return QApplication::applicationDirPath()+"/dict/ordinal/twentieth.wav";
	else if (word=="twentyfirst") return QApplication::applicationDirPath()+"/dict/ordinal/twentyfirst.wav";
	else if (word=="twentysecond") return QApplication::applicationDirPath()+"/dict/ordinal/twentysecond.wav";
	else if (word=="twentythird") return QApplication::applicationDirPath()+"/dict/ordinal/twentythird.wav";
	else if (word=="twentyfourth") return QApplication::applicationDirPath()+"/dict/ordinal/twentyfourth.wav";
	else if (word=="twentyfifth") return QApplication::applicationDirPath()+"/dict/ordinal/twentyfifth.wav";
	else if (word=="twentysixth") return QApplication::applicationDirPath()+"/dict/ordinal/twentysixth.wav";
	else if (word=="twentyseventh") return QApplication::applicationDirPath()+"/dict/ordinal/twentyseventh.wav";
	else if (word=="twentyeighth") return QApplication::applicationDirPath()+"/dict/ordinal/twentyeighth.wav";
	else if (word=="twentyninth") return QApplication::applicationDirPath()+"/dict/ordinal/twentyninth.wav";
	else if (word=="thirtieth") return QApplication::applicationDirPath()+"/dict/ordinal/thirtieth.wav";
	else if (word=="thirtyfirst") return QApplication::applicationDirPath()+"/dict/ordinal/thirtyfirst.wav";

  // cardinal numbers
  else if (word == "zero")
    return QApplication::applicationDirPath() + "/dict/cardinal/zero.wav";
  else if (word == "one")
    return QApplication::applicationDirPath() + "/dict/cardinal/one.wav";
  else if (word == "two")
    return QApplication::applicationDirPath() + "/dict/cardinal/two.wav";
  else if (word == "three")
    return QApplication::applicationDirPath() + "/dict/cardinal/three.wav";
  else if (word == "four")
    return QApplication::applicationDirPath() + "/dict/cardinal/four.wav";
  else if (word == "five")
    return QApplication::applicationDirPath() + "/dict/cardinal/five.wav";
  else if (word == "six")
    return QApplication::applicationDirPath() + "/dict/cardinal/six.wav";
  else if (word == "seven")
    return QApplication::applicationDirPath() + "/dict/cardinal/seven.wav";
  else if (word == "eight")
    return QApplication::applicationDirPath() + "/dict/cardinal/eight.wav";
  else if (word == "nine")
    return QApplication::applicationDirPath() + "//dict/cardinal/nine.wav";
  else if (word == "ten")
    return QApplication::applicationDirPath() + "/dict/cardinal/ten.wav";
  else if (word == "eleven")
    return QApplication::applicationDirPath() + "//dict/cardinal/eleven.wav";
  else if (word == "twelve")
    return QApplication::applicationDirPath() + "//dict/cardinal/twelve.wav";
  else if (word == "thirteen")
    return QApplication::applicationDirPath() + "/dict/cardinal/thirteen.wav";
  else if (word == "fourteen")
    return QApplication::applicationDirPath() + "/dict/cardinal/fourteen.wav";
  else if (word == "fifteen")
    return QApplication::applicationDirPath() + "//dict/cardinal/fifteen.wav";

  else if (word == "sixteen")
    return QApplication::applicationDirPath() + "/dict/cardinal/sixteen.wav";
    
  else if (word == "seventeen")
    return QApplication::applicationDirPath() + "/dict/cardinal/seventeen.wav";
  else if (word == "eighteen")
    return QApplication::applicationDirPath() + "/dict/cardinal/eighteen.wav";
  else if (word == "ninteen")
    return QApplication::applicationDirPath() + "/dict/cardinal/nineteen.wav";
  else if (word == "twenty")
    return QApplication::applicationDirPath() + "/dict/cardinal/twenty.wav";
  else if (word == "thirty")
    return QApplication::applicationDirPath() + "/dict/cardinal/thirty.wav";
  else if (word == "forty")
    return QApplication::applicationDirPath() + "/dict/cardinal/forty.wav";
  else if (word == "fifty")
    return QApplication::applicationDirPath() + "/dict/cardinal/fifty.wav";

  // words
  // a words
  else if (word == "activity")
    return QApplication::applicationDirPath() + "/dict/a/activity.wav";
  else if (word == "airport")
    return QApplication::applicationDirPath() + "/dict/a/airport.wav";
  else if (word == "alert")
    return QApplication::applicationDirPath() + "/dict/a/alert.wav";
  else if (word == "all")
    return QApplication::applicationDirPath() + "/dict/a/all.wav";
  else if (word == "am")
    return QApplication::applicationDirPath() + "/dict/a/am.wav";
  else if (word == "anniversary")
    return QApplication::applicationDirPath() + "/dict/a/anniversary.wav";
  else if (word == "appointment")
    return QApplication::applicationDirPath() + "/dict/a/appointment.wav";
  else if (word == "as")
    return QApplication::applicationDirPath() + "/dict/a/as.wav";
  // b words
  else if (word == "bank")
    return QApplication::applicationDirPath() + "/dict/b/bank.wav";
  else if (word == "birthday")
    return QApplication::applicationDirPath() + "/dict/b/birthday.wav";
  else if (word == "boxing")
    return QApplication::applicationDirPath() + "/dict/b/boxing.wav";
  else if (word == "bus")
    return QApplication::applicationDirPath() + "/dict/b/bus.wav";
  // c words
  else if (word == "calendar")
    return QApplication::applicationDirPath() + "/dict/c/calendar.wav";
  else if (word == "car")
    return QApplication::applicationDirPath() + "/dict/c/car.wav";
  else if (word == "casper")
    return QApplication::applicationDirPath() + "/dict/c/casper.wav";
  else if (word == "church")
    return QApplication::applicationDirPath() + "/dict/c/church.wav";
  else if (word == "christmas")
    return QApplication::applicationDirPath() + "/dict/c/christmas.wav";
  else if (word == "code")
    return QApplication::applicationDirPath() + "/dict/c/code.wav";
  // d words
  else if (word == "day")
    return QApplication::applicationDirPath() + "/dict/d/day.wav";
  else if (word == "decorating")
    return QApplication::applicationDirPath() + "/dict/d/decorating.wav";
  else if (word == "delivery")
    return QApplication::applicationDirPath() + "/dict/d/delivery.wav";
  else if (word == "dentist")
    return QApplication::applicationDirPath() + "/dict/d/dentist.wav";
  else if (word == "development")
    return QApplication::applicationDirPath() + "/dict/d/development.wav";
  else if (word == "diy")
    return QApplication::applicationDirPath() + "/dict/d/diy.wav";
  else if (word == "doctor")
    return QApplication::applicationDirPath() + "/dict/d/doctor.wav";
  // e words
  else if (word == "easter")
    return QApplication::applicationDirPath() + "/dict/e/easter.wav";
  else if (word == "engagement")
    return QApplication::applicationDirPath() + "/dict/e/engagement.wav";
  else if (word == "event")
    return QApplication::applicationDirPath() + "/dict/e/event.wav";
  else if (word == "events")
    return QApplication::applicationDirPath() + "/dict/e/events.wav";
  // f words
  else if (word == "family")
    return QApplication::applicationDirPath() + "/dict/f/family.wav";
  else if (word == "film")
    return QApplication::applicationDirPath() + "/dict/f/film.wav";
  else if (word == "friends")
    return QApplication::applicationDirPath() + "/dict/f/friends.wav";
  else if (word == "funeral")
    return QApplication::applicationDirPath() + "/dict/f/funeral.wav";
  // g words
  else if (word == "garden")
    return QApplication::applicationDirPath() + "/dict/g/garden.wav";
  // h words
  else if (word == "halloween")
    return QApplication::applicationDirPath() + "/dict/h/halloween.wav";
  else if (word == "have")
    return QApplication::applicationDirPath() + "/dict/h/have.wav";
  else if (word == "high")
    return QApplication::applicationDirPath() + "/dict/h/high.wav";
  else if (word == "holiday")
    return QApplication::applicationDirPath() + "/dict/h/holiday.wav";
  else if (word == "hospital")
    return QApplication::applicationDirPath() + "/dict/h/hospital.wav";
  // i words
  else if (word == "important")
    return QApplication::applicationDirPath() + "/dict/i/important.wav";
  else if (word == "information")
    return QApplication::applicationDirPath() + "/dict/i/information.wav";
  // m words
  else if (word == "many")
    return QApplication::applicationDirPath() + "/dict/m/many.wav";
  else if (word == "meal")
    return QApplication::applicationDirPath() + "/dict/m/meal.wav";
  else if (word == "medical")
    return QApplication::applicationDirPath() + "/dict/m/medical.wav";
  else if (word == "meeting")
    return QApplication::applicationDirPath() + "/dict/m/meeting.wav";
  else if (word == "meetup")
    return QApplication::applicationDirPath() + "/dict/m/meetup.wav";
  else if (word == "multi")
    return QApplication::applicationDirPath() + "/dict/m/multi.wav";
  // n words
  else if (word == "netflix")
    return QApplication::applicationDirPath() + "/dict/n/netflix.wav";
  else if (word == "new")
    return QApplication::applicationDirPath() + "/dict/n/new.wav";
  else if (word == "no")
    return QApplication::applicationDirPath() + "/dict/n/no.wav";
  else if (word == "note")
    return QApplication::applicationDirPath() + "/dict/n/note.wav";
  // o words
  else if (word == "overlapping")
    return QApplication::applicationDirPath() + "/dict/o/overlapping.wav";
  // p words
  else if (word == "party")
    return QApplication::applicationDirPath() + "/dict/p/party.wav";
  else if (word == "payment")
    return QApplication::applicationDirPath() + "/dict/p/payment.wav";
  else if (word == "pm")
    return QApplication::applicationDirPath() + "/dict/p/pm.wav";
  else if (word == "priority")
    return QApplication::applicationDirPath() + "/dict/p/priority.wav";
  else if (word == "public")
    return QApplication::applicationDirPath() + "/dict/p/public.wav";
  // r words
  else if (word == "radio")
    return QApplication::applicationDirPath() + "/dict/r/radio.wav";
  else if (word == "reminder")
    return QApplication::applicationDirPath() + "/dict/r/reminder.wav";
  else if (word == "restaurant")
    return QApplication::applicationDirPath() + "/dict/r/restaurant.wav";
  else if (word == "retirement")
    return QApplication::applicationDirPath() + "/dict/r/retirement.wav";
  // s words
  else if (word == "school")
    return QApplication::applicationDirPath() + "/dict/s/school.wav";
  else if (word == "service")
    return QApplication::applicationDirPath() + "/dict/s/service.wav";
  else if (word == "shopping")
    return QApplication::applicationDirPath() + "/dict/s/shopping.wav";
  else if (word == "social")
    return QApplication::applicationDirPath() + "/dict/s/social.wav";
  else if (word == "sport")
    return QApplication::applicationDirPath() + "/dict/s/sport.wav";
  else if (word == "station")
    return QApplication::applicationDirPath() + "/dict/s/station.wav";
  // t words
  else if (word == "tagged")
    return QApplication::applicationDirPath() + "/dict/t/tagged.wav";
  else if (word == "talk")
    return QApplication::applicationDirPath() + "/dict/t/talk.wav";
  else if (word == "then")
    return QApplication::applicationDirPath() + "/dict/t/then.wav";
  else if (word == "today")
    return QApplication::applicationDirPath() + "/dict/t/today.wav";
  else if (word == "train")
    return QApplication::applicationDirPath() + "/dict/t/train.wav";
  else if (word == "travel")
    return QApplication::applicationDirPath() + "/dict/t/travel.wav";
  // u words
  else if (word == "upcoming")
    return QApplication::applicationDirPath() + "/dict/u/upcoming.wav";
  // v words
  else if (word == "visit")
    return QApplication::applicationDirPath() + "/dict/v/visit.wav";
  else if (word == "valentine")
    return QApplication::applicationDirPath() + "/dict/v/valentine.wav";
  // w words
  else if (word == "wedding")
    return QApplication::applicationDirPath() + "/dict/w/wedding.wav";
  // y words
  else if (word == "year")
    return QApplication::applicationDirPath() + "/dict/y/year.wav";
  else if (word == "you")
    return QApplication::applicationDirPath() + "/dict/y/you.wav";

  else
    return QApplication::applicationDirPath() + "/dict/u/unknown.wav";
}

void SpeechEngine::setupLookupCardinalNumber()
{
    //how many number
    lookupCardinalNumber.insert(0, "zero ");
    lookupCardinalNumber.insert(1, "one ");
    lookupCardinalNumber.insert(2, "two ");
    lookupCardinalNumber.insert(3, "three ");
    lookupCardinalNumber.insert(4, "four ");
    lookupCardinalNumber.insert(5, "five ");
    lookupCardinalNumber.insert(6, "six ");
    lookupCardinalNumber.insert(7, "seven ");
    lookupCardinalNumber.insert(8, "eight ");
    lookupCardinalNumber.insert(9, "nine ");
    lookupCardinalNumber.insert(10, "ten ");
    lookupCardinalNumber.insert(11, "eleven ");
    lookupCardinalNumber.insert(12, "twelve ");
    lookupCardinalNumber.insert(13, "thirteen ");
    lookupCardinalNumber.insert(14, "fourteen ");
    lookupCardinalNumber.insert(15, "fifteen ");
    lookupCardinalNumber.insert(16, "sixteen ");
    lookupCardinalNumber.insert(17, "seventeen ");
    lookupCardinalNumber.insert(18, "eighteen ");
    lookupCardinalNumber.insert(19, "nineteen ");
    lookupCardinalNumber.insert(20, "twenty ");
    lookupCardinalNumber.insert(21, "twenty one ");   
    lookupCardinalNumber.insert(22, "twenty two ");
    lookupCardinalNumber.insert(23, "twenty three ");
    lookupCardinalNumber.insert(24, "twenty four ");
    lookupCardinalNumber.insert(25, "twenty five");
    lookupCardinalNumber.insert(26, "twenty six ");
    lookupCardinalNumber.insert(27, "twenty seven ");
    lookupCardinalNumber.insert(28, "twenty eight ");
    lookupCardinalNumber.insert(29, "twenty nine ");
    lookupCardinalNumber.insert(30, "thirty ");
    lookupCardinalNumber.insert(31, "thirty one ");
    lookupCardinalNumber.insert(32, "thirty two");
    lookupCardinalNumber.insert(33, "thirty three ");
    lookupCardinalNumber.insert(35, "thirty five ");
    lookupCardinalNumber.insert(36, "thirty six ");
    lookupCardinalNumber.insert(37, "thirty seven ");
    lookupCardinalNumber.insert(38, "thirty eight ");
    lookupCardinalNumber.insert(39, "thirty nine ");
    lookupCardinalNumber.insert(40, "forty ");
    lookupCardinalNumber.insert(41, "forty one ");
    lookupCardinalNumber.insert(42, "forty two ");
    lookupCardinalNumber.insert(43, "forty three ");
    lookupCardinalNumber.insert(44, "forty four ");
    lookupCardinalNumber.insert(45, "forty five ");
    lookupCardinalNumber.insert(46, "forty six ");
    lookupCardinalNumber.insert(47, "forty seven ");
    lookupCardinalNumber.insert(48, "forty eight");
    lookupCardinalNumber.insert(49, "forty nine ");
    lookupCardinalNumber.insert(50, "fifty ");
    lookupCardinalNumber.insert(51, "fifty one ");
    lookupCardinalNumber.insert(52, "fifty two ");
    lookupCardinalNumber.insert(53, "fifty three ");
    lookupCardinalNumber.insert(54, "fifty four ");
    lookupCardinalNumber.insert(55, "fifty five ");
    lookupCardinalNumber.insert(56, "fifty six ");
    lookupCardinalNumber.insert(57, "fifty seven ");
    lookupCardinalNumber.insert(58, "fifty eight ");
    lookupCardinalNumber.insert(59, "fifty nine ");

}


void SpeechEngine::setupLookupOrdinalNumber()
{
    //position number
    lookupOrdinalNumber.insert(1, "first ");
    lookupOrdinalNumber.insert(2, "second ");
    lookupOrdinalNumber.insert(3, "third ");
    lookupOrdinalNumber.insert(4, "fourth ");
    lookupOrdinalNumber.insert(5, "fifth ");
    lookupOrdinalNumber.insert(6, "sixth ");
    lookupOrdinalNumber.insert(7, "seventh ");
    lookupOrdinalNumber.insert(8, "eighth ");
    lookupOrdinalNumber.insert(9, "ninth ");
    lookupOrdinalNumber.insert(10, "tenth ");
    lookupOrdinalNumber.insert(11,"eleventh ");
    lookupOrdinalNumber.insert(12, "twelfth ");
    lookupOrdinalNumber.insert(13, "thirteenth ");
    lookupOrdinalNumber.insert(14, "fourteenth ");
    lookupOrdinalNumber.insert(15, "fifteenth ");
    lookupOrdinalNumber.insert(16, "sixteenth ");
    lookupOrdinalNumber.insert(17, "seventeenth ");
    lookupOrdinalNumber.insert(18, "eighteenth ");
    lookupOrdinalNumber.insert(19, "nineteenth ");
    lookupOrdinalNumber.insert(20, "twentieth ");
    lookupOrdinalNumber.insert(21, "twenty first ");
    lookupOrdinalNumber.insert(22, "twenty second ");
    lookupOrdinalNumber.insert(23, "twenty third ");
    lookupOrdinalNumber.insert(24, "twenty fourth ");
    lookupOrdinalNumber.insert(25, "twenty fifth ");
    lookupOrdinalNumber.insert(26, "twenty sixth ");
    lookupOrdinalNumber.insert(27, "twenty seventh ");
    lookupOrdinalNumber.insert(28, "twenty eighth ");
    lookupOrdinalNumber.insert(29, "twenty ninth ");
    lookupOrdinalNumber.insert(30, "thirtieth ");
    lookupOrdinalNumber.insert(31, "thirty first ");    
}

void SpeechEngine::setupLookupDay()
{
    lookupDay.insert(1, "monday");
    lookupDay.insert(2, "tuesday");
    lookupDay.insert(3, "wednesday");
    lookupDay.insert(4, "thursday");
    lookupDay.insert(5, "friday");
    lookupDay.insert(6, "saturday");
    lookupDay.insert(7, "sunday"); 
}

void SpeechEngine::setupLookupMonth()
{
    lookupMonth.insert(1, "january");
    lookupMonth.insert(2, "february");
    lookupMonth.insert(3, "march");
    lookupMonth.insert(4, "april");
    lookupMonth.insert(5, "may");
    lookupMonth.insert(6, "june");
    lookupMonth.insert(7, "july");
    lookupMonth.insert(8, "august");
    lookupMonth.insert(9, "september");
    lookupMonth.insert(10, "october");
    lookupMonth.insert(11, "november");
    lookupMonth.insert(12, "december");

}

void SpeechEngine::generateTalkOut()
{
  QString talkText;
  talkText.append("casper");
  talkText.append(" ");
  talkText.append("calendar");
  talkText.append(" ");
  talkText.append("reminder");

  // Must initialise wavout using wavEmpty
  WavCat wavEmpty(1, 8000, 16);
  wavEmpty.save("/tmp/empty.wav");
  WavCat wavout("/tmp/empty.wav"); // Assign empty wav to concatenation output

  QString textStr = talkText.toLower();
  QStringList wordList = textStr.split(QRegularExpression("\\s+"), QStringParser::SkipEmptyParts);

  for (int i = 0; i < wordList.count(); i++)
  {

    // qDebug() <<" word: " << wordList[i];
    QString word = wordList.at(i);
    QString path = getWavPath(word);
    WavCat tmp(path.toStdString());
    wavout = wavout + tmp;
  }
  wavout.save("/tmp/talkout.wav");
}

QString SpeechEngine::getNumberWords(int num) {

  QString talkText;
  if(num==0){
    talkText.append(" no ");
    talkText.append(" events");
  }
  else if(num==1){
    talkText.append(" one ");
    talkText.append(" event ");

  }
  else if(num==2){
    talkText.append(" two ");
    talkText.append(" events ");
  }
  else if(num==3){
    talkText.append("three");
    talkText.append("events");
  }
  else if(num==4){
    talkText.append(" four ");
    talkText.append(" events ");
  }
  else if(num==5){
    talkText.append(" five ");
    talkText.append(" events ");
  }
  else{
    talkText.append(" many ");
    talkText.append(" events ");
  }
  return talkText;
}

QString SpeechEngine::getNumberUpcomingWords(int num) {

  QString talkText;
  if(num==0){
    talkText.append(" no ");
    talkText.append(" upcoming ");
    talkText.append(" events");
  }
  else if(num==1){
    talkText.append(" one ");
    talkText.append(" upcoming ");
    talkText.append(" event ");
  }
  else if(num==2){
    talkText.append(" two ");
    talkText.append(" upcoming ");
    talkText.append(" events ");
  }
  else if(num==3){
    talkText.append("three");
    talkText.append(" upcoming ");
    talkText.append("events");
  }
  else if(num==4){
    talkText.append(" four ");
    talkText.append(" upcoming ");
    talkText.append(" events ");
  }
  else if(num==5){
    talkText.append(" five ");
    talkText.append(" upcoming ");
    talkText.append(" events ");
  }
  else{
    talkText.append(" many ");
    talkText.append(" upcoming ");
    talkText.append(" events ");
  }
  return talkText;
}


QString SpeechEngine::getSpeechWords(QString summary) {

  QString talkText;
  QString summaryStr =summary.toLower();

     summaryStr.replace(';', " ");
     summaryStr.replace('.', " ");
     summaryStr.replace(',', " ");
     summaryStr.replace('\'', " ");
     summaryStr.replace('\"', " ");    
     summaryStr.replace(QRegularExpression("[\\n|\\r|\\t]+"), " ");

     QStringList list = summaryStr.split(QRegularExpression("\\s+"), QStringParser::SkipEmptyParts);

     //check to see if tag word exists
     bool tagWordExists =false;

     for (int i = 0; i < list.count(); i++){
       QString word =list[i];
       if (word.contains("activity") ||
         word.contains("airport") ||
         word.contains("anniversary") ||
         word.contains("appointment") ||
         word.contains("bank") ||
         word.contains("birthday") ||
         word.contains("bus") ||
         word.contains("car") ||
         word.contains("church") ||
         word.contains("code") ||
         word.contains("decorating") ||
         word.contains("delivery") ||
         word.contains("dentist") ||
         word.contains("development") ||
         word.contains("diy") ||
         word.contains("doctor") ||
         word.contains("engagement") ||
         word.contains("family") ||
         word.contains("film") ||
         word.contains("friends") ||
         word.contains("funeral") ||
         word.contains("garden") ||
         word.contains("holiday") ||
         word.contains("hospital") ||
         word.contains("important") ||
         word.contains("information") ||
         word.contains("meal") ||
         word.contains("medical") ||
         word.contains("meeting") ||
         word.contains("meetup") ||
         word.contains("netflix") ||
         word.contains("note") ||
         word.contains("party") ||
         word.contains("payment") ||
         word.contains("radio") ||
         word.contains("reminder") ||
         word.contains("restaurant") ||
         word.contains("retirement") ||
         word.contains("school") ||
         word.contains("service") ||
         word.contains("shopping") ||
         word.contains("social") ||
         word.contains("sport") ||
         word.contains("station") ||
         word.contains("train") ||
         word.contains("travel") ||
         word.contains("visit") ||
         word.contains("wedding")
       )
       {
         tagWordExists =true;
       }

     }

     if(tagWordExists) {

       for (int i = 0; i < list.count(); i++) {
         //qDebug() <<"summary word: " << list[i];
         //iterate through each word at a time search for speech tag
         QString word =list[i];

         if (word.contains("activity")){
           talkText.append(" activity ");
         }
         if (word.contains("airport")){
           talkText.append(" airport ");
         }
         if (word.contains("anniversary")){
           talkText.append(" anniversary ");
         }
         if (word.contains("appointment")){
           talkText.append(" appointment ");
         }
         if (word.contains("bank")){
           talkText.append(" bank ");
         }
         if (word.contains("birthday")){
           talkText.append(" birthday ");
         }
         if (word.contains("bus")){
           talkText.append(" bus ");
         }
         if (word.contains("car")){
           talkText.append(" car ");
         }
         if (word.contains("church")){
           talkText.append(" church ");
         }
         if (word.contains("code")){
           talkText.append(" code ");
         }
         if (word.contains("decorating")){
           talkText.append(" decorating ");
         }
         if (word.contains("delivery")){
           talkText.append(" delivery ");
         }
         if (word.contains("dentist")){
           talkText.append(" dentist ");
         }
         if (word.contains("development")){
           talkText.append(" development ");
         }
         if (word.contains("diy")){
           talkText.append(" diy ");
         }
         if (word.contains("doctor")){
           talkText.append(" doctor ");
         }
         if (word.contains("engagement")){
           talkText.append(" engagement ");
         }
         if (word.contains("family")){
           talkText.append(" family ");
         }
         if (word.contains("film")){
           talkText.append(" film ");
         }
         if (word.contains("friends")){
           talkText.append(" friends ");
         }
         if (word.contains("funeral")){
           talkText.append(" funeral ");
         }
         if (word.contains("garden")){
           talkText.append(" garden ");
         }
         if (word.contains("holiday")){
           talkText.append(" holiday ");
         }
         if (word.contains("hospital")){
           talkText.append(" hospital ");
         }
         if (word.contains("important")){
           talkText.append(" important ");
         }
         if (word.contains("information")){
           talkText.append(" information ");
         }
         if (word.contains("meal")){
           talkText.append(" meal ");
         }
         if (word.contains("medical")){
           talkText.append(" medical ");
         }
         if (word.contains("meeting")){
           talkText.append(" meeting ");
         }
         if (word.contains("meetup")){
           talkText.append(" meetup ");
         }
         if (word.contains("netflix")){
           talkText.append(" netflix ");
         }
         if (word.contains("note")){
           talkText.append(" note ");
         }
         if (word.contains("party")){
           talkText.append(" party ");
         }
         if (word.contains("payment")){
           talkText.append(" payment ");
         }
         if (word.contains("radio")){
           talkText.append(" radio ");
         }
         if (word.contains("reminder")){
           talkText.append(" reminder ");
         }
         if (word.contains("restaurant")){
           talkText.append(" restaurant ");
         }
         if (word.contains("retirement")){
           talkText.append(" retirement ");
         }
         if (word.contains("school")){
           talkText.append(" school ");
         }
         if (word.contains("service")){
           talkText.append(" service ");
         }
         if (word.contains("shopping")){
           talkText.append(" shopping ");
         }
         if (word.contains("social")){
           talkText.append(" social ");
         }
         if (word.contains("sport")){
           talkText.append(" sport ");
         }
         if (word.contains("station")){
           talkText.append(" station ");
         }

         if (word.contains("train")){
           talkText.append(" train ");
         }
         if (word.contains("travel")){
           talkText.append(" travel ");
         }

         if (word.contains("visit")){
           talkText.append(" visit ");
         }
         if (word.contains("wedding")){
           talkText.append(" wedding ");
         }
       } //for word
     } //if tagWordExists
     else {
       talkText.append(" calendar ");
       talkText.append(" event ");
     }

     //qDebug() <<"Speech words: "<<talkText;
     return talkText;

}

void SpeechEngine::generateUpcomingEventsTalk(QList<Event> upcomingList)
{

  QString talkText;
  int num = upcomingList.size();
  // qDebug()<<"number of upcoming events = "<<num<<"\n";
  QString numberSpeechStr = getNumberUpcomingWords(num);
  talkText.append(numberSpeechStr);
  // qDebug()<<"list of upcoming events";

  for (int i = 0; i < upcomingList.size(); i++)
  {

    Event e = upcomingList.at(i);
    // QDate date;
    QDate eventStartDate = QDate(e.m_startYear, e.m_startMonth, e.m_startDay);
    QString day = lookupDay.value(eventStartDate.dayOfWeek());
    QString dayStrOrdinal = lookupOrdinalNumber.value(eventStartDate.day()); // first
    QString monthStr = lookupMonth.value(eventStartDate.month());
    // qDebug()<<day<<" "<<dayStrOrdinal<<" "<<monthStr;
    talkText.append(" ");
    talkText.append(day.toLower());
    talkText.append(" ");
    talkText.append(dayStrOrdinal);
    talkText.append(" ");
    talkText.append(monthStr);
    QString summarySpeechStr = getSpeechWords(e.m_summary);
    talkText.append(summarySpeechStr);
  } // for upcominglist

  // Must initialise wavout using wavEmpty
  WavCat wavEmpty(1, 8000, 16);
  wavEmpty.save("/tmp/empty.wav");
  WavCat wavout("/tmp/empty.wav"); // Assign empty wav to concatenation output

  QString textStr = talkText.toLower();
  QStringList wordList = textStr.split(QRegularExpression("\\s+"), QStringParser::SkipEmptyParts);

  for (int i = 0; i < wordList.count(); i++)
  {

    // qDebug() <<" word: " << wordList[i];
    QString word = wordList.at(i);
    QString path = getWavPath(word);
    WavCat tmp(path.toStdString());
    wavout = wavout + tmp;
  }
  wavout.save("/tmp/upcoming.wav");
}

//--------------------------------------------------------------------------------

void SpeechEngine::generateTalkOut(QDate date, QList<Event> dateEventList, QList<Event> upcomingList, Preferences currentPreferences)
{
  QString day = lookupDay.value(date.dayOfWeek());
  QString dayStrOrdinal = lookupOrdinalNumber.value(date.day()); // first
  QString monthStr = lookupMonth.value(date.month());
  QString talkText;

  talkText.append(day);
  talkText.append(" ");
  talkText.append(dayStrOrdinal);
  talkText.append(" ");
  talkText.append(monthStr);
  talkText.append(" ");

  //------------------------------------------------------------
  // check for holidays
  //------------------------------------------------------------

  if (currentPreferences.m_publicHolidays)
  {
    // speak holiday names
    if ((date.day() == 25) && (date.month() == 12))
      talkText.append(" christmas day ");
    if ((date.day() == 26) && (date.month() == 12))
      talkText.append(" boxing day ");
    if ((date.day() == 1) && (date.month() == 1))
      talkText.append(" new Year ");
    if ((date.day() == 14) && (date.month() == 2))
      talkText.append(" valentine day ");
    if ((date.day() == 31) && (date.month() == 10))
      talkText.append(" halloween");

    QDate easterDate = calculateEaster(date.year());

    if (date.day() == easterDate.day() && date.month() == easterDate.month())
    {
      talkText.append(" Easter Day ");
    }

    if (date == easterDate.addDays(-2))
      talkText.append(" easter Friday ");
    if (date == easterDate.addDays(1))
      talkText.append(" easter Monday ");

    // may day
    QDate firstMondayMay(date.year(), 5, 1);
    while (firstMondayMay.dayOfWeek() != Qt::Monday)
      firstMondayMay = firstMondayMay.addDays(1);
    if (date == firstMondayMay)
      talkText.append(" public holiday ");

    // springbank
    int daysInMay = QDate(date.year(), date.month(), 1).daysInMonth();
    int plusDays = 0;
    if (firstMondayMay.day() + 28 <= daysInMay)
    {
      plusDays = 28;
    }
    else
    {
      plusDays = 21;
    }
    QDate springbank = firstMondayMay.addDays(plusDays); // spring bank
    if (springbank.isValid())
    {
      if (date == springbank)
        talkText.append(" public holiday ");
    }
    // august holiday
    QDate firstMondayAug(date.year(), 8, 1);
    while (firstMondayAug.dayOfWeek() != Qt::Monday)
      firstMondayAug = firstMondayAug.addDays(1);
    int daysInAugust = QDate(date.year(), 8, 1).daysInMonth();
    int plusAugDays = 0;
    if (firstMondayAug.day() + 28 <= daysInAugust)
    {
      plusAugDays = 28;
    }
    else
    {
      plusAugDays = 21;
    }
    QDate summerBankHol = firstMondayAug.addDays(plusAugDays);
    if (summerBankHol.isValid())
    {
      if (date == summerBankHol)
        talkText.append(" public holiday ");
    }
  } // holidays

  //--------------------------------------------------------------
  // Number of events
  //---------------------------------------------------------------
  int n = dateEventList.size();
  QString numberSpeechStr = getNumberWords(n);
  talkText.append(" ");
  talkText.append(numberSpeechStr);
  talkText.append(" ");

  //--------------------------------------------------------------
  // cycle through event list
  //--------------------------------------------------------------
  for (int i = 0; i < dateEventList.size(); i++)
  {

    Event event = dateEventList.at(i);

    //------------------------------------------------------------
    // Check for multi day event
    //-------------------------------------------------------------

    QDate eventStartDate = QDate(event.m_startYear, event.m_startMonth, event.m_startDay);
    QDate eventEndDate = QDate(event.m_endYear, event.m_endMonth, event.m_endDay);

    if (eventStartDate != eventEndDate)
    {
      // qDebug()<< "event summary = "<< event.m_summary;
      qDebug() << "multi day event";
      talkText.append(" multi ");
      talkText.append(" day ");
      talkText.append(" event ");
      talkText.append(" ");
    }

    //-------------------------------------------------------------
    // Speak time
    //-------------------------------------------------------------

    if (eventStartDate == eventEndDate)
    {
      int sHour = event.m_startHour;
      int sMin = event.m_startMin;
      QString startHourStr = "";
      QString startMinStr = "";

      if (currentPreferences.m_12HourFormat)
      {

        if (sHour == 12)
        {
          sHour = 12;
          startHourStr.append(lookupCardinalNumber.value(sHour));
          startHourStr.append(" ");
          if (sMin == 0)
          {
            startMinStr.append("pm");
            startMinStr.append(" ");
          }
          if (sMin > 0 && sMin <= 9)
          {
            startMinStr.append("zero");
            startMinStr.append(" ");
            startMinStr.append(lookupCardinalNumber.value(sMin));
            startMinStr.append(" ");
            startMinStr.append("pm");
            startMinStr.append(" ");
          }
          else if (sMin > 9 && sMin < 59)
          {
            startMinStr.append(lookupCardinalNumber.value(sMin));
            startMinStr.append(" ");
            startMinStr.append("pm");
            startMinStr.append(" ");
          }
        } // if sHour==12

        else if (sHour > 12)
        { // pm
          sHour = sHour - 12;
          startHourStr.append(lookupCardinalNumber.value(sHour));
          startHourStr.append(" ");
          if (sMin == 0)
          {
            startMinStr.append("pm");
            startMinStr.append(" ");
          }
          if (sMin > 0 && sMin <= 9)
          {
            startMinStr.append(" zero ");
            startMinStr.append(lookupCardinalNumber.value(sMin));
            startMinStr.append(" ");
            startMinStr.append("pm");
            startMinStr.append(" ");
          }
          else if (sMin > 9 && sMin < 59)
          {
            startMinStr.append(lookupCardinalNumber.value(sMin));
            startMinStr.append(" ");
            startMinStr.append("pm");
            startMinStr.append(" ");
          }
        } // if sHour>12

        else
        { // am
          startHourStr.append(lookupCardinalNumber.value(sHour));

          if (sMin == 0)
          {
            startMinStr.append("am");
            startMinStr.append(" ");
          }
          if (sMin > 0 && sMin <= 9)
          {
            startMinStr.append("zero");
            startMinStr.append(" ");
            startMinStr.append(lookupCardinalNumber.value(sMin));
            startMinStr.append(" ");
            startMinStr.append("am");
            startMinStr.append(" ");
          }
          else if (sMin > 9 && sMin <= 59)
          {
            startMinStr.append(lookupCardinalNumber.value(sMin));
            startMinStr.append(" ");
            startMinStr.append("am");
            startMinStr.append(" ");
          }
        }
      } // if 12hour format

      else
      { // 24hour format

        startHourStr.append(lookupCardinalNumber.value(sHour));
        if (sMin <= 9)
        {
          startMinStr.append("zero");
          startMinStr.append(" ");
          startMinStr.append(lookupCardinalNumber.value(sMin));
          startMinStr.append(" ");
        }
        else
        {
          startMinStr.append(lookupCardinalNumber.value(sMin));
          startMinStr.append(" ");
        }
      } // else

      if (event.m_isAllDay)
      {
        talkText.append(" all ");
        talkText.append(" day ");
        talkText.append(" event ");
        talkText.append(" ");
      }
      else
      {

        talkText.append(" ");
        talkText.append(startHourStr);
        talkText.append(" ");
        talkText.append(startMinStr);
        talkText.append(" ");
      }
    }
    // time
    //----------------------------------------------------

    if (event.m_isPriority)
    {
      talkText.append(" high");
      talkText.append(" priority ");
      talkText.append(" event ");
      talkText.append(" ");
    }

    //---------------------------------------------------------------
    // speak title
    //---------------------------------------------------------------

    QString summarySpeechStr = getSpeechWords(event.m_summary);
    talkText.append(" ");
    talkText.append(summarySpeechStr);
    talkText.append(" ");

  } // end cycle through dateEventList

  //---------------------------------------------------------------
  // check for overlap
  //----------------------------------------------------------------
  bool overlap = CheckForDayEventOverlap(dateEventList);

  if (overlap)
  {
    talkText.append(" you ");
    talkText.append(" have ");
    talkText.append(" overlapping ");
    talkText.append(" events ");
    talkText.append(" ");
  }

  //-------------------------------------------------------------
  // Upcoming
  //--------------------------------------------------------------

  if (currentPreferences.m_talkUpcoming && date == QDate::currentDate())
  {

    int num = upcomingList.size();
    qDebug() << "number of upcoming events = " << num << "\n";

    QString numberSpeechStr = getNumberUpcomingWords(num);
    talkText.append(numberSpeechStr);

    for (int i = 0; i < upcomingList.size(); i++)
    {

      Event e = upcomingList.at(i);

      QDate eventStartDate = QDate(e.m_startYear, e.m_startMonth, e.m_startDay);

      QString day = lookupDay.value(eventStartDate.dayOfWeek());
      QString dayStrOrdinal = lookupOrdinalNumber.value(eventStartDate.day()); // first
      QString monthStr = lookupMonth.value(eventStartDate.month());
      // qDebug()<<day<<" "<<dayStrOrdinal<<" "<<monthStr;

      talkText.append(" ");
      talkText.append(day.toLower());
      talkText.append(" ");
      talkText.append(dayStrOrdinal);
      talkText.append(" ");
      talkText.append(monthStr);
      talkText.append(" ");

      QString summarySpeechStr = getSpeechWords(e.m_summary);
      talkText.append(" ");
      talkText.append(summarySpeechStr);
      talkText.append(" ");
    } // talk upcoming
  }   // if talk upcoming

  //------------------------------------------------------------
  // Generate talk output
  //------------------------------------------------------------

  // Must initialise wavout using wavEmpty
  WavCat wavEmpty(1, 8000, 16);
  wavEmpty.save("/tmp/empty.wav");
  WavCat wavout("/tmp/empty.wav"); // Assign empty wav to concatenation output

  QString textStr = talkText.toLower();
  QStringList wordList = textStr.split(QRegularExpression("\\s+"), QStringParser::SkipEmptyParts);

  for (int i = 0; i < wordList.count(); i++)
  {

    // qDebug() <<" word: " << wordList[i];
    // iterate through each word one at a time
    QString word = wordList.at(i);
    QString path = getWavPath(word);
    WavCat tmp(path.toStdString());
    wavout = wavout + tmp; // use wavcat to concatenate
  }
  wavout.save("/tmp/talkout.wav");
}

//---------------------------------------------------------------------------------
bool SpeechEngine::CheckForDayEventOverlap(QList<Event> eventListDay)
{
  bool result = false;
  // get all day events

  if (eventListDay.size() > 1)
  {

    for (int i = 1; i < eventListDay.size(); i++)
    {
      Event a = eventListDay.at(i - 1);
      Event b = eventListDay.at(i);
      QTime aStartTime = QTime(a.m_startHour, a.m_startMin);
      QTime aEndTime = QTime(a.m_endHour, a.m_endMin);
      QTime bStartTime = QTime(b.m_startHour, b.m_startMin);
      QTime bEndTime = QTime(b.m_endHour, b.m_endMin);

      if ((aStartTime < bEndTime) && (bStartTime < aEndTime))
      {
        result = true;
      }
    }
  }

  return result;
}
