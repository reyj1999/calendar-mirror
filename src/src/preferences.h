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

#ifndef PREFERENCES_H
#define PREFERENCES_H


#include <QString>
struct Preferences {

 Preferences(
            
      //application
      int appFontSize = 20,
	  int windowWidth =600,
	  int windowHeight =600,
      //calendar
      bool publicHolidays = false,
      bool eventStars=false,    
      bool darkStyle =false,
      bool pmFormat=false,
      int todayRed=135, //skyblue
      int todayGreen=206,
      int todayBlue =235,
      int eventRed =70, //steel
      int eventGreen=130,
      int eventBlue =180,
      int priorityRed =255, //fuchsia
      int priorityGreen=0,
      int priorityBlue =255,
	  int publicRed =255, //yellow
      int publicGreen=255,
      int publicBlue =0,  

	  int lookAheadDays=7,      
      //alarm      
      bool audioAlarm = false,
      //speaking
	  bool talkUpcoming =false,
	  bool talkLocation =false,
      bool talkAtStartup = false

      ) :

		m_appFontSize(appFontSize), 
		m_windowWidth(windowWidth),
	    m_windowHeight(windowHeight),
		//calendar
		m_publicHolidays(publicHolidays),
		m_eventStars(eventStars),		
		m_darkStyle(darkStyle),
		m_12HourFormat(pmFormat),
		m_todayRed(todayRed),
		m_todayGreen(todayGreen),
		m_todayBlue(todayBlue),
		m_eventRed(eventRed),
		m_eventGreen(eventGreen),
		m_eventBlue(eventBlue),
		m_priorityRed(priorityRed),
		m_priorityGreen(priorityGreen),
		m_priorityBlue(priorityBlue),
		m_publicRed(publicRed),
		m_publicGreen(publicGreen),
		m_publicBlue(publicBlue),	
	
	   m_lookAheadDays(lookAheadDays),
		//alarm
		m_audioAlarm(audioAlarm),
		//speaking
		m_talkUpcoming(talkUpcoming),
		m_talkLocation(talkUpcoming),
		m_talkAtStartup(talkAtStartup)  {
  }

	  
	  int m_appFontSize;
	  int m_windowWidth;
	 int m_windowHeight;
	  
	  bool m_publicHolidays;
	  bool m_eventStars;	
	  bool m_darkStyle;
	  bool m_12HourFormat;
	  int m_todayRed;
	  int m_todayGreen;
	  int m_todayBlue;
	  int m_eventRed;
	  int m_eventGreen;
	  int m_eventBlue;
	  int m_priorityRed;
	  int m_priorityGreen;
	  int m_priorityBlue;
	  int m_publicRed;
	  int m_publicGreen;
	  int m_publicBlue;	 
	  int m_lookAheadDays;	 
	  
	  bool m_audioAlarm;
	  bool m_talkUpcoming;
	  bool m_talkLocation;
	  bool m_talkAtStartup;
};

#endif // PREFERENCES_H
