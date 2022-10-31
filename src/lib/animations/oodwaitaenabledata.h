/*************************************************************************
 * Copyright (C) 2014 by Hugo Pereira Da Costa <hugo.pereira@free.fr>    *
 *                                                                       *
 * This program is free software; you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation; either version 2 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program; if not, write to the                         *
 * Free Software Foundation, Inc.,                                       *
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 *************************************************************************/

#ifndef OODWAITA_ENABLE_DATA_H
#define OODWAITA_ENABLE_DATA_H

#include "oodwaitawidgetstatedata.h"
#include "oodwaitaqt_export.h"

namespace Oodwaita
{
//* Enable data
class OODWAITAQT_EXPORT EnableData : public WidgetStateData
{
    Q_OBJECT
public:
    //* constructor
    EnableData(QObject *parent, QWidget *target, int duration, bool state = true)
        : WidgetStateData(parent, target, duration, state)
    {
        target->installEventFilter(this);
    }

    //* destructor
    virtual ~EnableData()
    {
    }

    //* event filter
    virtual bool eventFilter(QObject *, QEvent *);
};

} // namespace Oodwaita

#endif // OODWAITA_ENABLE_DATA_H
