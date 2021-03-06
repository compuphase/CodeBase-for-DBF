/* *********************************************************************************************** */
/* Copyright (C) 1999-2015 by Sequiter, Inc., 9644-54 Ave, NW, Suite 209, Edmonton, Alberta Canada.*/
/* This program is free software: you can redistribute it and/or modify it under the terms of      */
/* the GNU Lesser General Public License as published by the Free Software Foundation, version     */
/* 3 of the License.                                                                               */
/*                                                                                                 */
/* This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;       */
/* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.       */
/* See the GNU Lesser General Public License for more details.                                     */
/*                                                                                                 */
/* You should have received a copy of the GNU Lesser General Public License along with this        */
/* program. If not, see <https://www.gnu.org/licenses/>.                                           */
/* *********************************************************************************************** */

//ex184.cpp
#include "d4all.hpp"
extern unsigned _stklen = 10000 ;

void main( )
{
   Code4 cb ;
   cb.readOnly = 1 ;
   Data4 data( cb, "INFO" ) ;
   cb.exitTest( ) ;

   // get the reference to the "INF_NAME" tag
   Tag4 tag( data, "INF_NAME" ) ;

   data.select( tag ) ; // select the "INF_NAME" ordering
   for( data.top( ) ; !data.eof( ) ; data.skip( ) )
   {
      Field4 field( data, "NAME" ) ;
      cout << field.str( ) << endl ; // List out the NAMES
   }
   data.close( ) ;
   cb.initUndo( ) ;
}
