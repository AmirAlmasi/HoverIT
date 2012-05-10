/*! 
This file is part of Hoveritu.

Hoveritu is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Hoveritu is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Hoveritu.  If not, see <http://www.gnu.org/licenses/>.
*/

/* $Id: unused_gps.h WP21 20120410 $ */
/*! 
 *  @brief     A common header fie for unusded GPS module.
 *  @details   This module contains forward declarations of standard functions, identifiers, variables of GPS modules. These functions for planned and implemented but left out of the final product
 *  @author    Johan Wikstr�m Sch�tzer
 *  @version   0.1
 *  @date      2012-05-07
 *  @copyright GNU Public License.
 */

/*!
 * @brief Calculates the distance between the two given points in kilometers
 * @param [in] p1 pointer to the first position of type struct position
 * @param [in] p2 pointer to the second position of type struct position
 * @see gps.h struct position for info on this struct
 * @warning The result might be inaccurate (faulty by up to ~50 metres)
 * @return double
 */
double get_distance_km(struct position p1, struct position p2);

/*!
 * @brief Calculates the distance between the two given points in miles
 * @param [in] p1 pointer to the first position of type struct position
 * @param [in] p2 pointer to the second position of type struct position
 * @see gps.h struct position for info on this struct
 * @warning The result might be inaccurate (faulty by up to ~50 metres)
 * @return double
 */
double get_distance_mi(struct position p1, struct position p2);

/*!
 * @brief Parses decimal degrees to radians
 * @param [in] d the degree to convert to radian
 * @return double
 */
double d2r(double);
