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

#ifndef OODWAITA_ANIMATIONS_H
#define OODWAITA_ANIMATIONS_H

#include "oodwaitabusyindicatorengine.h"
#include "oodwaitadialengine.h"
#include "oodwaitaheaderviewengine.h"
#include "oodwaitascrollbarengine.h"
#include "oodwaitaspinboxengine.h"
#include "oodwaitastackedwidgetengine.h"
#include "oodwaitatabbarengine.h"
#include "oodwaitatoolboxengine.h"
#include "oodwaitawidgetstateengine.h"
#include "oodwaitaqt_export.h"

#include <QList>
#include <QObject>

namespace Oodwaita
{
//* stores engines
class OODWAITAQT_EXPORT Animations : public QObject
{
    Q_OBJECT

public:
    //* constructor
    explicit Animations(QObject *);

    //* destructor
    virtual ~Animations()
    {
    }

    //* register animations corresponding to given widget, depending on its type.
    void registerWidget(QWidget *widget) const;

    /** unregister all animations associated to a widget */
    void unregisterWidget(QWidget *widget) const;

    //* enability engine
    WidgetStateEngine &widgetEnabilityEngine() const
    {
        return *_widgetEnabilityEngine;
    }

    //* abstractButton engine
    WidgetStateEngine &widgetStateEngine() const
    {
        return *_widgetStateEngine;
    }

    //* editable combobox arrow hover engine
    WidgetStateEngine &comboBoxEngine() const
    {
        return *_comboBoxEngine;
    }

    //! Tool buttons arrow hover engine
    WidgetStateEngine &toolButtonEngine() const
    {
        return *_toolButtonEngine;
    }

    //! item view engine
    WidgetStateEngine &inputWidgetEngine() const
    {
        return *_inputWidgetEngine;
    }

    //* busy indicator
    BusyIndicatorEngine &busyIndicatorEngine() const
    {
        return *_busyIndicatorEngine;
    }

    //* header view engine
    HeaderViewEngine &headerViewEngine() const
    {
        return *_headerViewEngine;
    }

    //* scrollbar engine
    ScrollBarEngine &scrollBarEngine() const
    {
        return *_scrollBarEngine;
    }

    //* dial engine
    DialEngine &dialEngine() const
    {
        return *_dialEngine;
    }

    //* spinbox engine
    SpinBoxEngine &spinBoxEngine() const
    {
        return *_spinBoxEngine;
    }

    //* tabbar
    TabBarEngine &tabBarEngine() const
    {
        return *_tabBarEngine;
    }

    //* toolbox
    ToolBoxEngine &toolBoxEngine() const
    {
        return *_toolBoxEngine;
    }

    //* setup engines
    void setupEngines();

protected Q_SLOTS:

    //* enregister engine
    void unregisterEngine(QObject *);

private:
    //* register new engine
    void registerEngine(BaseEngine *engine);

    //* busy indicator
    BusyIndicatorEngine *_busyIndicatorEngine;

    //* headerview hover effect
    HeaderViewEngine *_headerViewEngine;

    //* widget enability engine
    WidgetStateEngine *_widgetEnabilityEngine;

    //* abstract button engine
    WidgetStateEngine *_widgetStateEngine;

    //* editable combobox arrow hover effect
    WidgetStateEngine *_comboBoxEngine;

    //! mennu toolbutton arrow hover effect
    WidgetStateEngine *_toolButtonEngine;

    //! item view engine
    WidgetStateEngine *_inputWidgetEngine;

    //* scrollbar engine
    ScrollBarEngine *_scrollBarEngine;

    //* dial engine
    DialEngine *_dialEngine;

    //* spinbox engine
    SpinBoxEngine *_spinBoxEngine;

    //* stacked widget engine
    StackedWidgetEngine *_stackedWidgetEngine;

    //* tabbar engine
    TabBarEngine *_tabBarEngine;

    //* toolbar engine
    ToolBoxEngine *_toolBoxEngine;

    //* keep list of existing engines
    QList<BaseEngine::Pointer> _engines;
};

} // namespace Oodwaita

#endif // OODWAITA_ANIMATIONS_H
