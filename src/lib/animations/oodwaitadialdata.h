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

#ifndef OODWAITA_DIAL_DATA_H
#define OODWAITA_DIAL_DATA_H

#include "oodwaitawidgetstatedata.h"
#include "oodwaitaqt_export.h"

namespace Oodwaita
{
//* dial data
class OODWAITAQT_EXPORT DialData : public WidgetStateData
{
    Q_OBJECT
public:
    //* constructor
    DialData(QObject *parent, QWidget *target, int);

    //* destructor
    virtual ~DialData()
    {
    }

    //* event filter
    virtual bool eventFilter(QObject *, QEvent *);

    //* subcontrol rect
    virtual void setHandleRect(const QRect &rect)
    {
        _handleRect = rect;
    }

    //* mouse position
    QPoint position() const
    {
        return _position;
    }

protected:
    //* hoverMoveEvent
    virtual void hoverMoveEvent(QObject *, QEvent *);

    //* hoverMoveEvent
    virtual void hoverLeaveEvent(QObject *, QEvent *);

private:
    //* rect
    QRect _handleRect;

    //* mouse position
    QPoint _position;
};

} // namespace Oodwaita

#endif // OODWAITA_DIAL_DATA_H
